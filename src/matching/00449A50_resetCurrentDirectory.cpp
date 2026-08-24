#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation {
public:
    char gap_0[4];
    char initialDirectoryValue[1];

    int changeDirectory(char* path);
    int resetCurrentDirectory(void);
};
#endif

int DriveInformation::resetCurrentDirectory(void) {
    return this->changeDirectory(this->initialDirectoryValue);
}
