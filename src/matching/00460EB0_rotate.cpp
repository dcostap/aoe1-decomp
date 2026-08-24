// VA: 00460EB0 rotate
// move_obj.cpp lines 3157-3167, 143 bytes
// RGE_Moving_Object::rotate(int)
// Attempt log:
// 1: Baseline had wrong object/angle offsets (+14/+A0) and fake stdcall vtable call pushed ECX; 43.36% positional.
// 2: Fixed layout (gameObj +0x10, rotOffset +0x9C) and declared virtual padding so set_rotation is vt[45]/+0xB4. This removed offset/call mismatches and improved to 41.96% pos / 29.37% edit.
// 3: Tried double multiplication literal/casts to force original qword fmul; variants either inserted extra fld/fst around rotOffset or worsened broad FPU topology, rolled back.
// 4: Changed upper-bound while compare to 6.283185f; small edit improvement only.
// 5: Tried explicit else `rotation = val`; compiler optimized size-short 128, rolled back.
// 2026-05-19: MATCH breakthrough: add one missing virtual pad so set_rotation is really vt+0xB4; remove the extra `val` temp so ST0 stays live across both range checks; use double 2*pi constants for multiply and upper-bound compares while keeping float subtract constants. Result: MATCH.

#ifndef MOVE_OBJ_CANONICAL_TU
class RGE_Moving_Object {
public:
    virtual ~RGE_Moving_Object();
    char gap0[0x0C];
    void* gameObj;              // +0x10
    char gap14[0x88];
    float rotOffset;            // +0x9C
    char gapA0[4];

    virtual void vpad1(); virtual void vpad2(); virtual void vpad3(); virtual void vpad4();
    virtual void vpad5(); virtual void vpad6(); virtual void vpad7(); virtual void vpad8();
    virtual void vpad9(); virtual void vpad10(); virtual void vpad11(); virtual void vpad12();
    virtual void vpad13(); virtual void vpad14(); virtual void vpad15(); virtual void vpad16();
    virtual void vpad17(); virtual void vpad18(); virtual void vpad19(); virtual void vpad20();
    virtual void vpad21(); virtual void vpad22(); virtual void vpad23(); virtual void vpad24();
    virtual void vpad25(); virtual void vpad26(); virtual void vpad27(); virtual void vpad28();
    virtual void vpad29(); virtual void vpad30(); virtual void vpad31(); virtual void vpad32();
    virtual void vpad33(); virtual void vpad34(); virtual void vpad35(); virtual void vpad36();
    virtual void vpad37(); virtual void vpad38(); virtual void vpad39(); virtual void vpad40();
    virtual void vpad41(); virtual void vpad42(); virtual void vpad43(); virtual void vpad44(); virtual void set_rotation(float rotation);
    void rotate(int angleDeg);
};
#endif

#ifdef MOVE_OBJ_CANONICAL_TU
#define gameObj sprite
#define rotOffset angle
#endif

void RGE_Moving_Object::rotate(int angleDeg) {
    void* obj;
    float rotation;

    obj = gameObj;
    rotation = (float)(((double)angleDeg * 6.283185307179586) / (double)*(short*)((char*)obj + 0x60)) + rotOffset;

    if (rotation < 0.0f) {
        do {
            rotation += 6.283185f;
        } while (rotation < 0.0f);
    }
    if (rotation >= 6.283185307179586) {
        do {
            rotation -= 6.283185f;
        } while (rotation >= 6.283185307179586);
    }

    this->set_rotation(rotation);
}

#ifdef MOVE_OBJ_CANONICAL_TU
#undef gameObj
#undef rotOffset
#endif
