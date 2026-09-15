
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
    RGE_Master_Action_Object* other_object, int do_setup)
    : RGE_Master_Moving_Object(other_object, 0) {
    if (do_setup) {
        setup(other_object);
    }
}

RGE_Master_Action_Object::RGE_Master_Action_Object(
    int infile, RGE_Sprite** sprites, RGE_Sound** sounds, int do_setup)
    : RGE_Master_Moving_Object(infile, sprites, sounds, 0) {
    if (do_setup) {
        setup(infile, sprites, sounds);
    }
}

RGE_Master_Action_Object::RGE_Master_Action_Object(
    FILE* infile, RGE_Sprite** sprites, RGE_Sound** sounds, short in_id,
    int do_setup)
    : RGE_Master_Moving_Object(infile, sprites, sounds, in_id, 0) {
    if (do_setup) {
        setup(infile, sprites, sounds, in_id);
    }
}

int RGE_Master_Action_Object::setup(RGE_Master_Action_Object* other_object) {
    RGE_Master_Moving_Object::setup(other_object);
    master_type = 0x28;
    default_task = other_object->default_task;
    search_radius = other_object->search_radius;
    work_rate = other_object->work_rate;
    drop_site = other_object->drop_site;
    backup_drop_site = other_object->backup_drop_site;
    task_by_group = other_object->task_by_group;
    command_sound = other_object->command_sound;
    move_sound = other_object->move_sound;
    run_pattern = other_object->run_pattern;
    tasks = create_task_list();
    tasks->copy(other_object->tasks);
    return 1;
}

int RGE_Master_Action_Object::setup(int infile, RGE_Sprite** sprites,
                                    RGE_Sound** sounds) {
    short command_sound_num;
    short move_sound_num;
    RGE_Sound* selected_sound;

    RGE_Master_Moving_Object::setup(infile, sprites, sounds);
    master_type = 0x28;

    rge_read(infile, &default_task, 2);
    rge_read(infile, &search_radius, 4);
    rge_read(infile, &work_rate, 4);
    rge_read(infile, &drop_site, 2);
    rge_read(infile, &backup_drop_site, 2);
    rge_read(infile, &task_by_group, 1);
    rge_read(infile, &command_sound_num, 2);
    // save version 6.92 added a separate move sound. Older
    // saves reuse the command sound index for both sounds.
    if (save_game_version >= DAT_00570484) {
        rge_read(infile, &move_sound_num, 2);
    } else {
        move_sound_num = command_sound_num;
    }
    rge_read(infile, &run_pattern, 1);

    if (command_sound_num >= 0) {
        selected_sound = sounds[command_sound_num];
    } else {
        selected_sound = 0;
    }
    command_sound = selected_sound;

    if (move_sound_num >= 0) {
        selected_sound = sounds[move_sound_num];
    } else {
        selected_sound = 0;
    }
    move_sound = selected_sound;

    tasks = create_task_list();
    tasks->load(infile, sprites, sounds);
    return 1;
}

int RGE_Master_Action_Object::setup(FILE* infile, RGE_Sprite** sprites,
                                    RGE_Sound** sounds, short in_id) {
    short temp_task_by_group;
    short temp_command_sound;
    short temp_move_sound;
    short temp_run_pattern;
    RGE_Sound* selected_sound;
    int index;
    int task_count;

    RGE_Master_Moving_Object::setup(infile, sprites, sounds, in_id);
    master_type = 0x28;

    fscanf(infile, "%f %f %hd %hd %hd %hd %hd %hd",
           &search_radius, &work_rate, &drop_site, &backup_drop_site,
           &temp_task_by_group, &temp_command_sound, &temp_move_sound,
           &temp_run_pattern);

    task_by_group = (unsigned char)temp_task_by_group;
    run_pattern = (unsigned char)temp_run_pattern;

    if (temp_command_sound >= 0) {
        selected_sound = sounds[temp_command_sound];
    } else {
        selected_sound = 0;
    }
    command_sound = selected_sound;

    if (temp_move_sound >= 0) {
        selected_sound = sounds[temp_move_sound];
    } else {
        selected_sound = 0;
    }
    move_sound = selected_sound;

    tasks = create_task_list();
    tasks->load(infile, sprites, sounds);
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

RGE_Master_Action_Object::~RGE_Master_Action_Object() {
    if (tasks) {
        delete tasks;
        tasks = 0;
    }
}

RGE_Task_List* RGE_Master_Action_Object::create_task_list() {
    return new RGE_Task_List();
}

RGE_Static_Object* RGE_Master_Action_Object::make_new_obj(
    RGE_Player* owner, float x, float y, float z) {
    if (recyclable) {
        RGE_Static_Object* recycled =
            owner->world->recycle_object_in_to_game(master_type);
        if (recycled) {
            recycled->recycle_in_to_game(this, owner, x, y, z);
            return recycled;
        }
    }

    return new RGE_Action_Object(this, owner, x, y, z, 1);
}

RGE_Master_Static_Object* RGE_Master_Action_Object::make_new_master() {
    return new RGE_Master_Action_Object(this, 1);
}

RGE_Task* RGE_Master_Action_Object::get_task(short task_id) {
    if ((task_id != -1) && (task_id < tasks->list_num)) {
        return tasks->list[task_id];
    }
    return 0;
}

RGE_Task* RGE_Master_Action_Object::getTaskByTaskID(int t) const {
    if (t == -1) {
        return 0;
    }

    for (int index = 0; index < tasks->list_num; index++) {
        if (t == tasks->list[index]->action_type) {
            return tasks->list[index];
        }
    }
    return 0;
}

void RGE_Master_Action_Object::copy_obj(RGE_Master_Static_Object* source) {
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

void RGE_Master_Action_Object::modify(float amount, unsigned char flag) {
    if (flag != 0x0D) {
        RGE_Master_Moving_Object::modify(amount, flag);
        return;
    }
    work_rate = amount;
}

void RGE_Master_Action_Object::modify_delta(float amount,
                                            unsigned char flag) {
    if (flag != 0x0D) {
        RGE_Master_Moving_Object::modify_delta(amount, flag);
    } else {
        work_rate = amount + work_rate;
    }
}

void RGE_Master_Action_Object::modify_percent(float amount,
                                              unsigned char flag) {
    if (flag != 0x0D) {
        RGE_Master_Moving_Object::modify_percent(amount, flag);
        return;
    }
    work_rate = amount * work_rate;
}

void RGE_Master_Action_Object::save(int outfile) {
    short command_sound_num = -1;
    short move_sound_num = -1;

    RGE_Master_Moving_Object::save(outfile);

    if (command_sound) {
        command_sound_num = command_sound->id;
    }
    if (move_sound) {
        move_sound_num = move_sound->id;
    }

    rge_write(outfile, &default_task, 2);
    rge_write(outfile, &search_radius, 4);
    rge_write(outfile, &work_rate, 4);
    rge_write(outfile, &drop_site, 2);
    rge_write(outfile, &backup_drop_site, 2);
    rge_write(outfile, &task_by_group, 1);
    rge_write(outfile, &command_sound_num, 2);
    rge_write(outfile, &move_sound_num, 2);
    rge_write(outfile, &run_pattern, 1);
    tasks->save(outfile);
}

void RGE_Master_Action_Object::play_command_sound() {
    if (command_sound) {
        command_sound->play(1);
    }
}

void RGE_Master_Action_Object::play_move_sound() {
    if (move_sound) {
        move_sound->play(1);
    }
}
