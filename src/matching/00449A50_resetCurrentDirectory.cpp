class DriveInformation {
public:
    char gap_0[4];
    char initialDirectoryValue;

    int changeDirectory(char* path);
    int resetCurrentDirectory(void);
};

int DriveInformation::resetCurrentDirectory(void) {
    return this->changeDirectory(&this->initialDirectoryValue);
}
