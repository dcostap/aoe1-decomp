class BaseItem {
public:
    virtual ~BaseItem();
    char gap_04[12];
    char name_arr[1];

    char * name();
};

char * BaseItem::name() {
    return this->name_arr;
}
