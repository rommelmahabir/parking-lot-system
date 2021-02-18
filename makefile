park: admin.o admins.o lot.o lots.o main.o manager.o managers.o user.o users.o ticket.o tickets.o
		g++ admin.o admins.o lot.o lots.o main.o manager.o managers.o user.o users.o ticket.o tickets.o -o output

admin.o: admin.cpp admin.h
		g++ -c admin.cpp admin.h

admins.o: admins.cpp admins.h
		g++ -c admins.cpp admins.h

lot.o: lot.cpp lot.h
		g++ -c lot.cpp lot.h

lots.o: lots.cpp lots.h
		g++ -c lots.cpp lots.h

main.o: main.cpp
		g++ -c main.cpp

manager.o: manager.cpp manager.h
		g++ -c manager.cpp manager.h

managers.o: managers.cpp managers.h
		g++ -c managers.cpp managers.h

user.o: user.cpp user.h
		g++ -c user.cpp user.h

users.o: users.cpp users.h
		g++ -c users.cpp users.h

ticket.o: ticket.cpp ticket.h
		g++ -c ticket.cpp ticket.h

tickets.o: tickets.cpp tickets.h
		g++ -c tickets.cpp tickets.h

run:
		make
		./output

clean:
		rm *.gch *.o output
