// VA: 0050E7A0 TRIBE_Master_Building_Object::draw (420B)
// PDB source: tm_b_obj.cpp lines 228-260
//
// Baseline reconstruction: use the inherited master sprite/radii, select the
// connected-building facet, and optionally add the four projected radius
// corners to the GDI clipping list.
//
// Attempt log:
// - Replaced the incomplete wrapper with the period-plausible typed draw
//   source supported by the target's six direct calls and proven offsets.
// - Positive connected-building control flow and duplicate natural sprite
//   arms recover the target's common call tail and the 0x10 frame; parameter
//   mutation and short-coordinate aliases were emitted-code duplicates.
// - Restored the complete master-object inheritance/field ownership surface;
//   it is layout-canonical but codegen-neutral for this body.
// - Final bounded result: all six ordered calls, CFG counts, and frame size
//   match; the target remains 420B while this source emits 394B.  The first
//   unresolved hunk is the target's EDX/self stack home and its later
//   parameter/register/local schedule, not behavior or call discovery.
// - Tried removing the redundant object alias while keeping the cached sprite
//   local; VC5 emitted identical code, so the self-home gap is not this alias.
// - Tried the same-TU donor's flat typed building surface with named sprite
//   and radius fields; it emitted identical code, so inheritance context is
//   not the first self-home structural cause. Restored the canonical layout.
// - Moving the self alias to function entry, splitting its declaration, and
//   reordering map/radius declarations reproduced the older 403B basin; all
//   were rolled back.
// - Short coordinate aliases and direct sprite/member/map expressions were
//   codegen duplicates. Explicit sprite-coordinate locals widened the gap.
// - A volatile self alias moved the size to 410B and diff to 386B, but added
//   repeated stack loads and is not plausible source; it was rolled back.
// - Raw 32-bit reads of short coordinate homes changed the frame and broad
//   CFG, so target raw EDI/EBX pushes are not a reason to retain pointer casts.
// - Revisited under a fresh lease: typed reference aliases, the full static
//   virtual declaration surface, direct members, interleaved output scopes,
//   local declaration context, an outline-only receiver alias, and a named
//   negative-radius temporary all emitted the same 394B code.
// - A decompiler-supported packed-output probe mapped the four get_point
//   result pairs onto rx1 and dead parameter homes.  This follows the target's
//   short output addresses and improved diagnostic shape to 74%, but it needs
//   raw parameter-home casts.  It is not retained as canonical source.
// - The packed probe also used whole-word x/y parameter reads.  The target
//   pushes those words without MOVSX in each map call, but the clean typed
//   source does not force that compiler detail.
// - Passing the first radius pair as direct member expressions reached a
//   420B/161-instruction diagnostic basin and reduced strict diff to 353B.
//   Its FPU and register topology did not match the target, so it was rolled
//   back.  The packed-output probe remains the next lead for a natural donor.
// - Original stack evidence still shows dead parameter homes reused for later
//   map outputs. Forcing that shape would violate the clean-source policy;
//   retain the typed natural rendering flow instead.
// - Current clean reconstruction remains the best plausible source. The
//   unresolved structural lead is VC5 self-home/register scheduling before
//   the first field load; calls and behavior remain aligned.

#include "..\..\include\game_globals.h"

class RGE_Color_Table;
class TDrawArea;
class RGE_Sprite;
class RGE_Map;
class RGE_Game_World;

class RGE_Sprite {
public:
    unsigned char draw(long facet, long param_2, long x1, long y1,
                       long x2, long y2, RGE_Color_Table* color_table,
                       TDrawArea* draw_area, unsigned char color_index);
};

class RGE_Map {
public:
    void get_point(short* out_x, short* out_y, float param_3, float param_4,
                   float param_5, int param_6, int param_7);
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
};

class RGE_Base_Game {
public:
    char gap_00[0x3F4];
    RGE_Game_World* world;
};

class DClipInfo_List {
public:
    void AddGDINode(int type, int y_line,
                    short x1, short y1, short x2, short y2,
                    short x3, short y3, short x4, short y4,
                    int draw_level, int draw_flag, int object_id);
};

extern RGE_Base_Game* rge_base_game;
extern DClipInfo_List* SDI_List;
extern int SDI_Object_ID;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();

    char gap_04[0x14];
    RGE_Sprite* sprite;          // +0x18
    char gap_1C[0x14];
    float radius_x;              // +0x30
    float radius_y;              // +0x34
    char gap_38[0x80];
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed; // +0xB8
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[0x1C];
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_D8[0x24];
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    char gap_FC[0x4C];
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    char gap_148[0x1C];
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    RGE_Sound* construction_sound; // +0x164
    RGE_Sprite* construction_sprite; // +0x168
    unsigned char building_connect_flag; // +0x16C
    char gap_16D[1];
    short building_facet;                // +0x16E
    char gap_170[0xC];

    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* color_table, long param_5,
                      long param_6, int param_7, unsigned char param_8);
};

void TRIBE_Master_Building_Object::draw(TDrawArea* area, short x, short y,
                                        RGE_Color_Table* color_table,
                                        long param_5, long param_6,
                                        int param_7, unsigned char param_8) {
    RGE_Sprite* sprite = this->sprite;
    if (sprite != 0) {
        TRIBE_Master_Building_Object* object = this;
        if (object->building_connect_flag != 0) {
            if (param_5 == 0) {
                sprite->draw(2, 0, (int)x, (int)y, (int)x, (int)y,
                             color_table, area, 0);
            } else {
                sprite->draw(param_5 - 1, 0, (int)x, (int)y,
                             (int)x, (int)y,
                             color_table, area, 0);
            }
        } else {
            sprite->draw(object->building_facet, 0, (int)x, (int)y,
                         (int)x, (int)y,
                         color_table, area, 0);
        }

        if (param_7 != 0) {
            RGE_Game_World* world = rge_base_game->world;
            float rx1 = object->radius_x;
            float ry1 = object->radius_y;
            RGE_Map* map = world->map;
            short x1;
            short y1;
            short x2;
            short y2;
            short x3;
            short y3;
            short x4;
            short y4;

            map->get_point(&x1, &y1, rx1, -ry1, 0.0f, x, y);
            map->get_point(&x2, &y2, rx1, ry1, 0.0f, x, y);
            rx1 = -rx1;
            map->get_point(&x3, &y3, rx1, ry1, 0.0f, x, y);
            map->get_point(&x4, &y4, rx1, -ry1, 0.0f, x, y);

            SDI_List->AddGDINode(1, (int)y, x1, y1, x2, y2, x3, y3,
                                 x4, y4, 10, (int)(param_8 & 0xFF),
                                 SDI_Object_ID);
        }
    }
}
