// 004C3F90 RGE_Static_Object::check_damage_sprites()
// Source: stat_obj.cpp lines 1866-1934
// Attempt log:
// - Initial natural implementation from packet/decompiler.
// - Fixed RGE_Static_Object local layout for hidden vptr/base gap: master_obj +0x8, owner +0xC, sprite_list +0x18, hit_points +0x30, curr_damage_percent +0x34, world xyz +0x38/+0x3C/+0x40.
// - Expanded virtual declarations so use_sprite dispatches through vtable +0x38 like original.
// - Current source compiles but check_function stops because rebuilt .text is 512 bytes vs original 561. The early arithmetic/calls are behaviorally close after layout fixes, but register allocation is a different family: VC5 keeps master in EBX and delays PUSH EDI, while original pushes EDI in prologue, uses EDI=-1 sentinel and EBP=master. Damage-sprite case layout/FPU random get_point region is also much shorter/different. Left in scratch; no inline asm or accepted_drift proposal.

extern "C" int __cdecl debug_rand(char* file, int line);
static char s_stat_obj_cpp[] = "C:\\msdev\\work\\age1_x1\\stat_obj.cpp";

class RGE_Static_Object;
class RGE_Map {
public:
    void get_point(short* x, short* y, float wx, float wy, float wz, int, int);
};
class RGE_Active_Sprite_List {
public:
    void add_sprite(void* sprite, int type, int x, int y);
    void remove_sprite(void* sprite);
};
class RGE_WorldWrap { public: char gap[0x3C]; RGE_Map* map; };
class RGE_Owner { public: char gap[0x0C]; RGE_WorldWrap* world; };
struct DamageSpriteInfo { void* sprite; unsigned char damage_percent; unsigned char flag; char pad[2]; };
class RGE_Master_Static_Object {
public:
    char gap_000[0x18];
    void* sprite;
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
    virtual void use_sprite(void* sprite);
    char gap_vptr[4];
    RGE_Master_Static_Object* master_obj; // +8
    RGE_Owner* owner; // +0c
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

void RGE_Static_Object::check_damage_sprites()
{
    int new_damage_loc = -1;
    int old_damage_loc = -1;
    RGE_Master_Static_Object* master = this->master_obj;
    unsigned char count;
    unsigned char new_percent;

    if (master->hp <= 0) return;
    count = master->damage_sprite_num;
    if (count == 0) return;

    new_percent = (unsigned char)(100 - (int)(this->hit_points * 100.0f / master->hp));
    if (new_percent == this->curr_damage_percent) return;

    if (new_percent < 100 && count > 0) {
        DamageSpriteInfo* info = master->damage_sprites;
        int i = 0;
        int n = count;
        do {
            if (info->damage_percent < new_percent) new_damage_loc = i;
            if (info->damage_percent < this->curr_damage_percent) old_damage_loc = i;
            i++;
            info++;
            n--;
        } while (n != 0);
    }

    if (new_damage_loc != old_damage_loc) {
        if (new_damage_loc > -1) {
            DamageSpriteInfo* info = &this->master_obj->damage_sprites[new_damage_loc];
            unsigned char flag = info->flag;
            if (flag == 0) {
                this->sprite_list->add_sprite(info->sprite, 0x5A, 0, 0);
            }
            else if (flag == 1) {
                RGE_Master_Static_Object* m = this->master_obj;
                int rx = debug_rand(s_stat_obj_cpp, 0x774);
                float fx = this->world_x + ((float)rx * m->size_x * 0.000030517578f - m->size_x);
                int ix = (int)fx;
                int ry = debug_rand(s_stat_obj_cpp, 0x775);
                float fy = this->world_y + ((float)ry * m->size_y * 0.000030517578f - m->size_y);
                int iy = (int)fy;
                short sx, sy;
                this->owner->world->map->get_point(&sx, &sy, fx, fy, this->world_z, 0, 0);
                this->sprite_list->add_sprite(info->sprite, 0x5A, sx, sy);
            }
            else if (flag == 2) {
                this->use_sprite(info->sprite);
            }
        }

        if (old_damage_loc > -1) {
            DamageSpriteInfo* oldInfo = &this->master_obj->damage_sprites[old_damage_loc];
            if (oldInfo->flag <= 1) {
                this->sprite_list->remove_sprite(oldInfo->sprite);
            }
            else if (oldInfo->flag == 2) {
                if (new_damage_loc < 0 || this->master_obj->damage_sprites[new_damage_loc].flag != 2) {
                    this->use_sprite(this->master_obj->sprite);
                }
            }
        }
    }
    this->curr_damage_percent = new_percent;
}
