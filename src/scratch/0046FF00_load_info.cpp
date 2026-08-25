class RGE_Object_List_li {
public:
    void rehook(void);
};

class RGE_Player_li {
public:
    void load_blob(void* infile, int a, int b);

    void load_info(void* infile);
    char gap_04[0x24];
    RGE_Object_List_li* list1;
    RGE_Object_List_li* list2;
    RGE_Object_List_li* list3;
};

void RGE_Player_li::load_info(void* infile) {
    this->load_blob(infile, 0, 1);
    this->list1->rehook();
    this->list2->rehook();
    this->list3->rehook();
}
