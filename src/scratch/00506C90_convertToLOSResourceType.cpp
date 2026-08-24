#ifndef TAIUAIMD_COMPLETE_TU
class TribeSoldierUnitAIModule {
public:
    int convertToLOSResourceType(int);
};
#endif

#ifdef TAIUAIMD_COMPLETE_TU
int taiuaimd_soldier_convertToLOSResourceType(int value) {
#else
int TribeSoldierUnitAIModule::convertToLOSResourceType(int value) {
#endif
    if (value == 0x1F || value == 0x5 || value == 0x21)
        return 2;
    return -1;
}
