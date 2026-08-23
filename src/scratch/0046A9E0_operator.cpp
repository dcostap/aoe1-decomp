// VA: 0046A9E0 Path::operator=(const Path& other)
// Path.cpp lines 82-94, 241 bytes, no EH frame
//
// INVESTIGATION:
// probe 1: simplified realloc logic (if/else) -> 208 bytes (whole-struct copy)
// probe 2: field-by-field copy in second loop -> 240 bytes, 1 byte short of 241
// probe 3: dead else-if branch -> optimized away (still 240)
// probe 4: ternary expression -> 240 bytes
// probe 5: memcpy for realloc copy -> different approach
// probe 6: nested if with dead branch -> optimized away
// probe 7: switch/case -> 240 bytes, different encoding
// probe 8: variant lab (5 source shapes) -> 4 groups, 0 matches
// probe 9: inlined natural resize helper with the helper's own range guard
//          regenerated the previously missing redundant max-size tests.
// probe 10: changed helper growth to compute the new size in the parameter
//           before storing it, matching the original lea/add/store family.
// probe 11: removed the outer current-size guard; second copy loop now matches.
// probe 12: allocation/source-shape labs (helper style, locals, assign/comma,
//           getters, includes, flags) still collapse to the same 240-byte basin.
// probe 13: 4096-way standard-header combination lab over iostream/fstream/
//           stdlib/malloc/new/string/math/float/limits/assert/ctype/stdio all
//           produced one identical 240-byte group; headers do not move this basin.
// probe 14: investigator-suggested allocation forms ((maxSizeValue=new)*sizeof,
//           member-after-assignment, named count, and new Waypoint[maxSizeValue=new])
//           still miss; member-after-assignment moves to a worse 256-byte group.
// probe 15: sibling byte search found exact 8bc8/store/shl-ecx only in this
//           function; Path::Path(int) uses the shorter store/shl-eax form.
// probe 16: compound member growth plus class-surface context exact-matched.
// probe 17: reduced the context: the minimal proven match is compound growth in
//           setMaxSize plus a preceding inline growMaxSize body and a following
//           dummy member declaration. The dummy declaration is intentionally
//           unused VC5 class-surface context; no original name is known.
// probe 18: declaration-surface check: name/return type/int parameter are not
//           individually required; an intervening member decl with a parameter,
//           explicit void parameter, static/const variation, operator, or dtor
//           still matches, while no decl, foo(), or ctor-only loses the basin.

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

struct Waypoint {
    float x, y, z;
    unsigned char facetToNextWaypoint;
};

struct Path {
    int timeStampValue;
    float startValue[3];
    int gap_10;
    float goalValue[3];
    int gap_20;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;

    int growMaxSize(int new_maximum) {
        if (new_maximum == 0) {
            return maxSizeValue += maxSizeValue;
        } else {
            return maxSizeValue += new_maximum;
        }
    }

    void dummy(void);

    void setMaxSize(int new_maximum) {
        if (new_maximum == 0 || maxSizeValue <= new_maximum) {
            if (new_maximum == 0) {
                maxSizeValue += maxSizeValue;
            } else {
                maxSizeValue += new_maximum;
            }
            Waypoint* new_path = (Waypoint*)operator_new(maxSizeValue * 16);
            for (int i = 0; i < currentSizeValue; i++) {
                new_path[i].x = pathValue[i].x;
                new_path[i].y = pathValue[i].y;
                new_path[i].z = pathValue[i].z;
                new_path[i].facetToNextWaypoint = pathValue[i].facetToNextWaypoint;
            }
            if (pathValue != 0) {
                operator_delete(pathValue);
            }
            pathValue = new_path;
        }
    }

    Path& operator=(const Path& other);
};

Path& Path::operator=(const Path& other) {
    if (maxSizeValue < other.maxSizeValue) {
        setMaxSize(other.maxSizeValue);
    }
    for (int i = 0; i < other.currentSizeValue; i++) {
        pathValue[i].x = other.pathValue[i].x;
        pathValue[i].y = other.pathValue[i].y;
        pathValue[i].z = other.pathValue[i].z;
        pathValue[i].facetToNextWaypoint = other.pathValue[i].facetToNextWaypoint;
    }
    currentWaypointValue = other.currentWaypointValue;
    currentSizeValue = other.currentSizeValue;
    return *this;
}
