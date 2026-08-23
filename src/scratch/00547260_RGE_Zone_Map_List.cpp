class Base_RGE_Zone_Map_List {
public:
    virtual ~Base_RGE_Zone_Map_List();
};

class RGE_Zone_Map_List : public Base_RGE_Zone_Map_List {
};

extern "C" void probe_RGE_Zone_Map_List(RGE_Zone_Map_List* p);
#pragma alloc_text(".xtra", probe_RGE_Zone_Map_List)
extern "C" void probe_RGE_Zone_Map_List(RGE_Zone_Map_List* p) {
    p->RGE_Zone_Map_List::~RGE_Zone_Map_List();
}
