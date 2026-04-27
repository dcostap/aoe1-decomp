// file_stf.cpp:134-145, 102 bytes
// DriveInformation::numberOfFilesWithFilename(char*)
// attempt 1: natural _findfirst/_findnext loop with count starting at 1
#include <io.h>

class DriveInformation {
public:
    int numberOfFilesWithFilename(char* filename);
};

int DriveInformation::numberOfFilesWithFilename(char* filename) {
    long handle;
    _finddata_t fileInfo;
    int count;

    handle = _findfirst(filename, &fileInfo);
    if (handle == -1) {
        return 0;
    }
    count = 1;
    while (_findnext(handle, &fileInfo) != -1) {
        count++;
    }
    return count;
}
