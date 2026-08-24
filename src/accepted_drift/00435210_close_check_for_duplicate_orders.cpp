// ACCEPTED_DRIFT: switch dispatch uses eax versus edx for the command pointer/type index; jump table, helper calls, boolean tests, return values, and stack cleanup are equivalent.
// tried the natural switch form; VC5 still picked the wrong register basin for the selector byte
// Grouped-context retry: direct, named, and typed packet forms kept the same
// seven-byte register drift. Split declarations, enums, and register hints did
// not change the basin.
// BLOCKER: 00435260 matched in the larger context, but that class surface
// regressed exact anchors 004348F0 and 004351B0. The wrapper excludes both.
#ifndef COMMAND_TU_CONTEXT
struct RGE_Command_Order;
struct RGE_Command_Stop;

class RGE_Command {
protected:
    unsigned char duplicate_check_command_order(RGE_Command_Order* param_1);
    unsigned char duplicate_check_command_stop(RGE_Command_Stop* param_1);
    unsigned char close_check_for_duplicate_orders(unsigned char* param_1);
};
#endif

unsigned char RGE_Command::close_check_for_duplicate_orders(unsigned char* param_1) {
    unsigned char selector = *param_1;
    switch (selector) {
    case 0:
    case 2:
    case 3:
        if (this->duplicate_check_command_order((RGE_Command_Order*)param_1) != 0) {
            return 1;
        }
        break;
    case 1:
        if (this->duplicate_check_command_stop((RGE_Command_Stop*)param_1) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
