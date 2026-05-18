// 00458C90 RGE_Map::place_terrain_object
// Attempt log:
// 1: natural Ghidra-based implementation with direct terrain layout and virtual object placement calls.
// 2: first compile matched final size (832) but broad shifted mismatch: frame 0x2C vs original 0x30 and this kept in ESI not EDI.
// 3: fixed terrain-table offsets to original's this+terrain*0x198 + absolute field offsets (+0x220/+0x18A/+0x1C6/+0x202); edit diff improved 48.80% -> 46.03%.
// 4: changed get_terrain call through self local; no codegen change.
// 5: tried int terrain_id with explicit &0xff to avoid byte temp; generated too-small .text/failed size budget, rolled back.
// 6: tried volatile self local to force stack home / 0x30 frame; no codegen change, left harmless but not useful.
// 7: main blocker: prologue/local topology. Original uses EDI=this before get_terrain and homes it at [esp+38]; rebuilt uses ESI=this and a byte temp at [esp+2C].
// 8: second blocker: terrain density load/register family differs (original DI holds density and ESI object; rebuilt SI density and EDI object), cascading through both placement branches.
// 9: behavior/call set is represented (debug_rand lines, vtable +0x20/+0x18, mode 0 loop and mode 1 single placement), but register/local basin is not close enough.
// GIVEUP: left in scratch; needs source/TU context or real map class context to recover original EDI-this / DI-density register allocation and 0x30 frame.

extern "C" int __cdecl debug_rand(char* file, int line);
extern "C" char s_map_cpp[];

class RGE_Player {
public:
    char gap_00[0x24];
    void** master_objects;
};

class RGE_Game_World {};

class RGE_Master_Static_Object {
public:
    virtual void vf00();
    virtual void vf04();
    virtual void vf08();
    virtual void vf0C();
    virtual void vf10();
    virtual void vf14();
    virtual void place(RGE_Player* player, float x, float y, int a, int b);
    virtual void vf1C();
    virtual unsigned char can_place(RGE_Player* player, float x, float y, int a, int b, int c, int d, int e, int f, int g);
};

class RGE_Map {
public:
    char gap_00[0x8C];
    char terrain_types[0x20 * 0x198];

    unsigned char get_terrain(short x, short y);
    void place_terrain_object(RGE_Player* player, RGE_Game_World* world, short y, short x, int unknown, int mode);
};

void RGE_Map::place_terrain_object(RGE_Player* player, RGE_Game_World* world, short y, short x, int unknown, int mode)
{
    unsigned char terrain_id;
    int terrain;
    int end_i;
    int i;
    int local_20;
    short obj_density;
    float x_pos;
    float y_pos;
    unsigned char obj_flag;

    volatile RGE_Map* self = this;
    terrain_id = ((RGE_Map*)self)->get_terrain(x, y);
    char* terrain_base = (char*)self + terrain_id * 0x198;
    end_i = *(short*)(terrain_base + 0x220);
    terrain = 0;
    if (end_i <= 0) {
        return;
    }

    i = (int)(terrain_base + 0x18A);
    do {
        int obj_type = *(short*)i;
        if (obj_type != -1) {
            RGE_Master_Static_Object* obj = (RGE_Master_Static_Object*)player->master_objects[obj_type];
            int t = terrain_id;
            char* tb = (char*)self + (t * 0x198);
            obj_density = *(short*)(tb + 0x1C6 + terrain * 2);
            obj_flag = *(unsigned char*)(tb + 0x202 + terrain);
            if (obj != 0) {
                if (mode == 0) {
                    if (obj_density > 0) {
                        local_20 = obj_density;
                        do {
                            if (obj_flag != 0) {
                                x_pos = (float)(int)x - -0.5f;
                                y_pos = (float)(int)y - -0.5f;
                            } else {
                                x_pos = (float)(int)x - (float)debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x894) * -3.051851e-05f;
                                y_pos = (float)(int)y - (float)debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x895) * -3.051851e-05f;
                            }
                            int place_it;
                            if (obj_density >= 1000) {
                                place_it = 1;
                            } else {
                                int r = debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x8A2);
                                place_it = ((r * 1000) / 0x7fff) < local_20;
                            }
                            if (place_it) {
                                if (!obj->can_place(player, x_pos, y_pos, 0, 0, 1, 0, 1, 0, 1)) {
                                    obj->place(player, x_pos, y_pos, 0, 0);
                                }
                            }
                            obj_density -= 1000;
                            local_20 -= 1000;
                        } while (obj_density > 0);
                    }
                } else {
                    if (mode == 1) {
                        if (obj_flag != 0) {
                            x_pos = (float)(int)x - -0.5f;
                            y_pos = (float)(int)y - -0.5f;
                        } else {
                            x_pos = (float)(int)x - (float)debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x8AF) * -3.051851e-05f;
                            y_pos = (float)(int)y - (float)debug_rand("C:\\msdev\\work\\age1_x1\\map.cpp", 0x8B0) * -3.051851e-05f;
                        }
                        if (!obj->can_place(player, x_pos, y_pos, 0, 0, 1, 0, 1, 0, 1)) {
                            obj->place(player, x_pos, y_pos, 0, 0);
                            return;
                        }
                    }
                }
            }
        }
        terrain++;
        i += 2;
    } while (terrain < end_i);
}
