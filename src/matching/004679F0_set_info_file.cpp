// TEasy_Panel::set_info_file at 004679F0 (Panel_ez.cpp lines 547-553)
// Inventory: 004679F0_set_info_file
// Status: pass 1 – using strcpy, building to compare

#ifndef AOE1_PANEL_EZ_CONTEXT_H
class TEasy_Panel {
public:
    char pad[0xFC];                    // base class area / alignment to +0xFC
    char info_file_name[260];          // +0xFC buffer
    long info_id;                      // +0x200
    
    void set_info_file(char* fname, long id);
};
#endif

extern "C" char* __cdecl strcpy(char* dst, const char* src);

void TEasy_Panel::set_info_file(char* fname, long id) {
    if (fname) {
        strcpy((char*)this + 0xFC, fname);
    } else {
        *((char*)this + 0xFC) = '\0';
    }
    *(long*)((char*)this + 0x200) = id;
}
