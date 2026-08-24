#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation {
public:
    int resetCurrentDrive();
    int resetCurrentDirectory();
    int resetCurrentDriveAndDirectory();
};
#endif

int DriveInformation::resetCurrentDriveAndDirectory() {
    if (this->resetCurrentDrive() != 0) {
        return this->resetCurrentDirectory();
    }
    return 0;
}
