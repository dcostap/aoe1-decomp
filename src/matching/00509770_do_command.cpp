class RGE_Command {
public:
    virtual void vfunc0();
    virtual ~RGE_Command();
    virtual void vfunc8();
    virtual void vfuncC();
    void do_command(void* cmd);
};

class TRIBE_Command : public RGE_Command {
public:
    virtual void do_command_give_attribute(void* cmd);

    void do_command(void* cmd);
    void do_command_make(void* cmd);
    void do_command_research(void* cmd);
    void do_command_build(void* cmd);
    void do_command_build_wall(void* cmd);
    void do_command_explore(void* cmd);
    void do_command_game(void* cmd);
    void do_command_tribe_create(void* cmd);
    void do_command_cancel_build(void* cmd);
    void do_command_attack_ground(void* cmd);
    void do_command_trade_attribute(void* cmd);
    void do_command_repair(void* cmd);
    void do_command_unload(void* cmd);
    void do_command_queue(void* cmd);
};

extern "C" int __cdecl debug_rand(const char* file, int line);

void TRIBE_Command::do_command(void* cmd)
{
    debug_rand("C:\\msdev\\work\\age1_x1\\tcommand.cpp", 0x3F);
    switch (*(unsigned char*)cmd) {
    case 0x64:
        do_command_make(cmd);
        return;
    case 0x65:
        do_command_research(cmd);
        return;
    case 0x66:
        do_command_build(cmd);
        return;
    case 0x69:
        do_command_build_wall(cmd);
        return;
    case 0x68:
        do_command_explore(cmd);
        return;
    case 0x67:
        do_command_game(cmd);
        return;
    case 0x04:
        do_command_tribe_create(cmd);
        return;
    case 0x6A:
        do_command_cancel_build(cmd);
        return;
    case 0x6B:
        do_command_attack_ground(cmd);
        return;
    case 0x6C:
        do_command_give_attribute(cmd);
        return;
    case 0x6D:
        do_command_trade_attribute(cmd);
        return;
    case 0x6E:
        do_command_repair(cmd);
        return;
    case 0x6F:
        do_command_unload(cmd);
        return;
    case 0x77:
        do_command_queue(cmd);
        return;
    default:
        RGE_Command::do_command(cmd);
        return;
    }
}
