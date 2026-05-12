// VA: 0045B560 TMousePointer::delete_surfaces (105 B)
// PDB source: Mouseptr.cpp lines 494-520
//
// Status: STUCK — pure register allocation mismatch.
//
// Blocker: VC5's register allocator chooses different register assignments
// for this, zero/counter, walk pointer, and temp than the 1998 build.
// The source structure, control flow, call set, and memory effects are identical.
// All source forms and standard flag probes tested produce different register
// allocations. No source-visible surface can control VC5's internal reg-assignment.
//
// Original: EBP=this, EBX=0/counter, EDI=walk ptr, ESI=temp ptr
// Rebuilt best: EBP=this, EDI=0/counter, ESI=walk ptr, EBX=max (60.0%)
// Rebuilt baseline: EDI=this, EBX=0/counter, ESI=temp (63.8%)
// 60-64% positional diff — too broad for accepted_drift.
//
// Attempt log:
// - Pre-existing: 20+ variants (direct/pointer-walk, locals, register hints,
//   declaration order, loop forms, flag probes /G5/Oa/Og/Ob0/Ot/Ox/Ow).
//   Best: pointer-walk with edit diff 25.7% but still different registers.
// - 2026-05-12 (this pass):
//   V1: Early return + for loop + locals (75.24%)
//   V2: Pointer-walk with pp/count/i locals (60.0%, EBP=this matches)
//   Neither solves the register allocation mismatch.
//
// No accepted_drift: register swap affects every instruction encoding.
// No inline asm/hacks.

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
    if (this->custom_draw != 0) {
        if (this->save_area != 0) {
            this->save_area->TDrawArea::~TDrawArea();
            operator_delete(this->save_area);
            this->save_area = 0;
        }
        if (this->Max_Cursors > 0) {
            int i = 0;
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
