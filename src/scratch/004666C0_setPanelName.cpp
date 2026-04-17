// STATUS: blocked
// BLOCKER: VC5 is very close, but still short-jumps directly into the clear-name path and keeps the final copy setup in a slightly different order instead of the original long jump to the shared epilogue plus subtract-edi/ecx source reconstruction
// NOTE: repne-scasb length scans, free/malloc call set, and rep movsd/movsb copy are understood; remaining drift is block layout and copy-prep scheduling only

extern "C" void __cdecl free(void* block);
extern "C" void* __cdecl malloc(unsigned int size);
extern "C" unsigned int __cdecl strlen(const char* s);
extern "C" void* __cdecl memcpy(void* dst, const void* src, unsigned int count);

class TPanel {
public:
    char gap_00[0x1C];
    char* panelNameValue;

    void setPanelName(char* name);
};

void TPanel::setPanelName(char* name) {
    unsigned int len;

    if (name == 0) {
        goto clear_name;
    }

    len = strlen(name);
    if (len == 0) {
        goto clear_name;
    }

    if (panelNameValue != 0) {
        if (strlen(panelNameValue) < len) {
            free(panelNameValue);
            panelNameValue = 0;
        }
    }

    if (panelNameValue == 0) {
        panelNameValue = (char*)malloc(strlen(name) + 1);
    }

    memcpy(panelNameValue, name, strlen(name) + 1);
    goto done;

clear_name:
    if (panelNameValue != 0) {
        free(panelNameValue);
        panelNameValue = 0;
    }

done:
    ;
}
