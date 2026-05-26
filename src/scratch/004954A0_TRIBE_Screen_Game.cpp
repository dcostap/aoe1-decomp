// 004954A0 ~TRIBE_Screen_Game - destructor reconstruction attempt
// FLAGS: config/flags/004954A0_TRIBE_Screen_Game.rsp (/GX for original EH destructor frame)
// Attempts:
// - Modeled vptr restore, global UI cleanup, p7B8/p680 special cleanup, repeated UI pointer destroys at +0x478..+0x4A8, vector frees +0x5D0..+0x5DC, and deleting-destructor sweeps across +0x55C, +0x4C8, +0x58C, and scalar pointer fields.
// - Helper-based DEL_UI/DEL_OBJ source compiled far too small (.text 912); macro-inlining improved size to .text 1184 with /GX, still below original 1271.
// - Testing without /GX worsened size/frame direction (.text 1120), so kept /GX hypothesis.
// - Remaining gap is exact destructor declaration/context/order for many child controls and base dtor lowering. Not accepted-drift quality.
extern "C" void __cdecl operator_delete(void*);
extern "C" void __cdecl vector_delete(void*);
class UI { public: void destroy(); };
class Panel { public: void close(); int maybe(); void cleanup(); };
class Base { public: virtual ~Base(); };
extern UI* global_ui_62E870;
class TRIBE_Screen_Game : public Base { public:
    char pad04[0x474]; UI* ui478; UI* ui47c; UI* ui480; UI* ui484; UI* ui488; UI* ui48c; UI* ui490; UI* ui494; UI* arr498[5]; char pad4ac[0x0c]; Base* p4b8; Base* p4bc; Base* p4c0; Base* p4c4; Base* arr4c8[17]; Base* p50c; Base* p510; Base* p514; Base* arr518[10]; Base* p540; Base* p544; Base* p548; Base* p54c; Base* p550; Base* p554; Base* p558; Base* arr55c[8]; Base* p57c; Base* p580; Base* p584; Base* p588; Base* arr58c[8]; Base* p5ac; Base* p5b0; char pad5b4[0x1c]; void* v5d0; void* v5d4; void* v5d8; void* v5dc; char pad5e0[0xa0]; Panel* p680; int flag684; char pad688[0x130]; Panel* p7b8; ~TRIBE_Screen_Game(); };
#define DEL_UI(P) if((P)){ (P)->destroy(); operator_delete(P); (P)=0; }
#define DEL_OBJ(P) if((P)){ delete (P); (P)=0; }
TRIBE_Screen_Game::~TRIBE_Screen_Game(){
    *(int*)this = 0x572BB8; int zero=0;
    global_ui_62E870->destroy();
    if (p7b8) { if (p7b8->maybe()) p7b8->cleanup(); delete p7b8; p7b8=0; }
    if (p680) { if (flag684) { flag684=0; p680->close(); } p680=0; }
    DEL_UI(ui478); DEL_UI(ui47c); DEL_UI(ui480); DEL_UI(ui484); DEL_UI(ui488); DEL_UI(ui48c); DEL_UI(ui490); DEL_UI(ui494);
    int i; for(i=0;i<5;i++) DEL_UI(arr498[i]);
    if(v5d0){ vector_delete(v5d0); v5d0=0; } if(v5d4){ vector_delete(v5d4); v5d4=0; } if(v5d8){ vector_delete(v5d8); v5d8=0; } if(v5dc){ vector_delete(v5dc); v5dc=0; }
    for(i=0;i<8;i++) DEL_OBJ(arr55c[i]);
    for(i=0;i<17;i++) DEL_OBJ(arr4c8[i]);
    DEL_OBJ(p580); DEL_OBJ(p588); for(i=0;i<8;i++) DEL_OBJ(arr58c[i]); DEL_OBJ(p5ac); DEL_OBJ(p5b0);
    DEL_OBJ(p4c0); DEL_OBJ(p4c4); DEL_OBJ(p510); DEL_OBJ(p50c); DEL_OBJ(p514); DEL_OBJ(p540); for(i=0;i<10;i++) DEL_OBJ(arr518[i]); DEL_OBJ(p558); DEL_OBJ(p554); DEL_OBJ(p550); DEL_OBJ(p54c); DEL_OBJ(p548); DEL_OBJ(p544); DEL_OBJ(p57c); DEL_OBJ(p584); DEL_OBJ(p4b8); DEL_OBJ(p4bc);
}
