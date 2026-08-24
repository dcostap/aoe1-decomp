#ifndef AOE1_DPL_OBJ_CONTEXT_H
#define AOE1_DPL_OBJ_CONTEXT_H

// Canonical declaration surface for the original dpl_obj.cpp module.
//
// The PDB places the fifteen ordinary owners in one source module, in the
// address and line order recorded by the module packet.  The wrapper defines
// DPL_OBJ_SHARED_CONTEXT before including the owner bodies.  Those bodies keep
// isolated fallback declarations for focused checks.

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char uchar;
typedef unsigned long ulong;

class RGE_Game_World;
class RGE_Player;
class RGE_Static_Object;
class RGE_Animated_Object;
class RGE_Master_Static_Object;
class RGE_Master_Animated_Object;
class RGE_Master_Doppleganger_Object;
class RGE_Doppleganger_Object;
class RGE_Doppleganger_Creator;
class RGE_Color_Table;
class RGE_Active_Sprite_Node;
class RGE_Active_Sprite_List;

extern "C" int __cdecl __ftol();
extern "C" void __cdecl rge_read(int handle, void* buffer, int size);
extern "C" void __cdecl rge_write(int handle, void* buffer, int size);
extern unsigned long* unified_map_offsets[];
extern float save_game_version;
extern float DAT_00570418;
extern FILE* DDlogf;

class RGE_Color_Table {
public:
    char gap_00[0x25];
    unsigned char map_color;
};

class RGE_Active_Sprite_List {
public:
    RGE_Active_Sprite_Node* copy_sprite_list();
    void use_sprite_list(RGE_Active_Sprite_Node* node);
};

class RGE_Master_Animated_Object {
};

class RGE_Master_Doppleganger_Object : public RGE_Master_Animated_Object {
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short string_id;
    char gap_12[0x7C];
    unsigned char map_draw_level;
    unsigned char gap_8F;
    unsigned char map_color;

    virtual void create_doppleganger(void* player, float x, float y,
                                      float z, RGE_Static_Object* object);
};

typedef RGE_Master_Static_Object RGE_Master_Object;

class RGE_Game_World {
public:
    virtual ~RGE_Game_World();
    union {
        unsigned long world_time;
        unsigned long someField;
    };
    char gap_08[0x38];
    RGE_Player** players;

    RGE_Static_Object* object(int id);
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x1E];
    short master_object_num;
    char gap_24[2];
    RGE_Master_Static_Object** master_objects;
    char gap_28[0x14];
    RGE_Game_World* world;
    char gap_40[0x0A];
    short id;
    char gap_4C[0x88];
    unsigned long mutualVisibleMask;
    unsigned long nonMutualVisibleMask;
    unsigned long RemoveVisibleBits[9];
    char gap_100[8];
    RGE_Color_Table* color_table;
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player, float x, float y,
                                    float z);
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void vf18();
    virtual void vf1C();
    virtual void vf20();
    virtual unsigned char update();
    virtual void vf28();
    virtual void rehook();
    virtual void save(int file);
    virtual void vf34();
    virtual void vf38();
    virtual void vf3C();
    virtual void vf40();
    virtual void vf44();
    virtual void vf48();
    virtual void vf4C();
    virtual void vf50();
    virtual void vf54();
    virtual void vf58();
    virtual void vf5C();
    virtual void vf60();
    virtual void vf64();
    virtual void destroy_obj();

    long id;
    RGE_Master_Static_Object* master_obj;
    union {
        RGE_Player* owner;
        void* world;
    };
    void* sprite;
    char gap_14[4];
    RGE_Active_Sprite_List* sprite_list;
    char gap_1C[0x19];
    unsigned char facet;
    char gap_36[2];
    union {
        float world_x;
        float x;
        float field_38;
    };
    union {
        float world_y;
        float y;
        float field_3C;
        float field_3c;
    };
    float world_z;
    char gap_44[4];
    unsigned char object_state;
    char gap_49[5];
    union {
        unsigned char type;
        unsigned char field_4E;
        unsigned char field_4e;
    };
    char gap_4F[0x39];

    RGE_Static_Object* get_object_pointer(long id);
};

class RGE_Animated_Object : public RGE_Static_Object {
public:
    float speed;

    RGE_Animated_Object(RGE_Master_Animated_Object* master, RGE_Player* player,
                        float x, float y, float z, int do_setup);
    RGE_Animated_Object(int file, RGE_Game_World* world, int do_setup);
    virtual unsigned char update();
    virtual int setup(RGE_Master_Animated_Object* master, RGE_Player* player,
                      float x, float y, float z);
    virtual int setup(int file, RGE_Game_World* world);
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player, float x, float y,
                                    float z);
    virtual void save(int file);
};

class RGE_Doppleganger_Object : public RGE_Animated_Object {
public:
    virtual ~RGE_Doppleganger_Object();
    virtual void recycle_in_to_game(RGE_Master_Static_Object* master,
                                    RGE_Player* player, float x, float y,
                                    float z, RGE_Static_Object* doppled);
    virtual unsigned char update();
    virtual void rehook();
    virtual void save(int file);
    virtual void destroy_obj();

    RGE_Doppleganger_Object(RGE_Master_Doppleganger_Object* master,
                            RGE_Player* player, float x, float y, float z,
                            int do_setup, RGE_Static_Object* doppled);
    RGE_Doppleganger_Object(int file, RGE_Game_World* world, int do_setup);
    virtual int setup(RGE_Master_Doppleganger_Object* master, RGE_Player* player,
                      float x, float y, float z);
    virtual int setup(int file, RGE_Game_World* world);
    void validate();

    RGE_Static_Object* doppled_object;
    RGE_Color_Table* draw_color;
    RGE_Master_Static_Object* doppled_master_obj;
    int doppled_player;
    unsigned long* MapAddress;
    union {
        unsigned long LastMapValue;
        int lastMapValue;
    };
    union {
        unsigned long CantSeeBits;
        int cantSeeBits;
    };
    unsigned char map_draw_level;
    unsigned char map_color;
    unsigned char gap_AA[2];
    union {
        int doppledObjectID;
        int doppledObjID;
    };
};

class RGE_Doppleganger_Creator {
public:
    union {
        RGE_Player* owner;
        void* player;
    };
    union {
        int allocated_size;
        int maxCount;
    };
    union {
        int active_size;
        int activeCount;
    };
    union {
        RGE_Static_Object** Objects;
        int* objects;
    };
    union {
        unsigned long** Map_Addresses;
        int* mapAddresses;
    };
    union {
        unsigned long* Last_Map_Value;
        int* lastMapValue;
    };
    union {
        int* Object_ids;
        int* objectIds;
    };

    RGE_Doppleganger_Creator(RGE_Player* player, int count);
    ~RGE_Doppleganger_Creator();
    int add_doppleganger_check(RGE_Static_Object* object,
                               unsigned long* map_address);
    int remove_doppleganger_check(RGE_Static_Object* object);
    void perform_doppleganger_checks();
    void expand_allocations(int grow_size);
};

#endif
