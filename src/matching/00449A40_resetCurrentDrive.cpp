#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation {
public:
    int initialDriveValue;

    int changeDrive(int value);
    int resetCurrentDrive(void);
};
#endif

int DriveInformation::resetCurrentDrive(void) {
    return this->changeDrive(this->initialDriveValue);
}
