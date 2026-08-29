#ifndef AOE1_FILE_STF_H
#define AOE1_FILE_STF_H

class DriveInformation {
public:
    int initialDriveValue;
    char initialDirectoryValue[0x100];
    int currentDriveValue;
    char currentDirectoryValue[0x100];
    int driveValues[0x1B];

    DriveInformation();

    int initialDrive() const;
    char initialDriveAsLetter() const;
    char* initialDirectory();
    int currentDrive() const;
    char currentDriveAsLetter() const;
    char* currentDirectory();
    int numberDrives() const;
    int validDrive(int index) const;
    void checkDrives();
    int numberOfFilesWithFilename(char* filename);
    int numberOfFilesWithAttribute(int attribute);
    int numberOfFilesWithFilenameOrAttribute(char* filename, int attribute);
    int resetCurrentDriveAndDirectory();
    int resetCurrentDrive();
    int resetCurrentDirectory();
    int changeDrive(int drive);
    int changeDirectory(char* path);

protected:
    void updateDirectory();
};

int __cdecl compareFilenameStrings(const void* a, const void* b);
char driveAsLetter(int value);
int driveAsInt(char value);

#endif  // AOE1_FILE_STF_H
