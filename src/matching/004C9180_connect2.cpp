#ifndef T_B_OBJ_CONTEXT_H
class TRIBE_Building_Object {
public:
    char gap0[0x10];
    void* object_info;
    char gap14[0x21];
    unsigned char facet;

    void check(TRIBE_Building_Object** checks);
    void rotate(long amount);
    void connect2();
};
#endif

void TRIBE_Building_Object::connect2()
{
    TRIBE_Building_Object* checks[4];

    if (object_info) {
        if (*(short*)((char*)object_info + 0x60) == 3) {
            check(checks);
            TRIBE_Building_Object* a = checks[0];
            TRIBE_Building_Object* c = checks[2];
            TRIBE_Building_Object* b = checks[1];
            TRIBE_Building_Object* d = checks[3];

            if (a && d) {
                if (!b && !c) {
                    rotate(1 - facet);
                    return;
                }
            }
            if (b && c) {
                if (!a && !d) {
                    rotate(-facet);
                    return;
                }
            }
            rotate(2 - facet);
            return;
        }
        facet = 0;
    }
}
