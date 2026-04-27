// file_stf.cpp:150-162, 117 bytes
// attempt 1: similar to 004498A0, with attribute filter check
#include <io.h>

class DriveInformation {
public:
    int numberOfFilesWithAttribute(int param1);
};

int DriveInformation::numberOfFilesWithAttribute(int param1) {
    long handle;
    _finddata_t fileInfo;
    int count;

    handle = _findfirst("*.*", &fileInfo);
    if (handle == -1) {
        return 0;
    }
    count = 1;
    while (_findnext(handle, &fileInfo) != -1) {
        if ((fileInfo.attrib & param1) != 0) {
            count++;
        }
    }
    return count;
}
