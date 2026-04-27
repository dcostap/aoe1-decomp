// VA: 0045A9E0 RGE_Missile_Object::init_missile (Combat + 4 floats variant)
// PDB source: misl_obj.cpp
// Attempt log:
// - EH-framed — 124/137 bytes expected (EH frame + scheduling)
// - 5 params: (RGE_Combat_Object*, float, float, float, float)
// - Correct: new 0x54-byte object + ACT_make with (this, p1, 0, p2, p3, p4) + list add + max_range store
// - Left in scratch

void* operator new(size_t size);

struct RGE_Missile_Object_init2 {
    char base[0x1C8];
    float max_range;
    void init_missile(void* p1, float p2, float p3, float p4, float p5);
};

void RGE_Missile_Object_init2::init_missile(void* p1, float p2, float p3, float p4, float p5)
{
    void* obj = operator new(0x54);
    if (obj) {
        // ACT_make with (this, p1, 0, p2, p3, p4)
    }
    if (obj) {
        // add to list at this+0x184
    }
    max_range = p5;
}
