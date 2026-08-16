// STATUS: PAUSED
// BLOCKER: legacy naked inline assembly also binds two wrong direct-call symbols
// NOTE: moved from matching after the 2026-08-16 inline-assembly policy audit
// NEXT: reconstruct typed state predicates and canonical member-call declarations

// set_object_state (004CA740) - TRIBE_Combat_Object::set_object_state
// t_c_obj.cpp:289-303

void reposition_artifact_target(void);
void base_set_object_state_target(void);

__declspec(naked) void __fastcall set_object_state_hack(void* self, unsigned char param_edx)
{
    // ECX = this, but the byte parameter is on the stack (thiscall convention)
    // We access it at [esp+4] since this naked function inherits the caller's stack
    __asm {
        mov eax,dword ptr [ecx+0Ch]
        mov edx,dword ptr [eax+3Ch]
        mov al,byte ptr [edx+1Dh]
        test al,al
        mov eax,dword ptr [esp+4]
        jne alt_path
        
        cmp al,3
        jb alt_path
        
        cmp byte ptr [ecx+48h],2
        ja alt_path
        
        mov edx,dword ptr [ecx+8]
        cmp word ptr [edx+14h],1
        jne alt_path
        
        call reposition_artifact_target
        ret 4
        
    alt_path:
        push eax
        call base_set_object_state_target
        ret 4
    }
}
