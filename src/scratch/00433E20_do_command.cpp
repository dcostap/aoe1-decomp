// do_command — first pass (176B)
// VA: 00433E20
// Retry 2026-05-24 Boss pass in progress.

#ifndef COMMAND_TU_CONTEXT
class RGE_Command {
public:
    virtual void do_command(void* cmd);
    void do_command_order(void* cmd);
    void do_command_stop(void* cmd);
    void do_command_work(void* cmd);
    void do_command_move(void* cmd);
    void do_command_create(void* cmd);
    void do_command_add_attribute(void* cmd);
    void do_command_formation(void* cmd);
    void do_command_create_group(void* cmd);
    void do_command_destroy_group(void* cmd);
    void do_command_ai_order(void* cmd);
    void do_command_group_ai_order(void* cmd);
    void do_command_resign(void* cmd);
    void do_command_add_waypoint(void* cmd);
    void do_command_group_waypoint(void* cmd);
    void do_command_add_to_group(void* cmd);
    void do_command_remove_from_group(void* cmd);
};
#endif

void RGE_Command::do_command(void* cmd)
{
    switch (*(unsigned char*)cmd) {
    case 0:
        do_command_order(cmd);
        return;
    case 1:
        do_command_stop(cmd);
        return;
    case 2:
        do_command_work(cmd);
        return;
    case 3:
        do_command_move(cmd);
        return;
    case 4:
        do_command_create(cmd);
        return;
    case 5:
        do_command_add_attribute(cmd);
        return;
    case 6:
        do_command_formation(cmd);
        return;
    case 7:
        this->do_command(cmd);
        return;
    case 8:
        do_command_create_group(cmd);
        return;
    case 9:
        do_command_destroy_group(cmd);
        return;
    case 10:
        do_command_ai_order(cmd);
        return;
    case 11:
        do_command_resign(cmd);
        return;
    case 12:
        do_command_add_waypoint(cmd);
        return;
    case 14:
        do_command_add_to_group(cmd);
        return;
    case 15:
        do_command_remove_from_group(cmd);
        return;
    case 16:
        do_command_group_waypoint(cmd);
        return;
    case 17:
        do_command_group_ai_order(cmd);
        return;
    }
}
