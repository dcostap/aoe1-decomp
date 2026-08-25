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
//   persistent units base were codegen-neutral or worse.  Ghidra's recovered
//   literal negative constants support -1/-1.5/-2 rather than mutable globals.
// - The natural reconstruction has exact frame, size, CFG signals, protected
//   ABI decoration, and six-call multiset; 347 strict bytes remain.
// - Reused one typed unit cursor across both scans to mirror the original
//   EDI cursor and saved-base lifetime; codegen was unchanged, so the clean
//   separate-cursor source remains the best reconstruction.
// - Reordered the first switch's 2/3 and 1/4/5 groups to match the original
//   literal blocks; this improved strict bytes from 363 to 355.
// - Moved only the second units assignment into its positive-count guard.  It
//   restored the original post-jle home store and improved strict bytes to 347.
// - Reused the named units cursor itself across both scans and reset it from
//   command->units; this moved the outer cursor into the original EDI/base-save
//   topology and reduced strict diff from 709 to 363 bytes.
// - Twenty focused probes tested switch scopes, update spellings, local order,
//   bool width, ABI access, flags, and standard-header context.  None removed
//   the six-instruction common-tail difference in the second switch.
// Accepted-drift review: the executable duplicates a six-instruction x87 store
// tail for formation cases zero and one. The rebuild shares it. Each predecessor
// reaches the tail with the same x87 order, and the stores keep the same order
// and values. Remaining drift is switch relocation and local register choice.
// All six calls and formation effects match.
// Exact translation-unit finish: the real earlier Command.cpp owner at
// 004348F0 selects the original second-switch tail. The shared command surface
// then matches all 775 bytes and six calls. Target-only compilation emits the
// reviewed shared-x87-tail drift.

#include <math.h>
#pragma intrinsic(sqrt)

#ifndef COMMAND_CONTEXT_H
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

#include "../../include/command_static_object_context.h"

class RGE_Command {
public:
    virtual ~RGE_Command();
    char gap_04[4];
    void* world;
protected:
    RGE_Static_Object* get_obj(RGE_Obj_Info info);
    void do_command_formation(RGE_Command_Formation* command);
};
#endif

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
        case 2:
        case 3:
            adjusted_y = 2.0f;
            temp_x = 2.0f;
            break;
        case 1:
        case 4:
        case 5:
            adjusted_y = 1.5f;
            temp_x = 1.5f;
            break;
        }

        int index = 0;
        if (index < unit_num) {
            units = command->units;
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
                            adjusted_y = adjusted_y - -1.0f;
                            adjusted_x = adjusted_x + temp_x;
                            temp_x = temp_x - -1.0f;
                            break;
                        case 1:
                            temp_count = temp_count + adjusted_y;
                            adjusted_y = adjusted_y - -1.5f;
                            adjusted_x = adjusted_x - temp_x;
                            temp_x = temp_x - -1.5f;
                            break;
                        case 2:
                            temp_count += adjusted_y;
                            adjusted_y = adjusted_y - -2.0f;
                            break;
                        case 3:
                            adjusted_x += temp_x;
                            temp_x = temp_x - -2.0f;
                            break;
                        case 5:
                            temp_count -= adjusted_y;
                            if (alternate == 0) {
                                adjusted_x -= temp_x;
                                alternate = 1;
                            } else {
                                adjusted_x += temp_x;
                                temp_x = temp_x - -1.5f;
                                adjusted_y = adjusted_y - -1.5f;
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
                                temp_x = temp_x - -1.5f;
                                adjusted_y = adjusted_y - -1.5f;
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
