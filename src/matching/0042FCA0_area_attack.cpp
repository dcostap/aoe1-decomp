// VA: 0042FCA0 RGE_Combat_Object::area_attack
// Source: com_obj.cpp lines 191-262

extern "C" long __cdecl _ftol();
#ifndef RGE_COM_OBJ_SHARED_CONTEXT
extern "C" int __cdecl debug_rand(char*, int);
#endif
extern double DAT_0056f4a0;
extern float DAT_0056f4a8;

struct Link { void* object; Link* next; };

#ifndef RGE_COM_OBJ_SHARED_CONTEXT
#include "../com_obj_fallback_area.h"
#endif

unsigned char RGE_Combat_Object::area_attack(float x, float y, float z, RGE_Combat_Object* attacker, RGE_Static_Object* ignored)
{
    float attack_modifier;
    RGE_Player* player = this->owner;
    RGE_Map* map = player->world->map;
    RGE_Master_Combat_Object* master = this->master;
    float radius = master->area_effect_range;
    short maxx = map->width - 1;
    short maxy = map->height - 1;
    float r2 = radius * radius;
    if (!(radius > DAT_0056f4a0)) return 0;

    short x0;
    x0 = (short)((long)(x - radius));
    x0 = x0 - 2;
    short x1;
    x1 = (short)((long)(x + radius));
    x1 = x1 + 2;
    short y0;
    y0 = (short)((long)(y - radius));
    y0 = y0 - 2;
    short y1;
    y1 = (short)((long)(y + radius));
    y1 = y1 + 2;
    if (x0 < 0) x0 = 0;
    if (x1 > maxx + 1) x1 = maxx + 1;
    if (y0 < 0) y0 = 0;
    if (y1 > maxy + 1) y1 = maxy + 1;

    for (short yy = y0; yy < y1; yy++) {
        for (short xx = x0; xx < x1; xx++) {
            Link* link = map->rows[yy]->cell[xx].objects;
            while (link != 0) {
                RGE_Combat_Object* obj = (RGE_Combat_Object*)link->object;
                if (obj != this &&
                    obj->master->area_effect_object_level >= this->master->area_effect_level &&
                    obj != (RGE_Combat_Object*)ignored) {
                    float dx = obj->x - x;
                    float dy = obj->y - y;
                    if (dx < DAT_0056f4a8) dx = -dx;
                    if (dy < DAT_0056f4a8) dy = -dy;
                    float radius_x = obj->master->radius_x;
                    float radius_y = obj->master->radius_y;
                    if (dx > radius_x) dx -= radius_x;
                    else dx = DAT_0056f4a8;
                    if (dy > radius_y) dy -= radius_y;
                    else dy = DAT_0056f4a8;
                    if (r2 > dx * dx + dy * dy) {
                        int rnd = debug_rand("C:\\msdev\\work\\age1_x1\\com_obj.cpp", 0xFA) * 100;
                        int chance = rnd / 0x7fff;
                        if ((short)chance <= this->master->base_hit_chance) {
                            attack_modifier = this->calc_attack_modifier((RGE_Static_Object*)obj);
                            obj->damage((int)this->master->weapon_num, this->master->weapon,
                                        attack_modifier, this->owner, (RGE_Static_Object*)attacker);
                        }
                    }
                }
                link = link->next;
            }
        }
    }
    return 1;
}
