extern "C" int __cdecl _getdrive(void);
extern "C" char* __cdecl strcpy(char* dst, const char* src);

class DriveInformation {
public:
    int initialDriveValue;
    char initialDirectoryValue[256];
    int currentDriveValue;
    char currentDirectoryValue[256];
    int driveValues[27];

    DriveInformation();
    void updateDirectory();
};

DriveInformation::DriveInformation()
{
    int drive;

    drive = _getdrive();
    this->initialDriveValue = drive;
    this->currentDriveValue = drive;
    this->updateDirectory();
    strcpy(this->initialDirectoryValue, this->currentDirectoryValue);
}
