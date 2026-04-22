// STATUS: active lead
// nested early guards restored the original late clear-name block; the best current shape keeps the short null/empty jumps and only misses the later compare setup
// re-testing the fully uncached repeated-strlen(name) family pushed the null case back into a near jump, so the better basin is still the nested-guard form with the earlier cached len

#include <string.h>

extern "C" void __cdecl free(void* block);
extern "C" void* __cdecl malloc(unsigned int size);

class TPanel {
public:
    char gap_00[0x1C];
    char* panelNameValue;

    void setPanelName(char* name);
};

void TPanel::setPanelName(char* name) {
    unsigned int len;

    if (name != 0) {
        len = strlen(name);
        if (len != 0) {
            if (panelNameValue != 0) {
                if (strlen(panelNameValue) < len) {
                    free(panelNameValue);
                    panelNameValue = 0;
                }
            }

            if (panelNameValue == 0) {
                panelNameValue = (char*)malloc(strlen(name) + 1);
            }

            strcpy(panelNameValue, name);
            return;
        }
    }

    if (panelNameValue != 0) {
        free(panelNameValue);
        panelNameValue = 0;
    }
}
