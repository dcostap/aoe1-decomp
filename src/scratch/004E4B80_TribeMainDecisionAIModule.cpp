// VA: 004E4B80 TribeMainDecisionAIModule::TribeMainDecisionAIModule
// taimdmd.cpp
// FLAGS: /GX
// Attempt log:
// initial natural constructor reconstruction using known subobject offsets and /GX EH context.

extern "C" void __cdecl rge_read(int, void*, int);
extern "C" void* __cdecl memset(void*, int, unsigned int);

extern int rgeLog; // 0062C50C
extern float g_time; // 0058EBCC
extern float g_cut1; // 00575618
extern float g_cut2; // 0057561C

class TRIBE_Player {};

class AIModule {
public:
    virtual ~AIModule();
    char gap_04[0xEC];
    AIModule(char* name, int id, int param1, void* param2);
    void setPlayer(int playerNumber, char* playerName);
    void setLogCommonHistory(int enabled);
};

class MainDecisionAIModule : public AIModule {
public:
    TRIBE_Player* player; // +F0
    char gap_F4[0x10];
    MainDecisionAIModule(int p1, TRIBE_Player* p2, int p3);
};

class TribeBuildAIModule { public: virtual ~TribeBuildAIModule(); char bytes[0x5BC]; TribeBuildAIModule(int,int); void setPlayer(int,char*); void setup(MainDecisionAIModule*); };
class TribeConstructionAIModule { public: virtual ~TribeConstructionAIModule(); char bytes[0x314]; TribeConstructionAIModule(int,int); void setPlayer(int,char*); void setup(MainDecisionAIModule*); };
class DiplomacyAIModule { public: virtual ~DiplomacyAIModule(); char bytes[0x14C]; DiplomacyAIModule(int,int); void setPlayer(int,char*); void setup(MainDecisionAIModule*); };
class EmotionalAIModule { public: virtual ~EmotionalAIModule(); char bytes[0x1BC]; EmotionalAIModule(int,int); void setPlayer(int,char*); void setup(MainDecisionAIModule*); };
class TribeInformationAIModule { public: virtual ~TribeInformationAIModule(); char bytes[0x1008C]; TribeInformationAIModule(int,int); void setPlayer(int,char*); void setup(MainDecisionAIModule*); };
class TribeResourceAIModule { public: virtual ~TribeResourceAIModule(); char bytes[0xF4]; TribeResourceAIModule(int,int); void setPlayer(int,char*); void setup(MainDecisionAIModule*); };
class TribeStrategyAIModule { public: virtual ~TribeStrategyAIModule(); char bytes[0x5F4]; TribeStrategyAIModule(int,int); void setPlayer(int,char*); void setup(MainDecisionAIModule*); };
class TribeTacticalAIModule { public: virtual ~TribeTacticalAIModule(); char bytes[0x1008]; TribeTacticalAIModule(int,int); void setPlayer(int,char*); void setup(MainDecisionAIModule*); };
class TradeAIModule { public: virtual ~TradeAIModule(); char bytes[0xF0]; TradeAIModule(int,int); void setPlayer(int,char*); void setup(MainDecisionAIModule*); };

class TribeMainDecisionAIModule : public MainDecisionAIModule {
public:
    TribeBuildAIModule build;
    TribeConstructionAIModule construction;
    DiplomacyAIModule diplomacy;
    EmotionalAIModule emotional;
    TribeInformationAIModule information;
    TribeResourceAIModule resource;
    TribeStrategyAIModule strategy;
    TribeTacticalAIModule tactical;
    TradeAIModule trade;
    TRIBE_Player* tribe_player;
    int field_12570;
    int field_12574;
    char* name;
    int field_1257C;
    int field_12580;
    int field_12584;
    int field_12588;
    int field_1258C;
    int field_12590;
    int field_12594;
    int field_12598;
    int field_1259C;
    int field_125A0;
    int array_125A4[9];

    TribeMainDecisionAIModule(int p1, char* p2, TRIBE_Player* p3, int file);
};

TribeMainDecisionAIModule::TribeMainDecisionAIModule(int p1, char* p2, TRIBE_Player* p3, int file)
    : MainDecisionAIModule(p1, p3, file),
      build(p1, file),
      construction(p1, file),
      diplomacy(p1, file),
      emotional(p1, file),
      information(p1, file),
      resource(p1, file),
      strategy(p1, file),
      tactical(p1, file),
      trade(p1, file)
{
    this->tribe_player = p3;
    this->field_12570 = 0;
    this->field_12574 = 0;
    this->name = (char*)p1;
    this->field_1257C = 0;
    this->field_12580 = 0;
    this->field_1259C = 0;
    this->field_125A0 = 0;
    *(void**)this = (void*)0x005755C8;

    this->setPlayer(p1, p2);
    if (rgeLog != 0) {
        this->setLogCommonHistory(1);
    } else {
        this->setLogCommonHistory(0);
    }

    this->build.setup(this);
    this->construction.setup(this);
    this->diplomacy.setup(this);
    this->emotional.setup(this);
    this->information.setup(this);
    this->resource.setup(this);
    this->strategy.setup(this);
    this->tactical.setup(this);
    this->trade.setup(this);

    this->build.setPlayer(p1, p2);
    this->construction.setPlayer(p1, p2);
    this->diplomacy.setPlayer(p1, p2);
    this->emotional.setPlayer(p1, p2);
    this->information.setPlayer(p1, p2);
    this->resource.setPlayer(p1, p2);
    this->strategy.setPlayer(p1, p2);
    this->tactical.setPlayer(p1, p2);
    this->trade.setPlayer(p1, p2);

    rge_read(file, &this->name, 4);
    rge_read(file, &this->field_1257C, 4);
    rge_read(file, &this->field_12580, 4);

    if (g_time >= g_cut1) {
        rge_read(file, &this->field_12584, 4);
        rge_read(file, &this->field_12588, 4);
        rge_read(file, &this->field_1258C, 4);
        rge_read(file, &this->field_12590, 4);
        rge_read(file, &this->field_12594, 4);
        rge_read(file, &this->field_12598, 4);
    }
    if (g_time >= g_cut2) {
        rge_read(file, &this->field_1259C, 4);
        rge_read(file, &this->field_125A0, 4);
        rge_read(file, this->array_125A4, 0x24);
    } else {
        memset(this->array_125A4, 0, 0x24);
    }
}
