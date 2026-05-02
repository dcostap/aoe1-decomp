// VA: 004497C0 initialDrive
// file_stf.cpp lines 58-60
// 3 bytes: mov eax,[ecx]; ret

// Use class tag to match forward decl in game_types.h
class DriveInformation {
public:
    int initialDriveValue;
    char initialDirectoryValue[256];
    int currentDriveValue;
    char currentDirectoryValue[256];
    int driveValues[27];
    int initialDrive();
};

int DriveInformation::initialDrive() {
    return initialDriveValue;
}
