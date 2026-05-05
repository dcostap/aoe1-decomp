// VA: 004C9D20 TRIBE_Building_Object::empty_production_queue()
// PDB source: t_b_obj.cpp lines 1119-1131 (97 bytes, 23 asm lines)
// Default flags
//
// __thiscall: this in ecx, no stack params. void return (ret, not ret N).
//
// 96/97 bytes matching. Left in scratch.
//
// Difference: VC5 optimizes `arr[pid]--` to `dec dword [ecx+eax*4+0A34h]`
// (7 bytes) instead of the original's `lea eax,[edx+ecx*4+0A34h]; 
// mov ecx,[edx+ecx*4+0A34h]; dec ecx; mov [eax],ecx` (17 bytes).
// This is a stable VC5 version optimization — the newer compiler recognizes
// the read-modify-write pattern and uses the single-instruction form.
// Net effect: 10 bytes saved in the array access, 9 NOPs fill the gap,
// making the section 96 bytes vs the original 97.
//
// Everything else matches exactly:
// - push esi; mov esi, ecx prologue
// - mov ax, [esi+1DAh]; cmp ax, 0FFFFh; je skip for -1 check
// - cmp ax, 4; jne skip_attr for == 4 check
// - mov eax, [esi+0Ch] for owner_player access
// - movsx eax, word [eax+4Ah] for player_id sign extension
// - mov word [esi+1DAh], 0FFFFh for setting need_attr to -1
// - mov ecx, [esi+1D4h]; mov word [esi+1CEh], 0 for queue clear
// - call delete_list on production_queue_actions
// - mov al,[esi+1D8h]; inc al; mov [esi+1D8h],al for flag increment
// - pop esi; ret epilogue

struct TRIBE_Player {
    char gap_4A[0x4A];
    short player_id;
};

struct RGE_Action_List {
    void delete_list();
};

struct TRIBE_Building_Object {
    char gap_00[0x0C];
    TRIBE_Player* owner_player;                    // +0x0C
    char gap_10[0x1C8 - 0x10];
    void* production_queue;                        // +0x1C8
    short production_queue_gap;                    // +0x1CC
    short production_queue_count;                  // +0x1CE
    char gap_1D0[4];
    RGE_Action_List* production_queue_actions;      // +0x1D4
    unsigned char production_queue_change_flag;      // +0x1D8
    short production_queue_need_attr;              // +0x1DA

    void empty_production_queue();
};

extern void* rge_base_game;  // 0x62C574

void TRIBE_Building_Object::empty_production_queue() {
    short need_attr = this->production_queue_need_attr;
    if (need_attr != -1) {
        if (need_attr == 4) {
            void* game = rge_base_game;
            int pid = (int)(short)this->owner_player->player_id;
            int* val_p = (int*)((char*)game + pid * 4 + 0xA34);
            int old = *val_p;
            int result = old - 1;
            *val_p = result;
        }
        this->production_queue_need_attr = -1;
    }

    this->production_queue_count = 0;
    this->production_queue_actions->delete_list();
    this->production_queue_change_flag++;
}
