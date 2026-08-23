// 00540A40 RGE_Game_World::~RGE_Game_World
// World.cpp lines 226-344.
//
// The PDB class surfaces and this-relative accesses identify each owned member.
// Keep the seven list deletes separate. Their source lines and direct destructor
// calls prove separate member expressions.
//
// Recovery notes:
// 1. The old local overlays emitted 678 bytes and differed at 66 positions.
// 2. Canonical members, virtual ownership, globals, and stdio emitted all 674 exact bytes.
// 3. Removing the RGE_Command leading slot changed the first delete call and failed.
// 4. Virtual RGE_Sprite destruction replaced the two direct calls and failed.
// 5. Nonvirtual RGE_Effects, RGE_Color_Table, or AIPlayBook destruction failed separately.

#include "../../include/world_scenario_context.h"

RGE_Game_World::~RGE_Game_World()
{
    delete this->commands;
    this->del_game_info();

    delete this->reusable_static_objects;
    delete this->reusable_animated_objects;
    delete this->reusable_moving_objects;
    delete this->reusable_action_objects;
    delete this->reusable_combat_objects;
    delete this->reusable_missile_objects;
    delete this->reusable_doppleganger_objects;

    if (this->master_players != 0) {
        for (int i = 0; i < this->master_player_num; i++) {
            if (this->master_players[i] != 0) {
                delete this->master_players[i];
                this->master_players[i] = 0;
            }
        }
        free(this->master_players);
        this->master_players = 0;
    }

    if (this->effects != 0) {
        delete this->effects;
        this->effects = 0;
    }

    if (this->map != 0) {
        delete this->map;
        this->map = 0;
    }

    if (this->sprites != 0) {
        for (int i = 0; i < this->sprite_num; i++) {
            if (this->sprites[i] != 0) {
                delete this->sprites[i];
            }
        }
        free(this->sprites);
        this->sprites = 0;
    }

    if (this->sounds != 0) {
        for (int i = 0; i < this->sound_num; i++) {
            if (this->sounds[i] != 0) {
                delete this->sounds[i];
            }
        }
        free(this->sounds);
        this->sounds = 0;
    }

    if (this->terrains != 0) {
        for (int i = 0; i < this->terrain_num; i++) {
            if (this->terrains[i] != 0) {
                free(this->terrains[i]);
            }
        }
        free(this->terrains);
        this->terrains = 0;
    }

    if (this->color_tables != 0) {
        for (int i = 0; i < this->color_table_num; i++) {
            if (this->color_tables[i] != 0) {
                delete this->color_tables[i];
            }
        }
        free(this->color_tables);
        this->color_tables = 0;
    }

    if (this->objectsValue != 0) {
        delete this->objectsValue;
        this->objectsValue = 0;
        VIS_UNIT_objectsValue = 0;
    }

    if (this->negativeObjectsValue != 0) {
        delete this->negativeObjectsValue;
        this->negativeObjectsValue = 0;
    }

    if (logStatusFile != 0) {
        fclose(logStatusFile);
        logStatusFile = 0;
    }

    if (this->playbook != 0) {
        delete this->playbook;
        this->playbook = 0;
    }

    if (DVlogf != 0) {
        fclose(DVlogf);
        DVlogf = 0;
    }
}
