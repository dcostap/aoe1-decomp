class DriveInformation {
public:
    virtual ~DriveInformation();
    char gap_0[0x204];
    int field_208;
    int numberDrives();
};

int DriveInformation::numberDrives() { return this->field_208; }
