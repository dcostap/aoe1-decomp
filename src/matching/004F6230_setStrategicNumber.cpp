// 004F6230 TribeTacticalAIModule::setStrategicNumber(int,int)
// Source: taitacmd.cpp lines 6355-6382
// Attempt log:
// - Replaced simple stub with bounds check, raw sn array store, percentage clamp,
//   and informationAI notification for strategic number 0x69.
// - Exact match with the literal `||` comparison order from original asm.

class TribeInformationAIModule {
public:
    void setSaveLearnInformation(int value);
};

class TribeMainDecisionAIModule {
public:
    char gap_000[0xCEC];
    TribeInformationAIModule informationAI;
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    TribeMainDecisionAIModule* md;
    char gap_0F4[0x194 - 0xF4];
    int sn[0xE2];

    void setStrategicNumber(int index, int value);
};

void TribeTacticalAIModule::setStrategicNumber(int index, int value)
{
    if (index >= 0 && index < 0xE2) {
        this->sn[index] = value;
        if (index == 0x75 || index == 0x78 || index == 0x77 || index == 0x76 ||
            index == 0x9C || index == 0x9D || index == 0x9E || index == 0x9F) {
            if (value < 0) {
                this->sn[index] = 0;
            }
            else if (value > 100) {
                this->sn[index] = 100;
            }
        }
        if (index == 0x69) {
            this->md->informationAI.setSaveLearnInformation(value);
        }
    }
}
