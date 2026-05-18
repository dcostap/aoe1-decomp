// 0051D060 TRIBE_Panel_Pop::draw
// tpnl_pop.cpp
// Attempt log:
// try 1: broad reconstruction from packet: guard surfaces, animation-state update, optional backing panel draw, text/rect drawing and restore.
// try 2: modeled early guards for screen(+0x20), palette(+0x70), surface(+0x6C), frame increment, and virtual draw/postDraw calls.
// try 3: modeled current-player lookup through global panel manager and cached object at +0x10C.
// try 4: modeled animMode +0x118 transition from player/font metric table and animTime +0x11C accumulation/reset cycle.
// try 5: modeled coordinate calculation via camera floats at +0x50/+0x2C/+0x10/+0x80 using roundFloat.
// try 6: modeled redraw/rebuild path controlled by image +0x124, changed flag, needsRedraw +0xF3, lastX +0x110, lastY +0x114.
// try 7: modeled overlay/image fast path with lock/draw/unlock and early virtual postDraw.
// try 8: modeled main drawing setup: lock, SelectObject, SetTextColor, SetBkMode, sprintf label from coord helper.
// try 9: modeled border text as repeated SetRect + DrawTextA around panel bounds (+8C/+90/+18/+14), then foreground text and GDI restore.
// try 10: default compile produced .text 928B vs original 1033B, no full diff.
// try 11: /GX probe produced identical 928B, removed flag file.
// left in scratch: broad drawing behavior is modeled, but exact class layout, overlay/backing-surface blit calls, HDC/font member surfaces, and repeated rect arithmetic/source order are incomplete; rebuilt is size-short. No accepted_drift: no localized diff.

typedef unsigned char BYTE;
struct Rect { int left, top, right, bottom; };
class Screen { public: void lock(const char*); void unlock(const char*); void* font; };
class View { public: void draw(); void postDraw(); };
class Font { public: char gap[0x50]; short lineHeight; void* metrics; };
class Player { public: char gap[0x50]; void* camera; };

extern "C" int __cdecl sprintf(char*, const char*, ...);
extern int roundFloat(float);
extern void* gPanelMgr;
extern "C" void* __stdcall SelectObject(void*, void*);
extern "C" void* __stdcall SetTextColor(void*, unsigned int);
extern "C" int __stdcall SetBkMode(void*, int);
extern "C" int __stdcall SetRect(Rect*, int, int, int, int);
extern "C" int __stdcall DrawTextA(void*, const char*, int, Rect*, unsigned int);

class TRIBE_Panel_Pop {
public:
    View* vtblAsView;
    char gap04[0x14]; int width; int height; Screen* screen;
    char gap24[0x6c-0x24]; void* surface; void* palette;
    char gap74[0x88-0x74]; int oldBk; int x; int y;
    char gap94[0xe0-0x94]; int frame;
    char gapE4[0xF3-0xE4]; BYTE needsRedraw;
    void* oldPen; int oldColor; int textColor; int borderColor;
    void* object; int lastX; int lastY; BYTE animMode; char pad119[3]; float animTime;
    void* image; char gap128[0x138-0x128]; char label[16]; int labelX; int labelY; void* overlay;
    void draw();
    void rebuild();
    int coordX(int,int,int); int coordY(int,int,int);
};
extern void* getCurrentPlayer(void*);

void TRIBE_Panel_Pop::draw() {
    char str[256];
    Rect r;
    void* oldFont;
    int maxx, maxy;
    int changed;
    int dx, dy;
    void* localV;

    if (!screen || !palette || !surface) return;
    ++frame;
    localV = *(void**)this;
    ((View*)this)->draw();
    Player* p = (Player*)getCurrentPlayer(gPanelMgr);
    object = p;
    changed = 0;
    if (!animMode) {
        Font* f = (Font*)p->camera;
        if (*(int*)((char*)gPanelMgr + ((int)f->lineHeight)*4 + 0xa34) > 0) {
            animMode = 1; animTime = 0.0f; changed = 1;
        }
    }
    if (animMode) {
        animTime += *(float*)((char*)((Player*)object)->camera + 0x84);
        if (animTime >= 1.0f) { changed = 1; animTime = 0.0f; if (++animMode > 2) animMode = 0; }
    }
    void* cam = *(void**)((char*)object + 0x50);
    dx = roundFloat(*(float*)((char*)cam+0x2c));
    dy = roundFloat(*(float*)((char*)cam+0x10)) + dx;
    maxx = roundFloat(*(float*)((char*)cam+0x80));
    if (dy > maxx) dy = maxx;
    if (image) {
        if (changed || needsRedraw || lastX != dx || lastY != dy) { lastX=dx; lastY=dy; rebuild(); if (needsRedraw) { needsRedraw=0; ((View*)this)->postDraw(); return; } }
    }
    if (overlay && image) {
        screen->lock((const char*)1); overlay = image; screen->unlock((const char*)0); ((View*)this)->postDraw(); return;
    }
    screen->lock((const char*)0x58B718);
    oldFont = SelectObject(screen->font, oldPen);
    oldColor = (int)SetTextColor(screen->font, textColor);
    oldBk = SetBkMode(screen->font, 1);
    sprintf(str, (const char*)0x58B70C, coordX(0x2b2a,lastX,lastY));
    SetTextColor(screen->font, borderColor);
    int left=x+1, top=y+1, right=x+width-2, bottom=y+height-2;
    SetRect(&r,left-1,top-1,right-2,bottom-2); DrawTextA(screen->font,str,-1,&r,0x21);
    SetRect(&r,left,top+1,right-2,bottom); DrawTextA(screen->font,str,-1,&r,0x21);
    SetRect(&r,left+1,top,right,bottom-2); DrawTextA(screen->font,str,-1,&r,0x21);
    SetRect(&r,left,top,right,bottom); DrawTextA(screen->font,str,-1,&r,0x21);
    SetTextColor(screen->font, animMode==1 ? textColor : oldColor);
    SetRect(&r,left,top,right-1,bottom-1); DrawTextA(screen->font,str,-1,&r,0x21);
    SetTextColor(screen->font, oldColor);
    SetBkMode(screen->font, 0);
    screen->unlock((const char*)0x58B718);
    ((View*)this)->postDraw();
}
