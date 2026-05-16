// 004926E0 TRIBE_Credits_Screen::TRIBE_Credits_Screen
// Attempt log:
// initial direct constructor from original asm; custom /GX for EH-framed constructor.
// tried natural TScreenPanel base ctor/setup/set_size, file open/read, TScrollTextPanel/TShape placement-new, mouse-mode gate. /O2 /Oy /GX compiles but rebuilt .text is 560 bytes vs configured/original 619, so check_function cannot compare.
// tried default flags without custom file: same 560-byte short object, indicating source model/context rather than /GX alone.
// tried /Od /GX diagnostic: got comparable 619-byte object but completely wrong debug-frame basin (first byte mismatch, 526 positional / 738 edit), rolled back to /O2 /Oy /GX.
// left in scratch: behavior model is only a scaffold; missing exact constructor/EH/source-shape context and not accepted_drift-safe.

#include "../../include/game_globals.h"

extern "C" int sprintf(char*, const char*, ...);
extern "C" int _open(const char*, int);
extern "C" int _lseek(int, long, int);
extern "C" long _filelength(int);
extern "C" int _read(int, void*, unsigned int);
extern "C" int _close(int);
extern "C" void* operator_new(unsigned int);
extern "C" void operator_delete(void*);
inline void* operator new(unsigned int, void* p) { return p; }

class TScreenPanel {
public:
    TScreenPanel(char*);
    int setup(void*, char*, int, int);
    void set_size(int, int);
};

class TRIBE_Screen_Game { public: void* get_font(int); char gap[0x60]; void* ptr64; };
extern TRIBE_Screen_Game* rge_base_game;

class TScrollTextPanel {
public:
    TScrollTextPanel(void*, int, int, int, int, int, int, int, void*, int, int, char*, int);
};
class TShape { public: TShape(char*, int); };
class MouseObj { public: char gap104[0x104]; unsigned char f104; char gap105[0x248-0x105]; int f248; };
extern "C" void target_00462140(MouseObj*, int, int, int, int, int);

class TRIBE_Credits_Screen : public TScreenPanel {
public:
    char gap_004[0x14-0x04];
    int x14;
    int x18;
    char gap_01c[0x20-0x1c];
    int x20;
    char gap_024[0xd8-0x24];
    int xD8;
    char gap_0dc[0x204-0x0dc];
    int image204;
    char gap_208[0x478-0x208];
    TScrollTextPanel* scroll;
    int f47c, f480, f484, f488, f48c;
    char gap_490[0x894-0x490];
    TShape* shapes[7];
    int f8b0;
    int f8b4;

    TRIBE_Credits_Screen();
};

TRIBE_Credits_Screen::TRIBE_Credits_Screen() : TScreenPanel((char*)0x5842bc)
{
    int zero = 0;
    int one = 1;
    for (int i = 0; i < 7; i++) this->shapes[i] = 0;
    *(int*)this = 0x572750;
    this->scroll = 0;
    this->f47c = one;
    this->f480 = one;
    this->f484 = zero;
    this->f488 = zero;
    this->f48c = one;
    this->f8b0 = one;
    this->f8b4 = zero;

    if (!this->setup(*(void**)((char*)rge_base_game + 0x4c), (char*)0x5862b0, 0xc38b, one)) {
        this->xD8 = one;
        return;
    }
    this->set_size(0x280, 0x1e0);
    void* font = rge_base_game->get_font(4);
    int fd = _open((char*)0x5862a0, 0x8000);
    char* buf = 0;
    int len = 0;
    if (fd != -1) {
        _lseek(fd, 0, 2);
        len = _filelength(fd);
        buf = (char*)operator_new(len + 1);
        if (buf) {
            _lseek(fd, 0, 0);
            _read(fd, buf, len);
        }
        _close(fd);
    }
    TScrollTextPanel* p = (TScrollTextPanel*)operator_new(0x198);
    if (p) {
        p = new(p) TScrollTextPanel(this, this->x20, (this->x14 / 2) - 0xfa, (this->x18 / 2) - 0x96, 0x1f4, 0x12c, 0x1e, this->image204, font, *(int*)((char*)font+4), *(int*)((char*)font+8), buf, 0xc3eb);
    }
    this->scroll = p;
    if (buf) operator_delete(buf);
    this->shapes[0] = (TShape*)this->image204;
    for (int id = 0xc3eb; id - 0xc3ea < 7; id++) {
        char temp[13];
        sprintf(temp, (char*)0x586294, id - 0xc3e9);
        TShape* s = (TShape*)operator_new(0x20);
        if (s) s = new(s) TShape(temp, id);
        this->shapes[id - 0xc3ea] = s;
    }
    MouseObj* mo = (MouseObj*)((TRIBE_Screen_Game*)rge_base_game)->ptr64;
    if (mo && mo->f104 == 1 && mo->f248 == 0x0f) {
        target_00462140(mo, 0x0f, 0x0f, 1, 0, 0);
    }
}
