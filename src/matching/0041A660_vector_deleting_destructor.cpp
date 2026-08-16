class RGE_Active_Sprite_List {
public:
    virtual ~RGE_Active_Sprite_List();
    void *vector_deleting_destructor(unsigned int param_1);
};

void operator_delete(void *param_1);

void *RGE_Active_Sprite_List::vector_deleting_destructor(unsigned int param_1) {
    this->RGE_Active_Sprite_List::~RGE_Active_Sprite_List();
    if ((param_1 & 1) != 0) {
        operator_delete(this);
    }
    return this;
}
