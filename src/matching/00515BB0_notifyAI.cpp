// VA: 00515BB0 TRIBE_Player::notifyAI
// Attempt log:
// 1: natural source from packet/decompiler with explicit switch.
// 2: fixed tributeNotify receiver to PlayerAI as TribeMainDecisionAIModule surface.
// 3: first build same-size but broad diff from class surface adding vptr/base offsets (+40/+23C/+11468); removed inherited surfaces and used explicit gaps/casts.
// 4: offsets fixed, but first mismatch remains at dispatch shape: compiler inlines 0x1F9 case before 0x72/0x74 notify path; original lays default return then 0x1F9 out-of-line.
// 5: rewrote dispatch as one switch over all interesting event ids; improved top dispatch shape and kept exact size, but placed 0x72/0x74/0x201 notify block before the 0x202+ jump-table family instead of original late shared notify block.
// 6: kept raw PlayerAI plus casts; fixes module offsets (+0xCEC/+0x1146C) versus earlier typed empty-member padding.
// 7: tried /GX; unchanged.
// 8: tried /O2 without /Oy; unchanged.
// 9: current best same-size 531 B; early guard, object/unitAI call surface, module offsets, and call set are right, but broad dispatch/block-placement mismatch remains.
// 10: left in scratch: not accepted_drift-safe because many event cases are laid out in different order despite behavior-equivalent source.
// 11: reordered the ordinary event switch so 0x202/0x209/0x20a precede the shared 0x72/0x74/0x201 notify cases; calls/CFG aligned, but the switch table crossed the original boundary.
// 12: tried an explicit subtraction expression for the 0x202 parameter gate; it added a compare and worsened the structural basin, then restored the prior source.
// 13: an ordinary two-case switch on param_4 (0x25d/0x26f) recovers the original sub/sub dispatch, 531-byte boundary, and exact bytes.
// 14: removed a redundant source label before the grouped notify cases; exact output is unchanged. Current candidate is exact and remains typed/canonical except for proven raw module offsets.

class RGE_Static_Object;
class UnitAIModule;
class TacticalAIGroup;

#ifndef AOE1_TPLAYER_TU_SHARED_CONTEXT
class RGE_Game_World { public: RGE_Static_Object* object(int id); };
class RGE_Player { public: char gap_00[0x3C]; RGE_Game_World* world; };
class Owner { public: char gap_00[0x4A]; short id; };
class RGE_Static_Object { public: char gap_00[0x0C]; Owner* owner; char gap_10[0x38-0x10]; long world_x; long world_y; UnitAIModule* unitAI(); };
class TacticalAIGroup { public: int id(); int type(); };

class TribeTacticalAIModule {
public:
    char gap_00[0x40];
    virtual void vt00(); virtual void vt04(); virtual void vt08(); virtual void vt0C();
    virtual void vt10(); virtual void vt14(); virtual void vt18(); virtual void vt1C();
    virtual void vt20(); virtual void vt24(); virtual void vt28(); virtual void vt2C();
    virtual void vt30(); virtual void vt34(); virtual void vt38(); virtual void vt3C();
    virtual void notify(int,int,int,long,long,long);
    TacticalAIGroup* groupUnitIsIn(int unit);
    int removeGroup(int id);
    int taskExplorer(int unit, long x, long y);
    void detask(int unit);
};
class TribeInformationAIModule { public: int fullyExploredZone(int); int closestUnexploredTile(int,long,long,long*,long*); int addImportantObject(long); };
class DiplomacyAIModule { public: void changeStance(int,int,int); };
class TribeMainDecisionAIModule { public: void tributeNotify(int,long,long); };

class PlayerAI { public: char raw[0x11470]; };

class TRIBE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x238-0x40];
    PlayerAI* playerAI;
    void notifyAI(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6);
};
#endif

void TRIBE_Player::notifyAI(int param_1, int param_2, int param_3, long param_4, long param_5, long param_6)
{
    RGE_Static_Object* obj = this->world->object(param_1);
    if (param_3 != 0x20a && param_3 != 0x72 && param_3 != 0x74) {
        if (obj == 0) return;
        if (obj->unitAI() == 0) return;
    }

    switch (param_3) {
    case 0x1f9:
        if (param_4 != 0x25d) return;
        {
            TacticalAIGroup* group = ((TribeTacticalAIModule*)((char*)this->playerAI + 0x1146c))->groupUnitIsIn(param_1);
            if (group == 0) return;
            if (group->type() != 0x6b) return;
            ((TribeTacticalAIModule*)((char*)this->playerAI + 0x1146c))->removeGroup(group->id());
            return;
        }
    case 0x202:
        switch (param_4) {
        case 0x25d:
        case 0x26f:
            if (((TribeInformationAIModule*)((char*)this->playerAI + 0xcec))->fullyExploredZone(param_1) != 0 &&
                ((TribeInformationAIModule*)((char*)this->playerAI + 0xcec))->closestUnexploredTile(param_1, obj->world_x, obj->world_y, &param_5, &param_4) == 1) {
                ((TribeTacticalAIModule*)((char*)this->playerAI + 0x1146c))->taskExplorer(param_1, param_5, param_4);
                return;
            }
            ((TribeTacticalAIModule*)((char*)this->playerAI + 0x1146c))->detask(param_1);
            return;
        }
        break;
    case 0x209:
        obj = this->world->object(param_4);
        if (obj != 0) {
            ((DiplomacyAIModule*)((char*)this->playerAI + 0x9dc))->changeStance(obj->owner->id, 0, 10);
            return;
        }
        break;
    case 0x20a:
        ((TribeMainDecisionAIModule*)this->playerAI)->tributeNotify(param_1, param_4, param_5);
        return;
    case 0x72:
    case 0x74:
    case 0x201:
        ((TribeTacticalAIModule*)((char*)this->playerAI + 0x1146c))->notify(param_1, param_2, param_3, param_4, param_5, param_6);
        return;
    case 0x20d:
        ((TribeInformationAIModule*)((char*)this->playerAI + 0xcec))->addImportantObject(param_4);
        break;
    }
}
