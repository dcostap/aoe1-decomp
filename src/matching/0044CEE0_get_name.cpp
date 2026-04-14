class RGE_Person_Info {
public:
    char* get_name();
};

char* RGE_Person_Info::get_name() { return (char*)this; }
