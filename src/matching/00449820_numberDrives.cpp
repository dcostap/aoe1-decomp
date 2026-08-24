#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation {
public:
    virtual ~DriveInformation();
    char gap_0[0x204];
    int driveValues[1];
    int numberDrives() const;
};
#endif

int DriveInformation::numberDrives() const { return this->driveValues[0]; }
