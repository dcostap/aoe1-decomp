// 0049E2E0 TribeLoadSavedGameScreen::action
// scr_load.cpp
// Attempt log:
// try 1: broad reconstruction from packet: saved-game screen action handler, filename formatting, load/delete/buttons, campaign/browser branches.
// try 2: modeled stack buffers as filename[260], filenameNoExt[260], findInfo-ish block; original frame is 0x438 plus EH registration.
// try 3: modeled panel text path: `panel->text()` compared to literal 0x5860E4, ui_set_text, then file-list scanning/enable branch when p4==0.
// try 4: modeled delete-button branch: get localized string 0x24CA, sprintf with selected filename, then confirmation message.
// try 5: modeled file-list double-click branch (msg==3) opening load button action.
// try 6: modeled load-button branch: count check, copy selected filename, sprintf save path, `_findfirst`, choose extension/status string, fileExists, then error message.
// try 7: modeled campaign/browser branch with 0x5842CC push/pop and optional network setup stub; broad only because direct thiscall casts are not valid under VC5.
// try 8: initial compile had explicit operator-new and raw `__thiscall` casts rejected by VC5; replaced with declarations/stubs so source builds.
// try 9: probed /GX and default flags. Both produce same rebuilt text and still lack original EH prologue/state shape; left default rsp (`/O2 /Oy`) because /GX did not improve.
// try 10: current rebuild is size-matched at 1005B, but broad mismatch from byte 0: original starts with VC5 EH registration and 0x438 frame; rebuilt starts direct `sub esp,348h` with no EH and wrong frame/local layout.
// try 11: reviewed diff: missing visible destructible/local objects and exact UI/list class surfaces cause broad prologue, call-surface, local-buffer, and branch-layout drift.
// left in scratch: behavior is broad/partial and size-matched, but exact EH/local-object/source context is unresolved. No accepted_drift: broad prologue/EH/control/call-surface drift.

#include <string.h>
#include <stdio.h>

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern "C" int __cdecl strcmp(const char*, const char*);
extern "C" char* __cdecl strcpy(char*, const char*);
extern "C" int __cdecl _findfirst(const char*, void*);
extern void* DAT_0062c574;

class TPanel { public: char* text(); int count(); int selected(); int empty(); void enable(int); };
class ScreenBase { public: virtual long action(TPanel*, long, unsigned long, unsigned long); };
class GlobalUI { public: char gap[0xc]; char* basePath; int mode(); int fileExists(char*); int netMode(); int a00; };
class Dialog { public: Dialog(); };
class TribeLoadSavedGameScreen : public ScreenBase {
public:
    char gap[0x480-4];
    TPanel* fileList;
    TPanel* loadButton;
    TPanel* deleteButton;
    TPanel* cancelButton;
    TPanel* campaignButton;
    virtual void open(TPanel*,int,int,int);
    void get_string(int,char*,int);
    void message(char*,char*,int,int);
    long action(TPanel* panel, long msg, unsigned long p3, unsigned long p4);
};

void ui_set_text(const char* s);
void ui_push(const char* s);
void ui_pop(const char* a, int b);
static void* make_dialog() { void* p = operator new(0x49c); return p; }

long TribeLoadSavedGameScreen::action(TPanel* panel, long msg, unsigned long p3, unsigned long p4) {
    char fileName[260];
    char fileNameNoExt[260];
    char findInfo[0x140];

    if (panel && panel->text() && strcmp(panel->text(), (const char*)0x5860E4) == 0) {
        ui_set_text((const char*)0x5860E4);
        if (p4 != 0) return 1;
        GlobalUI* ui = (GlobalUI*)DAT_0062c574;
        sprintf(fileName, (const char*)0x586684, ui->basePath + 0xB12, fileList->text());
        _findfirst(fileName, findInfo);
        sprintf(fileName, (const char*)0x586678, ui->basePath + 0xB12, fileList->text());
        _findfirst(fileName, findInfo);
        fileList->selected();
        fileList->count();
        if (*fileList->text() != 0) return 1;
        loadButton->enable(1);
        deleteButton->enable(1);
        return 1;
    }
    if (panel == deleteButton && msg == 1) {
        if (*fileList->text() != 0) {
            get_string(0x24ca, fileName, 0x100);
            sprintf(fileNameNoExt, fileName, fileList->text());
            message(fileNameNoExt, (char*)0x5860E4, 0x1c2, 100);
        }
    }
    if (panel == fileList) {
        if (msg != 3) return ScreenBase::action(panel,msg,p3,p4);
        open(loadButton,1,0,0);
        return 1;
    }
    if (panel == loadButton) {
        if (msg != 1) return ScreenBase::action(panel,msg,p3,p4);
        if (fileList->count() <= 0) return 1;
        strcpy(fileNameNoExt, fileList->text());
        sprintf(fileName, (const char*)0x586678, ((GlobalUI*)DAT_0062c574)->basePath + 0xB12, fileNameNoExt);
        if (_findfirst(fileName, findInfo) == -1) sprintf(fileName, (const char*)0x586670, fileNameNoExt);
        else sprintf(fileName, (const char*)0x586668, fileNameNoExt);
        if (((GlobalUI*)DAT_0062c574)->fileExists(fileName)) return 1;
        message((char*)0x2501, 0, 0x1c2, 100);
        return 1;
    }
    if (panel == campaignButton) {
        if (msg != 1) return ScreenBase::action(panel,msg,p3,p4);
        ui_push((const char*)0x5842CC);
        if (((GlobalUI*)DAT_0062c574)->netMode() == 1 && ((GlobalUI*)DAT_0062c574)->a00 == 0) {
            /* network setup stub */
        }
        ui_pop((const char*)0x5842CC,0);
        ui_set_text((const char*)0x586464);
        return 1;
    }
    return ScreenBase::action(panel,msg,p3,p4);
}
