/* expr.cc -- part of aamath
 *
 * This program is copyright (C) 2005 Mauro Persano, and is free
 * software which is freely distributable under the terms of the
 * GNU public license, included as the file COPYING in this
 * distribution.  It is NOT public domain software, and any
 * redistribution not permitted by the GNU General Public License is
 * expressly forbidden without prior written permission from
 * the author.
 *
 */

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "canvas.h"
#include "expr.h"

static Integer ZERO("0");

extern bool big_radicals;

static inline int
max(int a, int b)
{
	return a > b ? a : b;
}

static inline int
min(int a, int b)
{
	return a < b ? a : b;
}

//
//	E x p r e s s i o n
//

Expression::Expression(ExpressionType type_)
: expr_type(type_)
{ }

Expression::~Expression()
{ }

ExpressionType
Expression::get_expr_type() const
{
	return expr_type;
}


//
//	C o n s t a n t
//

Constant::Constant(ConstantType type_)
: Expression(ET_Constant)
, const_type(type_)
{ }

Constant::~Constant()
{ }

ConstantType
Constant::get_const_type() const
{
	return const_type;
}

bool
Constant::need_parens() const
{
	return false;
}

bool
Constant::is_constant() const
{
	return true;
}

bool
Constant::accept_expn() const
{
	return false;
}

void
Constant::set_expn(Expression *expn_)
{
	assert(0);
}


Integer::Integer(char *value_)
: Constant(CT_Integer)
, value(value_)
{ }

Integer::~Integer()
{ }

CanvasPtr
Integer::render() const
{
	CanvasPtr c;

	c->paste_string(value, 0, 0);

	return c;
}

Real::Real(char *value_)
: Constant(CT_Real)
, value(value_)
{ }

Real::~Real()
{ }

CanvasPtr
Real::render() const
{
	CanvasPtr c;

	c->paste_string(value, 0, 0);

	return c;
}


Ellipsis::Ellipsis()
: Constant(CT_Ellipsis)
{ }

Ellipsis::~Ellipsis()
{ }

CanvasPtr
Ellipsis::render() const
{
	CanvasPtr c;

	c->paste_string("...", 0, 0);

	return c;
}

Infinity::Infinity()
: Constant(CT_Infinity)
{ }

Infinity::~Infinity()
{ }

CanvasPtr
Infinity::render() const
{
	CanvasPtr c;

	c->paste_string("oo", 0, 0);

	return c;
}

Pi::Pi()
: Constant(CT_Pi)
, expn(NULL)
{ }

Pi::~Pi()
{
	if (expn != NULL)
		delete expn;
}

bool
Pi::accept_expn() const
{
	return expn == NULL;
}

void
Pi::set_expn(Expression *expn_)
{
	assert(expn == NULL);

	expn = expn_;
}

CanvasPtr
Pi::render() const
{
	CanvasPtr c;

	c->paste_string("__", -1, 0);
	c->paste_string("||", 0, 0);

	if (expn != NULL)
		c->paste(*(expn->render()), -1, 2, Canvas::VA_Top);

	return c;
}

Nabla::Nabla()
: Constant(CT_Nabla)
, expn(NULL)
{ }

Nabla::~Nabla()
{
	if (expn != NULL)
		delete expn;
}

bool
Nabla::accept_expn() const
{
	return expn == NULL;
}

void
Nabla::set_expn(Expression *expn_)
{
	assert(expn == NULL);

	expn = expn_;
}

CanvasPtr
Nabla::render() const
{
	CanvasPtr c;

	c->paste_string("__", -1, 0);
	c->paste_string("\\/", 0, 0);

	if (expn != NULL)
		c->paste(*(expn->render()), -1, 2, Canvas::VA_Top);

	return c;
}

//
//	V a r i a b l e
//

Symbol::Symbol(char *name_)
: Expression(ET_Symbol)
, name(name_)
, subscr(NULL)
, expn(NULL)
, num_ticks(0)
, is_conj(false)
, has_bar(false)
{ }

Symbol::~Symbol()
{
	if (subscr != NULL)
		delete subscr;

	if (expn != NULL)
		delete expn;
}

bool
Symbol::need_parens() const
{
	return false;
}

bool
Symbol::is_constant() const
{
	return false;
}

bool
Symbol::accept_expn() const
{
	return expn == NULL;
}

CanvasPtr
Symbol::render() const
{
	CanvasPtr canvas;

	canvas->paste_string(name, 0, 0);

	int c = name.length();

	if (has_bar) {
		for (int i = 0; i < c; i++)
			(*canvas)[-1][i] = '_';
	}

	if (subscr != NULL)
		canvas->paste(*(subscr->render()), 1, c, Canvas::VA_Bottom);

	for (int i = 0; i < num_ticks; i++)
		(*canvas)[0][c + i] = '\'';

	if (is_conj) {
		(*canvas)[-1][c] = '*';
		++c;
	}

	if (expn != NULL)
		canvas->paste(*(expn->render()), -1, c, Canvas::VA_Top);

	return canvas;
}

void
Symbol::set_subscr(Expression *subscr_)
{
	assert(subscr == NULL);

	subscr = subscr_;
}

bool
Symbol::has_subscr() const
{
	return subscr != NULL;
}

void
Symbol::set_expn(Expression *expn_)
{
	assert(expn == NULL);

	expn = expn_;
}

bool
Symbol::has_expn() const
{
	return expn != NULL;
}

void
Symbol::add_tick()
{
	++num_ticks;
}

void
Symbol::set_conj(bool is_conj_)
{
	is_conj = is_conj_;
}


void
Symbol::switch_conj()
{
	is_conj = !is_conj;
}

bool
Symbol::get_conj() const
{
	return is_conj;
}

void
Symbol::set_bar()
{
	has_bar = true;
}

bool
Symbol::get_bar() const
{
	return has_bar;
}

//
//	U n a r y O p
//

UnaryOp::UnaryOp(UnaryOpType type_, Expression *down_)
: Expression(ET_UnaryOp)
, unop_type(type_)
, down(down_)
{ }

UnaryOp::~UnaryOp()
{
	delete down;
}

UnaryOpType
UnaryOp::get_unop_type() const
{
	return unop_type;
}

bool
UnaryOp::is_constant() const
{
	return down->is_constant();
}

bool
UnaryOp::accept_expn() const
{
	return false;
}

void
UnaryOp::set_expn(Expression *expn_)
{
	assert(0);
}

Neg::Neg(Expression *down_)
: UnaryOp(UT_Neg, down_)
{ }

Neg::~Neg()
{ }

CanvasPtr
Neg::render() const
{
	CanvasPtr canvas_down = down->render();

	Size size_down = canvas_down->size();

	CanvasPtr canvas;

	(*canvas)[0][0] = '-';

	canvas->paste_with_parens(*canvas_down, 0,
	  down->get_expr_type() == ET_Constant ||
	  down->get_expr_type() == ET_Symbol ? 1 : 2,
	  down->need_parens());

	return canvas;
}

bool
Neg::need_parens() const
{
	return true;
}

Sqrt::Sqrt(Expression *down_)
: UnaryOp(UT_Sqrt, down_)
{ }

Sqrt::~Sqrt()
{ }

CanvasPtr
Sqrt::render() const
{
	CanvasPtr canvas_down = down->render();

	Size size_down = canvas_down->size();

	CanvasPtr canvas;

	(*canvas)[size_down.descent][0] = '\\';

	int c;

	if (big_radicals) {
		c = size_down.rows + 1;

		for (int i = 0; i < size_down.rows; i++)
			(*canvas)[size_down.descent - i][1 + i] = '/';
	} else {
		c = 2;

		for (int i = 0; i < size_down.rows; i++)
			(*canvas)[-size_down.ascent + i][1] = '|';
	}

	canvas->paste(*canvas_down, 0, c);

	for (int i = 0; i < size_down.cols; i++)
		(*canvas)[-size_down.ascent - 1][c + i] = '_';

	return canvas;
}

bool
Sqrt::need_parens() const
{
	return false;
}

Fact::Fact(Expression *down_)
: UnaryOp(UT_Fact, down_)
{ }

Fact::~Fact()
{ }

CanvasPtr
Fact::render() const
{
	CanvasPtr canvas_down = down->render();

	Size size_down = canvas_down->size();

	bool parens = down->get_expr_type() != ET_Constant &&
	  down->get_expr_type() != ET_Symbol;

	CanvasPtr canvas;

	canvas->paste_with_parens(*canvas_down, 0, 0, parens);

	(*canvas)[0][size_down.cols + (parens ? 2 : 0)] = '!';

	return canvas;
}


bool
Fact::need_parens() const
{
	return false;
}

Conj::Conj(Expression *down_)
: UnaryOp(UT_Conj, down_)
{ }

Conj::~Conj()
{ }

CanvasPtr
Conj::render() const
{
	CanvasPtr canvas_down = down->render();

	Size size_down = canvas_down->size();

	bool parens = (down->get_expr_type() != ET_Constant &&
	  down->get_expr_type() != ET_Symbol)
	  || (down->get_expr_type() == ET_Symbol &&
	  dynamic_cast<Symbol *>(down)->has_expn() == true);

	CanvasPtr canvas;

	canvas->paste_with_parens(*canvas_down, 0, 0, parens);

	(*canvas)[-1][size_down.cols + (parens ? 2 : 0)] = '*';

	return canvas;
}

bool
Conj::need_parens() const
{
	return false;
}

Bar::Bar(Expression *down_)
: UnaryOp(UT_Bar, down_)
{ }

Bar::~Bar()
{ }

CanvasPtr
Bar::render() const
{
	CanvasPtr canvas_down = down->render();

	Size size_down = canvas_down->size();

	CanvasPtr canvas;

	canvas->paste(*canvas_down, 0, 0);

	for (int i = 0; i < size_down.cols; i++)
		(*canvas)[-size_down.ascent - 1][i] = '_';

	return canvas;
}

bool
Bar::need_parens() const
{
	return false;
}

Abs::Abs(Expression *down_)
: UnaryOp(UT_Abs, down_)
{ }

Abs::~Abs()
{ }

CanvasPtr
Abs::render() const
{
	CanvasPtr canvas_down = down->render();

	Size size_down = canvas_down->size();

	CanvasPtr canvas;

	canvas->paste(*canvas_down, 0, 1);

	for (int i = 0; i < size_down.rows; i++)
		(*canvas)[-size_down.ascent + i][0] = 
		(*canvas)[-size_down.ascent + i][size_down.cols + 1] = '|';

	return canvas;
}

bool
Abs::need_parens() const
{
	return false;
}


//
//	B i n a r y O p
//

BinaryOp::BinaryOp(BinaryOpType type_, Expression *left_, Expression *right_)
: Expression(ET_BinaryOp)
, binop_type(type_)
, left(left_)
, right(right_)
{ }

BinaryOp::~BinaryOp()
{
	delete left;
	delete right;
}

BinaryOpType
BinaryOp::get_binop_type() const
{
	return binop_type;
}

bool
BinaryOp::is_constant() const
{
	return left->is_constant() && right->is_constant();
}

bool
BinaryOp::accept_expn() const
{
	return false;
}

void
BinaryOp::set_expn(Expression *expn_)
{
	assert(0);
}

SimpleBinaryOp::SimpleBinaryOp(BinaryOpType type_, Expression *left_, Expression *right_)
: BinaryOp(type_, left_, right_)
{ }

SimpleBinaryOp::~SimpleBinaryOp()
{ }

CanvasPtr
SimpleBinaryOp::render() const
{
	CanvasPtr canvas_left = left->render();

	Size size_left = canvas_left->size();

	CanvasPtr canvas;

	canvas->paste(*canvas_left, 0, 0);

	(*canvas)[0][size_left.cols + 1] = symbol();

	canvas->paste(*(right->render()), 0, size_left.cols + 3);

	return canvas;
}

bool
SimpleBinaryOp::need_parens() const
{
	return true;
}

Add::Add(Expression *left_, Expression *right_)
: SimpleBinaryOp(BT_Add, left_, right_)
{ }

Add::~Add()
{ }

char
Add::symbol() const
{
	return '+';
}

Sub::Sub(Expression *left_, Expression *right_)
: SimpleBinaryOp(BT_Sub, left_, right_)
{ }

Sub::~Sub()
{ }

CanvasPtr
Sub::render() const
{
	CanvasPtr canvas_left = left->render();
	Size size_left = canvas_left->size();

	CanvasPtr canvas;

	canvas->paste(*canvas_left, 0, 0);

	(*canvas)[0][size_left.cols + 1] = '-';

	canvas->paste_with_parens(*(right->render()), 0, size_left.cols + 3,
	  right->need_parens());

	return canvas;
}

char
Sub::symbol() const
{
	return '-';
}

Equal::Equal(Expression *left_, Expression *right_)
: SimpleBinaryOp(BT_Equal, left_, right_)
{ }

Equal::~Equal()
{ }

char
Equal::symbol() const
{
	return '=';
}

Less::Less(Expression *left_, Expression *right_)
: SimpleBinaryOp(BT_Less, left_, right_)
{ }

Less::~Less()
{ }

char
Less::symbol() const
{
	return '<';
}

Greater::Greater(Expression *left_, Expression *right_)
: SimpleBinaryOp(BT_Greater, left_, right_)
{ }

Greater::~Greater()
{ }

char
Greater::symbol() const
{
	return '>';
}

GreaterOrEqual::GreaterOrEqual(Expression *left_, Expression *right_)
: BinaryOp(BT_GreaterOrEqual, left_, right_)
{ }

GreaterOrEqual::~GreaterOrEqual()
{ }

CanvasPtr
GreaterOrEqual::render() const
{
	CanvasPtr canvas_left = left->render();
	Size size_left = canvas_left->size();

	CanvasPtr canvas;

	canvas->paste(*canvas_left, 0, 0);

	(*canvas)[0][size_left.cols + 1] = '>';
	(*canvas)[1][size_left.cols + 1] = '-';

	canvas->paste_with_parens(*(right->render()), 0, size_left.cols + 3,
	  right->need_parens());

	return canvas;
}

bool
GreaterOrEqual::need_parens() const
{
	return false;
}

LessOrEqual::LessOrEqual(Expression *left_, Expression *right_)
: BinaryOp(BT_LessOrEqual, left_, right_)
{ }

LessOrEqual::~LessOrEqual()
{ }

CanvasPtr
LessOrEqual::render() const
{
	CanvasPtr canvas_left = left->render();
	Size size_left = canvas_left->size();

	CanvasPtr canvas;

	canvas->paste(*canvas_left, 0, 0);

	(*canvas)[0][size_left.cols + 1] = '<';
	(*canvas)[1][size_left.cols + 1] = '-';

	canvas->paste_with_parens(*(right->render()), 0, size_left.cols + 3,
	  right->need_parens());

	return canvas;
}

bool
LessOrEqual::need_parens() const
{
	return false;
}

Mul::Mul(Expression *left_, Expression *right_)
: BinaryOp(BT_Mul, left_, right_)
{ }

Mul::~Mul()
{ }

CanvasPtr
Mul::render() const
{
	CanvasPtr canvas_left = left->render();
	Size size_left = canvas_left->size();

	CanvasPtr canvas;

	canvas->paste_with_parens(*canvas_left, 0, 0, left->need_parens());

	int c = size_left.cols + (left->need_parens() ? 3 : 1);

	canvas->paste_with_parens(*(right->render()), 0, c,
	  right->need_parens());

	return canvas;
}

bool
Mul::need_parens() const
{
	return false;
}

Div::Div(Expression *left_, Expression *right_)
: BinaryOp(BT_Div, left_, right_)
{ }

Div::~Div()
{ }

CanvasPtr
Div::render() const
{
	CanvasPtr canvas_left = left->render();
	Size size_left = canvas_left->size();

	CanvasPtr canvas_right = right->render();
	Size size_right = canvas_right->size();

	int cols = max(size_left.cols, size_right.cols);

	CanvasPtr canvas;

	canvas->paste(*canvas_left, -1, cols/2 - size_left.cols/2,
	  Canvas::VA_Top);

	for (int i = 0; i < cols; i++)
		(*canvas)[0][i] = '-';

	canvas->paste(*canvas_right, 1, cols/2 - size_right.cols/2,
	  Canvas::VA_Bottom);

	return canvas;
}

bool
Div::need_parens() const
{
	return false;
}

Pow::Pow(Expression *left_, Expression *right_)
: BinaryOp(BT_Div, left_, right_)
{ }

Pow::~Pow()
{ }

CanvasPtr
Pow::render() const
{
	CanvasPtr canvas_left = left->render();
	Size size_left = canvas_left->size();

	bool parens = (left->get_expr_type() != ET_Constant &&
	  left->get_expr_type() != ET_Symbol &&
	  left->get_expr_type() != ET_Function &&
	  left->get_expr_type() != ET_Matrix)
	  || (left->get_expr_type() == ET_Symbol &&
	  dynamic_cast<Symbol *>(left)->has_expn() == true);

	CanvasPtr canvas;

	canvas->paste_with_parens(*canvas_left, 0, 0, parens);

	canvas->paste(*(right->render()), -size_left.ascent - 1,
	  size_left.cols + (parens ? 2 : 0), Canvas::VA_Top);

	return canvas;
}

bool
Pow::need_parens() const
{
	return false;
}

Root::Root(Expression *left_, Expression *right_)
: BinaryOp(BT_Div, left_, right_)
{ }

Root::~Root()
{ }

CanvasPtr
Root::render() const
{
	CanvasPtr canvas_left = left->render();
	Size size_left = canvas_left->size();

	CanvasPtr canvas_right = right->render();
	Size size_right = canvas_right->size();

	int c = big_radicals ? size_left.rows : 1;

	int d = size_right.cols - c - 1;

	if (d < 0)
		d = 0;

	CanvasPtr canvas;

	canvas->paste(*canvas_left, 0, c + 1 + d);

	canvas->paste(*canvas_right, -size_left.ascent - 1,
	  d + c - size_right.cols + 1, Canvas::VA_Top);

	(*canvas)[size_left.descent][0] = '\\';

	for (int i = 0; i < size_left.cols; i++)
		(*canvas)[-size_left.ascent - 1][c + 1 + i + d] = '_';

	if (big_radicals) {
		for (int i = 0; i < size_left.rows; i++)
			(*canvas)[size_left.descent - i][1 + i + d] = '/';
	} else {
		for (int i = 0; i < size_left.rows; i++)
			(*canvas)[-size_left.ascent + i][1 + d] = '|';
	}

	return canvas;
}

bool
Root::need_parens() const
{
	return false;
}



//
//	O p O n F u n c t i o n
//

OpOnFunction::OpOnFunction(OpOnFunctionType type_, Expression *fn_,
  Expression *var_)
: Expression(ET_OpOnFunction)
, op_on_func_type(type_)
, function(fn_)
, var(var_)
{ }

OpOnFunction::~OpOnFunction()
{
	delete function;
	delete var;
}

OpOnFunctionType
OpOnFunction::get_op_on_func_type() const
{
	return op_on_func_type;
}

bool
OpOnFunction::need_parens() const
{
	return false;
}

bool
OpOnFunction::is_constant() const
{
	return false;
}

bool
OpOnFunction::accept_expn() const
{
	return false;
}

void
OpOnFunction::set_expn(Expression *expn_)
{
	assert(0);
}

OpOverInterval::OpOverInterval(Expression *from_, Expression *to_)
: from(from_)
, to(to_)
{ }

OpOverInterval::~OpOverInterval()
{
	delete from;
	delete to;
}

//	I n t e g r a l

Integral::Integral(Expression *fn_, Expression *var_)
: OpOnFunction(FT_Integral, fn_, var_)
{ }

Integral::~Integral()
{ }

int
Integral::get_rise() const
{
	int rise;

	// the idea behind this ugly hack is that we want the integration
	// symbols of nested (multivariate) integrals to have the same
	// height. we check if the function being integrated is another
	// integral; if it is, recursively get its height (rise).
	// otherwise calculate height according to argument height.

	// this will probably result in some useless object creation/
	// rendering/destruction overhead, but will do until we figure out
	// a smarter way to do this.

	Integral *integral = dynamic_cast<Integral *>(function);

	if (integral != NULL) {
	  	rise = integral->get_rise();
	} else {
		CanvasPtr temp = function->render();
		Size size = temp->size();
		rise = max(size.ascent, size.descent);

		if (rise == 0)
			rise = 1;
	}

	return rise;
}

void
Integral::render_symbol(Canvas& canvas, int r, int c, int h) const
{
	for (int i = 0; i < h; i++) {
		canvas[r + i + 1][c + 1] = '|';
		canvas[r - i - 1][c + 1] = '|';
	}

	canvas[r][c + 1] = '|';

	canvas[r - h - 1][c + 2] = '/';
	canvas[r + h + 1][c] = '/';
}

CanvasPtr
Integral::render_head() const
{
	CanvasPtr canvas;

	render_symbol(*canvas, 0, 0, get_rise());

	return canvas;
}

CanvasPtr
Integral::render() const
{
	CanvasPtr canvas_head = render_head();

	Size size_head = canvas_head->size();

	CanvasPtr canvas;

	canvas->paste(*canvas_head, 0, 0);

	CanvasPtr canvas_fn = function->render();

	Size size_fn = canvas_fn->size();

	int c;

	if (dynamic_cast<Integral *>(function) != NULL)
		c = size_head.cols + 1;
	else
		c = 3;

	canvas->paste_with_parens(*canvas_fn, 0, c, function->need_parens());

	c += 1 + size_fn.cols + (function->need_parens() ? 2 : 0);

	(*canvas)[0][c] = 'd';

	canvas->paste_with_parens(*(var->render()), 0, c + 1,
	  var->need_parens());

	return canvas;
}

IntegralOnInterval::IntegralOnInterval(Expression *function_, Expression *var_,
  Expression *from_, Expression *to_)
: Integral(function_, var_)
, OpOverInterval(from_, to_)
{ }

IntegralOnInterval::~IntegralOnInterval()
{ }

CanvasPtr
IntegralOnInterval::render_head() const
{
	int rise = get_rise();

	CanvasPtr canvas_from = from->render();
	Size size_from = canvas_from->size();

	CanvasPtr canvas_to = to->render();
	Size size_to = canvas_to->size();

	CanvasPtr canvas;

	render_symbol(*canvas, 0, 0, rise);

	canvas->paste(*canvas_from, rise + 2, 1, Canvas::VA_Bottom);
	canvas->paste(*canvas_to, -rise - 2, 3,  Canvas::VA_Top);

	return canvas;
}

class SumSymbol : public OpSymbol {
  public:
	void render(Canvas& c, int r, int c) const;
};

void
SumSymbol::render(Canvas& canvas, int r, int c) const
{
	canvas[r - 1][c] = '\\';
	canvas[r][c + 1] = '>';
	canvas[r + 1][c] = '/';

	for (int i = 0; i < 5; i++)
		canvas[r - 2][i + c] = canvas[r + 2][i + c] = '=';
}

class ProductSymbol : public OpSymbol {
  public:
	void render(Canvas& c, int r, int c) const;
};

void
ProductSymbol::render(Canvas& canvas, int r, int c) const
{
	for (int i = 0; i < 5; i++)
		canvas[r - 2][i + c] = '=';

	for (int i = -1; i <= 2; i++)
		canvas[i][c + 1] = canvas[i][c + 3] = '|';
}

SumOrProduct::SumOrProduct(Expression *fn_, Expression *var_)
: OpOnFunction(FT_SumOrProduct, fn_, var_)
{ }

SumOrProduct::~SumOrProduct()
{ }

CanvasPtr
SumOrProduct::render1(const OpSymbol& os) const
{
	CanvasPtr canvas_sym = render_head(os);

	CanvasPtr canvas;

	canvas->paste(*canvas_sym, 0, 0);

	Size sym_size = canvas_sym->size();

	canvas->paste_with_parens(*(function->render()), 0, sym_size.cols + 1,
	  function->need_parens());

	return canvas;
}

CanvasPtr
SumOrProduct::render_head(const OpSymbol& os) const
{
	CanvasPtr canvas_var = var->render();
	Size size_var = canvas_var->size();

	int left = size_var.cols / 2 - 2;

	if (left < 0)
		left = 0;

	CanvasPtr canvas;

	os.render(*canvas, 0, left);

	canvas->paste(*canvas_var, 3, left + 2 - size_var.cols / 2,
	  Canvas::VA_Bottom);

	return canvas;
}

SumOrProductOverInterval::SumOrProductOverInterval(Expression *function_,
  Expression *var_, Expression *from_, Expression *to_)
: SumOrProduct(function_, var_)
, OpOverInterval(from_, to_)
{ }

SumOrProductOverInterval::~SumOrProductOverInterval()
{ }

CanvasPtr
SumOrProductOverInterval::render_head(const OpSymbol& os) const
{
	CanvasPtr canvas_var = var->render();
	Size size_var = canvas_var->size();

	CanvasPtr canvas_from = from->render();
	Size size_from = canvas_from->size();

	CanvasPtr canvas_to = to->render();
	Size size_to = canvas_to->size();

	int extra = max(size_to.cols, size_var.cols + 3 + size_from.cols);

	int dist = extra / 2 - 2;

	if (dist < 0)
		dist = 0;

	CanvasPtr canvas;

	os.render(*canvas, 0, dist);

	int c1 = dist + 2 - (size_var.cols + 3 + size_from.cols) / 2;

	int h = max(size_var.ascent, size_from.ascent);

	canvas->paste(*canvas_var, 3 + h, c1);

	c1 += size_var.cols + 1;

	(*canvas)[3 + h][c1] = '=';

	c1 += 2;

	canvas->paste(*canvas_from, 3 + h, c1);

	canvas->paste(*canvas_to, -3, dist + 2 - size_to.cols / 2,
	  Canvas::VA_Top);

	return canvas;
}

Sum::Sum(Expression *fn_, Expression *var_)
: SumOrProduct(fn_, var_)
{ }

Sum::~Sum()
{ }

CanvasPtr
Sum::render() const
{
	return render1(SumSymbol());
}

SumOverInterval::SumOverInterval(Expression *fn_, Expression *var_,
  Expression *from_, Expression *to_)
: SumOrProductOverInterval(fn_, var_, from_, to_)
{ }

SumOverInterval::~SumOverInterval()
{ }

CanvasPtr
SumOverInterval::render() const
{
	return render1(SumSymbol());
}

Product::Product(Expression *fn_, Expression *var_)
: SumOrProduct(fn_, var_)
{ }

Product::~Product()
{ }

CanvasPtr
Product::render() const
{
	return render1(ProductSymbol());
}

ProductOverInterval::ProductOverInterval(Expression *fn_, Expression *var_,
  Expression *from_, Expression *to_)
: SumOrProductOverInterval(fn_, var_, from_, to_)
{ }

ProductOverInterval::~ProductOverInterval()
{ }

CanvasPtr
ProductOverInterval::render() const
{
	return render1(ProductSymbol());
}

Limit::Limit(Expression *fn_, Expression *var_, Expression *limit_)
: OpOnFunction(FT_Limit, fn_, var_)
, limit(limit_)
{ }

Limit::~Limit()
{
	delete limit;
}

CanvasPtr
Limit::render() const
{
	CanvasPtr canvas_var = var->render();
	Size size_var = canvas_var->size();

	CanvasPtr canvas_limit = limit->render();
	Size size_limit = canvas_limit->size();

	int cols = size_var.cols + 4 + size_limit.cols;

	CanvasPtr canvas;

	canvas->paste_string("lim", 0, cols/2 - 2);

	int r = 2 + max(size_var.ascent, size_limit.ascent);

	canvas->paste(*canvas_var, r, 0);

	canvas->paste_string("->", r, size_var.cols + 1);

	canvas->paste(*canvas_limit, r, size_var.cols + 4);

	canvas->paste_with_parens(*(function->render()), 0,
	  size_var.cols + 5 + size_limit.cols, function->need_parens());

	return canvas;
}


//
//	F u n c t i o n
//

FunctionArgs::FunctionArgs()
{ }

FunctionArgs::~FunctionArgs()
{
	std::vector<Expression *>::iterator i;

	for (i = args.begin(); i != args.end(); i++)
		delete *i;
}

void
FunctionArgs::add_arg(Expression *expr)
{
	args.push_back(expr);
}

CanvasPtr
FunctionArgs::render() const
{
	std::vector<Expression *>::const_iterator i;

	int c = 0;

	CanvasPtr canvas;

	for (i = args.begin(); i != args.end(); i++) {
		if (i != args.begin()) {
			(*canvas)[0][c] = ',';
			c += 2;
		}

		CanvasPtr canvas_arg = (*i)->render();

		Size size_arg = canvas_arg->size();

		canvas->paste(*canvas_arg, 0, c);

		c += size_arg.cols;
	}

	return canvas;
}

Function::Function(Symbol *symbol_)
: Expression(ET_Function)
, symbol(symbol_)
{ }

Function::~Function()
{
	delete symbol;
}

bool
Function::need_parens() const
{
	return false;
}

bool
Function::is_constant() const
{
	return false;
}

MultivarFunction::MultivarFunction(Symbol *symbol_, FunctionArgs *args_)
: Function(symbol_)
, args(args_)
{ }

MultivarFunction::~MultivarFunction()
{
	delete args;
}

CanvasPtr
MultivarFunction::render() const
{
	CanvasPtr canvas_sym = symbol->render();

	Size size_sym = canvas_sym->size();

	CanvasPtr canvas;

	canvas->paste(*canvas_sym, 0, 0);

	canvas->paste_with_parens(*(args->render()), 0, size_sym.cols, true);
	
	return canvas;
}

bool
MultivarFunction::accept_expn() const
{
	return false;
}

void
MultivarFunction::set_expn(Expression *expn_)
{
	assert(0);
}

TrigFunction::TrigFunction(Symbol *symbol_, Expression *arg_)
: Function(symbol_)
, arg(arg_)
{ }

TrigFunction::~TrigFunction()
{
	delete arg;
}

CanvasPtr
TrigFunction::render() const
{
	CanvasPtr canvas_sym = symbol->render();

	Size size_sym = canvas_sym->size();

	CanvasPtr canvas;

	canvas->paste(*canvas_sym, 0, 0);

	int c = size_sym.cols + (symbol->has_expn() == false ? 1 : 0);

	canvas->paste_with_parens(*(arg->render()), 0, c,
	  arg->need_parens());

	return canvas;
}

bool
TrigFunction::accept_expn() const
{
	return symbol->accept_expn();
}

void
TrigFunction::set_expn(Expression *expr)
{
	symbol->set_expn(expr);
}

bool
TrigFunction::has_expn() const
{
	return symbol->has_expn();
}


std::ostream&
operator<<(std::ostream& o, Expression& e)
{
		o << *(e.render());

		return o;
}


//
//	M a t r i x
//

Matrix::Matrix()
: Expression(ET_Matrix)
, is_det(false)
{ }

Matrix::~Matrix()
{
	std::vector<Row *>::iterator i;

	for (i = rows.begin(); i != rows.end(); i++)
		delete *i;
}

void
Matrix::add_row(Matrix::Row* row)
{
	rows.push_back(row);
}

const Matrix::Row&
Matrix::operator[](int i) const
{
	return *rows[i];
}

CanvasPtr
Matrix::render() const
{
	int cols = num_cols();
	int rows = num_rows();

	CanvasPtr ec[cols * rows];
	Size sz[cols * rows];

	int row_height[rows];
	int col_width[cols];

	memset(row_height, 0, sizeof row_height);
	memset(col_width, 0, sizeof col_width);

	int idx = 0;

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ec[idx] = (*this)[i][j]->render();

			sz[idx] = ec[idx]->size();

			if (sz[idx].rows > row_height[i])
				row_height[i] = sz[idx].rows;

			if (sz[idx].cols > col_width[j])
				col_width[j] = sz[idx].cols;

			++idx;
		}
	}

	idx = 0;

	int r = 0;

	CanvasPtr canvas;

	for (int i = 0; i < rows; i++) {
		int c = 2;

		for (int j = 0; j < cols; j++) {
			canvas->paste(*ec[idx],
			  r + row_height[i]/2 - sz[idx].rows/2,
			  c + col_width[j]/2 - sz[idx].cols/2,
			  Canvas::VA_Bottom);

			c += col_width[j] + 1;

			++idx;
		}

		r += row_height[i] + 1;
	}

	int h = 0;

	for (int i = 0; i < rows; i++)
		h += row_height[i];

	h += rows - 1;

	int w = 0;

	for (int i = 0; i < cols; i++)
		w += col_width[i];

	w += cols + 1;

	if (!is_det) {
		for (int i = 1; i < h - 1; i++)
			(*canvas)[i][0] = (*canvas)[i][w + 1] = '|';

		(*canvas)[0][0] = '/';
		(*canvas)[0][w + 1] = '\\';

		(*canvas)[h - 1][0] = '\\';
		(*canvas)[h - 1][w + 1] = '/';
	} else {
		for (int i = 0; i < h; i++)
			(*canvas)[i][0] = (*canvas)[i][w + 1] = '|';
	}

	canvas->center();

	return canvas;
}

bool
Matrix::need_parens() const
{
	return false;
}

bool
Matrix::is_constant() const
{
	return false;
}

bool
Matrix::accept_expn() const
{
	return false;
}

void
Matrix::set_expn(Expression *expn_)
{
	assert(0);
}

int
Matrix::num_rows() const
{
	return rows.size();
}

void
Matrix::set_det()
{
	is_det = true;
}

int
Matrix::num_cols() const
{
	int num_cols = 0;

	std::vector<Row *>::const_iterator i;

	for (i = rows.begin(); i != rows.end(); i++) {
		if ((*i)->num_cols() > num_cols)
			num_cols = (*i)->num_cols();
	}

	return num_cols;
}

Matrix::Row::Row()
{ }

Matrix::Row::~Row()
{
	ExprVector::iterator i;

	for (i = elems.begin(); i != elems.end(); i++)
		delete *i;
}

void
Matrix::Row::add_elem(Expression *expr)
{
	elems.push_back(expr);
}

int
Matrix::Row::num_cols() const
{
	return elems.size();
}

const Expression *
Matrix::Row::operator[](int i) const
{
	if (i >= (int)elems.size())
		return &ZERO;
	else
		return elems[i];
}
