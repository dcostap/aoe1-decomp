// VA: 0051B070 TRIBE_Panel_Object::~TRIBE_Panel_Object (148B)
// tpnl_obj.cpp
// FLAGS: /GX (original has EH registration while deleting owned TShape members)
// Attempt log:
// try 1: natural typed destructor with two owned shape deletes and base TPanel dtor.

#ifndef AOE1_TPNL_OBJ_CONTEXT_H
void operator delete(void* p);

class TPanel {
public:
    virtual ~TPanel();
};

class TShape {
public:
    ~TShape();
};

class TRIBE_Panel_Object : public TPanel {
public:
    char gap_004[0x100 - 0x004];
    TShape* health_pic;
    TShape* item_pic;

    virtual ~TRIBE_Panel_Object();
};
#endif

TRIBE_Panel_Object::~TRIBE_Panel_Object()
{
    if (this->health_pic != 0) {
        delete this->health_pic;
        this->health_pic = 0;
    }

    if (this->item_pic != 0) {
        delete this->item_pic;
        this->item_pic = 0;
    }
}
