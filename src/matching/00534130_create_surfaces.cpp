// VA: 00534130 RGE_View::create_surfaces
// Attempt log:
// initial natural implementation from packet with real constructors/destructors; relies on /GX EH lowering.

#ifndef RGE_VIEW_SHARED_CONTEXT
extern "C" void* __cdecl operator_new(unsigned int);
extern "C" void __cdecl operator_delete(void*);

class TDrawArea {
public:
    char size_pad[0x100];
    TDrawArea(char* name, int param);
    int Init(void* sys, int width, int height, int p4, int p5);
    void SetSize(int width, int height, int p3);
    void SetFloatOffsets(int x, int y);
};

class DClipInfo_List {
public:
    char size_pad[0x70];
    DClipInfo_List(int a, int b, int c, int d, int e, int f);
    ~DClipInfo_List();
    void SetDrawRegion(int x1, int y1, int x2, int y2);
};

class RGE_View {
public:
    char gap_000[0x14];
    int width;           // +14
    int height;          // +18
    char gap_01c[4];
    void** drawSystem;   // +20
    char gap_024[0x2d0-0x24];
    int float_x;         // +2d0
    int float_y;         // +2d4
    char gap_2d8[0x324-0x2d8];
    TDrawArea* save_area1; // +324
    char gap_328[0x334-0x328];
    DClipInfo_List* prior_objs; // +334
    DClipInfo_List* futur_objs; // +338

    int create_surfaces();
};
#endif

int RGE_View::create_surfaces()
{
    if (this->width == 0 && this->height == 0) {
        return 1;
    }

    if (this->save_area1 == 0) {
        TDrawArea* area = new TDrawArea((char*)0x0058CD78, 0);
        this->save_area1 = area;
        if (area != 0) {
            area->Init(*this->drawSystem, this->width, this->height, 1, 0);
        }
    }

    if (this->save_area1 != 0 && this->height > 0) {
        this->save_area1->SetSize(this->width, this->height, 1);
        this->float_x = 0;
        this->float_y = 0;
        this->save_area1->SetFloatOffsets(0, 0);

        DClipInfo_List* p = this->prior_objs;
        if (p != 0) {
            delete p;
        }
        p = this->futur_objs;
        if (p != 0) {
            delete p;
        }

        int v = this->height + 0x1c2;
        this->prior_objs = new DClipInfo_List(v + v, v, 0x40, -200, this->height + 0xf9, 0x28);
        this->futur_objs = new DClipInfo_List(v + v, v, 0x40, -200, this->height + 0xf9, 0x28);

        this->prior_objs->SetDrawRegion(0, 0, this->width - 1, this->height - 1);
        this->futur_objs->SetDrawRegion(0, 0, this->width - 1, this->height - 1);
    }

    return this->save_area1 != 0;
}
