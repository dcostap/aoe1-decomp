// VA: 00509AF0 TRIBE_Command::do_command_research
// Source: tcommand.cpp lines 209-251
// FLAGS: config/flags/00509AF0_do_command_research.rsp uses /GX for EH-framed new+ctor cleanup.
// Attempt log:
// initial natural source from packet/decompiler with local vtable surfaces.
// /GX is required for EH-framed operator new + ctor cleanup; without /GX the function is much too small (288B text).
// natural source with &cmd work_status and direct cmd use compiles to 352B text (original 364B): correct EH frame/local size/new region family, but no EBX save and wrong long-lived register topology (compiler keeps this in EDI/building in ESI instead of original EBX/EDI and does not preserve cmd in ESI).
// tried p=cmd local plus self=this local/register variants to force cmd/self liveness: either optimized away or worsened to extra EBP save/stack p home while still 352B.
// tried passing &p versus &cmd to work_status: &p is wrong for original parameter-slot overwrite; &cmd restores the intended stack slot use but still misses original ESI=cmd / EDI=building allocation.
// tried /Od as a diagnostic: produced 364B but 83% positional mismatch and wrong frame; rolled back.
// left unresolved: behavior/call set appear modeled, but VC5 register-allocation/TU-context basin is still wrong and check_function reports configured size 364 exceeds rebuilt .text 352 under the kept /GX flags.

class RGE_Static_Object;
class TRIBE_Building_Object;
class UnitAIModule;
class TRIBE_Action_Make_Tech;

class RGE_Game_World {
public:
    char gap_00[0x40];
    void** players; // +0x40
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
    VPAD(0) VPAD(1) VPAD(2) VPAD(3) VPAD(4) VPAD(5) VPAD(6) VPAD(7)
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
    virtual void add_action(void* action); // +0x208
};

class RGE_Static_Object : public RGE_Static_Object_VTable208 {
public:
    UnitAIModule* unitAI();
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    int work_status(void* command, short* local_76, short* local_78, char* work_name, int len);
};

class PlayerLike {
public:
#define PPAD(n) virtual void p##n();
    PPAD(0) PPAD(1) PPAD(2) PPAD(3) PPAD(4) PPAD(5) PPAD(6) PPAD(7)
    PPAD(8) PPAD(9) PPAD(10) PPAD(11) PPAD(12) PPAD(13) PPAD(14) PPAD(15)
    PPAD(16) PPAD(17) PPAD(18) PPAD(19) PPAD(20) PPAD(21) PPAD(22) PPAD(23)
    PPAD(24) PPAD(25) PPAD(26) PPAD(27) PPAD(28) PPAD(29) PPAD(30) PPAD(31)
    PPAD(32) PPAD(33) PPAD(34) PPAD(35) PPAD(36) PPAD(37) PPAD(38) PPAD(39)
    PPAD(40) PPAD(41) PPAD(42) PPAD(43) PPAD(44) PPAD(45) PPAD(46) PPAD(47)
    PPAD(48) PPAD(49) PPAD(50) PPAD(51) PPAD(52) PPAD(53) PPAD(54) PPAD(55)
    PPAD(56) PPAD(57) PPAD(58) PPAD(59) PPAD(60) PPAD(61) PPAD(62) PPAD(63)
    PPAD(64) PPAD(65) PPAD(66) PPAD(67) PPAD(68) PPAD(69)
#undef PPAD
    virtual void research(short tech_id, int unit_id, int p3, int unique_id); // +0x118
};

struct TRIBE_Command_Research {
    short progress;      // +0
    short work_target;   // +2
    int unit_id;         // +4
    unsigned char player_index; // +8
    char gap_09;
    short tech_id;       // +0A
    int unique_id;       // +0C
};

class TRIBE_Action_Make_Tech {
public:
    char gap[0x48];
    TRIBE_Action_Make_Tech(RGE_Static_Object* obj, short tech_id, int unique_id);
};

class TRIBE_Command {
public:
    void* vtable;
    RGE_Game_World* world;
    void do_command_research(TRIBE_Command_Research* cmd);
};

void TRIBE_Command::do_command_research(TRIBE_Command_Research* cmd)
{
    short progress;
    short work_target;
    short local_78;
    short local_76;
    char work_name[100];
    TRIBE_Building_Object* building;

    building = (TRIBE_Building_Object*)this->world->object(cmd->unit_id);
    if (building != 0) {
        building->work_status(&cmd, &local_76, &local_78, work_name + 4, 100);
        progress = *(short*)&cmd;
        if (progress != 0x67 && progress != 0x66) {
            TRIBE_Action_Make_Tech* action = new TRIBE_Action_Make_Tech(building, cmd->tech_id, cmd->unique_id);
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

    PlayerLike* player = (PlayerLike*)this->world->players[cmd->player_index];
    if (player != 0) {
        player->research(cmd->tech_id, cmd->unit_id, -1, cmd->unique_id);
    }
}
