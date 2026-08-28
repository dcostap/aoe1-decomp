// PDB source module: C:\\msdev\\work\\age1_x1\\m_ac_obj.cpp.
// Definitions follow the original source order.

#include "../include/m_ac_obj.h"
#include "../include/act_obj.h"
#include "../include/game_globals.h"
#include "../include/player.h"
#include "../include/rge_fio.h"
#include "../include/sound.h"
#include "../include/stat_obj.h"
#include "../include/task_lst.h"
#include "../include/world.h"

RGE_Master_Action_Object::RGE_Master_Action_Object(
    RGE_Master_Action_Object* source, int do_setup)
    : RGE_Master_Moving_Object(source, 0)
{
    if (do_setup) {
        setup(source);
    }
}

RGE_Master_Action_Object::RGE_Master_Action_Object(
    int id, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : RGE_Master_Moving_Object(id, sprites, sounds, 0)
{
    if (do_setup) {
        setup(id, sprites, sounds);
    }
}

RGE_Master_Action_Object::RGE_Master_Action_Object(
    FILE* file, RGE_Sprite** sprites, RGE_Sound** sounds, short id,
    int do_setup)
    : RGE_Master_Moving_Object(file, sprites, sounds, id, 0)
{
    if (do_setup) {
        setup(file, sprites, sounds, id);
    }
}

int RGE_Master_Action_Object::setup(RGE_Master_Action_Object* source)
{
    RGE_Master_Moving_Object::setup(source);
    master_type = 0x28;
    default_task = source->default_task;
    search_radius = source->search_radius;
    work_rate = source->work_rate;
    drop_site = source->drop_site;
    backup_drop_site = source->backup_drop_site;
    task_by_group = source->task_by_group;
    command_sound = source->command_sound;
    move_sound = source->move_sound;
    run_pattern = source->run_pattern;
    tasks = create_task_list();
    tasks->copy(source->tasks);
    return 1;
}

int RGE_Master_Action_Object::setup(int file, RGE_Sprite** sprites,
                                    RGE_Sound** sounds)
{
    short command_sound_id;
    short move_sound_id;
    RGE_Sound* selected_sound;

    RGE_Master_Moving_Object::setup(file, sprites, sounds);
    master_type = 0x28;

    rge_read(file, &default_task, 2);
    rge_read(file, &search_radius, 4);
    rge_read(file, &work_rate, 4);
    rge_read(file, &drop_site, 2);
    rge_read(file, &backup_drop_site, 2);
    rge_read(file, &task_by_group, 1);
    rge_read(file, &command_sound_id, 2);
    // BINARY NOTE: save version 6.92 added a separate move sound. Older
    // saves reuse the command sound index for both sounds.
    if (save_game_version >= DAT_00570484) {
        rge_read(file, &move_sound_id, 2);
    } else {
        move_sound_id = command_sound_id;
    }
    rge_read(file, &run_pattern, 1);

    if (command_sound_id >= 0) {
        selected_sound = sounds[command_sound_id];
    } else {
        selected_sound = 0;
    }
    command_sound = selected_sound;

    if (move_sound_id >= 0) {
        selected_sound = sounds[move_sound_id];
    } else {
        selected_sound = 0;
    }
    move_sound = selected_sound;

    tasks = create_task_list();
    tasks->load(file, sprites, sounds);
    return 1;
}

int RGE_Master_Action_Object::setup(FILE* file, RGE_Sprite** sprites,
                                    RGE_Sound** sounds, short id)
{
    short task_by_group_value;
    short command_sound_id;
    short move_sound_id;
    short run_pattern_value;
    RGE_Sound* selected_sound;
    int index;
    int task_count;

    RGE_Master_Moving_Object::setup(file, sprites, sounds, id);
    master_type = 0x28;

    fscanf(file, "%f %f %hd %hd %hd %hd %hd %hd",
           &search_radius, &work_rate, &drop_site, &backup_drop_site,
           &task_by_group_value, &command_sound_id, &move_sound_id,
           &run_pattern_value);

    task_by_group = (unsigned char)task_by_group_value;
    run_pattern = (unsigned char)run_pattern_value;

    if (command_sound_id >= 0) {
        selected_sound = sounds[command_sound_id];
    } else {
        selected_sound = 0;
    }
    command_sound = selected_sound;

    if (move_sound_id >= 0) {
        selected_sound = sounds[move_sound_id];
    } else {
        selected_sound = 0;
    }
    move_sound = selected_sound;

    tasks = create_task_list();
    tasks->load(file, sprites, sounds);
    default_task = -1;
    index = 0;
    task_count = tasks->list_num;
    if (task_count > 0) {
        do {
            if (tasks->list[index]->is_default == 0) {
                index++;
            } else {
                default_task = (short)index;
                break;
            }
        } while (index < task_count);
    }
    return 1;
}

RGE_Master_Action_Object::~RGE_Master_Action_Object()
{
    if (tasks) {
        delete tasks;
        tasks = 0;
    }
}

RGE_Task_List* RGE_Master_Action_Object::create_task_list()
{
    return new RGE_Task_List();
}

RGE_Static_Object* RGE_Master_Action_Object::make_new_obj(
    RGE_Player* player, float x, float y, float z)
{
    if (recyclable) {
        RGE_Static_Object* recycled =
            player->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->recycle_in_to_game(this, player, x, y, z);
            return recycled;
        }
    }

    return new RGE_Action_Object(this, player, x, y, z, 1);
}

RGE_Master_Static_Object* RGE_Master_Action_Object::make_new_master()
{
    return new RGE_Master_Action_Object(this, 1);
}

RGE_Task* RGE_Master_Action_Object::get_task(short task_id)
{
    if ((task_id != -1) && (task_id < tasks->list_num)) {
        return tasks->list[task_id];
    }
    return 0;
}

RGE_Task* RGE_Master_Action_Object::getTaskByTaskID(int task_id) const
{
    if (task_id == -1) {
        return 0;
    }

    for (int index = 0; index < tasks->list_num; index++) {
        if (task_id == tasks->list[index]->action_type) {
            return tasks->list[index];
        }
    }
    return 0;
}

void RGE_Master_Action_Object::copy_obj(RGE_Master_Static_Object* source)
{
    RGE_Master_Moving_Object::copy_obj(source);

    RGE_Master_Action_Object* action_source =
        static_cast<RGE_Master_Action_Object*>(source);
    default_task = action_source->default_task;
    search_radius = action_source->search_radius;
    work_rate = action_source->work_rate;
    drop_site = action_source->drop_site;
    backup_drop_site = action_source->backup_drop_site;
    task_by_group = action_source->task_by_group;
    command_sound = action_source->command_sound;
    move_sound = action_source->move_sound;
    tasks->copy(action_source->tasks);
}

void RGE_Master_Action_Object::modify(float value, unsigned char attribute)
{
    if (attribute != 0x0D) {
        RGE_Master_Moving_Object::modify(value, attribute);
        return;
    }
    work_rate = value;
}

void RGE_Master_Action_Object::modify_delta(float value,
                                            unsigned char attribute)
{
    if (attribute != 0x0D) {
        RGE_Master_Moving_Object::modify_delta(value, attribute);
    } else {
        work_rate = value + work_rate;
    }
}

void RGE_Master_Action_Object::modify_percent(float value,
                                              unsigned char attribute)
{
    if (attribute != 0x0D) {
        RGE_Master_Moving_Object::modify_percent(value, attribute);
        return;
    }
    work_rate = value * work_rate;
}

void RGE_Master_Action_Object::save(int file)
{
    short command_sound_id = -1;
    short move_sound_id = -1;

    RGE_Master_Moving_Object::save(file);

    if (command_sound) {
        command_sound_id = command_sound->id;
    }
    if (move_sound) {
        move_sound_id = move_sound->id;
    }

    rge_write(file, &default_task, 2);
    rge_write(file, &search_radius, 4);
    rge_write(file, &work_rate, 4);
    rge_write(file, &drop_site, 2);
    rge_write(file, &backup_drop_site, 2);
    rge_write(file, &task_by_group, 1);
    rge_write(file, &command_sound_id, 2);
    rge_write(file, &move_sound_id, 2);
    rge_write(file, &run_pattern, 1);
    tasks->save(file);
}

void RGE_Master_Action_Object::play_command_sound()
{
    if (command_sound) {
        command_sound->play(1);
    }
}

void RGE_Master_Action_Object::play_move_sound()
{
    if (move_sound) {
        move_sound->play(1);
    }
}
