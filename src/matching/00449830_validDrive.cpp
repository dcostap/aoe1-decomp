class DriveInformation {
public:
    virtual ~DriveInformation();
    char gap_0[0x204];
    int array_208[1];
    int validDrive(int idx);
};

int DriveInformation::validDrive(int idx) { return this->array_208[idx]; }
