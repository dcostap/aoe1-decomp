#ifndef TAIINFMD_PREFIX_CONTEXT
#ifndef TAIINFMD_PREFIX_CONTEXT
struct BuildItem;
#endif

#ifndef TAIINFMD_PREFIX_CONTEXT
class TribeInformationAIModule {
public:
    virtual ~TribeInformationAIModule();
    int influenceCanPlaceStructure(BuildItem* p0);
};
#endif

#endif
int TribeInformationAIModule::influenceCanPlaceStructure(BuildItem* p0) {
    return 1;
}
