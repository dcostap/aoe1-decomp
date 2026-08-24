// currentDriveAsLetter (00449800, 10 bytes, file_stf.cpp)
// simple getter: return this->currentDriveValue + '@'
#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation {
public:
    int initialDriveValue;
    char initialDirectoryValue[256];
    int currentDriveValue;
    char currentDriveAsLetter() const;
};
#endif

char DriveInformation::currentDriveAsLetter() const {
    return (char)(currentDriveValue + '@');
}
