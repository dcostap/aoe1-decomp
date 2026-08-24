#ifndef PATH_TU_CONTEXT
void __cdecl operator_delete(void* ptr);

struct Waypoint {
    char bytes[0x10];
};

class Path {
public:
    char gap_00[0x24];
    Waypoint* pathValue;

    ~Path();
};
#endif

Path::~Path() {
    if (pathValue != 0) {
        operator_delete(pathValue);
    }
}
