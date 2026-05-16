// VA: 00544090 RGE_Game_World::load_scenario
// Source: World.cpp lines 2393-2465
// 440 bytes, 149 asm
// __thiscall, returns unsigned char, param: RGE_Player_Info& (ret 4)
//
// STATUS: STUCK
// Attempts: 7
// Best result: 384/440 equal bytes (87.3%), 43.4% positional diff
// 
// What worked:
// - 31 dummy virtual functions align vtable to get correct offsets (0x7C-0xA8)
// - Field layout: gap_04[0xA0] accounts for implicit vtable pointer
// - `__fastcall` on campaign_open_scenario/setup_scenario_views for correct codegen
// - Absolute addr: ((RGE_Base_Game*)*(int*)0x62C574)->method()
// - goto-based control flow: shared virt_80 path, single fail+cleanup
//
// Remaining differences: All jump displacements (26 edit hunks). The code
// structure is correct but label placement differs by 1-2 bytes in various
// jump offsets. This is a cascading effect of slightly different function
// size (148 lines vs 150) shifting all branch targets.
//
// Not eligible for accepted_drift at 43% diff. Left in scratch.

#include <stdlib.h>

#define VER_1_01 (*(int*)0x58EE18)
#define VER_1_02 (*(int*)0x58EE10)
#define VER_1_03 (*(int*)0x57FB90)
#define VER_1_04 (*(int*)0x57FB88)
#define VER_1_05 (*(int*)0x57FB80)
#define VER_1_06 (*(int*)0x57FB78)
#define VER_1_07 (*(int*)0x57FB70)
#define VER_1_08 (*(int*)0x57FB68)
#define VER_1_09 (*(int*)0x57FB60)
#define VER_1_10 (*(int*)0x57FB50)
#define VER_1_11 (*(int*)0x57FB58)

void rge_close(int handle);
void* malloc(int size);
void free(void* ptr);
void rge_read_uncompressed(int handle, void* buf, int size);

class RGE_Base_Game {
public:
    int __fastcall campaign_open_scenario();
    void __fastcall setup_scenario_views(int* a4, int* a8, int* ac);
};

class RGE_Game_World {
public:
    // 31 dummy virtuals (vt[0..30] = offsets 0x00..0x78)
    virtual void stub_00();  virtual void stub_04();  virtual void stub_08();  virtual void stub_0C();
    virtual void stub_10();  virtual void stub_14();  virtual void stub_18();  virtual void stub_1C();
    virtual void stub_20();  virtual void stub_24();  virtual void stub_28();  virtual void stub_2C();
    virtual void stub_30();  virtual void stub_34();  virtual void stub_38();  virtual void stub_3C();
    virtual void stub_40();  virtual void stub_44();  virtual void stub_48();  virtual void stub_4C();
    virtual void stub_50();  virtual void stub_54();  virtual void stub_58();  virtual void stub_5C();
    virtual void stub_60();  virtual void stub_64();  virtual void stub_68();  virtual void stub_6C();
    virtual void stub_70();  virtual void stub_74();  virtual void stub_78();
    // Real methods at correct vtable offsets
    virtual void virt_7C(int a1, class RGE_Player_Info& a2);   // vt+0x7C
    virtual void virt_80(int a1, class RGE_Player_Info& a2);   // vt+0x80
    virtual void virt_84(int a1, class RGE_Player_Info& a2);   // vt+0x84
    virtual void virt_88(int a1, class RGE_Player_Info& a2);   // vt+0x88
    virtual void virt_8C(int a1, class RGE_Player_Info& a2);   // vt+0x8C
    virtual void virt_90(int a1, class RGE_Player_Info& a2);   // vt+0x90
    virtual void virt_94(int a1, class RGE_Player_Info& a2);   // vt+0x94
    virtual void virt_98(int a1, class RGE_Player_Info& a2);   // vt+0x98
    virtual void stub_9C();  virtual void stub_A0();  virtual void stub_A4();
    virtual void virt_A8(class RGE_Player_Info& a1);            // vt+0xA8
    virtual void stub_AC();

    // Fields (vtable ptr at +0x00 is implicit)
    char gap_04[0xA0];
    int field_A4;
    int field_A8;
    int field_AC;

    unsigned char load_scenario(class RGE_Player_Info& param_1);
};

unsigned char RGE_Game_World::load_scenario(class RGE_Player_Info& param_1)
{
    int header_size;
    int version;

    *(int*)0x886C10 = 0;

    int file_handle = ((RGE_Base_Game*)*(int*)0x62C574)->campaign_open_scenario();
    if (file_handle == -1) {
        goto cleanup;
    }

    rge_read_uncompressed(file_handle, &header_size, 4);

    if (header_size == VER_1_01) {
        this->virt_7C(file_handle, param_1);
        goto success_tail;
    }

    if (header_size == VER_1_02) {
        goto shared_80;
    }

    if (header_size == VER_1_03) {
        rge_read_uncompressed(file_handle, &version, 4);
        if (version > 0) {
            void* buf = malloc(version);
            if (buf != 0) {
                rge_read_uncompressed(file_handle, buf, version);
                free(buf);
            } else {
                goto fail;
            }
        }
        goto shared_80;
    }

    if (header_size == VER_1_04) {
        this->virt_84(file_handle, param_1);
        goto success_tail;
    }

    if (header_size == VER_1_05) {
        this->virt_88(file_handle, param_1);
        goto success_tail;
    }

    if (header_size == VER_1_06) {
        this->virt_8C(file_handle, param_1);
        goto success_tail;
    }

    if (header_size == VER_1_07) {
        this->virt_90(file_handle, param_1);
        goto success_tail;
    }

    if (header_size == VER_1_08) {
        this->virt_94(file_handle, param_1);
        goto success_tail;
    }

    if (header_size == VER_1_09 ||
        header_size == VER_1_10 ||
        header_size == VER_1_11) {
        this->virt_98(file_handle, param_1);
        goto success_tail;
    }

    goto fail;

shared_80:
    this->virt_80(file_handle, param_1);
    goto success_tail;

success_tail:
    this->virt_A8(param_1);
    ((RGE_Base_Game*)*(int*)0x62C574)->setup_scenario_views(&field_A4, &field_A8, &field_AC);
    return 1;

fail:
    rge_close(file_handle);
cleanup:
    return 0;
}
