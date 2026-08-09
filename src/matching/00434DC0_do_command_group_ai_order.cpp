// VA: 00434DC0 do_command_group_ai_order (239B)
// Command.cpp:894-923
//
// Attempt log:
// - Baseline scratch was only a partial field store and had no calls/loop.
// - Reconstructed the packet, recipient-id array, object lookup, coordinate
//   fallback, pathing cleanup, and player processAIOrder call from the binary.
// - Natural float comparisons entered an x87 basin; the executable instead
//   compares the -1.0 coordinate bit pattern as an integer while forwarding
//   the coordinates as float values.  Raw dword lvalues preserve that proven
//   sentinel behavior and ordinary float assignments preserve stack homes.
// - Keeping the command object across get_obj/removeAllFromPathingGroup and
//   splitting the pre-guard recipient base from the loop cursor recovered the
//   EBX/ESI frame, all three ordered calls, all branch bodies, and 239-byte
//   size parity.  A separate loop counter keeps the count home in the
//   original incoming-parameter slot.
// - Probes 1-9 tested the natural loop/cursor scope, raw versus typed
//   coordinate surfaces, self/declaration order, explicit fallback arms, and
//   count lifetime.  Best before the final base split was 221 strict-diff
//   bytes with 94.56% resync similarity; several source forms were codegen
//   duplicates or regressed to x87/incorrect saved-register layouts.
// - Probe 10 (current) reaches 6 strict-diff bytes, 95.70% exact-block
//   coverage, 3/3 ordered calls, exact size/frame, and 2/2 relocation identity.
//   Remaining drift is one localized prologue ordering hunk: the executable
//   stores the count home before moving the precomputed recipient base into
//   EBP; VC5 emits those two operations in the opposite order here.
// - Main-agent audit restored canonical polymorphic ownership for command,
//   player, and static object; emitted code is unchanged.
// - Probe 13 (new claim) declared the recipient cursor before the loop count
//   inside the positive guard.  The natural declaration/initialization order
//   makes VC5 move the cursor into EBP before storing the reused count home,
//   producing an exact 239-byte match with the canonical typed surfaces.

struct RGE_Obj_Info {
    int id;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    int id;
    char gap_08[0x30];
    float world_x;
    float world_y;
    float world_z;

    void removeAllFromPathingGroup();
};

class RGE_Player {
public:
    virtual ~RGE_Player(); virtual void v04();  virtual void v08();
    virtual void v0C();  virtual void v10();  virtual void v14();
    virtual void v18();  virtual void v1C();  virtual void v20();
    virtual void v24();  virtual void v28();  virtual void v2C();
    virtual void v30();
    virtual void processAIOrder(int issuer, int object_id, int order_type,
                                int target, int target_owner, float target_x,
                                float target_y, float target_z, float range,
                                unsigned int immediate, unsigned int in_front,
                                unsigned int order_priority);
};

class RGE_Game_World {
public:
    char gap_00[0x40];
    RGE_Player** players;
};

struct RGE_Command_Group_AI_Order {
    unsigned char command;
    unsigned char player_id;
    unsigned char issuer;
    unsigned char recipient_count;
    short orderType;
    unsigned char orderPriority;
    unsigned char gap_07;
    int target;
    unsigned char targetOwner;
    unsigned char gap_0D[3];
    float targetX;
    float targetY;
    float targetZ;
    float range;
    unsigned char immediate;
    unsigned char inFront;
    unsigned char gap_22[2];
};

class RGE_Command {
public:
    virtual ~RGE_Command();
    RGE_Game_World* world;

    RGE_Static_Object* get_obj(RGE_Obj_Info info);
    void do_command_group_ai_order(RGE_Command_Group_AI_Order* command);
};

void RGE_Command::do_command_group_ai_order(RGE_Command_Group_AI_Order* command)
{
    RGE_Command* self = this;
    int count = command->recipient_count;
    RGE_Obj_Info* recipient_base = (RGE_Obj_Info*)(command + 1);

    if (count > 0) {
        RGE_Obj_Info* recipients = recipient_base;
        int loop_count = count;
        do {
            RGE_Static_Object* object = self->get_obj(*recipients);
            if (object != 0) {
                int default_coord = -1082130432;
                float target_x;
                if (*(int*)&command->targetX != default_coord)
                    target_x = command->targetX;
                else
                    target_x = object->world_x;

                float target_y;
                if (*(int*)&command->targetY != default_coord)
                    target_y = command->targetY;
                else
                    target_y = object->world_y;

                float target_z;
                if (*(int*)&command->targetZ != default_coord)
                    target_z = command->targetZ;
                else
                    target_z = object->world_z;

                object->removeAllFromPathingGroup();

                RGE_Player* player = self->world->players[command->player_id];
                player->processAIOrder(command->issuer, object->id,
                                       command->orderType, command->target,
                                       command->targetOwner, target_x, target_y,
                                       target_z, command->range,
                                       command->immediate, command->inFront,
                                       command->orderPriority);
            }
            ++recipients;
            --loop_count;
        } while (loop_count != 0);
    }
}
