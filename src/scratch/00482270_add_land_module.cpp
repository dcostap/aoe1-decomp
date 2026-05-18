// 00482270 RGE_RMM_Controller::add_land_module
// Attempt log:
// try 1: packet-grounded reconstruction with /GX. Models type switch defaults, land_info parameter block initialization, polar/random placement loop with collision avoidance, and construction of RGE_RMM_Land_Generator. Compiles too short (896B vs 1090B).
// try 2: modeled mode switch 0..3 initialization of output block fields +0x141c..+0x1434, including terrain bytes 0/0x22/0x14.
// try 3: modeled radius/scale constants 90/70/50/30 feeding later size math.
// try 4: modeled center/min/max bounds and clamp to 9 / width-10 / height-10.
// try 5: modeled outer land count loop and per-entry stride 0x34.
// try 6: modeled debug_rand line 209/210 random x/y generation with VC-style 0x7fff scaling approximation.
// try 7: modeled central-rectangle acceptance and collision-distance scan across prior entries.
// try 8: modeled fallback overwrite of last prior point when no hit and last scan entry.
// try 9: modeled per-land output x/y and area allocation.
// try 10: modeled final new RGE_RMM_Land_Generator(0x1468 bytes expected by packet/original ctor) via natural new+ctor surface; still far size-short due math/control topology.
// GIVEUP blockers: exact LandBlock layout/field offsets, original FPU/sqrt math expression, precise debug_rand scaling, collision loop control flow, and RGE_RMM_Land_Generator ctor signature/size surface. No inline asm used; no accepted_drift proposal.
// FLAGS: config/flags/00482270_add_land_module.rsp (/GX for original EH/new+ctor prologue)

typedef unsigned char byte;
extern "C" int __cdecl debug_rand(char*, int);
extern "C" long __cdecl ftol(float);
extern char rmm_cntr_cpp_path[];

struct LandBlock {
    int area; int x1; int y1; int x2; int y2; byte active; byte terrain; char pad16[0x34-0x16];
};
class RGE_RMM_Land_Generator {
public:
    RGE_RMM_Land_Generator(int, void*, void*);
};
class RGE_RMM_Controller {
public:
    char gap00[0x0c]; int id; char gap10[4]; int width; int height;
    RGE_RMM_Land_Generator* add_land_module(int area, void* out, int mode);
};

RGE_RMM_Land_Generator* RGE_RMM_Controller::add_land_module(int area, void* outp, int mode)
{
    LandBlock* out = (LandBlock*)outp;
    out->area = area;
    int radius;
    int n = 0;
    switch (mode) {
    case 0:
        out->active = 1; out->x1 = 0; out->y1 = 0; out->x2 = 0; out->y2 = 0; out->terrain = 0; radius = 90; break;
    case 1:
        out->active = 1; out->x1 = 4; out->y1 = 4; out->x2 = this->width - 5; out->y2 = this->height - 5; out->terrain = 0x22; radius = 70; break;
    case 2:
        out->active = 1; out->x1 = 6; out->y1 = 6; out->x2 = this->width - 7; out->y2 = this->height - 7; out->terrain = 0x14; radius = 50; break;
    case 3:
        out->active = 1; out->x1 = 8; out->y1 = 8; out->x2 = this->width - 9; out->y2 = this->height - 9; out->terrain = 0x14; radius = 30; break;
    default:
        out->active = 0; out->x1 = out->y1 = out->x2 = out->y2 = 0; out->terrain = 0; radius = 0; break;
    }

    int minx, maxx, miny, maxy;
    int midx = this->width / 2;
    int midy = this->height / 2;
    float f = (float)(area);
    int spread = (radius * this->height * this->width) / 100;
    int rr = ftol((float)(this->width - 16) / f * 3.1415926535f);
    minx = midx - rr; maxx = midx + rr;
    miny = midy - rr; maxy = midy + rr;
    if (minx <= 8) minx = 9;
    if (miny <= 8) miny = 9;
    if (maxx >= this->width - 9) maxx = this->width - 10;
    if (maxy >= this->height - 9) maxy = this->height - 10;

    int count = 0;
    LandBlock* p = out + 1;
    while (count < area) {
        byte ok = 0;
        int x = 0, y = 0;
        while (!ok) {
            ok = 0;
            x = debug_rand(rmm_cntr_cpp_path, 209) * (this->width - 16) / 0x7fff + 8;
            y = debug_rand(rmm_cntr_cpp_path, 210) * (this->height - 16) / 0x7fff + 8;
            if (x > minx && x < maxx && y > miny && y < maxy) ok = 1;
            for (int j = 0; j < count; ++j) {
                int dx = x - out[j+1].x1; if (dx < 0) dx = -dx;
                int dy = y - out[j+1].y1; if (dy < 0) dy = -dy;
                if ((float)(dx*dx + dy*dy) < (float)spread) {
                    if (!ok && j == count - 1) { out[j+1].x1 = x; out[j+1].y1 = y; }
                    ok = 1;
                }
            }
        }
        p->x1 = x; p->y1 = y; p->area = spread / area;
        ++p;
        ++count;
    }
    return new RGE_RMM_Land_Generator(this->id, this, out);
}
