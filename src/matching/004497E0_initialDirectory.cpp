#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation {
public:
    virtual ~DriveInformation();
    char initialDirectoryValue[1];
    char* initialDirectory();
};
#endif

char* DriveInformation::initialDirectory() { return this->initialDirectoryValue; }
