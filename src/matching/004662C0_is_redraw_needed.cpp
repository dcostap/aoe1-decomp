#ifndef AOE1_PANEL_CONTEXT_H
class TDrawArea;

class TPanel {
public:
    char gap_00[0x20];
    TDrawArea* render_area;
    char gap_24[0x14];
    unsigned char need_redraw;
    char gap_39[0x33];
    int active;
    int visible;

    unsigned char is_redraw_needed(void);
};

#endif
unsigned char TPanel::is_redraw_needed(void) {
    if (render_area != 0 && visible != 0 && active != 0) {
        return need_redraw;
    }
    return 0;
}
