#ifndef RGE_VIEW_SHARED_CONTEXT
void __cdecl operator_delete(void* ptr);

class TDrawArea {
public:
    ~TDrawArea();
};

class RGE_View {
public:
    char gap_00[0x324];
    TDrawArea* save_area1;

    void delete_surfaces(void);
};
#endif

void RGE_View::delete_surfaces(void) {
    TDrawArea* area;

    area = save_area1;
    if (area != 0) {
        area->TDrawArea::~TDrawArea();
        operator_delete(area);
        save_area1 = 0;
    }
}
