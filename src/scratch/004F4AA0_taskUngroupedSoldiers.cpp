// Attempt log for 004F4AA0 TribeTacticalAIModule::taskUngroupedSoldiers
// try 1: natural reconstruction from packet/decompiler, local managed-array surface; builds 736B vs 740B, close but size stop.
// try 2: /Oy- probe; too small 720B.
// try 3: /O1 probe; too small 675B.
// try 4: reviewed timer magic multiply; source matches observed threshold behavior.
// try 5: reviewed groupUnitIsIn removal path; broad behavior follows packet.
// try 6: reviewed missing/duplicate tasked-list membership scans; source likely too high-level.
// try 7: reviewed ungrouped resize manual allocation path; close but not exact array helper shape.
// try 8: reviewed finder call args/stack locals; local point ordering uncertain.
// try 9: reviewed taskSoldier FPU argument order; likely drift.
// try 10: left in scratch; near-size scaffold but not exact.
// BLOCKER: rebuilt .text 736B vs original 740B; missing exact managed-array resize/membership scan source shape and finder/taskSoldier stack/FPU scheduling. Not accepted_drift-safe.

typedef unsigned char uchar;
class RGE_Static_Object { public: char pad[0x38]; float x; float y; };
class MainDecisionAIModule { public: char pad[0xf0]; void* md; RGE_Static_Object* object(int,int,int,int,int,int,int,int,int,int); RGE_Static_Object* object(int); };
class ManagedArray { public: int* data; int count; int cap; int resize(int); };
class TribeTacticalAIModule { public: char pad[0xf0]; MainDecisionAIModule* md; char padf4[0x20]; ManagedArray ungrouped; ManagedArray tasked; char pad134[0xE8]; int field1ec; char pad1f0[0xC4]; int field2b4; char pad2b8[0xcf0]; int last_time; void* groupUnitIsIn(int); void taskUngroupedSoldiers(); void taskSoldier(int,float,float,int); };
class Finder { public: int find(int*,int,int*,int,int*,int,int*,int); };
extern "C" long __cdecl _ftol(void);

void TribeTacticalAIModule::taskUngroupedSoldiers()
{
    int i;
    RGE_Static_Object* soldierObj;
    int centerPoint_y, gatherPoint_x;
    int centerPoint_x, gatherPoint_y;
    int now = *(int*)(*(int*)(*(int*)((char*)this->md + 0xf0) + 0x3c) + 4);
    if ((unsigned)(((now - this->last_time) * 0x10624dd3) >> 6) < 60) return;
    RGE_Static_Object* center = this->md->object(-1,0x6d,-1,-1,-1,-1,-1,-1,-1,-1);
    this->last_time = now;
    if (!center) return;
    centerPoint_y = (int)center->x;
    gatherPoint_x = (int)center->y;
    if (this->ungrouped.count <= 0) return;
    for (i = 0; i < this->ungrouped.count; ++i) {
        if (i > this->ungrouped.cap - 1) this->ungrouped.resize(i+1);
        int unit = this->ungrouped.data[i];
        if (this->groupUnitIsIn(unit)) {
            int j=0;
            while (j < this->tasked.count && this->tasked.data[j] != unit) ++j;
            if (j < this->tasked.count) {
                for (++j; j < this->tasked.count; ++j) this->tasked.data[j-1] = this->tasked.data[j];
                if (--this->tasked.count < 0) this->tasked.count = 0;
            }
            continue;
        }
        soldierObj = this->md->object(unit);
        centerPoint_x = (int)soldierObj;
        if (!soldierObj) continue;
        int k=0; bool found=false;
        while (k < this->tasked.count && k < this->tasked.cap) { if (this->tasked.data[k] == unit) { found=true; break; } ++k; }
        if (found) continue;
        if (i > this->ungrouped.cap - 1) {
            int newCount=i+1; int* arr=(int*)operator new(newCount*4); if (arr) { for(int n=0;n<this->ungrouped.count && n<newCount;n++) arr[n]=this->ungrouped.data[n]; operator delete(this->ungrouped.data); this->ungrouped.data=arr; this->ungrouped.cap=newCount; }
        }
        unit = this->ungrouped.data[i];
        k=0; found=false; while(k<this->tasked.count && k<this->tasked.cap){ if(this->tasked.data[k]==unit){found=true;break;} ++k; }
        if (!found) { if (this->tasked.count > this->tasked.cap-1) this->tasked.resize(this->tasked.count+1); this->tasked.data[this->tasked.count++] = unit; }
        Finder* f=(Finder*)((char*)this->md + 0xcec);
        if (f->find(&centerPoint_y,1,&centerPoint_x,1,&this->field1ec,this->field2b4,&gatherPoint_y,unit)==1) {
            if (i > this->ungrouped.cap-1) this->ungrouped.resize(i+1);
            this->taskSoldier(this->ungrouped.data[i],(float)gatherPoint_y,(float)centerPoint_x,0x32);
        }
    }
}
