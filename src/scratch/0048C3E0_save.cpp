// VA: 0048C3E0 RGE_Scenario::save(int file)  (2108 bytes, __thiscall, ret 4)
// PDB source: scenario.cpp 860-1078. EH-framed (FS chain) due to /GX + new-expression.
// Owner: dsb1-0048C3E0.
//
// STATUS: PAUSED (budget). Clean canonical reconstruction preserved below; NOT exact.
// Metrics: diff=1856 (86.77%), shape=93.86%, exact-block=70%, ordered calls=100% (77/77),
//   reloc=0, frame=0x1D0/0x1D4 (4 short), code 2139/2108 (+31). Flags:/nologo /c /O2 /Oy /GX.
//
// Attempt log:
//  baseline: reconstruct from donor 0048B6C0 layout + 0048B5A0 dtor + decompiler. Compile
//    fixes: VC5 for-init redeclars need distinct names; EH needs /GX rsp; file/temp buffers
//    are 224 (0xE0) not 256 (frame was 0x210 until shrunk to 224).
//  probe: TPicture replace block - first form put delete-new into a cold tail (reloc sites
//    2); restructured to decompiler goto-skip_store + sibling if(old) recheck -> 100% call
//    alignment, reloc sites 0, size -11, shape 92.75->93.86%.
//  Leads (next worker): frame 4 short = original keeps &CityPlan base in stack local
//    [esp+18h] (saved in CityPlan str loop, reloaded in AI loop) + &Version local; inline
//    member addrs cost those 4 bytes -> try named base-pointer locals. 1 direct-call target
//    mismatch in AI loop (orig close -> rebuilt _lseek at +06A3): lseek(SET)/read/close
//    schedule differently. CFG orig cond45/jumps7 vs rebuilt 47/10 -> +31 overflow in middle
//    (likely Version>=1.08 fcomp region or AI-loop arms).
//  Length spellings (binary-proven; LESSONS: strlen+1 cancels the dec fixup): scenario_name + 4
//    cinema strings + BuildList/CityPlan/AiRules use plain strlen (asm has dec);
//    desc/hints/win/loss/historicle_notes use strlen+1 (asm has no dec).
//  Orchestrator audit: corrected the copied donor stub to the PDB-proven
//    RGE_Scenario::Get_Version member surface and removed the spurious local
//    g_version definition. This target has only one meaningful source probe and
//    remains structurally active, not exhausted or logic-review-ready.

// == Layout (RGE_Scenario, verified vs asm + donor 0048B6C0) ==

#include <string.h>
#include <stddef.h>

void rge_write(int file, void* buf, int size);

extern "C" int __cdecl sprintf(char* dst, const char* fmt, ...);
extern "C" int __cdecl _open(const char* path, int mode);
extern "C" int __cdecl lseek(int fd, int off, int whence);
extern "C" long __cdecl _tell(int fd);
extern "C" void __cdecl free(void* p);
extern "C" void* __cdecl calloc(size_t n, size_t sz);
extern "C" int __cdecl read(int fd, void* buf, unsigned int n);
extern "C" int __cdecl close(int fd);

void* operator new(unsigned int sz);
void operator delete(void* p);

class RGE_Prog_Info {
public:
    char gap_00[0x102B];
    char ai_dir[0x100];            // +0x102B
};

class RGE_Base_Game {
public:
    char gap_00[0x0C];
    RGE_Prog_Info* prog_info;      // +0x0C
};
extern RGE_Base_Game* rge_base_game;

class RGE_Timeline {
public:
    void save(int file);
};

class TPicture {
public:
    void* Dib;                     // +0x00
    TPicture(char* name, int a, int b, int c, int d);
    ~TPicture();
    void Save(int file);
};

class RGE_Scenario {
public:
    virtual void save(int file);
    float Get_Version();

    RGE_Timeline* time_line;           // +0x04
    char _pad_08[0x04];                // +0x08..0x0B
    char victory_conquest;             // +0x0C
    char player_name[16][0x100];       // +0x0D
    char* scenario_name;               // +0x1010
    char* description;                 // +0x1014
    char* hints;                       // +0x1018
    char* win_message;                 // +0x101C
    char* loss_message;                // +0x1020
    char* historicle_notes;            // +0x1024
    char TempText1[0xE0];              // +0x1028
    char TempText2[0xE0];              // +0x1108
    char TempText3[0xE0];              // +0x11E8
    char* BuildList[16];               // +0x12C8
    char* CityPlan[16];                // +0x1308
    char* AiRules[16];                 // +0x1348
    unsigned char* BuildListFile[16];  // +0x1388
    unsigned char* CityPlanFile[16];   // +0x13C8
    unsigned char* AiRulesFile[16];    // +0x1408
    int BuildListFileSize[16];         // +0x1448
    int CityPlanFileSize[16];          // +0x1488
    int AiRulesFileSize[16];           // +0x14C8
    char Cine_PreGame[0xE0];           // +0x1508
    char Cine_Victory[0xE0];           // +0x15E8
    char Cine_Loss[0xE0];              // +0x16C8
    char Mission_Bmp[0xE0];            // +0x17A8
    float Version;                     // +0x1888
    int PlayerPosture[16];             // +0x188C
    int PlType[16];                    // +0x18CC
    int PlCivilization[16];            // +0x190C
    int PlActive[16];                  // +0x194C
    TPicture* mission_picture;         // +0x198C
};

void RGE_Scenario::save(int file)
{
    char file_name[224];
    char temp_file_name[224];
    short length;
    int fd;

    this->Version = this->Get_Version();
    rge_write(file, &this->Version, 4);

    for (int a = 0; a < 16; a++)
        rge_write(file, this->player_name[a], 0x100);

    for (int b = 0; b < 16; b++) {
        rge_write(file, &this->PlActive[b], 4);
        rge_write(file, &this->PlType[b], 4);
        rge_write(file, &this->PlCivilization[b], 4);
        rge_write(file, &this->PlayerPosture[b], 4);
    }

    rge_write(file, &this->victory_conquest, 1);

    if (this->time_line != 0)
        this->time_line->save(file);

    if (this->scenario_name != 0)
        length = (short)strlen(this->scenario_name);
    else
        length = 0;
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->scenario_name, length);

    if (this->description != 0)
        length = (short)(strlen(this->description) + 1);
    else
        length = 0;
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->description, length);

    if (this->hints != 0)
        length = (short)(strlen(this->hints) + 1);
    else
        length = 0;
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->hints, length);

    if (this->win_message != 0)
        length = (short)(strlen(this->win_message) + 1);
    else
        length = 0;
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->win_message, length);

    if (this->loss_message != 0)
        length = (short)(strlen(this->loss_message) + 1);
    else
        length = 0;
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->loss_message, length);

    if (this->historicle_notes != 0)
        length = (short)(strlen(this->historicle_notes) + 1);
    else
        length = 0;
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->historicle_notes, length);

    length = (short)strlen(this->Cine_PreGame);
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->Cine_PreGame, length);

    length = (short)strlen(this->Cine_Victory);
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->Cine_Victory, length);

    length = (short)strlen(this->Cine_Loss);
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->Cine_Loss, length);

    length = (short)strlen(this->Mission_Bmp);
    rge_write(file, &length, 2);
    if (length > 0)
        rge_write(file, this->Mission_Bmp, length);

    sprintf(file_name + 4, "%s.bmp", this->Mission_Bmp);

    TPicture* np = new TPicture(file_name + 4, -1, 0, 0, 0);
    TPicture* old = this->mission_picture;
    if (old != 0) {
        if (np->Dib == 0) {
            if (np != 0) {
                np->~TPicture();
                operator delete(np);
            }
            goto skip_store;
        }
        if (old != 0) {
            old->~TPicture();
            operator delete(old);
        }
    }
    this->mission_picture = np;
skip_store:
    this->mission_picture->Save(file);

    // BuildList strings
    for (int c = 0; c < 16; c++) {
        if (this->BuildList[c] != 0)
            length = (short)strlen(this->BuildList[c]);
        else
            length = 0;
        rge_write(file, &length, 2);
        if (length > 0)
            rge_write(file, this->BuildList[c], length);
    }

    // CityPlan strings
    for (int d = 0; d < 16; d++) {
        if (this->CityPlan[d] != 0)
            length = (short)strlen(this->CityPlan[d]);
        else
            length = 0;
        rge_write(file, &length, 2);
        if (length > 0)
            rge_write(file, this->CityPlan[d], length);
    }

    // AiRules strings (version >= 1.08 only)
    if (this->Version >= 1.08) {
        for (int e = 0; e < 16; e++) {
            if (this->AiRules[e] != 0)
                length = (short)strlen(this->AiRules[e]);
            else
                length = 0;
            rge_write(file, &length, 2);
            if (length > 0)
                rge_write(file, this->AiRules[e], length);
        }
    }

    // per-player AI data files
    for (int f = 0; f < 16; f++) {
        if (this->BuildList[f] != 0) {
            sprintf(temp_file_name + 4, "%s%s.ai", rge_base_game->prog_info->ai_dir, this->BuildList[f]);
            fd = _open(temp_file_name + 4, 0x8000);
            if (fd >= 0) {
                lseek(fd, 0, 2);
                this->BuildListFileSize[f] = _tell(fd);
                if (this->BuildListFile[f] != 0) free(this->BuildListFile[f]);
                this->BuildListFile[f] = (unsigned char*)calloc(this->BuildListFileSize[f], 1);
                lseek(fd, 0, 0);
                read(fd, this->BuildListFile[f], this->BuildListFileSize[f]);
                close(fd);
            }
        }
        if (this->CityPlan[f] != 0) {
            sprintf(temp_file_name + 4, "%s%s.cty", rge_base_game->prog_info->ai_dir, this->CityPlan[f]);
            fd = _open(temp_file_name + 4, 0x8000);
            if (fd >= 0) {
                lseek(fd, 0, 2);
                this->CityPlanFileSize[f] = _tell(fd);
                if (this->CityPlanFile[f] != 0) free(this->CityPlanFile[f]);
                this->CityPlanFile[f] = (unsigned char*)calloc(this->CityPlanFileSize[f], 1);
                lseek(fd, 0, 0);
                read(fd, this->CityPlanFile[f], this->CityPlanFileSize[f]);
                close(fd);
            }
        }
        if (this->AiRules[f] != 0) {
            sprintf(temp_file_name + 4, "%s%s.per", rge_base_game->prog_info->ai_dir, this->AiRules[f]);
            fd = _open(temp_file_name + 4, 0x8000);
            if (fd >= 0) {
                lseek(fd, 0, 2);
                this->AiRulesFileSize[f] = _tell(fd);
                if (this->AiRulesFile[f] != 0) free(this->AiRulesFile[f]);
                this->AiRulesFile[f] = (unsigned char*)calloc(this->AiRulesFileSize[f], 1);
                lseek(fd, 0, 0);
                read(fd, this->AiRulesFile[f], this->AiRulesFileSize[f]);
                close(fd);
            }
        }

        rge_write(file, &this->BuildListFileSize[f], 4);
        rge_write(file, &this->CityPlanFileSize[f], 4);
        if (this->Version >= 1.08)
            rge_write(file, &this->AiRulesFileSize[f], 4);
        if (this->BuildListFile[f] != 0)
            rge_write(file, this->BuildListFile[f], this->BuildListFileSize[f]);
        if (this->CityPlanFile[f] != 0)
            rge_write(file, this->CityPlanFile[f], this->CityPlanFileSize[f]);
        if (this->AiRulesFile[f] != 0)
            rge_write(file, this->AiRulesFile[f], this->AiRulesFileSize[f]);
    }

    *((int*)temp_file_name) = -99;
    rge_write(file, temp_file_name, 4);
}
