// VA: 004E2E90 TribeInformationAIModule::updateResourceDropsites
// PDB: taiinfmd.cpp:7471-7527 (397 bytes, 110 asm lines)
// Default flags. No inline asm/hacks.
// Attempt log:
// baseline: direct typed resource scan with cached count/base and a for-loop;
//   calls aligned, but the index died before the loop and VC5 omitted EBP,
//   duplicated the count guard, and selected a pointer-walk basin (361 bytes).
// probe 2: restore the same-TU direct-expression/do-while scan shape: keep the
//   incoming index live through the loop condition, use one byte offset, and
//   reread resources[idx] at each proven record access.
// probe 3: model the proven RGE_Master_Static_Object vptr and +0x14
//   object_group field; this closed the final one-byte field-offset mismatch.

struct RGE_Master_Static_Object {
    void* vtable;
    char gap04[0x10];
    short object_group;
};

struct RGE_Static_Object {
    char gap0[0x04];
    int id;
    RGE_Master_Static_Object* master_obj;
};

struct ResourceMemory {
    int id;
    unsigned char x;
    unsigned char y;
    unsigned char gatherAttempts;
    unsigned char gap07;
    int gatherValue;
    unsigned char valid;
    unsigned char gone;
    unsigned char dropDistance;
    unsigned char resourceType;
    int dropsiteID;
};

extern float _flt_5755B8;
extern float _flt_5755BC;

struct MainDecisionAIModule {
    RGE_Static_Object* object(int id);
};

struct TribeInformationAIModule {
    char gap0[0x100];
    MainDecisionAIModule* md;
    char gap104[0x3CC];
    ResourceMemory* resources[4];
    int numResources[4];
    char gap4F0[0x50];
    int bestdv[4];
    int bestid[4];

    float findClosestDropsite(RGE_Static_Object* obj, int mode, int* outId);
    void updateResourceDropsites(int idx);
};

void TribeInformationAIModule::updateResourceDropsites(int idx) {
    this->bestdv[idx] = -1;
    this->bestid[idx] = -1;

    int i = 0;
    int byte_off = 0;

    if (this->numResources[idx] > 0) {
        do {
            if (*(unsigned char*)((char*)this->resources[idx] + byte_off + 0x0D) != 1) {
                int obj_id = *(int*)((char*)this->resources[idx] + byte_off);
                RGE_Static_Object* obj = this->md->object(obj_id);

                if (obj != 0) {
                    int out_id = -1;
                    float dist = this->findClosestDropsite(obj, 1, &out_id);

                    int val = (int)(_flt_5755BC - _flt_5755B8 * dist);
                    *(int*)((char*)this->resources[idx] + byte_off + 8) = val;
                    *(unsigned char*)((char*)this->resources[idx] + byte_off + 0x0E) =
                        (unsigned char)(int)dist;
                    *(int*)((char*)this->resources[idx] + byte_off + 0x10) = out_id;

                    int grp = obj->master_obj->object_group;

                    if (grp == 0x0F) {
                        int v = (int)dist;
                        if (v < this->bestdv[1] || this->bestdv[1] == -1) {
                            this->bestdv[1] = v;
                            this->bestid[1] = obj->id;
                        }
                    } else if (grp == 0x20) {
                        int v = (int)dist;
                        if (v < this->bestdv[3] || this->bestdv[3] == -1) {
                            this->bestdv[3] = v;
                            this->bestid[3] = obj->id;
                        }
                    } else if (grp == 8) {
                        int v = (int)dist;
                        if (v < this->bestdv[2] || this->bestdv[2] == -1) {
                            this->bestdv[2] = v;
                            this->bestid[2] = obj->id;
                        }
                    } else if (grp == 7) {
                        int v = (int)dist;
                        if (v < this->bestdv[0] || this->bestdv[0] == -1) {
                            this->bestdv[0] = v;
                            this->bestid[0] = obj->id;
                        }
                    }
                }
            }

            i++;
            byte_off += 0x14;
        } while (i < this->numResources[idx]);
    }
}
