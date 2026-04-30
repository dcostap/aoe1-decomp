// 00437120 RGE_Diamond_Map::create_surfaces (diam_map.cpp:403-420)

void* operator new(unsigned int);
void operator delete(void*);

class TDrawArea {
public:
    char pad_00[0xFC]; // total sizeof = 4 (vtable) + 0xFC = 0x100
    TDrawArea(char* name, int param);
    virtual ~TDrawArea();
    int Init(void* param_1, int param_2, int param_3, int param_4, int param_5);
    void SetSize(int param_1, int param_2, int param_3);
};

class RGE_Diamond_Map {
public:
    int create_surfaces();

    char gap_00[0x14];
    int field_14;            // +0x14
    int field_18;            // +0x18
    int field_1C;            // +0x1C
    void* field_20;          // +0x20
    char gap_24[0x140];
    int own_save_area;       // +0x164
    TDrawArea* save_area;    // +0x168
};

int RGE_Diamond_Map::create_surfaces()
{
    if (this->save_area == 0) {
        TDrawArea* da = new TDrawArea("Diamond map (restored)", 0);
        this->save_area = da;
        if (da == 0) {
            return 0;
        }
        if (!da->Init(*(void**)this->field_20, this->field_14, this->field_18, 0, 0)) {
            TDrawArea* to_delete = this->save_area;
            if (to_delete != 0) {
                to_delete->TDrawArea::~TDrawArea();
                operator delete(to_delete);
            }
            this->save_area = 0;
            return 0;
        }
        this->own_save_area = 1;
    } else if (this->own_save_area) {
        this->save_area->SetSize(this->field_14, this->field_18, 0);
    }
    return 1;
}
