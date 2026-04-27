// VA: 00413150 save (758B)
// aiuaimod.cpp
// EH frame (/GX)

class UnitAIModule {
public:
    char gap4[0x4];
    void* field_08;
    
    void save(int fd);
};

int __cdecl color_log(int fd, int a, int b, const void* data, int size);
int __cdecl rge_write(int fd, const void* data, int size);

void UnitAIModule::save(int fd) {
    color_log(fd, 0x28, 0x28, 0, 1);
    
    // Save fields
    rge_write(fd, &field_08, 4);
    rge_write(fd, (char*)&field_08 + 4, 4);
    rge_write(fd, (char*)&field_08 + 8, 4);
    rge_write(fd, (char*)&field_08 + 12, 4);
    rge_write(fd, (char*)&field_08 + 16, 4);
}
