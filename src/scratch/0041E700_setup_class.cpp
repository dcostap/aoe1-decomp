// VA: 0041E700 setup_class
// basegame.cpp (152 bytes)
// Class registration function - sets up a class entry

// IAT imports as function pointers
extern int (__stdcall * RegisterClass)(void* info);
extern void (__stdcall * SetupClass)(void* name, void* info);

// Global string constants
extern const char class_name[]; // at 592A40h
extern const char setup_string[]; // at 41E7A0h

class SomeClass {
public:
    char gap_00[0x0C];
    void* field_0C;    // +0x0C - points to another struct
    
    int setup_class();
};

int SomeClass::setup_class() {
    // Quick check if already initialized
    if (*(int*)((char*)field_0C + 0x414) != 0) {
        return 1;
    }
    
    // Setup class info
    char* name_ptr = (char*)&class_name;
    char* class_name_start = (char*)((char*)field_0C + 0x645);
    if (*class_name_start == 0) {
        name_ptr = class_name_start;
    }
    
    // Call registration
    char* sub_class_name = (char*)((char*)field_0C + 0x61C);
    void* parent_class = *(void**)((char*)field_0C + 0x410);
    
    int result = RegisterClass(parent_class);
    
    // Set up class info structure
    void* info = (void*)((char*)field_0C + 0x410);
    
    // Call setup function
    SetupClass(sub_class_name, info);
    return 1;
}
