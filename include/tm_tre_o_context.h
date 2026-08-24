#ifndef TM_TRE_O_CONTEXT_H
#define TM_TRE_O_CONTEXT_H

// Canonical declarations for the tm_tre_o.cpp owner sequence.
// The base object has a byte type marker at +0x04 and a total size of 0xB8.

#include <stdio.h>

typedef unsigned char uchar;

class RGE_Player;
class RGE_Static_Object;
class RGE_Sprite;
class RGE_Sound;
class RGE_Game_World;
class RGE_Master_Combat_Object;
class TDrawArea;
class RGE_Color_Table;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float value, uchar mode);
    virtual void modify_delta(float value, uchar mode);
    virtual void modify_percent(float value, uchar mode);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player,
        float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master(void);
    virtual uchar check_placement(RGE_Player* player, float x, float y,
        int* result, uchar a, uchar b, uchar c, uchar d, uchar e, uchar f);
    virtual uchar alignment(float* x, float* y, RGE_Game_World* world,
        uchar mode);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);
    virtual void play_command_sound(void);
    virtual void play_move_sound(void);
    virtual void draw(TDrawArea* area, short x, short y,
        RGE_Color_Table* colors, long a, long b, int c, uchar d);

    RGE_Master_Static_Object(RGE_Master_Static_Object* object, int do_setup);
    RGE_Master_Static_Object(int param_1, RGE_Sprite** sprites,
        RGE_Sound** sounds, int flag);
    RGE_Master_Static_Object(FILE* stream, RGE_Sprite** sprites,
        RGE_Sound** sounds,
        short index, int flag);

    void setup(RGE_Master_Static_Object* object);
    void setup(int param_1, RGE_Sprite** sprites, RGE_Sound** sounds);
    void setup(FILE* stream, RGE_Sprite** sprites, RGE_Sound** sounds,
        short index);

    char field_04;
    char _gap_05[0xB3];
};

class TRIBE_Master_Tree_Object : public RGE_Master_Static_Object {
public:
    virtual ~TRIBE_Master_Tree_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float value, uchar mode);
    virtual void modify_delta(float value, uchar mode);
    virtual void modify_percent(float value, uchar mode);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player,
        float x, float y, float z);
    virtual RGE_Master_Static_Object* make_new_master(void);
    virtual uchar check_placement(RGE_Player* player, float x, float y,
        int* result, uchar a, uchar b, uchar c, uchar d, uchar e, uchar f);
    virtual uchar alignment(float* x, float* y, RGE_Game_World* world,
        uchar mode);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);
    virtual void play_command_sound(void);
    virtual void play_move_sound(void);
    virtual void draw(TDrawArea* area, short x, short y,
        RGE_Color_Table* colors, long a, long b, int c, uchar d);

    TRIBE_Master_Tree_Object(TRIBE_Master_Tree_Object* param_1, int param_2);
    TRIBE_Master_Tree_Object(int param_1, RGE_Sprite** sprites,
        RGE_Sound** sounds, int flag);
    TRIBE_Master_Tree_Object(FILE* stream, RGE_Sprite** sprites,
        RGE_Sound** sounds,
        short index, int flag);
};

#endif
