// VA: 00434290 do_command_stop (70 B)
// PDB source: Command.cpp lines 425-442

#pragma pack(push, 1)
struct RGE_Command_Stop {
    unsigned char command;    // +0
    unsigned char unit_num;   // +1
    int unit_ids[1];          // +2 (at least 1 element)
};
#pragma pack(pop)

class RGE_Game_World;
class RGE_Player;

class RGE_Static_Object {
public:
    virtual void vf00() = 0;
    virtual void vf04() = 0;
    virtual void vf08() = 0;
    virtual void vf0C() = 0;
    virtual void vf10() = 0;
    virtual void vf14() = 0;
    virtual void vf18() = 0;
    virtual void vf1C() = 0;
    virtual void vf20() = 0;
    virtual void vf24() = 0;
    virtual void vf28() = 0;
    virtual void vf2C() = 0;
    virtual void vf30() = 0;
    virtual void vf34() = 0;
    virtual void vf38() = 0;
    virtual void vf3C() = 0;
    virtual void vf40() = 0;
    virtual void vf44() = 0;
    virtual void vf48() = 0;
    virtual void vf4C() = 0;
    virtual void vf50() = 0;
    virtual void vf54() = 0;
    virtual void vf58() = 0;
    virtual void vf5C() = 0;
    virtual void vf60() = 0;
    virtual void vf64() = 0;
    virtual void vf68() = 0;
    virtual void vf6C() = 0;
    virtual void vf70() = 0;
    virtual void vf74() = 0;
    virtual void vf78() = 0;
    virtual void vf7C() = 0;
    virtual void vf80() = 0;
    virtual void vf84() = 0;
    virtual void vf88() = 0;
    virtual void vf8C() = 0;
    virtual void vf90() = 0;
    virtual void vf94() = 0;
    virtual void vf98() = 0;
    virtual void vf9C() = 0;
    virtual void vfA0() = 0;     // vt[40] = +0xA0
    virtual void stop() = 0;     // vt[41] = +0xA4

    int id;                      // +0x04
    void* master_obj;            // +0x08
    RGE_Player* owner;           // +0x0C

    void removeAllFromPathingGroup();
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Command {
public:
    virtual void vf00() = 0;
    virtual ~RGE_Command() {}
    virtual void vf08() = 0;
    virtual void vf0C() = 0;

    RGE_Game_World* world;       // +0x04

    RGE_Static_Object* get_obj(int id);
    void do_command_stop(RGE_Command_Stop* param_1);
};

void RGE_Command::do_command_stop(RGE_Command_Stop* param_1) {
    for (int count = (unsigned char)param_1->unit_num; count > 0; count--) {
        RGE_Static_Object* obj = get_obj(param_1->unit_ids[param_1->unit_num - count]);
        if (obj) {
            obj->removeAllFromPathingGroup();
            obj->stop();
        }
    }
}
