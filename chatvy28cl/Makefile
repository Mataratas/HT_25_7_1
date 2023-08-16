UP_DIR = ../
BUILD_DIR = $(UP_DIR)BUILD/
SRC_CL = main.cpp TCPClient.cpp CMessage.cpp sha1.cpp $(UP_DIR)utils.cpp $(UP_DIR)netcommon.h

ifeq ($(OS), Windows_NT)

chatvy28cl.exe: $(SRC_CL)|$(BUILD_DIR)
	g++ -o $(BUILD_DIR)$@ $^ -lWs2_32 ; echo Client built OK
else
chatvy28cl.o: $($^) 
	g++ -o $(BUILD_DIR)$@ $^ ; echo Client built OK
endif

$(BUILD_DIR):
	mkdir $(BUILD_DIR)
	
clean:
	rm -rf *.o *.a *.exe *.obj
