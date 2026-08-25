#ifndef TAITACMD_SHARED_CONTEXT
class ResourceItem {
public:
    int value(int resourceType) const;
};
#endif

#ifndef TAITACMD_SHARED_CONTEXT
class TribeTacticalAIModule {
public:
    int neededResourceAmount(int index) const;
    char gap_00[0xD88];
    int neededResourceValue[4];
    char gap_D98[0x10];
    ResourceItem neededResources;
};
#endif

int TribeTacticalAIModule::neededResourceAmount(int index) const {
    if (index >= 0 && index < 4)
        return this->neededResources.value(this->neededResourceValue[index]);
    return -1;
}
