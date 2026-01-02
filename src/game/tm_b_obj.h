#pragma once
#include "../common.h"

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    RGE_Sound* construction_sound;           // 0x164
    RGE_Sprite* construction_sprite;         // 0x168
    uchar building_connect_flag;             // 0x16C
    short building_facet;                    // 0x16E
    uchar build_and_go_away;                 // 0x170
    short on_build_make_obj;                 // 0x172
    short on_build_make_tile;                // 0x174
    short on_build_make_overlay;             // 0x176
    short on_build_make_tech;                // 0x178

    TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* param_1, int param_2);
    TRIBE_Master_Building_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    TRIBE_Master_Building_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
    virtual int setup(TRIBE_Master_Building_Object* param_1);
    virtual int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    virtual int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
    virtual ~TRIBE_Master_Building_Object();
    virtual void copy_obj(RGE_Master_Static_Object* param_1);
    virtual void modify(float param_1, uchar param_2);
    virtual void modify_delta(float param_1, uchar param_2);
    virtual void modify_percent(float param_1, uchar param_2);
    virtual void save(int param_1);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, int param_5);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual void draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8);
    virtual uchar alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4);
};

static_assert(sizeof(TRIBE_Master_Building_Object) == 0x17C, "TRIBE_Master_Building_Object Size Mismatch");
static_assert(offsetof(TRIBE_Master_Building_Object, on_build_make_tech) == 0x178, "TRIBE_Master_Building_Object Offset Mismatch");

