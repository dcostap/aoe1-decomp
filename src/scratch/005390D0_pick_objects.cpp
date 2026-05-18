// 005390D0 RGE_View::pick_objects
// Attempt log:
// try 1: packet-grounded reconstruction of object picking. Models viewport/radius validation, scanline loop, bounds hit tests, mask priority, picked-object buckets and final flattening. Compiles too short (688B vs 1081B).
// try 2: modeled early validation of radius/min/max and viewport limits +0x8c/+0x90/+0x94/+0x98.
// try 3: modeled min/max clamp to 0..40 and conversion to view-relative x/y.
// try 4: modeled zeroing temp bucket locals and view bucket array at +0x314.
// try 5: modeled scan over player/grid rows and per-object null/id/skip checks.
// try 6: modeled rough outer padded bounds hit test and inner object bounds hit test.
// try 7: modeled flag bit 2 changing default hit priority and mask-test helper producing priority 1/2.
// try 8: modeled priority cutoff against caller priority and append into temporary bucket list.
// try 9: modeled final flattening from buckets into global Picked_Objects and returning count.
// try 10: helper/typed high-level model remains far too short; original has large inlined linked-list bucket management and scanline topology.
// GIVEUP blockers: exact RGE_View/player/grid/object/Picked_Objects layouts, mask helper signature, linked-list/bucket storage topology, and nested scan source shape. No inline asm used; no accepted_drift proposal.

struct PickedObj { int id; short action; short pad; int next; };
extern PickedObj Picked_Objects[];
extern "C" int __cdecl pick_mask_test(int,int,int,int);

class RGE_Static_Object { public: char gap00[8]; int id; char gap0c[0x10]; int flags; char gap20[0x0c]; short x1; short y1; short x2; short y2; short action; char gap3c[0x20]; };
struct Row { RGE_Static_Object** objects; };
struct Grid { char gap[0x5c]; Row** rows; };
class Player { public: char gap[0x334]; Grid* grid; };

class RGE_View {
public:
    char gap00[0x8c]; int view_x1; int view_y1; int view_x2; int view_y2;
    char gap9c[0x258]; int buckets[4]; char gap304[0x30]; Player* player;
    int pick_objects(int x, int y, int minr, int maxr, int radius, int priority, int skipNeg);
};

int RGE_View::pick_objects(int x, int y, int minr, int maxr, int radius, int priority, int skipNeg)
{
    if (radius < 0) return 0;
    if (maxr < minr) return 0;
    if (x < view_x1 || x > view_x2 || y < view_y1 || y > view_y2) return 0;
    if (minr > 40) return 0;
    if (maxr < 0) return 0;
    if (minr < 0) minr = 0;
    if (maxr > 40) maxr = 40;
    x -= view_x1;
    y -= view_y1;
    buckets[0]=buckets[1]=buckets[2]=buckets[3]=0;
    int found = 0;
    int outCount = 0;
    for (int row = maxr; row >= minr; --row) {
        Row* r = player->grid->rows[row];
        if (!r) continue;
        for (int k=0; k<40; ++k) {
            RGE_Static_Object* obj = r->objects[k];
            if (!obj) continue;
            int hit = 0;
            if (obj->id >= 0 || !skipNeg) {
                int ox1=obj->x1-radius, oy1=obj->y1-radius, ox2=obj->x2+radius, oy2=obj->y2+radius;
                if (x>=ox1 && y>=oy1 && x<=ox2 && y<=oy2) {
                    hit = 4;
                    if (x>=obj->x1 && y>=obj->y1 && x<=obj->x2 && y<=obj->y2) {
                        hit = (obj->flags & 2) ? 3 : 4;
                        int m = pick_mask_test(obj->gap00[0], obj->gap20[0], x-obj->x1, y-obj->y1);
                        if (m == 1) hit = 2; else if (m == 2) hit = 1;
                    }
                }
            }
            if (hit && hit <= priority) {
                PickedObj* po = &Picked_Objects[outCount++];
                po->id = obj->id;
                po->action = obj->action;
                po->next = buckets[hit-1];
                buckets[hit-1] = (int)po;
            }
        }
    }
    int n = 0;
    for (int b=0;b<4;b++) {
        int p=buckets[b];
        while (p) {
            PickedObj* po=(PickedObj*)p;
            Picked_Objects[n++] = *po;
            p = po->next;
        }
    }
    return n;
}
