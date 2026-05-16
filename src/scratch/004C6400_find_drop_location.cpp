// 004C6400 RGE_Static_Object::find_drop_location
// Attempt log:
// initial direct behavioral source from asm: two-radius/two-pass randomized edge probes.
// first source modeled side switch, random line constants, map bounds, terrain check, drop collision virtual call, and final can_drop virtual call; compiled but rebuilt .text was 656 vs original/configured 674, so check_function stopped before compare.
// local obj disassembly showed same general prologue/FPU/random-switch shape but wrong register topology: rebuilt keeps this in EBX while original keeps drop object in EBX and this in EBP; stack frame 0x0c vs original 0x08.
// tried explicit register locals self=this and held=drop and using them throughout; VC5 still emitted same 656-byte topology.
// tried natural member calls for terrain_at/can_drop/check_drop instead of raw function pointers; call surfaces compile but do not recover original size/topology.
// left in scratch: behavior model is plausible but broad register/frame and FPU temp layout mismatch from entry; not accepted_drift-safe.

extern "C" int debug_rand(char*, int);
extern "C" int __ftol();

class RGE_Master_Static_Object { public: int can_drop(float, float, int); };
class RGE_Game_World { public: char gap[0x3c]; void* map_holder; };
class MapHolder { public: char gap[0x28]; void* map; };
class RGE_Static_Object;
class DropObj {
public:
    virtual char dummy0();
    virtual char dummy1();
    virtual char dummy2();
    virtual char dummy3();
    virtual char dummy4();
    virtual char dummy5();
    virtual char dummy6();
    virtual char dummy7();
    virtual char check_drop(RGE_Game_World*, float, float, int, int, int, int, int, int);
};

class RGE_Static_Object {
public:
    char gap_00[0x0c];
    RGE_Game_World* world;
    char gap_10[0x30-0x10];
    float x;
    float y;
    char gap_38[0x38-0x38];
    unsigned char terrain_at(int x, int y);
    unsigned char find_drop_location(int terrain, RGE_Master_Static_Object* drop, float* outx, float* outy, float a, float b, float c, float d, int required);
};

unsigned char RGE_Static_Object::find_drop_location(int terrain, RGE_Master_Static_Object* drop, float* outx, float* outy, float a, float b, float c, float d, int required)
{
    register RGE_Static_Object* self = this;
    register RGE_Master_Static_Object* held = drop;
    float sx = a + self->x;
    float sy = b + self->y;
    float minx = sx;
    float miny = sy;
    float spanx = sx + sx;
    float spany = sy + sy;
    int ring = 1;
    int attempt = 0;
    do {
        for (attempt = 0; attempt < 50; attempt++) {
            int r = debug_rand((char*)0x587180, 0xf3a);
            int side = ((r * 4) / 0x7fff);
            switch (side) {
            case 0: {
                *outx = minx + c;
                int rr = debug_rand((char*)0x587180, 0xf3e);
                *outy = (float)rr * spany * *(float*)0x574764 - miny + d;
                break;
            }
            case 1: {
                *outx = c - minx;
                int rr = debug_rand((char*)0x587180, 0xf42);
                *outy = (float)rr * spany * *(float*)0x574764 - miny + d;
                break;
            }
            case 2: {
                *outy = miny + d;
                int rr = debug_rand((char*)0x587180, 0xf46);
                *outx = (float)rr * spanx * *(float*)0x574764 - minx + c;
                break;
            }
            case 3: {
                *outy = d - miny;
                int rr = debug_rand((char*)0x587180, 0xf4a);
                *outx = (float)rr * spanx * *(float*)0x574764 - minx + c;
                break;
            }
            }
            if (*outx >= *(float*)0x574720 && *outy >= *(float*)0x574720) {
                MapHolder* mh = *(MapHolder**)((char*)self->world + 0x3c);
                void* map = mh->map;
                if ((float)*(int*)((char*)map + 8) >= *outx && (float)*(int*)((char*)map + 0x0c) >= *outy) {
                    if (terrain == -1 || terrain == self->terrain_at((int)*outx, (int)*outy)) {
                        if (!((DropObj*)held)->check_drop(self->world, *outx, *outy, 0, 1, 1, 1, 0, 1)) {
                            if (held->can_drop(*outx, *outy, 0) == 1) {
                                return 1;
                            }
                        }
                    }
                }
            }
        }
        minx += self->x;
        miny += self->y;
        spanx += self->x + self->x;
        spany += self->y + self->y;
        ring++;
    } while (ring < 2);
    return 0;
}
