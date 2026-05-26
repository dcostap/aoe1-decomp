// 004E2490 addResourceObject - rough reconstruction
// Attempts:
// - Modeled resource bucket classification from master type (0x0f=>1, 0x08=>2, 0x20=>3 else 0), dynamic 20-byte entry array resize/copy/default-fill, and insertion/update branching at a high level.
// - Packet shows exact 20-byte struct copy/default initialization followed by many resource-type-specific cases. This compact source is only a behavioral notebook.
// - Current compile is far too small (.text 560 vs original 1392); missing most branch-specific resource influence bookkeeping from lines 7224-7336 and exact copy/fill topology.
// - Not accepted-drift quality.
extern "C" void* __cdecl operator_new(unsigned int); extern "C" void __cdecl operator_delete(void*);
struct Master { char pad[0x14]; short type; };
struct Obj { char pad[8]; Master* master; char padc[0x2c]; float x; float y; int id; };
struct ResEntry { int id; unsigned char a,b,c; int amount; unsigned char e,f,g,h; int other; };
class TribeInformationAIModule { public: char pad[0x4d0]; ResEntry* lists[4]; int counts[4]; int caps[4]; void addResourceObject(Obj*); };
static void init_entry(ResEntry* e){ e->id=-1; e->a=e->b=e->c=0; e->amount=0xff; e->e=e->f=0; e->g=e->h=0xff; e->other=-1; }
void TribeInformationAIModule::addResourceObject(Obj* obj){
    short t=obj->master->type; int bucket; if(t==0x0f) bucket=1; else if(t==8) bucket=2; else { bucket=(t!=0x20); bucket--; bucket&=3; }
    int n=counts[bucket], cap=caps[bucket]; ResEntry* arr=lists[bucket];
    if(n==cap || !arr){ int newcap=cap?cap*2:100; ResEntry* na=(ResEntry*)operator_new(newcap*20); if(!na)return; int i; for(i=0;i<n;i++) na[i]=arr[i]; for(;i<newcap;i++) init_entry(&na[i]); if(arr) operator_delete(arr); lists[bucket]=na; caps[bucket]=newcap; arr=na; }
    int idx=-1; for(int i=0;i<counts[bucket];i++) if(arr[i].id==obj->id){ idx=i; break; }
    if(idx<0){ idx=counts[bucket]++; init_entry(&arr[idx]); arr[idx].id=obj->id; }
    arr[idx].a=(unsigned char)bucket; arr[idx].amount=0xff; arr[idx].other=-1;
    switch(t){ case 0x0f: arr[idx].b=1; break; case 8: arr[idx].b=2; break; case 0x20: arr[idx].b=3; break; default: arr[idx].b=0; break; }
}
