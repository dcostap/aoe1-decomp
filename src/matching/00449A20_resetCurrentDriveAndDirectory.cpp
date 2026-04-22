class DriveInformation {
public:
    int resetCurrentDrive();
    int resetCurrentDirectory();
    int resetCurrentDriveAndDirectory();
};

int DriveInformation::resetCurrentDriveAndDirectory() {
    if (this->resetCurrentDrive() != 0) {
        return this->resetCurrentDirectory();
    }
    return 0;
}
