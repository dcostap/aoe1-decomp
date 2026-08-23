// VA: 0048C3E0 RGE_Scenario::save(int file)  (2108 bytes, __thiscall, ret 4)
// PDB source: scenario.cpp 860-1078. EH-framed (FS chain) due to /GX + new-expression.
// Owner: sa-e937ac69-r1.
//
// STATUS: EXACT MATCH (validated 2026-08-06). diff=0 (0.0000%), shape=100.00%,
//   exact-block=100.00%, ordered calls=100% (77/77), reloc=90/90, frame=0x1D4/0x1D4,
//   code 2108/2108. Flags: /nologo /c /O2 /Oy /GX (EH frame requires /GX).
//
// Attempt log:
//  baseline: reconstructed from the scenario.cpp packet, InitializeTextValues, and the
//    scenario destructor. Audited all 77 static call sites, order, sizes, 1.08 gates,
//    failed-open persistence, file refresh/free/read/close effects, and picture cleanup.
//    Corrected TPicture to its proven 0x20-byte layout, kept Get_Version as the
//    PDB-proven RGE_Scenario member, removed false null guards from the three initialized
//    script-name arrays, and used `fd > -1`; diff fell to 1055 with exact code size.
//  control-flow: made the binary-proven redundant old-picture test a sibling arm rather
//    than a compiler-eliminated nested recheck; this recovered the original 707-instruction
//    CFG and reduced the remaining diff to 12 bytes.
//  ABI: matched Picture.cpp's constructor surface (char*, long, int, void*, int); no
//    emitted-code movement, but the declaration is now canonical.
//  topology probes: moving/initializing declarations for `np`, `old`, `version`, and the
//    two 224-byte buffers, including the proven int-address diagnostic, all emitted the
//    same 12-byte result. Do not retain synthetic padding or raw address plumbing.
//  restore/validation lead: original local homes are length/count/raw-new/version at
//    [esp+10h,+14h,+18h,+1Ch], with a 1D4h frame; current VC5 keeps the same behavior and
//    call set but uses a 1D0h frame and swaps the raw-new/version stack displacements.
//    This is the remaining evidence-backed lead, not a reason to force an opaque local.
//  Independent serialization audit: the packet has 77 static call sites in this
//    order: version/player state/timeline, six nullable text records, four fixed
//    cinema records, picture replacement+save, BuildList and CityPlan records,
//    the version-gated AiRules records, three per-player file refreshes, six
//    size/payload writes, and the -99 terminator. The original dereferences the
//    three script-name arrays unconditionally during string serialization (their
//    constructors establish non-null buffers), but conditionally refreshes and
//    writes the corresponding file-data buffers. The AiRules size/string records
//    are gated at 1.08; AiRules payload writes at the end are not gated. Failed
//    opens leave the previous size/buffer state untouched, and successful opens
//    free/reallocate/read/close in that order. The picture failure path deletes
//    only the newly constructed picture and saves the existing picture.
//  exact-match: the missing frame dword was a SEPARATE int local for the -99
//    terminator. Ghidra folds the -99 dword into temp_file_name[0] (its base sits 4
//    bytes below the real buffer), and the prior source mirrored that by writing the
//    strings at +4 and the -99 into the buffer head. The original writes the strings
//    at the buffer base (S+0x24) and keeps a distinct `int end_marker` home at S+0x20
//    just below temp_file_name; restoring that local (and removing the +4 buffer
//    offsets) added the missing dword and produced an exact match with no other change.

// == Layout (RGE_Scenario, verified vs asm + donor 0048B6C0) ==

#include <string.h>
#include <stddef.h>

void rge_write(int file, void* buf, int size);

extern "C" int __cdecl sprintf(char* dst, const char* fmt, ...);
extern "C" int __cdecl _open(const char* path, int mode, ...);
extern "C" int __cdecl lseek(int fd, int off, int whence);
extern "C" long __cdecl _tell(int fd);
extern "C" void __cdecl free(void* p);
extern "C" void* __cdecl calloc(size_t n, size_t sz);
extern "C" int __cdecl read(int fd, void* buf, unsigned int n);
extern "C" int __cdecl close(int fd);

void* operator new(unsigned int sz);
void operator delete(void* p);

#ifndef SCENARIO_TU
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

class RGE_Game_World;

class RGE_Timeline {
public:
    void save(int file);
};

class TPicture {
public:
    void* Dib;                     // +0x00
    void* BitmapInfo;              // +0x04
    unsigned char* Bits;            // +0x08
    void* TransInfo;               // +0x0C
    int OwnMemory;                 // +0x10
    int Width;                     // +0x14
    int Height;                    // +0x18
    short Orien;                   // +0x1C; class size rounds to 0x20
    TPicture(char* name, long a, int b, void* c, int d);
    ~TPicture();
    void Save(int file);
};

class RGE_Scenario {
public:
    virtual void save(int file);
    float Get_Version();

    RGE_Timeline* time_line;           // +0x04
    RGE_Game_World* world;             // +0x08
    unsigned char victory_conquest;   // +0x0C
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
#endif

void RGE_Scenario::save(int file)
{
    float* version;
    char temp_file_name[224];
    char file_name[224];
    short length;
    int fd;
    TPicture* np;
    TPicture* old;
    int end_marker;

    version = &this->Version;

    this->Version = this->Get_Version();
    rge_write(file, version, 4);

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

    sprintf(file_name, "%s.bmp", this->Mission_Bmp);

    np = new TPicture(file_name, -1, 0, 0, 0);
    old = this->mission_picture;
    if (old != 0) {
        if (np->Dib == 0) {
            if (np != 0) {
                delete np;
            }
            goto skip_store;
        }
    }
    if (old != 0) {
        delete old;
    }
    this->mission_picture = np;
skip_store:
    this->mission_picture->Save(file);

    // BuildList strings
    for (int c = 0; c < 16; c++) {
        length = (short)strlen(this->BuildList[c]);
        rge_write(file, &length, 2);
        if (length > 0)
            rge_write(file, this->BuildList[c], length);
    }

    // CityPlan strings
    for (int d = 0; d < 16; d++) {
        length = (short)strlen(this->CityPlan[d]);
        rge_write(file, &length, 2);
        if (length > 0)
            rge_write(file, this->CityPlan[d], length);
    }

    // AiRules strings (version >= 1.08 only)
    if (*version >= 1.08) {
        for (int e = 0; e < 16; e++) {
            length = (short)strlen(this->AiRules[e]);
            rge_write(file, &length, 2);
            if (length > 0)
                rge_write(file, this->AiRules[e], length);
        }
    }

    // per-player AI data files
    for (int f = 0; f < 16; f++) {
        if (this->BuildList[f] != 0) {
            sprintf(temp_file_name, "%s%s.ai", rge_base_game->prog_info->ai_dir, this->BuildList[f]);
            fd = _open(temp_file_name, 0x8000);
            if (fd > -1) {
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
            sprintf(temp_file_name, "%s%s.cty", rge_base_game->prog_info->ai_dir, this->CityPlan[f]);
            fd = _open(temp_file_name, 0x8000);
            if (fd > -1) {
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
            sprintf(temp_file_name, "%s%s.per", rge_base_game->prog_info->ai_dir, this->AiRules[f]);
            fd = _open(temp_file_name, 0x8000);
            if (fd > -1) {
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
        if (*version >= 1.08)
            rge_write(file, &this->AiRulesFileSize[f], 4);
        if (this->BuildListFile[f] != 0)
            rge_write(file, this->BuildListFile[f], this->BuildListFileSize[f]);
        if (this->CityPlanFile[f] != 0)
            rge_write(file, this->CityPlanFile[f], this->CityPlanFileSize[f]);
        if (this->AiRulesFile[f] != 0)
            rge_write(file, this->AiRulesFile[f], this->AiRulesFileSize[f]);
    }

    end_marker = -99;
    rge_write(file, &end_marker, 4);
}
