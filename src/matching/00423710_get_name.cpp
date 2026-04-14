class RGE_Campaign {
public:
    virtual ~RGE_Campaign();
    char field_4[1];
    char* get_name();
};

char* RGE_Campaign::get_name() { return this->field_4; }
