// VA: 00434A00 RGE_Command::do_command_formation (775B)
// PDB: Command.cpp lines 723-864
// Attempt log:
// - Reconstructed the formation packet scan from the executable's two object
//   loops, closest-unit distance selection, formation switches, pathing-group
//   rebuild, and virtual move_to call.
// - The first natural build had exact frame/call parity but was 77 bytes too
//   large.  Swapping the distance terms to world_x then world_y matched the
//   x87 load topology.  Ordering the second switch as case 5 before case 4 and
//   making the zero-alternate arm the inline arm recovered the original shared
//   FPU tail and exact 775-byte size.
// - Explicit packet/self aliases, packet-plus-one cursors, and removal of the
//   persistent units base were codegen-neutral or worse.  Binding the proven
//   -1/-1.5/-2 constants to DAT_0056f4f4/f8/fc is retained as canonical global
//   ownership, though it did not move the current metric.
// - Current source is a natural typed reconstruction with exact frame, CFG
//   signals, and six-call multiset; 709 strict bytes remain, beginning in the
//   prologue/register basin at 00434A03 and extending through shifted blocks.
// - Reused one typed unit cursor across both scans to mirror the original
//   EDI cursor and saved-base lifetime; codegen was unchanged, so the clean
//   separate-cursor source remains the best reconstruction.
// - Reordered the first switch's natural 2/3 and 1/4/5 case groups to follow
//   the original jump-table block placement; strict bytes stayed at 709 and
//   the edit/resync diagnostic improved only, so restored the clean order.
// - Moved unit_num and units into the unit-count guard to mirror the original
//   post-compare home stores; this worsened strict diff to 718 and was restored.
// - Reused the named units cursor itself across both scans and reset it from
//   command->units; this moved the outer cursor into the original EDI/base-save
//   topology and reduced strict diff from 709 to 363 bytes.

#include <math.h>
#pragma intrinsic(sqrt)
#include "../../include/game_globals.h"

struct RGE_Obj_Info {
    int id;
};

struct RGE_Command_Formation {
    unsigned char command;
    unsigned char gap_01[3];
    int unitNum;
    int formationID;
    RGE_Obj_Info units[1];
};

class RGE_Static_Object {
public:
    virtual void vf00(void); virtual void vf04(void); virtual void vf08(void); virtual void vf0C(void);
    virtual void vf10(void); virtual void vf14(void); virtual void vf18(void); virtual void vf1C(void);
    virtual void vf20(void); virtual void vf24(void); virtual void vf28(void); virtual void vf2C(void);
    virtual void vf30(void); virtual void vf34(void); virtual void vf38(void); virtual void vf3C(void);
    virtual void vf40(void); virtual void vf44(void); virtual void vf48(void); virtual void vf4C(void);
    virtual void vf50(void); virtual void vf54(void); virtual void vf58(void); virtual void vf5C(void);
    virtual void vf60(void); virtual void vf64(void); virtual void vf68(void); virtual void vf6C(void);
    virtual void vf70(void); virtual void vf74(void); virtual void vf78(void); virtual void vf7C(void);
    virtual void vf80(void); virtual void vf84(void); virtual void vf88(void); virtual void vf8C(void);
    virtual void vf90(void); virtual void vf94(void); virtual void vf98(void);
    virtual void move_to(void* target, float x, float y, float z);
    virtual void vfA0(void); virtual void vfA4(void); virtual void vfA8(void); virtual void vfAC(void);
    virtual void vfB0(void); virtual void vfB4(void); virtual void vfB8(void); virtual void vfBC(void);
    virtual void vfC0(void); virtual void vfC4(void); virtual void vfC8(void); virtual void vfCC(void);
    virtual void vfD0(void); virtual void vfD4(void); virtual void vfD8(void); virtual void vfDC(void);
    virtual void vfE0(void); virtual void vfE4(void); virtual void vfE8(void); virtual void vfEC(void);
    virtual void vfF0(void); virtual void vfF4(void); virtual void vfF8(void); virtual void vfFC(void);
    virtual void vf100(void); virtual void vf104(void); virtual void vf108(void); virtual void vf10C(void);
    virtual void vf110(void); virtual void vf114(void); virtual void vf118(void); virtual void vf11C(void);
    virtual void vf120(void); virtual void vf124(void); virtual void vf128(void);
    virtual void setWaitingToMove(unsigned char waiting);

    long id;
    void* master_obj;
    void* owner;
    char gap_10[0x28];
    float world_x;
    float world_y;
    float world_z;

    void removeAllFromPathingGroup(void);
    void addToPathingGroup(int group_index);
};

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_04[4];
    void* world;
    RGE_Static_Object* get_obj(RGE_Obj_Info info);
    void do_command_formation(RGE_Command_Formation* command);
};

void RGE_Command::do_command_formation(RGE_Command_Formation* command)
{
    int unit_num = command->unitNum;
    RGE_Obj_Info* units = command->units;

    if (unit_num > 1) {
        RGE_Static_Object* reference_unit = 0;
        float distance;
        int i = 0;
        if (i < unit_num) {
            do {
                RGE_Static_Object* object = this->get_obj(*units);
                if (object != 0) {
                    float object_distance =
                        (float)sqrt(object->world_x * object->world_x +
                                    object->world_y * object->world_y);
                    if (i == 0 || object_distance < distance) {
                        reference_unit = object;
                        distance = object_distance;
                    }
                }
                ++i;
                ++units;
            } while (i < unit_num);
        }

        float adjusted_y = 1.0f;
        float temp_x = 1.0f;
        int alternate = 0;
        switch (command->formationID) {
        case 0:
            adjusted_y = 1.0f;
            temp_x = 1.0f;
            break;
        case 1:
        case 4:
        case 5:
            adjusted_y = 1.5f;
            temp_x = 1.5f;
            break;
        case 2:
        case 3:
            adjusted_y = 2.0f;
            temp_x = 2.0f;
            break;
        }

        int index = 0;
        units = command->units;
        if (index < unit_num) {
            do {
                RGE_Static_Object* object = this->get_obj(*units);
                if (object != 0) {
                    object->removeAllFromPathingGroup();
                    object->setWaitingToMove(1);

                    int other_index = 0;
                    RGE_Obj_Info* other_unit = command->units;
                    do {
                        if (other_index != index)
                            object->addToPathingGroup(other_unit->id);
                        ++other_index;
                        ++other_unit;
                    } while (other_index < unit_num);

                    if (object != reference_unit) {
                        float temp_count = reference_unit->world_x;
                        float adjusted_x = reference_unit->world_y;

                        switch (command->formationID) {
                        case 0:
                            temp_count += adjusted_y;
                            adjusted_y -= DAT_0056f4f4;
                            adjusted_x += temp_x;
                            temp_x -= DAT_0056f4f4;
                            break;
                        case 1:
                            temp_count += adjusted_y;
                            adjusted_y -= DAT_0056f4f8;
                            adjusted_x -= temp_x;
                            temp_x -= DAT_0056f4f8;
                            break;
                        case 2:
                            temp_count += adjusted_y;
                            adjusted_y -= DAT_0056f4fc;
                            break;
                        case 3:
                            adjusted_x += temp_x;
                            temp_x -= DAT_0056f4fc;
                            break;
                        case 5:
                            temp_count -= adjusted_y;
                            if (alternate == 0) {
                                adjusted_x -= temp_x;
                                alternate = 1;
                            } else {
                                adjusted_x += temp_x;
                                temp_x -= DAT_0056f4f8;
                                adjusted_y -= DAT_0056f4f8;
                                alternate = 0;
                            }
                            break;
                        case 4:
                            temp_count += adjusted_y;
                            if (alternate == 0) {
                                adjusted_x -= temp_x;
                                alternate = 1;
                            } else {
                                adjusted_x += temp_x;
                                temp_x -= DAT_0056f4f8;
                                adjusted_y -= DAT_0056f4f8;
                                alternate = 0;
                            }
                            break;
                        }

                        object->move_to(0, temp_count, adjusted_x, 1.0f);
                    }
                }
                ++index;
                ++units;
            } while (index < unit_num);
        }
    }
}
