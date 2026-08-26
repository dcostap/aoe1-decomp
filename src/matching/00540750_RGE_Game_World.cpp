// public: __thiscall RGE_Game_World::RGE_Game_World(void)
// VA: 00540750
// PDB-qualified owner/name: public: __thiscall RGE_Game_World::RGE_Game_World(void)
// PDB source: World.cpp:138-221
// Original body boundary: 00540750-00540A0B; next symbol: 00540A40.
// 00540700 is the separate vw_main.cpp sibling and ends at 00540747.
// The constructor uses the reviewed World.cpp class surface. The compiler
// emits the constructor prologue and exception cleanup.
// BINARY NOTE: The first two allocations publish objectsValue before the seven
// separate list allocations. The repeated guarded constructor blocks preserve
// exception cleanup state and fault order.
// Recovery log: the initial body-assignment form differed by 42 bytes after
// the reduced field order. A natural initializer list recovered the delayed
// vptr and the exact first allocation block. Moving effects after commands and
// scenario, next IDs after temp_pause, and sound indices after game_end matched
// the remaining store order. Walkbacks proved each placement necessary.
// Final validation: MATCH, 700 bytes, 0.0000%, 17 ordered direct calls.

#include <stdio.h>
#include "../world_phase2_context.h"

void* __cdecl operator new(unsigned int);
extern "C" FILE* __cdecl fopen(const char*, const char*);

RGE_Game_World::RGE_Game_World()
    : objectsValue(0),
      numberObjectsValue(0),
      maxNumberObjectsValue(10000),
      negativeObjectsValue(0),
      numberNegativeObjectsValue(0),
      maxNumberNegativeObjectsValue(1000),
      maximumComputerPlayerUpdateTime(2),
      availableComputerPlayerUpdateTime(2),
      currentUpdateComputerPlayer(-1),
      difficultyLevelValue(-1)
{
    world_update_counter = 0;
    objectsValue = static_cast<RGE_Static_Object**>(operator new(maxNumberObjectsValue * 4));
    negativeObjectsValue = static_cast<RGE_Static_Object**>(operator new(maxNumberNegativeObjectsValue * 4));
    VIS_UNIT_objectsValue = objectsValue;
    playbook = 0;
    sound_num = 0;
    sounds = 0;
    sprite_num = 0;
    sprites = 0;
    player_num = 0;
    players = 0;
    master_player_num = 0;
    master_players = 0;
    terrain_num = 0;
    terrains = 0;
    color_table_num = 0;
    color_tables = 0;
    commands = 0;
    scenario = 0;
    effects = 0;
    map = 0;
    world_time = 0;
    old_world_time = 0;
    world_time_delta = 0;
    world_time_delta_seconds = 0;
    timer = 0;
    old_time = 0;
    game_speed = 0;
    temp_pause = 0;
    next_object_id = 0;
    next_reusable_object_id = -1;
    random_seed = 14;
    curr_player = 1;
    sound_driver = 0;
    game_state = 2;
    game_end_condition = 0;
    sound_update_index = 0;
    sprite_update_index = 0;
    player_turn = 0;
    for (int i = 0; i < 9; i++) {
        player_time_delta[i] = 0;
    }
    reusable_static_objects = new RGE_Object_List;
    reusable_animated_objects = new RGE_Object_List;
    reusable_moving_objects = new RGE_Object_List;
    reusable_action_objects = new RGE_Object_List;
    reusable_combat_objects = new RGE_Object_List;
    reusable_missile_objects = new RGE_Object_List;
    reusable_doppleganger_objects = new RGE_Object_List;
    scenario_object_flag = 0;
    if (DVlogf == 0) {
        DVlogf = fopen("c:\\aoeWVlog.txt", "w");
    }
}
