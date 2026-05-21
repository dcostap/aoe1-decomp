// VA: 00410050 AIPlayStatus::copy (170 bytes)
// ACCEPTED_DRIFT 2026-05-21 (Boss approved): behavior-equivalent copy with localized 7-byte positional / 4-byte edit drift.
// Best validation: 170B, 4.1176% positional / 2.3529% edit, first mismatch 004100BE.
// Drift is confined to setup before the grouping copy loop: rebuilt computes dest/diff before
// `mov esi, edx` (`lea eax,[ecx+4]; sub edi,ecx; mov esi,edx`) while original does
// `mov esi,edx; lea eax,[ecx+4]; sub edi,ecx`. Loop body, counts, copied bytes,
// originalHitPoints loop, callee-saved registers, and stack cleanup are byte-identical after resync.
// Tried count placement, source/dest/diff declaration order, struct-loop form, alias/pointer-loop form,
// register hints, int-vs-pointer diff, volatile base, and lastPhase temp variants; this is the tightest basin.

struct GroupingStruct {
    int id;
    unsigned char field1;
    unsigned char field2;
    unsigned char pad[2];
};

struct PointValue {
    int xValue;
    int yValue;
    int zValue;
};

struct AIPlayStatus {
    GroupingStruct groupings[50];
    int playNumberValue;
    int targetValue;
    PointValue originalPointValue;
    int originalHitPointsValue[5];
    unsigned char currentPhaseValue;
    char pad_1B9[3];
    int savedAttackerValue;
    int lastPhaseChangeTimeValue;

    void copy(AIPlayStatus* other);
};

void AIPlayStatus::copy(AIPlayStatus* other)
{
    int count = 50;
    this->playNumberValue = other->playNumberValue;
    this->targetValue = other->targetValue;
    int z = other->originalPointValue.zValue;
    int y = other->originalPointValue.yValue;
    int x = other->originalPointValue.xValue;
    this->originalPointValue.xValue = x;
    this->originalPointValue.yValue = y;
    this->originalPointValue.zValue = z;
    this->currentPhaseValue = other->currentPhaseValue;
    this->savedAttackerValue = other->savedAttackerValue;

    AIPlayStatus* p = other;
    this->lastPhaseChangeTimeValue = p->lastPhaseChangeTimeValue;
    unsigned char* dest = (unsigned char*)this + 4;
    int diff = (unsigned char*)p - (unsigned char*)this;
    unsigned char* src = (unsigned char*)p;

    do {
        *(int*)(dest - 4) = *(int*)src;
        src += 8;
        *dest = *(dest + diff);
        *(dest + 1) = *(src - 3);
        dest += 8;
        count--;
    } while (count);

    int* hpDest = &this->originalHitPointsValue[0];
    int hpCount = 5;
    do {
        *hpDest = *(int*)((unsigned char*)hpDest + diff);
        hpDest++;
        hpCount--;
    } while (hpCount);
}
