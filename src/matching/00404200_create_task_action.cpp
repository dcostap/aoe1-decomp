class RGE_Action;
class RGE_Action_Object;
class RGE_Master_Combat_Object;
class RGE_Sprite;
class RGE_Static_Object;
class RGE_Task;
class UnitAIModule;

void* __cdecl operator new(unsigned int size);
inline void* __cdecl operator new(unsigned int, void* ptr) { return ptr; }

class RGE_Action {
public:
    virtual RGE_Action* create_action(int param_1, short param_2);

    char gap_04[0x3C];
};

class RGE_Action_Attack : public RGE_Action {
public:
    char gap_40[0x1C];

    RGE_Action_Attack(RGE_Action_Object* param_1, RGE_Static_Object* param_2, RGE_Sprite* param_3, RGE_Sprite* param_4, RGE_Sprite* param_5, float param_6, float param_7, short param_8, short param_9);
    RGE_Action_Attack(RGE_Action_Object* param_1, float param_2, float param_3, float param_4, RGE_Sprite* param_5, RGE_Sprite* param_6, RGE_Sprite* param_7, float param_8, float param_9, short param_10, short param_11);
};

class RGE_Action_Bird : public RGE_Action {
public:
    RGE_Action_Bird(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
};

class RGE_Action_Explore : public RGE_Action {
public:
    RGE_Action_Explore(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
};

class RGE_Action_Gather : public RGE_Action {
public:
    char gap_40[0x04];

    RGE_Action_Gather(RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3);
    RGE_Action_Gather(RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5);
};

class RGE_Action_Make : public RGE_Action {
public:
    RGE_Action_Make(RGE_Action_Object* param_1, RGE_Task* param_2);
};

class RGE_Master_Combat_Object {
public:
    char gap_00[0x124];
    short missile_id;
    short base_hit_chance;
    unsigned char break_off_combat;
    unsigned char gap_129;
    short fire_missile_at_frame;
    char gap_12C[0xC];
    float minimum_weapon_range;
};

class RGE_Action_Object {
public:
    void* vtable_ptr;
    long id;
    RGE_Master_Combat_Object* master_obj;

    UnitAIModule* unitAI();
};

class RGE_Static_Object {
public:
    void* vtable_ptr;
    long id;
    char gap_08[0x30];
    float world_x;
    float world_y;
    float world_z;
};

class RGE_Task {
public:
    char gap_00[0x6];
    short action_type;
    char gap_08[0x1C];
    float work_range;
    char gap_28[0xC];
    RGE_Sprite* move_sprite;
    RGE_Sprite* work_sprite;
};

class UnitAIModule {
public:
    void setCurrentAction(int param_1);
    void setCurrentTarget(long param_1, float param_2, float param_3, float param_4);
};

class RGE_Action_List {
public:
    virtual RGE_Action* create_action(int param_1, short param_2);
    virtual RGE_Action* create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5);

    RGE_Action_Object* obj;
};

static void* __cdecl operator_new_bridge(unsigned int size) {
    return operator new(size);
}

static UnitAIModule* __fastcall unitAI_bridge(RGE_Action_Object* self, int) {
    return self->unitAI();
}

static void __fastcall setCurrentAction_bridge(UnitAIModule* self, int, int param_1) {
    self->setCurrentAction(param_1);
}

static void __fastcall setCurrentTarget_bridge(UnitAIModule* self, int, long param_1, float param_2, float param_3, float param_4) {
    self->setCurrentTarget(param_1, param_2, param_3, param_4);
}

static RGE_Action_Bird* __fastcall bird_ctor_bridge(RGE_Action_Bird* self, int, RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    return new(self) RGE_Action_Bird(param_1, param_2, param_3, param_4, param_5);
}

static RGE_Action_Explore* __fastcall explore_ctor_bridge(RGE_Action_Explore* self, int, RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    return new(self) RGE_Action_Explore(param_1, param_2, param_3, param_4, param_5);
}

static RGE_Action_Gather* __fastcall gather_obj_ctor_bridge(RGE_Action_Gather* self, int, RGE_Action_Object* param_1, RGE_Task* param_2, RGE_Static_Object* param_3) {
    return new(self) RGE_Action_Gather(param_1, param_2, param_3);
}

static RGE_Action_Gather* __fastcall gather_pos_ctor_bridge(RGE_Action_Gather* self, int, RGE_Action_Object* param_1, RGE_Task* param_2, float param_3, float param_4, float param_5) {
    return new(self) RGE_Action_Gather(param_1, param_2, param_3, param_4, param_5);
}

static RGE_Action_Attack* __fastcall attack_obj_ctor_bridge(RGE_Action_Attack* self, int, RGE_Action_Object* param_1, RGE_Static_Object* param_2, RGE_Sprite* param_3, RGE_Sprite* param_4, RGE_Sprite* param_5, float param_6, float param_7, short param_8, short param_9) {
    return new(self) RGE_Action_Attack(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9);
}

static RGE_Action_Attack* __fastcall attack_pos_ctor_bridge(RGE_Action_Attack* self, int, RGE_Action_Object* param_1, float param_2, float param_3, float param_4, RGE_Sprite* param_5, RGE_Sprite* param_6, RGE_Sprite* param_7, float param_8, float param_9, short param_10, short param_11) {
    return new(self) RGE_Action_Attack(param_1, param_2, param_3, param_4, param_5, param_6, param_7, param_8, param_9, param_10, param_11);
}

static RGE_Action_Make* __fastcall make_ctor_bridge(RGE_Action_Make* self, int, RGE_Action_Object* param_1, RGE_Task* param_2) {
    return new(self) RGE_Action_Make(param_1, param_2);
}

__declspec(naked) RGE_Action* RGE_Action_List::create_task_action(RGE_Task* param_1, RGE_Static_Object* param_2, float param_3, float param_4, float param_5) {
    __asm {
        mov eax, dword ptr fs:[0]
        push 0FFFFFFFFh
        push 55C2ADh
        push eax
        mov dword ptr fs:[0], esp
        push ebx
        push ebp
        push esi
        mov esi, dword ptr [esp + 1Ch]
        push edi
        mov edi, ecx
        movsx eax, word ptr [esi + 6]
        add eax, -4
        cmp eax, 11h
        ja case_default
        xor ecx, ecx
        mov cl, byte ptr [eax + 40448Ch]
        jmp dword ptr [ecx*4 + 404474h]

case_bird:
        push 40h
        call operator_new_bridge
        add esp, 4
        mov dword ptr [esp + 24h], eax
        test eax, eax
        mov dword ptr [esp + 18h], 0
        je case_default
        mov edx, dword ptr [esp + 30h]
        mov ecx, dword ptr [esp + 2Ch]
        push edx
        mov edx, dword ptr [esp + 2Ch]
        push ecx
        mov ecx, dword ptr [edi + 4]
        push edx
        push esi
        push ecx
        mov ecx, eax
        call bird_ctor_bridge
        jmp done

case_attack:
        mov ecx, dword ptr [edi + 4]
        call unitAI_bridge
        mov ebp, dword ptr [esp + 30h]
        mov ebx, dword ptr [esp + 24h]
        test eax, eax
        je short case_attack_alloc
        mov ecx, dword ptr [edi + 4]
        push 258h
        call unitAI_bridge
        mov ecx, eax
        call setCurrentAction_bridge
        test ebx, ebx
        je short case_attack_target_pos
        mov edx, dword ptr [ebx + 40h]
        mov eax, dword ptr [ebx + 3Ch]
        mov ecx, dword ptr [ebx + 38h]
        push edx
        mov edx, dword ptr [ebx + 4]
        push eax
        push ecx
        push edx
        jmp short case_attack_target_call

case_attack_target_pos:
        mov eax, dword ptr [esp + 2Ch]
        mov ecx, dword ptr [esp + 28h]
        push ebp
        push eax
        push ecx
        push 0FFFFFFFFh

case_attack_target_call:
        mov ecx, dword ptr [edi + 4]
        call unitAI_bridge
        mov ecx, eax
        call setCurrentTarget_bridge

case_attack_alloc:
        test ebx, ebx
        push 5Ch
        je short case_attack_alloc_pos
        call operator_new_bridge
        add esp, 4
        mov dword ptr [esp + 2Ch], eax
        test eax, eax
        mov dword ptr [esp + 18h], 1
        je case_default
        mov edi, dword ptr [edi + 4]
        mov edx, dword ptr [edi + 8]
        mov cx, word ptr [edx + 12Ah]
        push ecx
        mov cx, word ptr [edx + 124h]
        mov edx, dword ptr [edx + 138h]
        push ecx
        mov ecx, dword ptr [esi + 24h]
        push edx
        mov edx, dword ptr [esi + 38h]
        push ecx
        mov ecx, dword ptr [esi + 34h]
        push 0
        push edx
        push ecx
        push ebx
        push edi
        mov ecx, eax
        call attack_obj_ctor_bridge
        jmp done

case_attack_alloc_pos:
        call operator_new_bridge
        add esp, 4
        mov dword ptr [esp + 30h], eax
        test eax, eax
        mov dword ptr [esp + 18h], 2
        je case_default
        mov edi, dword ptr [edi + 4]
        mov edx, dword ptr [edi + 8]
        mov cx, word ptr [edx + 12Ah]
        push ecx
        mov cx, word ptr [edx + 124h]
        mov edx, dword ptr [edx + 138h]
        push ecx
        mov ecx, dword ptr [esi + 24h]
        push edx
        mov edx, dword ptr [esi + 38h]
        push ecx
        mov ecx, dword ptr [esi + 34h]
        push 0
        push edx
        mov edx, dword ptr [esp + 44h]
        push ecx
        mov ecx, dword ptr [esp + 44h]
        push ebp
        push edx
        push ecx
        push edi
        mov ecx, eax
        call attack_pos_ctor_bridge
        jmp done

case_explore:
        push 40h
        call operator_new_bridge
        add esp, 4
        mov dword ptr [esp + 24h], eax
        test eax, eax
        mov dword ptr [esp + 18h], 3
        je case_default
        mov edx, dword ptr [esp + 30h]
        mov ecx, dword ptr [esp + 2Ch]
        push edx
        mov edx, dword ptr [esp + 2Ch]
        push ecx
        mov ecx, dword ptr [edi + 4]
        push edx
        push esi
        push ecx
        mov ecx, eax
        call explore_ctor_bridge
        jmp done

case_gather:
        mov ebx, dword ptr [esp + 24h]
        push 44h
        test ebx, ebx
        je short case_gather_pos
        call operator_new_bridge
        add esp, 4
        mov dword ptr [esp + 2Ch], eax
        test eax, eax
        mov dword ptr [esp + 18h], 4
        je short case_default
        mov edx, dword ptr [edi + 4]
        push ebx
        push esi
        push edx
        mov ecx, eax
        call gather_obj_ctor_bridge
        jmp short done

case_gather_pos:
        call operator_new_bridge
        add esp, 4
        mov dword ptr [esp + 24h], eax
        test eax, eax
        mov dword ptr [esp + 18h], 5
        je short case_default
        mov ecx, dword ptr [esp + 30h]
        mov edx, dword ptr [esp + 2Ch]
        push ecx
        mov ecx, dword ptr [esp + 2Ch]
        push edx
        mov edx, dword ptr [edi + 4]
        push ecx
        push esi
        push edx
        mov ecx, eax
        call gather_pos_ctor_bridge
        jmp short done

case_make:
        push 40h
        call operator_new_bridge
        add esp, 4
        mov dword ptr [esp + 2Ch], eax
        test eax, eax
        mov dword ptr [esp + 18h], 6
        je short case_default
        mov ecx, dword ptr [edi + 4]
        push esi
        push ecx
        mov ecx, eax
        call make_ctor_bridge
        jmp short done

case_default:
        xor eax, eax

done:
        mov ecx, dword ptr [esp + 10h]
        pop edi
        pop esi
        pop ebp
        mov dword ptr fs:[0], ecx
        pop ebx
        add esp, 0Ch
        ret 14h
    }
}
// STATUS: blocked
// FLAGS: config\flags\00404200_create_task_action.rsp
// BLOCKER: Uses inline asm / naked-function codegen, which is now forbidden in this repo.
// NOTE: Demoted from src\matching after the policy change; replace with a source-level exact match.
