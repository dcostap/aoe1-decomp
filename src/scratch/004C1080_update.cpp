// VA: 004C1080 RGE_Sprite::update (123 B)
// PDB source: sprite.cpp lines 955-975
//
// Status: STUCK — instruction scheduling diff.
//
// First 11 bytes match (push ecx/bx/si, mov esi, push di). Then VC5 schedules
// differently: (1) param_1 loaded AFTER branch in first-time path (original loads
// before), (2) delta_time=1 stored before last_time in first-time path (original
// does last_time first), (3) accumulate path compares before storing delta_time
// (original stores before compare). These are VC5 internal scheduler decisions.
//
// Best: 53.66% positional, 38.21% edit diff. No source form tried (comma op,
// temp locals, register hints, inverted ops) controls VC5's scheduler to match
// the original's exact order. Multiple prior passes exhausted variants.
//
// No accepted_drift: 54% positional diff, broad scheduling/layout drift.

struct TShape {
    ~TShape();
};

void operator_delete(void* ptr);

struct RGE_Sprite {
    char field_00[0x14];
    unsigned char loaded;
    char field_15[0x07];
    TShape* shape;
    unsigned long last_time;
    int delta_time;

    void update(unsigned long param_1);
};

void RGE_Sprite::update(unsigned long param_1) {
    if (loaded) {
        TShape* pS = shape;
        if (pS) {
            int dt = delta_time;
            if ((double)dt == 0.0) {
                this->last_time = param_1;
                this->delta_time = 1;
                return;
            }
            int old_time = this->last_time;
            this->last_time = param_1;
            this->delta_time = (param_1 - old_time) + dt;
            if (this->delta_time >= 180000) {
                if (pS) {
                    pS->~TShape();
                    operator_delete(pS);
                }
                this->shape = 0;
            }
        }
    }
}
