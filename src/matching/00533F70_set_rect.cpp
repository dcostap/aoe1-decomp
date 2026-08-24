// VA: 00533F70
// PDB: view.cpp lines 811-841
// RGE_View::set_rect(long a, long b, long c, long d)
// FLAGS: config/flags/00533F70_set_rect.rsp (/GX)

#include <new.h>

extern "C" void __cdecl operator_delete(void* ptr);
extern "C" void* __cdecl operator_new(unsigned int size);

#ifndef RGE_VIEW_SHARED_CONTEXT
class TMousePointer {
public:
    void set_game_window(long a, long b, long c, long d);
    void set_game_mode(int mode);
};

extern TMousePointer* MouseSystem;

class TPanel {
public:
    virtual ~TPanel();
    void set_rect(long a, long b, long c, long d);
};

class TSpan_List_Manager {
public:
    char gap_00[0x68];
    TSpan_List_Manager(long a, long b);
    ~TSpan_List_Manager();
};

class RGE_View : public TPanel {
public:
    char gap_04[0x134];
    float last_view_x;          // +0x138
    float last_view_y;          // +0x13C
    char gap_140[0x38];
    TSpan_List_Manager* tm;     // +0x178
    TSpan_List_Manager* tfm;    // +0x17C
    TSpan_List_Manager* mcm;    // +0x180

    void calc_draw_vars();
    int create_surfaces();
    virtual void set_rect(long a, long b, long c, long d);
    virtual ~RGE_View();
    virtual void v02();
    virtual void v03();
    virtual void v04();
    virtual void v05();
    virtual void v06();
    virtual void v07();
    virtual void target08(int a);
};
#endif

void RGE_View::set_rect(long a, long b, long c, long d)
{
    ((TPanel*)this)->set_rect(a, b, c, d);
    this->calc_draw_vars();
    this->create_surfaces();

    this->last_view_x = -9999.0f;
    this->last_view_y = -9999.0f;

    delete this->tm;
    delete this->tfm;
    delete this->mcm;

    this->tm = new TSpan_List_Manager(c, d);
    this->tfm = new TSpan_List_Manager(c, d);
    this->mcm = new TSpan_List_Manager(c, d);

    if (MouseSystem != 0 && c > 0 && d > 0) {
        MouseSystem->set_game_window(a, b, a + c, b + d);
        MouseSystem->set_game_mode(1);
    }

    this->target08(2);
}
