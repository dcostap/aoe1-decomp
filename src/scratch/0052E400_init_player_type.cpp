// VA: 0052E400 TRIBE_World::init_player_type
// PDB source: tworld.cpp
// Attempt log:
// natural /GX new-expression for TRIBE_Master_Player, base fallback, virtual setup slot +4: correct EH/new/ctor/body skeleton.
// fixed base as polymorphic so base call uses complete this, and rebased fields so field_30/+38/players +48 match.
// tried allocated class size 0x2C via implicit vptr+0x28 payload; operator new size correct.
// tried condition spellings: type!=1, (type&0xff)!=1, int temp, unsigned temp with &=0xff/--temp. Best keeps 180B but hoists type load before FS registration and uses a different top compare/push family.
// tried /Ob0 (no help) and /O1 (too short); kept /GX because original has EH frame.
// left in scratch: body after branch is largely understood, but remaining mismatch is broad early EH/parameter scheduling and fallback push order, not accepted drift.
// Retry 2026-05-26 Boss pass: 15 probes on VA 0052E400 only. Revalidated baseline /GX: 180B, 73.8889% positional / 38.8889% edit, first mismatch +14 from type load before FS registration. Tried direct `type != 1`, `type == 1` else, unsigned-char temp, int temp with decrement, mutating `type`, saving `player` before/after branch, direct `p->init`, index local, manual placement-new (VC5 rejected), expression forms `((t&0xff)-1)==0` / `!=0`, no-temp casts, and flags /Ob0 /G5 /Oa /Oy- /O1 with /GX. Kept the int-temp/decrement variant because it improves to 67.7778% positional / 25.0000% edit and first mismatch +35, but it still has an extra `and eax,0xff` and shifts the allocation branch. GIVEUP: not accepted_drift quality; remaining drift is broad EH/type-test/fallback layout and shifted new/virtual-call path, not localized equivalent drift.

class RGE_Game_World {
public:
    virtual void v0();
    unsigned char init_player_type(int player, short index, unsigned char type);
};

class TRIBE_Master_Player {
public:
    char bytes[0x28];
    TRIBE_Master_Player(int player);
    virtual void v0();
    virtual void init(int player, int a, int b);
};

class TRIBE_World : public RGE_Game_World {
public:
    char gap_04[0x2C];
    int field_30;
    char gap_34[4];
    int field_38;
    char gap_3C[0x0C];
    TRIBE_Master_Player** players; // +0x48

    virtual unsigned char init_player_type(int player, short index, unsigned char type);
};

unsigned char TRIBE_World::init_player_type(int player, short index, unsigned char type)
{
    int t = type;
    t = (unsigned char)t;
    if (--t != 0) {
        return RGE_Game_World::init_player_type(player, index, type);
    }

    TRIBE_Master_Player* p = new TRIBE_Master_Player(player);
    this->players[index] = p;
    this->players[index]->init(player, this->field_38, this->field_30);
    return 1;
}
