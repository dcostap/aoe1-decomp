#ifndef GAMEINFO_SHARED_CONTEXT
class RGE_Person_Info {
public:
    char* get_name();
};
#endif

char* RGE_Person_Info::get_name() { return (char*)this; }
