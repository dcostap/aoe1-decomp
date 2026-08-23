// 004536D0 RGE_Master_Static_Object::save
// Attempt log:
// 1: raw-offset reconstruction from packet: temp sprite/sound ids, name length, fixed field rge_write sequence, selected sounds loop, damage graphics loop, optional name bytes, final id write.
// 2: initial raw-offset source compiled 1376 bytes, 3 bytes under original 1379.
// 3: adding a volatile dummy/pad branch reached exact size but worsened prologue to 0x24 frame and broad mismatch (79.5504% positional / 60.4061% edit); rolled back.
// 4: changed selected-sound loop from for to do/while; no size/codegen change.
// 5: /Ob0 and /Op flag probes did not change the 1376-byte under-size and were removed.
// 6: added a redundant post-write reload/check of damage graphic count, reaching exact 1379-byte size without frame growth; still broad mismatch (73.5315% positional / 59.8260% edit).
// 7: tried naming a `self` local for the object pointer; no improvement (still exact size, 73.3865% positional / 62.6541% edit).
// 8: main remaining gap is register/prologue topology and serialization source shape: original pushes EBX then immediately keeps `this` in EBX, delays ESI/EDI saves until after early tests, uses ECX=-1 for memset-like local initialization and repne scasb; rebuilt saves EBP/ESI/EDI up front and uses EDI/ECX differently. Not accepted_drift-safe.
// 9: replaced raw offsets and fake SpriteLike/SoundLike types with the canonical typed RGE_Master_Static_Object owner, virtual save slot, and typed 0x8 damage records; short selector locals, strlen, and positive do/while damage traversal preserve the observed topology. Current check: 219 strict-diff bytes, 99.40% shape, 68 ordered calls, and a 4-byte size gap; retained as the natural typed candidate.
// 10: changed the outer damage-count guard to typed truth testing; this retained the second positive guard, reached original size, and reduced the diagnostic diff to 11 bytes. Rolled back because it changed the observed outer jbe to je and did not fix the attribute-loop pointer order.
// 11: tried an unsigned-short positive inner guard with the original outer guard; VC5 returned to the clean 219-byte codegen. Restored the clean double positive guard.
// 12: declared the attribute-flag cursor before the typed arrays; this recovered the original store-before-LEA schedule and reduced the diff to 209 bytes.
// 13: combined the reordered cursors with a nonzero outer damage guard and positive inner guard; the result reached a 1-byte diff.
// 14: local-count, widened-count, alias-pointer, and self-assignment variants did not improve the 1-byte branch gap and were removed.
// 15: reversed the outer positive comparison to `0 < damage_sprite_num`; this emits the original jbe while retaining the nested positive guard. Exact 1379-byte match.

#include <string.h>

extern "C" void rge_write(int fd, void* src, int size);

typedef unsigned char uchar;

#ifndef RGE_MS_OBJ_SHARED_CONTEXT
class RGE_Sprite {
public:
    char gap_00[0x72];
    short id;
    char gap_74[0x4];
};

class RGE_Sound {
public:
    char gap_00[0x0C];
    short id;
    char gap_0E[0x2];
};

struct RGE_Damage_Sprite_Info {
    RGE_Sprite* sprite;
    unsigned char damage_percent;
    unsigned char flag;
    char pad[2];
};

class RGE_Static_Object;
class RGE_Player;
class RGE_Game_World;
class RGE_Master_Combat_Object;
class TDrawArea;
class RGE_Color_Table;

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int fd);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                             float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player* player, float x,
                                          float y, int* value,
                                          unsigned char a, unsigned char b,
                                          unsigned char c, unsigned char d,
                                          unsigned char e, unsigned char f);
    virtual unsigned char alignment(float* x, float* y, RGE_Game_World* world,
                                    unsigned char value);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea* area, short x, short y,
                      RGE_Color_Table* colors, long clip_x, long clip_y,
                      int value, unsigned char flags);

    unsigned char master_type;
    char pad_05[3];
    char* name;
    short string_id;
    short string_id2;
    short id;
    short copy_id;
    short object_group;
    char pad_16[2];
    RGE_Sprite* sprite;
    RGE_Sprite* death_sprite;
    RGE_Sprite* undead_sprite;
    unsigned char undead_flag;
    char pad_25;
    short hp;
    float los;
    unsigned char obj_max;
    char pad_2D[3];
    float radius_x;
    float radius_y;
    float radius_z;
    RGE_Sound* selected_sound;
    RGE_Sound* created_sound;
    RGE_Sound* death_sound;
    short death_spawn_obj_id;
    unsigned char sort_number;
    unsigned char can_be_built_on;
    short button_pict;
    unsigned char hide_in_scenario_editor;
    char pad_4F;
    short portrait_pict;
    unsigned char available;
    char pad_53;
    short tile_req1;
    short tile_req2;
    short center_tile_req1;
    short center_tile_req2;
    float construction_radius_x;
    float construction_radius_y;
    unsigned char elevation_flag;
    unsigned char fog_flag;
    short terrain;
    unsigned char movement_type;
    char pad_69;
    short attribute_type_held[3];
    float attribute_amount_held[3];
    short attribute_max_amount;
    char pad_7E[2];
    float attribute_rot;
    float multiple_attribute_mod;
    unsigned char attribute_flag[3];
    unsigned char area_effect_object_level;
    unsigned char combat_level;
    unsigned char select_level;
    unsigned char map_draw_level;
    unsigned char unit_level;
    unsigned char map_color;
    unsigned char attack_reaction;
    unsigned char convert_terrain_flag;
    unsigned char damage_sprite_num;
    RGE_Damage_Sprite_Info* damage_sprites;
    int help_string_id;
    int help_page_id;
    int hotkey_id;
    unsigned char recyclable;
    unsigned char track_as_resource;
    unsigned char create_doppleganger_on_death;
    unsigned char resource_group;
    unsigned char draw_flag;
    unsigned char draw_color;
    char pad_AA[2];
    float outline_radius_x;
    float outline_radius_y;
    float outline_radius_z;
};
#endif

#define W(ptr,sz) rge_write(fd,(void*)(ptr),(sz))

void RGE_Master_Static_Object::save(int fd)
{
    RGE_Master_Static_Object* self = this;
    short name_size = 0;
    short temp_death_sprite = -1;
    short temp_undead_sprite = -1;
    short created_sound_num = -1;
    short temp_sprite = -1;
    short selected_sound_num = -1;
    short death_sound_num = -1;

    RGE_Sound* s;
    RGE_Sprite* sp;

    s = self->created_sound;
    if (s) temp_sprite = s->id;
    s = self->selected_sound;
    if (s) death_sound_num = s->id;
    s = self->death_sound;
    if (s) selected_sound_num = s->id;
    sp = self->sprite;
    if (sp) temp_death_sprite = sp->id;
    sp = self->death_sprite;
    if (sp) temp_undead_sprite = sp->id;
    sp = self->undead_sprite;
    if (sp) created_sound_num = sp->id;

    char* name = self->name;
    name_size = (short)strlen(name);
    if (name_size > 0) name_size++;

    W(&self->master_type,1);
    W(&name_size,2);
    W(&self->id,2);
    W(&self->string_id,2);
    W(&self->string_id2,2);
    W(&self->object_group,2);
    W(&temp_death_sprite,2);
    W(&temp_undead_sprite,2);
    W(&created_sound_num,2);
    W(&self->undead_flag,1);
    W(&self->hp,2);
    W(&self->los,4);
    W(&self->obj_max,1);
    W(&self->radius_x,4);
    W(&self->radius_y,4);
    W(&self->radius_z,4);
    W(&temp_sprite,2);
    W(&self->death_spawn_obj_id,2);
    W(&self->sort_number,1);
    W(&self->can_be_built_on,1);
    W(&self->button_pict,2);
    W(&self->hide_in_scenario_editor,1);
    W(&self->portrait_pict,2);
    W(&self->available,1);
    W(&self->tile_req1,2);
    W(&self->tile_req2,2);
    W(&self->center_tile_req1,2);
    W(&self->center_tile_req2,2);
    W(&self->construction_radius_x,4);
    W(&self->construction_radius_y,4);
    W(&self->elevation_flag,1);
    W(&self->fog_flag,1);
    W(&self->terrain,2);
    W(&self->movement_type,1);
    W(&self->attribute_max_amount,2);
    W(&self->attribute_rot,4);
    W(&self->area_effect_object_level,1);
    W(&self->combat_level,1);
    W(&self->select_level,1);
    W(&self->map_draw_level,1);
    W(&self->unit_level,1);
    W(&self->multiple_attribute_mod,4);
    W(&self->map_color,1);
    W(&self->help_string_id,4);
    W(&self->help_page_id,4);
    W(&self->hotkey_id,4);
    W(&self->recyclable,1);
    W(&self->track_as_resource,1);
    W(&self->create_doppleganger_on_death,1);
    W(&self->resource_group,1);
    W(&self->draw_flag,1);
    W(&self->draw_color,1);
    W(&self->outline_radius_x,4);
    W(&self->outline_radius_y,4);
    W(&self->outline_radius_z,4);

    unsigned char* soundPtr = self->attribute_flag;
    float* selectedProb = self->attribute_amount_held;
    short* selected = self->attribute_type_held;
    int i = 3;
    do {
        W(selected,2);
        W(selectedProb,4);
        W(soundPtr,1);
        selected++;
        selectedProb++;
        soundPtr++;
        --i;
    } while (i);

    W(&self->damage_sprite_num,1);
    if (0 < self->damage_sprite_num) {
        short j = 0;
        if (self->damage_sprite_num > 0) {
            do {
                W(&self->damage_sprites[j].sprite->id,2);
                W(&self->damage_sprites[j].damage_percent,2);
                W(&self->damage_sprites[j].flag,1);
                j++;
            } while (j < (short)self->damage_sprite_num);
        }
    }

    W(&death_sound_num,2);
    W(&selected_sound_num,2);
    W(&self->attack_reaction,1);
    W(&self->convert_terrain_flag,1);
    if (name_size != 0) {
        W(self->name, name_size);
    }
    W(&self->copy_id,2);
}
