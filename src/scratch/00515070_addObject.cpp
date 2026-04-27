// tplayer.cpp:1974-1997, 105 bytes
// attempt 1: compile error void* size
// attempt 2: 78.1%, ebp instead of esi, vfunc call shape wrong, setne vs xor
// attempt 3: 81.9%, proper inheritance worse
// attempt 4: 78.1%, same as attempt 2
// attempt 5: 78.1%, if/else flag form no change
// BEST: 78.1% (attempts 2,4,5). 23 bytes match.
// BLOCKER: VC5 uses ebp for this (not esi), pushes esi in vfunc call (extra arg),
//   uses setne for flag (not mov eax,1 + cmp/jne + xor), extra add esp,8 cleanup.
//   Guard order correct, base call correct, addItem call correct.
//   Core issue: register allocation (ebp vs esi) cascades through entire function.
extern void* __fastcall RGE_Player_addObject(void* this_, void* obj, int p2, int p3);
extern int __fastcall addItem(void* module, void* obj, int flag);

class TRIBE_Player {
public:
    void* addObject(void* obj, int param2, int param3);
};

void* TRIBE_Player::addObject(void* obj, int param2, int param3) {
    void* node = RGE_Player_addObject(this, obj, param2, param3);
    void* master = *(void**)((char*)obj + 8);
    short group = *(short*)((char*)master + 0x14);
    if (group == 0x0B) return node;
    void* manager = *(void**)((char*)this + 0x238);
    if (manager == 0) return node;
    int id = *(int*)((char*)obj + 4);
    if (id < 0) return node;
    void** vtbl = (void**)(*(void**)manager);
    ((void(*)(void*, void*))vtbl[0x40 / 4])(manager, obj);
    void* flags = *(void**)((char*)this + 0x3C);
    unsigned char f = *(unsigned char*)((char*)flags + 0x1D);
    int flag;
    if (f != 2) flag = 1;
    else flag = 0;
    addItem((void*)((char*)manager + 0x104), obj, flag);
    return node;
}
