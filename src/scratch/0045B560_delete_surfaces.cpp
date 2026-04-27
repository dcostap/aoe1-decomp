// attempt 1: delete-surface cleanup using the real TMousePointer offsets and reset tail call
// later tries: tightened the layout and switched between temp-shaped and direct-member forms; the remaining mismatch stayed in the prolog / branch basin
// target shape: guard on custom_draw, free save_area at +8, loop cursors at +18 for Max_Cursors at +14, clear +10, then reset()
// paused here because the remaining diff is prolog/branch-layout drift rather than the surface cleanup behavior

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

    void delete_surfaces(void);
    void reset(void);
};

void TMousePointer::delete_surfaces(void) {
    int i = 0;

    if (this->custom_draw != 0) {
        if (this->save_area != 0) {
            this->save_area->TDrawArea::~TDrawArea();
            operator_delete(this->save_area);
            this->save_area = 0;
        }

        if (this->Max_Cursors > 0) {
            do {
                if (this->cursors[i] != 0) {
                    this->cursors[i]->TDrawArea::~TDrawArea();
                    operator_delete(this->cursors[i]);
                    this->cursors[i] = 0;
                }
                ++i;
            } while (i < this->Max_Cursors);
        }

        this->Num_Cursors = 0;
        this->reset();
    }
}
