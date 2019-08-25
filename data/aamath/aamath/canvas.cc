/* canvas.cc -- part of aamath
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

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "canvas.h"

std::ostream&
operator<<(std::ostream& o, Size& s)
{
	o << "(" << s.rows << ", " << s.cols << ")";

	return o;
}

Canvas::Canvas(int nrows_, int ncols_, int first_row_)
: nrows(nrows_)
, first_row(first_row_)
, ref_count(0)
{
	assert(nrows >= 1);
	assert(first_row <= 0);

	if (-first_row + 1 > nrows)
		nrows = -first_row + 1;

	rows = new Row *[nrows];

	for (int i = 0; i < nrows; i++)
		rows[i] = new Row(ncols_);
}

Canvas::~Canvas()
{
	if (nrows != 0) {
		for (int i = 0; i < nrows; i++)
			delete rows[i];

		delete[] rows;
	}
}

const Canvas::Row&
Canvas::operator[](int i) const
{
	assert(i >= first_row && i < first_row + nrows);

	return *rows[i - first_row];
}

Canvas::Row&
Canvas::operator[](int i)
{
	if (i < first_row || i >= first_row + nrows) {
		int new_first_row, new_nrows;

		if (i < first_row) {
			new_first_row = i;
			new_nrows = first_row + nrows - i;
		} else {
			new_first_row = first_row;
			new_nrows = i - first_row + 1;
		}

		Row **new_rows = new Row *[new_nrows];

		if (rows != NULL) {
			for (int i = 0; i < nrows; i++) {
				new_rows[i + (first_row - new_first_row)] =
				  rows[i];
			}

			delete[] rows;
		}

		if (i < first_row) {
			for (int i = 0; i < new_nrows - nrows; i++)
				new_rows[i] = new Row();
		} else {
			for (int i = 0; i < new_nrows - nrows; i++)
				new_rows[i + nrows] = new Row();
		}

		rows = new_rows;
		nrows = new_nrows;
		first_row = new_first_row;
	}

	return *rows[i - first_row];
}

void
Canvas::paste(const Canvas& cn, int r, int c, Align a)
{
	if (a == VA_Center)
		r = r + cn.first_row;
	else if (a == VA_Top)
		r = r - cn.nrows + 1;

	for (int i = 0; i < cn.nrows; i++)
		((*this)[r + i]).paste(cn[cn.first_row + i], c);
}

void
Canvas::center()
{
	first_row = - nrows/2; // - nrows%2;
}

Size
Canvas::size() const
{
	Size s;

	s.rows = nrows;

	if (nrows == 0) {
		s.cols = 0;
	} else {
		s.cols = rows[0]->num_cols();

		for (int i = 1; i < nrows; i++) {
			if (s.cols < rows[i]->num_cols())
				s.cols = rows[i]->num_cols();
		}
	}

	s.ascent = -first_row;
	s.descent = nrows + first_row - 1;

	return s;
}

Canvas::Row::Row(int ncols)
{
	if (ncols == 0) {
		size = 0;
		data = NULL;
		last_pos = -1;
	} else {
		size = ncols + 20;
		data = new char[size];
		memset(data, ' ', ncols);
		data[ncols] = 0;
		last_pos = ncols - 1;
	}
}

Canvas::Row::~Row()
{
	if (data != NULL)
		delete[] data;
}

char&
Canvas::Row::operator[](int i)
{
	assert(i >= 0);

	if (i >= size - 1)
		resize_to(i + 30 + 1);

	if (i > last_pos) {
		memset(data + last_pos + 1, ' ', i - last_pos);
		last_pos = i;
		data[last_pos + 1] = 0;
	}

	return data[i];
}

char
Canvas::Row::operator[](int i) const
{
	assert(i >= 0 && i <= last_pos);

	return data[i];
}

void
Canvas::Row::resize_to(int new_size)
{
	char *new_data = new char[new_size];

	if (data != NULL) {
		memcpy(new_data, data, new_size > size ? size : new_size);
		delete[] data;
	}

	size = new_size;
	data = new_data;
}

int
Canvas::Row::num_cols() const
{
	if (data == NULL)
		return 0;

	return last_pos + 1;
}

void
Canvas::Row::paste(const Row& r, int c)
{
	if (r.data == NULL)
		return;

	int len = r.num_cols();

	if (c + len >= size - 1)
		resize_to(c + len + 30 + 1);

	memcpy(data + c, r.data, len);

	if (c > last_pos + 1)
		memset(data + last_pos + 1, ' ', c - last_pos - 1);

	if (c + len - 1 >= last_pos) {
		last_pos = c + len - 1;
		data[last_pos + 1] = 0;
	}
}

void
Canvas::Row::paste_string(const std::string& str, int c)
{
	int len = str.length();

	if (c + len >= size - 1)
		resize_to(c + len + 30 + 1);

	memcpy(data + c, str.c_str(), len);

	if (c > last_pos + 1)
		memset(data + last_pos + 1, ' ', c - last_pos - 1);

	if (c + len - 1 >= last_pos) {
		last_pos = c + len - 1;
		data[last_pos + 1] = 0;
	}
}

std::ostream&
operator<<(std::ostream& o, Canvas::Row& r)
{
	if (r.data != NULL)
		o << r.data;

	return o;
}

std::ostream&
operator<<(std::ostream& o, Canvas& c)
{
	for (int i = c.first_row; i < c.first_row + c.nrows; i++)
		o << c[i] << "\n";

	return o;
}

void
Canvas::paste_with_parens(const Canvas& cn, int r, int c, bool with_parens)
{
	if (with_parens)
		c += 1;

	paste(cn, r, c, VA_Center);

	if (with_parens) {
		Size s = cn.size();

		if (s.rows == 1) {
			(*this)[r][c - 1] = '(';
			(*this)[r][c + s.cols] = ')';
		} else {
			(*this)[-s.ascent][c - 1] = '/';
			(*this)[-s.ascent][c + s.cols] = '\\';

			(*this)[-s.ascent + s.rows - 1][c - 1] = '\\';
			(*this)[-s.ascent + s.rows - 1][c + s.cols] = '/';

			for (int i = 0; i < s.rows - 2; i++) {
				(*this)[-s.ascent + i + 1][c - 1] =
				  (*this)[-s.ascent + i + 1][c + s.cols] = '|';
			}
		}
	}
}

void
Canvas::paste_string(const std::string& str, int r, int c)
{
	((*this)[r]).paste_string(str, c);
}

CanvasPtr::CanvasPtr()
: canvas(new Canvas())
{
	canvas->ref_count++;
}

CanvasPtr::CanvasPtr(const CanvasPtr& ptr)
: canvas(ptr.canvas)
{
	canvas->ref_count++;
}

CanvasPtr::~CanvasPtr()
{
	if (--canvas->ref_count == 0)
		delete canvas;
}

CanvasPtr&
CanvasPtr::operator=(const CanvasPtr& ptr)
{
	ptr.canvas->ref_count++;

	if (--canvas->ref_count == 0)
		delete canvas;

	canvas = ptr.canvas;

	return *this;
}

Canvas *
CanvasPtr::operator->()
{
	return canvas;
}

Canvas&
CanvasPtr::operator*()
{
	return *canvas;
}
