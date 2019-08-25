/* expr.h -- part of aamath
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

#include <string>
#include <vector>

class Canvas;
class CanvasPtr;

//
//	E x p r e s s i o n
//

enum ExpressionType {
	ET_Constant,
	ET_Symbol,
	ET_UnaryOp,
	ET_BinaryOp,
	ET_OpOnFunction,
	ET_Function,
	ET_Matrix,
};

class Expression {
  public:
	Expression(ExpressionType type_);
	virtual ~Expression();

	virtual CanvasPtr render() const = 0;
	virtual bool is_constant() const = 0;
	virtual bool need_parens() const = 0;
	virtual bool accept_expn() const = 0;
	virtual void set_expn(Expression *expn_) = 0;
	ExpressionType get_expr_type() const;

  protected:
	ExpressionType expr_type;

	friend std::ostream& operator<<(std::ostream& o, Expression& e);
};

typedef std::vector<Expression *> ExprVector;


//
//	C o n s t a n t
//

enum ConstantType {
	CT_Integer,
	CT_Real,
	CT_Ellipsis,
	CT_Infinity,
	CT_Pi,
	CT_Nabla,
};

class Constant : public Expression {
  public:
	Constant(ConstantType type_);
	virtual ~Constant();
	ConstantType get_const_type() const;
	virtual bool need_parens() const;
	virtual bool is_constant() const;
	virtual bool accept_expn() const;
	virtual void set_expn(Expression *expn_);

  protected:
	ConstantType const_type;
};

class Integer : public Constant {
  public:
	Integer(char *value_);
	virtual ~Integer();

	virtual CanvasPtr render() const;

  protected:
	std::string value;
};

class Real : public Constant {
  public:
	Real(char *value_);
	virtual ~Real();

	virtual CanvasPtr render() const;

  protected:
	std::string value;
};

class Ellipsis : public Constant {
  public:
	Ellipsis();
	virtual ~Ellipsis();

	virtual CanvasPtr render() const;
};

class Infinity : public Constant {
  public:
	Infinity();
	virtual ~Infinity();

	virtual CanvasPtr render() const;
};

class Pi : public Constant {
  public:
	Pi();
	virtual ~Pi();

	virtual bool accept_expn() const;
	virtual void set_expn(Expression *expn_);

	virtual CanvasPtr render() const;

  protected:
	Expression *expn;
};

class Nabla : public Constant {
  public:
	Nabla();
	virtual ~Nabla();

	virtual bool accept_expn() const;
	virtual void set_expn(Expression *expn_);

	virtual CanvasPtr render() const;

  protected:
	Expression *expn;
};

//
//	S y m b o l
//

class Symbol : public Expression {
  public:
	Symbol(char *name_);
	virtual ~Symbol();

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
	virtual bool is_constant() const;
	virtual bool accept_expn() const;

	void set_subscr(Expression *subscr_);
	bool has_subscr() const;
	void set_expn(Expression *expn_);
	bool has_expn() const;
	void switch_conj();
	void set_conj(bool is_conj_);
	bool get_conj() const;
	void set_bar();
	bool get_bar() const;
	void add_tick();

  protected:
	std::string name;
	Expression *subscr;		// subscript
	Expression *expn;		// exponent
	int num_ticks;			// # of ticks (e.g. f'(x))
	bool is_conj;			// is conjugate (should render with *
					//  superscript)
	bool has_bar;
};

typedef std::vector<Symbol *> SymVector;


//
//	U n a r y O p
//

enum UnaryOpType {
	UT_Neg,
	UT_Sqrt,
	UT_Fact,
	UT_Conj,
	UT_Bar,
	UT_Abs,
};

class UnaryOp : public Expression {
  public:
	UnaryOp(UnaryOpType type_, Expression *down_);
	virtual ~UnaryOp();
	UnaryOpType get_unop_type() const;
	virtual bool is_constant() const;
	virtual bool accept_expn() const;
	virtual void set_expn(Expression *expn_);

  protected:
	UnaryOpType unop_type;
	Expression *down;
};

class Neg : public UnaryOp {
  public:
	Neg(Expression *down_);
	virtual ~Neg();

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
};

class Sqrt : public UnaryOp {
  public:
	Sqrt(Expression *down_);
	virtual ~Sqrt();

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
};

class Fact : public UnaryOp {
  public:
	Fact(Expression *down_);
	virtual ~Fact();

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
};

class Conj : public UnaryOp {
  public:
	Conj(Expression *down_);
	virtual ~Conj();

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
};

class Bar : public UnaryOp {
  public:
	Bar(Expression *down_);
	virtual ~Bar();

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
};

class Abs : public UnaryOp {
  public:
	Abs(Expression *down_);
	virtual ~Abs();

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
};


//
//	B i n a r y O p
//

enum BinaryOpType {
	BT_Add,
	BT_Sub,
	BT_Mul,
	BT_Div,
	BT_Pow,
	BT_Root,
	BT_Equal,
	BT_Greater,
	BT_Less,
	BT_GreaterOrEqual,
	BT_LessOrEqual,
};

class BinaryOp : public Expression {
  public:
	BinaryOp(BinaryOpType type_, Expression *left_, Expression *right_);
	virtual ~BinaryOp();
	BinaryOpType get_binop_type() const;
	bool is_constant() const;
	bool accept_expn() const;
	void set_expn(Expression *expn_);

  protected:
	BinaryOpType binop_type;
	Expression *left;
	Expression *right;
};

class SimpleBinaryOp : public BinaryOp {
  public:
	SimpleBinaryOp(BinaryOpType type_, Expression *left_, Expression *right_);
	virtual ~SimpleBinaryOp();

	virtual bool need_parens() const;
	virtual CanvasPtr render() const;
	virtual char symbol() const = 0;
};

class Add : public SimpleBinaryOp {
  public:
	Add(Expression *left_, Expression *right_);
	virtual ~Add();

	virtual char symbol() const;
};

class Sub : public SimpleBinaryOp {
  public:
	Sub(Expression *left_, Expression *right_);
	virtual ~Sub();

	virtual CanvasPtr render() const;
	virtual char symbol() const;
};

class Equal : public SimpleBinaryOp {
  public:
	Equal(Expression *left_, Expression *right_);
	virtual ~Equal();

	virtual char symbol() const;
};

class Less : public SimpleBinaryOp {
  public:
	Less(Expression *left_, Expression *right_);
	virtual ~Less();

	virtual char symbol() const;
};

class Greater : public SimpleBinaryOp {
  public:
	Greater(Expression *left_, Expression *right_);
	virtual ~Greater();

	virtual char symbol() const;
};

class LessOrEqual : public BinaryOp {
  public:
	LessOrEqual(Expression *left_, Expression *right_);
	virtual ~LessOrEqual();

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
};

class GreaterOrEqual : public BinaryOp {
  public:
	GreaterOrEqual(Expression *left_, Expression *right_);
	virtual ~GreaterOrEqual();

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
};

class Mul : public BinaryOp {
  public:
	Mul(Expression *left_, Expression *right_);
	virtual ~Mul();

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
};

class Div : public BinaryOp {
  public:
	Div(Expression *left_, Expression *right_);
	virtual ~Div();

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
};

class Pow : public BinaryOp {
  public:
	Pow(Expression *left_, Expression *right_);
	virtual ~Pow();

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
};

class Root : public BinaryOp {
  public:
	Root(Expression *left_, Expression *right_);
	virtual ~Root();

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
};



//
//	O p O n F u n c t i o n
//

enum OpOnFunctionType {
	FT_Integral,
	FT_Derivative,
	FT_SumOrProduct,
	FT_Limit,
};

class OpOnFunction : public Expression {
  public:
	OpOnFunction(OpOnFunctionType type_, Expression *function_,
	  Expression *var_);
	virtual ~OpOnFunction();
	OpOnFunctionType get_op_on_func_type() const;
	virtual bool need_parens() const;
	virtual bool is_constant() const;
	virtual bool accept_expn() const;
	virtual void set_expn(Expression *expn_);

  protected:
	OpOnFunctionType op_on_func_type;
	Expression *function;
	Expression *var;
};

class OpOverInterval {
  public:
	OpOverInterval(Expression *from_, Expression *to_);
	virtual ~OpOverInterval();

  protected:
	Expression *from;
	Expression *to;
};

class Integral : public OpOnFunction {
  public:
	Integral(Expression *function_, Expression *var_);
	virtual ~Integral();

	int get_rise() const;

	virtual CanvasPtr render_head() const;

	void render_symbol(Canvas& c, int r, int c, int h) const;

	virtual CanvasPtr render() const;
};

class IntegralOnInterval : public Integral, public OpOverInterval {
  public:
	IntegralOnInterval(Expression *function_, Expression *var_,
	  Expression *from_, Expression *to_);
	virtual ~IntegralOnInterval();

	virtual CanvasPtr render_head() const;
};

class OpSymbol {
  public:
	virtual void render(Canvas& c, int r, int c) const = 0;
};

class SumOrProduct : public OpOnFunction {
  public:
	SumOrProduct(Expression *function_, Expression *var_);
	virtual ~SumOrProduct();
	
	virtual CanvasPtr render1(const OpSymbol& os) const;

	virtual CanvasPtr render_head(const OpSymbol& os) const;
};

class SumOrProductOverInterval : public SumOrProduct, public OpOverInterval {
  public:
	SumOrProductOverInterval(Expression *function_, Expression *var_,
	  Expression *from_, Expression *to_);
	virtual ~SumOrProductOverInterval();

	virtual CanvasPtr render_head(const OpSymbol& os) const;
};

class Sum : public SumOrProduct {
  public:
	Sum(Expression *function_, Expression *var_);
	virtual ~Sum();

	virtual CanvasPtr render() const;
};

class SumOverInterval : public SumOrProductOverInterval {
  public:
	SumOverInterval(Expression *function_, Expression *var_,
	  Expression *from_, Expression *to_);
	virtual ~SumOverInterval();

	virtual CanvasPtr render() const;
};

class Product : public SumOrProduct {
  public:
	Product(Expression *function_, Expression *var_);
  	virtual ~Product();

	virtual CanvasPtr render() const;
};

class ProductOverInterval : public SumOrProductOverInterval {
  public:
	ProductOverInterval(Expression *function_, Expression *var_,
	  Expression *from_, Expression *to_);
	virtual ~ProductOverInterval();

	virtual CanvasPtr render() const;
};

class Limit : public OpOnFunction {
  public:
	Limit(Expression *function_, Expression *var_, Expression *limit_);
	virtual ~Limit();

	virtual CanvasPtr render() const;

  protected:
	Expression *limit;
};


//
//	F u n c t i o n
//

class FunctionArgs {
  public:
	FunctionArgs();
	virtual ~FunctionArgs();

	void add_arg(Expression *expr);
	CanvasPtr render() const;

  protected:
	ExprVector args;
};

class Function : public Expression {
  public:
	Function(Symbol *symbol_);
	virtual ~Function();

	virtual bool need_parens() const;
	virtual bool is_constant() const;

  protected:
	Symbol *symbol;
};

class MultivarFunction : public Function {
  public:
	MultivarFunction(Symbol *symbol_, FunctionArgs *args_);
	virtual ~MultivarFunction();

	virtual bool accept_expn() const;
	virtual void set_expn(Expression *expn_);
	virtual CanvasPtr render() const;

  protected:
	FunctionArgs *args;
};

class TrigFunction : public Function {
  public:
	TrigFunction(Symbol *symbol_, Expression *arg_);
	virtual ~TrigFunction();

	virtual bool accept_expn() const;
	virtual CanvasPtr render() const;

	void set_expn(Expression *expr);
	bool has_expn() const;

  protected:
	Expression *arg;
};

class Matrix : public Expression {
  public:
	Matrix();
	virtual ~Matrix();

	class Row;

	void add_row(Row *row);
	const Row& operator[](int i) const;

	virtual CanvasPtr render() const;
	virtual bool need_parens() const;
	virtual bool is_constant() const;
	virtual bool accept_expn() const;
	virtual void set_expn(Expression *expn_);

	void set_det();

	int num_rows() const;
	int num_cols() const;

	class Row {
	  public:
		Row();
		virtual ~Row();

		void add_elem(Expression *expr);
		int num_cols() const;
		const Expression *operator[](int i) const;

	  protected:
		ExprVector elems;
	};

  protected:
	std::vector<Row *> rows;
	bool is_det;
};

std::ostream&
operator<<(std::ostream& o, Expression& e);
