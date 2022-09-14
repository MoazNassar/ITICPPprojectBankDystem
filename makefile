
#make rule to generate the final binary

Bank_system: main.o bank.o linkedlist.o
	g++ main.o bank.o linkedlist.o -o Bank_system.exe
	

main.o: bank.cpp main.cpp linkedlist.cpp
	g++ -c main.cpp

bank.o: bank.cpp bank.h
	g++ -c bank.cpp
	
linkedlist.o: linkedlist.cpp linkedlist.h
	g++ -c linkedlist.cpp