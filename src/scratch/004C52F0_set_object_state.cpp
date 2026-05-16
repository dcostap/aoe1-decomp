// VA: 004C52F0 RGE_Static_Object::set_object_state
// Attempt log:
// try 1: behavioral reconstruction from asm/Ghidra: state transition hooks, garrison/commander propagation, sleep flag update.
// try 2: fixed virtual surfaces for no-arg release and three-arg return/release calls so source compiles.
// try 3: modeled old<3/new>=3 owner-attribute removal and resource release for player mode 2.
// try 4: modeled old<=3/new>=7 recycle-in hook.
// try 5: modeled carried-resource transition from state 2 to >=3 with return/release resource calls and master float gate.
// try 6: modeled state 7 entry return-resource call.
// try 7: modeled state byte store before commander propagation.
// try 8: modeled commander/list dynamic-array growth, object lookup, low-state/unitAI filters, and commander reassignment.
// try 9: /Od probe exact-size but wrong debug-basin codegen; removed.
// try 10: /GX probe no useful change; removed.
// left in scratch: current clean source is 704B vs original 787B with broad dynamic-array/vtable/control-flow drift, not accepted_drift-safe.

extern void* __cdecl operator new(unsigned int);
extern void __cdecl operator delete(void*);

class RGE_Game_World { public: void* object(int); };
class UnitAI { public: int group(); int commanderPriority(int); };
class RGE_Player { public: char gap[0x3c]; RGE_Game_World* world; };
class MasterObj { public: char gap[0x28]; float f28; char gap2c[0x100]; int v12c; };
class RGE_Static_Object {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0C(); virtual void vf10(); virtual void vf14();
    virtual void vf18(); virtual void take_attribute_from_owner(); virtual void vf20(); virtual void vf24(); virtual void vf28(); virtual void vf2C();
    virtual void vf30(); virtual void vf34(); virtual void vf38(); virtual void vf3C(); virtual void vf40(); virtual void vf44();
    virtual void vf48(); virtual void vf4C(); virtual void vf50(); virtual void recycleOut(); virtual void recycleIn(); virtual void vf5C();
    virtual void returnAttribute(RGE_Player*,int,int); virtual void releaseNoArg(); virtual void releaseResource(RGE_Player*,int,int);
    char gap_04[4]; int id; RGE_Player* player; char state; char sleepFlag; char gap_12[0x0A]; int carried; char gap20[0x44]; int* links; int linkCount; int linkMax; int leader; int payload; int commander;
    void set_sleep_flag(int);
    void set_object_state(unsigned char s);
};

void RGE_Static_Object::set_object_state(unsigned char s)
{
    unsigned char old = this->state;
    if (old == s) return;
    if (s >= 3 && old < 3) {
        this->take_attribute_from_owner();
        if (*(unsigned char*)((char*)this->player + 0xA6) == 2) this->releaseNoArg();
    }
    if (old <= 3 && s >= 7) this->recycleIn();
    if (s >= 3 && old == 2 && this->carried != 0) {
        this->returnAttribute(this->player,0,-1);
        if (((MasterObj*)this->player)->f28 > 0.0) this->releaseResource(this->player,1,-1);
    }
    if (old < 7 && s == 7 && this->carried != 0 && ((MasterObj*)this->player)->f28 > 0.0) {
        this->returnAttribute(this->player,1,-1);
    }
    this->state = s;
    if (s == 3 && this->commander == this->id && this->payload != 0 && this->linkCount > 1) {
        int newCommander = -1;
        for (int i = 0; i < this->linkCount; i++) {
            if (i > this->linkMax - 1) {
                int* nv = (int*)operator new(i * 4 + 4);
                if (nv) {
                    for (int j = 0; j < this->linkMax && j < i + 1; j++) nv[j] = this->links[j];
                    operator delete(this->links);
                    this->links = nv; this->linkMax = i + 1;
                }
            }
            if (this->links[i] == this->id) continue;
            if (i > this->linkMax - 1) {
                int* nv2 = (int*)operator new(i * 4 + 4);
                if (nv2) {
                    for (int j = 0; j < this->linkMax && j < i + 1; j++) nv2[j] = this->links[j];
                    operator delete(this->links);
                    this->links = nv2; this->linkMax = i + 1;
                }
            }
            RGE_Static_Object* obj = (RGE_Static_Object*)this->player->world->object(this->links[i]);
            if (obj && obj->state <= 2 && ((UnitAI*)obj->player)->group()) {
                if (newCommander == -1) {
                    if (i > this->linkMax - 1) {
                        int* nv3 = (int*)operator new(i * 4 + 4);
                        if (nv3) {
                            for (int j = 0; j < this->linkMax && j < i + 1; j++) nv3[j] = this->links[j];
                            operator delete(this->links);
                            this->links = nv3; this->linkMax = i + 1;
                        }
                    }
                    newCommander = this->links[i];
                }
                obj->commander = newCommander;
                if (this->links[i] == newCommander) ((UnitAI*)obj->player)->commanderPriority(((MasterObj*)this->payload)->v12c);
            }
        }
    }
    if (this->sleepFlag && this->state != 2 && this->state != 6) this->set_sleep_flag(0);
}
