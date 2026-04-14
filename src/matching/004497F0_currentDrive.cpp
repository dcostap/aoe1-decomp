class DriveInformation {
public:
    virtual ~DriveInformation();
    char gap_0[0x100];
    int field_104;
    int currentDrive();
};

int DriveInformation::currentDrive() { return this->field_104; }
