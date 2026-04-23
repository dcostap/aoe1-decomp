class RGE_Dialog_List {
public:
    virtual int create_list(void);
};

class TRIBE_Dialog_List : public RGE_Dialog_List {
public:
    char gap_04[0x4A8];
    int mode;

    int create_build_list(void);
    int create_train_list(void);
    int create_research_list(void);
    int create_list(void);
};

int TRIBE_Dialog_List::create_list(void) {
    int mode;

    mode = this->mode - 100;
    if (mode == 0) {
        return this->create_build_list();
    }
    mode--;
    if (mode == 0) {
        return this->create_train_list();
    }
    mode--;
    if (mode == 0) {
        return this->create_research_list();
    }
    return RGE_Dialog_List::create_list();
}
