// VA: 004CBEF0 TRIBE_Combat_Object::higher_than_target
// Attempt log:
// 1: direct reconstruction from packet/decompiler, including FPU-ish stepping and vtable +0x248 helper calls.
// 2: added dummy locals to probe original 0x48 frame and changed first height compare spelling; dummy locals optimized out, rebuilt remains 0x40 frame.
// 3: current same-size 701B only because codegen is broadly different; first mismatch at offset 2 (frame size 0x40 vs original 0x48). FPU setup for delta/abs/step selection is decompiler-shaped and does not match original x87 stack choreography; later helper-call argument ordering is only approximate.
// left in scratch: broad frame/FPU/helper-call topology mismatch, not accepted_drift-safe.

class RGE_Static_Object { public: char gap[0x38]; float x; float y; float z; };

class TRIBE_Combat_Object {
public:
    void** vtbl;
    char gap04[8];
    void* owner; // +0c, points to object with +3c -> +28 count-ish
    char gap10[0x28];
    float x;
    float y;
    float z;
    int higher_than_target(RGE_Static_Object* target);
};

typedef int (__stdcall *CheckFn)(RGE_Static_Object*, int, int, float, float, float, float, int, int, int, int, float*, int*);

int TRIBE_Combat_Object::higher_than_target(RGE_Static_Object* target)
{
    int pad0;
    int pad1;
    if (target->z <= this->z) {
        return 1;
    }

    float XStep = target->x - this->x;
    float YStep = target->y - this->y;
    if (XStep == 0.0f && YStep == 0.0f) {
        return 0;
    }

    float stepSource;
    float ax0 = XStep < 0.0f ? -XStep : XStep;
    float ay0 = YStep < 0.0f ? -YStep : YStep;
    if (ax0 < ay0) {
        stepSource = YStep;
    } else {
        stepSource = XStep;
    }
    int steps = ((int)stepSource);
    if (steps < 0) steps = -steps;
    steps <<= 1;

    float divisor = (float)steps;
    float yStep = XStep / divisor;
    float xStep = YStep / divisor;
    float absX = xStep;
    float absY = yStep;
    if (absY < 0.0f) absY = -yStep;
    if (absX < 0.0f) absX = -xStep;

    int dx1, dx2, dy1, dy2;
    if (absX >= absY) {
        dx1 = -1; dy1 = 0; dx2 = 1; dy2 = 0;
    } else {
        dx1 = 0; dy1 = -1; dx2 = 0; dy2 = 1;
    }

    float yTile = this->x;
    float xTile = this->y;
    int priorY = -999;
    int priorX = -999;
    int count = *(int*)(*(int*)(*(int*)((char*)this + 0x0c) + 0x3c) + 0x28);
    float numSteps = -1.0f;
    int result = 0;
    if (steps > 0) {
        int loopCount = steps;
        do {
            yTile += yStep;
            xTile += xStep;
            int iy = (int)yTile;
            int ix = (int)xTile;
            if (iy != priorY || ix != priorX) {
                CheckFn fn = (CheckFn)*(int*)((char*)this->vtbl + 0x248);
                priorY = iy;
                priorX = ix;
                if (!fn(target, iy, ix, XStep, this->x, YStep, target->x, priorX, 0, count, dx1, &numSteps, &result)) {
                    if (!fn(target, iy + dy2, ix + dx2, XStep, this->x, YStep, target->x, priorX, 0, count, dx1, &numSteps, &result)) {
                        fn(target, iy + dy1, ix + dx1, XStep, this->x, YStep, target->x, priorX, 0, count, dx1, &numSteps, &result);
                    }
                }
            }
            --loopCount;
        } while (loopCount != 0);
    }
    if (result < 1) result = 0;
    if (result > 0) result = 1;
    return result > 0;
}
