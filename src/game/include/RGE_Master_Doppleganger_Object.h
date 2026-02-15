#pragma once
#include "common.h"
#include "RGE_Master_Animated_Object.h"

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
public:
    RGE_Master_Doppleganger_Object();
    RGE_Master_Doppleganger_Object(RGE_Master_Doppleganger_Object* param_1, int param_2);
    RGE_Master_Doppleganger_Object(int param_1, RGE_Sprite** param_2, RGE_Sound** param_3, int param_4);
    RGE_Master_Doppleganger_Object(FILE* param_1, RGE_Sprite** param_2, RGE_Sound** param_3, short param_4, int param_5);

    // Virtuals (best-effort)
    virtual ~RGE_Master_Doppleganger_Object(); // vt[0] (0x0)
    virtual void copy_obj(RGE_Master_Static_Object* param_1); // vt[1] (0x4)
    virtual void modify(float param_1, uchar param_2); // vt[2] (0x8)
    virtual void modify_delta(float param_1, uchar param_2); // vt[3] (0xC)
    virtual void modify_percent(float param_1, uchar param_2); // vt[4] (0x10)
    virtual void save(int param_1); // vt[5] (0x14)
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4); // vt[6] (0x18)
    virtual RGE_Master_Static_Object* make_new_master(); // vt[7] (0x1C)
    virtual uchar check_placement(RGE_Player* param_1, float param_2, float param_3, int* param_4, uchar param_5, uchar param_6, uchar param_7, uchar param_8, uchar param_9, uchar param_10); // vt[8] (0x20)
    virtual uchar alignment(float* param_1, float* param_2, RGE_Game_World* param_3, uchar param_4); // vt[9] (0x24)
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* param_1); // vt[10] (0x28)
    virtual void play_command_sound(); // vt[11] (0x2C)
    virtual void play_move_sound(); // vt[12] (0x30)
    virtual void draw(TDrawArea* param_1, short param_2, short param_3, RGE_Color_Table* param_4, long param_5, long param_6, int param_7, uchar param_8); // vt[13] (0x34)
    virtual RGE_Static_Object* make_new_obj(RGE_Player* param_1, float param_2, float param_3, float param_4, RGE_Static_Object* param_5); // vt[14] (0x38)

};
static_assert(sizeof(RGE_Master_Doppleganger_Object) == 0xBC, "Size mismatch");
