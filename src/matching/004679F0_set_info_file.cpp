// TEasy_Panel::set_info_file at 004679F0 (Panel_ez.cpp lines 547-553)
// Inventory: 004679F0_set_info_file
// Status: pass 1 – using strcpy, building to compare

class TEasy_Panel {
public:
    char pad[0xFC];                    // base class area / alignment to +0xFC
    char info_file_name[260];          // +0xFC buffer
    long info_id;                      // +0x200
    
    void set_info_file(char* fname, long id);
};

extern "C" char* __cdecl strcpy(char* dst, const char* src);

void TEasy_Panel::set_info_file(char* fname, long id) {
    if (fname) {
        strcpy(this->info_file_name, fname);
    } else {
        this->info_file_name[0] = '\0';
    }
    this->info_id = id;
}
