// BINARY NOTE: PDB-qualified owner is TribeInformationAIModule in taiinfmd.cpp.
#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    int groupInfluenceDimension(int dim);
};
#endif
#endif
int TribeInformationAIModule::groupInfluenceDimension(int dim) {
    if (dim <= 1) return 2;
    return dim * dim;
}
