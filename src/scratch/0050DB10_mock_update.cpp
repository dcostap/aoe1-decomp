// 0050DB10 RGE_Timeline::mock_update
// Attempt log:
// initial source from packet/decompiler compiled to 512B: correct broad structure but old_time was at +0x0c instead of +0x10.
// fixed RGE_Timeline layout with gap_0C so old_time is +0x10; FPU member offsets now match.
// changed FPU compare spellings to `n->time > old_time`, `e->time <= t`, and `e->time > old_time` to recover original fld/fcomp/test 0x41 forms.
// changed command dispatch from if/else byte compares to switch; this recovered the original xor/mov al/dec/sub dispatch family and grew body to 528B.
// tried assigning list/e in alternate order (`e=time_list; list=e`); worsened early register use (loaded esi directly and moved edx later), rolled back.
// tried assignment-in-condition for e=list; no change from baseline.
// tried more explicit first scan loop (`while (e->next != 0) { n=e->next; ... }`); worsened diff with extra compare of [edx+2c], rolled back.
// temporarily added a separate dummy pad function only to let check_function compare the 528B body against 529B original; removed it. Diagnostic with pad: same 529 compare size, 13.23% edit diff, first mismatch at 0x16 due branch target/initial cmp scheduling.
// left in scratch: current real source is 528B (one byte short, check_function stops with section-size error). Remaining mismatch is small edit-distance but not accepted-drift-safe: early rewind list prologue schedules `cmp edx,ebx; mov esi,edx` instead of original `mov esi,edx; cmp esi,ebx`, first scan loop is shorter, and branch targets shift through both pass blocks.
// Fresh same-TU pass (sa-ab07d2be-Timeline):
// - Separate direct time_list reads preserved the original edx-list/esi-cursor
//   prologue and improved structural coverage; assignment aliases alone were
//   codegen duplicates.
// - do/while and comma-guard rewrites reached a 524-byte/460-diff diagnostic
//   basin but introduced less natural guard blocks; the living source stays the
//   typed natural scan. A fresh member reread worsened size to 546 B and was
//   rolled back.
// - Removing the relink `next` temp improved exact-block coverage (93.53%) but
//   leaves the same structural 9-byte shortfall. Budget exhausted; retain this
//   readable source and leave the rewind loop/backedge as the next lead.
// Main-agent audit restored canonical polymorphic timeline/world/player/master
// and object ownership while retaining the natural forward/rewind scans.
// Session sa1-0050db10: binary vslot-0 + delete-flag calls require natural
// polymorphic delete; retained that behavior and restored the readable scan.
// Fresh worker probes (sa-011f8785-r1): mirrored update/sub type surfaces, then
// tested decompiler-supported rewind forms: comma-assigned next, explicit and
// do/while scans, for-header cursor updates, and a combined short-circuit
// condition. The best structural basin was 524B/460 diff but still had the
// wrong assignment/null-test order; restored the natural 520B source. The
// remaining blocker is the binary's redundant post-next null compare and the
// resulting rewind block spans; no further blind variants remain in this pass.
// Fresh replacement (orch-timeline-fresh-03): dossier confirms 4 calls, exact
// vslot +0x18 create calls and vslot 0 deleting-destructor calls; ABI query has
// no additional living declarations. Re-tested direct/comma assignment forms,
// explicit loop bodies, assignment-result continue, and direct n->time >
// old_time spellings; all landed in the same 524B/460-diff basin. A focused
// first-scan lab produced only 520B and 524B groups. A second lab was invalid
// for the intended two-region splice; its generated files are diagnostic only.
// A moving predecessor cursor (p/n) was a codegen duplicate. Restored the
// natural typed source: remaining structural gap is the VC5 redundant
// post-next null compare/move order at the first rewind scan and its shifted
// predecessor block; no source-quality justification remains for scaffolding.
// TU pass (tu-timeline-50DB10): reused the update function's typed timeline
// event/list ownership and four-call tail context. A separate next assignment
// plus post-assignment null test improved the diagnostic to 524B/460 diff, but
// VC5 still emitted compare-before-move and the source was less natural. Restored
// the clean 520B typed scan; the structural rewind blocker remains.

struct RGE_Static_Object { virtual ~RGE_Static_Object(); };
struct RGE_Master_Static_Object { virtual ~RGE_Master_Static_Object(); virtual void v4(); virtual void v8(); virtual void vc(); virtual void v10(); virtual void v14(); virtual RGE_Static_Object* create(void* player, int x, int y, int z); };
struct RGE_Player { virtual ~RGE_Player(); char gap_04[0x20]; RGE_Master_Static_Object** master_objects; };
struct RGE_World { virtual ~RGE_World(); char gap_04[0x3C]; RGE_Player** players; };

struct RGE_Time_Entry {
    float time;
    unsigned char command;
    char gap_05;
    short obj_type;
    unsigned char player;
    char gap_09[3];
    int x;
    int y;
    char gap_14[8];
    RGE_Static_Object* this_obj;
    short this_obj_id;
    char gap_22[2];
    RGE_Static_Object* target_obj;
    short target_obj_id;
    char gap_2A[2];
    RGE_Time_Entry* next;
};

class RGE_Timeline {
public:
    virtual ~RGE_Timeline();
    RGE_World* world;
    RGE_Time_Entry* time_list;
    char gap_0C[4];
    float old_time;
    void mock_update(float t);
};

void RGE_Timeline::mock_update(float t)
{
    RGE_Time_Entry* list;
    RGE_Time_Entry* e;
    RGE_Time_Entry* n;
    RGE_Static_Object* obj;

    if (t < old_time) {
        list = time_list;
        e = time_list;
        if (e != 0) {
            while (e->next != 0 && e->next->time <= old_time)
                e = e->next;
            while (e != 0) {
                if (e->time <= t) break;
                if (!(e->time > old_time)) {
                    switch (e->command) {
                    case 1:
                        obj = e->this_obj;
                        if (obj != 0) {
                            for (n = list; n != 0; n = n->next) {
                                if (obj == n->this_obj) n->this_obj = 0;
                                if (obj == n->target_obj) n->target_obj = 0;
                            }
                            if (obj != 0) delete obj;
                        }
                        break;
                    case 4:
                        {
                            RGE_Player* p = world->players[e->player];
                            RGE_Master_Static_Object* mo = p->master_objects[e->obj_type];
                            if (mo != 0) {
                                obj = mo->create(p, e->x, e->y, 0);
                                for (n = time_list; n != 0; n = n->next) {
                                    if (e->this_obj_id == n->this_obj_id) n->this_obj = obj;
                                    if (e->this_obj_id == n->target_obj_id) n->target_obj = obj;
                                }
                            }
                        }
                        break;
                    }
                }
                list = time_list;
                if (e == list) {
                    e = 0;
                } else {
                    n = list;
                    while (n != 0) {
                        if (n->next == e) e = n;
                        n = n->next;
                    }
                }
            }
        }
    }
    if (old_time < t) {
        e = time_list;
        while (e != 0) {
            if (e->time > old_time && !(e->time > t)) {
                switch (e->command) {
                case 1:
                    {
                        RGE_Player* p = world->players[e->player];
                        RGE_Master_Static_Object* mo = p->master_objects[e->obj_type];
                        if (mo != 0) {
                            obj = mo->create(p, e->x, e->y, 0);
                            for (n = time_list; n != 0; n = n->next) {
                                if (e->this_obj_id == n->this_obj_id) n->this_obj = obj;
                                if (e->this_obj_id == n->target_obj_id) n->target_obj = obj;
                            }
                        }
                    }
                    break;
                case 4:
                    obj = e->this_obj;
                    if (obj != 0) {
                        for (n = time_list; n != 0; n = n->next) {
                            if (obj == n->this_obj) n->this_obj = 0;
                            if (obj == n->target_obj) n->target_obj = 0;
                        }
                        if (obj != 0) delete obj;
                    }
                    break;
                }
            }
            e = e->next;
        }
    }
    old_time = t;
}
