#ifndef FILE_STF_SHARED_CONTEXT
class DriveInformation {
public:
    virtual ~DriveInformation();
    char gap_0[0x204];
    int driveValues[1];
    int validDrive(int idx) const;
};
#endif

int DriveInformation::validDrive(int idx) const { return this->driveValues[idx]; }
