extern "C" int __cdecl __chdrive(int drive);

#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation {
public:
    char gap_00[0x104];
    int currentDriveValue;

    int changeDrive(int drive);
};
#endif

int DriveInformation::changeDrive(int drive) {
    if (__chdrive(drive) == 0) {
        this->currentDriveValue = drive;
        return 1;
    }
    return 0;
}
