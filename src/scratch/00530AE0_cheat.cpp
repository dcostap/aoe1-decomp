// VA: 00530AE0 TRIBE_World::cheat (1534 B)
// PDB source: tworld.cpp
// Packet-grounded: cheat code dispatch by param_2 (switch 0..N)

extern int RGE_Base_Game_allowCheatCodes(void* game);
extern void* rge_base_game;
extern void* RGE_Object_List_find_by_master_id(void* list, int masterId, 
    float x1, float x2, unsigned char f1, unsigned char f2, void* unk);
extern int TRIBE_Command_command_make(void* world, void* obj, int cmd);

extern void TRIBE_World_sendMessage(void* self, int msgId, void* player);

struct Shim_cheat_AE0 {
    char gap00[0x28];
    void* object_list;         // +0x28
    char gap2C[0x40 - 0x2C];
    void** player_array;       // +0x40
};

void TRIBE_World_cheat(Shim_cheat_AE0* self, short cheatId, short playerIdx)
{
    if (!RGE_Base_Game_allowCheatCodes(rge_base_game))
        return;
    
    void* obj;
    
    switch (cheatId) {
    case 0:
        if (playerIdx > 0) {
            obj = RGE_Object_List_find_by_master_id(
                *(void**)((char*)self->player_array[playerIdx] + 0x28),
                0x6D, -1.0f, -1.0f, 1, 2, 0);
            if (obj) TRIBE_Command_command_make(self, obj, 0x112);
        }
        break;
    case 1:
        if (playerIdx > 0) {
            obj = RGE_Object_List_find_by_master_id(
                *(void**)((char*)self->player_array[playerIdx] + 0x28),
                0x6D, -1.0f, -1.0f, 1, 2, 0);
            if (obj) TRIBE_Command_command_make(self, obj, 0xF8);
        }
        break;
    case 2: case 3: case 4:
    case 6: case 7: case 8: case 9: case 10:
    case 12: case 13: case 14: case 15:
        if (playerIdx > 0)
            TRIBE_World_sendMessage(self, cheatId + 0x7D, self->player_array[playerIdx]);
        break;
    case 5: case 16:
        TRIBE_World_sendMessage(self, cheatId == 5 ? 0x82 : 0x8C, self->player_array[0]);
        break;
    case 11:
        if (playerIdx > 0) {
            obj = RGE_Object_List_find_by_master_id(
                *(void**)((char*)self->player_array[playerIdx] + 0x28),
                0x6D, -1.0f, -1.0f, 1, 2, 0);
            if (obj) TRIBE_Command_command_make(self, obj, 0x98);
        }
        break;
    case 17:
        if (playerIdx > 0) {
            obj = RGE_Object_List_find_by_master_id(
                *(void**)((char*)self->player_array[playerIdx] + 0x28),
                0x6D, -1.0f, -1.0f, 1, 2, 0);
            if (obj) TRIBE_Command_command_make(self, obj, 0x53);
        }
        break;
    }
}
