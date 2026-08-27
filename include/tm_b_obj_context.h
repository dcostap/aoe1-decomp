#ifndef AOE1_TM_B_OBJ_CONTEXT_H
#define AOE1_TM_B_OBJ_CONTEXT_H

// Canonical declarations for the PDB source module tm_b_obj.cpp.
// The module wrapper defines TM_B_OBJ_SHARED_CONTEXT before including owners.
// Standalone owners retain their local recovery declarations.

#ifdef TM_B_OBJ_SHARED_CONTEXT
#include "game_globals.h"

typedef unsigned char uchar;

class RGE_Sprite {
public:
    char gap_00[0x72];
    short id;

    void draw(long facet, long frame, long x1, long y1,
              long x2, long y2, RGE_Color_Table* color_table,
              TDrawArea* draw_area, unsigned char color_index);
};

class RGE_Sound {
public:
    char gap_00[0x0C];
    short id;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    RGE_Master_Static_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int flag);

    char gap_04[0x14];
    RGE_Sprite* sprite;          // +0x18
    char gap_1C[0x14];
    float radius_x;              // +0x30
    float radius_y;              // +0x34
    char gap_38[0x80];

    virtual unsigned char alignment(float& x, float& y,
                                    RGE_Game_World* world,
                                    unsigned char flag);
};

class RGE_Master_Animated_Object : public RGE_Master_Static_Object {
public:
    float speed;                 // +0xB8
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[0x1C];           // +0xBC
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    char gap_D8[0x24];           // +0xD8

    RGE_Master_Action_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int flag);
};

class RGE_Master_Combat_Object : public RGE_Master_Action_Object {
public:
    char gap_FC[0x4C];           // +0xFC

    RGE_Master_Combat_Object(int id, RGE_Sprite** sprites,
                             RGE_Sound** sounds, int flag);
};

class TRIBE_Master_Combat_Object : public RGE_Master_Combat_Object {
public:
    char gap_148[0x1C];          // +0x148, ends at +0x164

    virtual ~TRIBE_Master_Combat_Object();
    TRIBE_Master_Combat_Object(TRIBE_Master_Combat_Object* source,
                               int do_setup);
    TRIBE_Master_Combat_Object(int id, RGE_Sprite** sprites,
                               RGE_Sound** sounds, int flag);
    TRIBE_Master_Combat_Object(FILE* file, RGE_Sprite** sprites,
                               RGE_Sound** sounds, short id, int flag);

    int setup(TRIBE_Master_Combat_Object* source);
    int setup(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
              short id);
    void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
};

typedef TRIBE_Master_Combat_Object TRIBE_Master_Combat_Object_Base;

class RGE_Static_Object {
public:
    char pad[0x204];
};

class TRIBE_Master_Building_Object : public TRIBE_Master_Combat_Object {
public:
    RGE_Sound* construction_sound;       // +0x164
    RGE_Sprite* construction_sprite;     // +0x168
    unsigned char building_connect_flag; // +0x16C
    char gap_16D[1];
    short building_facet;               // +0x16E
    unsigned char build_and_go_away;     // +0x170
    char gap_171[1];
    short on_build_make_obj;             // +0x172
    short on_build_make_tile;            // +0x174
    short on_build_make_overlay;         // +0x176
    short on_build_make_tech;             // +0x178

    TRIBE_Master_Building_Object(TRIBE_Master_Building_Object* source,
                                 int do_setup);
    TRIBE_Master_Building_Object(int id, RGE_Sprite** sprites,
                                 RGE_Sound** sounds, int flag);
    TRIBE_Master_Building_Object(FILE* file, RGE_Sprite** sprites,
                                 RGE_Sound** sounds, short id, int flag);
    virtual ~TRIBE_Master_Building_Object();

protected:
    int setup(TRIBE_Master_Building_Object* source);
    int setup(int file, RGE_Sprite** sprites, RGE_Sound** sounds);
    int setup(FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds,
              short id);

public:
    virtual void copy_obj(RGE_Master_Static_Object* source);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int file);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                            float y, float z, int value);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                            float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* color_table, long param_5,
                      long param_6, int param_7, unsigned char param_8);
    virtual unsigned char alignment(float& x, float& y,
                                    RGE_Game_World* world,
                                    unsigned char flag);
};

class TRIBE_Building_Object : public RGE_Static_Object {
public:
    TRIBE_Building_Object(TRIBE_Master_Building_Object* master,
                          RGE_Player* player, float x, float y, float z,
                          int value, int flag);
    TRIBE_Building_Object(TRIBE_Master_Building_Object* master,
                          RGE_Player* player, float x, float y, float z,
                          int value);
};

class RGE_Map {
public:
    char gap_00[0x28];
    void get_point(short& out_x, short& out_y, float x, float y,
                   float z, short map_x, short map_y);
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

void rge_read(int file, void* data, int size);
void rge_write(int file, void* data, int size);

// Layout checks keep the shared surface tied to the binary-proven offsets.
typedef char tm_b_obj_master_size[(sizeof(TRIBE_Master_Building_Object) == 0x17C) ? 1 : -1];
typedef char tm_b_obj_static_size[(sizeof(RGE_Static_Object) == 0x204) ? 1 : -1];

#endif  // TM_B_OBJ_SHARED_CONTEXT
#endif  // AOE1_TM_B_OBJ_CONTEXT_H
