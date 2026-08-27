#ifndef TECH_GROUP_CONTEXT
// /Od debug-style no-PDB TRIBE_Tech text-file constructor.
// Layout evidence: this is a 0x0C-byte, non-virtual class. The text-file
// constructor initializes only tech_tree; the world field belongs to the other
// constructor and remains untouched here. The target has no base or EH setup.
// Attempt log:
// - The 0x0C class layout and branch-local name buffer matched frame, size, and
//   calls, but natural local homes left a 35-byte displacement-only mismatch.
// - Function-scope and branch-scope index experiments broke block topology.
// - Exact VC5 /Od output uses j for the file index, tech_id for inner loops,
//   used_read for the name length, and len for the %hd scratch. This matches the
//   original local homes. The roles are explicit in the source below.
// Final: exact bytes, frame, calls, and CFG validated locally.

extern "C" void* __cdecl fopen(const char* filename, const char* mode);
extern "C" int __cdecl fclose(void* file);
extern "C" int __cdecl fscanf(void* file, const char* fmt, ...);
extern "C" int __cdecl strlen(const char* s);
extern "C" void* __cdecl calloc(unsigned int size, unsigned int count);
void __cdecl getstring(char** dst, char* src);

struct Tech_Entry {
    char* name;
    short pre_reqs[4];
    short pre_reqs_required;
    short attribute[3];
    short attribute_cost[3];
    unsigned char attribute_used[3];
    char gap_1D;
    short research;
    short effect;
    short civilization;
    short full_tech_mode;
    unsigned char button_location;
    char gap_27;
    short button_id;
    short string_id;
    short string_id2;
    char gap_2E[2];
    long help_string_id;
    long help_page_id;
    long hotkey_id;
};

class TRIBE_Tech {
public:
    Tech_Entry* tech_tree;
    short tech_tree_num;
    char gap_06[2];
    void* world;

    TRIBE_Tech(char* filename);
};

#endif

TRIBE_Tech::TRIBE_Tech(char* filename)
{
    int file;
    unsigned char button_temp;
    int k;
    int used_read;
    short file_count;
    int len;
    
    this->tech_tree = 0;
    file = (int)fopen(filename, "r");
    if (file != 0) {
        if (fscanf((void*)file, "%d %d", &this->tech_tree_num, &file_count) != -1) {
            if (this->tech_tree_num > 0) {
                char name_buf[0x64];
                short i;
                this->tech_tree = (Tech_Entry*)calloc(0x3c, this->tech_tree_num);
                for (i = 0; i < file_count; i++) {
                    short j;
                    short tech_id;
                    
                    fscanf((void*)file, "%hd", &j);
                    fscanf((void*)file, "%s %hd %hd %hd %hd %hd %hd %hd",
                        name_buf,
                        &this->tech_tree[j].pre_reqs_required,
                        &this->tech_tree[j].research,
                        &this->tech_tree[j].effect,
                        &this->tech_tree[j].civilization,
                        &this->tech_tree[j].full_tech_mode,
                        &button_temp,
                        &this->tech_tree[j].button_id);
                    this->tech_tree[j].button_location = button_temp;
                    used_read = strlen(name_buf);
                    for (k = 0; k < used_read; k++) {
                        if (name_buf[k] == '_') {
                            name_buf[k] = ' ';
                        }
                    }
                    this->tech_tree[j].name = 0;
                    getstring(&this->tech_tree[j].name, name_buf);
                    for (tech_id = 0; tech_id < 4; tech_id++) {
                        fscanf((void*)file, "%hd", &this->tech_tree[j].pre_reqs[tech_id]);
                    }
                    for (tech_id = 0; tech_id < 3; tech_id++) {
                        fscanf((void*)file, "%hd %hd %hd",
                            &this->tech_tree[j].attribute[tech_id],
                            &this->tech_tree[j].attribute_cost[tech_id],
                            &len);
                        this->tech_tree[j].attribute_used[tech_id] = (unsigned char)len;
                    }
                    fscanf((void*)file, "%hd %hd %ld %ld %ld",
                        &this->tech_tree[j].string_id,
                        &this->tech_tree[j].string_id2,
                        &this->tech_tree[j].help_string_id,
                        &this->tech_tree[j].help_page_id,
                        &this->tech_tree[j].hotkey_id);
                }
            }
        }
        fclose((void*)file);
    }
}
