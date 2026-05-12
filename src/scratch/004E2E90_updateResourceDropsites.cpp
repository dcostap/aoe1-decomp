// VA: 004E2E90 TribeInformationAIModule::updateResourceDropsites
// PDB: taiinfmd.cpp:7471-7527 (397 bytes, 110 asm lines)
// Default flags. No inline asm/hacks.

struct RGE_Static_Object {
    void* vtable;
    int id;
    void* master_obj;
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
    char* resources[4];
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

    int cnt = this->numResources[idx];
    if (cnt <= 0)
        return;

    char* base = this->resources[idx];
    int byte_off = 0;

    for (int i = 0; i < cnt; i++) {
        char* p = base + byte_off;

        if (p[0x0D] != 1) {
            int obj_id = *(int*)p;
            RGE_Static_Object* obj = this->md->object(obj_id);

            if (obj != 0) {
                int out_id = -1;
                float dist = this->findClosestDropsite(obj, 1, &out_id);

                int val = (int)(_flt_5755BC - _flt_5755B8 * dist);
                *(int*)(p + 8) = val;
                p[0x0E] = (unsigned char)(int)dist;
                *(int*)(p + 0x10) = out_id;

                int grp = *(short*)((char*)obj->master_obj + 0x14);

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

        byte_off += 0x14;
    }
}
