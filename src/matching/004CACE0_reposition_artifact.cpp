// VA: 004CACE0 TRIBE_Combat_Object::reposition_artifact
// PDB source: t_c_obj.cpp:586-732
// Attempt log:
// 1: prior worker used helper functions and a decompiler-shaped map-holder
//    surface; /O2 emitted helper calls and was 215 bytes short.
// 2: baseline reconstruction below restores the period ownership surface:
//    inside_obj/owner/world/map, Master_Static_Object::check_placement, and
//    the direct inline edge scans.  It keeps the original -0.5f rdata symbol
//    and the real RGE_Combat_Object virtual method signatures.
// 3: moving the found flag initialization after map acquisition fixed the
//    prologue and reduced the positional drift from 131 to 28 bytes.
// 4: declaration reordering and outer-loop index scoping were codegen
//    duplicates; no source change was retained for either.
// 5: separate natural vertical (i) and horizontal (j) scan locals let VC5
//    coalesce their lifetimes onto the original loop home; exact match.

extern float DAT_00574ca0;

#ifndef T_C_OBJ_CONTEXT_H
class RGE_Player;
class RGE_Game_World;
class RGE_Map;
class RGE_Static_Object;
class RGE_Master_Static_Object;

class RGE_Map {
public:
    char gap_00[8];
    int map_width;
    int map_height;

    unsigned char get_terrain(short col, short row);
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    RGE_Map* map;
    char gap_2c[0x14];
    RGE_Player** players;
};

class RGE_Player {
public:
    char gap_00[0x3c];
    RGE_Game_World* world;
};

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual unsigned char check_placement(RGE_Player* player,
                                            float x, float y,
                                            int* placement_info,
                                            unsigned char a,
                                            unsigned char b,
                                            unsigned char c,
                                            unsigned char d,
                                            unsigned char e,
                                            unsigned char f);
};

class RGE_Static_Object {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0c();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1c();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2c();
    virtual void v30();
    virtual float teleport(float x, float y, float z);
    virtual void v38();
    virtual void v3c();
    virtual void v40();
    virtual void change_ownership(RGE_Player* player);
    virtual void v48();
    virtual void v4c();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5c();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void v6c();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7c();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8c();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void move_to(RGE_Static_Object* object,
                         float x, float y, float z);
    virtual void va0();
    virtual void va4();
    virtual void va8();
    virtual void vac();
    virtual void vb0();
    virtual void vb4();
    virtual void vb8();
    virtual void vbc();
    virtual void vc0();
    virtual void vc4();
    virtual void vc8();
    virtual void vcc();
    virtual void vd0();
    virtual void exit_obj();

    char gap_04[4];
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;                     // +0x0c
    char gap_10[0x10];
    RGE_Static_Object* inside_obj;         // +0x20
    char gap_24[0x0c];
    float hp;                               // +0x30
    char gap_34[4];
    float world_x;                          // +0x38
    float world_y;                          // +0x3c
    float world_z;                          // +0x40

    void set_location(float x, float y, float z);
};

class RGE_Combat_Object : public RGE_Static_Object {
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    void reposition_artifact();
};
#endif

void TRIBE_Combat_Object::reposition_artifact()
{
    int y2;
    int x2;
    float y1;
    float x_pos;
    int x1;
    int found_pos;
    int map_max_x;
    int map_max_y;
    int found;
    unsigned char terrain;

    RGE_Static_Object* parent = this->inside_obj;
    if (parent != 0) {
        y2 = (int)parent->world_x;
        x2 = (int)parent->world_y;
        y1 = parent->world_x;
        x_pos = parent->world_y;
    } else {
        y2 = (int)this->world_x;
        x2 = (int)this->world_y;
        y1 = this->world_x;
        x_pos = this->world_y;
    }

    x1 = y2;
    found_pos = x2;

    RGE_Map* map = this->owner->world->map;
    found = 0;
    map_max_x = map->map_width - 1;
    map_max_y = map->map_height - 1;

    do {
        int i;
        i = y2;
        for (; i <= x1; ++i) {
            terrain = map->get_terrain((short)i, (short)x2);
            if (terrain != 1 && terrain != 2) {
                y1 = (float)i - DAT_00574ca0;
                x_pos = (float)x2 - DAT_00574ca0;
                if (!this->master_obj->check_placement(this->owner,
                                                        y1, x_pos,
                                                        0, 1, 1, 1, 0, 1, 1)) {
                    found = 1;
                    break;
                }
            }

            terrain = map->get_terrain((short)i, (short)found_pos);
            if (terrain != 1 && terrain != 2) {
                y1 = (float)i - DAT_00574ca0;
                x_pos = (float)found_pos - DAT_00574ca0;
                if (!this->master_obj->check_placement(this->owner,
                                                        y1, x_pos,
                                                        0, 1, 1, 1, 0, 1, 1)) {
                    found = 1;
                    break;
                }
            }
        }

        if (found) {
            break;
        }

        int j = x2 + 1;
        for (; j <= found_pos - 1; ++j) {
            terrain = map->get_terrain((short)y2, (short)j);
            if (terrain != 1 && terrain != 2) {
                y1 = (float)y2 - DAT_00574ca0;
                x_pos = (float)j - DAT_00574ca0;
                if (!this->master_obj->check_placement(this->owner,
                                                        y1, x_pos,
                                                        0, 1, 1, 1, 0, 1, 1)) {
                    found = 1;
                    break;
                }
            }

            terrain = map->get_terrain((short)x1, (short)j);
            if (terrain != 1 && terrain != 2) {
                y1 = (float)x1 - DAT_00574ca0;
                x_pos = (float)j - DAT_00574ca0;
                if (!this->master_obj->check_placement(this->owner,
                                                        y1, x_pos,
                                                        0, 0, 1, 1, 0, 1, 1)) {
                    found = 1;
                    break;
                }
            }
        }

        if (found) {
            break;
        }

        if (y2 == 0 && x1 == map_max_x &&
            x2 == 0 && found_pos == map_max_y) {
            parent = this->inside_obj;
            if (parent != 0) {
                y1 = parent->world_x;
                x_pos = parent->world_y;
            } else {
                y1 = this->world_x;
                x_pos = this->world_y;
            }
            break;
        }

        if (y2 > 0) {
            --y2;
        }
        if (x2 > 0) {
            --x2;
        }
        if (x1 < map_max_x) {
            ++x1;
        }
        if (found_pos < map_max_y) {
            ++found_pos;
        }
    } while (1);

    this->set_location(y1, x_pos, this->world_z);
    if (this->inside_obj != 0) {
        this->exit_obj();
    }
    this->teleport(y1, x_pos, this->world_z);
    this->change_ownership(this->owner->world->players[0]);
    this->move_to(0, y1, x_pos, this->world_z);
    this->hp = 1.0f;
}
