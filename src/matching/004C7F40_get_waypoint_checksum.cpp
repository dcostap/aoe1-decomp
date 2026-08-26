#ifndef RGE_STAT_OBJ_SHARED_CONTEXT
class RGE_Static_Object {
public:
    virtual ~RGE_Static_Object();
    virtual long get_waypoint_checksum();
};
#endif

// BINARY NOTE: the shipped getter returns long and is virtual.
long RGE_Static_Object::get_waypoint_checksum() { return 0; }
