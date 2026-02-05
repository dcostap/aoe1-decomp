#include "../include/TShape.h"
#include "../include/Res_file.h"
#include "../include/custom_debug.h"
#include "../include/TDrawArea.h"
#include "../include/TDrawSystem.h"
#include <string.h>
#include <stdio.h>
#include <io.h>
#include <fcntl.h>

// External globals referenced in ASM
extern unsigned char shape_file_first;

// Constructor - implements ASM at 0x004B8B50
TShape::TShape(char* filename, int file_id) {
    // Initialize all members to zero/null (ASM lines 004b8b5e-004b8b6a)
    this->shape = nullptr;
    this->shape_header = nullptr;
    this->head = nullptr;
    this->offsets = nullptr;
    this->FShape = nullptr;
    this->shape_info = nullptr;
    this->load_type = -1;
    this->load_size = 0;

    // Check if we should try file first or go straight to resource (ASM 004b8b6d-004b8b80)
    if (!shape_file_first && file_id < 0) {
        // Neither file nor resource available, skip loading
        return;
    }

    // Try loading from file first (if shape_file_first is set)
    if (shape_file_first && filename && filename[0] != '\0') {
        char nextFile[260];
        
        // First try .SLP extension (ASM 004b8bb4-004b8c6e)
        strcpy(nextFile, filename);
        // Append .SLP if not already present
        size_t len = strlen(nextFile);
        if (len < 4 || _stricmp(nextFile + len - 4, ".slp") != 0) {
            strcat(nextFile, ".SLP");
        }
        
        int fHandle = _open(nextFile, _O_BINARY | _O_RDONLY);
        if (fHandle != -1) {
            // Get file size
            _lseek(fHandle, 0, SEEK_END);
            int fileSize = (int)_tell(fHandle);
            
            // Allocate and read file
            this->FShape = (SLhape_File_Header*)malloc(fileSize);
            if (this->FShape) {
                _lseek(fHandle, 0, SEEK_SET);
                _read(fHandle, this->FShape, fileSize);
                _close(fHandle);
                
                // Setup pointers (ASM 004b8c62-004b8c6e)
                this->load_type = 1;  // File-based load
                this->shape_info = (Shape_Info*)((unsigned char*)this->FShape + 0x20);
                this->load_size = fileSize;
                CUSTOM_DEBUG_LOG_FMT("TShape: Loaded %s from file, size=%d", nextFile, fileSize);
                return;  // Success
            }
            _close(fHandle);
        }
        
        // Try .SHP extension (ASM 004b8c71-004b8d20)
        strcpy(nextFile, filename);
        len = strlen(nextFile);
        if (len >= 4 && _stricmp(nextFile + len - 4, ".slp") == 0) {
            nextFile[len - 4] = '\0';
        }
        strcat(nextFile, ".SHP");
        
        fHandle = _open(nextFile, _O_BINARY | _O_RDONLY);
        if (fHandle != -1) {
            _lseek(fHandle, 0, SEEK_END);
            int fileSize = (int)_tell(fHandle);
            
            this->shape = (unsigned char*)malloc(fileSize);
            if (this->shape) {
                _lseek(fHandle, 0, SEEK_SET);
                _read(fHandle, this->shape, fileSize);
                _close(fHandle);
                
                // Setup pointers for SHP format (ASM 004b8d0e-004b8d20)
                this->head = (Shape_File_Header*)this->shape;
                this->offsets = (Shape_Offsets*)(this->shape + 8);
                this->load_type = 1;  // File-based load
                this->load_size = fileSize;
                CUSTOM_DEBUG_LOG_FMT("TShape: Loaded %s from file (SHP), size=%d", nextFile, fileSize);
                return;  // Success
            }
            _close(fHandle);
        }
    }
    
    // Try loading from resource files (ASM 004b8d39-004b8dbc)
    if (file_id >= 0) {
        int lType = 0;
        int lSize = 0;
        
        // Try 'shp ' type first (0x73687020) - ASM at 004b8d57-004b8d6a
        this->shape = RESFILE_load(0x73687020, file_id, &lSize, &lType);
        
        if (this->shape) {
            // Verify version "1.10" (ASM 004b8d71-004b8d7b)
            if (*(unsigned long*)this->shape == *(unsigned long*)"1.10") {
                this->head = (Shape_File_Header*)this->shape;
                this->offsets = (Shape_Offsets*)(this->shape + 8);
                this->load_type = lType;
                this->load_size = lSize;
                CUSTOM_DEBUG_LOG_FMT("TShape: Loaded id=%d from DRS (shp), size=%d", file_id, lSize);
                return;  // Success
            }
            // Version mismatch, try slp
            if (lType == 1) free(this->shape);
            this->shape = nullptr;
        }
        
        // Try 'slp ' type (0x736c7020) - ASM at 004b8d95-004b8db9
        unsigned char* slpData = RESFILE_load(0x736c7020, file_id, &lSize, &lType);
        if (slpData) {
            this->FShape = (SLhape_File_Header*)slpData;
            this->shape_info = (Shape_Info*)(slpData + 0x20);
            this->shape = nullptr;  // Not using old-style shape pointer
            this->load_type = lType;
            this->load_size = lSize;
            CUSTOM_DEBUG_LOG_FMT("TShape: Loaded id=%d from DRS (slp), size=%d", file_id, lSize);
            return;  // Success
        }
    }
    
    // Loading failed
    CUSTOM_DEBUG_LOG_FMT("TShape: Failed to load filename=%s, id=%d", filename ? filename : "(null)", file_id);
}

// Destructor - implements ASM at 0x004B8DD0
TShape::~TShape() {
    // Free FShape if allocated (ASM 004b8dd4-004b8e01)
    if (this->FShape) {
        if (this->load_type == 1) {
            // File-based, free the malloc'd buffer
            free(this->FShape);
        }
        // else: memory-mapped, don't free
    }
    
    // Free shape if allocated (ASM 004b8e01-004b8e2a)
    if (this->shape) {
        if (this->load_type == 1) {
            free(this->shape);
        }
    }
    
    // Clear all pointers
    this->shape = nullptr;
    this->shape_header = nullptr;
    this->head = nullptr;
    this->offsets = nullptr;
    this->FShape = nullptr;
    this->shape_info = nullptr;
}

// Check if shape file loaded successfully
int TShape::is_loaded() {
    // ASM at 004b8f90: return 1 if either shape or FShape is non-null
    if (this->shape != nullptr || this->FShape != nullptr) {
        return 1;
    }
    return 0;
}

// Get number of shapes in the shape file
long TShape::shape_count() {
    // ASM at 004b9040-004b9065
    if (this->FShape) {
        return this->FShape->Num_Shapes;
    }
    if (this->head) {
        return this->head->shape_num;
    }
    return 0;
}

void TShape::shape_minmax(long* x_min, long* y_min, long* x_max, long* y_max, int shape_idx) {
    // Best-effort implementation based on how `shape_draw` interprets SLP hotspots and dimensions.
    // Source-of-truth usage: `Panel_ez.cpp.decomp` / `Pnl_btn.cpp.decomp` call sites.
    //
    // ASSUMPTION: For SLP shapes, bounds are `[-Hotspot_X, -Hotspot_Y]` .. `[-Hotspot_X+Width-1, -Hotspot_Y+Height-1]`.
    if (x_min) *x_min = 0;
    if (y_min) *y_min = 0;
    if (x_max) *x_max = 0;
    if (y_max) *y_max = 0;

    if (!this->FShape || !this->shape_info) return;
    long count = this->shape_count();
    if (shape_idx < 0 || shape_idx >= count) return;

    Shape_Info* info = &this->shape_info[shape_idx];
    long xmin = -info->Hotspot_X;
    long ymin = -info->Hotspot_Y;
    long xmax = xmin + info->Width - 1;
    long ymax = ymin + info->Height - 1;

    if (x_min) *x_min = xmin;
    if (y_min) *y_min = ymin;
    if (x_max) *x_max = xmax;
    if (y_max) *y_max = ymax;
}

// Helper logic to validate shape index (ASM 0x004B8E40)
unsigned char TShape::Check_shape(long shape_idx, char* msg) {
    if (!this->shape && !this->FShape) {
        return 1; // Error
    }
    
    long num_shapes = this->shape_count();
    
    if (shape_idx < 0 || shape_idx >= num_shapes) {
        CUSTOM_DEBUG_LOG_FMT("Check_shape: Index out of bounds idx=%d count=%d msg=%s", 
            shape_idx, num_shapes, msg ? msg : "none");
        return 1; // Error
    }
    
    return 0; // Success
}

// Draw a shape (ASM 0x004B9440)
unsigned char TShape::shape_draw(TDrawArea* draw_area, long x, long y, long shape_idx, long param_5, unsigned char param_6, unsigned char* param_7) {
    if (this->Check_shape(shape_idx, "shape_draw")) {
        return 0; // Failure
    }
    
    // Get shape info
    if (!this->FShape || !this->shape_info) {
        CUSTOM_DEBUG_LOG("shape_draw: No FShape or shape_info");
        return 0;
    }
    
    Shape_Info* info = &this->shape_info[shape_idx];
    long width = info->Width;
    long height = info->Height;
    long x_origin = info->Hotspot_X;
    long y_origin = info->Hotspot_Y;
    
    // Adjust x,y by origin (SLP hotspots are offsets from top-left)
    long draw_x = x - x_origin;
    long draw_y = y - y_origin;
    
    if (!draw_area) {
        return 0;
    }
    
    // Lock the draw area surface, unless the caller already locked it.
    int locked_here = 0;
    uchar* dest_bits = draw_area->Bits;
    if (!dest_bits) {
        dest_bits = draw_area->Lock("shape_draw", 0);
        locked_here = 1;
    }
    if (!dest_bits) {
        CUSTOM_DEBUG_LOG("shape_draw: Failed to lock draw area");
        return 0;
    }
    long dest_pitch = draw_area->Pitch;
    int da_w = draw_area->Width;
    int da_h = draw_area->Height;
    int bytes_per_pixel = 1;
    if (da_w > 0 && dest_pitch > 0) {
        bytes_per_pixel = dest_pitch / da_w;
        if (bytes_per_pixel <= 0) bytes_per_pixel = 1;
    }
    tagPALETTEENTRY* pal = nullptr;
    if (draw_area->DrawSystem) {
        pal = draw_area->DrawSystem->palette;
    }

    // Clip rect is inclusive (matches `TDrawArea::SetClipRect` in `Drawarea.cpp.decomp`).
    long clip_l = draw_area->ClipRect.left;
    long clip_t = draw_area->ClipRect.top;
    long clip_r = draw_area->ClipRect.right;
    long clip_b = draw_area->ClipRect.bottom;
    if (clip_l < 0) clip_l = 0;
    if (clip_t < 0) clip_t = 0;
    if (clip_r >= da_w) clip_r = da_w - 1;
    if (clip_b >= da_h) clip_b = da_h - 1;

    unsigned char* slp_base = (unsigned char*)this->FShape;
    
    // Bounds check offsets with height awareness
    // row_offsets needs 4 bytes per row
    // outline needs 4 bytes per row (2 shorts)
    if (info->Shape_Data_Offsets + height * 4 > (unsigned long)this->load_size || 
        info->Shape_Outline_Offset + height * 4 > (unsigned long)this->load_size) {
         CUSTOM_DEBUG_LOG_FMT("shape_draw: invalid offsets/size data=0x%lx outline=0x%lx size=0x%x height=%ld", 
             info->Shape_Data_Offsets, info->Shape_Outline_Offset, this->load_size, height);
         if (locked_here) draw_area->Unlock("shape_draw");
         return 0;
    }

    unsigned long* row_offsets = (unsigned long*)(slp_base + info->Shape_Data_Offsets);
    unsigned short* outline = (unsigned short*)(slp_base + info->Shape_Outline_Offset);
    unsigned char* xlate = param_7;

    for (long row = 0; row < height; row++) {
        long dst_y = draw_y + row;
        if (dst_y < 0 || dst_y >= da_h) {
            continue;
        }
        if (dst_y < clip_t || dst_y > clip_b) {
            continue;
        }

        unsigned short left = outline[row * 2 + 0];
        if (left & 0x8000) {
            continue;
        }

        unsigned short right = outline[row * 2 + 1];

        left = (unsigned short)(left & 0x7FFF);
        right = (unsigned short)(right & 0x7FFF);

        unsigned long row_off = row_offsets[row];
        if (row_off >= (unsigned long)this->load_size) {
             CUSTOM_DEBUG_LOG_FMT("shape_draw: invalid row_off 0x%lx at row %ld", row_off, row);
             continue; // Skip invalid row
        }
        unsigned char* src = slp_base + row_off;

        long dst_x = draw_x + (long)left;
        long max_x = draw_x + width - 1 - (long)right;
        uchar* dst_row = dest_bits + dst_y * dest_pitch;
        unsigned long* dst_row32 = (unsigned long*)dst_row;
        static int shape_draw_log_once = 0;
        if (shape_draw_log_once == 0 && row == 0) {
            CUSTOM_DEBUG_LOG_FMT("shape_draw bounds: idx=%ld w=%ld h=%ld left=%u right=%u dst_x=%ld max_x=%ld span=%ld", shape_idx, width, height, (unsigned int)left, (unsigned int)right, dst_x, max_x, (max_x - dst_x + 1));
            shape_draw_log_once = 1;
        }

        unsigned char* shape_end = slp_base + this->load_size;
        
        for (;;) {
            if (src >= shape_end) {
                CUSTOM_DEBUG_LOG_FMT("shape_draw: src buffer overrun at row %ld", row);
                break;
            }
            unsigned char cmd = *src++;
            unsigned char op = (unsigned char)(cmd & 0x0F);

            if (op == 0x0F) {
                break;
            }

            if (dst_x > max_x) {
                // Skip remaining bytes for this row if we passed max_x? 
                // ASM logic usually keeps processing commands to maintain src pointer sync, 
                // but if we are crashing, maybe just break.
                // However, breaking here desyncs src for next ops in same row (which shouldn't happen if data is valid).
                // Let's just break for safety.
                break;
            }

            if (op == 0x02) {
                if (src >= shape_end) break;
                unsigned int len = (unsigned int)(((cmd & 0xF0) << 4) | (*src++));
                unsigned int to_copy = len;
                if (dst_x + (long)to_copy - 1 > max_x) {
                    to_copy = (unsigned int)(max_x - dst_x + 1);
                }
                
                if (src + to_copy > shape_end) {
                     CUSTOM_DEBUG_LOG("shape_draw: src buffer overrun in op 0x02");
                     break; 
                }

                for (unsigned int i = 0; i < to_copy; i++) {
                    unsigned char px = *src++;
                    unsigned char idx = xlate ? xlate[px] : px;
                    if (dst_x >= clip_l && dst_x <= clip_r) {
                        if (bytes_per_pixel == 4 && pal) {
                            tagPALETTEENTRY pe = pal[idx];
                            unsigned int rgb = (unsigned int)((pe.peRed << 16) | (pe.peGreen << 8) | pe.peBlue);
                            if (rgb == 0 && idx != 0 && pe.peRed == 0 && pe.peGreen == 0 && pe.peBlue == 0) {
                                rgb = (unsigned int)((idx << 16) | (idx << 8) | idx);
                            }
                            dst_row32[dst_x] = (unsigned long)rgb;
                        } else {
                            dst_row[dst_x] = idx;
                        }
                    }
                    dst_x++;
                }
                // Skip source bytes we didn't copy if clipped
                if (to_copy < len) {
                    unsigned int skip = len - to_copy;
                    if (src + skip > shape_end) break;
                    src += skip;
                }
                continue;
            }

            if (op == 0x03) {
                if (src >= shape_end) break;
                unsigned int len = (unsigned int)(((cmd & 0xF0) << 4) | (*src++));
                dst_x += (long)len;
                continue;
            }

            if (op == 0x07) {
                unsigned int len = (unsigned int)(cmd >> 4);
                if (len == 0) {
                    if (src >= shape_end) break;
                    len = (unsigned int)(*src++);
                }
                if (src >= shape_end) break;
                unsigned char px = *src++;
                unsigned char out_px = xlate ? xlate[px] : px;
                unsigned int to_write = len;
                if (dst_x + (long)to_write - 1 > max_x) {
                    to_write = (unsigned int)(max_x - dst_x + 1);
                }
                for (unsigned int i = 0; i < to_write; i++) {
                    if (dst_x >= clip_l && dst_x <= clip_r) {
                        if (bytes_per_pixel == 4 && pal) {
                            tagPALETTEENTRY pe = pal[out_px];
                            unsigned int rgb = (unsigned int)((pe.peRed << 16) | (pe.peGreen << 8) | pe.peBlue);
                            if (rgb == 0 && out_px != 0 && pe.peRed == 0 && pe.peGreen == 0 && pe.peBlue == 0) {
                                rgb = (unsigned int)((out_px << 16) | (out_px << 8) | out_px);
                            }
                            dst_row32[dst_x] = (unsigned long)rgb;
                        } else {
                            dst_row[dst_x] = out_px;
                        }
                    }
                    dst_x++;
                }
                continue;
            }

            if (op == 0x06 || op == 0x0B || op == 0x0E) {
                unsigned int len = (unsigned int)(cmd >> 4);
                if (len == 0) {
                    if (src >= shape_end) break;
                    len = (unsigned int)(*src++);
                }
                unsigned int to_copy = len;
                if (dst_x + (long)to_copy - 1 > max_x) {
                    to_copy = (unsigned int)(max_x - dst_x + 1);
                }
                
                if (src + to_copy > shape_end) break;

                for (unsigned int i = 0; i < to_copy; i++) {
                    unsigned char px = *src++;
                    unsigned char idx = xlate ? xlate[px] : px;
                    if (dst_x >= clip_l && dst_x <= clip_r) {
                        if (bytes_per_pixel == 4 && pal) {
                            tagPALETTEENTRY pe = pal[idx];
                            unsigned int rgb = (unsigned int)((pe.peRed << 16) | (pe.peGreen << 8) | pe.peBlue);
                            if (rgb == 0 && idx != 0 && pe.peRed == 0 && pe.peGreen == 0 && pe.peBlue == 0) {
                                rgb = (unsigned int)((idx << 16) | (idx << 8) | idx);
                            }
                            dst_row32[dst_x] = (unsigned long)rgb;
                        } else {
                            dst_row[dst_x] = idx;
                        }
                    }
                    dst_x++;
                }
                if (to_copy < len) {
                    unsigned int skip = len - to_copy;
                    if (src + skip > shape_end) break;
                    src += skip;
                }
                continue;
            }

            if (op == 0x0A) {
                unsigned int len = (unsigned int)(cmd >> 4);
                if (len == 0) {
                    if (src >= shape_end) break;
                    len = (unsigned int)(*src++);
                }
                if (src + 2 > shape_end) break;
                unsigned char px0 = *src++;
                unsigned char px1 = *src++;
                unsigned char out0 = xlate ? xlate[px0] : px0;
                unsigned char out1 = xlate ? xlate[px1] : px1;
                unsigned int to_write = len;
                if (dst_x + (long)to_write - 1 > max_x) {
                    to_write = (unsigned int)(max_x - dst_x + 1);
                }
                for (unsigned int i = 0; i < to_write; i++) {
                    unsigned char out_px = (i & 1) ? out1 : out0;
                    if (dst_x >= clip_l && dst_x <= clip_r) {
                        if (bytes_per_pixel == 4 && pal) {
                            tagPALETTEENTRY pe = pal[out_px];
                            unsigned int rgb = (unsigned int)((pe.peRed << 16) | (pe.peGreen << 8) | pe.peBlue);
                            if (rgb == 0 && out_px != 0 && pe.peRed == 0 && pe.peGreen == 0 && pe.peBlue == 0) {
                                rgb = (unsigned int)((out_px << 16) | (out_px << 8) | out_px);
                            }
                            dst_row32[dst_x] = (unsigned long)rgb;
                        } else {
                            dst_row[dst_x] = out_px;
                        }
                    }
                    dst_x++;
                }
                continue;
            }

            if ((op & 0x03) == 0x00) {
                unsigned int len = (unsigned int)(cmd >> 2);
                unsigned int to_copy = len;
                if (dst_x + (long)to_copy - 1 > max_x) {
                    to_copy = (unsigned int)(max_x - dst_x + 1);
                }
                
                if (src + to_copy > shape_end) break;

                for (unsigned int i = 0; i < to_copy; i++) {
                    unsigned char px = *src++;
                    unsigned char idx = xlate ? xlate[px] : px;
                    if (dst_x >= clip_l && dst_x <= clip_r) {
                        if (bytes_per_pixel == 4 && pal) {
                            tagPALETTEENTRY pe = pal[idx];
                            unsigned int rgb = (unsigned int)((pe.peRed << 16) | (pe.peGreen << 8) | pe.peBlue);
                            if (rgb == 0 && idx != 0 && pe.peRed == 0 && pe.peGreen == 0 && pe.peBlue == 0) {
                                rgb = (unsigned int)((idx << 16) | (idx << 8) | idx);
                            }
                            dst_row32[dst_x] = (unsigned long)rgb;
                        } else {
                            dst_row[dst_x] = idx;
                        }
                    }
                    dst_x++;
                }
                if (to_copy < len) {
                    unsigned int skip = len - to_copy;
                    if (src + skip > shape_end) break;
                    src += skip;
                }
                continue;
            }

            if ((op & 0x03) == 0x01) {
                unsigned int len = (unsigned int)(cmd >> 2);
                dst_x += (long)len;
                continue;
            }

            static int shape_draw_unknown_once = 0;
            if (shape_draw_unknown_once == 0) {
                CUSTOM_DEBUG_LOG_FMT("shape_draw unknown: idx=%ld row=%ld cmd=0x%02X op=0x%X dst_x=%ld", shape_idx, row, (unsigned int)cmd, (unsigned int)op, dst_x);
                shape_draw_unknown_once = 1;
            }

            break;
        }
    }

    if (locked_here) draw_area->Unlock("shape_draw");
    return 1; // Success
}
