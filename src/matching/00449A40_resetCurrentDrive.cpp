class DriveInformation {
public:
    int initialDriveValue;

    int changeDrive(int value);
    int resetCurrentDrive(void);
};

int DriveInformation::resetCurrentDrive(void) {
    return this->changeDrive(this->initialDriveValue);
}
