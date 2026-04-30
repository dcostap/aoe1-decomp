// 004666C0 TPanel::setPanelName
// Panel.cpp:2398-2413, 166 bytes, __thiscall, ret 4

#include <string.h>
#include <stdlib.h>

class TPanel {
public:
    unsigned char gap_00[0x1C];
    char* panel_name;  // +0x1C
    
    void setPanelName(const char* name);
};

void TPanel::setPanelName(const char* name) {
    if (name == 0) goto exit;
    if (strlen(name) == 0) goto exit;
    
    if (panel_name == 0) goto alloc;
    if (strlen(panel_name) >= strlen(name)) goto copy;
    free(panel_name);
alloc:
    panel_name = (char*)malloc(1 + strlen(name));
copy:
    {
        size_t n = 1 + strlen(name);
        memcpy(panel_name, name, n);
    }
    return;
    
exit:
    if (panel_name != 0) {
        free(panel_name);
        panel_name = 0;
    }
}
