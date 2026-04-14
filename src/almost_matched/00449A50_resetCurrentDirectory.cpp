// STATUS: almost_matched
// CLASS: register-allocation-drift
// RISK: low
// WHY: VC5 uses add ecx,4;push ecx instead of lea eax,[ecx+4];push eax — identical semantics, different register choice
// NEXT: TU-context experiment or compiler version investigation
extern void __stdcall resetDirHelper(char *path);

class TDrive_System {
public:
    char gap_0[4];
    char currentDir;
    void resetCurrentDirectory();
};

void TDrive_System::resetCurrentDirectory() {
    resetDirHelper(&this->currentDir);
}
