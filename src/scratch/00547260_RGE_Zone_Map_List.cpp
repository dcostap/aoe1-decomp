// The shipped destructor is a five-byte tail thunk to delete_zone_maps.
// Keep the owner as a real nonvirtual member definition so the grouped TU
// emits the target symbol instead of the old probe-only helper.
#ifndef ZONE_MAP_TU_BUILD
class RGE_Zone_Map_List {
public:
    ~RGE_Zone_Map_List();
    void delete_zone_maps();
};
#endif

RGE_Zone_Map_List::~RGE_Zone_Map_List()
{
    this->delete_zone_maps();
}
