// 00436A10 RGE_Diamond_Map::set_bitmap (diam_map.cpp:118-221)
// Attempt log:
// - Replaced the incomplete loader with the binary-supported TPicture layout,
//   image-line ownership, orientation-dependent row setup, and two natural
//   sentinel scans.  The original FS registration is retained through the
//   donor-proven /GX translation-unit exception.
// - The canonical candidate reached 572 emitted bytes (original 541), 13/13
//   ordered calls, and 89.20% instruction-shape similarity.  A bounded `for`
//   scan recovered the oracle's first row-loop topology; declaration-order,
//   explicit-cleanup, result/goto, and parameter-home probes were neutral.
// - Final unresolved drift begins at the picture cleanup/control-flow split:
//   VC5 keeps the picture in EBX and duplicates two failure epilogues, while
//   the oracle keeps it in EBP/width in BX and jumps to one shared epilogue.
//   No opaque register forcing or parameter-home cast is retained.
// - Tested one typed ownership scope: one postcondition delete and a result-
//   gated set_world.  It reduced size to 528 and diff to 387, but merged the
//   two observed TPicture cleanup call sites (11/13 ordered calls); rolled back.
// FLAGS: config/flags/00436A10_set_bitmap.rsp (/nologo /c /O2 /Oy /GX)

#include <stdlib.h>

class TPicture {
public:
    void* Dib;                    // +0x00
    void* BitmapInfo;             // +0x04
    unsigned char* Bits;          // +0x08
    void* TransInfo;              // +0x0C
    int OwnMemory;                // +0x10
    int Width;                    // +0x14
    int Height;                   // +0x18
    short Orien;                  // +0x1C

    TPicture(char* name, long param_2, int param_3, void* param_4, int param_5);
    ~TPicture();
    long AlignedWidth();
};

class RGE_Game_World;

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0xF0];
};

class RGE_Map_Image_Line {
public:
    short tile_row;
    short start_x;
    short line_len;
};

class RGE_Diamond_Map : public TPanel {
public:
    int set_bitmap(char* name, long param_2);

    RGE_Game_World* world;         // +0xF4
    char gap_F8[0x30];
    RGE_Map_Image_Line* map_image_lines; // +0x128
    void* map_tile_rows;           // +0x12C
    short map_wid;                 // +0x130
    short map_hgt;                 // +0x132
    short map_image_start_y;       // +0x134
    short map_image_wid;           // +0x136
    short map_image_hgt;           // +0x138
    short map_tile_row_cnt;        // +0x13A
    float map_row_step;            // +0x13C

    void set_world(RGE_Game_World* w);
};

void* operator new(unsigned int);
void operator delete(void*);

int RGE_Diamond_Map::set_bitmap(char* name, long param_2)
{
    int result;
    short pic_wid;
    TPicture* picture;
    short pic_hgt;
    char* pic_line;
    short pic_pitch;
    short y;

    if (this->map_image_lines != 0) {
        free(this->map_image_lines);
        this->map_image_lines = 0;
    }
    if (this->map_tile_rows != 0) {
        free(this->map_tile_rows);
        this->map_tile_rows = 0;
    }

    picture = new TPicture(name, param_2, 0, 0, 0);
    if (picture == 0) {
        result = 0;
    } else {
        if (picture->Dib == 0) {
            delete picture;
            result = 0;
        } else {
            pic_hgt = (short)picture->Height;
            pic_wid = (short)picture->Width;
            this->map_image_lines = (RGE_Map_Image_Line*)calloc(pic_hgt, 6);

            if (picture->Orien == 1) {
                pic_line = (char*)picture->Bits;
                pic_pitch = (short)picture->AlignedWidth();
            } else {
                pic_line = (char*)(picture->AlignedWidth() * (pic_hgt - 1) +
                                   (long)picture->Bits);
                pic_pitch = -(short)picture->AlignedWidth();
            }

            this->map_image_start_y = -1;
            this->map_image_wid = 0;
            this->map_image_hgt = 0;

            y = 0;
            if (pic_hgt > 0) {
                do {
                    short start_x = -1;
                    short x = 0;
                    char* p = pic_line;

                    if (pic_wid > 0) {
                        for (; x < pic_wid; ++p, ++x) {
                            if (*p == -1) {
                                start_x = x;
                                break;
                            }
                        }
                    }

                    if (start_x != -1) {
                        short line_len = 0;
                        while (x < pic_wid && *p == -1) {
                            ++line_len;
                            ++p;
                            ++x;
                        }

                        this->map_image_lines[this->map_image_hgt].start_x = start_x;
                        this->map_image_lines[this->map_image_hgt].line_len = line_len;
                        ++this->map_image_hgt;
                        if (this->map_image_wid < line_len) {
                            this->map_image_wid = line_len;
                        }
                        if (this->map_image_start_y == -1) {
                            this->map_image_start_y = y;
                        }
                    }

                    pic_line += pic_pitch;
                    ++y;
                } while (y < pic_hgt);
            }

            delete picture;
            if (this->world != 0) {
                this->set_world(this->world);
            }
            result = 1;
        }
    }
    return result;
}
