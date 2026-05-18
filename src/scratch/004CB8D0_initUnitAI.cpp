// 004CB8D0 TRIBE_Combat_Object::initUnitAI
// Attempt log:
// try 1: packet-grounded reconstruction with /GX: switch on master object type and create matching 0x134-byte UnitAIModule subclass; compact shared-exit source compiled too short (672B vs 1019B).
// try 2: expanded each allocation case with direct assignment and immediate return to mimic original repeated epilogues.
// try 3: corrected custom flag filename to slug form; /GX then produced original-style EH prologue and exact configured size 1019.
// try 4: modeled artifact special IDs 0x63/0x0a as no-AI path, else Artifact AI with ctor arg 5.
// try 5: modeled Civilian/Villager/FishingBoat straightforward cases with ctor arg 10.
// try 6: modeled type-5 id split: 0x9d fishing, 0x30 trade boat, 0x7e trade cart, otherwise transport boat.
// try 7: modeled building/priest/trade ship/farm/combat/default AI module cases.
// try 8: modeled default-unit special IDs 0x4f/0xc7/0x45/0x116/0x17f/0x17c under type 11.
// try 9: direct-return per case improved size/epilogue repetition but switch topology stayed wrong.
// try 10: validation exact size but broad mismatch (75.0736% positional / 74.1904% edit). First mismatch at dispatch: original switches over master type-1 range up to 0x20 using compiler jump-table mapping bytes; rebuilt uses dense 1..11 switch. No drift proposal.
// GIVEUP blockers: exact object type bucket mapping across 0x21 possible type values, true AI subclass/type mapping for all packet cases, and source shape needed to force VC5 byte-map switch table while preserving repeated EH/new epilogues.
// FLAGS: config/flags/004CB8D0_initUnitAI.rsp (/GX required by original EH registration around new+ctor)

class TRIBE_Combat_Object;
struct MasterObj { char gap00[0x10]; short id; char gap12[2]; short type; };
class UnitAIModule { public: char pad[0x134]; };
class TribeArtifactUnitAIModule : public UnitAIModule { public: TribeArtifactUnitAIModule(TRIBE_Combat_Object*, int); };
class TribeCivilianUnitAIModule : public UnitAIModule { public: TribeCivilianUnitAIModule(TRIBE_Combat_Object*, int); };
class TribeVillagerUnitAIModule : public UnitAIModule { public: TribeVillagerUnitAIModule(TRIBE_Combat_Object*, int); };
class TribeFishingBoatUnitAIModule : public UnitAIModule { public: TribeFishingBoatUnitAIModule(TRIBE_Combat_Object*, int); };
class TribeTradeBoatUnitAIModule : public UnitAIModule { public: TribeTradeBoatUnitAIModule(TRIBE_Combat_Object*, int); };
class TribeTradeCartUnitAIModule : public UnitAIModule { public: TribeTradeCartUnitAIModule(TRIBE_Combat_Object*, int); };
class TribeTransportBoatUnitAIModule : public UnitAIModule { public: TribeTransportBoatUnitAIModule(TRIBE_Combat_Object*, int); };
class TribeBuildingUnitAIModule : public UnitAIModule { public: TribeBuildingUnitAIModule(TRIBE_Combat_Object*, int); };
class TribePriestUnitAIModule : public UnitAIModule { public: TribePriestUnitAIModule(TRIBE_Combat_Object*, int); };
class TribeTradeShipUnitAIModule : public UnitAIModule { public: TribeTradeShipUnitAIModule(TRIBE_Combat_Object*, int); };
class TribeFarmUnitAIModule : public UnitAIModule { public: TribeFarmUnitAIModule(TRIBE_Combat_Object*, int); };
class TribeCombatUnitAIModule : public UnitAIModule { public: TribeCombatUnitAIModule(TRIBE_Combat_Object*, int); };
class TribeDefaultUnitAIModule : public UnitAIModule { public: TribeDefaultUnitAIModule(TRIBE_Combat_Object*, int); };
class TRIBE_Combat_Object { public: char gap00[8]; MasterObj* master; char gap0c[0x68]; UnitAIModule* ai; void initUnitAI(); };

void TRIBE_Combat_Object::initUnitAI()
{
    MasterObj* m = this->master;
    switch (m->type) {
    case 1:
        if (m->id == 0x63 || m->id == 0x0a) { this->ai = 0; return; }
        this->ai = new TribeArtifactUnitAIModule(this, 5); return;
    case 2:
        this->ai = new TribeCivilianUnitAIModule(this, 10); return;
    case 3:
        this->ai = new TribeVillagerUnitAIModule(this, 10); return;
    case 4:
        this->ai = new TribeFishingBoatUnitAIModule(this, 10); return;
    case 5:
        if (m->id == 0x9d) { this->ai = new TribeFishingBoatUnitAIModule(this, 10); return; }
        if (m->id == 0x30) { this->ai = new TribeTradeBoatUnitAIModule(this, 10); return; }
        if (m->id == 0x7e) { this->ai = new TribeTradeCartUnitAIModule(this, 10); return; }
        this->ai = new TribeTransportBoatUnitAIModule(this, 10); return;
    case 6:
        this->ai = new TribeBuildingUnitAIModule(this, 10); return;
    case 7:
        this->ai = new TribePriestUnitAIModule(this, 10); return;
    case 8:
        this->ai = new TribeTradeShipUnitAIModule(this, 10); return;
    case 9:
        this->ai = new TribeFarmUnitAIModule(this, 10); return;
    case 10:
        this->ai = new TribeCombatUnitAIModule(this, 10); return;
    case 11:
        if (m->id == 0x4f || m->id == 0xc7 || m->id == 0x45 || m->id == 0x116 || m->id == 0x17f || m->id == 0x17c) {
            this->ai = new TribeDefaultUnitAIModule(this, 10); return;
        }
        this->ai = new TribeCombatUnitAIModule(this, 10); return;
    default:
        this->ai = new TribeDefaultUnitAIModule(this, 10); return;
    }
}
