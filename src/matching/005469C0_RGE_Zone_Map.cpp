#include <stdlib.h>

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
    free(this->field_404);
    free(this->field_408);
    free(this->field_510);
}
