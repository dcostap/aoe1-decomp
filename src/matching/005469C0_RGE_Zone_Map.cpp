void __cdecl operator_delete(void* p);

class RGE_Zone_Map {
public:
    char gap_00[0x404];
    void* field_404;
    void* field_408;
    char gap_40C[0x104];
    void* field_510;

    ~RGE_Zone_Map();
};

RGE_Zone_Map::~RGE_Zone_Map() {
    operator_delete(this->field_404);
    operator_delete(this->field_408);
    operator_delete(this->field_510);
}