// TRIBE_Scenario_Editor_Panel_Object::draw
// VA: 004BEE70
// PDB: spnl_obj.cpp:78-325
//
// First pass — basin classification
// Reuses class layout and GDI surface from draw_item

#include "../../include/game_globals.h"
#include <stdio.h>
#include <string.h>

typedef int (__stdcall *GDI_SetBkMode)(int, int);
typedef int (__stdcall *GDI_SetTextColor)(int, int);
typedef int (__stdcall *GDI_SelectClipRgn)(int, int);
typedef int (__stdcall *GDI_SelectObject)(int, int);
typedef int (__stdcall *GDI_TextOutA)(int, int, int, char*, int);

extern GDI_SetBkMode _SetBkMode;
extern GDI_SetTextColor _SetTextColor;
extern GDI_SelectClipRgn _SelectClipRgn;
extern GDI_SelectObject _SelectObject;
extern GDI_TextOutA _TextOutA;

class TDrawArea {
public:
    char* Lock(char* a, int b);
    void Unlock(char* a);
    void* GetDc(char* a);
    void ReleaseDc(char* a);
};

class TShape {
public:
    void shape_draw(void* draw_area, void* src_rect, void* dst_rect, int param, int zero1, int zero2);
};

// Extended class layout for draw function
class TRIBE_Scenario_Editor_Panel_Object {
public:
    virtual void d0();
    virtual void draw();
    virtual void d2(); virtual void d3(); virtual void d4();
    virtual void d5(); virtual void d6(); virtual void d7();
    virtual void d8(); virtual void d9(); virtual void d10();
    virtual void d11(); virtual void d12(); virtual void d13();
    virtual void d14(); virtual void d15(); virtual void d16();
    virtual void draw_item(int, int, int, int, int);

    char pad_04[8];
    void* base_info;       // +0x0C
    void* str_pos_info;    // +0x10
    char pad_14_1C[0x20 - 0x14];
    void* draw_area;       // +0x20
    char pad_24_38[0x38 - 0x24];
    int dc_handle;         // +0x38
    char pad_3C_40[0x40 - 0x3C];
    void* field_40;        // +0x40
    char pad_44_6C[0x6C - 0x44];
    int field_6C;          // +0x6C
    int field_70;          // +0x70
    char pad_74_88[0x88 - 0x74];
    int clip_region;       // +0x88
    char pad_8C_F4[0xF4 - 0x8C];
    int font_handle;       // +0xF4
    char pad_F8_104[0x104 - 0xF8];
    void* shape_ptr;       // +0x104
    void* field_108;       // +0x108
    void* field_10C;       // +0x10C
    void* field_110;       // +0x110
    void* field_114;       // +0x114
    char pad_118_120[0x120 - 0x118];
    unsigned char field_120; // +0x120
    char pad_121_214[0x214 - 0x121];
    void* field_214;       // +0x214
    void* field_218;       // +0x218
};

void TRIBE_Scenario_Editor_Panel_Object::draw()
{
    if (!this->draw_area || !this->field_70 || !this->field_6C)
        return;

    if (this->field_120 == 2) {
        void* vt = *(void**)this;
        ((void (__stdcall *)(TRIBE_Scenario_Editor_Panel_Object*))((void**)vt)[10])(this);
        return;
    }

    if (!this->field_214) {
        void* vt = *(void**)this;
        ((void (__stdcall *)(TRIBE_Scenario_Editor_Panel_Object*, void*))((void**)vt)[13])(this, &this->pad_24_38[-0x24 + 0x24]);
        this->dc_handle = 0;
        return;
    }

    void* vt = *(void**)this;
    ((void (__stdcall *)(TRIBE_Scenario_Editor_Panel_Object*))((void**)vt)[10])(this);

    ((TDrawArea*)this->draw_area)->Lock((char*)&this->pad_24_38[-0x24 + 0x24], 0);

    char* lock_result = ((TDrawArea*)this->draw_area)->Lock(0, 1);
    if (lock_result) {
        void* item = this->field_214;
        short item_id = *(short*)((char*)item + 0x4C);

        if (item_id != (short)-1) {
            // Shape drawing path
            ((TShape*)this->shape_ptr)->shape_draw(
                this->draw_area,
                (char*)this->base_info + 2,
                (char*)this->str_pos_info + 0x21,
                item_id, 0, 0);
        }

        ((TDrawArea*)this->draw_area)->Unlock(0);
    }

    // GDI text section
    void* dc = ((TDrawArea*)this->draw_area)->GetDc(0);
    if (dc) {
        _SetBkMode(*(int*)((char*)this->draw_area + 0x38), 1);
        _SetTextColor(*(int*)((char*)this->draw_area + 0x38), 0xFFFFFF);
        _SelectClipRgn(*(int*)((char*)this->draw_area + 0x38), this->clip_region);
        int old_font = _SelectObject(*(int*)((char*)this->draw_area + 0x38), this->font_handle);

        if (this->field_110) {
            // Draw resource/player name from vtable
            char buf[200];
            void* vt2 = *(void**)this;
            int pid = *(short*)((char*)this->field_110 + 0x4A);
            ((void (__stdcall *)(TRIBE_Scenario_Editor_Panel_Object*, int, char*, int))((void**)vt2)[10])(
                this, pid, buf, 100);

            int len = strlen(buf);
            if (len) {
                _TextOutA(*(int*)((char*)this->draw_area + 0x38),
                    (int)((char*)this->base_info + 2),
                    (int)((char*)this->str_pos_info + 0x0F),
                    buf, len);
            }

            // Second name string
            char buf2[100];
            buf2[0] = 0;
            int len2 = strlen(buf2);
            if (len2) {
                _TextOutA(*(int*)((char*)this->draw_area + 0x38),
                    (int)((char*)this->base_info + 2),
                    (int)((char*)this->str_pos_info + 0x0F),
                    buf2, len2);
            }
        }

        // Item description text
        {
            void* item = this->field_214;
            char desc_buf[200];
            short count = *(short*)((char*)item + 0x0C);
            if (count > 0) {
                void* vt2 = *(void**)this;
                ((void (__stdcall *)(TRIBE_Scenario_Editor_Panel_Object*, int, char*, int))((void**)vt2)[8])(
                    this, count, desc_buf, 100);
            } else {
                // Copy from item name
                char* src = (char*)item + 8;
                int slen = strlen(src);
                memcpy(desc_buf, src, slen + 1);
            }

            int dlen = strlen(desc_buf);
            if (dlen) {
                _TextOutA(*(int*)((char*)this->draw_area + 0x38),
                    (int)((char*)this->base_info + 2),
                    (int)((char*)this->str_pos_info + 0x0F),
                    desc_buf, dlen);
            }
        }

        _SelectObject(*(int*)((char*)this->draw_area + 0x38), old_font);
        _SelectClipRgn(*(int*)((char*)this->draw_area + 0x38), 0);
        ((TDrawArea*)this->draw_area)->ReleaseDc(0);
    }

    // Type dispatch for additional drawing
    if (dc) {
        unsigned char type = *(unsigned char*)((char*)this->field_214 + 0x8F);
        
        if (type == 1) {
            // Float comparison
            float* values = (float*)((char*)this->field_214 + 0x70);
            int idx = 0;
            for (int i = 0; i < 3; i++) {
                if (values[i] <= 1.0f) {
                    idx = i;
                    break;
                }
            }

            short sub_type = *(short*)((char*)this->field_214 + idx * 2 + 0x6A);
            int action = 3;
            if (sub_type == 2) action = 2;
            else if (sub_type == 0) action = 0;
            else if (sub_type == 1) action = 1;

            int val = (int)values[idx];
            void* vt2 = *(void**)this;
            ((void (__stdcall *)(TRIBE_Scenario_Editor_Panel_Object*, int, int, int, int))((void**)vt2)[0xE0/4])(
                this, 0, action, 0, val);
            ((void (__stdcall *)(TRIBE_Scenario_Editor_Panel_Object*))((void**)vt2)[0x2C/4])(this);
        }
        else if (type == 2) {
            // Direct draw with item fields
            short val1 = *(short*)((char*)this->field_214 + 0x13E);
            void* vt2 = *(void**)this;
            ((void (__stdcall *)(TRIBE_Scenario_Editor_Panel_Object*, int, int, int, int))((void**)vt2)[0xE0/4])(
                this, 0, 7, 1, val1);
            
            short val2 = *(short*)((char*)this->field_214 + 0x13C);
            ((void (__stdcall *)(TRIBE_Scenario_Editor_Panel_Object*, int, int, int, int))((void**)vt2)[0xE0/4])(
                this, 1, 8, 1, val2);
            
            float f3 = *(float*)((char*)this->field_214 + 0x114);
            ((void (__stdcall *)(TRIBE_Scenario_Editor_Panel_Object*, int, int, int, int))((void**)vt2)[0xE0/4])(
                this, 2, 6, 1, (int)f3);

            ((void (__stdcall *)(TRIBE_Scenario_Editor_Panel_Object*))((void**)vt2)[0x2C/4])(this);
        }
    }

    if (dc) {
        ((TDrawArea*)this->draw_area)->ReleaseDc(0);
    }
}
