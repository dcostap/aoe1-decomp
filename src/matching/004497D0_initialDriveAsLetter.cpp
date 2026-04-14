class TDrive_System {
public:
    int initialDrive;
    int initialDriveAsLetter();
};

int TDrive_System::initialDriveAsLetter() {
    return this->initialDrive + 0x40;
}
