// 0051CDB0 TRIBE_Panel_Pop::~TRIBE_Panel_Pop
// Size: 139 bytes
// FLAGS: /GX (EH frame)

__declspec(dllimport) int __stdcall DeleteObject(void* obj);

class TDrawArea {
public:
    ~TDrawArea();
};

class TPanel {
public:
    virtual ~TPanel();
    char gap_04[0x11C];
    void* image_clip_region;   // +0x120
    TDrawArea* ImageBuffer;    // +0x124
};

class TRIBE_Panel_Pop : public TPanel {
public:
    virtual ~TRIBE_Panel_Pop();
};

TRIBE_Panel_Pop::~TRIBE_Panel_Pop() {
    TDrawArea* buf;

    if (this->image_clip_region != 0) {
        DeleteObject(this->image_clip_region);
        this->image_clip_region = 0;
    }
    buf = this->ImageBuffer;
    if (buf != 0) {
        buf->~TDrawArea();
        operator delete(buf);
        this->ImageBuffer = 0;
    }
}
