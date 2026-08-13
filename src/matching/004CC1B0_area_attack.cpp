// VA: 004CC1B0 TRIBE_Combat_Object::area_attack
// Attempt log:
// 1: direct reconstruction from packet/decompiler with local offset stubs.
// 2: removed explicit vtbl data member after dump showed virtual class already has hidden vptr and had shifted type/owner offsets by 4.
// 3: tried dummy frame local to force original 0x28 frame; optimized out, rebuilt stays 0x24 frame and 752B.
// 4: scoped initial master/owner locals; compiler returned to the prior 737B basin.
// 5: rebuilt the owning surfaces as RGE master combat, player/world/map, combat target,
//    and typed damage/death virtual calls. Corrected the random threshold to division
//    by 0x7fff and passed the attacker as the fifth damage argument.
// 6: moved map acquisition before radius-square evaluation; frame and size reached 0x28/776B.
// 7: initial master/player locals were codegen-neutral.
// 8: inverted footprint clamp predicates to match the original FPU block layout.
// 9: squared-distance x-first order improved the localized FPU hunk.
// 10: radius-first comparison produced 100% instruction-shape and 771/776 positional bytes.
// 11: restored same-TU polymorphic player/world declarations with proven offsets;
//     emitted code was unchanged, so rolled back and retained the clean source.
// 12: direct-member early master/player accesses were codegen-neutral.
// 13: function-scope modifier local, split initialization, reference/const/register
//     aliases, separate static-object surface, and standard-header context were
//     all codegen-neutral in focused variants.
// 14: after a clean-source reset, declaring owner->world->map before the master
//     radius preserves the original initial register coloring and closes all five bytes.
// exact candidate: natural typed source, proven ownership, default VC5 flags, 776B.
// Behavior retained: ignored-target filtering, special owner gate, level gate, footprint distance,
// random hit chance, modifier calculation, typed damage argument order, and post-damage death call.

extern double DAT_00574CA8;
extern float DAT_00574C98;
extern float DAT_00574C78;
extern "C" int __cdecl debug_rand(char*, int);

class RGE_Player;
class RGE_Combat_Object;
class RGE_Action_Object;
typedef RGE_Action_Object RGE_Static_Object;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[0x0C];
    short id;
    char gap_12[0x1E];
    float radius_x;
    float radius_y;
    char gap_38[0x53];
    unsigned char area_effect_object_level;
    char gap_8C[0x2C];
};

class RGE_Master_Combat_Object : public RGE_Master_Static_Object {
public:
    char gap_B8[0x50];
    short weapon_num;
    char gap_10A[2];
    void* weapon;
    char gap_110[4];
    float weapon_range;
    float area_effect_range;
    unsigned char area_effect_level;
    char gap_11D[3];
    float speed_of_attack;
    short missile_id;
    short base_hit_chance;
};

class RGE_Game_World {
public:
    char gap_00[0x28];
    class RGE_Map* map;
};

class RGE_Player {
public:
    char gap_00[0x3C];
    RGE_Game_World* world;
};

class RGE_Tile;
class RGE_Object_Node {
public:
    RGE_Combat_Object* object;
    RGE_Object_Node* next;
};

class RGE_Tile {
public:
    char gap_00[0x10];
    RGE_Object_Node* object_list;
    char gap_14[0x04];
};

class RGE_Map {
public:
    void* vtable_ptr;
    void* map;
    long map_width;
    long map_height;
    char gap_10[0x8D8C - 0x10];
    RGE_Tile** map_row_offset;
};

#define ACTION_SLOT(n) virtual void slot_##n();
class RGE_Action_Object {
public:
    virtual ~RGE_Action_Object();
    ACTION_SLOT(04) ACTION_SLOT(08) ACTION_SLOT(0C) ACTION_SLOT(10)
    ACTION_SLOT(14) ACTION_SLOT(18) ACTION_SLOT(1C) ACTION_SLOT(20)
    ACTION_SLOT(24) ACTION_SLOT(28) ACTION_SLOT(2C) ACTION_SLOT(30)
    ACTION_SLOT(34) ACTION_SLOT(38) ACTION_SLOT(3C) ACTION_SLOT(40)
    ACTION_SLOT(44) ACTION_SLOT(48) ACTION_SLOT(4C) ACTION_SLOT(50)
    ACTION_SLOT(54) ACTION_SLOT(58) ACTION_SLOT(5C) ACTION_SLOT(60)
    ACTION_SLOT(64) ACTION_SLOT(68) ACTION_SLOT(6C)
    virtual void damage(int, void*, float, RGE_Player*, RGE_Static_Object*);
    ACTION_SLOT(74) ACTION_SLOT(78) ACTION_SLOT(7C) ACTION_SLOT(80)
    virtual void set_attribute_amount(float, unsigned char, unsigned char);
    ACTION_SLOT(88) ACTION_SLOT(8C) ACTION_SLOT(90) ACTION_SLOT(94)
    ACTION_SLOT(98) ACTION_SLOT(9C) ACTION_SLOT(A0) ACTION_SLOT(A4)
    ACTION_SLOT(A8) ACTION_SLOT(AC) ACTION_SLOT(B0) ACTION_SLOT(B4)
    ACTION_SLOT(B8) ACTION_SLOT(BC) ACTION_SLOT(C0) ACTION_SLOT(C4)
    ACTION_SLOT(C8) ACTION_SLOT(CC) ACTION_SLOT(D0) ACTION_SLOT(D4)
    ACTION_SLOT(D8) ACTION_SLOT(DC) ACTION_SLOT(E0) ACTION_SLOT(E4)
    ACTION_SLOT(E8) ACTION_SLOT(EC)

    int id;
    RGE_Master_Combat_Object* master_obj;
    RGE_Player* owner;
    char gap_10[0x20];
    float hp;
    char gap_34[4];
    float x;
    float y;
};
#undef ACTION_SLOT

class RGE_Combat_Object : public RGE_Action_Object {
public:
    virtual float calc_attack_modifier(RGE_Static_Object*);
};

class TRIBE_Combat_Object : public RGE_Combat_Object {
public:
    unsigned char area_attack(float, float, float, RGE_Combat_Object*, RGE_Static_Object*);
};

unsigned char TRIBE_Combat_Object::area_attack(float x, float y, float attack_modifier,
                                                RGE_Combat_Object* attacker,
                                                RGE_Static_Object* ignored)
{
    RGE_Player* initial_player = this->owner;
    RGE_Map* map = initial_player->world->map;
    RGE_Master_Combat_Object* initial_master = this->master_obj;
    float radius = initial_master->area_effect_range;
    float radius_squared = radius * radius;
    short max_x = (short)map->map_width;
    short max_y = (short)map->map_height;
    --max_x;
    --max_y;

    if (!(radius > DAT_00574CA8)) {
        return 0;
    }

    short x0 = (short)(x - radius) - 2;
    short x1 = (short)(x + radius) + 2;
    short y0 = (short)(y - radius) - 2;
    short y1 = (short)(y + radius) + 2;

    if (x0 < 0) {
        x0 = 0;
    }
    if (x1 > max_x + 1) {
        x1 = max_x + 1;
    }
    if (y0 < 0) {
        y0 = 0;
    }
    if (y1 > max_y + 1) {
        y1 = max_y + 1;
    }

    for (short row = y0; row < y1; ++row) {
        for (short col = x0; col < x1; ++col) {
            RGE_Object_Node* link = map->map_row_offset[row][col].object_list;
            while (link != 0) {
                RGE_Combat_Object* object = link->object;
                if (object != ignored) {
                    short master_id = this->master_obj->id;
                    if (((master_id != 0x2e && master_id != 0x28 &&
                          master_id != 0x153 && master_id != 0x159) ||
                         object->owner != this->owner) &&
                        object != this &&
                        object->master_obj->area_effect_object_level >=
                            this->master_obj->area_effect_level) {
                        float dx = object->x - x;
                        float dy = object->y - y;
                        if (dx < DAT_00574C98) {
                            dx = -dx;
                        }
                        if (dy < DAT_00574C98) {
                            dy = -dy;
                        }
                        float object_radius_x = object->master_obj->radius_x;
                        float object_radius_y = object->master_obj->radius_y;
                        if (dx > object_radius_x) {
                            dx -= object_radius_x;
                        } else {
                            dx = DAT_00574C98;
                        }
                        if (dy > object_radius_y) {
                            dy -= object_radius_y;
                        } else {
                            dy = DAT_00574C98;
                        }
                        if (radius_squared > dx * dx + dy * dy) {
                            int random_value = debug_rand(
                                (char*)"C:\\msdev\\work\\age1_x1\\t_c_obj.cpp", 0x653);
                            int chance = (random_value * 100) / 0x7fff;
                            if ((short)chance <= this->master_obj->base_hit_chance) {
                                float modifier = this->calc_attack_modifier((RGE_Static_Object*)object);
                                object->damage(this->master_obj->weapon_num,
                                               this->master_obj->weapon,
                                               modifier,
                                               this->owner,
                                               (RGE_Static_Object*)attacker);
                                if (object->hp < DAT_00574C78) {
                                    object->set_attribute_amount(0.0f, 0, 1);
                                }
                            }
                        }
                    }
                }
                link = link->next;
            }
        }
    }
    return 1;
}
