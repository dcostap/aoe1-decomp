class UnitAIModule;
class RGE_Action_Object;

extern "C" UnitAIModule* __fastcall unitAI_004C7420(RGE_Action_Object* this_ptr);
extern "C" int __fastcall currentOrder_00413920(UnitAIModule* this_ptr);
extern "C" int __fastcall ready_to_attack_00401B30(void* this_ptr, void* unused, int* range_status);

static const double g_zero_double = 0.0;

class RGE_Action_Attack {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void first_in_stack(unsigned char param_1);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual void work(void);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void vf44(void);
    virtual void vf48(void);
    virtual void vf4C(void);
    virtual void vf50(void);
    virtual void vf54(void);
    virtual void vf58(void);
    virtual void set_state(unsigned char param_1);
};

__declspec(naked) void RGE_Action_Attack::first_in_stack(unsigned char param_1) {
    __asm {
        push ecx
        push esi
        mov esi, ecx

        mov ecx, [esi+8]
        mov eax, [ecx]
        call dword ptr [eax+0FCh]
        fcomp qword ptr [g_zero_double]
        fnstsw ax
        test ah, 40h
        jne ready_check

        mov ecx, [esi+8]
        call unitAI_004C7420
        test eax, eax
        jz set_state_4

        mov ecx, [esi+8]
        call unitAI_004C7420
        mov ecx, eax
        call currentOrder_00413920
        cmp eax, 2D5h
        je ready_check

set_state_4:
        mov edx, [esi]
        push 4
        mov ecx, esi
        call dword ptr [edx+5Ch]
        pop esi
        pop ecx
        ret 4

ready_check:
        lea eax, [esp+4]
        mov ecx, esi
        push eax
        mov dword ptr [esp+8], 0FFFFFFFFh
        call ready_to_attack_00401B30
        test eax, eax
        jne set_state_6
        cmp dword ptr [esp+4], 1
        je set_state_6

        mov eax, [esi]
        push 0Dh
        mov ecx, esi
        call dword ptr [eax+5Ch]
        pop esi
        pop ecx
        ret 4

set_state_6:
        mov edx, [esi]
        push 6
        mov ecx, esi
        call dword ptr [edx+5Ch]
        pop esi
        pop ecx
        ret 4
    }
}
// STATUS: blocked
// FLAGS: config\flags\004014B0_first_in_stack.rsp
// BLOCKER: Uses inline asm / naked-function codegen, which is now forbidden in this repo.
// NOTE: Demoted from src\matching after the policy change; replace with a source-level exact match.
