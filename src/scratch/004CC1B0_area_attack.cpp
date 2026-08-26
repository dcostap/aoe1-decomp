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
// Policy repair: use the true canonical t_c_obj class relation and named virtual methods.
// Behavior retained: ignored-target filtering, special owner gate, level gate, footprint distance,
// random hit chance, modifier calculation, typed damage argument order, and post-damage death call.

#include "../../include/t_c_obj_context.h"

extern double DAT_00574CA8;
extern float DAT_00574C98;
extern float DAT_00574C78;
extern "C" int __cdecl debug_rand(const char*, int);

unsigned char TRIBE_Combat_Object::area_attack(float x, float y,
                                                float attack_modifier,
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
                                float modifier = this->calc_attack_modifier(
                                    (RGE_Static_Object*)object);
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
