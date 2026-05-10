// VA: 0045B560 TMousePointer::delete_surfaces (105 B)
// PDB source: Mouseptr.cpp lines 494-520
// Notes: 63.8% positional diff. Structure and logic all match: guard on
// custom_draw, free save_area, loop cursors for Max_Cursors, reset Num_Cursors,
// call reset(). Remaining diff is register allocation: original saves this in
// EBP, rebuilt saves this in EDI. Cascading effect changes all [ebp+N] to [edi+N],
// and swaps ESI/EDI roles for pointer walk vs temp pointers.
// Tried: self = this local, direct this-> access, different variable orderings.
// Tried pointer-walk cursor local + area temp: closer edit diff (25.7%) but worse
// positional; VC5 chose ebx=this and ebp=zero/counter, opposite of original.
// Tried declaration reorder, register/const/split initialization, long/unsigned
// counter, and narrow /O1 flag probe; none selected ebp=this (O1 wrong size).
// Kept direct this-> form because it is the best validated default-flags result.
// All source-level variants so far suggest a VC5 register allocator/TU-context
// barrier for choosing EBP as object base in isolation.
// 2026-05-10 current Boss-assigned pass: revalidated baseline and tried pointer-walk forms,
// self/register locals, top/inner declarations, unqualified member access, direct index vs pointer walk,
// while/for/do loop spellings, delete expressions vs explicit dtor/operator_delete, global operator delete,
// virtual dtor surface, and flag probes (/G5, /Oa, /Og, /Ob0, /Ot, /Ox, /Ow). No exact. Direct-index
// family keeps zero in EBX but this in EDI; pointer-walk/delete-expression family uses EBX=this and
// EBP=zero/counter. Neither selects original EBP=this, EBX=zero, EDI=cursor slot, ESI=temp area.

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
