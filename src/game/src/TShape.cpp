#include "../include/TShape.h"
#include "../include/Res_file.h"
#include "../include/custom_debug.h"
#include "../include/TDrawArea.h"
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
    
    // For now, implement a PLACEHOLDER draw routine
    // Real implementation requires complex assembly for SLP decompression and clipping
    
    // Calculate simple bounds if possible
    int width = 20;
    int height = 20;
    int x_origin = 10;
    int y_origin = 10;
    
    if (this->FShape && this->shape_info) {
        // SLP format
        Shape_Info* info = &this->shape_info[shape_idx];
        width = info->Width;
        height = info->Height;
        x_origin = info->Hotspot_X;
        y_origin = info->Hotspot_Y;
    } 
    
    // Adjust x,y by origin (SLP hotspots are offsets from top-left)
    int draw_x = (int)x - x_origin;
    int draw_y = (int)y - y_origin;
    
    if (draw_area) {
        // Draw a colored rectangle representing the sprite
        // Use a color that stands out but varies by shape index to distinguish them
        unsigned char color = (unsigned char)(240 + (shape_idx % 16)); 
        
        // Debug logging for the first few draws
        static int log_count = 0;
        if (log_count < 5) {
            CUSTOM_DEBUG_LOG_FMT("shape_draw: x=%d y=%d w=%d h=%d idx=%d", draw_x, draw_y, width, height, (int)shape_idx);
            log_count++;
        }

        draw_area->FillRect(draw_x, draw_y, draw_x + width, draw_y + height, color);
    }
    
    return 1; // Success
}
