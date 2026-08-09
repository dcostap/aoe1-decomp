// 00509980 TRIBE_Command::do_command_make
// Source: tcommand.cpp lines 143-205
// Attempt log:
// 1: natural source based on sibling do_command_research; /GX for EH-framed new+ctor cleanup: built 352 bytes (14 short).
// 2: volatile padding local forced size but wrong EH prologue/order; removed.
// 3: remove p local and pass &cmd; original reuses parameter stack slot for work_status progress and keeps cmd closer, but this/building regs still off.
// 4: add self local to keep this live in EBX like original; no change, later removed for smaller exact-size section.
// 5: add p alias for cmd while still passing &cmd to work_status: got EBX and closer fallback, but p/building regs swapped and extra EBP, size 352.
// 6: widen PlayerLike::make train_id parameter to int to force movsx instead of partial AX push.
// 7: split player fallback into progress-special lookup plus building-missing lookup with common virtual call; edit diff 22.1 but EBP/padding too large.
// 8: remove p alias again while keeping split fallback: still oversized/truncated and worse; rolled back to smaller merged fallback.
// Left in scratch: behavior/calls modeled, but first mismatch is EH funclet address/prologue metadata and register/coloring drift remains broad.
// This pass normalized TRIBE_Command to the shared RGE_Command inheritance;
// codegen stayed at 366B/318 strict bytes. The final natural typed candidate
// remains blocked by the EH prologue and duplicated-fallback CFG basin.
// Main-agent audit removed parameter-home aliasing, restored named work-status
// outputs, and canonicalized world/player/action ownership.

class UnitAIModule;
class RGE_Static_Object;
class TRIBE_Building_Object;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x3C];
    class TRIBE_Player** players;
    RGE_Static_Object* object(int id);
};

class UnitAIModule {
public:
    void setCurrentAction(int action);
    void setCurrentTarget(int id, int id2, float x, float y, float z);
};

class RGE_Static_Object_VTable208 {
public:
#define VPAD(n) virtual void v##n();
    virtual ~RGE_Static_Object_VTable208();
    VPAD(1) VPAD(2) VPAD(3) VPAD(4) VPAD(5) VPAD(6) VPAD(7)
    VPAD(8) VPAD(9) VPAD(10) VPAD(11) VPAD(12) VPAD(13) VPAD(14) VPAD(15)
    VPAD(16) VPAD(17) VPAD(18) VPAD(19) VPAD(20) VPAD(21) VPAD(22) VPAD(23)
    VPAD(24) VPAD(25) VPAD(26) VPAD(27) VPAD(28) VPAD(29) VPAD(30) VPAD(31)
    VPAD(32) VPAD(33) VPAD(34) VPAD(35) VPAD(36) VPAD(37) VPAD(38) VPAD(39)
    VPAD(40) VPAD(41) VPAD(42) VPAD(43) VPAD(44) VPAD(45) VPAD(46) VPAD(47)
    VPAD(48) VPAD(49) VPAD(50) VPAD(51) VPAD(52) VPAD(53) VPAD(54) VPAD(55)
    VPAD(56) VPAD(57) VPAD(58) VPAD(59) VPAD(60) VPAD(61) VPAD(62) VPAD(63)
    VPAD(64) VPAD(65) VPAD(66) VPAD(67) VPAD(68) VPAD(69) VPAD(70) VPAD(71)
    VPAD(72) VPAD(73) VPAD(74) VPAD(75) VPAD(76) VPAD(77) VPAD(78) VPAD(79)
    VPAD(80) VPAD(81) VPAD(82) VPAD(83) VPAD(84) VPAD(85) VPAD(86) VPAD(87)
    VPAD(88) VPAD(89) VPAD(90) VPAD(91) VPAD(92) VPAD(93) VPAD(94) VPAD(95)
    VPAD(96) VPAD(97) VPAD(98) VPAD(99) VPAD(100) VPAD(101) VPAD(102) VPAD(103)
    VPAD(104) VPAD(105) VPAD(106) VPAD(107) VPAD(108) VPAD(109) VPAD(110) VPAD(111)
    VPAD(112) VPAD(113) VPAD(114) VPAD(115) VPAD(116) VPAD(117) VPAD(118) VPAD(119)
    VPAD(120) VPAD(121) VPAD(122) VPAD(123) VPAD(124) VPAD(125) VPAD(126) VPAD(127)
    VPAD(128) VPAD(129)
#undef VPAD
    virtual void add_action(void* action);
};

class RGE_Static_Object : public RGE_Static_Object_VTable208 {
public:
    UnitAIModule* unitAI();
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    int work_status(void* command, short* local_76, short* local_78, char* work_name, int len);
};

class TRIBE_Player {
public:
#define PPAD(n) virtual void p##n();
    virtual ~TRIBE_Player();
    PPAD(1) PPAD(2) PPAD(3) PPAD(4) PPAD(5) PPAD(6) PPAD(7)
    PPAD(8) PPAD(9) PPAD(10) PPAD(11) PPAD(12) PPAD(13) PPAD(14) PPAD(15)
    PPAD(16) PPAD(17) PPAD(18) PPAD(19) PPAD(20) PPAD(21) PPAD(22) PPAD(23)
    PPAD(24) PPAD(25) PPAD(26) PPAD(27) PPAD(28) PPAD(29) PPAD(30) PPAD(31)
    PPAD(32) PPAD(33) PPAD(34) PPAD(35) PPAD(36) PPAD(37) PPAD(38) PPAD(39)
    PPAD(40) PPAD(41) PPAD(42) PPAD(43) PPAD(44) PPAD(45) PPAD(46) PPAD(47)
    PPAD(48) PPAD(49) PPAD(50) PPAD(51) PPAD(52) PPAD(53) PPAD(54) PPAD(55)
    PPAD(56) PPAD(57) PPAD(58) PPAD(59) PPAD(60) PPAD(61) PPAD(62) PPAD(63)
    PPAD(64) PPAD(65) PPAD(66)
#undef PPAD
    virtual void make(int p0, int train_id, int unit_id, int unique_id); // +0x10C
};

struct TRIBE_Command_Make {
    short progress;      // +0
    short work_target;   // +2
    int unit_id;         // +4
    unsigned char player_index; // +8
    char gap_09;
    short train_id;      // +0A
    int unique_id;       // +0C
};

class TRIBE_Action_Make_Obj {
public:
    virtual ~TRIBE_Action_Make_Obj();
    char gap_04[0x4C];
    TRIBE_Action_Make_Obj(RGE_Static_Object* obj, short train_id, int unique_id, char flag);
};

class TCommunications_Handler;

class RGE_Command {
public:
    virtual void vfunc0() = 0;
    virtual ~RGE_Command();
    virtual void vfunc8() = 0;
    virtual void vfuncC() = 0;

    RGE_Game_World* world;
    void* last_order;
    int last_order_size;
    unsigned int last_order_time;
    TCommunications_Handler* com_hand;
};

class TRIBE_Command : public RGE_Command {
public:
    void do_command_make(TRIBE_Command_Make* cmd);
};

void TRIBE_Command::do_command_make(TRIBE_Command_Make* cmd)
{
    short progress;
    short work_target;
    char work_name[100];
    TRIBE_Building_Object* building;

    building = (TRIBE_Building_Object*)this->world->object(cmd->unit_id);
    if (building != 0) {
        building->work_status(cmd, &progress, &work_target, work_name, 100);
        if (progress != 0x67 && progress != 0x66) {
            TRIBE_Action_Make_Obj* action = new TRIBE_Action_Make_Obj(building, cmd->train_id, cmd->unique_id, 0);
            if (action != 0) {
                building->add_action(action);
            }
            if (building->unitAI() != 0) {
                building->unitAI()->setCurrentAction(0x26c);
                building->unitAI()->setCurrentTarget(cmd->unique_id, -1, -1.0f, -1.0f, -1.0f);
                return;
            }
            return;
        }
    }

    TRIBE_Player* player = this->world->players[cmd->player_index];
    if (player != 0) {
        player->make(0, cmd->train_id, cmd->unit_id, cmd->unique_id);
    }
}
