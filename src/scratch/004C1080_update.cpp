// VA: 004C1080 RGE_Sprite::update
// PDB source: sprite.cpp lines 955-975
// left in scratch: behavior modeled; nearest shape gets saved EBX and correct early structure,
// but remaining drift is source-order/register scheduling around first-time path and timeout delete.
// 2026-05-10 current Boss-assigned pass: tried hoisting param/now before the FPU compare,
// inverted delta-time branch, explicit else/no-return first-time forms, temp one/now locals,
// volatile now, split arithmetic in original-looking order, cmp-after-store temps, and
// shape-delete redundant-test variants. No exact. Redundant delete-test variants recover
// original `test edi,edi` before deleting but lengthen the late path and shift/truncate the tail;
// the kept baseline is cleaner overall. VC5 still loads param after the zero-compare branch,
// stores `delta_time=1` before `last_time` in the first-time path, and compares before storing
// accumulated delta. Original loads param before the branch, stores last_time then delta_time,
// stores delta before cmp, and has different branch distances. No accepted_drift: broad
// scheduling/layout drift across both first-time and timeout paths.

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
        TShape* pShape = shape;
        if (pShape) {
            int dt = delta_time;
            if ((double)dt == 0.0) {
                last_time = param_1;
                delta_time = 1;
                return;
            }
            int old_time = last_time;
            int now = param_1;
            int elapsed = now - old_time;
            last_time = now;
            int new_dt = elapsed + dt;
            delta_time = new_dt;
            if (new_dt >= 180000) {
                if (pShape) {
                    pShape->~TShape();
                    operator_delete(pShape);
                }
                shape = 0;
            }
        }
    }
}
