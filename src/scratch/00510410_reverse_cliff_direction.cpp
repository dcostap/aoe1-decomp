#ifndef TMAP_GROUP_CONTEXT
class TRIBE_Map {
public:
    long reverse_cliff_direction(long dir);
};
#endif

long TRIBE_Map::reverse_cliff_direction(long dir) {
    long result = dir + 2;
    if (result >= 4) result -= 4;
    return result;
}
