// 00436A10 RGE_Diamond_Map::set_bitmap (diam_map.cpp:118-221)
// Attempt log:
// - The typed TPicture reconstruction preserves the two frees, allocation,
//   constructor, bitmap publication, row scans, cleanup calls, and set_world.
// - Natural early returns for null picture and null Dib recover the original
//   branch topology.  Reversing the width comparison recovers every CFG block.
// - Fresh validation: 13/13 calls, matching frame and saved registers, 100%
//   block coverage, and 359 differing bytes.  The remaining bytes are the
//   picture/width register colors.  The rebuilt body is one byte shorter.
// - Declaration, alias, parameter-home, header-order, and cleanup spelling
//   probes did not recover the EBP picture and BX width colors.
// - Ambient declarations and an early TPicture declaration are not evidence.
//   Both tests produced one unchanged compiler basin.  No such context remains.
// - The retained source is the smallest natural form that keeps fault order,
//   allocation/free order, bitmap publication, and all 13 direct calls.
// BLOCKED: exactness still needs the original VC5 register allocation basin.
// FLAGS: config/flags/00436A10_set_bitmap.rsp (/nologo /c /O2 /Oy /GX)

#include "../../include/diam_map_context.h"
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

void* operator new(unsigned int);
void operator delete(void*);

int RGE_Diamond_Map::set_bitmap(char* name, long param_2)
{
    TPicture* picture;
    short pic_hgt;
    short pic_wid;
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
    if (picture == 0)
        return 0;
    if (picture->Dib == 0) {
        delete picture;
        return 0;
    }
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
                        if (line_len > this->map_image_wid) {
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
    return 1;
}
