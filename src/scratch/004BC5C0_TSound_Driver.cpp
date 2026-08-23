class Base_TSound_Driver {
public:
    virtual ~Base_TSound_Driver();
};

class TSound_Driver : public Base_TSound_Driver {
};

extern "C" void probe_TSound_Driver(TSound_Driver* p);
#pragma alloc_text(".xtra", probe_TSound_Driver)
extern "C" void probe_TSound_Driver(TSound_Driver* p) {
    p->TSound_Driver::~TSound_Driver();
}
