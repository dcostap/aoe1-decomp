// 004D6BB0 TribeInformationAIModule::TribeInformationAIModule
// FLAGS: config/flags/004D6BB0_TribeInformationAIModule.rsp (/GX for original constructor EH frame)
// Attempt log:
// 1: raw-offset constructor reconstruction from packet; model base ctor, InfluenceMap ctor, operator new allocations and fill loops.
// 2: added /GX and <string.h>; reached same 1182-byte size after forcing repeated member-pointer reloads in allocation fill loops.
// 3: first mismatch remains early EH/member-constructor shape: original stores EH state [esp+1C]=0 after base ctor, later state 5 before InfluenceMap ctor and state 8 before first operator new; raw placement-new emits a null check and no EH state stores.
// 4: likely needs a real typed class layout with scalar member initializers before an InfluenceMap member at +0x158 so VC5 emits constructor-unwind state transitions naturally; current raw-offset version is not accepted_drift (broad shifted diff, wrong EH bookkeeping/control around member ctor).

#include <string.h>

typedef unsigned char uchar;

void* __cdecl operator new(unsigned int size);
inline void* operator new(unsigned int, void* p) { return p; }

class AIModule { public: virtual ~AIModule(); AIModule(char*, int, int, void*); };
class InformationAIModule : public AIModule { public: InformationAIModule(void* p, int v); virtual ~InformationAIModule(); };
class InfluenceMap { public: InfluenceMap(int, int, int); };

class __declspec(novtable) TribeInformationAIModule : public InformationAIModule {
public:
    char bytes[0x560 - sizeof(InformationAIModule)];
    TribeInformationAIModule(void* p, int v);
};

#define I(off) (*(int*)((char*)this + (off)))
#define S(off) (*(short*)((char*)this + (off)))
#define B(off) (*(uchar*)((char*)this + (off)))
#define P(off) (*(void**)((char*)this + (off)))

TribeInformationAIModule::TribeInformationAIModule(void* p, int v)
    : InformationAIModule(p, v)
{
    int z = 0;
    I(0x0F0)=z; I(0x0F4)=z; I(0x0F8)=z; I(0x0FC)=z; I(0x100)=z;
    I(0x104)=-1; I(0x108)=-1; I(0x10C)=z; I(0x110)=500;
    I(0x118)=z; I(0x11C)=z; I(0x120)=z; I(0x124)=z;
    I(0x128)=z; I(0x12C)=z; I(0x130)=z; I(0x134)=z;
    I(0x138)=z; I(0x13C)=z; I(0x140)=z; I(0x144)=z;
    I(0x148)=z; I(0x14C)=z; I(0x150)=z; I(0x154)=z;

    new ((void*)((char*)this + 0x158)) InfluenceMap(0xfe, 0xfe, 0xff);

    I(0x180)=z; I(0x184)=z; I(0x188)=z; I(0x18C)=z;
    I(0x190)=z; I(0x194)=z; I(0x198)=z; I(0x19C)=z;
    I(0x1F4)=200; I(0x1FC)=25; I(0x204)=z; I(0x560)=z;
    *(void**)this = (void*)0x575510;

    strcpy((char*)this + 0xFF90, (const char*)0x5878BC);

    P(0x4C8) = operator new(0x10);
    P(0x4CC) = operator new(0x10);
    for (int off=0; off<0x10; off+=4) {
        *(int*)((char*)P(0x4CC)+off)=0;
        *(int*)((char*)P(0x4C8)+off)=0;
    }

    memset((char*)this + 0xFF64, 0, 0x2c);
    memset((char*)this + 0x564, 0, 0xFA00);

    int* a = (int*)((char*)this + 0x510);
    for (int i=0;i<4;i++,a++) { a[-4]=0; a[0]=1; a[4]=1; a[8]=1; }
    int* b = (int*)((char*)this + 0x550);
    for (int j=0;j<4;j++,b++) { b[-4]=-1; b[0]=-1; }

    P(0x114) = operator new(I(0x110) * 0x24);
    if (P(0x114) != 0 && I(0x110) > 0) {
        int off=0;
        for (int k=0;k<I(0x110);k++, off+=0x24) {
            *(int*)((char*)P(0x114)+off+0)=-1;
            *(short*)((char*)P(0x114)+off+4)=-1;
            *(short*)((char*)P(0x114)+off+6)=-1;
            *((char*)P(0x114)+off+8)=0;
            *((char*)P(0x114)+off+9)=0;
            *((char*)P(0x114)+off+10)=0;
            *((char*)P(0x114)+off+11)=0;
            *(short*)((char*)P(0x114)+off+12)=0;
            *(int*)((char*)P(0x114)+off+0x10)=0;
            *((char*)P(0x114)+off+0x14)=0;
            *(int*)((char*)P(0x114)+off+0x18)=0;
            *(int*)((char*)P(0x114)+off+0x1c)=0;
            *(int*)((char*)P(0x114)+off+0x20)=0;
        }
    }

    P(0x1F8) = operator new(I(0x1F4) * 8);
    if (P(0x1F8) != 0 && I(0x1F4) > 0) {
        int k;
        for (k=0;k<I(0x1F4);k++) {
            char* q=(char*)P(0x1F8)+k*8;
            *(int*)q=-1; q[5]=0; q[6]=0; q[4]=0;
        }
    }

    P(0x200) = operator new(I(0x1FC) * 0x18);
    if (P(0x200) != 0 && I(0x1FC) > 0) {
        int off=0;
        int k;
        for (k=0;k<I(0x1FC);k++, off+=0x18) {
            *(int*)((char*)P(0x200)+off+0)=-1;
            *(int*)((char*)P(0x200)+off+0)=-1;
            *((char*)P(0x200)+off+5)=0;
            *((char*)P(0x200)+off+6)=0;
            *((char*)P(0x200)+off+7)=0;
            *((char*)P(0x200)+off+8)=0;
            *((char*)P(0x200)+off+9)=0xff;
            *((char*)P(0x200)+off+10)=0xff;
            *(short*)((char*)P(0x200)+off+12)=0;
            *((char*)P(0x200)+off+14)=0;
            *(int*)((char*)P(0x200)+off+0x14)=-1;
        }
    }

    I(0x1A0)=-1; I(0x1A4)=-1; I(0x1A8)=-1; I(0x1AC)=-1; I(0x1B0)=-1;
    int* c=(int*)((char*)this+0x1B8);
    for (int k=0;k<4;k++, c+=2) { c[-1]=-1; c[0]=-1; c[7]=-1; c[8]=-1; }

    memset((char*)this + 0x308, 0, 0xFF);

    int* d=(int*)((char*)this+0x410);
    for (int y=0;y<4;y++) {
        for (int x=0;x<4;x++, d+=3) { d[-2]=0; d[-1]=0; d[0]=0; }
    }

    int* e=(int*)((char*)this+0x4F0);
    for (k=0;k<4;k++, e++) { e[-8]=0; e[0]=0; e[-4]=0; }
}
