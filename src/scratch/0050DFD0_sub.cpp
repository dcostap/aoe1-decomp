// VA: 0050DFD0 RGE_Timeline::sub(RGE_Time_Entry*) (100 B)
// PDB source: Timeline.cpp lines 499-530
// Attempt log (orch-w2):
// 1 (baseline): while (p != entry) + inner if (p==0) return -> rotated loop with shared
//   exit, EBX save, folded dup guard (92B/98).
// 2 (control-flow): while (p != 0) { if (p == entry) break; ... } -> folded dup guard,
//   shared not-found exit, EBX save (90B).
// 3 (control-flow): compound-cond for + post if (p==0) return -> extra redundant post-test
//   and found path runs through it (55.81% blocks).
// 4 (control-flow): if (p == 0) return; INSIDE compound-cond for body -> loop rotation now
//   matches original (head cmp / bottom test jne head / inline not-found epilogue); remaining:
//   EBX save (entry kept live in EAX across loop), lea edx vs lea ecx, je else vs je join.
// 5 (liveness): duplicate this->sub(entry) in BOTH command arms + volatile stack-home read on
//   the else path -> EBX eliminated, register family matches, loop matches; 96B/86 diff
//   shape 95.35%; only missing 4-byte second guard test (504/509 fold).
// 6 (liveness): find copy for loop compare regressed (94B); rolled back.
// 7 (control-flow): outer guard on member (this->time_list) folded identically; rolled back.
// 8 (control-flow): member in for-cond regressed (104B, EBX); rolled back.
// 9 (control-flow): while+break+post-check -> right rotation but shared not-found exit (95B).
// 10 (restore): restored the best source (probe 6): compound-cond for with inner return,
//   duplicated sub(entry) call + volatile stack-home read on the else path. 96B / 86 diff /
//   95.35% shape / 76.74% blocks / edit-diff 11. EVERYTHING matches the original except the
//   redundant second guard test (test esi,esi; je) at +0x0E (line 509) - a 4-byte /Og
//   redundant-branch elimination artifact: ~35 harness experiments (nested ifs, &&, comma,
//   member reads, goto, while-wrap, for-header, for(;;), do-while, /O1 /G5 /G6 /GX /Og-
//   flags) all fold the duplicate guard; /Og- keeps it but destroys the rest of the codegen.
//
// Key findings this session:
// - Loop rotation requires the COMPOUND cond: for (; p != 0 && p != entry; ) with
//   if (p == 0) return; INSIDE the body -> head cmp / bottom test jne head / inline
//   not-found epilogue. Single-cond while/for/for(;;) forms rotate differently
//   (bottom cmp re-test + shared not-found exit) and never match.
// - Register family (link=eax, &time_list=ecx, entry=edx, no EBX) requires the
//   DUPLICATED this->sub(entry) call in both command arms PLUS a forced stack-home
//   reload of the param on the else path (mov eax,[esp+0Ch]). Without the forced
//   reload VC5 keeps entry live in a register across the loop and saves EBX for the
//   unlink temp (the original kills entry at the unlink, reusing edx for p->next).
// - The volatile read only reproduces the binary-proven else-path stack reload; it
//   is a codegen steer for the observed mov eax,[esp+0Ch], not a semantic claim.

#include <stdlib.h>

class RGE_Game_World;
class RGE_Static_Object;

struct RGE_Time_Entry {
    float time;                    // +0x00
    unsigned char command;         // +0x04
    unsigned char gap_05[1];       // +0x05
    short obj_type;                // +0x06
    unsigned char player;          // +0x08
    unsigned char gap_09[3];       // +0x09
    float x;                       // +0x0C
    float y;                       // +0x10
    float z;                       // +0x14
    short task;                    // +0x18
    unsigned char gap_1A[2];       // +0x1A
    void* this_obj;                // +0x1C
    short this_obj_id;             // +0x20
    unsigned char gap_22[2];       // +0x22
    void* target_obj;              // +0x24
    short target_obj_id;           // +0x28
    unsigned char gap_2A[2];       // +0x2A
    RGE_Time_Entry* next;          // +0x2C
};

class RGE_Timeline {
public:
    RGE_Timeline(RGE_Game_World* world);
    RGE_Timeline(int handle, RGE_Game_World* world);
    virtual ~RGE_Timeline();
    RGE_Game_World* world;         // +0x04
    RGE_Time_Entry* time_list;     // +0x08
    short list_num;                // +0x0C
    short avail_id;                // +0x0E
    float old_time;                // +0x10

    RGE_Time_Entry* add(float time);
    RGE_Time_Entry* add_attack(float time, RGE_Static_Object* this_obj,
                                RGE_Static_Object* target_obj);
    RGE_Time_Entry* add_create(float time, short obj_type, unsigned char player,
                                float x, float y, float z);
    RGE_Time_Entry* add_delete(float time, RGE_Static_Object* this_obj);
    RGE_Time_Entry* add_move(float time, RGE_Static_Object* this_obj,
                             float x, float y, float z);
    short find_id(RGE_Static_Object* obj);
    void mock_update(float time);
    void save(int handle);
    void sub(RGE_Time_Entry* entry);
    void update();
};

void RGE_Timeline::sub(RGE_Time_Entry* entry) {
    RGE_Time_Entry* p = this->time_list;
    RGE_Time_Entry** link = &this->time_list;
    if (p != 0) {
        for (; p != 0 && p != entry; ) {
            link = &p->next;
            p = p->next;
            if (p == 0)
                return;
        }
        *link = p->next;
        if (p->command == 1) {
            entry = this->time_list;
            while (entry != 0)
                entry = entry->next;
            this->sub(entry);
        } else {
            this->sub(*(RGE_Time_Entry* volatile*)&entry);
        }
        free(p);
        this->list_num--;
    }
}
