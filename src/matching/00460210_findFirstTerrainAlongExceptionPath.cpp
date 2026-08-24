// VA: 00460210 RGE_Moving_Object::findFirstTerrainAlongExceptionPath
// Attempt log:
// 1: placeholder helper-only source was structurally unrelated to the 406-byte oracle.
// 2: reconstructed the exception-path segment scan from the packet: typed XYPoint
//    locals, repeated currentWaypoint/natural float-to-int conversions,
//    firstTileAlongLine vslot +1B4,
//    and the -1.0 output sentinel. Initial typed baseline follows the original
//    local declaration order; further VC5 stack-home tuning may be needed.
// 3: natural top-tested while plus one named success result reached exact size/frame,
//    26/26 calls, and 16 differing bytes; residual drift is local stack-home ordering
//    and branch-tail displacement around the coordinate temporaries.
// 4: direct zero returns for early path failures matched the oracle's separate
//    return tail and reduced drift to 12 bytes. A named contiguous segment
//    aggregate reached 9 bytes but was not retained; separate XYPoint locals
//    remain the natural source. Remaining drift is local-home allocation only.
// 5: testing the evidence-backed contiguous segment with pointer ABI and
//    explicit y-field addresses; the loop counter remains separate.
// 6: the segment/pointer form kept size, frame, and ordered calls aligned but
//    emitted the same 12-byte local-home drift; retained as the clean lead.
// 7: canonical contiguous XYPoint locals with typed point addresses and rVal.x
//    removed the decompiler field mapping and reached an exact 406-byte match.
// The exact-donor XYPoint* virtual ABI matches the executable.

extern float DAT_00570B80;

#ifndef MOVE_OBJ_CANONICAL_TU
struct Waypoint {
    float x;
    float y;
    float z;
    unsigned char facet;
    unsigned char pad[3];
};

struct XYPoint {
    int x;
    int y;
};

class Path {
public:
    char data[0x34];
    void initToStart();
    int moveToNextWaypoint();
    int numberOfWaypoints();
    Waypoint* currentWaypoint();
};

class RGE_Moving_Object {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58();
    virtual void vf59();
    virtual void vf60();
    virtual void vf61();
    virtual void vf62();
    virtual void vf63();
    virtual void vf64();
    virtual void vf65();
    virtual void vf66();
    virtual void vf67();
    virtual void vf68();
    virtual void vf69();
    virtual void vf70();
    virtual void vf71();
    virtual void vf72();
    virtual void vf73();
    virtual void vf74();
    virtual void vf75();
    virtual void vf76();
    virtual void vf77();
    virtual void vf78();
    virtual void vf79();
    virtual void vf80();
    virtual void vf81();
    virtual void vf82();
    virtual void vf83();
    virtual void vf84();
    virtual void vf85();
    virtual void vf86();
    virtual void vf87();
    virtual void vf88();
    virtual void vf89();
    virtual void vf90();
    virtual void vf91();
    virtual void vf92();
    virtual void vf93();
    virtual void vf94();
    virtual void vf95();
    virtual void vf96();
    virtual void vf97();
    virtual void vf98();
    virtual void vf99();
    virtual void vf100();
    virtual void vf101();
    virtual void vf102();
    virtual void vf103();
    virtual void vf104();
    virtual void vf105();
    virtual void vf106();
    virtual void vf107();
    virtual void vf108();
    virtual int firstTileAlongLine(XYPoint*, XYPoint*, XYPoint*, int, int, int);

    char gap04[0xD4];
    Path exceptionPathValue; // +D8

    int findFirstTerrainAlongExceptionPath(int, float*, float*);
};
#endif

int RGE_Moving_Object::findFirstTerrainAlongExceptionPath(
    int terrain, float* result_x, float* result_y) {
    int i;
    XYPoint p1, p2, rVal;
    Path* path = &this->exceptionPathValue;

    if (path->numberOfWaypoints() < 2) {
        return 0;
    }

    path->initToStart();
    if (path->currentWaypoint() == 0) {
        return 0;
    }

    p1.x = (int)path->currentWaypoint()->x;
    p1.y = (int)path->currentWaypoint()->y;
    path->moveToNextWaypoint();
    if (path->currentWaypoint() == 0) {
        return 0;
    }

    p2.x = (int)path->currentWaypoint()->x;
    p2.y = (int)path->currentWaypoint()->y;
    i = 1;
    while (i < path->numberOfWaypoints()) {
        if (this->firstTileAlongLine(&p1, &p2, &rVal,
                                     terrain, terrain, 1) == 1) {
            float result = (float)rVal.x - DAT_00570B80;
            *result_x = result;
            *result_y = result;
            return 1;
        }

        p1.x = (int)path->currentWaypoint()->x;
        p1.y = (int)path->currentWaypoint()->y;
        path->moveToNextWaypoint();
        if (path->currentWaypoint() == 0) {
            return 0;
        }

        p2.x = (int)path->currentWaypoint()->x;
        p2.y = (int)path->currentWaypoint()->y;
        ++i;
    }

    *result_x = -1.0f;
    *result_y = -1.0f;
    return 0;
}
