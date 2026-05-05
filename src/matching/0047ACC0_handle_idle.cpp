// attempt 1: natural TScrollBarPanel idle repeat state machine
unsigned long debug_timeGetTime(char* file, int line);

struct Rect { long left, top, right, bottom; };
class TScrollBarPanel {
public:
    virtual void vf00(); virtual void vf04(); virtual void vf08(); virtual void vf0c(); virtual void vf10(); virtual void vf14(); virtual void vf18(); virtual void vf1c();
    virtual void vf20(int);
    char gap_004[0x144-4];
    unsigned char action_type;
    char gap_145[3];
    long active;
    long mouse_x;
    long mouse_y;
    unsigned char state;
    char pad_155[3];
    unsigned long last_time;
    unsigned long repeat_time;
    unsigned long initial_time;
    char gap_164[0x30];
    Rect rect1;
    Rect rect2;
    void scroll(int action, int pos);
    int hit_test(long x, long y, Rect* r);
    long handle_idle();
};

long TScrollBarPanel::handle_idle() {
    switch (this->state) {
    case 2: {
        if (this->active == 0) return 0;
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp", 306);
        if (now - this->last_time < this->repeat_time) return 0;
        this->last_time = now;
        switch (this->action_type) {
        case 1:
            this->scroll(0,0); return 0;
        case 2:
            this->scroll(1,0); return 0;
        case 3:
            if (!this->hit_test(this->mouse_x, this->mouse_y, &this->rect1)) {
                this->active = 0; this->state = 0; this->vf20(1); return 0;
            }
            this->scroll(2,0); return 0;
        case 4:
            this->scroll(2,0); return 0;
        case 5:
            if (!this->hit_test(this->mouse_x, this->mouse_y, &this->rect2)) {
                this->active = 0; this->state = 0; this->vf20(1); return 0;
            }
            this->scroll(3,0); return 0;
        }
        break;
    }
    case 1: {
        unsigned long now = debug_timeGetTime("C:\\msdev\\work\\age1_x1\\Pnl_scbr.cpp", 296);
        if (now - this->last_time >= this->initial_time) {
            this->state = 2;
            this->last_time = now - this->repeat_time;
        }
        break;
    }
    }
    return 0;
}
