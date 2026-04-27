// VA: 004AF320 TRIBE_Screen_Sed_Edit::init_module_variables (925 B)
// PDB source: scr_sed2.cpp
// Packet-grounded: zero-init scenario editor module variables

void TRIBE_Screen_Sed_Edit_init_module_variables(void* self)
{
    int i;
    
    // Zero out many fields (offset range 0x4C4 - 0x6BC)
    *(int*)((char*)self + 0x4C4) = 0;
    *(int*)((char*)self + 0x4C8) = 0;
    *(int*)((char*)self + 0x4CC) = 0;
    *(int*)((char*)self + 0x4D0) = 0;
    *(int*)((char*)self + 0x4D4) = 0;
    
    // Zero-init 10 dwords starting at 0x4D8
    for (i = 0; i < 10; i++)
        *(int*)((char*)self + 0x4D8 + i * 4) = 0;
    
    *(int*)((char*)self + 0x47C) = 0;
    *(int*)((char*)self + 0x500) = 0;
    *(int*)((char*)self + 0x504) = 0;
    *(int*)((char*)self + 0x520) = 0;
    
    // Zero-init 3 dwords each at 0x508, 0x514, 0x520
    for (i = 0; i < 3; i++) {
        *(int*)((char*)self + 0x508 + i * 4) = 0;
        *(int*)((char*)self + 0x514 + i * 4) = 0;
        *(int*)((char*)self + 0x520 + i * 4) = 0;
    }
    
    *(int*)((char*)self + 0x528) = 0;
    *(int*)((char*)self + 0x524) = 0;
    *(int*)((char*)self + 0x530) = 0;
    *(int*)((char*)self + 0x52C) = 0;
    *(int*)((char*)self + 0x538) = 0;
    *(int*)((char*)self + 0x534) = 0;
    *(int*)((char*)self + 0x550) = 0;
    *(int*)((char*)self + 0x53C) = 0;
    *(int*)((char*)self + 0x540) = 0;
    *(int*)((char*)self + 0x544) = 0;
    *(int*)((char*)self + 0x548) = 0;
    *(int*)((char*)self + 0x54C) = 0;
    *(int*)((char*)self + 0x554) = 0;
    *(int*)((char*)self + 0x580) = 0;
    *(int*)((char*)self + 0x59C) = 0;
    
    // Zero-init 5 dwords at 0x558, 0x56C
    for (i = 0; i < 5; i++) {
        *(int*)((char*)self + 0x558 + i * 4) = 0;
        *(int*)((char*)self + 0x56C + i * 4) = 0;
    }
    
    // Zero-init 3 dwords at 0x584, 0x590
    for (i = 0; i < 3; i++) {
        *(int*)((char*)self + 0x584 + i * 4) = 0;
        *(int*)((char*)self + 0x590 + i * 4) = 0;
    }
    
    *(int*)((char*)self + 0x5A0) = 0;
    *(int*)((char*)self + 0x5A4) = 0;
    *(int*)((char*)self + 0x5A8) = 0;
    *(int*)((char*)self + 0x5AC) = 0;
    *(int*)((char*)self + 0x5BC) = 0;
    *(int*)((char*)self + 0x5B0) = 0;
    *(int*)((char*)self + 0x5F4) = 0;
    *(int*)((char*)self + 0x60C) = 0;
    *(int*)((char*)self + 0x610) = 0;
    *(int*)((char*)self + 0x5B4) = 0;
    
    // ... more zero-init chain continues to 0x6BC
}
