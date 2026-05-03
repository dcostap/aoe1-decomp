// VA: 00434290 do_command_stop (70 B)
// PDB source: Command.cpp lines 425-442
// 
// Blocker: VC5 register allocation for param_1 differs. Our compiler loads
// param_1 into eax before saving this (ecx→ebx), while the original saves
// this first, then reuses ecx for param_1. This cascades through 12 byte
// differences (eax↔ecx swap for param_1, edx↔eax in loop body, pop order).
// 
// Remaining differences (all register allocation):
//   1. Prologue: mov eax,[esp+4] (5B) vs push ebx; mov ebx,ecx; mov ecx,[esp+8] (original)
//      → Our compiler loads param_1 before saving this; original saves this first.
//   2. xor ecx,ecx; mov cl,[eax+1] vs xor eax,eax; mov al,[ecx+1] (register swap)
//   3. lea edi,[eax+2] vs lea edi,[ecx+2]
//   4. mov ebp,ecx vs mov ebp,eax (count init)
//   5. mov edx,[edi]; push edx vs mov eax,[edi]; push eax
//   6. mov eax,[esi]; ff 90 vs mov edx,[esi]; ff 92 (vtable call)
//   7. Pop order: esi,edi,ebp,ebx vs ebp,esi,edi,ebx
//   8. Extra nop padding (3 nops vs 0)
// 
// Everything else matches: loop structure (dec ebp; jne), null check,
// get_obj → removeAllFromPathingGroup → vtable[0xA4] call sequence,
// push esi inside loop guard, ret 4.

class RGE_Game_World;
class RGE_Player;

class RGE_Static_Object {
public:
    virtual void vf00() = 0;
    virtual void vf04() = 0;
    virtual void vf08() = 0;
    virtual void vf0C() = 0;
    virtual void vf10() = 0;
    virtual void vf14() = 0;
    virtual void vf18() = 0;
    virtual void vf1C() = 0;
    virtual void vf20() = 0;
    virtual void vf24() = 0;
    virtual void vf28() = 0;
    virtual void vf2C() = 0;
    virtual void vf30() = 0;
    virtual void vf34() = 0;
    virtual void vf38() = 0;
    virtual void vf3C() = 0;
    virtual void vf40() = 0;
    virtual void vf44() = 0;
    virtual void vf48() = 0;
    virtual void vf4C() = 0;
    virtual void vf50() = 0;
    virtual void vf54() = 0;
    virtual void vf58() = 0;
    virtual void vf5C() = 0;
    virtual void vf60() = 0;
    virtual void vf64() = 0;
    virtual void vf68() = 0;
    virtual void vf6C() = 0;
    virtual void vf70() = 0;
    virtual void vf74() = 0;
    virtual void vf78() = 0;
    virtual void vf7C() = 0;
    virtual void vf80() = 0;
    virtual void vf84() = 0;
    virtual void vf88() = 0;
    virtual void vf8C() = 0;
    virtual void vf90() = 0;
    virtual void vf94() = 0;
    virtual void vf98() = 0;
    virtual void vf9C() = 0;
    virtual void vfA0() = 0;
    virtual void stop() = 0;     // vt[41] = +0xA4

    int id;
    void* master_obj;
    RGE_Player* owner;

    void removeAllFromPathingGroup();
};

class RGE_Game_World {
public:
    RGE_Static_Object* object(int id);
};

class RGE_Command {
public:
    virtual void vf00() = 0;
    virtual ~RGE_Command() {}
    virtual void vf08() = 0;
    virtual void vf0C() = 0;

    RGE_Game_World* world;

    RGE_Static_Object* get_obj(int id);
    void do_command_stop(void* param_1);
};

void RGE_Command::do_command_stop(void* param_1) {
    int count;
    int* ids;
    RGE_Static_Object* obj;

    ids = (int*)((unsigned char*)param_1 + 2);
    if ((count = ((unsigned char*)param_1)[1]) <= 0) goto end;

    do {
        obj = get_obj(*ids);
        if (obj) {
            obj->removeAllFromPathingGroup();
            obj->stop();
        }
        ids++;
    } while (--count != 0);

end:
    ;
}
