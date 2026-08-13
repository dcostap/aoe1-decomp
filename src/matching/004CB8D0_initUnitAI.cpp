// 004CB8D0 TRIBE_Combat_Object::initUnitAI
// Attempt log:
// try 1: packet-grounded reconstruction used a dense 1..11 switch and false
//         AI class mappings; it matched the EH frame but not the dispatch.
// try 2: restored the packet's 0x21-entry type bucket switch and constructor
//         classes.  The original groups no-AI buckets and uses Soldier as the
//         out-of-range/default constructor.
// FLAGS: config/flags/004CB8D0_initUnitAI.rsp (/GX required by original EH)

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
};
class RGE_Master_Static_Object {
public:
    char gap_00[0x10];
    short id;
    char gap_12[2];
    short object_group;
};

class UnitAIModule { public: char pad[0x134]; };
class TribeArtifactUnitAIModule : public UnitAIModule {
public: TribeArtifactUnitAIModule(RGE_Static_Object*, int);
};
class TribeCivilianUnitAIModule : public UnitAIModule {
public: TribeCivilianUnitAIModule(RGE_Static_Object*, int);
};
class TribePriestUnitAIModule : public UnitAIModule {
public: TribePriestUnitAIModule(RGE_Static_Object*, int);
};
class TribeHuntedAnimalUnitAIModule : public UnitAIModule {
public: TribeHuntedAnimalUnitAIModule(RGE_Static_Object*, int);
};
class TribeElephantUnitAIModule : public UnitAIModule {
public: TribeElephantUnitAIModule(RGE_Static_Object*, int);
};
class TribeLionUnitAIModule : public UnitAIModule {
public: TribeLionUnitAIModule(RGE_Static_Object*, int);
};
class TribePreditorUnitAIModule : public UnitAIModule {
public: TribePreditorUnitAIModule(RGE_Static_Object*, int);
};
class TribeFishingShipUnitAIModule : public UnitAIModule {
public: TribeFishingShipUnitAIModule(RGE_Static_Object*, int);
};
class TribeTradeShipUnitAIModule : public UnitAIModule {
public: TribeTradeShipUnitAIModule(RGE_Static_Object*, int);
};
class TribeTransportShipUnitAIModule : public UnitAIModule {
public: TribeTransportShipUnitAIModule(RGE_Static_Object*, int);
};
class TribeBuildingUnitAIModule : public UnitAIModule {
public: TribeBuildingUnitAIModule(RGE_Static_Object*, int);
};
class TribeTowerUnitAIModule : public UnitAIModule {
public: TribeTowerUnitAIModule(RGE_Static_Object*, int);
};
class TribeSoldierUnitAIModule : public UnitAIModule {
public: TribeSoldierUnitAIModule(RGE_Static_Object*, int);
};

class RGE_Combat_Object : public RGE_Static_Object {
public:
    int id;
    RGE_Master_Static_Object* master_obj;
    char gap_0c[0x68];
    UnitAIModule* unit_ai;
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    void initUnitAI();
};

void TRIBE_Combat_Object::initUnitAI()
{
    RGE_Master_Static_Object* master = this->master_obj;

    switch (master->object_group) {
    case 1:
        if (master->id == 0x63 || master->id == 0x0a) {
            return;
        }
        this->unit_ai = new TribeArtifactUnitAIModule(this, 5);
        return;

    case 4:
        this->unit_ai = new TribeCivilianUnitAIModule(this, 10);
        return;

    case 0x12:
        this->unit_ai = new TribePriestUnitAIModule(this, 10);
        return;

    case 9:
        this->unit_ai = new TribeHuntedAnimalUnitAIModule(this, 10);
        return;

    case 0x0a:
        if (master->id == 0x9d) {
            this->unit_ai = new TribeHuntedAnimalUnitAIModule(this, 10);
        } else if (master->id == 0x30) {
            this->unit_ai = new TribeElephantUnitAIModule(this, 10);
        } else if (master->id == 0x7e) {
            this->unit_ai = new TribeLionUnitAIModule(this, 10);
        } else {
            this->unit_ai = new TribePreditorUnitAIModule(this, 10);
        }
        return;

    case 0x15:
        this->unit_ai = new TribeFishingShipUnitAIModule(this, 10);
        return;

    case 2:
        this->unit_ai = new TribeTradeShipUnitAIModule(this, 10);
        return;

    case 0x14:
        this->unit_ai = new TribeTransportShipUnitAIModule(this, 10);
        return;

    case 3:
    case 0x1b:
        if (master->id == 0x4f || master->id == 0xc7 || master->id == 0x45 ||
            master->id == 0x116 || master->id == 0x17f || master->id == 0x17c) {
            this->unit_ai = new TribeTowerUnitAIModule(this, 10);
        } else {
            this->unit_ai = new TribeBuildingUnitAIModule(this, 10);
        }
        return;

    default:
        this->unit_ai = new TribeSoldierUnitAIModule(this, 10);
        return;

    case 5:
    case 7:
    case 8:
    case 0x0b:
    case 0x0e:
    case 0x0f:
    case 0x10:
    case 0x1d:
    case 0x1e:
    case 0x1f:
    case 0x20:
    case 0x21:
        return;
    }
}
