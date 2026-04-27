// VA: 0052A260 TRIBE_Game::setup_video_system (450 B)
// PDB source: tribegam.cpp
// Packet-grounded: EH-framed, create TDrawSystem, set up TDrawArea chain

extern void* operator_new(unsigned int size);
extern void operator_delete(void* p);

void TRIBE_Game_setup_video_system(void* self)
{
    // EH frame via FS:[0]
    // ...
    
    // Create TDrawSystem (operator_new + constructor)
    void* drawSys = operator_new(0x480);
    
    // Store in self+0xC00
    *(void**)((char*)self + 0xC00) = drawSys;
}
