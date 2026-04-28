// VA: 0046A8E0 Path::operator+(const Path& other) const
// Path.cpp lines 70-77, 253 bytes, UDT return with EH frame
// FLAGS: config/flags/0046A8E0_operator.rsp
//
// INVESTIGATED: ~14 source-shaped probes + 1728-variant lab (6 source × /GX × 12 small × 12 risky)
// BLOCKER: VC5 codegen-family problem — pinned toolchain allocates `other.maxSizeValue` into `eax`
//          (mov eax,[ebx+28h]) at offset 32; original uses `edx` (mov edx,[ebx+28h]).
//          This single register choice cascades through the entire function.
// NEGATIVE EVIDENCE: 1728 variants in 30 asm groups; 840 with-GX+default-opt all hit offset 32
//          in the same basin. The other 888 (risky/alternate flags) hit offset 0 or 24 with
//          different loop structures (count-down, frame-pointer, etc.) — none produce offset >32.
// Not ready for accepted_drift: remaining diff cascades from prolog, not localized.
// Leave in scratch.

void* __cdecl operator_new(unsigned int size);
void __cdecl operator_delete(void* ptr);

struct Waypoint {
    float x;
    float y;
    float z;
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

    Path(int max_size);
    int insertAtEnd(Waypoint wp);
    ~Path();
    Path operator+(const Path& other) const;
};

Path Path::operator+(const Path& other) const {
    Path newPath(maxSizeValue + other.maxSizeValue);
    if (currentSizeValue > 0) {
        for (int i = 0; i < currentSizeValue; i++) {
            newPath.insertAtEnd(pathValue[i]);
        }
    }
    if (other.currentSizeValue > 0) {
        int offset = newPath.currentSizeValue * 16;
        for (int i = 0; i < other.currentSizeValue; i++) {
            newPath.insertAtEnd(*(Waypoint*)((char*)other.pathValue + offset));
            offset += 16;
        }
    }
    return newPath;
}
