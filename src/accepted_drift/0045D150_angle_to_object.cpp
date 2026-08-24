// 0045D150 angle_to_object
// move_obj.cpp:436-470, 160 bytes
// Round2 pass: 10 focused variants tried: atan2 argument order, explicit dx/dy temps,
// reversed temp declarations, in-place coordinate subtraction, and final scale expression order.
// Best retained source is exact-size and near-identical: MISMATCH 6.2500% positional,
// 3.7500% edit, first mismatch 54. Remaining drift is only equivalent FPU stack
// ordering around the coordinate subtracts before FPATAN; all guards, constants,
// wrap predicates, scale, stack-slot reuse, returns, and memory effects match.

extern float DAT_00570b48;
extern float DAT_00570b4c;
extern float DAT_00570b50;
extern double DAT_00570b68;
extern double DAT_00570b70;
extern float DAT_00570b78;

#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    char gap0[0x10];
    void* gameObj;
    char gap14[0x24];
    float x;
    float y;
    char gap40[0x5C];
    float angle;

    float angle_to_object(void* target, float tx, float ty);
};
#endif

extern "C" double __cdecl atan2(double, double);

#ifdef MOVE_OBJ_CANONICAL_TU
#define gameObj sprite
#define x world_x
#define y world_y
float RGE_Moving_Object::angle_to_object(RGE_Static_Object* target, float tx, float ty)
#else
float RGE_Moving_Object::angle_to_object(void* target, float tx, float ty)
#endif
{
    void* g = gameObj;
    if (g && (*(unsigned char*)((char*)g + 0x70) & 2) && *(short*)((char*)g + 0x60) > 0) {
        float ax;
        float ay;
        if (target) {
            ay = *(float*)((char*)target + 0x3c);
            ax = *(float*)((char*)target + 0x38);
        } else {
            ay = ty;
            ax = tx;
        }

        float a = (float)atan2((double)(ay - y), (double)(ax - x));
        if (a < DAT_00570b48)
            a -= DAT_00570b4c;
        a -= angle;
        if (a > DAT_00570b68)
            a -= DAT_00570b50;
        if (a < DAT_00570b70)
            a -= DAT_00570b4c;

        return ((float)((int)*(short*)((char*)g + 0x60)) * DAT_00570b78) * a;
    }
    return DAT_00570b48;
}

#ifdef MOVE_OBJ_CANONICAL_TU
#undef gameObj
#undef x
#undef y
#endif
