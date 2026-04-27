// attempt 1: packet loop over ids with get_obj lookup and a 3-byte waypoint local
// target shape: byte 1 is count, ids start at +4, and each found object sends a tiny waypoint payload through owner slot +0x48
// paused here: the packet loop is understood, but VC5 is still choosing the wrong prolog / count-local basin versus the packet

typedef unsigned char uchar;

class RGE_Command_Group_Waypoint {
public:
    uchar command;
    uchar unit_num;
    uchar x;
    uchar y;
};

class RGE_Command;
class RGE_Static_Object;

class RGE_Object_Owner {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void vf34(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void send_waypoint(int id, unsigned char* waypoint, int push_order);
};

class RGE_Static_Object {
public:
    int id;
    char gap_04[0x8];
    RGE_Object_Owner* owner;
};

class RGE_Game_World;

class RGE_Command {
public:
    char gap_00[0x4];
    RGE_Game_World* world;

    RGE_Static_Object* get_obj(int id);
    void do_command_group_waypoint(RGE_Command_Group_Waypoint* packet);
};

void RGE_Command::do_command_group_waypoint(RGE_Command_Group_Waypoint* packet) {
    int count;
    int* ids;
    unsigned char waypoint[3];

    if (packet->unit_num <= 0) {
        return;
    }
    count = packet->unit_num;
    ids = (int*)((char*)packet + 4);

    do {
        RGE_Static_Object* obj = this->get_obj(*ids);
        if (obj != 0) {
            waypoint[0] = packet->x;
            waypoint[1] = packet->y;
            waypoint[2] = 0;
            obj->owner->send_waypoint(obj->id, waypoint, 1);
        }
        ++ids;
        --count;
    } while (count != 0);
}
