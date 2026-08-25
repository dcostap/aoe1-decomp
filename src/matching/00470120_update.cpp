// 00470120: RGE_Player::update (player.cpp lines 1231-1254)
// Attempt 1: direct translation of the original assembly following PDB line mapping.
// No custom flags; default /O2.

// ============================================================
// Minimal type stubs needed for this function only
// ============================================================

#ifndef PLAYER_GROUPED_TU

// Forward declarations for pointer types
class TMousePointer {
public:
    void Poll();
};
extern TMousePointer* MouseSystem;

class RGE_Object_List {
public:
    void update();
};

class RGE_Victory_Conditions {
public:
    unsigned char update();
};

class RGE_Tile_List_Node; // forward for RGE_Tile_List

class RGE_Tile_List {
public:
    int list_size;
    int num_active;
    int new_count;
    int collapse_list;
    RGE_Tile_List_Node* list;
};

class Visible_Resource_Manager {
public:
    void Process_New_Tiles(RGE_Tile_List* tile_list);
};

// Forward declarations for types used as fields in RGE_Player
class RGE_Master_Static_Object;
class RGE_Visible_Map;
class RGE_Game_World;
class RGE_Doppleganger_Creator;
class RGE_Color_Table;
class RGE_Static_Object;

// ============================================================
// RGE_Player class definition (partial, fields needed for this function)
// Layout matches inventory type dump (size 0x220)
// ============================================================
class RGE_Player {
public:
    virtual ~RGE_Player();                    // vt[0] – reserve slot 0
    virtual void set_game_status(unsigned char); // vt[1] – reserve slot 1
    void update_selected();                       // non-virtual helper
    virtual void update();

    // Data members (exact order and padding to match binary layout)
    int computerPlayerValue;                       // +0x4
    int pathingAttemptCapValue;                    // +0x8
    int pathingDelayCapValue;                      // +0xC
    int currentUpdatePathingAttemptsValue;         // +0x10
    long checksum;                                 // +0x14
    long position_checksum;                        // +0x18
    long action_checksum;                          // +0x1C
    unsigned char checksum_created_this_update;    // +0x20
    unsigned char _pad_0[0x1];                     // gap at 0x21
    short master_object_num;                       // +0x22
    RGE_Master_Static_Object** master_objects;     // +0x24
    RGE_Object_List* objects;                      // +0x28
    RGE_Object_List* sleeping_objects;             // +0x2C
    RGE_Object_List* doppleganger_objects;         // +0x30
    RGE_Victory_Conditions* victory_conditions;   // +0x34
    RGE_Visible_Map* visible;                      // +0x38
    RGE_Game_World* world;                         // +0x3C
    RGE_Doppleganger_Creator* doppleganger_creator; // +0x40
    char* name;                                    // +0x44
    unsigned char type;                            // +0x48
    unsigned char _pad_1[0x1];                     // gap at 0x49
    short id;                                      // +0x4A
    short attribute_num;                           // +0x4C
    unsigned char _pad_2[0x2];                     // gap at 0x4E
    float* attributes;                             // +0x50
    unsigned char culture;                         // +0x54
    unsigned char _pad_3[0x3];                     // gap at 0x55
    RGE_Tile_List tile_list;                       // +0x58
    RGE_Tile_List diam_tile_list;                  // +0x6C
    unsigned char game_status;                     // +0x80
    unsigned char resigned;                        // +0x81
    unsigned char _pad_4[0x2];                     // gap at 0x82
    unsigned char* relations;                      // +0x84
    int unitDiplomacy[9];                          // +0x88
    int mutualAlly[9];                             // +0xAC
    unsigned long mutualExploredMask;              // +0xD0
    unsigned long mutualVisibleMask;               // +0xD4
    unsigned long nonMutualVisibleMask;            // +0xD8
    unsigned long RemoveVisibleBits[9];            // +0xDC
    int allied_LOS_Enable;                         // +0x100
    unsigned char allied_victory;                  // +0x104
    unsigned char master_player_id;                // +0x105
    unsigned char _pad_5[0x2];                     // gap at 0x106
    RGE_Color_Table* color_table;                  // +0x108
    long tribe_effect;                             // +0x10C
    Visible_Resource_Manager* VR_List;             // +0x110
    float view_x;                                  // +0x114
    float view_y;                                  // +0x118
    short map_x;                                   // +0x11C
    short map_y;                                   // +0x11E
    short selected_start_col;                      // +0x120
    short selected_start_row;                      // +0x122
    short selected_end_col;                        // +0x124
    short selected_end_row;                        // +0x126
    short replacement_terrain;                     // +0x128
    short replacement_overlay;                     // +0x12A
    short replacement_overlay_shape;               // +0x12C
    unsigned char _pad_6[0x2];                     // gap at 0x12E
    RGE_Static_Object* selected_obj;               // +0x130
    RGE_Static_Object* sel_list[25];               // +0x134
    unsigned long sel_object_properties;           // +0x198
    short sel_count;                               // +0x19C
    unsigned char groups_used[127];                // +0x19E
    unsigned char _pad_end[0x3];                   // gap at 0x21D
};

#endif

// ============================================================
// Function implementation
// ============================================================
void RGE_Player::update() {
    // Line 1231: prolog handled by compiler (push esi; mov esi, ecx)
    // Line 1235: load global MouseSystem and test
    if (MouseSystem) {
        MouseSystem->Poll(); // line 1236
    }

    // Line 1242: zero pathing attempts counter, then update object list
    this->currentUpdatePathingAttemptsValue = 0;
    this->objects->update();

    // Line 1243: update selected units/objects
    this->update_selected();

    // Line 1244-1245: update victory conditions and check result
    if (this->victory_conditions->update() == 1) {
        // vt[1]: call set_game_status(2)
        this->set_game_status(2);
    }

    // Line 1251: clear per-update checksum flag before VR_List processing
    this->checksum_created_this_update = 0;

    // Line 1251-1252: if VR_List exists, process new tiles
    if (this->VR_List) {
        // Pass address of tile_list (offset 0x58 from this)
        this->VR_List->Process_New_Tiles(&this->tile_list);
    }

    // Epilog: compiler will emit pop esi; ret
}
