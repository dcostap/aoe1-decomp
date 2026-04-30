// 00436A10 RGE_Diamond_Map::set_bitmap (diam_map.cpp:118-221)
// EH-framed: TPicture loading, image line scanning

#include <stdlib.h>

class TPicture {
public:
    TPicture(char* name, int p2, int p3, int p4, int p5);
    ~TPicture();
    long AlignedWidth();
    char gap_00[4];
    int field_08;
    short field_14;
    short field_18;
    short field_1C;
};

class TDrawArea;

class RGE_Game_World;

class TPanel {
public:
    char pad[0xF4];
};

class RGE_Diamond_Map : public TPanel {
public:
    int set_bitmap(char* name, long param_2);

    void* world;                // +0xF4
    char gap_F8[0x30];
    void* map_image_lines;      // +0x128
    void* map_tile_rows;        // +0x12C
    short map_wid;              // +0x130
    short map_hgt;              // +0x132
    short map_image_start_y;    // +0x134
    short map_image_wid;        // +0x136
    short map_image_hgt;        // +0x138
    short map_tile_row_cnt;     // +0x13A
    float map_row_step;         // +0x13C

    void set_world(RGE_Game_World* w);
};

void* operator new(unsigned int);
void operator delete(void*);

int RGE_Diamond_Map::set_bitmap(char* name, long param_2)
{
    // Free existing map_image_lines
    if (this->map_image_lines != 0) {
        free(this->map_image_lines);
        this->map_image_lines = 0;
    }
    // Free existing map_tile_rows
    if (this->map_tile_rows != 0) {
        free(this->map_tile_rows);
        this->map_tile_rows = 0;
    }

    // Create TPicture
    TPicture* pic = new TPicture(name, param_2, 0, 0, 0);
    if (pic == 0) {
        return 0;
    }
    if (*(int*)pic == 0) {
        // Invalid picture
        delete pic;
        return 0;
    }

    short pic_height = pic->field_18;
    short pic_width = pic->field_14;
    int line_count = pic_height;

    // Allocate map_image_lines
    this->map_image_lines = calloc(line_count, 6);

    long aligned_width;
    short more_height;
    if (pic->field_1C == 1) {
        aligned_width = pic->AlignedWidth();
        more_height = 0;
    } else {
        aligned_width = pic->AlignedWidth();
        more_height = aligned_width * (line_count - 1) + pic->field_08;
        aligned_width = -pic->AlignedWidth();
    }

    this->map_image_start_y = -1;
    this->map_image_wid = 0;
    this->map_image_hgt = 0;

    if (pic_height <= 0) {
        delete pic;
        if (this->world != 0) {
            this->set_world((RGE_Game_World*)this->world);
        }
        return 1;
    }

    return 1;
}
