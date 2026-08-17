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
// Typed the world player table as RGE_Player** from the shared engine ABI;
// output was codegen-duplicate at 500/500 B and 19 strict bytes. Retained the
// natural typed ownership, but kept the clean source as the recovery authority.
// Tried a natural cached player-table local; it was codegen-duplicate at 19 bytes
// and was rolled back. The clean direct world member form remains authoritative.
// Reordered natural early declarations to evaluate player before ids; this widened the
// first hunk to 40 bytes and was rolled back. The clean declaration order remains best.
// Tested exact-TU world/player ABI surfaces, split declarations, an explicit byte index,
// and named pointer arithmetic; these all stayed at 19 bytes or worsened the first hunk.
// Restored the clean source before the final ownership pass.
// Final ownership pass: modeled the proven 0x10-byte command header with trailing
// RGE_Obj_Info records and the player master_objects table; output stayed at 19 bytes.
// Naming branch-local x2/y2 bytes recovered both split-arm compare load orders;
// the natural source moved to 11 strict bytes and 90.2% exact blocks.
// Tested typed player-table, cached world/player, split declaration, and full
// same-TU player-vtable surfaces; these were codegen-duplicate. Current pause:
// the remaining 11 bytes are the initial world/player register-color schedule.
// Policy correction: replaced the fake virtual-slot padding and generic names
// with canonical RGE_Command and RGE_Static_Object virtual surfaces from the
// repository class dumps. The rebuild remains 500 B with an 11-byte mismatch.

typedef unsigned char uchar;

#include <stdlib.h>

class RGE_Static_Object;
class RGE_Player;
class RGE_Master_Static_Object;
class RGE_Command_Give_Attribute;
class TDrawArea;
class RGE_Color_Table;
class RGE_Sprite;
class RGE_Armor_Weapon_Info;
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
    virtual void do_command_give_attribute(RGE_Command_Give_Attribute* command);
    virtual ~RGE_Command();
    virtual void do_command(void* command);
    virtual void command_give_attribute(int player_id, int object_id,
                                        int attribute_id, float amount);
    RGE_Game_World* world;
    RGE_Static_Object* get_obj(RGE_Obj_Info id);
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player, float x, float y,
                                    float z);
    virtual void recycle_out_of_game();
    virtual void draw(TDrawArea* draw_area, short x, short y,
                      RGE_Color_Table* color_table);
    virtual void shadow_draw(TDrawArea* draw_area, short x, short y,
                             uchar shadow);
    virtual void normal_draw(TDrawArea* draw_area, short x, short y);
    virtual void draw_front_frame(TDrawArea* draw_area, short x, short y);
    virtual void draw_back_frame(TDrawArea* draw_area, short x, short y);
    virtual void draw_frame(TDrawArea* draw_area, short x, short y);
    virtual uchar update();
    virtual void check_damage_sprites();
    virtual void rehook();
    virtual void save(int file);
    virtual float teleport(float x, float y, float z);
    virtual void new_sprite(RGE_Sprite* sprite);
    virtual void add_overlay_sprite(RGE_Sprite* sprite, uchar flags);
    virtual void remove_overlay_sprite(RGE_Sprite* sprite);
    virtual void change_ownership(RGE_Player* player);
    virtual void modify(float amount, uchar attribute);
    virtual void modify_delta(float amount, uchar attribute);
    virtual void modify_percent(float amount, uchar attribute);
    virtual void transform(RGE_Master_Static_Object* master);
    virtual void copy_obj(RGE_Master_Static_Object* master);
    virtual void set_object_state(uchar state);
    virtual void remove_visible_resource();
    virtual void create_doppleganger_when_dying();
    virtual void destroy_obj();
    virtual void die_die_die();
    virtual void damage(int amount, RGE_Armor_Weapon_Info* armor,
                        float multiplier, RGE_Player* player,
                        RGE_Static_Object* source);
    virtual float calculateDamage(int amount, RGE_Armor_Weapon_Info* armor,
                                  float multiplier, RGE_Player* player,
                                  RGE_Static_Object* source);
    virtual void rotate(long angle);
    virtual uchar can_attack();
    virtual void set_attribute(short attribute, float amount);
    virtual void set_attribute_amount(float amount, uchar attribute,
                                      uchar flag);
    virtual int heal(int amount, int flag);
    virtual uchar heal(float amount);
    virtual int canRepair();
    virtual void notify_of_relation(long player_id, uchar relation);
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
    RGE_Master_Static_Object** master_objects;
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
};

class TRIBE_Command : public RGE_Command {
public:
    void place_line_of_walls(TRIBE_Player* player, TRIBE_Master_Building_Object* info, int unique_id, int x1, int y1, int x2, int y2, RGE_Static_Object** result);
    void do_command_build_wall(TRIBE_Command_Build_Wall* cmd);
};

void TRIBE_Command::do_command_build_wall(TRIBE_Command_Build_Wall* cmd)
{
    int count = cmd->count;
    RGE_Obj_Info* ids = (RGE_Obj_Info*)(cmd + 1);
    TRIBE_Player* player = (TRIBE_Player*)this->world->players[cmd->player_id];
    if (player == 0) return;
    if (cmd->obj_id == -1) return;
    TRIBE_Master_Building_Object* info = (TRIBE_Master_Building_Object*)player->master_objects[cmd->obj_id];
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
        uchar x2 = cmd->x2;
        if (cmd->x1 < x2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      (int)cmd->x1 + 1, cmd->y2,
                                      cmd->x2, cmd->y2, &foundation);
        } else if (cmd->x1 > x2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      (int)cmd->x1 - 1, cmd->y2,
                                      cmd->x2, cmd->y2, &foundation);
        }
    } else {
        this->place_line_of_walls(player, info, cmd->unique_id,
                                  cmd->x1, cmd->y1, cmd->x2, cmd->y1,
                                  &foundation);
        uchar y2 = cmd->y2;
        if (cmd->y1 < y2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      cmd->x2, (int)cmd->y1 + 1,
                                      cmd->x2, cmd->y2, &foundation);
        } else if (cmd->y1 > y2) {
            this->place_line_of_walls(player, info, cmd->unique_id,
                                      cmd->x2, (int)cmd->y1 - 1,
                                      cmd->x2, cmd->y2, &foundation);
        }
    }

    if (foundation != 0) {
        if (count > 0) {
            int n = count;
            RGE_Obj_Info* idp = ids;
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
