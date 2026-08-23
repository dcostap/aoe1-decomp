// VA: 0045CAA0 RGE_Moving_Object::setup
// Attempt log:
// try 1: natural load/setup reconstruction from packet; models rge_read sequence,
// Path append/reset, user-defined waypoint allocation/load, and version-gated fields.

extern "C" void rge_read(int fd, void* dst, int size);
extern void* __cdecl operator new(unsigned int size);

extern float savegame_version;
extern float version_570B54;
extern float version_570B58;
extern float version_570B5C;

struct Waypoint { int x; int y; int z; int w; };
struct UserWaypoint { char data[3]; };

class Path {
public:
    char data[0x34];
    Path();
    ~Path();
    void append(Waypoint wp);
    void reset();
    void add_default();
};

class RGE_Animated_Object {
public:
    virtual ~RGE_Animated_Object();
    int setup(int fd, void* world);
    char gap04[0x88];
};

class RGE_Moving_Object : public RGE_Animated_Object {
public:
    int field_8c;
    int field_90;
    int field_94;
    int field_98;
    int field_9c;
    int field_a0;
    Path path;              // +a4
    Path exceptionPath;     // +d8
    Waypoint waypoint1;     // +10c
    Waypoint waypoint2;     // +11c
    int field_12c;
    int field_130;
    int field_134;
    int field_138;
    int field_13c;
    int field_140;
    int field_144;
    int field_148;
    char gap_14c[9];
    unsigned char byte_155;
    unsigned char byte_156;
    char gap_157;
    int point_a;
    int point_b;
    int point_c;
    int point_d;
    UserWaypoint* userDefinedWaypoints; // +168
    int numberUserDefinedWaypointsValue; // +16c
    int maxUserDefinedWaypoints; // +170
    unsigned char byte_174;
    char gap_175[3];
    int finalWaypoint; // +178
    unsigned char byte_17c;
    unsigned char byte_17d;

    int setup(int fd, void* world);
};

int RGE_Moving_Object::setup(int fd, void* world)
{
    RGE_Animated_Object::setup(fd, world);
    this->gap04[0x4a] = 0x1e;

    rge_read(fd, &this->field_8c, 4);
    rge_read(fd, &this->field_90, 4);
    rge_read(fd, &this->field_94, 4);
    rge_read(fd, &this->field_98, 4);
    rge_read(fd, &this->field_9c, 4);
    rge_read(fd, &this->field_a0, 4);

    int count;
    rge_read(fd, &count, 4);
    for (int i = 0; i < count; ++i) {
        Waypoint wp;
        rge_read(fd, &wp, 0x10);
        this->path.append(wp);
    }

    int reset_count;
    rge_read(fd, &reset_count, 4);
    int j = 0;
    this->path.reset();
    for (; j < reset_count; ++j) {
        this->path.add_default();
    }

    rge_read(fd, &this->waypoint1, 0x10);
    rge_read(fd, &this->waypoint2, 0x10);
    rge_read(fd, &this->field_12c, 4);
    rge_read(fd, &this->field_130, 4);
    rge_read(fd, &this->field_134, 4);
    rge_read(fd, &this->field_138, 4);
    rge_read(fd, &this->field_13c, 4);
    rge_read(fd, &this->field_140, 4);
    rge_read(fd, &this->field_144, 4);
    rge_read(fd, &this->field_148, 4);
    rge_read(fd, &this->byte_155, 1);
    rge_read(fd, &this->byte_156, 1);

    rge_read(fd, &this->numberUserDefinedWaypointsValue, 4);
    rge_read(fd, &this->maxUserDefinedWaypoints, 4);
    this->userDefinedWaypoints = (UserWaypoint*)operator new(this->maxUserDefinedWaypoints * 3);
    for (int k = 0; k < this->numberUserDefinedWaypointsValue; ++k) {
        rge_read(fd, &this->userDefinedWaypoints[k], 3);
    }

    rge_read(fd, &this->byte_174, 1);

    if (!(savegame_version < version_570B54)) {
        rge_read(fd, &this->point_a, 8);
        rge_read(fd, &this->point_c, 8);
    } else {
        this->point_a = -1;
        this->point_b = -1;
        this->point_c = -1;
        this->point_d = -1;
    }

    if (!(savegame_version < version_570B58)) {
        rge_read(fd, &this->finalWaypoint, 4);
        rge_read(fd, &this->byte_17c, 1);
    } else {
        this->finalWaypoint = 0x47c35000;
        this->byte_17c = 0xff;
    }

    if (!(savegame_version < version_570B5C)) {
        rge_read(fd, &this->byte_17d, 1);
        return 1;
    }
    this->byte_17d = 0xff;
    return 1;
}
