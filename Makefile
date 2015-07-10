OBJ=main.o\
	 Subject.o \
	 Observer.o \
	 Node.o

CXX=clang++

#OPTIONS=-g -fsanitize=address
OPTIONS=-g -O0 -fsanitize=address,undefined,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,function,integer-divide-by-zero,null,object-size,return,shift,signed-integer-overflow,unreachable,unsigned-integer-overflow,vla-bound,vptr
LIBS=-L. -lloki -fsanitize=address,undefined,alignment,bool,bounds,enum,float-cast-overflow,float-divide-by-zero,function,integer-divide-by-zero,null,object-size,return,shift,signed-integer-overflow,unreachable,unsigned-integer-overflow,vla-bound,vptr

all: $(OBJ)
	$(CXX) $(OPTIONS) -o a.out $(OBJ) $(LIBS)

clean:
	rm -f *.o
	rm -f a.out
main.o: main.cxx
	$(CXX) $(OPTIONS) -c main.cxx

Subject.o: Subject.cxx
	$(CXX) $(OPTIONS) -c Subject.cxx

Observer.o: Observer.cxx
	$(CXX) $(OPTIONS) -c Observer.cxx -o Observer.o

Node.o: Node.cxx
	$(CXX) $(OPTIONS) -c Node.cxx -o Node.o