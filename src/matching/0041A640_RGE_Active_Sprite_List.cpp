class RGE_Static_Object;

class RGE_Active_Sprite_List {
public:
    virtual void destroy();
    int list;
    RGE_Static_Object* owner;

    RGE_Active_Sprite_List(RGE_Static_Object* param);
};

RGE_Active_Sprite_List::RGE_Active_Sprite_List(RGE_Static_Object* param) {
    list = 0;
    owner = param;
}
