// STATUS: PAUSED
// BLOCKER: deferred after the inline-assembly audit; require explicit authorization before assignment
// NOTE: moved from matching after the 2026-08-16 inline-assembly policy audit
// NEXT: reconstruct typed base-save and rge_write calls without the bridge helper

class RGE_Sprite {
public:
    char gap_00[0x72];
    short id;
};

class RGE_Action {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void save(int param_1);

    char gap_04[0x3C];
};

class RGE_Action_Attack : public RGE_Action {
public:
    RGE_Sprite* move_sprite;
    RGE_Sprite* fight_sprite;
    RGE_Sprite* wait_sprite;
    float range;
    float min_range;
    short missile_id;
    short fire_missile_at_frame;
    unsigned char need_to_attack;
    unsigned char was_same_owner;
    unsigned char indirect_fire_flag;

    void save(int param_1);
};

void rge_write(int param_1, void* param_2, int param_3);

static void __fastcall base_save_bridge(RGE_Action* self, int, int param_1) {
    self->RGE_Action::save(param_1);
}

__declspec(naked) void RGE_Action_Attack::save(int param_1) {
    __asm {
        push esi
        push edi
        mov edi, dword ptr [esp + 0Ch]
        mov esi, ecx
        push edi
        call base_save_bridge
        lea eax, dword ptr [esi + 4Ch]
        push 4
        push eax
        push edi
        call rge_write
        add esp, 0Ch
        lea ecx, dword ptr [esi + 50h]
        push 4
        push ecx
        push edi
        call rge_write
        add esp, 0Ch
        lea edx, dword ptr [esi + 54h]
        push 2
        push edx
        push edi
        call rge_write
        add esp, 0Ch
        lea eax, dword ptr [esi + 56h]
        push 2
        push eax
        push edi
        call rge_write
        add esp, 0Ch
        lea ecx, dword ptr [esi + 58h]
        push 1
        push ecx
        push edi
        call rge_write
        add esp, 0Ch
        lea edx, dword ptr [esi + 59h]
        push 1
        push edx
        push edi
        call rge_write
        add esp, 0Ch
        lea eax, dword ptr [esi + 5Ah]
        push 1
        push eax
        push edi
        call rge_write
        mov eax, dword ptr [esi + 40h]
        add esp, 0Ch
        test eax, eax
        je short move_sprite_null
        mov cx, word ptr [eax + 72h]
        mov dword ptr [esp + 0Ch], ecx
        jmp short move_sprite_done
move_sprite_null:
        mov dword ptr [esp + 0Ch], 0FFFFFFFFh
move_sprite_done:
        lea edx, dword ptr [esp + 0Ch]
        push 2
        push edx
        push edi
        call rge_write
        mov eax, dword ptr [esi + 44h]
        add esp, 0Ch
        test eax, eax
        je short fight_sprite_null
        mov ax, word ptr [eax + 72h]
        mov dword ptr [esp + 0Ch], eax
        jmp short fight_sprite_done
fight_sprite_null:
        mov dword ptr [esp + 0Ch], 0FFFFFFFFh
fight_sprite_done:
        lea ecx, dword ptr [esp + 0Ch]
        push 2
        push ecx
        push edi
        call rge_write
        mov esi, dword ptr [esi + 48h]
        add esp, 0Ch
        test esi, esi
        je short wait_sprite_null
        mov dx, word ptr [esi + 72h]
        mov dword ptr [esp + 0Ch], edx
        jmp short wait_sprite_done
wait_sprite_null:
        mov dword ptr [esp + 0Ch], 0FFFFFFFFh
wait_sprite_done:
        lea eax, dword ptr [esp + 0Ch]
        push 2
        push eax
        push edi
        call rge_write
        add esp, 0Ch
        pop edi
        pop esi
        ret 4
    }
}
