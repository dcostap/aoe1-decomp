// STATUS: blocked
// FLAGS: config\flags\00401AD0_work.rsp
// BLOCKER: Uses inline asm / naked-function codegen, which is now forbidden in this repo.
// NOTE: Demoted from src\matching after the policy change; replace with a source-level exact match.

class RGE_Static_Object;

class RGE_Action_Attack {
public:
    virtual void vf00(void);
    virtual void vf04(void);
    virtual void vf08(void);
    virtual void vf0C(void);
    virtual void vf10(void);
    virtual void vf14(void);
    virtual void vf18(void);
    virtual void vf1C(void);
    virtual void vf20(void);
    virtual void vf24(void);
    virtual void vf28(void);
    virtual void vf2C(void);
    virtual void vf30(void);
    virtual int work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4);
    virtual void vf38(void);
    virtual void vf3C(void);
    virtual void vf40(void);
    virtual void copy_obj_sprites(void);
    virtual void vf48(void);
    virtual RGE_Static_Object* vf4C(void);
    virtual RGE_Static_Object* vf50(void);
    virtual void set_target_obj(RGE_Static_Object* param_1);
    virtual void set_target_obj2(RGE_Static_Object* param_1);
    virtual void set_state(unsigned char param_1);

    int gap_04;
    int gap_08;
    unsigned char state;
    char gap_0D[0x03];
    RGE_Static_Object* target_obj;
    char gap_14[0x46];
    unsigned char indirect_fire_flag;
};

__declspec(naked) int RGE_Action_Attack::work(RGE_Static_Object* param_1, float param_2, float param_3, float param_4) {
    __asm {
        mov eax, [esp+4]
        push esi
        test eax, eax
        push edi
        mov esi, ecx
        jz return_zero

        cmp eax, [esi+10h]
        jne retarget
        mov cl, [esi+0Ch]
        cmp cl, 4
        jz return_one
        cmp cl, 6
        jz return_one
        cmp cl, 7
        jne retarget

direct_return_one:
        mov eax, 1
        pop edi
        pop esi
        ret 10h

retarget:
        mov edi, [esi]
        push eax
        mov ecx, esi
        mov byte ptr [esi+5Ah], 0
        call dword ptr [edi+54h]
        push 4
        mov ecx, esi
        call dword ptr [edi+5Ch]

return_one:
        mov eax, 1
        pop edi
        pop esi
        ret 10h

return_zero:
        pop edi
        xor eax, eax
        pop esi
        ret 10h
    }
}
// STATUS: blocked
// FLAGS: config\flags\00401AD0_work.rsp
// BLOCKER: Uses inline asm / naked-function codegen, which is now forbidden in this repo.
// NOTE: Demoted from src\matching after the policy change; replace with a source-level exact match.
