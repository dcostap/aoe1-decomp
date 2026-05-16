// 004B5920 TribeGameSettingsScreen::~TribeGameSettingsScreen
// Attempt log:
// initial direct destructor from original asm: vptr store, release-control calls in observed order, free arrays, base destructor.

extern "C" void operator_delete(void*);

class TScreenPanel {
public:
    virtual ~TScreenPanel();
};

class TribeGameSettingsScreen : public TScreenPanel {
public:
    char gap_004[0x478-0x004];
    void* f478; char gap_47c[0x480-0x47c];
    void* f480; void* f484; void* f488; void* f48c; void* f490; void* f494; void* f498;
    int f49c;
    void* f4a0; void* f4a4; void* f4a8; void* f4ac; void* f4b0; void* f4b4; void* f4b8; void* f4bc; void* f4c0; void* f4c4; void* f4c8; void* f4cc; void* f4d0; void* f4d4; void* f4d8; void* f4dc;
    char gap_4e0[0x4f0-0x4e0];
    void* f4f0; void* f4f4;
    int count4f8;
    void** array4fc;
    void* ptr500;
    char gap_504[0x508-0x504];
    void* f508;
    char gap_50c[0x51c-0x50c];
    void* f51c; void* f520;
    char gap_524[0x544-0x524];
    void* f544; void* f548; void* f54c;

    virtual ~TribeGameSettingsScreen();
    void release_control(void* p);
};

TribeGameSettingsScreen::~TribeGameSettingsScreen()
{
    this->release_control(&this->f478);
    this->release_control(&this->f480);
    this->release_control(&this->f484);
    this->release_control(&this->f488);
    this->release_control(&this->f48c);
    this->release_control(&this->f490);
    this->release_control(&this->f494);
    this->release_control(&this->f4ac);
    this->release_control(&this->f4a8);
    this->release_control(&this->f4a4);
    this->release_control(&this->f4a0);
    this->release_control(&this->f498);
    this->release_control(&this->f4b0);
    this->release_control(&this->f4b4);
    this->release_control(&this->f4b8);
    this->release_control(&this->f4bc);
    this->release_control(&this->f4c0);
    this->release_control(&this->f4c4);
    this->release_control(&this->f4d8);
    this->release_control(&this->f4dc);
    this->release_control(&this->f4f0);
    this->release_control(&this->f4f4);
    this->release_control(&this->f508);
    this->release_control(&this->f51c);
    this->release_control(&this->f520);
    this->release_control(&this->f4c8);
    this->release_control(&this->f4cc);
    this->release_control(&this->f4d0);
    this->release_control(&this->f4d4);
    char* p = (char*)this + 0x534;
    int n = 4;
    do {
        this->release_control(p - 0x10);
        this->release_control(p);
        p += 4;
        n--;
    } while (n != 0);
    this->release_control(&this->f544);
    this->release_control(&this->f548);
    this->release_control(&this->f54c);

    if (this->array4fc) {
        int i = 0;
        if (this->count4f8 > 0) {
            do {
                void* q = this->array4fc[i];
                if (q) operator_delete(q);
                i++;
            } while (i < this->count4f8);
        }
        operator_delete(this->array4fc);
    }
    if (this->ptr500) operator_delete(this->ptr500);
}
