all: bracket_balance

bracket_balance: Stack.o CheckString.o Test.o Source.o
	g++ Stack.o CheckString.o Test.o Source.o -o bracket_balance

Stack.o: Stack.cpp Stack.hpp
	g++ -c Stack.cpp

CheckString.o: Stack.hpp stdafx.hpp CheckString.cpp CheckString.hpp
	g++ -c CheckString.cpp

Test.o: CheckString.hpp Test.cpp Test.hpp
	g++ -c Test.cpp

Source.o: Test.hpp Source.cpp
	g++ -c Source.cpp

clean:
	rm -rf *.o bracket_balance