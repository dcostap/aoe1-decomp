// RGE_Victory_Conditions::condition_description
// VA: 00532CC0
// Attempt log:
// - Baseline: reconstructed the binary-supported switch, typed entry/object/player/master
//   ownership, ten period strings, float-to-double varargs, and the getstring output slot.
//   Direct source was 532 bytes versus 479; the initial byte clear also missed the observed
//   whole-dword zero.
// - Whole-dword clear probe improved the direct source to 435 differing bytes; the PDB-sized
//   200-byte temporary still left a 0xC8 frame versus the original 0xCC.
// - A diagnostic 204-byte temporary recovered the original frame and 71.71% exact-block
//   coverage, but conflicts with the PDB's char[200] local and was not retained.
// - An explicit shared two-argument sprintf tail for cases 1/9 recovered exact size, call
//   count, and 100% call-site alignment (394 differing bytes); its generic format/argument
//   locals are compiler-steering scaffolding, so it was restored out of the living source.
// - Case-local destination/name/id declarations, return-type context, and typed shared-tail
//   target/index locals were codegen duplicates or worse.
// - Paused after 10 hypotheses: canonical direct switch source retained; remaining structural
//   gap is VC5 tail merging plus the jump-table/code-layout basin, with no call/ABI/layout
//   behavior defect. Best diagnostic checkpoint is probe-006-control-flow (394 bytes).
// - Main-agent audit removed the diagnostic +4 stack window and pointer-overlaid output slot.
//   The living source uses the declared text buffer and a separate result pointer.
// - New worker initialized a separate result pointer before the 200-byte buffer;
//   this recovered the original 0xCC frame and natural temp base, but the direct
//   switch still has one extra sprintf call from VC5 tail layout (433 bytes).
// - A shared text pointer was codegen-neutral. A behavior-correct common case-1/
//   case-9 tail using long varargs recovered exact size/frame/call count (394 bytes;
//   393 with proven absolute string addresses), but pointer-to-long argument
//   scaffolding is not retained as living source. Argument declaration reordering
//   was a duplicate; restore the clean typed direct switch.
// - Legacy sprintf format constness and return type were unchanged codegen.
// - &temp[0], an inlined two-argument helper, and a shared format pointer were
//   unchanged codegen. The clean typed direct switch remains the best source model.
// - Fresh worker evidence confirms case 6 pushes count before number; the source
//   now uses that binary-supported argument order. A stdio.h context was worse.
//   The remaining gap is the extra direct sprintf call for the two-argument
//   case-1/case-9 tail; no natural source form recovered that tail.

extern "C" int __cdecl sprintf(char* buffer, const char* format, ...);
extern "C" void __cdecl getstring(char** destination, char* source);

class RGE_Master_Static_Object {
public:
    virtual ~RGE_Master_Static_Object();
    char gap_04[4];
    char* name; // +0x08
};

class RGE_Player {
public:
    virtual ~RGE_Player();
    char gap_04[0x20];
    RGE_Master_Static_Object** master_objects; // +0x24
    char gap_28[0x22];
    short id; // +0x4A
};

class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    char gap_04[4];
    RGE_Master_Static_Object* master_obj; // +0x08
};

class RGE_Victory_Entry {
public:
    unsigned char command; // +0x00
    char gap_01[3];
    long obj_type; // +0x04
    RGE_Player* target_player; // +0x08
    float x0; // +0x0C
    float y0; // +0x10
    float x1; // +0x14
    float y1; // +0x18
    long number; // +0x1C
    long count; // +0x20
    RGE_Static_Object* this_obj; // +0x24
    RGE_Static_Object* target_obj; // +0x28
};

class RGE_Victory_Conditions {
public:
    virtual ~RGE_Victory_Conditions();
    virtual void handle_point_condition(void* entry);
    virtual void handle_condition(RGE_Victory_Entry* entry);
    virtual char* condition_description(RGE_Victory_Entry* entry);
    virtual void save(int handle);

    RGE_Victory_Entry* victory_list; // +0x04
    long list_num; // +0x08
};

char* RGE_Victory_Conditions::condition_description(RGE_Victory_Entry* entry) {
    char* description = 0;
    char temp[200];

    switch (entry->command) {
    case 0:
        sprintf(temp, "Capture %s", entry->this_obj->master_obj->name);
        break;
    case 1:
        sprintf(temp, "Create %d %s", entry->number,
            entry->target_player->master_objects[entry->obj_type]->name);
        break;
    case 8:
        sprintf(temp, "Create %d %s in area (%f, %f) - (%f, %f)",
            entry->number,
            entry->target_player->master_objects[entry->obj_type]->name,
            (double)entry->x0, (double)entry->y0,
            (double)entry->x1, (double)entry->y1);
        break;
    case 2:
        sprintf(temp, "Destroy %s", entry->this_obj->master_obj->name);
        break;
    case 3:
        sprintf(temp, "Destroy %d %s of player %d", entry->number,
            entry->target_player->master_objects[entry->obj_type]->name,
            entry->target_player->id);
        break;
    case 9:
        sprintf(temp, "Destroy all %s of player %d",
            entry->target_player->master_objects[entry->obj_type]->name,
            entry->target_player->id);
        break;
    case 4:
        sprintf(temp, "Bring %s to area (%f, %f) - (%f, %f)",
            entry->this_obj->master_obj->name,
            (double)entry->x0, (double)entry->y0,
            (double)entry->x1, (double)entry->y1);
        break;
    case 5:
        sprintf(temp, "Bring %s to %s",
            entry->this_obj->master_obj->name,
            entry->target_obj->master_obj->name);
        break;
    case 6:
        sprintf(temp, "aqquire %d of attribute %d", entry->count,
            entry->number);
        break;
    case 7:
        sprintf(temp, "explore %d percent of the map", entry->count);
        break;
    }

    getstring(&description, temp);
    return description;
}
