// VA: 00489E90 ~RGE_Panel_Tool_Box dtor (186B)
// rpnl_tbx.cpp lines 166-174
// Has EH frame (fs:[0]), needs /GX

#ifndef RPNL_TBX_TU_CONTEXT
class TPanel {
public:
    virtual ~TPanel();
    char gap4[0xFC];
};

class SomeChild {
public:
    virtual ~SomeChild();
};

class RGE_Panel_Tool_Box : public TPanel {
public:
    SomeChild* field_100;
    SomeChild* field_104;
    SomeChild* field_108;
    SomeChild* field_10C;
    SomeChild* field_110;
    SomeChild* field_114;
    SomeChild* field_118;
    
    virtual ~RGE_Panel_Tool_Box();
};
#endif

RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box() {
    delete field_100;
    delete field_104;
    delete field_10C;
    delete field_108;
    delete field_110;
    delete field_114;
    delete field_118;
}
