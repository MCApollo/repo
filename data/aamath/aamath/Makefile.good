CXX		= g++
LD		= g++
CXXFILES	= parser.cc lexer.cc expr.cc canvas.cc aamath.cc
OBJS		= $(CXXFILES:.cc=.o) 
TARGET		= aamath
CFLAGS		= -Wall -O2 -g -DUSE_READLINE
LFLAGS		= -g
LIBS		= -lreadline -ltermcap

$(TARGET): $(OBJS)
	$(LD) $(LFLAGS) $(OBJS) -o $@ $(LIBS)

parser.cc parser.h: parser.y
	yacc -d parser.y && mv y.tab.c parser.cc && mv y.tab.h parser.h

lexer.cc: lexer.l parser.h
	lex lexer.l && mv lex.yy.c lexer.cc

.cc.o:
	$(CXX) $(CFLAGS) -c $<

clean:
	rm -f *.o lexer.cc parser.h parser.cc $(TARGET)
