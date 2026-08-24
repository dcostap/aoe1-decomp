#ifndef TMAP_GROUP_CONTEXT
class Base_TRIBE_Map {
public:
    virtual ~Base_TRIBE_Map();
};

class TRIBE_Map : public Base_TRIBE_Map {
public:
    virtual ~TRIBE_Map();
};
#endif

TRIBE_Map::~TRIBE_Map() {
}
