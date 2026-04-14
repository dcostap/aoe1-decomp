class UnitAIModule {
public:
    int importantWhenDead(int);
};

int UnitAIModule::importantWhenDead(int value) {
    if (value == 0x7 || value == 0x9 || value == 0xA || value == 0xF || value == 0x8 || value == 0x20)
        return 1;
    return 0;
}
