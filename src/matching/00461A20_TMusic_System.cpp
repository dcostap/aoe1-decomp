class Base_TMusic_System {
public:
    virtual ~Base_TMusic_System();
};

class TMusic_System : public Base_TMusic_System {
};

extern "C" void __stdcall probe_TMusic_System(void* p);
#pragma alloc_text(".text", probe_TMusic_System)
extern "C" void __stdcall probe_TMusic_System(void* p) {
    p->TMusic_System::~TMusic_System();
}
