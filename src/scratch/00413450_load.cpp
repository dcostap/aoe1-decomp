// VA: 00413450 load (949B)
// aiuaimod.cpp
// EH frame (/GX)

class UnitAIModule {
public:
    char gap4[0x4];
    void* field_08;
    
    void load(int fd);
};

void __cdecl rge_read(int fd, void* buf, int size);

void UnitAIModule::load(int fd) {
    // Load fields
    rge_read(fd, &field_08, 4);
    rge_read(fd, (char*)&field_08 + 4, 4);
    rge_read(fd, (char*)&field_08 + 8, 4);
    rge_read(fd, (char*)&field_08 + 12, 4);
    rge_read(fd, (char*)&field_08 + 16, 4);
}
