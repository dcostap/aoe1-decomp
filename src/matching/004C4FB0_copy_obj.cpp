// VA: 004C4FB0 RGE_Static_Object::copy_obj
// PDB source: stat_obj.cpp lines 2543-2577
// Attempt log:
// baseline: natural copy/restore flow with the binary-proven master and
// static-object fields; 20 bytes differed where the master assignment preceded
// the new hp conversion.
// liveness: a short new_hp local added a word spill and moved 58 bytes; rolled back.
// liveness: int new_hp = master->hp preserved the observed dword parameter-home
// temporary and produced an exact match.

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Sprite;
class RGE_Player;

class RGE_Master_Static_Object {
public:
    char gap_00[0x18];
    RGE_Sprite* sprite;       // +0x18
    RGE_Sprite* death_sprite; // +0x1C
    RGE_Sprite* undead_sprite;// +0x20
    char gap_24[0x02];
    short hp;                 // +0x26
    float los;                // +0x28
};

class RGE_Static_Object {
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
    virtual void check_damage_sprites(); // +0x28
    virtual void v2C();
    virtual void v30();
    virtual void v34();
    virtual void new_sprite(RGE_Sprite* sprite); // +0x38
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
    virtual void v6C();
    virtual void v70();
    virtual void v74();
    virtual void v78();
    virtual void v7C();
    virtual void v80();
    virtual void v84();
    virtual void v88();
    virtual void v8C();
    virtual void v90();
    virtual void v94();
    virtual void v98();
    virtual void v9C();
    virtual void vA0();
    virtual void vA4();
    virtual void vA8();
    virtual void vAC();
    virtual void vB0();
    virtual void vB4();
    virtual void vB8();
    virtual void vBC();
    virtual void vC0();
    virtual void vC4();
    virtual void vC8();
    virtual void vCC();
    virtual void vD0();
    virtual void vD4();
    virtual int explore_terrain(RGE_Player* player, unsigned char mode, int value); // +0xD8
    virtual void unexplore_terrain(RGE_Player* player, unsigned char mode, int value); // +0xDC

    long id;                         // +0x04
    RGE_Master_Static_Object* master_obj; // +0x08
    RGE_Player* owner;               // +0x0C
    RGE_Sprite* sprite;              // +0x10
    char gap_14[0x08];
    void* tile;                      // +0x1C
    char gap_20[0x10];
    float hp;                        // +0x30
    char gap_34[0x14];
    unsigned char object_state;      // +0x48

    void copy_obj(RGE_Master_Static_Object* master);
};
#endif

void RGE_Static_Object::copy_obj(RGE_Master_Static_Object* master)
{
    RGE_Sprite* new_sprite = 0;

    if (this->tile != 0 && this->object_state == 2) {
        this->unexplore_terrain(this->owner, 0, -1);
        this->explore_terrain(this->owner, 0, (int)master->los);
    }

    float hp_num = this->hp / (float)(int)this->master_obj->hp;
    this->hp = (float)(int)this->master_obj->hp;
    if (this->object_state == 2) {
        this->check_damage_sprites();
    }

    RGE_Master_Static_Object* old_master = this->master_obj;
    RGE_Sprite* old_sprite = this->sprite;
    if (old_sprite == old_master->sprite) {
        new_sprite = master->sprite;
    } else if (old_sprite == old_master->death_sprite) {
        new_sprite = master->death_sprite;
    } else if (old_sprite == old_master->undead_sprite) {
        new_sprite = master->undead_sprite;
    }

    int new_hp = master->hp;
    this->master_obj = master;
    this->hp = (float)(int)new_hp * hp_num;
    if (this->object_state == 2) {
        this->check_damage_sprites();
    }

    this->master_obj = old_master;
    if (new_sprite != 0) {
        this->new_sprite(new_sprite);
    }
}
