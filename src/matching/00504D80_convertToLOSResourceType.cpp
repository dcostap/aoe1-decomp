#ifndef TAIUAIMD_COMPLETE_TU
class TribeCivilianUnitAIModule {
public:
    virtual ~TribeCivilianUnitAIModule();
    int convertToLOSResourceType(int value);
};
#endif

int TribeCivilianUnitAIModule::convertToLOSResourceType(int value) {
    switch (value) {
    case 7:
        return 1;
    case 0x20:
        return 4;
    case 8:
        return 3;
    case 0xF:
        return 0;
    case 5:
    case 0x1F:
    case 0x21:
        return 2;
    default:
        return -1;
    }
}
