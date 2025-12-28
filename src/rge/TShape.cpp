#include "TShape.h"
#include "RESFILE.h"
#include "TDrawArea.h"
#include "TDrawSystem.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

TShape::TShape(const char *file, int id) {
    // Member initialization matching Ghidra 004b8b30
    this->shape = nullptr;
    this->shape_header = nullptr;
    this->head = nullptr;
    this->offsets = nullptr;
    this->FShape = nullptr;
    this->shape_info = nullptr;
    this->load_type = -1;
    this->load_size = 0;

    // Logic for Constructor at 004b8b50 (implied)
    if (id >= 0) {
        // Try loading as .shp (RGE format)
        this->shape = (uchar *)RESFILE_load(0x73687020, id, &this->load_type, &this->load_size); // 'shp '
        if (this->shape) {
            this->head = (Shape_File_Header *)this->shape;
            this->offsets = (Shape_Offsets *)(this->head + 1);
        } else {
            // Try loading as .slp (AoE format)
            this->FShape = (SLhape_File_Header *)RESFILE_load(0x736c7020, id, &this->load_type, &this->load_size); // 'slp '
            if (this->FShape) {
                this->shape_info = (Shape_Info *)(this->FShape + 1);
            }
        }
    }
    
    // TODO: Implement file loading if shape/FShape is still null and 'file' is provided
    if (!this->shape && !this->FShape && file && file[0]) {
#ifdef _DEBUG
        printf("TShape: Failed to load resource %d, file loading not implemented yet (%s)\n", id, file);
#endif
    }
}

TShape::~TShape() {
    // Only free if load_type indicates allocated memory (usually 1)
    if (this->load_type == 1) {
        if (this->shape) free(this->shape);
        // Note: FShape and shape usually point to the same RESFILE block, 
        // but if they were allocated separately:
        if (this->FShape && (void*)this->FShape != (void*)this->shape) free(this->FShape);
    }
    // Type 0 implies mapped memory managed by RESFILE
}

int TShape::is_loaded() {
    return (this->shape != nullptr || this->FShape != nullptr);
}

void TShape::shape_draw(TDrawArea *dest, int x, int y, int frame) {
    if (!dest || !is_loaded()) return;

    // SLP Drawing Logic
    if (this->FShape) {
        if (frame < 0 || frame >= this->FShape->Num_Shapes) return;

        Shape_Info *info = &this->shape_info[frame];
        int draw_x = x - info->Hotspot_X;
        int draw_y = y - info->Hotspot_Y;

        // Ensure dest surface is locked/ready
        if (!dest->Bits && dest->DrawSurface) {
             // If we were using the real TShape::shape_draw, we would likely call dest->Lock() here
        }

        int bpp = dest->SurfaceDesc.ddpfPixelFormat.dwRGBBitCount;
        // Fallback if palette is missing (sanity check)
        PALETTEENTRY *pal = (dest->DrawSystem) ? dest->DrawSystem->palette : nullptr;

        uchar *data_start = (uchar *)this->FShape;
        uint *row_offsets = (uint *)(data_start + info->Shape_Data_Offsets);
        
        for (int row = 0; row < info->Height; row++) {
            int curr_y = draw_y + row;
            if (curr_y < 0 || curr_y >= dest->Height) continue;

            // Use TDrawArea's pitch or calculate manually
            int dest_row_offset = curr_y * dest->Pitch;
            
            uchar *cmd_ptr = data_start + row_offsets[row];
            int curr_x = draw_x;
            bool end_of_row = false;
            
            // Basic RLE decoder for SLP
            while (!end_of_row) {
                uchar cmd = *cmd_ptr++;
                int count = 0;

                switch (cmd & 0x0F) {
                    case 0x00: case 0x04: case 0x08: case 0x0C: // Skip short
                        count = cmd >> 2;
                        curr_x += count;
                        break;
                    case 0x01: case 0x05: case 0x09: case 0x0D: // Skip long
                        count = ((cmd & 0xF0) << 4) | (*cmd_ptr++);
                        curr_x += count;
                        break;
                    case 0x02: // Copy short
                        count = cmd >> 2;
                        if (curr_x + count > 0 && curr_x < dest->Width) {
                            for (int i = 0; i < count; i++) {
                                if (curr_x >= 0 && curr_x < dest->Width) {
                                    if (bpp == 8) {
                                        dest->Bits[dest_row_offset + curr_x] = *cmd_ptr;
                                    } else if (bpp == 32 && pal) {
                                        uint *bits32 = (uint *)dest->Bits;
                                        uchar idx = *cmd_ptr;
                                        bits32[(dest_row_offset >> 2) + curr_x] = 
                                            (pal[idx].peRed << 16) | (pal[idx].peGreen << 8) | pal[idx].peBlue;
                                    }
                                }
                                curr_x++;
                                cmd_ptr++;
                            }
                        } else {
                            curr_x += count;
                            cmd_ptr += count;
                        }
                        break;
                    case 0x03: // Copy long
                        count = ((cmd & 0xF0) << 4) | (*cmd_ptr++);
                        // Simplified loop for brevity, similar to case 0x02
                        for (int i = 0; i < count; i++) {
                            if (curr_x >= 0 && curr_x < dest->Width) {
                                if (bpp == 8) {
                                    dest->Bits[dest_row_offset + curr_x] = *cmd_ptr;
                                } else if (bpp == 32 && pal) {
                                    uint *bits32 = (uint *)dest->Bits;
                                    uchar idx = *cmd_ptr;
                                    bits32[(dest_row_offset >> 2) + curr_x] = 
                                        (pal[idx].peRed << 16) | (pal[idx].peGreen << 8) | pal[idx].peBlue;
                                }
                            }
                            curr_x++;
                            cmd_ptr++;
                        }
                        break;
                    case 0x06: // Player color (Shadow/Special)
                        count = cmd >> 2;
                        // Transform player color logic would go here
                        // For now, treat as skip/fill or copy depending on implementation
                        for (int i = 0; i < count; i++) {
                            if (curr_x >= 0 && curr_x < dest->Width) {
                                if (bpp == 8) dest->Bits[dest_row_offset + curr_x] = *cmd_ptr;
                            }
                            curr_x++;
                            cmd_ptr++;
                        }
                        break;
                    case 0x07: // Fill
                        count = cmd >> 2;
                        {
                            uchar color = *cmd_ptr++;
                            for (int i = 0; i < count; i++) {
                                if (curr_x >= 0 && curr_x < dest->Width) {
                                    if (bpp == 8) dest->Bits[dest_row_offset + curr_x] = color;
                                }
                                curr_x++;
                            }
                        }
                        break;
                    case 0x0F: // EOL
                        end_of_row = true;
                        break;
                    default: // Reserved/Error
                        end_of_row = true; 
                        break;
                }
            }
        }
    }
}