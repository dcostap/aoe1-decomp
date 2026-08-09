// VA: 00509E10 TRIBE_Command::do_command_build_wall
// tcommand.cpp lines 337-450
// Attempt log:
// 1: natural structured source from packet/decompiler: behavior/call set modeled, rebuilt 480 B vs original 500 B.
// 2: corrected TRIBE_Player object table to proven +0x24 with explicit gap; fixed object-table offset but still 480 B.
// 3: tried adding a virtual vptr to TRIBE_Player for +0x24; caused worse register allocation (player in ebp, this homed to stack) and 0x1C frame; rolled back.
// 4: tried sign-shift absolute value spelling to force cdq/xor/sub; VC5 used sar temps, saved this to stack, frame 0x1C, 500 B but broad 91% positional diff; rolled back.
// 5: tried named sign temps for abs; same bad frame/register family; rolled back.
// 6: reordered dominance branch as dy > dx so inline branch matches original's post-compare fallthrough family; kept.
// 7: tried default /O2 /Oy /GX flags; unchanged 480 B.
// 8: tried /O2 without /Oy; unchanged 480 B.
// 9: compared dumped asm: top/object lookup and final pathing loop are close; remaining major gap is middle wall-splitting region, especially abs codegen and push/tail-sharing register allocation.
// 10: left in scratch: not accepted_drift-safe; broad middle control-flow/register mismatch despite correct behavior-level model and call boundaries.
// 11: direct command-field expressions plus natural stdlib abs recovered the original 0x18 frame, 500-byte size, and most middle/cold bytes (209 strict bytes; 41.7%); retained as the canonical source lead.
// 12: positive dy>=dx vertical arm with horizontal else matched the original JL block topology and reduced drift to 19 strict bytes; retained.
// 13: a named world-base local was codegen-duplicate and did not improve the 19-byte result; restored the simpler direct world member form.
// Current pause: calls, frame, size, CFG, and 73.6% exact blocks are aligned; remaining 19 bytes are localized to initial world/player register scheduling and do not justify opaque forcing.

typedef unsigned char uchar;

#include <stdlib.h>

class RGE_Static_Object;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    char gap_04[0x3C];
    void** players;
};

class RGE_Command {
public:
    virtual void vfunc0();
    virtual ~RGE_Command();
    virtual void vfunc8();
    virtual void vfuncC();
    RGE_Game_World* world;
    RGE_Static_Object* get_obj(int id);
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
    char gap_08[0x30];
    float world_x;
    float world_y;
    void removeAllFromPathingGroup();
};

class TRIBE_Player {
public:
    virtual ~TRIBE_Player();
    char gap_04[0x20];
    void** objects;
};
class TRIBE_Master_Building_Object;

struct TRIBE_Command_Build_Wall {
    uchar command;
    uchar count;
    uchar player_id;
    uchar x1;
    uchar y1;
    uchar x2;
    uchar y2;
    uchar pad7;
    short obj_id;
    short padA;
    int unique_id;
    int ids[1];
};

class TRIBE_Command : public RGE_Command {
public:
    void place_line_of_walls(TRIBE_Player* player, TRIBE_Master_Building_Object* info, int unique_id, int x1, int y1, int x2, int y2, RGE_Static_Object** result);
    void do_command_build_wall(TRIBE_Command_Build_Wall* cmd);
};

void TRIBE_Command::do_command_build_wall(TRIBE_Command_Build_Wall* cmd)
{
    int count = cmd->count;
    int* ids = &cmd->ids[0];
    TRIBE_Player* player = (TRIBE_Player*)this->world->players[cmd->player_id];
    if (player == 0) return;
    if (cmd->obj_id == -1) return;
    TRIBE_Master_Building_Object* info = (TRIBE_Master_Building_Object*)player->objects[cmd->obj_id];
    if (info == 0) return;

    RGE_Static_Object* foundation = 0;
    int dy = abs((int)cmd->y2 - (int)cmd->y1);
    int dx = abs((int)cmd->x2 - (int)cmd->x1);

    if (dy == dx) {
        this->place_line_of_walls(player, info, cmd->unique_id,
                                  cmd->x1, cmd->y1, cmd->x2, cmd->y2,
                                  &foundation);
    } else if (dy >= dx) {
        this->place_line_of_walls(player, info, cmd->unique_id,
                                  cmd->x1, cmd->y1, cmd->x1, cmd->y2,
                                  &foundation);
        if (cmd->x1 < cmd->x2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      (int)cmd->x1 + 1, cmd->y2,
                                      cmd->x2, cmd->y2, &foundation);
        } else if (cmd->x1 > cmd->x2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      (int)cmd->x1 - 1, cmd->y2,
                                      cmd->x2, cmd->y2, &foundation);
        }
    } else {
        this->place_line_of_walls(player, info, cmd->unique_id,
                                  cmd->x1, cmd->y1, cmd->x2, cmd->y1,
                                  &foundation);
        if (cmd->y1 < cmd->y2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      cmd->x2, (int)cmd->y1 + 1,
                                      cmd->x2, cmd->y2, &foundation);
        } else if (cmd->y1 > cmd->y2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      cmd->x2, (int)cmd->y1 - 1,
                                      cmd->x2, cmd->y2, &foundation);
        }
    }

    if (foundation != 0) {
        if (count > 0) {
            int n = count;
            int* idp = ids;
            do {
                RGE_Static_Object* obj = this->get_obj(*idp);
                if (obj != 0) {
                    obj->removeAllFromPathingGroup();
                    obj->do_command(foundation, foundation->world_x,
                                    foundation->world_y, 0.0f);
                }
                ++idp;
                --n;
            } while (n != 0);
        }
    }
}
