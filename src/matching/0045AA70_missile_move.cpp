// VA: 0045AA70 RGE_Missile_Object::missile_move
// PDB source: misl_obj.cpp
// Attempt log:
// - Original stub only.
// Probe 1: natural virtual surface with x/y/z + deltas and map bounds; body matched except byte-width return.
// Probe 2: widen visible return to int to force mov eax/xor eax tails.

#ifndef RGE_MISL_OBJ_SHARED_CONTEXT
class RGE_Game_World;
class RGE_Player { public: char gap_00[0x3C]; RGE_Game_World* world; };
class RGE_Map_Info { public: char gap_00[8]; int width; int height; };
class RGE_Game_World { public: char gap_00[0x28]; RGE_Map_Info* map_info; };

class RGE_Missile_Object {
public:
    virtual void v00();
    virtual void v04();
    virtual void v08();
    virtual void v0C();
    virtual void v10();
    virtual void v14();
    virtual void v18();
    virtual void v1C();
    virtual void v20();
    virtual void v24();
    virtual void v28();
    virtual void v2C();
    virtual void v30();
    virtual float move_to(float x, float y, float z); // +34
    virtual void v38();
    virtual void v3C();
    virtual void v40();
    virtual void v44();
    virtual void v48();
    virtual void v4C();
    virtual void v50();
    virtual void v54();
    virtual void v58();
    virtual void v5C();
    virtual void v60();
    virtual void v64();
    virtual void v68();
    virtual void destroy(); // +6C

    char gap_04[8];
    RGE_Player* owner; // +0C
    char gap_10[0x28];
    union { float x; float world_x; }; // +38
    union { float y; float world_y; }; // +3C
    union { float z; float world_z; }; // +40
    char gap_44[0x4C];
    float dx; // +90
    float dy; // +94
    float dz; // +98

    int missile_move();
};
#endif

int RGE_Missile_Object::missile_move()
{
    float new_x;
    float new_y;
    float new_z;

    new_x = this->world_x + this->dx;
    new_y = this->world_y + this->dy;
    new_z = this->world_z + this->dz;

    if (new_x < 0.0f || (float)this->owner->world->map_info->width <= new_x ||
        new_y < 0.0f || (float)this->owner->world->map_info->height <= new_y) {
        this->destroy();
    }

    if (this->move_to(new_x, new_y, new_z) == this->world_z) {
        return 1;
    }
    return 0;
}
