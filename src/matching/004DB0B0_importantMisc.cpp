// BINARY NOTE: PDB-qualified owner/name is TribeInformationAIModule::importantMisc(int)
// in taiinfmd.cpp, lines 2326-2331. The original body boundary is 004DB0B0-004DB0CA.
#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    int importantMisc(int value);
};
#endif

#endif
int TribeInformationAIModule::importantMisc(int value) {
    if (value != 1 && value != 0x1E) {
        return 0;
    }
    return 1;
}
