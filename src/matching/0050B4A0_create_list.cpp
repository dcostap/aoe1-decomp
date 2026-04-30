// TRIBE_Dialog_List::create_list - dispatch to create_*_list based on field value

class RGE_Dialog_List {
public:
    int create_list();
    char pad_00[0x4AC];
};

class TRIBE_Dialog_List : public RGE_Dialog_List {
public:
    int field_4AC;

    int create_build_list();
    int create_train_list();
    int create_research_list();
    int create_list();
};

int TRIBE_Dialog_List::create_list() {
    switch (this->field_4AC) {
    case 100:
        return this->create_build_list();
    case 101:
        return this->create_train_list();
    case 102:
        return this->create_research_list();
    default:
        return RGE_Dialog_List::create_list();
    }
}
