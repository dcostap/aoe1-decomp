#include "../../../include/drawarea.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char check_area_width[(offsetof(TDrawArea, Width) == 0x18) ? 1 : -1];
typedef char check_area_height[(offsetof(TDrawArea, Height) == 0x1C) ? 1 : -1];
typedef char check_area_offsets[(offsetof(TDrawArea, CurDisplayOffsets) == 0xC0) ? 1 : -1];
typedef char check_system_type[(offsetof(TDrawSystem, DrawType) == 0x478) ? 1 : -1];
typedef char check_span_start[(offsetof(VSpan_Node, StartPx) == 8) ? 1 : -1];
typedef char check_span_end[(offsetof(VSpan_Node, EndPx) == 12) ? 1 : -1];

static int lock_calls, unlock_calls, fail_lock;
static TDrawArea* expected_receiver;
static const char* expected_name;
static char* locked_name;

// Test doubles only. The game links its real Lock and Unlock implementations.
unsigned char* TDrawArea::Lock(char* name, int wait)
{
    if (this != expected_receiver || strcmp(name, expected_name) || wait != 1) exit(90);
    ++lock_calls;
    locked_name = name;
    return fail_lock ? 0 : (unsigned char*)1;
}
void TDrawArea::Unlock(char* name)
{
    if (this != expected_receiver || name != locked_name || strcmp(name, expected_name)) exit(91);
    ++unlock_calls;
}

static void setup(TDrawArea* area, TDrawSystem* system, unsigned char* buffer,
                  void** rows, int width, int height, int align)
{
    memset(area, 0, sizeof(*area));
    area->DrawSystem = system;
    area->Width = width;
    area->Height = height;
    area->CurDisplayOffsets = rows;
    for (int y = 0; y < height; ++y) rows[y] = buffer + y * 80 + 8 + align;
}

static int clear_tests(TDrawArea* area, TDrawSystem* system)
{
    unsigned char actual[3200], expected[3200];
    void* rows[40];
    for (int i = 0; i < 1024; ++i) {
        int width = 1 + i % 29, height = 1 + i % 13, align = (i >> 3) & 3;
        tagRECT rect = {i % 45 - 8, i % 19 - 4, 0, 0};
        rect.right = rect.left + (i / 7) % 40 - 4;
        rect.bottom = rect.top + (i / 11) % 16 - 2;
        tagRECT* selected = i % 7 ? &rect : 0;
        system->DrawType = (unsigned char)(i % 3);
        TDrawSystem* owner = i % 5 ? system : 0;
        setup(area, owner, actual, rows, width, height, align);
        memset(actual, 0xCD, sizeof(actual));
        memcpy(expected, actual, sizeof(actual));
        lock_calls = unlock_calls = 0;
        fail_lock = i % 11 == 0;
        expected_receiver = area;
        expected_name = "PtrClear";
        int left = selected ? rect.left : 0;
        int top = selected ? rect.top : 0;
        int right = selected ? rect.right : width;
        int bottom = selected ? rect.bottom : height;
        int valid = right >= 0 && left <= right && left < width && bottom >= 0 && top <= bottom && top < height;
        int locked = valid && owner && owner->DrawType == 2;
        if (valid && !(locked && fail_lock)) {
            if (left < 0) left = 0;
            if (top < 0) top = 0;
            if (right >= width) right = width - 1;
            if (bottom >= height) bottom = height - 1;
            for (int y = top; y <= bottom; ++y)
                memset(expected + y*80 + 8 + align + left, (unsigned char)i, right-left+1);
        }
        area->PtrClear(selected, i ^ 0xABCD8700);
        if (memcmp(actual, expected, sizeof(actual))) return 1;
        if (lock_calls != locked || unlock_calls != (locked && !fail_lock)) return 2;
    }
    return 0;
}

static int span_tests(TDrawArea* source, TDrawArea* dest, TDrawSystem* system)
{
    unsigned char input[3200], actual[3200], expected[3200];
    void* source_rows[40];
    void* dest_rows[40];
    VSpan_Node nodes[12][2];
    unsigned char* lists[12];
    for (int i = 0; i < 512; ++i) {
        int align = i & 3;
        tagRECT rect = {2, 1, 20, 8};
        int x = 5 + i % 5, y = i % 16;
        if (i % 13 == 0) rect.left = -1;
        if (i % 17 == 0) rect.bottom = 12;
        if (i % 19 == 0) x = -1;
        system->DrawType = (unsigned char)(i % 3);
        TDrawSystem* owner = i % 5 ? system : 0;
        setup(source, owner, input, source_rows, 24, 12, align);
        setup(dest, 0, actual, dest_rows, 40, 14, (align+1)&3);
        for (int j = 0; j < 3200; ++j) input[j] = (unsigned char)(j*37+i);
        memset(actual, 0xCD, sizeof(actual));
        memcpy(expected, actual, sizeof(actual));
        for (int row = 0; row < 12; ++row) {
            memset(nodes[row], 0, sizeof(nodes[row]));
            nodes[row][0].Next = &nodes[row][1];
            nodes[row][0].StartPx = row % 3;
            nodes[row][0].EndPx = row % 3 + i % 5;
            nodes[row][1].StartPx = 10;
            nodes[row][1].EndPx = 10 + i % 3;
            lists[row] = row % 3 ? (unsigned char*)&nodes[row][0] : 0;
        }
        lock_calls = unlock_calls = 0;
        fail_lock = i % 11 == 0;
        expected_receiver = dest;
        expected_name = "PtrSpanCopy";
        int valid = rect.left >= 0 && rect.left <= rect.right && rect.right < 24 &&
                    rect.top >= 0 && rect.top <= rect.bottom && rect.bottom < 12 &&
                    x >= 0 && x < 40 && y >= 0 && y < 14;
        int locked = valid && owner && owner->DrawType == 2;
        if (valid && !(locked && fail_lock)) {
            int count = rect.bottom - rect.top + 1;
            if (count + y > 14) count = 14-y;
            for (int row = 0; row < count; ++row) {
                VSpan_Node* node = (VSpan_Node*)lists[rect.top+row];
                while (node) {
                    memcpy(expected+(y+row)*80+8+((align+1)&3)+x+node->StartPx,
                           input+(rect.top+row)*80+8+align+rect.left+node->StartPx,
                           node->EndPx-node->StartPx+1);
                    node = node->Next;
                }
            }
        }
        source->PtrSpanCopy(dest, x, y, &rect, lists);
        if (memcmp(actual, expected, sizeof(actual))) return 3;
        if (lock_calls != locked || unlock_calls != 0) return 4;
    }
    return 0;
}

static int overlay_tests(TDrawArea* area, TDrawSystem* system)
{
    unsigned char actual[3200], expected[3200];
    void* rows[40];
    for (int i = 0; i < 512; ++i) {
        int width = 1+i%19, height = 1+i%8, align = i&3;
        int dx = i%3-1, dy = (i/3)%3-1, ox = i%4, oy = i%3;
        tagRECT source = {8, 5, 8+width-1, 5+height-1};
        tagRECT dest = {8+dx, 5+dy, 8+dx+width-1, 5+dy+height-1};
        system->DrawType = (unsigned char)(i%3);
        TDrawSystem* owner = i%5 ? system : 0;
        setup(area, owner, actual, rows, 40, 24, align);
        for (int j=0; j<3200; ++j) actual[j] = (unsigned char)(j*31+i);
        memcpy(expected, actual, sizeof(actual));
        lock_calls = unlock_calls = 0;
        fail_lock = i%11 == 0;
        expected_receiver = area;
        expected_name = "OverlayMemCopy";
        int active = dx != 0 || dy != 0;
        int locked = active && owner && owner->DrawType == 2;
        if (active && !(locked && fail_lock)) {
            int reverse = dy == 0 && dx < 0;
            int sy = (dy < 0 ? source.bottom : source.top) + oy;
            int ty = (dy < 0 ? dest.bottom : dest.top) + oy;
            int sx = (reverse ? source.right-3 : source.left) + ox;
            int tx = (reverse ? dest.right-3 : dest.left) + ox;
            int step_y = dy < 0 ? -1 : 1;
            int step_x = reverse ? -4 : 4;
            for (int row=0; row<height; ++row) {
                for (int word=0; word<(width+3)/4; ++word) {
                    unsigned long value;
                    memcpy(&value, expected+sy*80+8+align+sx+word*step_x, 4);
                    memcpy(expected+ty*80+8+align+tx+word*step_x, &value, 4);
                }
                sy += step_y;
                ty += step_y;
            }
        }
        area->OverlayMemCopy(source, dest, dx, dy, ox, oy);
        if (memcmp(actual, expected, sizeof(actual))) return 5;
        if (lock_calls != locked || unlock_calls != (locked && !fail_lock)) return 6;
    }
    return 0;
}

int main()
{
    // Controlled object images exercise the native ABI without game constructors.
    TDrawArea* a = (TDrawArea*)calloc(1, sizeof(TDrawArea));
    TDrawArea* b = (TDrawArea*)calloc(1, sizeof(TDrawArea));
    TDrawSystem* system = (TDrawSystem*)calloc(1, sizeof(TDrawSystem));
    if (!a || !b || !system) return 80;
    int result = clear_tests(a, system);
    if (!result) result = span_tests(a, b, system);
    if (!result) result = overlay_tests(a, system);
    printf("Drawing methods: %s (%d)\n", result ? "FAILED" : "PASS", result);
    free(system);
    free(b);
    free(a);
    return result;
}
