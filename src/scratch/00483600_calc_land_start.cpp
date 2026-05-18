// 00483600 RGE_RMM_Database_Controller::calc_land_start
// rmm_dbct.cpp
// Attempt log:
// try 1: broad reconstruction from packet: compute bounds from map size/radius/type, dispatch land-placement modes, random start generation and spacing checks.
// try 2: modeled initial debug_rand/log sequence and parameter order for start/radius/count/land.
// try 3: modeled map width/height at +0x14/+0x18, radius*2 range, and floating bound calculation with count-dependent scale.
// try 4: modeled central min/max x/y bounds and clamping against radius/map edges.
// try 5: modeled land->placement switch: 0=random individual starts, 1=copy fixed land x/y, 2=random starts with spacing rejection.
// try 6: modeled random scaling as debug_rand(file,line) * range / 0x7fff using __int64 helper to compile on VC5.
// try 7: modeled mode 2 loop with central-bounds test, pairwise squared-distance rejection against prior slots, retry loop, and per-slot log.
// try 8: modeled slots as 0x34-byte stride entries with x/y at +0x44/+0x48 from controller base +0x48.
// try 9: fixed VC5 compile issue: replaced unsupported long long with __int64.
// try 10: default compile produced .text 1008B vs original 1056B, no full diff.
// try 11: /GX probe produced identical 1008B, removed flag file.
// left in scratch: broad behavior is close and size gap is only 48B, but exact FPU expression tree, random scaling idiom, log/source-line interleaving, and retry-loop control flow still differ; no accepted_drift because no localized full diff.

extern "C" int __cdecl debug_rand(const char*, int);
extern "C" void __cdecl Log(void*, const char*, ...);
extern int roundFloat(float);
extern void* L;
struct LandInfo { char gap0[0x11]; unsigned char placement; char gap12[0x14-0x12]; int x; int y; };
class RGE_RMM_Database_Controller {
public:
    char gap0[0x14]; int mapW; int mapH; char gap1c[0x48-0x1c];
    struct Slot { int pad0[17]; int x; int y; int pad[11]; } slots[64];
    void calc_land_start(int start, int radius, int count, LandInfo* land);
};

static int rand_scaled(int lo, int range, int line) {
    int r = debug_rand((const char*)0x585D50, line);
    return lo + (int)(((__int64)r * range) / 0x7fff);
}

void RGE_RMM_Database_Controller::calc_land_start(int start, int radius, int count, LandInfo* land) {
    int w = mapW;
    int h = mapH;
    int minx, maxx, miny, maxy;
    int i, j;
    int x, y;
    int ok;
    int two = radius + radius;
    int range;
    float bound;

    Log(L,(const char*)0x585D20, debug_rand((const char*)0x585D50,0x1c3));
    bound = (float)(w - two) / (float)roundFloat(1.0f);
    if (count > 3 && count < 7) bound *= 0.75f;
    else if (count >= 7) bound *= 0.5f;
    bound = bound * bound;
    minx = roundFloat((float)(w/2) - (float)w * 0.35f);
    miny = roundFloat((float)(h/2) - (float)w * 0.35f);
    maxx = roundFloat((float)(w/2) + (float)w * 0.35f);
    maxy = roundFloat((float)(h/2) + (float)w * 0.35f);
    if (minx <= radius) minx = radius + 1;
    if (miny <= radius) miny = radius + 1;
    if (maxx >= w - radius - 1) maxx = w - radius - 2;
    if (maxy >= h - radius - 1) maxy = h - radius - 2;

    switch (land->placement) {
    case 0:
        Log(L,(const char*)0x585C68);
        for (i=start;i<start+count;i++) {
            slots[i].x = rand_scaled(radius, w-two, 0x1e5);
            slots[i].y = rand_scaled(radius, h-two, 0x1e6);
        }
        break;
    case 1:
        Log(L,(const char*)0x585C94);
        for (i=start;i<start+count;i++) { slots[i].x = land->x; slots[i].y = land->y; }
        break;
    case 2:
        Log(L,(const char*)0x585CF4);
        for (i=start;i<start+count;i++) {
            ok = 0;
            while (!ok) {
                x = rand_scaled(radius, w-two, 0x1fc);
                y = rand_scaled(radius, h-two, 0x1fd);
                if (x > minx && x < maxx && y > miny && y < maxy) ok = 1;
                for (j=start; j<i && ok; ++j) {
                    int dx=x-slots[j].x; if (dx<0) dx=-dx;
                    int dy=y-slots[j].y; if (dy<0) dy=-dy;
                    if ((float)(dx*dx + dy*dy) <= bound) ok = 0;
                }
            }
            slots[i].x=x; slots[i].y=y;
            Log(L,(const char*)0x585CC0,i,x,y);
        }
        break;
    default:
        break;
    }
    Log(L,(const char*)0x585C40);
}
