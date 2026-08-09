// VA: 0044F290 RGE_Master_Action_Object::setup
// PDB source: m_ac_obj.cpp
// Attempt log:
// - Replaced the old incomplete rsetup skeleton with the natural serialized
//   action-object load: typed fields, sound-index locals, the 6.92 compatibility
//   branch, and the real virtual task-list/load surface.
// - The binary-positive `save_game_version >= 6.92` spelling is required for
//   VC5's late legacy-copy arm; the equivalent negative guard laid out the
//   two read/copy arms in the opposite order (26-byte drift).
// - Replaced unused base virtual void* placeholders with donor-backed typed
//   declarations; emitted code stayed exact.
// - Main-agent audit confirmed canonical master-object inheritance and typed
//   task/sound ownership; emitted code remains exact.

#include <stdlib.h>

extern "C" {
    void rge_read(int fd, void* buf, int size);
}

extern float save_game_version;
extern float DAT_00570484;

class RGE_Sprite;
class RGE_Sound;
class RGE_Static_Object;
class RGE_Master_Static_Object;
class RGE_Master_Combat_Object;
class RGE_Player;
class RGE_Game_World;
class TDrawArea;
class RGE_Color_Table;

class RGE_Task_List {
public:
    void load(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
};

class RGE_Master_Animated_Object {
public:
    virtual ~RGE_Master_Animated_Object();
    virtual void copy_obj(RGE_Master_Static_Object* object);
    virtual void modify(float value, unsigned char attribute);
    virtual void modify_delta(float value, unsigned char attribute);
    virtual void modify_percent(float value, unsigned char attribute);
    virtual void save(int fd);
    virtual RGE_Static_Object* make_new_obj(RGE_Player* player, float x,
                                            float y, float z);
    virtual RGE_Master_Static_Object* make_new_master();
    virtual unsigned char check_placement(RGE_Player* player, float x, float y,
                                          int* value, unsigned char a,
                                          unsigned char b, unsigned char c,
                                          unsigned char d, unsigned char e,
                                          unsigned char f);
    virtual unsigned char alignment(float* x, float* y, RGE_Game_World* world,
                                    unsigned char value);
    virtual long calc_base_damage_ability(RGE_Master_Combat_Object* object);
    virtual void play_command_sound();
    virtual void play_move_sound();
    virtual void draw(TDrawArea* area, short x, short y, RGE_Color_Table* colors,
                      long clip_x, long clip_y, int value,
                      unsigned char flags);

    unsigned char master_type;
    char gap_005[0xB7];

    int setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
};

class RGE_Master_Moving_Object : public RGE_Master_Animated_Object {
public:
    char gap_BC[0x1C];

    int setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
};

class RGE_Master_Action_Object : public RGE_Master_Moving_Object {
public:
    RGE_Task_List* tasks;
    short default_task;
    float search_radius;
    float work_rate;
    short drop_site;
    short backup_drop_site;
    unsigned char task_by_group;
    char gap_ED[3];
    RGE_Sound* command_sound;
    RGE_Sound* move_sound;
    unsigned char run_pattern;
    char gap_F9[3];

    virtual RGE_Task_List* create_task_list();
    int setup(int fd, RGE_Sprite** sprites, RGE_Sound** sounds);
};

int RGE_Master_Action_Object::setup(int fd, RGE_Sprite** sprites,
                                    RGE_Sound** sounds)
{
    short command_sound_id;
    short move_sound_id;
    RGE_Sound* selected_sound;

    RGE_Master_Moving_Object::setup(fd, sprites, sounds);
    master_type = 0x28;

    rge_read(fd, &default_task, 2);
    rge_read(fd, &search_radius, 4);
    rge_read(fd, &work_rate, 4);
    rge_read(fd, &drop_site, 2);
    rge_read(fd, &backup_drop_site, 2);
    rge_read(fd, &task_by_group, 1);
    rge_read(fd, &command_sound_id, 2);
    if (save_game_version >= DAT_00570484) {
        rge_read(fd, &move_sound_id, 2);
    } else {
        move_sound_id = command_sound_id;
    }
    rge_read(fd, &run_pattern, 1);

    if (command_sound_id >= 0)
        selected_sound = sounds[command_sound_id];
    else
        selected_sound = (RGE_Sound*)0;
    command_sound = selected_sound;

    if (move_sound_id >= 0)
        selected_sound = sounds[move_sound_id];
    else
        selected_sound = (RGE_Sound*)0;
    move_sound = selected_sound;

    tasks = create_task_list();
    tasks->load(fd, sprites, sounds);
    return 1;
}
