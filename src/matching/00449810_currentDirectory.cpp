#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation {
public:
    virtual ~DriveInformation();
    char gap_0[0x104];
    char currentDirectoryValue[1];
    char* currentDirectory();
};
#endif

char* DriveInformation::currentDirectory() { return this->currentDirectoryValue; }
