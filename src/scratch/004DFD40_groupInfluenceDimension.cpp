// BINARY NOTE: PDB-qualified owner is TribeInformationAIModule in taiinfmd.cpp.
class TribeInformationAIModule {
public:
    int groupInfluenceDimension(int dim);
};
int TribeInformationAIModule::groupInfluenceDimension(int dim) {
    if (dim <= 1) return 2;
    return dim * dim;
}
