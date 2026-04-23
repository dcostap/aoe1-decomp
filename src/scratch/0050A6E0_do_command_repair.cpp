// compact packet-processing shape first
// tried the direct packet decode and then an explicit RGE_Command base; mismatch stayed in the prolog/register basin
// remaining drift is the packet-field packing / register save order at the function entry

class RGE_Static_Object;
class TRIBE_Combat_Object;

struct RGE_Obj_Info {
    long id;
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Command {
public:
    char gap_00[0x4];
    RGE_Game_World* world;

    RGE_Static_Object* get_obj(int id);
};

class TRIBE_Command_Repair {
public:
    unsigned char command;
    unsigned char unit_num;
    unsigned char gap_02[2];
    RGE_Obj_Info target;
};

class TRIBE_Command : public RGE_Command {
public:
    RGE_Static_Object* do_command_repair(TRIBE_Command_Repair* packet);
};

class TRIBE_Combat_Object {
public:
    void do_repair(RGE_Static_Object* target);
};

RGE_Static_Object* TRIBE_Command::do_command_repair(TRIBE_Command_Repair* packet) {
    unsigned char unit_count = packet->unit_num;
    TRIBE_Command_Repair* entry = (TRIBE_Command_Repair*)(packet + 1);
    RGE_Static_Object* target = this->get_obj(packet->target.id);

    for (; unit_count != 0; --unit_count, ++entry) {
        RGE_Static_Object* obj = this->get_obj(entry->target.id);
        if (obj != 0) {
            ((TRIBE_Combat_Object*)obj)->do_repair(target);
        }
    }

    return target;
}
