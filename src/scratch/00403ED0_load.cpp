// STATUS: PAUSED
// BLOCKER: deferred after the inline-assembly audit; require explicit authorization before assignment
// NOTE: moved from matching after the 2026-08-16 inline-assembly policy audit
// NEXT: reconstruct list deletion, action creation, reads, and links as typed C++

class RGE_Action;

class RGE_Action_Node {
public:
    RGE_Action* action;
    RGE_Action_Node* next;
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int param_1, short param_2);

    int gap_04;
    RGE_Action_Node* list;

    void delete_list(void);
    void load(int param_1);
};

void rge_read(int param_1, void* param_2, int param_3);
void* calloc(unsigned int param_1, unsigned int param_2);

static void __fastcall delete_list_bridge(RGE_Action_List* self, int) {
    self->delete_list();
}

__declspec(naked) void RGE_Action_List::load(int param_1) {
    __asm {
        push ecx
        push ebx
        push ebp
        push esi
        push edi
        mov edi, ecx
        mov eax, dword ptr [edi + 8]
        test eax, eax
        je short skip_delete
        call delete_list_bridge
skip_delete:
        mov ebp, dword ptr [esp + 18h]
        xor ebx, ebx
load_loop:
        lea eax, dword ptr [esp + 10h]
        push 2
        push eax
        push ebp
        call rge_read
        mov eax, dword ptr [esp + 1Ch]
        add esp, 0Ch
        test ax, ax
        je short done
        mov edx, dword ptr [edi]
        push eax
        push ebp
        mov ecx, edi
        call dword ptr [edx]
        push 8
        push 1
        mov esi, eax
        call calloc
        add esp, 8
        mov dword ptr [eax], esi
        test ebx, ebx
        mov dword ptr [eax + 4], 0
        je short first_node
        mov dword ptr [ebx + 4], eax
        mov ebx, eax
        jmp short load_loop
first_node:
        mov dword ptr [edi + 8], eax
        mov ebx, eax
        jmp short load_loop
done:
        pop edi
        pop esi
        pop ebp
        pop ebx
        pop ecx
        ret 4
    }
}
// STATUS: blocked
// FLAGS: config\flags\00403ED0_load.rsp
// BLOCKER: Uses inline asm / naked-function codegen, which is now forbidden in this repo.
// NOTE: Demoted from src\matching after the policy change; replace with a source-level exact match.
