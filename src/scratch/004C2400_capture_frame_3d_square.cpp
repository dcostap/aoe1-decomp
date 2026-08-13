// 004C2400 RGE_Static_Object::capture_frame_3d_square
// PDB: stat_obj.cpp:1010-1193
// Attempt log:
// - The prior notebook modeled only four corners and one draw call; it missed
//   the 14-node capture/selection/ID-marker paths and used fake helper types.
// - Current reconstruction follows the packet's typed ownership, exact map
//   get_point/AddGDINode/AddDrawNode surfaces, health-bar path, and ID digits.
// - Added the fifth health-bar projection and restored the original ordered
//   call sequence; int ID digits and parameter-home aliases align all 14 calls.
// - Inverted the digit branch only to reproduce VC5's original block order;
//   this is source-control evidence, not a behavior change.
// - Kept the cached base-game/master aliases after direct-member and outline
//   cache probes regressed the emitted basin.
// - Tried a typed geometry reorder: initialize map before master, read
//   outline_type directly, and reload master fields in the health path. The
//   frame fell to 0x44 and positional diff grew to 1275; restored the clean
//   source. The first hunk still points to local-home lifetime and geometry
//   temporary layout, not a call or CFG gap.
// - Paused: current code is 1345 vs 1382 bytes, frame 0x48 vs 0x54, 100%
//   ordered-call alignment, 70.45% shape, and 1168 positional diff bytes.
//   Remaining structural lead is original local-home/register allocation and
//   map/yline lifetime; no call-target or CFG-count gap remains.

class TDrawArea;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Map;
class TShape;
class Shape_Info;
class DClipInfo_List;

class RGE_Map {
public:
    char gap_00[0x8D9A];
    short tile_half_height;
    short tile_half_width;
    void get_point(short* out_x, short* out_y, float x, float y, float z,
                   int screen_x, int screen_y);
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
    char gap_2C[0x50];
    short curr_player;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
};

class RGE_Master_Static_Object {
public:
    char gap_00[0x26];
    short hp;
    char gap_28[8];
    float radius_x;
    float radius_y;
    float radius_z;
    char gap_3C[0xA8 - 0x3C];
    unsigned char draw_flag;
    unsigned char draw_color;
    char gap_AA[2];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};

class Shape_Info {
public:
    char gap_00[0x10];
    int width;
    int height;
    int hotspot_x;
    int hotspot_y;
};

class TShape {
public:
    char gap_00[0x18];
    Shape_Info* FShape;
};

class DClipInfo_List {
public:
    DClipInfo_List* dummy;
    void AddGDINode(int type, int yline, short x1, short y1, short x2,
                    short y2, short x3, short y3, short x4, short y4,
                    int draw_level, int draw_flag, int object_id);
    void AddDrawNode(void* shape_base, Shape_Info* shape, int yline,
                     int draw_x, int draw_y, int draw_flag,
                     unsigned char* color_table, int xform_mask,
                     int draw_level, int object_id);
};

class RGE_Base_Game {
public:
    char gap_00[0x50];
    unsigned char outline_type;
    char gap_51[0x15F];
    int prog_mode;                         // +0x1B0
    char gap_1B4[0x820];
    int display_selected_ids;              // +0x9D4
    TShape* get_shape(int index);
};

#define rge_base_game (*(RGE_Base_Game**)0x62C574)
#define startLoggingAI (*(int*)0x62C50C)
#define SDI_Object_ID (*(int*)0x86BBDC)
#define SDI_List (*(DClipInfo_List**)0x86BBF8)

class RGE_Static_Object {
public:
    void* vtable;
    long id;
    RGE_Master_Static_Object* master_obj;
    RGE_Player* owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    RGE_Static_Object* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    float hp;
    unsigned char curr_damage_percent;
    unsigned char facet;
    unsigned char selected;
    unsigned char selected_group;
    float world_x;
    float world_y;
    float world_z;
    float attribute_amount_held;
    unsigned char object_state;
    unsigned char sleep_flag;
    unsigned char dopple_flag;
    unsigned char goto_sleep_flag;
    short attribute_type_held;
    unsigned char type;
    unsigned char worker_num;
    void* player_object_node;
    char gap_54[0x24];
    int groupCommanderValue;

    void capture_frame_3d_square(TDrawArea* area, short x, short y);
};

void RGE_Static_Object::capture_frame_3d_square(
    TDrawArea* param_2, short param_3, short param_4)
{
    RGE_Master_Static_Object* pRVar1;
    RGE_Map* this_00;
    TShape* pTVar2;
    int iVar3;
    int iVar4;
    int* piVar5;
    unsigned int uVar6;
    int iVar7;
    short sVar8;
    short sVar9;
    unsigned char draw_color;
    unsigned char y2;
    float rx1;
    float x3_radius;
    float radius_y;
    float radius_z;
    short x4;
    short y3;
    float ry1;
    int local_3c;
    short y1;
    int local_34;
    int tot_hp;
    float neg_x3;
    TShape* group_num_shape;
    short x0;
    short y0;
    int idv[6];
    RGE_Base_Game* base;
    unsigned char outline_type;

    base = rge_base_game;
    outline_type = base->outline_type;
    pRVar1 = this->master_obj;
    this_00 = this->owner->world->map;
    if (outline_type == 3) {
        x3_radius = pRVar1->radius_x;
        radius_y = pRVar1->radius_y;
        radius_z = pRVar1->radius_z;
    } else {
        x3_radius = pRVar1->outline_radius_x;
        radius_y = pRVar1->outline_radius_y;
        radius_z = pRVar1->outline_radius_z;
    }
    if (startLoggingAI == 1 && this->groupCommanderValue == this->id &&
        this->id >= 0) {
        y2 = 0;
    } else if ((this->selected & 1) == 0) {
        if (outline_type == 3) {
            y2 = 0x74;
        } else if ((pRVar1->draw_flag & 1) == 1 &&
                   base->prog_mode == 7) {
            y2 = pRVar1->draw_color;
        } else {
            y2 = 0xFF;
        }
    } else {
        y2 = 0xFF;
    }
    if ((this->selected & 2) != 0) {
        y2 = 0x4A;
    }
    if ((this->selected & 4) != 0) {
        y2 = 0x97;
    }

    sVar9 = param_4 + this->screen_y_offset;
    sVar8 = param_3 + this->screen_x_offset;
    ry1 = -radius_y;
    this_00->get_point((short*)&group_num_shape, (short*)&local_34,
                       x3_radius, ry1, 0.0f, sVar8, sVar9);
    this_00->get_point(&param_3, (short*)&rx1, x3_radius, radius_y,
                       0.0f, sVar8, sVar9);
    neg_x3 = -x3_radius;
    this_00->get_point(&x4, (short*)&ry1, neg_x3, radius_y,
                       0.0f, sVar8, sVar9);
    this_00->get_point(&y3, (short*)&param_2, neg_x3, ry1,
                       0.0f, sVar8, sVar9);

    tot_hp = y2;
    iVar4 = (int)sVar9;
    SDI_List->AddGDINode(
        1, iVar4, (short)group_num_shape, (short)local_34,
        param_3, *(short*)&rx1, x4, *(short*)&ry1, y3,
        *(short*)&param_2, 10, y2, SDI_Object_ID);

    if (this->selected != 0 && this->selected_group != 0 &&
        this->selected_group < 10 &&
        this->owner->id == this->owner->world->curr_player &&
        (pTVar2 = rge_base_game->get_shape(0)) != 0) {
        SDI_List->AddDrawNode(
            pTVar2->FShape,
            pTVar2->FShape + this->selected_group,
            iVar4, y3 - 6, *(short*)&param_2 - 8,
            0, 0, 0, 0x1E, SDI_Object_ID);
    }

    if ((this->selected & 1) == 1 && (pRVar1->draw_flag & 2) == 0 &&
        (local_3c = (int)this->hp, local_3c > 0)) {
        this_00->get_point(&y0, (short*)idv, x3_radius, ry1, radius_z,
                           sVar8, sVar9);
        if ((int)local_3c < 1) {
            local_3c = 0;
        }
        int max_hp = pRVar1->hp;
        if (max_hp > 0) {
            group_num_shape = (TShape*)(y0 - 0x0C);
            rx1 = (float)(idv[0] - 1);
            param_3 = y0 + 0x0B;
            local_34 = idv[0] - 2;
            if (local_3c == max_hp) {
                ry1 = 1.4013e-45f;
                y3 = (short)0xFFFF;
                param_2 = 0;
                x4 = param_3;
            } else {
                if (local_3c == 0) {
                    x4 = -1;
                    ry1 = 0.0f;
                    y3 = (short)group_num_shape;
                } else {
                    ry1 = 1.4013e-45f;
                    x4 = (short)(local_34 + ((int)local_3c * 0x18) /
                                 max_hp);
                    if ((short)param_3 <= (short)x4) {
                        x4 = y0 + 10;
                    }
                    y3 = x4 + 1;
                }
                param_2 = (TDrawArea*)1;
            }
            SDI_List->AddGDINode(
                2, iVar4, (short)group_num_shape, (short)local_34,
                param_3, *(short*)&rx1, x4, *(short*)&ry1, y3,
                *(short*)&param_2, 0x1E, tot_hp, SDI_Object_ID);
        }
    }

    if (rge_base_game->display_selected_ids != 0) {
        pTVar2 = rge_base_game->get_shape(0);
        iVar7 = this->id;
        iVar3 = iVar7;
        if (iVar7 < 0) {
            iVar3 = -iVar7;
        }
        idv[1] = iVar3 / 10000;
        idv[2] = (iVar3 % 10000) / 1000;
        iVar3 = (iVar3 % 10000) % 1000;
        idv[3] = iVar3 / 100;
        iVar3 = iVar3 % 100;
        idv[4] = iVar3 / 10;
        idv[5] = iVar3 % 10;
        uVar6 = (unsigned int)(iVar7 < 10000);
        if (iVar7 < 1000) {
            uVar6 = 2;
        }
        if (iVar7 < 100) {
            uVar6 = 3;
        }
        if (iVar7 < 10) {
            uVar6 = 4;
        }
        if (iVar7 < 0) {
            param_3 = param_3 + 7;
            SDI_List->AddGDINode(
                4, iVar4, (short)param_3 + 1, *(short*)&rx1 + 3,
                (short)param_3 + 5, *(short*)&rx1 + 3,
                0, 0, 0, 0, 0x1E, 0x97, SDI_Object_ID);
        }
        if (uVar6 < 5) {
            piVar5 = idv + uVar6 + 1;
            iVar7 = 5 - uVar6;
            do {
                param_3 = param_3 + 7;
                sVar8 = (short)param_3;
                if (*piVar5 != 0) {
                    SDI_List->AddDrawNode(
                        pTVar2->FShape,
                        pTVar2->FShape + *piVar5,
                        iVar4, (int)sVar8, *(short*)&rx1,
                        0, 0, 0, 0x1E, SDI_Object_ID);
                } else {
                    SDI_List->AddGDINode(
                        4, iVar4, sVar8 + 1, *(short*)&rx1,
                        sVar8 + 5, *(short*)&rx1 + 5,
                        0, 0, 0, 0, 0x1E, 0xFF, SDI_Object_ID);
                }
                ++piVar5;
                --iVar7;
            } while (iVar7 != 0);
        }
    }
}
