extern "C" int __cdecl __chdrive(int drive);

class DriveInformation {
public:
    char gap_00[0x104];
    int currentDriveValue;

    int changeDrive(int drive);
};

int DriveInformation::changeDrive(int drive) {
    if (__chdrive(drive) == 0) {
        this->currentDriveValue = drive;
        return 1;
    }
    return 0;
}
