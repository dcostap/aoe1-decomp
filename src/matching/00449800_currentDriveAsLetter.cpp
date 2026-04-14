class TDrive_System {
public:
    char gap_0[0x104];
    int currentDrive;
    int currentDriveAsLetter();
};

int TDrive_System::currentDriveAsLetter() {
    return this->currentDrive + 0x40;
}
