#include "TShape.h"
#include "RESFILE.h"
#include "TDrawArea.h"
#include "TDrawSystem.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

TShape::TShape(const char *file, int id) {
    this->shape = nullptr;
    this->load_type = 0;
    this->load_size = 0;
    this->shape_header = nullptr;
    this->head = nullptr;
    this->offsets = nullptr;
    this->FShape = nullptr;
    this->shape_info = nullptr;

    if (id >= 0) {
        // Try loading as .shp
        this->shape = RESFILE_load(0x73687020, id, &this->load_type, &this->load_size); // 'shp '
        if (this->shape) {
#ifdef _DEBUG
            printf("TShape: Loaded .shp resource %d, size %d\n", id, this->load_size);
#endif
            this->head = (Shape_File_Header *)this->shape;
            this->offsets = (Shape_Offsets *)(this->head + 1);
        } else {
            // Try loading as .slp
            this->FShape = (SLhape_File_Header *)RESFILE_load(0x736c7020, id, &this->load_type, &this->load_size); // 'slp '
            if (this->FShape) {
#ifdef _DEBUG
                printf("TShape: Loaded .slp resource %d, size %d\n", id, this->load_size);
#endif
                this->shape_info = (Shape_Info *)(this->FShape + 1);
            }
        }
    }
    
    if (!this->shape && !this->FShape && file && file[0]) {
        // TODO: Implement loading from file if needed
#ifdef _DEBUG
        printf("TShape: Failed to load resource %d, file loading not implemented yet (%s)\n", id, file);
#endif
    }
}

TShape::~TShape() {
    if (this->load_type == 1) {
        if (this->shape) free(this->shape);
        if (this->FShape) free(this->FShape);
    }
    // If load_type == 0, it's mapped memory, we don't free it here (handled by RESFILE)
}

int TShape::is_loaded() {
    return (this->shape != nullptr || this->FShape != nullptr);
}

void TShape::shape_draw(TDrawArea *dest, int x, int y, int frame) {
    if (!dest || !is_loaded()) return;

    if (this->FShape) {
        if (frame < 0 || frame >= this->FShape->Num_Shapes) return;

        Shape_Info *info = &this->shape_info[frame];
        int draw_x = x - info->Hotspot_X;
        int draw_y = y - info->Hotspot_Y;

        int bpp = dest->SurfaceDesc.ddpfPixelFormat.dwRGBBitCount;
        PALETTEENTRY *pal = dest->DrawSystem->palette;

        // Basic SLP rendering (simplified)
        uchar *data_start = (uchar *)this->FShape;
        uint *row_offsets = (uint *)(data_start + info->Shape_Data_Offsets);
        
        int pixels_drawn = 0;
        for (int row = 0; row < info->Height; row++) {
            int curr_y = draw_y + row;
            if (curr_y < 0 || curr_y >= dest->Height) continue;

            uchar *cmd_ptr = data_start + row_offsets[row];
            int curr_x = draw_x;
            bool end_of_row = false;
            int safety_count = 0;

            while (!end_of_row && safety_count < 2000) {
                safety_count++;
                uchar cmd = *cmd_ptr++;
                int count = 0;

                switch (cmd & 0x0F) {
                    case 0x00: case 0x04: case 0x08: case 0x0C: // Skip
                        count = cmd >> 2;
                        curr_x += count;
                        break;
                    case 0x01: case 0x05: case 0x09: case 0x0D: // Skip (large)
                        count = ((cmd & 0xF0) << 4) | (*cmd_ptr++);
                        curr_x += count;
                        break;
                    case 0x02: // Draw
                        count = cmd >> 2;
                        for (int i = 0; i < count; i++) {
                            if (curr_x >= 0 && curr_x < dest->Width) {
                                if (bpp == 32) {
                                    uint *bits32 = (uint *)dest->Bits;
                                    uchar idx = *cmd_ptr;
                                    bits32[curr_y * (dest->Pitch / 4) + curr_x] = (pal[idx].peRed << 16) | (pal[idx].peGreen << 8) | pal[idx].peBlue;
                                } else {
                                    dest->Bits[curr_y * dest->Pitch + curr_x] = *cmd_ptr;
                                }
                                pixels_drawn++;
                            }
                            curr_x++;
                            cmd_ptr++;
                        }
                        break;
                    case 0x03: // Draw (large)
                        count = ((cmd & 0xF0) << 4) | (*cmd_ptr++);
                        for (int i = 0; i < count; i++) {
                            if (curr_x >= 0 && curr_x < dest->Width) {
                                if (bpp == 32) {
                                    uint *bits32 = (uint *)dest->Bits;
                                    uchar idx = *cmd_ptr;
                                    bits32[curr_y * (dest->Pitch / 4) + curr_x] = (pal[idx].peRed << 16) | (pal[idx].peGreen << 8) | pal[idx].peBlue;
                                } else {
                                    dest->Bits[curr_y * dest->Pitch + curr_x] = *cmd_ptr;
                                }
                                pixels_drawn++;
                            }
                            curr_x++;
                            cmd_ptr++;
                        }
                        break;
                    case 0x06: // Player color
                        count = cmd >> 2;
                        for (int i = 0; i < count; i++) {
                            if (curr_x >= 0 && curr_x < dest->Width) {
                                if (bpp == 32) {
                                    uint *bits32 = (uint *)dest->Bits;
                                    uchar idx = *cmd_ptr; // Should use player color table
                                    bits32[curr_y * (dest->Pitch / 4) + curr_x] = (pal[idx].peRed << 16) | (pal[idx].peGreen << 8) | pal[idx].peBlue;
                                } else {
                                    dest->Bits[curr_y * dest->Pitch + curr_x] = *cmd_ptr;
                                }
                                pixels_drawn++;
                            }
                            curr_x++;
                            cmd_ptr++;
                        }
                        break;
                    case 0x07: // Fill
                        count = cmd >> 2;
                        {
                            uchar color_idx = *cmd_ptr++;
                            for (int i = 0; i < count; i++) {
                                if (curr_x >= 0 && curr_x < dest->Width) {
                                    if (bpp == 32) {
                                        uint *bits32 = (uint *)dest->Bits;
                                        bits32[curr_y * (dest->Pitch / 4) + curr_x] = (pal[color_idx].peRed << 16) | (pal[color_idx].peGreen << 8) | pal[color_idx].peBlue;
                                    } else {
                                        dest->Bits[curr_y * dest->Pitch + curr_x] = color_idx;
                                    }
                                    pixels_drawn++;
                                }
                                curr_x++;
                            }
                        }
                        break;
                    case 0x0F: // End of row
                        end_of_row = true;
                        break;
                    default:
                        end_of_row = true; // Unknown command
                        break;
                }
            }
            if (safety_count >= 2000) {
                printf("TShape::shape_draw: WARNING: Safety count reached at row %d\n", row);
            }
        }
    }
}
