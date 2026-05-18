// 00538710 RGE_View::draw_tile
// Attempt log:
// try 1: packet-grounded reconstruction of tile draw. Models terrain lookup, overlay/object image resolution, debug checker flag, draw object/terrain calls, neighbor dirty marking, and fallback overlay draw paths. Compiles too short (848B vs 1135B).
// try 2: modeled terrain id bounds against map+0x8d90 and terrain info index ter*408.
// try 3: modeled terrain availability byte at +0x8c and early return when unavailable.
// try 4: modeled overlay nibble from tile+6, overlay info index overlay*1440, availability, image pointer and simple-vs-composite branch.
// try 5: modeled resolve1/resolve2 helpers for overlay and terrain picture selection with -1 failure handling.
// try 6: modeled debug_grid_size checkerboard flag mutation and no_terrain_images clearing terrain draw.
// try 7: modeled main terrain image draw path and no_terrain_images alternate path.
// try 8: modeled dirty marking of left/below neighbor tile byte +0xa bit 0x40 when no alt overlay.
// try 9: modeled overlay draw path for simple and composite variants.
// try 10: high-level helper/member-call model remains far too short because original duplicates simple/composite draw blocks and preserves many stack locals/outparams inline.
// GIVEUP blockers: exact RGE_View/RGE_Map terrain/overlay struct layouts, helper signatures and outparam order (00539B90/00539C80/00539AA0/draw paths), globals semantics, and original duplicated block/control-flow topology. No inline asm used; no accepted_drift proposal.

struct Tile { char gap4[4]; unsigned char frame; unsigned char terrain; unsigned char overlay; char gap10[4]; };
struct Map { char gap0[0xc]; int h; char gap104[0x8d80]; Tile** rows; short terrains; char rest[0x1000]; };
class RGE_View {
public:
    char gap[0x104]; Map* map;
    short resolve1(int,int,int,int,int);
    int resolve2(int,int,int,int,int,int*,int*,int*,int*);
    short resolve3(int,int,int,int);
    void draw_obj(int,int,void*,int,int,int,int,int);
    void draw_obj2(int,int,void*,int,int,int,int,int);
    int draw_tile(Tile* t,int a,int ter,int sx,int sy,int dx,int dy,int flags,int shade);
};
extern int debug_grid_size;
extern int no_terrain_images;

int RGE_View::draw_tile(Tile* t,int a,int ter,int sx,int sy,int dx,int dy,int flags,int shade)
{
    unsigned char origFlags = t->gap10[2];
    if ((unsigned short)ter >= this->map->terrains) return 0;
    int index = ter * 408;
    if (!*((unsigned char*)this->map + index + 0x8c)) return 0;
    int draw = 1, alt = 0, marked = 0;
    unsigned char overlay = t->overlay & 0xf;
    if (overlay) {
        unsigned char* o = (unsigned char*)this->map + overlay * 1440 + 0x338c;
        if (o[0] && *(void**)(o+0x20)) {
            if (*(short*)(o+0x59e)==0) {
                short id = resolve1(overlay,t->frame,t->overlay>>4,sx,sy);
                if (id != -1) { alt = 1; draw = o[0x59a]; }
            } else {
                int p1=0,p2=0,p3=0,p4=0;
                if (resolve2(overlay,t->frame,t->overlay>>4,sx,sy,&p1,&p2,&p3,&p4)) { alt=1; draw=1; }
            }
        }
    }
    if (debug_grid_size > 0 && !(origFlags & 0xdf)) {
        if ((((short)sx / debug_grid_size) + ((short)sy / debug_grid_size)) & 1) origFlags |= 0x20;
    }
    if (no_terrain_images) alt = 0;
    if (draw) {
        void* img = *(void**)((char*)this->map + index + 0xac);
        short pic = resolve3(ter,t->frame,sx,sy);
        if (img && pic != -1) {
            if (no_terrain_images) { draw_obj2(sx,sy,img,pic,sx,sy,dx,dy); return 1; }
            draw_obj(sx,sy,img,pic,flags,dx,dy,shade);
            marked = 1;
        }
        if (!alt) {
            if ((short)sx > 0) this->map->rows[(short)sy][(short)sx-1].gap10[2] |= 0x40;
            if ((short)sy < this->map->h-1) this->map->rows[(short)sy+1][(short)sx].gap10[2] |= 0x40;
        }
    }
    if (alt) {
        unsigned char* o = (unsigned char*)this->map + overlay * 1440;
        void* img = *(void**)(o+0x33ac);
        if (img) {
            if (*(short*)(o+0x392a)==0) {
                short id = resolve1(overlay,t->frame,t->overlay>>4,sx,sy);
                if (id != -1) draw_obj(sx,sy,img,id,flags,dx,dy,shade);
            } else {
                int p1=0,p2=0,p3=0,p4=0;
                if (resolve2(overlay,t->frame,t->overlay>>4,sx,sy,&p1,&p2,&p3,&p4)) draw_obj(sx,sy,img,p1,flags,dx,dy,shade);
            }
        }
    }
    return marked;
}
