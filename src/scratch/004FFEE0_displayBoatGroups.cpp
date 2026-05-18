// VA: 004FFEE0 TribeTacticalAIModule::displayBoatGroups
// taitacmd.cpp
// Attempt log:
// try 1: natural reconstruction from packet: walk boat group linked list, type-specific logging, stats, positions, per-boat loop.
// try 2: modeled list sentinel at this+0x9D4/next +0x9D8 and loop exit on sentinel/null.
// try 3: modeled TacticalAIGroup methods for observed calls: type 004EAF60, id 004EAF20, count 004EB2C0, object id 004EB2D0, stat getters and position getters.
// try 4: modeled first type filter exactly as repeated `type()` calls for 0x67,0x68,0x69,0x6B,0x6C,0x6A rather than caching type.
// try 5: modeled type-specific log strings at 0x58893C/0x588914/0x5888E8/0x588A6C/0x588A44/0x588A18 and shared log call.
// try 6: modeled stat summary and position logs with double promotion from float getters/fields.
// try 7: initially used `logCommonHistory(char*, ...)`; compiled equal 889B after adding player lookup, but broad 69.63% positional diff and first mismatch at prologue: compiler emitted EBP frame/stack alignment (`push ebp; mov ebp,esp; and esp,-8; sub esp,8`) while original is frameless push ebx/ebp/esi/edi.
// try 8: added Player::find_object(id) call for the observed 0040D760 lookup; this fixed size from 880B to 889B in varargs version.
// try 9: replaced varargs log declaration with fixed overloads to avoid stack-realignment prologue; this removed the EBP frame but shrank .text to 864B vs original 889B.
// try 10: added fixed overloads for all log arities including double/double and final boat detail log; still 864B, so overload approach loses original varargs-like call surface/size while varargs causes wrong prologue.
// left in scratch: behavior/call set is broad, but exact logCommonHistory declaration/calling surface is unresolved. Need original frameless prologue plus varargs-sized call code. No accepted_drift: broad drift from prologue/call surface.

struct Vec2 { float x; float y; };

class RGE_Static_Object {
public:
    char gap_00[0x38];
    float x;
    float y;
    char gap_40[8];
    unsigned char owner;
    void* master_obj();
};

class MasterObj {
public:
    int name1();
    int name2();
    int name3();
    int name4();
};

class TacticalAIGroup {
public:
    TacticalAIGroup* prev;
    TacticalAIGroup* next;
    int type();
    int id();
    int count();
    int get_object(int i);
    int v1(); int v2(); int v3(); int v4(); int v5(); int v6();
    Vec2* pos1(); Vec2* pos2(); Vec2* pos3(); Vec2* pos4();
};

class Player {
public:
    RGE_Static_Object* find_object(int id);
};

class TribeTacticalAIModule {
public:
    char gap_000[0xF0];
    Player* player;
    char gap_0F4[0x8E0];
    TacticalAIGroup sentinel; // +9D4 prev +9D8 next
    void logCommonHistory(char* fmt);
    void logCommonHistory(char* fmt, int a);
    void logCommonHistory(char* fmt, int a, int b);
    void logCommonHistory(char* fmt, int a, int b, int c, int d, int e);
    void logCommonHistory(char* fmt, int a, int b, void* c, int d, int e, int f);
    void logCommonHistory(char* fmt, double a, double b);
    void logCommonHistory(char* fmt, int a, int b, int c, int d, int e, int f, int g, double h, double i);
    void displayBoatGroups();
};

void TribeTacticalAIModule::displayBoatGroups() {
    this->logCommonHistory((char*)0x588A98);
    TacticalAIGroup* g = this->sentinel.next;
    while (g != &this->sentinel && g != 0) {
        int t = g->type();
        if (t == 0x67 || g->type() == 0x68 || g->type() == 0x69 || g->type() == 0x6b || g->type() == 0x6c || g->type() == 0x6a) {
            if (g->type() == 0x67) {
                this->logCommonHistory((char*)0x58893C, g->id(), g->type());
            } else if (g->type() == 0x68) {
                this->logCommonHistory((char*)0x588914, g->id(), g->type());
            } else if (g->type() == 0x69) {
                this->logCommonHistory((char*)0x5888E8, g->id(), g->type());
            } else if (g->type() == 0x6b) {
                this->logCommonHistory((char*)0x588A6C, g->id(), g->type());
            } else if (g->type() == 0x6c) {
                this->logCommonHistory((char*)0x588A44, g->id(), g->type());
            } else if (g->type() == 0x6a) {
                this->logCommonHistory((char*)0x588A18, g->id(), g->type());
            }
            this->logCommonHistory((char*)0x588874, g->v5(), g->v4(), g->v3(), g->v2(), g->v1());
            this->logCommonHistory((char*)0x5889DC, g->v6(), g->v4(), this->player, g->v3(), g->v2(), g->v5());
            this->logCommonHistory((char*)0x5887A8, g->pos1()->x, g->pos1()->y);
            this->logCommonHistory((char*)0x588788, g->pos2()->x, g->pos2()->y);
            this->logCommonHistory((char*)0x588768, g->pos3()->x, g->pos3()->y);
            this->logCommonHistory((char*)0x587F58, g->pos4()->x, g->pos4()->y);
            int i = 0;
            if (g->count() > 0) {
                do {
                    this->logCommonHistory((char*)0x5889CC, g->get_object(i));
                    RGE_Static_Object* obj = this->player->find_object(g->get_object(i));
                    if (obj == 0) {
                        this->logCommonHistory((char*)0x5883D4);
                    } else if (obj->master_obj() == 0) {
                        this->logCommonHistory((char*)0x5883B4);
                    } else {
                        MasterObj* m = (MasterObj*)obj->master_obj();
                        this->logCommonHistory((char*)0x588974, g->get_object(i), i, (int)obj->owner, m->name4(), m->name3(), m->name2(), m->name1(), obj->x, obj->y);
                    }
                    i++;
                } while (i < g->count());
            }
        }
        g = g->next;
    }
}
