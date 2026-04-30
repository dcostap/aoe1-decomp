// VA: 004497C0 initialDrive
// file_stf.cpp lines 58-60
// 3 bytes

struct DriveInformation {
    int initialDriveValue;
    char initialDirectoryValue[256];
    int currentDriveValue;
    char currentDirectoryValue[256];
    int driveValues[27];
};

int DriveInformation::initialDrive() {
    return initialDriveValue;
}
