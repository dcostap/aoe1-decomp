int debug_rand(char* file, int line);

class UnitAIModule {
public:
    char gap_00[0xFC];
    unsigned int adjustedIdleTimeoutValue;
    unsigned int idleTimeoutValue;

    void setAdjustedIdleTimeout(void);
};

void UnitAIModule::setAdjustedIdleTimeout(void) {
    unsigned int idleTimeout = this->idleTimeoutValue;
    unsigned int value = debug_rand("C:\\msdev\\work\\age1_x1\\aiuaimod.cpp", 0xF4C);

    this->adjustedIdleTimeoutValue = value % (idleTimeout >> 1) + ((idleTimeout * 3) >> 2);
}
