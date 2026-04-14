class DriveInformation {
public:
    virtual ~DriveInformation();
    char field_4[1];
    char* initialDirectory();
};

char* DriveInformation::initialDirectory() { return this->field_4; }
