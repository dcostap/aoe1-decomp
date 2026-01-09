#pragma once
#include "common.h"

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

    virtual void copy_obj(RGE_Master_Static_Object* param_1); // vt0[1]+0x4=0x50E440
    virtual void modify(float param_1, uchar param_2);      // vt0[2]+0x8=0x50E4D0
    virtual void modify_delta(float param_1, uchar param_2); // vt0[3]+0xC=0x50E500
    virtual void modify_percent(float param_1, uchar param_2); // vt0[4]+0x10=0x50E530
    virtual void save(int param_1);                         // vt0[5]+0x14=0x50E550
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4); // vt0[6]+0x18=0x50E6B0
    virtual RGE_Master_Static_Object* make_new_master();    // vt0[7]+0x1C=0x50E730
    virtual uchar alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4); // vt0[9]+0x24=0x50E950
    virtual void draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8); // vt0[13]+0x34=0x50E7A0
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, int param_5); // vt0[15]+0x3C=0x50E630
    TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* param_1, int param_2);
    TRIBE_Master_Building_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    TRIBE_Master_Building_Object(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);
    int setup(TRIBE_Master_Building_Object* param_1);
    int setup(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3);
    int setup(_iobuf* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4);
    ~TRIBE_Master_Building_Object();
};

static_assert(sizeof(TRIBE_Master_Building_Object) == 0x17C, "TRIBE_Master_Building_Object Size Mismatch");

