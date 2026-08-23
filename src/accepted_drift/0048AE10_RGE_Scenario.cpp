// VA: 0048AE10 RGE_Scenario::RGE_Scenario(int file, RGE_Game_World* world)
// Source: scenario.cpp lines 167-369
// FLAGS: /nologo /c /O2 /Oy /GX   (EH frame / new-expression ctor state present)
//
// Attempt log:
//  - baseline: clean /GX reconstruction w/ canonical RGE_Scenario layout (matches
//    InitializeTextValues + ctor field offsets: vtable+0,time_line+4,world+8,
//    victory_conquest+0xC,player_name[16][0x100]@+0xD, scenario_name..Mission_Bmp,
//    Version@+0x1888, mission_picture@+0x198C). New RGE_Timeline(file,world) and
//    TPicture(file,1) emit the /GX new-expression EH state. Calls 59/59 aligned.
//  - layout: frame was 0xF0 w/ text[0xE0]; text capped at ~0xD4 by frame 0xEC.
//    text[0xD4]->frame 0xE4, text[0xDC]->frame exactly 0xEC (kept).
//  - context: `register` on world param had no codegen effect; reverted.
//  - BLOCKER: register basin. Original keeps this in ebx throughout (frees edi for
//    the running-pointer loops, world transient in eax). Rebuilt puts this in edi
//    and spills it to a stack home each loop (mov [esp+18h],edi/reload), because
//    VC5 preloads world into ebx and can't use ebx for this. This adds ~10 insns /
//    +12 bytes and is the first strict mismatch. Not converged within budget.
//  - Main-agent semantic audit fixed historical-notes ownership: a positive
//    length keeps the allocated/read pointer; only the nonpositive arm stores 0.
//    The prior unconditional null assignment contradicted the executable's goto.
//    Recheck: 59/59 calls and 0xEC frame remain exact; strict diff improved
//    1839->1784 and exact-block coverage 58.49%->60.84% (size now +14).
//  - BREAKTHROUGH (this session): world must DIE at the top. The timeline ctor
//    arg is `this->world` (original reloads mov edx,[ebx+8] at 0050D5B0 call), so
//    the world param live range ends at `this->world = world;`. That freed ebx for
//    this (original prologue: ebx=this, esi=file, edi/ebp loop regs) and removed
//    the this-spill/version-home locals. Diff 1784->1387, frame 0xE4->0xEC with
//    text[0xDC]->[0xE4].
//  - Version gates: original keeps the rare arms (victory=1, <1.11 zero block,
//    mission_picture=0) as LATE jump targets; the ifs must be spelled positive
//    (>= 1.07 / >= 1.11 / >= 1.1) so the common read arms fall through. Diff
//    1387->71, calls 59/59, exact-blocks 96.6%.
//  - Float literals for fcomp dword sites: 1.03f, 1.15f, 1.02f (qword default
//    emitted dc 1d vs original d8 1d). Tail zero is a single dword: *(int*)text=0.
//  - BLOCKER (7 bytes, 0.37%): SIB base/index at 7 terminator stores. Original
//    encodes base=LENGTH (SIB 02/08/02/11) at description/hints/win/loss and the
//    BuildList/CityPlan/AiRules loop terminators; rebuilt encodes base=PTR
//    (SIB 10/01/10/0a). All other 1903 bytes incl. register allocation and load
//    order are identical; scenario_name terminator matches (base=ptr in both).
//    Exhausted: 10+ terminator spellings (every IR add-tree shape incl. int/ptr
//    casts and length-first), headers, full/polymorphic class surfaces,
//    register/volatile on length, /Ow /Oa /Og- /Os /Z7 /Zi /Zd /G4 /G5 /G6,
//    TU context via appended sibling fn, 2 variant-lab families. VC5 canonicalizes
//    int+ptr so no source form yields base=length; the original's length-first IR
//    at exactly these seven sites is an unreproducible TU-state artifact. Left in
//    scratch with the clean natural source (natural subscript terminators).
//  - Main-agent source audit replaced the literal vtable store/local vptr field
//    with RGE_Scenario's canonical four-slot virtual surface. VC5 still emits the
//    constructor vptr store; all substantive bytes and the seven SIB differences
//    are unchanged (the vtable address is relocation-masked as intended).
// ACCEPTED_DRIFT: seven one-byte SIB base/index swaps at terminator stores only.
// Each pair addresses the identical commutative sum (pointer + length, with the
// same displacement); instruction length, memory write, flags, control flow,
// calls, exception behavior, and all surrounding bytes are identical. Exhaustive
// natural source, context, and flag probes could not steer VC5's SIB choice.

#include <stddef.h>

void rge_read(int handle, void* buffer, int count);   // plain C++ -> /GX EH
void* __cdecl operator new(unsigned int size);
void* __cdecl calloc(int count, int size);

class RGE_Game_World;
class RGE_Static_Object;

#ifndef SCENARIO_TU
class RGE_Timeline {
public:
    virtual ~RGE_Timeline();
    RGE_Game_World* world;
    void* time_list;
    short list_num;
    short avail_id;
    float old_time;
    RGE_Timeline(int file, RGE_Game_World* world);
};

class TPicture {
public:
    void* Dib;
    void* BitmapInfo;
    unsigned char* Bits;
    void* TransInfo;
    int OwnMemory;
    int Width;
    int Height;
    short Orien;
    TPicture(int file_handle, int param_2);
    ~TPicture();
};

class RGE_Scenario {
public:
    virtual RGE_Static_Object* get_object_pointer(int object_id);
    virtual ~RGE_Scenario();
    virtual void rehook();
    virtual void save(int file);
    RGE_Timeline* time_line;            // +0x04
    RGE_Game_World* world;              // +0x08
    char victory_conquest;              // +0x0C
    char player_name[16][0x100];        // +0x0D
    char pad_100D[3];                   // +0x100D
    char* scenario_name;                // +0x1010
    char* description;                  // +0x1014
    char* hints;                        // +0x1018
    char* win_message;                  // +0x101C
    char* loss_message;                 // +0x1020
    char* historicle_notes;             // +0x1024
    char TempText1[0xE0];               // +0x1028
    char TempText2[0xE0];               // +0x1108
    char TempText3[0xE0];               // +0x11E8
    char* BuildList[16];                // +0x12C8
    char* CityPlan[16];                 // +0x1308
    char* AiRules[16];                  // +0x1348
    unsigned char* BuildListFile[16];   // +0x1388
    unsigned char* CityPlanFile[16];    // +0x13C8
    unsigned char* AiRulesFile[16];     // +0x1408
    int BuildListFileSize[16];          // +0x1448
    int CityPlanFileSize[16];           // +0x1488
    int AiRulesFileSize[16];            // +0x14C8
    char Cine_PreGame[0xE0];            // +0x1508
    char Cine_Victory[0xE0];            // +0x15E8
    char Cine_Loss[0xE0];               // +0x16C8
    char Mission_Bmp[0xE0];             // +0x17A8
    float Version;                      // +0x1888
    int PlayerPosture[16];              // +0x188C
    int PlType[16];                     // +0x18CC
    int PlCivilization[16];             // +0x190C
    int PlActive[16];                   // +0x194C
    TPicture* mission_picture;          // +0x198C

    void InitializeTextValues();
    RGE_Scenario(int file, RGE_Game_World* world);
};
#endif

RGE_Scenario::RGE_Scenario(int file, RGE_Game_World* world)
{
    short length;
    char text[0xE4];

    this->world = world;
    InitializeTextValues();

    rge_read(file, &this->Version, 4);

    if (this->Version > 1.13f) {
        for (int n1 = 0; n1 < 16; n1++)
            rge_read(file, this->player_name[n1], 0x100);
    }
    if (this->Version > 1.13) {
        for (int n2 = 0; n2 < 16; n2++) {
            rge_read(file, &this->PlActive[n2], 4);
            rge_read(file, &this->PlType[n2], 4);
            rge_read(file, &this->PlCivilization[n2], 4);
            rge_read(file, &this->PlayerPosture[n2], 4);
        }
    }

    if (this->Version >= 1.07) {
        rge_read(file, &this->victory_conquest, 1);
    } else {
        this->victory_conquest = 1;
    }

    this->time_line = new RGE_Timeline(file, this->world);

    rge_read(file, &length, 2);
    if (length > 0) rge_read(file, this->scenario_name, length);
    this->scenario_name[length] = 0;
    rge_read(file, &length, 2);
    if (length > 0) {
        this->description = (char*)calloc(length, 1);
        rge_read(file, this->description, length);
        this->description[length - 1] = 0;
    } else {
        this->description = 0;
    }

    if (this->Version >= 1.11) {
        rge_read(file, &length, 2);
        if (length > 0) {
            this->hints = (char*)calloc(length, 1);
            rge_read(file, this->hints, length);
            this->hints[length - 1] = 0;
        } else {
            this->hints = 0;
        }
        rge_read(file, &length, 2);
        if (length > 0) {
            this->win_message = (char*)calloc(length, 1);
            rge_read(file, this->win_message, length);
            this->win_message[length - 1] = 0;
        } else {
            this->win_message = 0;
        }
        rge_read(file, &length, 2);
        if (length > 0) {
            this->loss_message = (char*)calloc(length, 1);
            rge_read(file, this->loss_message, length);
            this->loss_message[length - 1] = 0;
        } else {
            this->loss_message = 0;
        }
        rge_read(file, &length, 2);
        if (length > 0) {
            this->historicle_notes = (char*)calloc(length, 1);
            rge_read(file, this->historicle_notes, length);
        } else {
            this->historicle_notes = 0;
        }
    } else {
        this->hints = 0;
        this->win_message = 0;
        this->loss_message = 0;
        this->historicle_notes = 0;
    }

    if (this->Version < 1.03f) {
        rge_read(file, &length, 2);
        if (length > 0) rge_read(file, text + 4, length);
        rge_read(file, &length, 2);
        if (length > 0) rge_read(file, text + 4, length);
        rge_read(file, &length, 2);
        if (length > 0) rge_read(file, text + 4, length);
    }

    rge_read(file, &length, 2);
    if (length > 0) rge_read(file, this->Cine_PreGame, length);
    this->Cine_PreGame[length] = 0;

    rge_read(file, &length, 2);
    if (length > 0) rge_read(file, this->Cine_Victory, length);
    this->Cine_Victory[length] = 0;

    rge_read(file, &length, 2);
    if (length > 0) rge_read(file, this->Cine_Loss, length);
    this->Cine_Loss[length] = 0;

    if (this->Version >= 1.09) {
        rge_read(file, &length, 2);
        if (length > 0) rge_read(file, this->Mission_Bmp, length);
        this->Mission_Bmp[length] = 0;
    }

    if (this->Version >= 1.1) {
        this->mission_picture = new TPicture(file, 1);
    } else {
        this->mission_picture = 0;
    }

    for (int n3 = 0; n3 < 16; n3++) {
        rge_read(file, &length, 2);
        if (length > 0) rge_read(file, this->BuildList[n3], length);
        this->BuildList[n3][length] = 0;
    }
    for (int n4 = 0; n4 < 16; n4++) {
        rge_read(file, &length, 2);
        if (length > 0) rge_read(file, this->CityPlan[n4], length);
        this->CityPlan[n4][length] = 0;
    }
    if (this->Version >= 1.08) {
        for (int n5 = 0; n5 < 16; n5++) {
            rge_read(file, &length, 2);
            if (length > 0) rge_read(file, this->AiRules[n5], length);
            this->AiRules[n5][length] = 0;
        }
    }

    for (int n6 = 0; n6 < 16; n6++) {
        rge_read(file, &this->BuildListFileSize[n6], 4);
        rge_read(file, &this->CityPlanFileSize[n6], 4);
        if (this->Version >= 1.08)
            rge_read(file, &this->AiRulesFileSize[n6], 4);
        this->BuildListFile[n6] = 0;
        this->CityPlanFile[n6] = 0;
        this->AiRulesFile[n6] = 0;
        if (this->Version >= 1.15f) {
            if (this->BuildListFileSize[n6] > 0) {
                this->BuildListFile[n6] = (unsigned char*)calloc(this->BuildListFileSize[n6], 1);
                rge_read(file, this->BuildListFile[n6], this->BuildListFileSize[n6]);
            }
            if (this->CityPlanFileSize[n6] > 0) {
                this->CityPlanFile[n6] = (unsigned char*)calloc(this->CityPlanFileSize[n6], 1);
                rge_read(file, this->CityPlanFile[n6], this->CityPlanFileSize[n6]);
            }
            if (this->AiRulesFileSize[n6] > 0) {
                this->AiRulesFile[n6] = (unsigned char*)calloc(this->AiRulesFileSize[n6], 1);
                rge_read(file, this->AiRulesFile[n6], this->AiRulesFileSize[n6]);
            }
        }
    }

    *(int*)text = 0;
    if (this->Version > 1.02f)
        rge_read(file, text, 4);
}
