// ACCEPTED_DRIFT: register-width/count-carrier drift only. Rebuilt keeps the byte count in bl and this in edi instead of zero-extending count to edi and this to ebx; nonzero byte counts execute the same number of iterations, with the same get_obj/do_repair calls and target pointer.
// compact packet-processing shape first
// tried direct packet decode and explicit RGE_Command base; mismatch stayed in the prolog/register basin
// tried void return with structured loop; worse prolog, so now spelling startup in original load order

class RGE_Static_Object;
class TRIBE_Combat_Object;

struct RGE_Obj_Info { long id; };

class RGE_Game_World { public: RGE_Static_Object* object(int id); };

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
    RGE_Obj_Info unit_ids[1];
};

class TRIBE_Command : public RGE_Command {
public:
    void do_command_repair(TRIBE_Command_Repair* packet);
};

class TRIBE_Combat_Object { public: void do_repair(RGE_Static_Object* target); };

void TRIBE_Command::do_command_repair(TRIBE_Command_Repair* packet)
{
    int target_id = packet->target.id;
    unsigned char unit_count = packet->unit_num;
    RGE_Obj_Info* ids = packet->unit_ids;
    RGE_Static_Object* target = this->get_obj(target_id);

    if ((int)unit_count > 0) {
        do {
            RGE_Static_Object* obj = this->get_obj(ids->id);
            if (obj != 0) {
                ((TRIBE_Combat_Object*)obj)->do_repair(target);
            }
            ++ids;
            --unit_count;
        } while (unit_count != 0);
    }
}
