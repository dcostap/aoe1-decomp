// VA: 0046A8E0 Path::operator+(const Path& other) const
// Path.cpp lines 70-77, 253 bytes, UDT return with EH frame
// FLAGS: config/flags/0046A8E0_operator.rsp
//
// INVESTIGATED: prior ~14 source-shaped probes + 1728-variant lab, then a fresh
//              default-/GX/source-shape pass in this session.
// CURRENT BEST: 253-byte function, exact frame/size/CFG/calls and 251/253 bytes.
// BLOCKER: two bytes remain at 0046A91F: VC5 emits `test eax,eax` for the first
//          count guard while the oracle uses `cmp eax,ebp` (EBP is the proven
//          zero byte-offset local). Constructor register allocation and every
//          later byte are now exact.
// NEGATIVE EVIDENCE: prior default-/GX variants all used the wrong constructor
//          max-size register basin. Removing /Og- restored the original EH frame;
//          do/while loops plus persistent offset/count topology restored size and
//          all loop/copy bytes. Reversed comparison spelling and comparing against
//          the zero offset did not change `test`; inline donor method bodies moved
//          the constructor basin back and were rolled back.
// Not ready for accepted_drift: remaining drift is localized but compiler-shaped.
// Leave in scratch.
// probe sa-e158994a-r1 #3: default /GX exposed the target's exact EH frame;
// switched both copy loops to do/while so the binary's single pre-loop guard
// is represented directly, and seeded the second source offset from the
// first loop's copied count rather than rereading newPath.currentSizeValue.
// probe sa-e158994a-r1 #4: reversed the first guard comparison; emitted code
// unchanged, so kept the binary-supported 0 < count spelling.
// probe sa-e158994a-r1 #5: moved offset initialization before Path construction;
// worsened ctor/local scheduling (23 bytes), restored.
// probe sa-e158994a-r1 #6: restored the 4-byte best source after #5.
// probe sa-e158994a-r1 #7: canonical padded Waypoint/typed start-goal layout;
// emitted code unchanged, retained for source ownership.
// probe sa-e158994a-r1 #8: added proven same-TU Path method declarations from
// exact operator= donor; fixed the two constructor register bytes.
// probe sa-e158994a-r1 #9: compared currentSizeValue to the zero offset local;
// emitted code unchanged and retained ordinary count comparison.
// probe sa-e158994a-r1 #10: restored inline donor method bodies; they moved the
// constructor register basin away, so retained declarations only and rolled back.
// probe refill-46A8E0-r1 #1: exact operator<< donor TU context (iostream.h plus
// class/public Path surface) added four bytes and lost later exact blocks; rolled back.
// probe refill-46A8E0-r1 #2: isolated class/public Path surface; emitted code unchanged.
// probe refill-46A8E0-r1 #3: isolated class/public Waypoint surface from operator<<;
// emitted code unchanged, retained as natural donor context.
// probe refill-46A8E0-r1 #4: reordered post-constructor offset/count declarations;
// swapped zero initialization and worsened to five bytes, rolled back.
// probe refill-46A8E0-r1 #5: retested Ghidra-supported pre-constructor offset with
// full donor declarations; worsened to 21 bytes, rolled back.
// Main-agent audit restored direct Waypoint array indexing. The byte-offset
// cursor was a decompiler artifact and did not express distinct behavior.

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

class Waypoint {
public:
    float x;
    float y;
    float z;
    unsigned char facetToNextWaypoint;
    unsigned char pad[3];
};

class Path {
public:
    unsigned long timeStampValue;
    Waypoint startValue;
    Waypoint goalValue;
    Waypoint* pathValue;
    int maxSizeValue;
    int currentSizeValue;
    int currentWaypointValue;

    Path(int max_size);
    int growMaxSize(int new_maximum);
    void dummy(void);
    void setMaxSize(int new_maximum);
    Path& operator=(const Path& other);
    int insertAtEnd(Waypoint wp);
    ~Path();
    Path operator+(const Path& other) const;
};

Path Path::operator+(const Path& other) const {
    Path newPath(maxSizeValue + other.maxSizeValue);
    int i = 0;
    if (0 < currentSizeValue) {
        do {
            newPath.insertAtEnd(pathValue[i]);
            i++;
        } while (i < currentSizeValue);
    }
    int j = 0;
    if (other.currentSizeValue > 0) {
        do {
            newPath.insertAtEnd(other.pathValue[j]);
            j++;
        } while (j < other.currentSizeValue);
    }
    return newPath;
}
