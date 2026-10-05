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
    int validDrive(int v) const;
    void checkDrives();
    int numberOfFilesWithFilename(char* n);
    int numberOfFilesWithAttribute(int a);
    int numberOfFilesWithFilenameOrAttribute(char* n, int a);
    int resetCurrentDriveAndDirectory();
    int resetCurrentDrive();
    int resetCurrentDirectory();
    int changeDrive(int d);
    int changeDirectory(char* d);

  protected:
    void updateDirectory();
};

int __cdecl compareFilenameStrings(const void* e1, const void* e2);
char driveAsLetter(int d);
int driveAsInt(char d);

#endif // AOE1_FILE_STF_H
