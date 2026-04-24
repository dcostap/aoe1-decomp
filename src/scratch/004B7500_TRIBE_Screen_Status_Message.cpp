// tried current natural inheritance shape: 80 bytes, still missing explicit destroying vtable store
#include <stddef.h>

class TPanel {
public:
    void delete_panel(TPanel** panel);
    virtual ~TPanel();
    virtual void draw();
};

class TScreenPanel : public TPanel {
public:
    char gap_004[0x474];

    virtual ~TScreenPanel();
    virtual void draw();
};

class TRIBE_Screen_Status_Message : public TScreenPanel {
public:
    TPanel* message;

    virtual ~TRIBE_Screen_Status_Message();
    virtual void draw();
};

TRIBE_Screen_Status_Message::~TRIBE_Screen_Status_Message() {
    this->delete_panel(&this->message);
    TScreenPanel::~TScreenPanel();
}
