all: test_server.cpp server.cpp ../include/server.h test_client.cpp client.cpp ../include/client.h ../include/global.h
	g++ -o ../bin/test_client test_client.cpp client.cpp -L/usr/local/lib/ -lboost_system -lboost_thread -lpthread
	g++ -o ../bin/test_server test_server.cpp server.cpp -L/usr/local/lib/ -lboost_system -lboost_thread -lpthread -L/usr/lib64/mysql -lmysqlclient -lhiredis
test_server: test_server.cpp server.cpp ../include/server.h ../include/global.h
	g++ -o test_server test_server.cpp server.cpp -L/usr/local/lib/ -lboost_system -lboost_thread -lpthread -L/usr/lib64/mysql -lmysqlclient -lhiredis
test_client: test_client.cpp client.cpp ../include/client.h ../include/global.h
	g++ -o test_client test_client.cpp client.cpp -L/usr/local/lib/ -lboost_system -lboost_thread -lpthread
clean:
	rm ../bin/test_server
	rm ../bin/test_client
