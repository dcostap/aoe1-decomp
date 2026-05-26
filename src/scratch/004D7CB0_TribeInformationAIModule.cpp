// VA: 004D7CB0 TribeInformationAIModule::~TribeInformationAIModule
// PDB source: taiinfmd.cpp
// Attempt log:
// - broad destructor reconstruction from packet: set vptr, optionally serialize several arrays/records, then free many owned dynamic arrays and call base destructor.
// - used /GX because original destructor has EH registration/unwind states for subobject destruction.
// - /O2 /Oy /GX compiles but .text is 896 bytes vs target 1472, too short for extraction; broad helper factoring collapses many original inline loops.
// - tried /Od /Oy- /GX diagnostically: 1361 bytes, still too short and wrong frame/codegen family.
// - restored /O2 /Oy /GX. Give-up: needs exact class layout/subobject destructors and original hand-inlined serialization/free loop shapes; no accepted_drift proposed.

extern void operator delete(void*);
extern int open_save(void*, int, int);
extern void write_save(int, void*, int);
extern void close_save(int);

struct Base { virtual ~Base(); };
class TribeInformationAIModule_4D7CB0 : public Base {
public:
    char gap4[0xf0-4]; void* a0; int n0,c0,k0; void* a1; int n1,c1,k1; void* a2; int n2,c2,k2; void* a3; int n3,c3,k3; void* big; char gap1a0[0x1f8-0x1a0]; void* arr200; int cnt1; char path[0x180]; void* table4c8; void* ptr4cc; void* p4d0; void* p4d4; void* p4d8; void* p4dc; int c4f0,c4f4,c4f8,c4fc; void* d4d0[4];
    ~TribeInformationAIModule_4D7CB0();
};

static void delp(void*& p){ if(p){ operator delete(p); p=0; } }
static void save_records(int f, char* base, int count, int stride, int kind){ int n=0; for(int i=0;i<count;i++) if(*(int*)(base+i*stride)!=-1 && (kind==0 || *(short*)(base+i*stride+4)==0x6d)) n++; write_save(f,&n,4); for(i=0;i<count;i++) if(*(int*)(base+i*stride)!=-1 && (kind==0 || *(short*)(base+i*stride+4)==0x6d)) write_save(f,base+i*stride,stride); }

TribeInformationAIModule_4D7CB0::~TribeInformationAIModule_4D7CB0()
{
    *(int*)this = 0x575510;
    if (table4c8) { void** t=(void**)table4c8; for(int i=0;i<4;i++) operator delete(t[i]); operator delete(table4c8); }
    operator delete(ptr4cc);
    if (cnt1==1) {
        int f=open_save(path,0x8301,0x180);
        if (f!=-1) {
            write_save(f,(char*)this+0x104,4); write_save(f,(char*)this+0x108,4);
            save_records(f,(char*)arr200,*(int*)((char*)this+0x1fc),0x18,0);
            save_records(f,(char*)a1,n1,0x24,1);
            int* counts=&c4f0; for(int j=0;j<4;j++){ write_save(f,&counts[j],4); write_save(f,(char*)this+0x4e0+j*4,4); if(counts[j]) write_save(f,*(void**)((char*)this+0x4d0+j*4),counts[j]*20); }
            int tmp=n2; write_save(f,&tmp,4); for(j=0;j<n2;j++) write_save(f,(char*)a2+j*4,4);
            tmp=n3; write_save(f,&tmp,4); for(j=0;j<n3;j++) write_save(f,(char*)a3+j*4,4);
            close_save(f);
        }
    }
    operator delete(a1); operator delete(big); operator delete(arr200);
    for(int k=0;k<4;k++) { if(d4d0[k]) { operator delete(d4d0[k]); d4d0[k]=0; } }
    delp(a3); n3=c3=k3=0; delp(a2); n2=c2=k2=0; delp(a1); n1=c1=k1=0; delp(a0); n0=c0=k0=0;
}
