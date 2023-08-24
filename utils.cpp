#include "utils.h"
//===================================================================================
auto print_os_data() -> void {
#ifdef __linux__
    struct utsname utsname;
    uname(&utsname);
    printf("OS name: %s (%s:%s)\n", utsname.sysname, utsname.release, utsname.version);

#elif defined(_WIN32) || defined(_WIN64)
     auto sharedUserData = (BYTE*)0x7FFE0000;
    std::cout << BOLDCYAN << "OS name: Windows " << *(ULONG*)(sharedUserData + 0x26c)<<"."
                                                                    << *(ULONG*)(sharedUserData + 0x270)<<"."
                                                                    << *(ULONG*)(sharedUserData + 0x260)
                                                                    << RESET << std::endl;
#else
    printf("Failed to define current OS\n",
#endif
 
}
//------------------------------------------------------------------------------------




