// /Od debug-style no-PDB TRIBE_Tech text-file constructor.
// Layout evidence: this is a 0x0C-byte, non-virtual class. The text-file
// constructor initializes only tech_tree; the world field belongs to the other
// constructor and remains untouched here. The target has no base or EH setup.
// Attempt log:
// - Added the proven world field at +0x08. It does not affect this constructor.
// - Tested function-scope and branch-scope loop declarations. Branch scope keeps
//   the original block shape and frame.
// - Reordered natural scalar declarations. Best result is 44 differing bytes;
//   remaining drift starts at the outer index and name-buffer homes.
// - Restored function-scope tech_id and j experiments because they shortened the
//   function and changed the original loop topology.

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

TRIBE_Tech::TRIBE_Tech(char* filename)
{
    char name_buf[0x64];
    int file;
    unsigned char button_temp;
    int k;
    short used_read;
    short file_count;
    int len;

    this->tech_tree = 0;
    file = (int)fopen(filename, "r");
    if (file != 0) {
        if (fscanf((void*)file, "%d %d", &this->tech_tree_num, &file_count) != -1) {
            if (this->tech_tree_num > 0) {
                short i;
                this->tech_tree = (Tech_Entry*)calloc(0x3c, this->tech_tree_num);
                for (i = 0; i < file_count; i++) {
                    short tech_id;

                    fscanf((void*)file, "%hd", &tech_id);
                    fscanf((void*)file, "%s %hd %hd %hd %hd %hd %hd %hd",
                        name_buf,
                        &this->tech_tree[tech_id].pre_reqs_required,
                        &this->tech_tree[tech_id].research,
                        &this->tech_tree[tech_id].effect,
                        &this->tech_tree[tech_id].civilization,
                        &this->tech_tree[tech_id].full_tech_mode,
                        &button_temp,
                        &this->tech_tree[tech_id].button_id);
                    this->tech_tree[tech_id].button_location = button_temp;
                    len = strlen(name_buf);
                    for (k = 0; k < len; k++) {
                        if (name_buf[k] == '_') {
                            name_buf[k] = ' ';
                        }
                    }
                    this->tech_tree[tech_id].name = 0;
                    getstring(&this->tech_tree[tech_id].name, name_buf);
                    {
                        short j;
                        for (j = 0; j < 4; j++) {
                            fscanf((void*)file, "%hd", &this->tech_tree[tech_id].pre_reqs[j]);
                        }
                        for (j = 0; j < 3; j++) {
                            fscanf((void*)file, "%hd %hd %hd",
                                &this->tech_tree[tech_id].attribute[j],
                                &this->tech_tree[tech_id].attribute_cost[j],
                                &used_read);
                            this->tech_tree[tech_id].attribute_used[j] = (unsigned char)used_read;
                        }
                    }
                    fscanf((void*)file, "%hd %hd %ld %ld %ld",
                        &this->tech_tree[tech_id].string_id,
                        &this->tech_tree[tech_id].string_id2,
                        &this->tech_tree[tech_id].help_string_id,
                        &this->tech_tree[tech_id].help_page_id,
                        &this->tech_tree[tech_id].hotkey_id);
                }
            }
        }
        fclose((void*)file);
    }
}
