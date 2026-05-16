// VA: 0045B560 TMousePointer::delete_surfaces (105 B)
// PDB source: Mouseptr.cpp lines 494-520
// Attempt: declare i before using this to bias register coloring

void operator_delete(void* ptr);

class TDrawArea {
public:
    ~TDrawArea();
};

class TMousePointer {
public:
    int custom_draw;
    TDrawArea* render_area;
    TDrawArea* save_area;
    TDrawArea* primary_area;
    int Num_Cursors;
    int Max_Cursors;
    TDrawArea* cursors[16];

    void delete_surfaces();
    void reset();
};

void TMousePointer::delete_surfaces()
{
    TMousePointer* self;
    self = this;
    int i = 0;
    TDrawArea* t;
    TDrawArea** walk;
    if (self->custom_draw != 0) {
        if ((t = self->save_area) != 0) {
            t->TDrawArea::~TDrawArea();
            operator_delete(t);
            self->save_area = 0;
        }
        if (self->Max_Cursors > 0) {
            walk = self->cursors;
            do {
                if ((t = *walk) != 0) {
                    t->TDrawArea::~TDrawArea();
                    operator_delete(t);
                    *walk = 0;
                }
                i++;
                walk++;
            } while (i < self->Max_Cursors);
        }
        self->Num_Cursors = 0;
        self->reset();
    }
}
