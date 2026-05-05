// VA: 0045B560 TMousePointer::delete_surfaces (105 B)
// PDB source: Mouseptr.cpp lines 494-520
// Notes: 63.8% positional diff. Structure and logic all match: guard on
// custom_draw, free save_area, loop cursors for Max_Cursors, reset Num_Cursors,
// call reset(). Remaining diff is register allocation: original saves this in
// EBP, rebuilt saves this in EDI. Cascading effect changes all [ebp+N] to [edi+N],
// and swaps ESI/EDI roles for pointer walk vs temp pointers.
// Tried: self = this local, direct this-> access, different variable orderings.
// All produce the same EDI-this pattern. VC5 register allocator prefers EDI
// over EBP for the base pointer in isolation.

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
                i++;
            } while (i < this->Max_Cursors);
        }
        this->Num_Cursors = 0;
        this->reset();
    }
}
