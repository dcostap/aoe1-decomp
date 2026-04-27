// VA: 00489E90 ~RGE_Panel_Tool_Box dtor (186B)
// rpnl_tbx.cpp lines 166-174
// Has EH frame (fs:[0]), needs /GX

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
    
    ~RGE_Panel_Tool_Box();
};

RGE_Panel_Tool_Box::~RGE_Panel_Tool_Box() {
    delete field_100;
    delete field_104;
    delete field_108;
    delete field_10C;
}
