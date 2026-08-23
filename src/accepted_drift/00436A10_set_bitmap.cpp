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
// - Tested a declaration-initialized TPicture* at the allocation site to model
//   the bitmap lifetime in the fresh diam_map TU; VC5 emitted the same first
//   hunk and full 572-byte body, so the natural typed form is retained.
// - Tested result = 0 before construction and one outer constructor-result
//   guard, while retaining both natural picture deletes.  This reached the
//   original 541-byte size, 95.12% shape, and diff 379; the cleanup block is
//   six bytes early, so the checker pairs its operator delete with the oracle's
//   destructor call.  Retain this source as the best natural reconstruction.
// - Rechecked top-scope and success-scope picture/size declarations, result
//   assignment after construction, and natural null/Dib else-if and shared-
//   label forms.  They were duplicate or worse basins; restored this clean
//   typed form.  The unresolved register and cleanup topology is unchanged.
// Accepted-drift review: the checker's destructor/delete warning is positional;
// both ordered call maps contain ~TPicture then operator delete at each cleanup.
// All 13 calls, arguments, allocation and Dib-null cases, row scans, map-image
// stores, destruction, result values, and conditional set_world effect match.
// Residual drift is picture/width register choice and shared cleanup placement.
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
    int result = 0;
    short pic_wid;
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

    TPicture* picture = new TPicture(name, param_2, 0, 0, 0);
    if (picture != 0) {
        if (picture->Dib == 0) {
            delete picture;
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
