extern "C" __declspec(dllimport) unsigned long __stdcall GetSysColor(int index);
extern "C" __declspec(dllimport) int __stdcall SetSysColors(int count, const int* elements, const unsigned long* colors);

#ifndef AOE1_PANEL_CONTEXT_H
class TPanelSystem {
public:
    char gap_00[0xACC];
    int saved_colors;
    unsigned long save_back_color;
    unsigned long save_text_color;

    void restore_system_colors(void);
};

#endif
void TPanelSystem::restore_system_colors(void) {
    int elems[2];
    unsigned long colors[2];

    if (saved_colors != 0) {
        if (GetSysColor(5) == save_back_color && GetSysColor(8) == save_text_color) {
            return;
        }
        colors[0] = save_back_color;
        elems[0] = 5;
        elems[1] = 8;
        colors[1] = save_text_color;
        SetSysColors(2, elems, colors);
    }
}
