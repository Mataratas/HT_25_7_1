UP_DIR = ../
BUILD_DIR = $(UP_DIR)BUILD/

SRC_SVR = main.cpp CUser.cpp CTCPServer.cpp CMessage.cpp CDBAccess.cpp $(UP_DIR)utils.cpp $(UP_DIR)netcommon.h

ifeq ($(OS), Windows_NT)
SQL_HEAD_DIR = "C:\Program Files\MySQL\MySQLServer8\include"
SQL_LIB_DIR = "C:\Program Files\MySQL\MySQLServer8\lib"

VPATH = $(SQL_HEAD_DIR):$(SQL_LIB_DIR)

chatvy28srv.exe: $(SRC_SVR) 
	g++ -o $(BUILD_DIR)$@ $^ -lWs2_32  -llibmysql
else
chatvy28srv.o: $(SRC_SVR) 
	g++ -o $(BUILD_DIR)$@ $^ -llibmysql
endif

$(BUILD_DIR):
	mkdir $(BUILD_DIR)


clean:
	rm -rf *.o *.a *.exe *.obj

show:
	#echo $(.LIBPATTERNS)
	#echo BUILD_DIR = $(BUILD_DIR)
	