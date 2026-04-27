// VA: 0044C5A0 RGE_Campaign_Info ctor (474B)
// gameinfo.cpp

class RGE_Campaign_Info {
public:
    char gap4[0x4];
    
    RGE_Campaign_Info(int fd);
};

int __cdecl rge_read(int fd, void* buf, int size);

RGE_Campaign_Info::RGE_Campaign_Info(int fd) {
    rge_read(fd, this, 0xFF);
}
