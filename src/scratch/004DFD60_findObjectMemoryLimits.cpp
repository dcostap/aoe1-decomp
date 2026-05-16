// 004DFD60 TribeInformationAIModule::findObjectMemoryLimits
// scratch give-up: natural reconstruction compiles to exact length 731 but remains broad mismatch
// (86.59% positional / 73.32% edit, first mismatch frame 0x44 vs original 0x3c).
// Behavior/call surface is reconstructed from packet; persistent gaps are stack-local packing,
// EBX/ESI this-vs-zero allocation, and ObjectMemory byte/word zero-init shape. Fixed ftol source
// to casts and corrected vf10c vtable slot to +0x10c; no exact basin found in this pass.

typedef unsigned char uchar;

struct ObjectMemory {
    int id;              // +00 also used as max distance result in return struct
    short type;          // +04
    short group;         // +06
    uchar x;             // +08
    uchar y;             // +09
    uchar z;             // +0A
    uchar owner;         // +0B
    short hitPoints;     // +0C
    short pad0e;         // +0E
    int attackAttempts;  // +10
    uchar kills;         // +14
    char pad15[3];
    float damageCapability; // +18
    float rateOfFire;       // +1C
    float range;            // +20
};

struct RGE_Static_Object;
struct RGE_Visible_Map { uchar get_visible(int x, int y); };
struct MainDecisionAIModule { char pad[0xF0]; void* map_holder; RGE_Static_Object* object(int id); };

struct RGE_Static_Object {
    virtual void pad000(); virtual void pad004(); virtual void pad008(); virtual void pad00c();
    virtual void pad010(); virtual void pad014(); virtual void pad018(); virtual void pad01c();
    virtual void pad020(); virtual void pad024(); virtual void pad028(); virtual void pad02c();
    virtual void pad030(); virtual void pad034(); virtual void pad038(); virtual void pad03c();
    virtual void pad040(); virtual void pad044(); virtual void pad048(); virtual void pad04c();
    virtual void pad050(); virtual void pad054(); virtual void pad058(); virtual void pad05c();
    virtual void pad060(); virtual void pad064(); virtual void pad068(); virtual void pad06c();
    virtual void pad070(); virtual void pad074(); virtual void pad078(); virtual void pad07c();
    virtual void pad080(); virtual void pad084(); virtual void pad088(); virtual void pad08c();
    virtual void pad090(); virtual void pad094(); virtual void pad098(); virtual void pad09c();
    virtual void pad0a0(); virtual void pad0a4(); virtual void pad0a8(); virtual void pad0ac();
    virtual void pad0b0(); virtual void pad0b4(); virtual void pad0b8(); virtual void pad0bc();
    virtual void pad0c0(); virtual void pad0c4(); virtual void pad0c8(); virtual void pad0cc();
    virtual void pad0d0(); virtual void pad0d4(); virtual void pad0d8(); virtual void pad0dc();
    virtual void pad0e0(); virtual void pad0e4(); virtual void pad0e8(); virtual void pad0ec();
    virtual void pad0f0(); virtual void pad0f4(); virtual void pad0f8(); virtual void pad0fc();
    virtual void pad100(); virtual void pad104(); virtual void pad108();
    virtual float vf10c(int* pt);
    char gap004[0x34];
    float x; // +38
    float y; // +3c
    uchar currentZone();
    int withinRangeOfZoneAtPoint(uchar zone, float dist, int* pt);
    float distance_to_position(float x, float y, float z);
};

struct TribeInformationAIModule {
    char pad000[0x100];
    MainDecisionAIModule* md;
    char pad104[0x0c];
    int maxImportantObjectMemory;
    ObjectMemory* importantObjectMemory;
    ObjectMemory findObjectMemoryLimits(int owner, int object_id, int& a, int& b);
};

ObjectMemory TribeInformationAIModule::findObjectMemoryLimits(int owner, int object_id, int& c1, int& c2)
{
    ObjectMemory rVal;
    float maxRange;
    RGE_Static_Object* target;
    RGE_Static_Object* obj;
    int i;
    int offset;
    uchar zone;
    int pt[2];
    int ix;
    int iy;
    int dx;
    int dy;
    ObjectMemory* mem;
    float dist;

    c1 = 0;
    c2 = 0;
    rVal.id = 0;
    rVal.type = 0;
    rVal.group = 0;
    rVal.x = 0;
    rVal.y = 0;
    rVal.z = 0;
    rVal.owner = 0;
    rVal.hitPoints = 0;
    rVal.pad0e = 0;
    rVal.attackAttempts = 0;
    rVal.kills = 0;
    rVal.pad15[0] = rVal.pad15[1] = rVal.pad15[2] = 0;
    rVal.damageCapability = 0.0f;
    rVal.rateOfFire = 0.0f;
    maxRange = 0.0f;

    target = this->md->object(object_id);
    if (target != 0) {
        zone = target->currentZone();
        i = 0;
        if (this->maxImportantObjectMemory > 0) {
            offset = 0;
            do {
                mem = (ObjectMemory*)((char*)this->importantObjectMemory + offset);
                if ((int)mem->owner == owner) {
                    obj = this->md->object(mem->id);
                    if (obj != 0) {
                        if (zone != obj->currentZone()) {
                            pt[0] = (int)obj->x;
                            pt[1] = (int)obj->y;
                            dist = target->vf10c(pt);
                            if (target->withinRangeOfZoneAtPoint(zone, dist, pt) != 1)
                                goto next;
                        }
                        obj = this->md->object(mem->id);
                        if (obj != 0) {
                            mem = (ObjectMemory*)((char*)this->importantObjectMemory + offset);
                            ix = (int)obj->x;
                            dx = (int)mem->x - ix;
                            if (dx < 0) dx = -dx;
                            iy = (int)obj->y;
                            dy = (int)mem->y - iy;
                            if (dy < 0) dy = -dy;
                            if ((dx > 5 || dy > 5) && ((RGE_Visible_Map*)(*(int*)(*(int*)((char*)this->md + 0xF0) + 0x38)))->get_visible(ix, iy) != 0x0F)
                                goto skip_visible;
                            if (mem->group != 3 && mem->group != 0x1B) c1++;
                            if (mem->group != 2 && mem->group != 0x15 && mem->group != 0x16 && mem->group != 0x14 && mem->type != 0x2D) c2++;
                            dist = target->distance_to_position((float)(int)mem->x, (float)(int)mem->y, (float)(int)mem->z);
                            if ((float)rVal.id < dist) rVal.id = (int)dist;
                            if (rVal.hitPoints < mem->hitPoints) rVal.hitPoints = mem->hitPoints;
                            if (mem->attackAttempts > 0) rVal.hitPoints = (short)mem->attackAttempts;
                            if (mem->kills != 0) rVal.hitPoints = (unsigned short)mem->kills;
                            if (rVal.damageCapability < mem->damageCapability) rVal.damageCapability = mem->damageCapability;
                            if (rVal.rateOfFire < mem->rateOfFire) rVal.rateOfFire = mem->rateOfFire;
                            if (maxRange < mem->range) maxRange = mem->range;
                        }
                    }
                }
skip_visible:
next:
                i++;
                offset += 0x24;
            } while (i < this->maxImportantObjectMemory);
        }
    }
    return rVal;
}
