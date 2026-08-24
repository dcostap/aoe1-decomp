#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation {
public:
    int initialDriveValue;
    char initialDriveAsLetter() const;
};
#endif

char DriveInformation::initialDriveAsLetter() const {
    return (char)(this->initialDriveValue + 0x40);
}
