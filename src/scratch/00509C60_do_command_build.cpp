// VA: 00509C60 TRIBE_Command::do_command_build
// tcommand.cpp lines 256-331
// Attempt log:
// 1: natural structured source from packet/decompiler: 416 B, frame 8 not original 0xC; count tested as byte.
// 2: introduced int count local loaded from cmd->count early: restored original early prologue/load order through player lookup, still frame 8 and 416 B.
// 3: widened placementResult storage to int while passing uchar*: worsened to 400 B; rolled back.
// 4: split count declaration/assignment: no material change, still 416 B.
// 5: volatile count stack-forcing: section 432 B, first mismatch still frame imm and broad extra volatile traffic; rolled back.
// 6: positive count comparisons (0 < count) instead of count <= 0: no size/layout improvement.
// 7: local one variable for can_place constant args optimized away/no improvement.
// 8: flags /O2 no-/Oy, /Ox, and /GX: same 416 B outcome.
// Left in scratch: behavior/call surface is modeled and early load order is close, but VC5 standalone keeps a 0x08 frame instead of original 0x0C and then broad branch/register displacement drift remains. Not accepted_drift-safe.
// This pass normalized the shared RGE_Command base and retested declaration
// order/self-alias context; output stayed at 405B/250 strict bytes, frame
// 0x08 versus 0x0C. Final candidate is natural and validated in scratch.
// Main-agent audit restored canonical polymorphic world/static/player/build
// ownership while retaining the ordinary placement/foundation branches.
// 9: ground-truth ABI pass changed command coordinates to float, IDs to RGE_Obj_Info, the player call to cancelBuild, the foundation call to make_new_obj, and the object call to do_command; size moved 405 -> 411 but the frame stayed 0x08.
// 10: nested the placement/pay/foundation arms to mirror the PDB line topology; it was slightly worse (407 B), so the natural early-return form remains authoritative.
// 11: tested int placementResult against the proven check_placement int* metadata; it regressed broadly and was rolled back to the binary-supported uchar local.
// 12-13: local declaration order and named command self alias were tested; emitted code was unchanged at 411 B/250 strict bytes.
// Current pause: canonical float/object/virtual surfaces and early-return behavior are modeled; remaining structural blocker is VC5's 0x08 standalone frame versus original 0x0C, shifting otherwise aligned stack homes by four bytes. Best output is 411/418 B, 10/10 ordered calls, CFG 12/12, 250 strict bytes.
// Main-agent audit removed the diagnostic command self-alias; direct member calls
// remain the canonical source even though the alias was codegen-neutral.
// Recovery: rebuilt the clean pinned source after the host crash; output stayed
// at 411/418 B and 250 strict bytes. No new evidence-backed structural lead
// remains, so this typed reconstruction stays in scratch.

typedef unsigned char uchar;

class RGE_Static_Object;
class RGE_Player;
class RGE_Master_Static_Object;
struct RGE_Obj_Info {
    int id;
};

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x3C];
    RGE_Player** players;
};

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
    void* com_hand;

    RGE_Static_Object* get_obj(RGE_Obj_Info id);
};

class RGE_Static_Object {
public:
#define OPAD(n) virtual void o##n();
    virtual ~RGE_Static_Object();
    OPAD(1) OPAD(2) OPAD(3) OPAD(4) OPAD(5) OPAD(6) OPAD(7)
    OPAD(8) OPAD(9) OPAD(10) OPAD(11) OPAD(12) OPAD(13) OPAD(14) OPAD(15)
    OPAD(16) OPAD(17) OPAD(18) OPAD(19) OPAD(20) OPAD(21) OPAD(22) OPAD(23)
    OPAD(24) OPAD(25) OPAD(26) OPAD(27) OPAD(28) OPAD(29) OPAD(30) OPAD(31)
    OPAD(32) OPAD(33) OPAD(34) OPAD(35) OPAD(36) OPAD(37)
#undef OPAD
    virtual void do_command(RGE_Static_Object* foundation, float x, float y, float z);
    int id;
    void removeAllFromPathingGroup();
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
#undef PPAD
    virtual void cancelBuild(int result, int count, int obj_id, float x, float y, int unique_id, int object_id);
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects;
    uchar pay_obj_cost(short obj_id, float amount, int flag);
};

class BuildInfo {
public:
    virtual ~BuildInfo();
    virtual void b1();
    virtual void b2();
    virtual void b3();
    virtual void b4();
    virtual void b5();
    virtual void b6();
    virtual void b7();
    virtual uchar can_place(TRIBE_Player* player, float x, float y, uchar* placement, int a, int b, int c, int d, int e, int f);
    virtual void b9();
    virtual void b10();
    virtual void b11();
    virtual void b12();
    virtual void b13();
    virtual void b14();
    virtual RGE_Static_Object* create_foundation(TRIBE_Player* player, float x, float y, int zero, int unique_id);
};

struct TRIBE_Command_Build {
    uchar command;
    uchar count;
    uchar player_id;
    uchar pad3;
    float x;
    float y;
    short obj_id;
    short padE;
    int unique_id;
    RGE_Obj_Info ids[1];
};

class TRIBE_Command : public RGE_Command {
public:
    void do_command_build(TRIBE_Command_Build* cmd);
};

void TRIBE_Command::do_command_build(TRIBE_Command_Build* cmd)
{
    RGE_Static_Object* blockingObject;
    uchar placementResult;
    int count;
    RGE_Static_Object* obj;

    count = cmd->count;
    TRIBE_Player* player = (TRIBE_Player*)this->world->players[cmd->player_id];
    if (player == 0) {
        return;
    }
    if (cmd->obj_id == -1) {
        return;
    }

    BuildInfo* info = (BuildInfo*)player->master_objects[cmd->obj_id];
    if (info == 0) {
        return;
    }

    placementResult = info->can_place(player, cmd->x, cmd->y, &placementResult, 1, 1, 1, 1, 1, 1);
    if (placementResult != 0) {
        if (count <= 0) {
            return;
        }
        obj = this->get_obj(cmd->ids[0]);
        if (obj == 0) {
            return;
        }
        player->cancelBuild(placementResult, count, cmd->obj_id, cmd->x, cmd->y, cmd->unique_id, obj->id);
        return;
    }

    if (!player->pay_obj_cost(cmd->obj_id, 1.0f, 0)) {
        if (count <= 0) {
            return;
        }
        obj = this->get_obj(cmd->ids[0]);
        if (obj == 0) {
            return;
        }
        player->cancelBuild(0, count, cmd->obj_id, cmd->x, cmd->y, cmd->unique_id, obj->id);
        return;
    }

    blockingObject = info->create_foundation(player, cmd->x, cmd->y, 0, cmd->unique_id);
    if (count <= 0) {
        return;
    }

    RGE_Obj_Info* idp = &cmd->ids[0];
    int n = count;
    do {
        obj = this->get_obj(*idp);
        if (obj != 0) {
            obj->removeAllFromPathingGroup();
            obj->do_command(blockingObject, cmd->x, cmd->y, 0.0f);
        }
        ++idp;
        --n;
    } while (n != 0);
}
