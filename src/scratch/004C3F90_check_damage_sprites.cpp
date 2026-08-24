// 004C3F90 RGE_Static_Object::check_damage_sprites()
// Source: stat_obj.cpp lines 1866-1934
// Attempt log:
// - Canonical ownership is the proven static-object/master layout: master_obj +0x8,
//   owner/world/map +0x0C/+0x3C/+0x28, sprite_list +0x18, hp +0x30,
//   curr_damage_percent +0x34, and world xyz +0x38/+0x3C/+0x40.
// - Corrected the active-sprite ABI to RGE_Sprite*, unsigned char, long, long;
//   the +0x38 virtual is the period new_sprite surface.
// - Recovered the binary's shared add_sprite tail with a switch and local labels;
//   flag 2/default bypass it.  Reused one random float home and modeled the
//   observed fractional coordinate formula (world coordinate minus signed-short
//   truncation plus the size-scaled random offset), restoring all 10 call targets.
// - Declaration-order and direct-member probes improved the best rebuild to 528
//   bytes versus the original 561 (67.40% shape, 453 positional diff bytes,
//   90% ordered-call alignment, frame 0x18); remaining drift is structural in
//   saved-register/index coloring, dispatch/local stack homes, and the second
//   coordinate x87 schedule.  Left in scratch; no inline asm or accepted_drift.
// - Binary-backed branch-layout probe: test the natural flag==2 branch before
//   the flag<2 removal branch, matching the original virtual-call then remove
//   call order while preserving behavior for flags above 2.
// - Typed loop probe: replaced the pointer/count do-while with an indexed
//   DamageSpriteInfo for-loop; diff improved 450 -> 415 and exact-block coverage
//   improved 25.41% -> 32.60%, but first structural drift remains at the scan gate.
// - Fresh structural probes tried the binary-looking byte-pointer walk,
//   counter width, declaration order, and master scope; all were nonexact
//   duplicates or worse (best fresh diff 432), so restored the 415-byte source.
// - A prior pass removed forced shared-tail labels, but the current binary-backed
//   switch keeps one proven add_sprite tail and preserves the ordered call set.
// - Revisited the typed scan and flag ownership. A named count in the indexed
//   scan was codegen-active, while direct typed member indexing was unchanged.
//   A natural grouped old-flag switch recovered the observed <=1/==2 compare
//   sequence and a 544-byte rebuild with all 10 ordered calls; it remains
//   nonexact at 415 positional bytes, so the source stays in scratch.
// - Follow-up scan probes tested pointer/count do-while forms, byte cursors,
//   counter widths, local order, named count lifetimes, and the decompiler's
//   float index. They were larger or changed the call surface. The byte cursor
//   recovered the EAX pointer and EDI index, but not the original EBP copy.
// - Replaced the grouped old-flag switch with the natural flag==2 / flag<2
//   if/else. This reduced the rebuild to 541 bytes and the strict diff to 414.
//   External rdata declarations were tested and restored because they widened
//   the strict diff to 415 and changed the proven x87 schedule.

extern "C" int __cdecl debug_rand(char* file, int line);
static char s_stat_obj_cpp[] = "C:\\msdev\\work\\age1_x1\\stat_obj.cpp";

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object;
class RGE_Sprite;
class RGE_Map {
public:
    void get_point(short* x, short* y, float wx, float wy, float wz, int, int);
};
class RGE_Active_Sprite_List {
public:
    void add_sprite(RGE_Sprite* sprite, unsigned char type, long x, long y);
    void remove_sprite(RGE_Sprite* sprite);
};
class RGE_Game_World { public: char gap[0x28]; RGE_Map* map; };
class RGE_Player { public: char gap[0x3C]; RGE_Game_World* world; };
struct DamageSpriteInfo { RGE_Sprite* sprite; unsigned char damage_percent; unsigned char flag; char pad[2]; };
class RGE_Master_Static_Object {
public:
    char gap_000[0x18];
    RGE_Sprite* sprite;
    char gap_01C[0x26-0x1C];
    short hp;
    char gap_028[0x30-0x28];
    float size_x;
    float size_y;
    char gap_038[0x93-0x38];
    unsigned char damage_sprite_num;
    DamageSpriteInfo* damage_sprites;
};

class RGE_Static_Object {
public:
    virtual void f0(); virtual void f1(); virtual void f2(); virtual void f3(); virtual void f4(); virtual void f5(); virtual void f6();
    virtual void f7(); virtual void f8(); virtual void f9(); virtual void f10(); virtual void f11(); virtual void f12(); virtual void f13();
    virtual void new_sprite(RGE_Sprite* sprite);
    char gap_vptr[4];
    RGE_Master_Static_Object* master_obj; // +8
    RGE_Player* owner; // +0c
    char gap_10[8];
    RGE_Active_Sprite_List* sprite_list; // +18
    char gap_1c[0x30-0x1c];
    float hit_points; // +30
    unsigned char curr_damage_percent; // +34
    char gap_35[3];
    float world_x; // +38
    float world_y; // +3c
    float world_z; // +40
    virtual void check_damage_sprites();
};
#endif

void RGE_Static_Object::check_damage_sprites()
{
    RGE_Master_Static_Object* master = this->master_obj;
    long old_damage_loc = -1;
    long new_damage_loc = -1;
    unsigned char new_percent;

    if (master->hp <= 0) return;
    if (master->damage_sprite_num == 0) return;

    new_percent = (unsigned char)(100 - (int)(this->hit_points * 100.0f / master->hp));
    if (new_percent == this->curr_damage_percent) return;

    if (new_percent < 100 && master->damage_sprite_num > 0) {
        for (int i = 0, n = master->damage_sprite_num; i < n; i++) {
            if (master->damage_sprites[i].damage_percent < new_percent) new_damage_loc = i;
            if (master->damage_sprites[i].damage_percent < this->curr_damage_percent) old_damage_loc = i;
        }
    }

    if (new_damage_loc != old_damage_loc) {
        if (new_damage_loc > -1) {
            DamageSpriteInfo* info = &this->master_obj->damage_sprites[new_damage_loc];
            unsigned char flag = info->flag;
            RGE_Sprite* sprite;
            long add_x;
            long add_y;
            switch (flag) {
            case 0:
                sprite = info->sprite;
                add_x = 0;
                add_y = 0;
                goto add_damage_sprite;
            case 1: {
                    RGE_Master_Static_Object* m = this->master_obj;
                    float rand_x = (float)debug_rand(s_stat_obj_cpp, 0x774);
                    float fx = (this->world_x - (short)this->world_x) +
                               (rand_x * m->size_x * 0.000030517578f - m->size_x);
                    rand_x = (float)debug_rand(s_stat_obj_cpp, 0x775);
                    float fy = (this->world_y - (short)this->world_y) +
                               (rand_x * m->size_y * 0.000030517578f - m->size_y);
                    short sx, sy;
                    this->owner->world->map->get_point(&sx, &sy, fx, fy, this->world_z, 0, 0);
                    sprite = info->sprite;
                    add_x = sx;
                    add_y = sy;
                    goto add_damage_sprite;
                }
            case 2:
                this->new_sprite(info->sprite);
                goto damage_sprite_done;
            default:
                goto damage_sprite_done;
            }

        add_damage_sprite:
            this->sprite_list->add_sprite(sprite, 0x5A, add_x, add_y);
        damage_sprite_done:;
        }

        if (old_damage_loc > -1) {
            DamageSpriteInfo* oldInfo = &this->master_obj->damage_sprites[old_damage_loc];
            if (oldInfo->flag == 2) {
                if (new_damage_loc < 0 || this->master_obj->damage_sprites[new_damage_loc].flag != 2) {
                    this->new_sprite(this->master_obj->sprite);
                }
            } else if (oldInfo->flag < 2) {
                this->sprite_list->remove_sprite(oldInfo->sprite);
            }
        }
    }
    this->curr_damage_percent = new_percent;
}
