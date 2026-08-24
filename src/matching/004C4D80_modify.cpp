// VA: 004C4D80 RGE_Static_Object::modify

#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void setHealth(int owner, int unk, int amount);
    virtual void setDamage(int owner, int unk, int amount);

    int id;
    void* master_obj;
    int owner;
    void* sprite;
    void* old_sprite;
    void* sprite_list;
    void* tile;
    void* inside_obj;
    void* objects;
    short screen_x_offset;
    short screen_y_offset;
    short shadow_x_offset;
    short shadow_y_offset;
    volatile float hp;
    char gap_34[0x14];
    unsigned char object_state;

    void modify(volatile float value, unsigned char type);
};
#endif

void RGE_Static_Object::modify(volatile float value, unsigned char type) {
    switch (type) {
    case 0:
        {
            int maxHp = *(short*)((char*)this->master_obj + 0x26);
            this->hp = (float)(short)(long)(value * this->hp / maxHp);
        }
        break;
    case 1:
        if (this->tile != 0 && this->object_state == 2) {
            this->setDamage(this->owner, 0, -1);
            this->setHealth(this->owner, 0, (long)value);
            return;
        }
        break;
    }
}
