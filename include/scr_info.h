#ifndef AOE1_SCR_INFO_H
#define AOE1_SCR_INFO_H

// surface and its 0x484-byte extent.
#include "Pnl_scr.h"

class TRIBE_Screen_Info : public TScreenPanel {
public:
    int auto_close;
    unsigned long timer;
    unsigned long last_time;

    TRIBE_Screen_Info(char* panel_name, char* screen_file, long screen_id,
                      unsigned long timer_value);
    virtual ~TRIBE_Screen_Info();
    virtual long handle_idle();
    virtual long key_down_action(long, short, int, int, int);
    virtual long mouse_left_down_action(long, long, int, int);
    virtual long action(TPanel*, long, unsigned long, unsigned long);
    void close_screen();
};

typedef char scr_info_screen_size_check[
    (sizeof(TRIBE_Screen_Info) == 0x484) ? 1 : -1];

#endif
