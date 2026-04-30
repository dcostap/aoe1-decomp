// VA: 00471B20 RGE_Player::addObject (71 B)
// PDB: player.cpp

class RGE_Static_Object;
class RGE_Object_Node;

class RGE_Object_List {
public:
    char gap[4];
    RGE_Object_Node* add_node(RGE_Static_Object* object);
};

// RGE_Game_World has updateObject at vtable offset 0xF8 (slot 62)
// We declare 62 padding virtual methods to reach the right slot
class RGE_Game_World {
public:
    virtual void pad00();
    virtual void pad01();
    virtual void pad02();
    virtual void pad03();
    virtual void pad04();
    virtual void pad05();
    virtual void pad06();
    virtual void pad07();
    virtual void pad08();
    virtual void pad09();
    virtual void pad0A();
    virtual void pad0B();
    virtual void pad0C();
    virtual void pad0D();
    virtual void pad0E();
    virtual void pad0F();
    virtual void pad10();
    virtual void pad11();
    virtual void pad12();
    virtual void pad13();
    virtual void pad14();
    virtual void pad15();
    virtual void pad16();
    virtual void pad17();
    virtual void pad18();
    virtual void pad19();
    virtual void pad1A();
    virtual void pad1B();
    virtual void pad1C();
    virtual void pad1D();
    virtual void pad1E();
    virtual void pad1F();
    virtual void pad20();
    virtual void pad21();
    virtual void pad22();
    virtual void pad23();
    virtual void pad24();
    virtual void pad25();
    virtual void pad26();
    virtual void pad27();
    virtual void pad28();
    virtual void pad29();
    virtual void pad2A();
    virtual void pad2B();
    virtual void pad2C();
    virtual void pad2D();
    virtual void pad2E();
    virtual void pad2F();
    virtual void pad30();
    virtual void pad31();
    virtual void pad32();
    virtual void pad33();
    virtual void pad34();
    virtual void pad35();
    virtual void pad36();
    virtual void pad37();
    virtual void pad38();
    virtual void pad39();
    virtual void pad3A();
    virtual void pad3B();
    virtual void pad3C();
    virtual void pad3D();
    virtual void updateObject(RGE_Static_Object* object); // slot 0x3E, vtable +0xF8
};

class RGE_Player {
public:
    char gap_00[0x28];
    RGE_Object_List* objects;             // +0x28
    RGE_Object_List* sleeping_objects;    // +0x2C
    RGE_Object_List* doppleganger_objects; // +0x30
    char gap_34[0x8];
    RGE_Game_World* world;                // +0x3C

    RGE_Object_Node* addObject(RGE_Static_Object* object, int is_sleeping, int use_doppleganger);
};

RGE_Object_Node* RGE_Player::addObject(RGE_Static_Object* object, int is_sleeping, int use_doppleganger) {
    RGE_Object_Node* node;

    if (is_sleeping != 0) {
        node = this->sleeping_objects->add_node(object);
    } else if (use_doppleganger != 0) {
        node = this->doppleganger_objects->add_node(object);
    } else {
        node = this->objects->add_node(object);
    }

    this->world->updateObject(object);
    return node;
}
