/* canvas.h -- part of aamath
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
#include <iostream>

struct Size {
	int rows;
	int cols;
	int ascent;
	int descent;
};

class Canvas {
  public:
	Canvas(int nrows_ = 1, int ncols_ = 0, int first_row_ = 0);
	virtual ~Canvas();

	class Row;

	enum Align {
		VA_Top,
		VA_Bottom,
		VA_Center,
	};

	void paste(const Canvas& cn, int r, int c, Align a = VA_Center);

	void paste_with_parens(const Canvas& cn, int r, int c,
	  bool with_parens = false);

	void paste_string(const std::string& str, int r, int c);

	void center();

	Row& operator[](int i);

	const Row& operator[](int i) const;

	Size size() const;

	class Row {
	  public:
		Row(int ncols_ = 0);
		virtual ~Row();

		char& operator[](int i);
		char operator[](int i) const;

		int num_cols() const;
		void paste(const Row& r, int c);
		void paste_string(const std::string& str, int c);

	  protected:
		void resize_to(int new_size);

		int size;
		int last_pos;
		char *data;

		friend std::ostream& operator<<(std::ostream& o, Row& r);
	};

  protected:
	int nrows;
	int first_row;
	int ref_count;
	Row **rows;

	friend class CanvasPtr;
	friend std::ostream& operator<<(std::ostream& o, Canvas& c);
};

class CanvasPtr {
  public:
	CanvasPtr();
	CanvasPtr(const CanvasPtr& ptr);
	~CanvasPtr();
	CanvasPtr& operator=(const CanvasPtr& ptr);

	Canvas *operator->();
	Canvas& operator*();

  protected:
	Canvas *canvas;
};

std::ostream&
operator<<(std::ostream& o, Canvas& c);

std::ostream&
operator<<(std::ostream& o, Size& s);
