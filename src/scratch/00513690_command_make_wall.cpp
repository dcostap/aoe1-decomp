// VA: 00513690 TRIBE_Player::command_make_wall
// PDB: tplayer.cpp lines 1140-1156 (143 bytes, 59 asm lines)
// Default flags: /nologo /c /O2 /Oy
//
// Attempt log (10 attempts):
//
// Attempt 9 was best: 30.77% edit diff, 113/143 bytes matching (79.0%).
// Prologue pushes all 3 registers first (push ecx; push esi; push edi) ✓
// VTable call matches exactly (mov [esi+24h]; mov [ecx+1D8h]; mov edx,[ecx]; call [edx+2Ch]) ✓
// All field offsets verified from inventory types (RGE_Player at +0x24, +0x3C) ✓
// get_selected_objects_to_command call sequence matches ✓
//
// Remaining differences (all register-allocation / instruction-encoding):
//
// Issue 1 — param_1 load:
//   Original: `mov edi,[esp+10h]` (DWORD load, 4B) + `movsx eax,di` (4B) = 8B
//   Rebuilt:  `movsx edi,word [esp+10h]` (sign-extending word load, 5B) = 5B
//   VC5 merges the load+sign-extend into one instruction when p1 is int.
//   Net: 3 bytes shorter, 5 bytes difference.
//
// Issue 2 — master_objects register:
//   Original: ecx = [esi+24h]; eax = [ecx+eax*4]
//   Rebuilt:  eax = [esi+24h]; eax = [eax+edi*4]
//   Different register selection for base pointer.
//
// Issue 3 — get_selected_objects LEA registers:
//   Original: lea edx,[esp+14h]; lea eax,[esp+20h]; push edx; push eax
//   Rebuilt:  lea ecx,[esp+14h]; lea edx,[esp+20h]; push ecx; push edx
//   Different register choice (ecx/edx swapped).
//
// Issue 4 — sVar2 (original param_1) in command_build_wall args:
//   Original: `push edi` (edi holds DWORD param_1, no sign-extend)
//   Rebuilt:  `movsx edx,word [esp+1Ch]` (sign-extend short, then push edx)
//   From using `param_1` directly (short) in the argument list.
//   Using `(int)p1` in the call would need p1 preserved differently.
//
// Issue 5 — Branch displacements differ by 6 bytes (77 vs 71, 70 vs 6a, 53 vs 4d)
//   due to 2-byte total size difference (143 vs 141) shifting jump targets.
//
// Not suitable for accepted_drift — remaining structural diff in register
// allocation and instruction encoding is systematic across the function,
// not localized.
//
// Left in scratch: best result with int p1 = param_1; (attempt 9).
// Retry 2026-05-19 Boss pass: 10 additional variants (dword alias for param_1 to force mov edi+dword, masters local/no local, real TRIBE_Command member thiscall, int vs short original_param, flag local, list_num local, raw thiscall pointer). Best new edit diff was 18.8811% but still broad register/argument scheduling mismatch; most dword-alias variants worsened first mismatch to offset 1 by perturbing prologue. Restored prior exact-size best.
// Retry 2026-05-20: 12 more probes. Kept real TRIBE_Command member call because it fixes the no-add-esp command_build_wall shape and improves edit diff to 18.8811%, but positional remains 70.6294% from early register/encoding drift. Tried int formal, short casts, raw indexed load, register p1, frame struct, dword alias, p1 short/no-p1; no exact. int formal gives very high byte equality but wrong prologue/order and non-original signature surface, so not kept.
// GIVEUP: remaining mismatch is not accepted_drift-worthy: VC5 chooses merged `movsx edi,word [esp+10h]` and EAX master_objects base instead of original dword param load to EDI plus `movsx eax,di` and ECX base; LEA register choices also differ. Later call bodies are close with real member call, but drift is systematic register-allocation/instruction encoding across setup and arguments.

#include <stddef.h>
#include <stdlib.h>
extern "C" void __cdecl free(void*);
class RGE_Master_Static_Object; class RGE_Game_World; class RGE_Static_Object; class TRIBE_Command { public: void command_build_wall(RGE_Static_Object** objects, short list_count, short original_param, long p2,long p3,long p4,long p5); };
class RGE_Player { public: void* vtable_ptr; int a,b,c,d; long e,f,g; unsigned char h; unsigned char pad; short master_object_num; RGE_Master_Static_Object** master_objects; char gap_28[0x14]; RGE_Game_World* world; unsigned char get_selected_objects_to_command(RGE_Static_Object***, short*, int,int,int,int); };
class TRIBE_Player: public RGE_Player { public: unsigned char command_make_wall(short,long,long,long,long); };
class __declspec(novtable) WallHelper { public: virtual void v0()=0; virtual void v1()=0; virtual void v2()=0; virtual void v3()=0; virtual void v4()=0; virtual void v5()=0; virtual void v6()=0; virtual void v7()=0; virtual void v8()=0; virtual void v9()=0; virtual void v10()=0; virtual void clear_wall_data()=0; };
unsigned char TRIBE_Player::command_make_wall(short param_1,long param_2,long param_3,long param_4,long param_5)
{
    short list_num;
    int p1 = param_1;
    RGE_Master_Static_Object* obj = this->master_objects[p1];
    if (obj && *(char*)((char*)obj + 0x52)) {
        void* local_4;
        if (this->get_selected_objects_to_command((RGE_Static_Object***)&param_1, (short*)&local_4, 4, 4, -1, -1)) {
            WallHelper* helper = *(WallHelper**)((char*)this->master_objects + 0x1D8);
            helper->clear_wall_data();
            TRIBE_Command* cmd = *(TRIBE_Command**)((char*)this->world + 0x58);
            cmd->command_build_wall((RGE_Static_Object**)(long)param_1, *(short*)&local_4, (short)p1, param_2,param_3,param_4,param_5);
            free((void*)(long)param_1);
            return 1;
        }
    }
    return 0;
}
