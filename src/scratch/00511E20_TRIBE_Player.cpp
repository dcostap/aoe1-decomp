// 00511E20 TRIBE_Player::TRIBE_Player(...)
// Source: tplayer.cpp lines 287-329
// FLAGS: config/flags/00511E20_TRIBE_Player.rsp
// Attempt log:
// - Initial natural constructor reconstruction from packet/decompiler.
// - Kept /GX because original has EH registration and many operator new + constructor cleanup states.
// - First typed-field attempt had bad local class layout (negative pads); rewrote as raw-offset TRIBE_Player surface with RGE_Player base initializer.
// - Current source compiles same-size 706B but broad mismatch: positional 82.5779%, edit 79.0368%, first mismatch at offset 0. Rebuilt EH prologue order differs (mov fs before push -1/handler), and broad drift follows through base-ctor argument setup, EH state stores, new/object-list construction, AI construction, relation loop, debug_rand arithmetic, history/tech construction, and epilogue. Not accepted_drift-safe.

void* __cdecl operator new(unsigned int);
extern int __cdecl debug_rand(char*, int);
extern void* comm;

class TRIBE_World { public: char gap0[0x28]; void* map; char gap2C[0x104-0x2C]; void* tech; };
class RGE_Master_Player;
class RGE_Player { public: RGE_Player(TRIBE_World*, RGE_Master_Player*, unsigned char, char*, unsigned char, unsigned char); void set_relation(int, char); };
class Visible_Resource_Manager { public: Visible_Resource_Manager(RGE_Player*, int); };
class TCommunications_Handler { public: int IsHost(); };
class TribeMainDecisionAIModule { public: TribeMainDecisionAIModule(int, int, char*, void*, char*, char*, char*); };
class RGE_Object_List { public: RGE_Object_List(); int vptr; };
class RGE_Visible_Map { public: RGE_Visible_Map(void*, RGE_Player*); };
class TRIBE_History_Info { public: TRIBE_History_Info(int); };
class TRIBE_Player_Tech { public: TRIBE_Player_Tech(void*, RGE_Player*, char); };

class TRIBE_Player : public RGE_Player {
public:
    char bytes[0x848];
    TRIBE_Player(TRIBE_World*, RGE_Master_Player*, unsigned char, char*, unsigned char, unsigned char, unsigned char, char*, char*, char*);
    void new_victory();
    void set_relation(int, char);
};

#define FIELD(type, off) (*(type*)((char*)this + (off)))

TRIBE_Player::TRIBE_Player(TRIBE_World* world, RGE_Master_Player* master, unsigned char p3, char* name, unsigned char p5, unsigned char make_ai, unsigned char make_lists, char* a, char* b, char* c)
    : RGE_Player(world, master, p3, name, p5, 0)
{
    FIELD(TribeMainDecisionAIModule*, 0x238) = 0;
    *(int*)this = 0x00576870;
    FIELD(Visible_Resource_Manager*, 0x110) = new Visible_Resource_Manager((RGE_Player*)this, 5);
    if (make_ai == 0) {
        FIELD(unsigned char, 0x48) = 1;
    } else {
        FIELD(unsigned char, 0x48) = 3;
        FIELD(int, 4) = 1;
        if (((TCommunications_Handler*)comm)->IsHost() == 1) {
            FIELD(TribeMainDecisionAIModule*, 0x238) = new TribeMainDecisionAIModule(0, FIELD(short,0x4A), FIELD(char*,0x44), this, a, b, c);
        }
    }
    if (make_lists) {
        RGE_Object_List* l;
        l = new RGE_Object_List(); if (l) l->vptr = 0x0057699c; FIELD(RGE_Object_List*,0x28) = l;
        l = new RGE_Object_List(); if (l) l->vptr = 0x0057699c; FIELD(RGE_Object_List*,0x2C) = l;
        l = new RGE_Object_List(); if (l) l->vptr = 0x0057699c; FIELD(RGE_Object_List*,0x30) = l;
        this->new_victory();
        FIELD(RGE_Visible_Map*,0x38) = new RGE_Visible_Map(world->map, (RGE_Player*)this);
    }
    int i = 1;
    if (*(short*)(FIELD(char*,0x3C) + 0x3c) > 1) {
        do {
            if (i != FIELD(short,0x4A)) ((RGE_Player*)this)->set_relation(i, 3);
            i++;
        } while (i < *(short*)(FIELD(char*,0x3C) + 0x3c));
    }
    FIELD(int,0x228) = 0;
    FIELD(int,0x22C) = 0;
    FIELD(int,0x230) = 0;
    FIELD(int,0x224) = (debug_rand((char*)0x0058AC44, 0x140) * 3) / 0x7fff + 3;
    FIELD(int,0x234) = 0;
    FIELD(TRIBE_History_Info*,0x83C) = new TRIBE_History_Info(-1);
    FIELD(TRIBE_Player_Tech*,0x220) = new TRIBE_Player_Tech(world->tech, (RGE_Player*)this, 1);
    FIELD(float,0x840) = -1.0f;
    FIELD(float,0x844) = -1.0f;
}
