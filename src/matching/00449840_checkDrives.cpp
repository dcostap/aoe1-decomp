// tried the straightforward pointer-walk form first; VC5 pulled in an extra frame register
// next probe is the direct array-index form so the loop can stay in the packet's EBX/ESI/EDI basin
extern "C" int __cdecl __chdrive(int drive);

class DriveInformation {
public:
    int initialDriveValue;
    char initialDirectoryValue[256];
    int currentDriveValue;
    char currentDirectoryValue[256];
    int driveValues[27];

    void checkDrives(void);
};

void DriveInformation::checkDrives(void) {
    int drive;

    this->driveValues[0] = 0;
    for (drive = 1; drive <= 0x1A; ++drive) {
        if (__chdrive(drive) == 0) {
            this->driveValues[0]++;
            this->driveValues[drive] = 1;
        } else {
            this->driveValues[drive] = 0;
        }
    }

    __chdrive(this->currentDriveValue);
}
