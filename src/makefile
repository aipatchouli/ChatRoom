all: test_server.cpp server.cpp server.h test_client.cpp client.cpp client.h global.h
	g++ -o ../bin/test_client test_client.cpp client.cpp -lboost_system -lboost_thread -lpthread -L/usr/local/lib/
	g++ -o ../bin/test_server test_server.cpp server.cpp -lboost_system -lboost_thread -L/usr/local/lib/ -L/usr/lib64/mysql -lmysqlclient -lhiredis -lpthread
test_server: test_server.cpp server.cpp server.h global.h
	g++ -o test_server test_server.cpp server.cpp -L/usr/local/lib/ -L/usr/lib64/mysql -lmysqlclient -lhiredis -lpthread
test_client: test_client.cpp client.cpp client.h global.h
	g++ -o test_client test_client.cpp client.cpp -lboost_system -lboost_thread -lpthread
clean:
	rm test_server
	rm test_client
