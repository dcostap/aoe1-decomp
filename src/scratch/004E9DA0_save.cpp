// VA: 004E9DA0 save (902B)
// taistrmd.cpp

class TribeStrategyAIModule {
public:
    char gap4[0xF0];
    int field_F4;
    
    void save(int fd);
};

int __cdecl rge_write(int fd, const void* buf, int size);

void TribeStrategyAIModule::save(int fd) {
    rge_write(fd, &field_F4, 4);
}
