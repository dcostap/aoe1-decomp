// VA: 004E5DB0 save (380B)
// taimdmd.cpp

class TribeMainDecisionAIModule {
public:
    char gap4[0x100];
    int* vtable_104;
    char gap108[0x5BC];
    int* vtable_6C4;
    
    void save(int fd);
};

void __cdecl sub_0040D0A0(void* this_, int fd);

void TribeMainDecisionAIModule::save(int fd) {
    sub_0040D0A0(this, fd);
    
    // Virtual call on member 1
    void (*func1)(void*, int) = (void (*)(void*, int))vtable_104[0x3C / 4];
    func1((char*)this + 0x104, fd);
    
    // Virtual call on member 2
    void (*func2)(void*, int) = (void (*)(void*, int))vtable_6C4[0x3C / 4];
    func2((char*)this + 0x6C4, fd);
}
