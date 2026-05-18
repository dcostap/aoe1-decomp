// 0053FBD0 RGE_Main_View::pick1
// Attempt log:
// try 1: packet-grounded reconstruction using vw_main pick family context. Models 0x29 pick path, output zeroing, pick_objects radius variants, no-exclude best scan, exclude-object alternate scan, output fill, 0x2a recursive wrapper, and fallback pick_multi call.
// try 2: fixed Picked_Objects entry stride/fields and helper declaration; reached exact configured size 982.
// try 3: first 0x60 bytes nearly match: parameter byte test, 0x29 branch, out struct zeroing, and pick_objects argument variants are in the right basin.
// try 4: modeled no-exclude best-object scan over Picked_Objects, player object array at +0xfc/+88, owner < 7, master byte +0x8d >= small.
// try 5: modeled optional terrain/path filter: alt param, terrain flag +0x8db8, virtual can_pick at vtable +0xe0, tile helper returning 0x0f.
// try 6: modeled score_pick virtual at +0xe4 and best-score update with view offsets +0x8c/+0x90 plus picked dx/dy.
// try 7: modeled exclude-object path with seen-exclude flag and alternate selection, including fallback to last picked entry.
// try 8: modeled output fill fields: world x/y from object +0x38/+0x3c, screen shorts, object pointer, and 0x34/0x32 return codes.
// try 9: modeled 0x2a wrapper that retries as 0x29 with alt=1 and returns early on 0x34.
// try 10: tried casting float positions directly to int for tile helper instead of ftol calls; worsened to 78.5132% positional / 111.6090% edit, rolled back.
// Current validation: exact size but broad mismatch (75.4582% positional / 92.1589% edit). First mismatch is branch distance from later block layout; early setup matches for 17 bytes and large prefix equalities, but scan/helper regions diverge.
// GIVEUP blockers: exact Picked_Objects entry/layout, RGE_Main_View/RGE_Player/RGE_Static_Object surfaces, virtual helper declarations for +0xe0/+0xe4 and tile check, and natural source shape for the two scan loops/tail-shared returns. No inline asm used; no accepted_drift proposal.

typedef unsigned char byte;
extern "C" long __cdecl ftol(float);

struct PickInfo { int x; int y; short sx; short sy; void* obj; int extra; };
struct PickedInfo { int id; short dx; short dy; short sx; short sy; };
extern PickedInfo Picked_Objects[];

class RGE_Static_Object { public: char gap00[8]; void* master; char gap0c[0x2c]; float x; float y; char gap40[8]; byte owner; };
class RGE_Player { public: char gap00[0x88]; RGE_Static_Object** objects; };
class PathThing { public: char gap00[0x38]; int terrain; };
class TerrainMap { public: char gap00[0x8db8]; byte flag; };

class RGE_Main_View {
public:
    void* vftable;
    char gap04[0x88]; short view_x; char gap8e[2]; short view_y; char gap92[0x6a]; RGE_Player* player; PathThing* path; TerrainMap* terrain;
    byte pick1(byte cmd, byte small, long x, long y, PickInfo* out, RGE_Static_Object* exclude, int alt);
    int pick_objects(int x,int y,int a,int b,int r,int c,int d);
    byte pick_multi(byte cmd, byte small, long x, long y, RGE_Static_Object* ex1, RGE_Static_Object* ex2, PickInfo* out);
    int can_pick(RGE_Static_Object* o);
    int score_pick(RGE_Static_Object* o, int action);
};
extern "C" byte helper_0053C490(PathThing*, int, int);

static void fill_pick(PickInfo* out, RGE_Static_Object* o, short sx, short sy)
{
    out->obj = o;
    out->sx = sx;
    out->sy = sy;
    out->x = *(int*)((char*)o + 0x38);
    out->y = *(int*)((char*)o + 0x3c);
}

byte RGE_Main_View::pick1(byte cmd, byte small, long x, long y, PickInfo* out, RGE_Static_Object* exclude, int alt)
{
    RGE_Main_View* self = this;
    if (cmd == 0x29) {
        out->x = 0; out->y = 0; out->sx = 0; out->sy = 0; out->obj = 0; out->extra = 0;
        int count;
        if (!small)
            count = self->pick_objects(x, y, 0, 40, 15, 4, 1);
        else
            count = self->pick_objects(x, y, 10, 20, 15, 4, 1);
        if (!count) return 0x32;
        if (!exclude) {
            RGE_Static_Object* best = 0;
            int bestScore = 0;
            short bestx = 0, besty = 0;
            for (int i = 0; i < count; ++i) {
                PickedInfo* p = &Picked_Objects[i];
                if (p->id >= 0) {
                    RGE_Static_Object* obj = self->player->objects[p->id];
                    if (obj && obj->owner < 7 && *((byte*)obj->master + 0x8d) >= small) {
                        if (alt || self->terrain->flag || self->can_pick(obj) || helper_0053C490(self->path, ftol(obj->y), ftol(obj->x)) == 0x0f) {
                            int s = self->score_pick(obj, p->dx);
                            if (s > bestScore) {
                                bestx = self->view_x + p->sx;
                                besty = self->view_y + p->sy;
                                best = obj;
                                bestScore = s;
                            }
                        }
                    }
                }
            }
            if (!best) return 0x32;
            fill_pick(out, best, bestx, besty);
            return 0x34;
        } else {
            int seenExclude = 0;
            RGE_Static_Object* chosen = 0;
            short cx = 0, cy = 0;
            for (int j = 0; j < count; ++j) {
                PickedInfo* p = &Picked_Objects[j];
                if (p->id >= 0) {
                    RGE_Static_Object* obj = self->player->objects[p->id];
                    if (obj && obj->owner < 7 && *((byte*)obj->master + 0x8d) >= small) {
                        int s = self->score_pick(obj, p->dx);
                        if (s > 0 && (alt || self->terrain->flag || self->can_pick(obj) || helper_0053C490(self->path, ftol(obj->y), ftol(obj->x)) == 0x0f)) {
                            if (obj == exclude) seenExclude = 1;
                            else if (!seenExclude) {
                                if (!chosen) { chosen = obj; cx = self->view_x + p->sx; cy = self->view_y + p->sy; }
                            } else {
                                chosen = obj; cx = self->view_x + p->sx; cy = self->view_y + p->sy; break;
                            }
                        }
                    }
                }
            }
            if (seenExclude && !chosen && count > 0) {
                int k = count - 1;
                PickedInfo* p = &Picked_Objects[k];
                chosen = (p->id >= 0) ? self->player->objects[p->id] : 0;
                cx = self->view_x + p->sx; cy = self->view_y + p->sy;
            }
            if (!chosen) return 0x32;
            fill_pick(out, chosen, cx, cy);
            return 0x34;
        }
    }
    if (cmd == 0x2a) {
        if (self->pick1(0x29, small, x, y, out, exclude, 1) == 0x34) return 0x34;
    }
    return self->pick_multi(0x28, small, x, y, exclude, (RGE_Static_Object*)alt, out);
}
