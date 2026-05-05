// VA: 004C1080 RGE_Sprite::update
// PDB source: sprite.cpp lines 955-975
// left in scratch: behavior modeled; nearest shape gets saved EBX and correct early structure,
// but remaining drift is source-order/register scheduling around first-time path and timeout delete.

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
