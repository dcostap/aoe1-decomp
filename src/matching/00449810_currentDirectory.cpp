class DriveInformation {
public:
    virtual ~DriveInformation();
    char gap_0[0x104];
    char field_108[1];
    char* currentDirectory();
};

char* DriveInformation::currentDirectory() { return this->field_108; }
