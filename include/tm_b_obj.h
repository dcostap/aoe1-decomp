#ifndef AOE1_TM_B_OBJ_H
#define AOE1_TM_B_OBJ_H

#include "tm_co_ob.h"
#include <stddef.h>

class RGE_Color_Table;
class RGE_Game_World;
class RGE_Player;
class RGE_Sound;
class RGE_Sprite;
class RGE_Static_Object;
class TDrawArea;

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* other_object, int do_setup);
    TRIBE_Master_Building_Object(int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup);
    TRIBE_Master_Building_Object(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id, int do_setup);
    virtual ~TRIBE_Master_Building_Object();

protected:
    int setup(TRIBE_Master_Building_Object* other_object);
    int setup(int infile, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id);

public:
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float amount, unsigned char flag);
    virtual void modify_delta(float amount, unsigned char flag);
    virtual void modify_percent(float amount, unsigned char flag);
    virtual void save(int outfile);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual RGE_Static_Object* make_new_obj(RGE_Player* owner, float x, float y, float z, int uID);
    virtual void draw(TDrawArea* render_area, short x, short y, RGE_Color_Table* player_color, long facet, long frame,
                      int draw_frame, unsigned char frame_color);
    virtual unsigned char alignment(float& col, float& row, RGE_Game_World* world,
                                    unsigned char center_flag);

    RGE_Sound* construction_sound;
    RGE_Sprite* construction_sprite;
    unsigned char building_connect_flag;
    short building_facet;
    unsigned char build_and_go_away;
    short on_build_make_obj;
    short on_build_make_tile;
    short on_build_make_overlay;
    short on_build_make_tech;
};

typedef char tribe_master_building_object_size_check[
    (sizeof(TRIBE_Master_Building_Object) == 0x17C) ? 1 : -1];
typedef char tribe_master_building_object_sound_offset_check[
    (offsetof(TRIBE_Master_Building_Object, construction_sound) == 0x164) ? 1
                                                                         : -1];
typedef char tribe_master_building_object_factory_slot_check[
    (offsetof(TRIBE_Master_Building_Object, on_build_make_tech) == 0x178) ? 1
                                                                         : -1];

#endif  // AOE1_TM_B_OBJ_H
