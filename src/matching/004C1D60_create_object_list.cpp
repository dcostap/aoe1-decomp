// attempt 2: direct new expression with real ctor and /GX EH
class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    char gap[8];
    RGE_Object_List();
};
class RGE_Static_Object { public: virtual RGE_Object_List* create_object_list(void); };
RGE_Object_List* RGE_Static_Object::create_object_list(void) {
    return new RGE_Object_List;
}
