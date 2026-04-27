// first pass: natural destructor with /GX-visible virtual destructors for EH frame/vptr restore
// use IAT-style extern function pointer for DeleteObject and explicit vptr restore to match original
extern int (__stdcall *DeleteObject)(void*);
void operator delete(void*);

class TDrawArea {
public:
    ~TDrawArea(void);
};

class TPanel {
public:
    virtual void pv0();
    virtual void pv1();
    virtual void pv2();
    virtual void pv3();
    virtual void pv4();
    virtual void pv5(int);
    virtual void pv6();
    virtual void pv7();
    virtual void pv8(int);
    char gap_004[0x2F8];
    virtual ~TPanel(void);
};

class TMessagePanel : public TPanel {
public:
    char gap_2FC[0x30];
    void* image_clip_region;
    TDrawArea* ImageBuffer;

    virtual ~TMessagePanel(void);
};

TMessagePanel::~TMessagePanel(void) {
    if (this->image_clip_region != 0) {
        DeleteObject(this->image_clip_region);
        this->image_clip_region = 0;
    }
    TDrawArea* image_buffer = this->ImageBuffer;
    if (image_buffer != 0) {
        delete image_buffer;
        this->ImageBuffer = 0;
    }
}
