class RGE_Object_List {
public:
    virtual void destroy();
    int list;
    short number_of_objects;

    RGE_Object_List();
};

RGE_Object_List::RGE_Object_List() {
    list = 0;
    number_of_objects = 0;
}
