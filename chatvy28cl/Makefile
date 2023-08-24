UP_DIR = ../
SRC_CL = main.cpp TCPClient.cpp CMessage.cpp sha1.cpp $(UP_DIR)utils.cpp $(UP_DIR)netcommon.h

ifeq ($(OS),Windows_NT)

chatvy28cl.exe: $(SRC_CL)|$(BUILD_DIR)
	echo IN WIN Block
	g++ -o $(BUILD_DIR)$@ $^ -lWs2_32 ; 
else
chatvy28cl.o: $(SRC_CL) 
	g++ -o $@ $^

endif
	
clean:
	rm -rf *.o *.a *.exe *.obj

