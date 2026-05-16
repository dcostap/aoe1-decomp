// 00491650 TribeJoinScreen::TribeJoinScreen
// Attempt log:
// 1: constructor reconstructed from packet with local panel surfaces and /GX for EH/new cleanup; compiles but too short and first create call surface was wrong.
// 2: model early 0047BAE0 resource/background call separately from create_text.

#define comm_handler (*(TCommunications_Handler**)0x0062C4C0)
#define rge_base_game (*(TRIBE_Game**)0x0062C574)
#define g_join_screen (*(int*)0x0086B288)

class TCommunications_Handler { public: void set_player(int, int); };
class TRIBE_Game { public: char pad[0x4c]; void* font; };
class TPanel { public: virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3(); virtual void v4(); virtual void set_active(int); virtual void set_positioning(int); };
class TPicturePanel : public TPanel { public: char pad[0x298-4]; int border; int unknown; };
class TEasy_Panel {
public:
    ~TEasy_Panel();
    TEasy_Panel(char*);
    void setup(int);
    void set_size(long, long);
    int create_resource(void*, char*, int, int);
    int create_text(TPanel**, TEasy_Panel*, long, long, long, long, long, long, long, long, int, int);
    int create_input(TPanel**, TEasy_Panel*, long, long, long, long, long, long);
    int create_edit(TPanel**, TPanel*, long);
    int create_button(TPanel**, TEasy_Panel*, long, long, long, long, long, long, long, long, long, long, long);
    int create_button2(TPanel**, TEasy_Panel*, long, long, long, long, long, long, long, long, long);
    int create_picture(TPanel**, TEasy_Panel*, long, long, long, long, long, long, long, long, long, long, long);
    int set_tab_order(TPanel**, int);
    void set_default_button(TPanel*);
};
class TribeJoinScreen : public TEasy_Panel {
public:
    char pad[0x478-sizeof(TEasy_Panel)];
    TPanel* p478;
    TPanel* p47c;
    TPanel* p480;
    TPanel* p484;
    TPanel* p488;
    TPanel* p48c;
    TPanel* p490;
    TPanel* p494;
    TPanel* p498;
    TPanel* p49c;
    TPanel* p4a0;
    int v4a4;
    int v4a8;
    int v4ac;
    ~TribeJoinScreen();
    TribeJoinScreen();
};

TribeJoinScreen::TribeJoinScreen() : TEasy_Panel((char*)0x0058617c)
{
    *(int*)this = 0x005724f8;
    this->p478 = 0;
    this->p47c = 0;
    g_join_screen = 0;
    this->v4a4 = 0;
    this->v4a8 = 0;
    this->v4ac = 0;
    this->p4a0 = 0;
    comm_handler->set_player(1, 2);
    for (int i = 2; i <= 9; ++i) {
        comm_handler->set_player(i, 0);
    }
    if (!this->create_resource(rge_base_game->font, (char*)0x00586174, 0xc385, 1)) {
        *(int*)((char*)this + 0xd8) = 1;
        return;
    }
    this->setup(0);
    this->set_size(640, 480);
    if (!this->create_text(&this->p480, this, 0x259f, 20, 20, 0x258, 30, 1, 1, 0, 0, 0)) goto fail;
    if (!this->create_text(&this->p484, this, 0x25a8, 20, 65, 0x258, 20, 4, 0, 0, 0, 0)) goto fail;
    if (!this->create_input(&this->p488, this, 20, 90, 0x258, 0x10e, 11, 0)) goto fail;
    if (!this->create_edit(&this->p48c, this->p488, 20)) goto fail;
    this->p47c = (TPanel*)1;
    this->p488->set_positioning(0x25ab);
    if (!this->create_button(&this->p49c, this, 0x25a1, 0, 0xd2, 0x172, 0xdc, 30, 0, 0, 0, 0, 0)) goto fail;
    if (!this->create_button(&this->p490, this, 0x25a0, 0, 10, 0x1b8, 0xc8, 30, 0, 0, 0, 0, 0)) goto fail;
    if (!this->create_button(&this->p494, this, 0x25a2, 0, 0xdc, 0x1b8, 0xc8, 30, 0, 0, 0, 0, 0)) goto fail;
    if (!this->create_button(&this->p498, this, 0x0fa2, 0, 0x1ae, 0x1b8, 0xc8, 30, 0, 0, 0, 0, 0)) goto fail;
    ((TPicturePanel*)this->p498)->border = 0x1b;
    ((TPicturePanel*)this->p498)->unknown = 0;
    if (!this->create_button2(&this->p4a0, this, 0x3ea, 0, 0, 0, 0, 0, 0, -1, -1)) goto fail;
    this->p4a0->set_active(1);
    this->p4a0->set_positioning(9);
    this->set_default_button(this->p49c);
    {
        TPanel* tabs[5];
        tabs[0] = this->p488;
        tabs[1] = this->p49c;
        tabs[2] = this->p490;
        tabs[3] = this->p494;
        tabs[4] = this->p498;
        this->set_tab_order(tabs, 5);
    }
fail:
    ;
}
