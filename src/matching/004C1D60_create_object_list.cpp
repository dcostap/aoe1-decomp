// attempt 2: direct new expression with real ctor and /GX EH
#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Object_List {
public:
    virtual ~RGE_Object_List();
    char gap[8];
    RGE_Object_List();
};
class RGE_Static_Object { protected: virtual RGE_Object_List* create_object_list(void); };
#endif

RGE_Object_List* RGE_Static_Object::create_object_list(void) {
    return new RGE_Object_List;
}
