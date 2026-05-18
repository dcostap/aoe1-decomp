// 0046D830 PathSys::copyPath
// pathsys.cpp
// Attempt log:
// try 1: broad reconstruction from packet: initialize current nav helper, read path byte/direction, validate point, scan neighbor tiles for IDs, grow copied-id list, step direction until destination.
// try 2: modeled helper reset/use dispatch through active PathChecker chosen by path object +0x154 flag.
// try 3: modeled curX/curY at +0x4F61C/+0x4F61D, 255-wide byte grid lookup, marker high bits + direction low bits, and 0xFF no-direction sentinel.
// try 4: modeled vector float construction using offX/offY +0x11DC54/+0x11DC58 and current direction byte.
// try 5: modeled early duplicate destination check against lastX/lastY +0x11DC7C/+0x11DC80 and valid-point rejection.
// try 6: modeled neighbor bounding box x/y +/-1 with edge expansion/contract exactly as observed.
// try 7: modeled nested scan calling query_id(finder,targetArg,x,y,&flag), duplicate suppression against copied array, dynamic grow by copiedCount+1, copy/free old array, append id.
// try 8: modeled direction switch 0..7 updating curX/curY by signed step byte and recomputing direction/vector.
// try 9: modeled final path valid check and returns.
// try 10: default compile produced .text 1104B vs original 1114B, no full diff.
// try 11: /GX probe produced identical 1104B, removed flag file.
// left in scratch: broad behavior and size are close, but exact helper call surface (+0xA4/+0xD8), byte-parameter stack reuse, allocation-copy loop topology, and direction switch layout differ; rebuilt is 10B size-short. No accepted_drift: no localized full diff.

struct Vec2 { float x; float y; int z; unsigned char dir; };
class PathChecker { public: void reset(); int valid(Vec2*); void use(Vec2*); };
class PathSys {
public:
    int width; int height; char gap0c[0x4f61c-0x0c]; unsigned char curX; unsigned char curY;
    char gap4f61e[0x11dc40-0x4f61e]; void* finder; void* actor; PathChecker* path;
    float offX; float offY; char gap11dc5c[0x11dc7c-0x11dc5c]; int lastX; int lastY;
    char gap11dc84[0x11dcd8-0x11dc84]; unsigned char marker; int targetId; void* targetArg;
    int* copied; int copiedCount; int copiedCap;
    int copyPath(int step);
};
extern int query_id(void*, void*, int, int, int*);
extern "C" void* __cdecl malloc(unsigned int);
extern "C" void __cdecl free(void*);

static unsigned char dir_at(PathSys* ps, int x, int y) {
    unsigned char v = *(unsigned char*)((char*)ps + x*255 + y + 0x0c);
    if ((v & 0xf8) == ps->marker) return (unsigned char)(v & 7);
    return 0xff;
}
static void make_vec(PathSys* ps, int x, int y, unsigned char d, Vec2* out) {
    out->x = (float)x + ps->offX; out->y = (float)y + ps->offY; out->dir = d;
}

int PathSys::copyPath(int step) {
    int x,y,i,j,id,k;
    int x1,x2,y1,y2;
    Vec2 v;
    unsigned char d;
    path->reset();
    x = curX; y = curY;
    d = dir_at(this,x,y);
    make_vec(this,x,y,d,&v);
    path->use(&v);
    if (lastX == x && lastY == y) goto final_check;
    if (d != 0xff) {
        if (!path->valid(&v)) return 0;
    }
    while (targetId != -1) {
        x1=x-1; x2=x+1; if (x1<0) { x1=0; ++x2; } else if (x2>=width) { --x1; x2=width-1; }
        y1=y-1; y2=y+1; if (y1<0) { y1=0; ++y2; } else if (y2>=height) { --y1; y2=height-1; }
        for (i=x1;i<=x2;i++) {
            for (j=y1;j<=y2;j++) {
                int flag=0;
                id = query_id(finder,targetArg,i,j,&flag);
                if (id != -1) {
                    for (k=0;k<copiedCount && k<copiedCap;k++) if (copied[k] == id) goto next_cell;
                    if (copiedCount > copiedCap-1) {
                        int newCap = copiedCount+1;
                        int* n = (int*)malloc(newCap*4);
                        if (n) {
                            for (k=0;k<copiedCap && k<newCap;k++) n[k]=copied[k];
                            free(copied); copied=n; copiedCap=newCap;
                        }
                    }
                    copied[copiedCount++] = id;
                }
next_cell: ;
            }
        }
        switch (d & 0xff) {
        case 0: curX += step; curY += step; break;
        case 1: curY += step; break;
        case 2: curX -= step; curY += step; break;
        case 3: curX -= step; break;
        case 4: curX -= step; curY -= step; break;
        case 5: curY -= step; break;
        case 6: curX += step; curY -= step; break;
        case 7: curX += step; break;
        }
        x = curX; y = curY;
        d = dir_at(this,x,y);
        make_vec(this,x,y,d,&v);
        if (lastX == x && lastY == y) break;
        if (d != 0xff && !path->valid(&v)) return 0;
    }
final_check:
    if (!path->valid(&v)) return 0;
    return 1;
}
