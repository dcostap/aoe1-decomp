// file_stf.cpp:230-239, 107 bytes
// attempt 1: 49.5%, _splitpath arg order wrong
// attempt 2: 49.5%, same
// attempt 3: 49.5%, local reorder no help
// attempt 4: try making dir a separate local, not member
#include <stdio.h>
extern char* _getcwd(char*, int);
extern void _splitpath(const char*, char*, char*, char*, char*);

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

    _getcwd(fullPath, 0x104);
    _splitpath(fullPath, cDrive, currentDirectoryValue, filename, extension);
    sprintf(currentDirectoryValue, "%s%s%s", currentDirectoryValue, filename, extension);
}
