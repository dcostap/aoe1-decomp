// BINARY NOTE: PDB owner is TribeInformationAIModule in taiinfmd.cpp, lines 2308-2321.
// The owned body is the exact 004DB070-004DB0A8 boundary.
class TribeInformationAIModule {
public:
    int importantResource(int param_1);
};

int TribeInformationAIModule::importantResource(int param_1) {
    if (param_1 == 0x1F || param_1 == 5 || param_1 == 0x21 || param_1 == 7 ||
        param_1 == 9 || param_1 == 8 || param_1 == 0x20 || param_1 == 0xF) {
        return 1;
    }
    return 0;
}
