// attempt 1: if/else with strcpy; wrong branch order (jne vs je), wrong offset +0x544
// attempt 2: if (filename) first; branch/offsets correct, register diff in null path (eax vs ecx)
// attempt 3: if (!filename) first; wrong branch order (jne vs je)
// attempt 4: reordered null path (id first, then zero); same eax vs ecx
// attempt 5: same order as original; same eax vs ecx
// Original null path: mov ecx,[esp+0Ch]; mov [edx+340h],0; mov [edx+444h],ecx
// VC5 null path:     mov eax,[esp+0Ch]; mov [edx+340h],0; mov [edx+444h],eax
// Left in scratch: benign register-allocation drift, behavior fully correct

#include <string.h>

class TEasy_Panel {
public:
    char gap_00[0x340];
    char popup_info_file_name[0x100];
    char gap_440[4];
    long popup_info_id;

    void set_popup_info_file(const char* filename, long id);
};

void TEasy_Panel::set_popup_info_file(const char* filename, long id) {
    if (filename) {
        strcpy(popup_info_file_name, filename);
        popup_info_id = id;
        return;
    }
    popup_info_file_name[0] = 0;
    popup_info_id = id;
}
