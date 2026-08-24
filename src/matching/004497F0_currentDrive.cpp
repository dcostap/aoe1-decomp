#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation {
public:
    virtual ~DriveInformation();
    char gap_0[0x100];
    int currentDriveValue;
    int currentDrive() const;
};
#endif

int DriveInformation::currentDrive() const { return this->currentDriveValue; }
