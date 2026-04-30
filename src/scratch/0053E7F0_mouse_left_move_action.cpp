// 0053E7F0 RGE_Main_View::mouse_left_move_action
// vw_main.cpp:636-675, 249 bytes, __thiscall, ret 10h

extern "C" void* rge_base_game;  // 0x62C574

class RGE_Base_Game {
public:
    char gap_00[0x1B0];
    int field_1B0;      // +0x1B0 = prog_mode
    int field_1B4;      // +0x1B4 = game_mode
    
    int get_paused();   // at 0x00420180
};

class TPanel {
public:
    // vt[0..7] padding
    virtual void pad00() = 0;
    virtual void pad01() = 0;
    virtual void pad02() = 0;
    virtual void pad03() = 0;
    virtual void pad04() = 0;
    virtual void pad05() = 0;
    virtual void pad06() = 0;
    virtual void pad07() = 0;
    // vt[8] = +0x20
    virtual void redraw(int flags) = 0;
    
    char gap_04[0xB8];          // +0x04 to +0xBB
    char gap_BC[0x08];          // +0xBC to +0xC3
    int field_C4;               // +0x0C4
    int field_C8;               // +0x0C8
    char gap_CC[0x24];          // +0xCC to +0xEF
    int clip_to_parent;         // +0xF0 to +0xF3

    void release_mouse();       // at 0x00466280
};

class RGE_Main_View : public TPanel {
public:
    char gap_F4[0x74];          // +0xF4 to +0x167
    
    char byte_168;              // +0x168
    
    // vt[9..57] padding
    virtual void pad09() = 0;
    virtual void pad10() = 0;
    virtual void pad11() = 0;
    virtual void pad12() = 0;
    virtual void pad13() = 0;
    virtual void pad14() = 0;
    virtual void pad15() = 0;
    virtual void pad16() = 0;
    virtual void pad17() = 0;
    virtual void pad18() = 0;
    virtual void pad19() = 0;
    virtual void pad20() = 0;
    virtual void pad21() = 0;
    virtual void pad22() = 0;
    virtual void pad23() = 0;
    virtual void pad24() = 0;
    virtual void pad25() = 0;
    virtual void pad26() = 0;
    virtual void pad27() = 0;
    virtual void pad28() = 0;
    virtual void pad29() = 0;
    virtual void pad30() = 0;
    virtual void pad31() = 0;
    virtual void pad32() = 0;
    virtual void pad33() = 0;
    virtual void pad34() = 0;
    virtual void pad35() = 0;
    virtual void pad36() = 0;
    virtual void pad37() = 0;
    virtual void pad38() = 0;
    virtual void pad39() = 0;
    virtual void pad40() = 0;
    virtual void pad41() = 0;
    virtual void pad42() = 0;
    virtual void pad43() = 0;
    virtual void pad44() = 0;
    virtual void pad45() = 0;
    virtual void pad46() = 0;
    virtual void pad47() = 0;
    virtual void pad48() = 0;
    virtual void pad49() = 0;
    virtual void pad50() = 0;
    virtual void pad51() = 0;
    virtual void pad52() = 0;
    virtual void pad53() = 0;
    virtual void pad54() = 0;
    virtual void pad55() = 0;
    virtual void pad56() = 0;
    virtual void pad57() = 0;
    // vt[58] = +0xE8
    virtual void vmethod_E8(int p1, int p2, int p3, int p4, int p5) = 0;
    // vt[59] = +0xEC
    virtual void vmethod_EC(int p1, int p2) = 0;
    // vt[60] = +0xF0
    virtual void vmethod_F0() = 0;
    
    long mouse_left_move_action(long param_1, long param_2, int param_3, int param_4);
};

long RGE_Main_View::mouse_left_move_action(long param_1, long param_2, int param_3, int param_4) {
    // Use raw char* pointer arithmetic to prevent compiler from caching game ptr
    int pm = *(int*)(*(char**)rge_base_game + 0x1B0);
    
    if (pm == 4 || pm == 6 || pm == 7 || pm == 5) {
        // Use struct pointer for get_passed call (needs ECX = this)
        if (((RGE_Base_Game*)*(void**)rge_base_game)->get_paused() != 0) {
            if (this->byte_168 != 0) {
                this->vmethod_F0();
            } else {
                this->release_mouse();
            }
            return 0;
        }
        
        if (this->byte_168 != 0) {
            this->vmethod_EC(param_1, param_2);
            return 1;
        }
        
        // Use incompatible pointer type (char**) to force a fresh load
        // from the global, preventing compiler from reusing cached game ptr
        int gm = *(int*)(*(char**)rge_base_game + 0x1B4);
        switch (gm) {
        case 0:
            this->release_mouse();
            this->vmethod_E8(2, this->field_C4, this->field_C8, param_3, param_4);
            this->vmethod_EC(param_3, param_4);
            return 1;
        case 1:
        case 7:
        case 8:
            this->redraw(1);
            break;
        }
        return 1;
    }
    return 0;
}
