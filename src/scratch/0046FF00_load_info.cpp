class RGE_Object_List_li {
public:
    void rehook(void);
};

class RGE_Player_li {
public:
    int load_info(void* infile);
    int vfptr;
    char gap_04[0x24];
    RGE_Object_List_li* list1;
    RGE_Object_List_li* list2;
    RGE_Object_List_li* list3;
};

int RGE_Player_li::load_info(void* infile) {
    int (__stdcall *load_fn)(void*, int, int) = (int (__stdcall *)(void*, int, int)) *((int*)&this->vfptr + 0x3C);
    // vtable call [eax+0xF0] = index 0x3C from vtable ptr
    // Simplified: call virtual load(infile, 0, 1) then rehook 3 lists
    (*(int (**)(void*, int, int))(*(int*)this + 0xF0))(infile, 0, 1);
    this->list1->rehook();
    this->list2->rehook();
    this->list3->rehook();
    return 0;
}
