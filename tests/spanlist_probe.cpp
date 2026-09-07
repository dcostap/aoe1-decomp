#include "../include/spanlist.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Snapshot output is outside this probe. Fail if the test reaches it.
void TDrawArea::GetPalette(tagPALETTEENTRY*) { abort(); }

static int check(TSpan_List_Manager& spans, const unsigned char* expected)
{
    unsigned char actual[64];
    memset(actual, 0, sizeof(actual));
    VSpan_Node* previous = 0;
    VSpan_Node* node = spans.Line_Head_Ptrs[0];
    int count = 0;
    while (node != 0) {
        if (++count > 64 || node->Prev != previous || node->StartPx < 0 ||
            node->EndPx >= 64 || node->StartPx > node->EndPx ||
            (previous != 0 && previous->EndPx + 1 >= node->StartPx)) {
            return 0;
        }
        for (int x = node->StartPx; x <= node->EndPx; ++x) actual[x] = 1;
        previous = node;
        node = node->Next;
    }
    if (count != spans.Span_Count[0] || previous != spans.Line_Tail_Ptrs[0]) return 0;
    if (count != 0 && (spans.LeftMostPx[0] != spans.Line_Head_Ptrs[0]->StartPx ||
                      spans.RightMostPx[0] != previous->EndPx)) return 0;
    return memcmp(actual, expected, sizeof(actual)) == 0;
}

static int add(TSpan_List_Manager& spans, unsigned char* expected, int left, int right)
{
    spans.AddSpan(left, right, 0);
    if (left > right) { int temp = left; left = right; right = temp; }
    for (int x = 0; x < 64; ++x) {
        if (x >= left && x <= right) expected[x] = 1;
    }
    if (!check(spans, expected)) {
        printf("FAIL after span [%d, %d]\n", left, right);
        return 0;
    }
    return 1;
}

int main()
{
    TSpan_List_Manager spans(64, 16);
    unsigned char expected[64];
    memset(expected, 0, sizeof(expected));
    if (!add(spans, expected, 0, 10) || !add(spans, expected, 20, 30) ||
        !add(spans, expected, 15, 40) || !add(spans, expected, 2, 3)) return 1;

    unsigned long state = 12345;
    for (int trial = 0; trial < 1000; ++trial) {
        spans.ResetAll();
        memset(expected, 0, sizeof(expected));
        for (int step = 0; step < 32; ++step) {
            state = state * 1664525UL + 1013904223UL;
            int left = (int)((state >> 16) % 72) - 4;
            state = state * 1664525UL + 1013904223UL;
            int right = left + (int)((state >> 16) % 15) - 7;
            if (!add(spans, expected, left, right)) {
                printf("trial=%d step=%d\n", trial, step);
                return 1;
            }
        }
    }
    puts("PASS: targeted right extension and 32000 deterministic span additions");
    return 0;
}
