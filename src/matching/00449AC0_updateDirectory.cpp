// file_stf.cpp:230-239, 107 bytes
// The original calls the non-underscore CRT import names getcwd and splitpath.
#include <stdio.h>
extern char* getcwd(char*, int);
extern void splitpath(const char*, char*, char*, char*, char*);

#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation {
public:
    char gap_00[0x108];
    char currentDirectoryValue[0x200];  // +0x108

    void updateDirectory();
};
#endif

void DriveInformation::updateDirectory() {
    char cDrive[3];
    char extension[256];
    char filename[256];
    char fullPath[260];

    getcwd(fullPath, 0x104);
    splitpath(fullPath, cDrive, currentDirectoryValue, filename, extension);
    sprintf(currentDirectoryValue, "%s%s%s", currentDirectoryValue, filename, extension);
}
