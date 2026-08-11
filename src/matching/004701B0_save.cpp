// VA: 004701B0 RGE_Player::save(int)
// PDB source: player.cpp, lines 1271-1310
//
// Attempt log:
// - Replaced the placeholder scaffold with the binary-supported player save
//   field ownership, typed world/color-table surfaces, and the natural
//   serialization sequence.  Baseline preserved size/frame/call set but had
//   an 80-byte localized color-table branch-layout drift.
// - Spelled the color-table test as a positive non-null arm; this reproduces
//   the original je-to-null block topology and gives an exact 454-byte match.

#include <string.h>

extern "C" void __cdecl color_log(unsigned char, unsigned char, unsigned char);
extern "C" void __cdecl rge_write(int file, void* data, int size);

class RGE_Game_World {
public:
    char gap_00[0x3C];
    short player_num;
};

class RGE_Color_Table {
public:
    virtual ~RGE_Color_Table();
    char gap_04[0x22];
    short id;
};

class RGE_Player {
public:
    virtual ~RGE_Player();

    int computerPlayerValue;              // +0x04
    int pathingAttemptCapValue;           // +0x08
    int pathingDelayCapValue;             // +0x0C
    char gap_10[0x12];                     // +0x10 .. +0x21
    short master_object_num;               // +0x22
    char gap_24[0x18];                     // +0x24 .. +0x3B
    RGE_Game_World* world;                 // +0x3C
    char gap_40[4];                        // +0x40 .. +0x43
    char* name;                            // +0x44
    unsigned char type;                    // +0x48
    unsigned char gap_49[1];               // +0x49
    short id;                              // +0x4A
    short attribute_num;                   // +0x4C
    unsigned char gap_4E[2];               // +0x4E .. +0x4F
    float* attributes;                     // +0x50
    unsigned char culture;                // +0x54
    unsigned char gap_55[0x2B];            // +0x55 .. +0x7F
    unsigned char game_status;             // +0x80
    unsigned char resigned;                // +0x81
    unsigned char gap_82[2];               // +0x82 .. +0x83
    unsigned char* relations;              // +0x84
    int unitDiplomacy[9];                  // +0x88
    char gap_AC[0x54];                     // +0xAC .. +0xFF
    int allied_LOS_Enable;                 // +0x100
    unsigned char allied_victory;          // +0x104
    unsigned char master_player_id;        // +0x105
    unsigned char gap_106[2];              // +0x106 .. +0x107
    RGE_Color_Table* color_table;          // +0x108
    char gap_10C[4];                       // +0x10C .. +0x10F
    char gap_110[4];                       // +0x110 .. +0x113
    float view_x;                          // +0x114
    float view_y;                          // +0x118
    short map_x;                           // +0x11C
    short map_y;                           // +0x11E

    virtual void save(int file);
};

void RGE_Player::save(int file)
{
    int name_length;
    unsigned char table;

    color_log(0x32, 0x32, 3);
    rge_write(file, &this->type, 1);
    rge_write(file, this->relations, (int)this->world->player_num);
    rge_write(file, this->unitDiplomacy, 0x24);
    rge_write(file, &this->allied_LOS_Enable, 4);
    rge_write(file, &this->allied_victory, 1);

    name_length = strlen(this->name) + 1;
    rge_write(file, &name_length, 2);
    if ((short)name_length > 0) {
        rge_write(file, this->name, (short)name_length);
    }

    rge_write(file, &this->attribute_num, 2);
    short attribute_count = this->attribute_num;
    if (attribute_count > 0) {
        rge_write(file, this->attributes, (int)attribute_count << 2);
    }

    rge_write(file, &this->view_x, 4);
    rge_write(file, &this->view_y, 4);
    rge_write(file, &this->map_x, 2);
    rge_write(file, &this->map_y, 2);
    rge_write(file, &this->culture, 1);
    rge_write(file, &this->master_player_id, 1);
    rge_write(file, &this->game_status, 1);
    rge_write(file, &this->resigned, 1);

    if (this->color_table != 0) {
        table = (unsigned char)this->color_table->id;
    } else {
        table = 0;
    }
    rge_write(file, &table, 1);
    rge_write(file, &this->pathingAttemptCapValue, 4);
    rge_write(file, &this->pathingDelayCapValue, 4);
    color_log(0x32, 0x5F, 3);
}
