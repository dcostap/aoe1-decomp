// attempt 1: destructor with Sess global cleanup, 9 delete_panel calls, base destructor

struct tagRECT;

class TPanel {
public:
    void* vftable;
    char pad[0xF0];

    virtual ~TPanel();
    void delete_panel(TPanel** panel);
};

class TEasy_Panel : public TPanel {
public:
    char pad_easy[0x380];
};

class TScreenPanel : public TEasy_Panel {
public:
    virtual ~TScreenPanel();
};

class TCommunications_Sessions {
public:
    ~TCommunications_Sessions();
};

extern "C" void* __cdecl operator_delete(void* ptr);

extern TCommunications_Sessions* Sess;

class TribeJoinScreen : public TScreenPanel {
public:
    int startedSession;
    int listFilled;
    TPanel* title;
    TPanel* listTitle;
    TPanel* list;
    TPanel* scrollbar;
    TPanel* joinButton;
    TPanel* createButton;
    TPanel* cancelButton;
    TPanel* refreshButton;
    TPanel* close_button;
    int game_count;
    int waitingToStart;
    unsigned long joinTime;

    virtual ~TribeJoinScreen();
};

TribeJoinScreen::~TribeJoinScreen() {
    TCommunications_Sessions* p = Sess;
    if (p != 0) {
        p->~TCommunications_Sessions();
        operator_delete(p);
    }
    this->delete_panel(&this->title);
    this->delete_panel(&this->listTitle);
    this->delete_panel(&this->list);
    this->delete_panel(&this->scrollbar);
    this->delete_panel(&this->refreshButton);
    this->delete_panel(&this->joinButton);
    this->delete_panel(&this->createButton);
    this->delete_panel(&this->cancelButton);
    this->delete_panel(&this->close_button);
}
