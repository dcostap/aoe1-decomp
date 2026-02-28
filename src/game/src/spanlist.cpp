#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include "../include/TSpan_List_Manager.h"
#include "../include/VSpanMiniList.h"
#include "../include/TShape.h"
#include "../include/Shape_Info.h"
#include "../include/TDrawArea.h"
#include "../include/custom_debug.h"

// NOTE: This file is a reimplementation based on immutable references:
// - `src/game/src/spanlist.cpp.asm`
// - `src/game/src/spanlist.cpp.decomp`
//
// It intentionally keeps the data layouts from dumped headers intact.

// -------------------------
// TSpan_Node_List
// -------------------------

TSpan_Node_List::TSpan_Node_List(int initial_zone_size, int default_grow_size, int element_size) {
    this->Free_Pool_Zone = -1;
    this->Free_Pool_Index = -1;
    this->Zone_Ptrs = (VSpan_Node**)0;
    this->Zone_Size_Ptrs = (int*)0;
    this->Used_Zones = 0;
    this->Free_Head = (VSpan_Node*)0;
    this->Total_Blocks = 0;
    this->Free_Blocks = 0;
    this->Element_Size = element_size;
    this->Max_Zones = 8;
    this->Default_Grow_Size = default_grow_size;
    this->ResetStats();
    this->SetNumZones(8);
    this->InitNewZone(initial_zone_size);
}

TSpan_Node_List::~TSpan_Node_List() {
    for (int i = 0; i < this->Used_Zones; ++i) {
        if (this->Zone_Ptrs && this->Zone_Ptrs[i]) {
            free(this->Zone_Ptrs[i]);
        }
    }
    if (this->Zone_Ptrs) free(this->Zone_Ptrs);
    if (this->Zone_Size_Ptrs) free(this->Zone_Size_Ptrs);
}

void TSpan_Node_List::SetNumZones(int num_zones) {
    if (this->Max_Zones <= num_zones) {
        VSpan_Node** new_zone_ptrs = (VSpan_Node**)calloc((size_t)num_zones, 4);
        int* new_zone_sizes = (int*)calloc((size_t)num_zones, 4);
        if (this->Zone_Ptrs) {
            for (int i = 0; i < this->Used_Zones; ++i) {
                new_zone_ptrs[i] = this->Zone_Ptrs[i];
                new_zone_sizes[i] = this->Zone_Size_Ptrs[i];
            }
            free(this->Zone_Ptrs);
            free(this->Zone_Size_Ptrs);
        }
        this->Zone_Ptrs = new_zone_ptrs;
        this->Zone_Size_Ptrs = new_zone_sizes;
        this->Max_Zones = num_zones;
    }
}

void TSpan_Node_List::InitNewZone(int zone_size) {
    if (this->Used_Zones == this->Max_Zones) {
        this->SetNumZones(this->Used_Zones + 4);
    }

    int zone_index = this->Used_Zones;
    this->Used_Zones = zone_index + 1;

    this->Zone_Size_Ptrs[zone_index] = zone_size;
    VSpan_Node* pool = (VSpan_Node*)malloc((size_t)this->Element_Size * (size_t)zone_size);
    this->Zone_Ptrs[zone_index] = pool;

    this->NewZone_Count = this->NewZone_Count + 1;
    this->Total_Blocks = this->Total_Blocks + zone_size;
    this->Free_Blocks = this->Free_Blocks + zone_size;

    if (this->Free_Pool_Zone == -1) {
        this->Free_Pool_Zone = zone_index;
        this->Free_Pool_Index = 0;
    }
}

VSpan_Node* TSpan_Node_List::GetNode() {
    if (this->Free_Blocks == 0) {
        this->InitNewZone(this->Default_Grow_Size);
    }

    VSpan_Node* node = this->Free_Head;
    if (node) {
        this->Free_Head = node->Next;
        this->Free_Blocks = this->Free_Blocks - 1;
        return node;
    }

    int pool_index = this->Free_Pool_Index;
    int pool_zone = this->Free_Pool_Zone;
    VSpan_Node* pool = this->Zone_Ptrs[pool_zone];

    int next_index = pool_index + 1;
    this->Free_Blocks = this->Free_Blocks - 1;
    this->Free_Pool_Index = next_index;

    if (next_index == this->Zone_Size_Ptrs[pool_zone]) {
        this->Free_Pool_Zone = pool_zone + 1;
        this->Free_Pool_Index = 0;
        if (pool_zone + 1 == this->Used_Zones) {
            this->Free_Pool_Zone = -1;
        }
    }

    return pool + pool_index;
}

void TSpan_Node_List::FreeNode(VSpan_Node* node) {
    if (!node) return;
    node->Next = this->Free_Head;
    node->Prev = (VSpan_Node*)0;
    this->Free_Head = node;
    this->Free_Blocks = this->Free_Blocks + 1;
}

int TSpan_Node_List::FreeThread(VSpan_Node* head, VSpan_Node* tail) {
    int count = 0;
    if (!head) return count;

    VSpan_Node* cur = head;
    if (!tail) {
        VSpan_Node* last = (VSpan_Node*)0;
        while (cur) {
            last = cur;
            count = count + 1;
            this->Free_Blocks = this->Free_Blocks + 1;
            cur = cur->Next;
        }
        last->Next = this->Free_Head;
        this->Free_Head = head;
        return count;
    }

    while (cur) {
        count = count + 1;
        this->Free_Blocks = this->Free_Blocks + 1;
        if (cur == tail) {
            cur = (VSpan_Node*)0;
        } else {
            cur = cur->Next;
        }
    }

    tail->Next = this->Free_Head;
    this->Free_Head = head;
    return count;
}

void TSpan_Node_List::ReclaimAllNodes() {
    this->Free_Head = (VSpan_Node*)0;
    this->Free_Pool_Zone = 0;
    this->Free_Pool_Index = 0;
    this->Free_Blocks = this->Total_Blocks;
    this->Reset_Count = this->Reset_Count + 1;
}

void TSpan_Node_List::ResetStats() {
    this->Alloc_Count = 0;
    this->Dealloc_Count = 0;
    this->NewZone_Count = 0;
    this->Reset_Count = 0;
}

// -------------------------
// TSpan_List_Manager
// -------------------------

static int span_initial_zone_size_from_pixels(int num_pixels, int num_lines) {
    // Matches `spanlist.cpp.decomp` ctor: ceil((num_pixels + 31) / 32) * num_lines.
    // Note: original expression includes sign handling; widths are non-negative in practice.
    int blocks_per_line = (num_pixels + 0x1f) >> 5;
    return blocks_per_line * num_lines;
}

TSpan_List_Manager::TSpan_List_Manager(int num_pixels, int num_lines)
    : VSList(span_initial_zone_size_from_pixels(num_pixels, num_lines), num_lines << 4, 0x10) {
    this->Num_Lines = num_lines;
    if (this->Num_Lines < 0x10) this->Num_Lines = 0x10;

    this->Num_Pixels = num_pixels;
    if (this->Num_Pixels < 0x10) this->Num_Pixels = 0x10;

    this->Line_Head_Ptrs = (VSpan_Node**)calloc((size_t)this->Num_Lines, 4);
    this->Line_Tail_Ptrs = (VSpan_Node**)calloc((size_t)this->Num_Lines, 4);
    this->LeftMostPx = (int*)calloc((size_t)this->Num_Lines, 4);
    this->RightMostPx = (int*)calloc((size_t)this->Num_Lines, 4);
    this->Span_Count = (int*)calloc((size_t)this->Num_Lines, 4);

    this->SetSpanRegions(0, 0, this->Num_Pixels - 1, this->Num_Lines - 1);
}

TSpan_List_Manager::~TSpan_List_Manager() {
    if (this->Line_Head_Ptrs) free(this->Line_Head_Ptrs);
    if (this->Line_Tail_Ptrs) free(this->Line_Tail_Ptrs);
    if (this->LeftMostPx) free(this->LeftMostPx);
    if (this->RightMostPx) free(this->RightMostPx);
    if (this->Span_Count) free(this->Span_Count);
}

void TSpan_List_Manager::SetSpanRegions(int left_px, int top_line, int right_px, int bottom_line) {
    int right = right_px;
    if (right_px < left_px) {
        right = left_px;
        left_px = right_px;
    }

    int top = top_line;
    if (bottom_line < top_line) {
        top = bottom_line;
        bottom_line = top_line;
    }

    if (top < 0) top = 0;
    if (-1 < bottom_line && top < this->Num_Lines) {
        if (this->Num_Lines <= bottom_line) bottom_line = this->Num_Lines - 1;

        if (left_px < 0) left_px = 0;
        if (-1 < right && left_px < this->Num_Pixels) {
            if (this->Num_Pixels <= right) right = this->Num_Pixels - 1;

            this->Min_Line = top;
            this->Max_Line = bottom_line;
            this->Min_Span_Px = left_px;
            this->Max_Span_Px = right;
        }
    }
}

void TSpan_List_Manager::ResetAll() {
    this->VSList.ReclaimAllNodes();
    if (this->Line_Head_Ptrs) memset(this->Line_Head_Ptrs, 0, (size_t)this->Num_Lines * 4);
    if (this->Line_Tail_Ptrs) memset(this->Line_Tail_Ptrs, 0, (size_t)this->Num_Lines * 4);
    if (this->LeftMostPx) memset(this->LeftMostPx, 0, (size_t)this->Num_Lines * 4);
    if (this->RightMostPx) memset(this->RightMostPx, 0, (size_t)this->Num_Lines * 4);
    if (this->Span_Count) memset(this->Span_Count, 0, (size_t)this->Num_Lines * 4);
}

void TSpan_List_Manager::AddSpan(int start_px, int end_px, int line) {
    if (line < this->Min_Line || line > this->Max_Line) return;

    if (end_px < start_px) {
        int t = start_px;
        start_px = end_px;
        end_px = t;
    }

    if (end_px < this->Min_Span_Px || start_px > this->Max_Span_Px) return;
    if (start_px < this->Min_Span_Px) start_px = this->Min_Span_Px;
    if (end_px > this->Max_Span_Px) end_px = this->Max_Span_Px;

    VSpan_Node* head = this->Line_Head_Ptrs[line];
    if (!head) {
        VSpan_Node* n = this->VSList.GetNode();
        n->Prev = (VSpan_Node*)0;
        n->Next = (VSpan_Node*)0;
        n->StartPx = start_px;
        n->EndPx = end_px;
        this->Line_Head_Ptrs[line] = n;
        this->Line_Tail_Ptrs[line] = n;
        this->LeftMostPx[line] = start_px;
        this->RightMostPx[line] = end_px;
        this->Span_Count[line] = this->Span_Count[line] + 1;
        return;
    }

    int left_most = this->LeftMostPx[line];
    int right_most = this->RightMostPx[line];

    // Fast-path append/prepend where no overlap is possible.
    if (end_px + 1 < left_most) {
        VSpan_Node* n = this->VSList.GetNode();
        n->Prev = (VSpan_Node*)0;
        n->Next = head;
        head->Prev = n;
        n->StartPx = start_px;
        n->EndPx = end_px;
        this->Line_Head_Ptrs[line] = n;
        this->LeftMostPx[line] = start_px;
        this->Span_Count[line] = this->Span_Count[line] + 1;
        return;
    }
    if (right_most + 1 < start_px) {
        VSpan_Node* tail = this->Line_Tail_Ptrs[line];
        VSpan_Node* n = this->VSList.GetNode();
        n->Prev = tail;
        n->Next = (VSpan_Node*)0;
        tail->Next = n;
        n->StartPx = start_px;
        n->EndPx = end_px;
        this->Line_Tail_Ptrs[line] = n;
        this->RightMostPx[line] = end_px;
        this->Span_Count[line] = this->Span_Count[line] + 1;
        return;
    }

    // General case: insert/merge into the sorted list.
    VSpan_Node* cur = head;
    while (cur && cur->EndPx < start_px - 1) {
        cur = cur->Next;
    }

    if (!cur) {
        // Should not happen given right_most checks, but keep safe.
        VSpan_Node* tail = this->Line_Tail_Ptrs[line];
        VSpan_Node* n = this->VSList.GetNode();
        n->Prev = tail;
        n->Next = (VSpan_Node*)0;
        tail->Next = n;
        n->StartPx = start_px;
        n->EndPx = end_px;
        this->Line_Tail_Ptrs[line] = n;
        if (start_px < this->LeftMostPx[line]) this->LeftMostPx[line] = start_px;
        if (end_px > this->RightMostPx[line]) this->RightMostPx[line] = end_px;
        this->Span_Count[line] = this->Span_Count[line] + 1;
        return;
    }

    if (end_px + 1 < cur->StartPx) {
        VSpan_Node* n = this->VSList.GetNode();
        VSpan_Node* prev = cur->Prev;
        n->Next = cur;
        n->Prev = prev;
        cur->Prev = n;
        if (prev) prev->Next = n;
        else this->Line_Head_Ptrs[line] = n;
        n->StartPx = start_px;
        n->EndPx = end_px;
        if (start_px < this->LeftMostPx[line]) this->LeftMostPx[line] = start_px;
        if (end_px > this->RightMostPx[line]) this->RightMostPx[line] = end_px;
        this->Span_Count[line] = this->Span_Count[line] + 1;
        return;
    }

    // Merge into cur.
    if (start_px < cur->StartPx) cur->StartPx = start_px;
    if (end_px > cur->EndPx) cur->EndPx = end_px;

    VSpan_Node* next = cur->Next;
    while (next && cur->EndPx + 1 >= next->StartPx) {
        if (next->EndPx > cur->EndPx) cur->EndPx = next->EndPx;
        VSpan_Node* to_free = next;
        next = next->Next;

        if (to_free->Prev) to_free->Prev->Next = to_free->Next;
        if (to_free->Next) to_free->Next->Prev = to_free->Prev;
        if (this->Line_Tail_Ptrs[line] == to_free) this->Line_Tail_Ptrs[line] = cur;

        this->VSList.FreeNode(to_free);
        this->Span_Count[line] = this->Span_Count[line] - 1;
    }

    cur->Next = next;
    if (next) next->Prev = cur;
    else this->Line_Tail_Ptrs[line] = cur;

    if (cur->StartPx < this->LeftMostPx[line]) this->LeftMostPx[line] = cur->StartPx;
    if (cur->EndPx > this->RightMostPx[line]) this->RightMostPx[line] = cur->EndPx;
}

void TSpan_List_Manager::AddShape(TShape* param_1, int param_2, int param_3, int param_4, int param_5) {
    // Fully verified. Source of truth: spanlist.cpp.decomp @ 0x004BDEA0
    if (param_1 == nullptr || param_1->FShape == nullptr || param_1->shape_info == nullptr) {
        return;
    }

    Shape_Info* shape_info = param_1->shape_info;
    long* outline = (long*)(param_1->FShape->Version + shape_info[param_2].Shape_Outline_Offset);
    int right = (int)shape_info[param_2].Width - 1 + param_3;
    int y = param_4;
    int end_y = param_4 + (int)shape_info[param_2].Height;

    if (param_5 == 0) {
        while (y < end_y) {
            long lVar = *outline++;
            ushort* puVar = (ushort*)((char*)outline - 2);
            if (this->Min_Line <= y && y <= this->Max_Line && (((ushort)lVar & 0x8000) == 0)) {
                this->AddSpan((short)(ushort)lVar + param_3, right - (short)(*puVar), y);
            }
            y++;
        }
        return;
    }

    while (y < end_y) {
        long lVar = *outline++;
        ushort* puVar = (ushort*)((char*)outline - 2);
        if (this->Min_Line <= y && y <= this->Max_Line && (((*puVar) & 0x8000) == 0)) {
            this->AddSpan((short)(*puVar) + param_3, right - (short)(ushort)lVar, y);
        }
        y++;
    }
}

void TSpan_List_Manager::AddShape_Align(uchar* param_1, Shape_Info* param_2, int param_3, int param_4, int param_5) {
    // Fully verified. Source of truth: spanlist.cpp.decomp @ 0x004BDFA0
    if (param_2 == nullptr) {
        return;
    }

    ushort* outline = (ushort*)(param_1 + param_2->Shape_Outline_Offset);
    int right = (int)param_2->Width - 1 + param_3;
    int y = param_4;
    int end_y = param_4 + (int)param_2->Height;

    if (param_5 == 0) {
        while (y < end_y) {
            ushort start = outline[0];
            ushort end = outline[1];
            outline += 2;
            if (this->Min_Line <= y && y <= this->Max_Line && ((start & 0x8000) == 0)) {
                this->AddSpan(((short)start + param_3) & 0xFFFFFFFC, (right - (short)end) | 3, y);
            }
            y++;
        }
        return;
    }

    while (y < end_y) {
        ushort start = outline[0];
        ushort end = outline[1];
        outline += 2;
        if (this->Min_Line <= y && y <= this->Max_Line && ((end & 0x8000) == 0)) {
            this->AddSpan(((short)end + param_3) & 0xFFFFFFFC, (right - (short)start) | 3, y);
        }
        y++;
    }
}

void TSpan_List_Manager::SubtractMiniList(VSpanMiniList* mini_list, int x_off, int y_off) {
    // Fully verified. Source of truth: spanlist.cpp.decomp @ 0x004BE240
    if (mini_list != (VSpanMiniList*)0) {
        do {
            if (mini_list->Y_delta == 0xff) {
                return;
            }
            this->DeleteSpan((int)mini_list->X_start + x_off, (int)mini_list->X_end + x_off, (int)mini_list->Y_delta + y_off);
            mini_list = mini_list + 1;
        } while (mini_list != (VSpanMiniList*)0);
    }
}

void TSpan_List_Manager::AddLine_Align(int x1, int y1, int x2, int y2) {
    // Fully verified. Source of truth: spanlist.cpp.decomp @ 0x004BE090
    int end_x = x2;
    if (x1 == x2) {
        int end_y = y2;
        if (y2 < y1) {
            end_y = y1;
            y1 = y2;
        }
        for (; y1 <= end_y; ++y1) {
            this->AddSpan(x1 & 0xFFFFFFFC, x1 | 3, y1);
        }
        return;
    }

    if (y1 == y2) {
        this->AddSpan(x1 & 0xFFFFFFFC, x2 | 3, y1);
        return;
    }

    int cur_y = y1;
    int target_y = y2;
    if (x2 < x1) {
        x2 = x1;
        x1 = end_x;
        cur_y = y2;
        target_y = y1;
    }

    const int width = (x2 - x1) + 1;
    int y_step = 1;
    int height = (target_y - cur_y);
    if (target_y < cur_y) {
        height = cur_y - target_y;
        y_step = -1;
    }
    height += 1;

    if (height <= width) {
        int err = 0;
        uint span_start = (uint)x1;
        for (; x1 < x2; ++x1) {
            err += height;
            if (width <= err) {
                this->AddSpan(span_start & 0xFFFFFFFCu, x1 | 3, cur_y);
                cur_y += y_step;
                err -= width;
                span_start = (uint)(x1 + 1);
            }
        }
        this->AddSpan(span_start & 0xFFFFFFFCu, x1 | 3, cur_y);
        return;
    }

    int err = 0;
    for (;;) {
        this->AddSpan(x1 & 0xFFFFFFFC, x1 | 3, cur_y);
        if (cur_y == target_y) {
            break;
        }
        cur_y += y_step;
        err += width;
        if (height <= err) {
            ++x1;
            err -= height;
        }
    }
}

void TSpan_List_Manager::AddMiniList(VSpanMiniList* mini_list, int x_off, int y_off) {
    if (mini_list == nullptr) {
        return;
    }

    for (VSpanMiniList* it = mini_list; it != nullptr; ++it) {
        if (it->Y_delta == 0xFF) {
            return;
        }

        this->AddSpan(
            (int)it->X_start + x_off,
            (int)it->X_end + x_off,
            (int)it->Y_delta + y_off);
    }
}

void TSpan_List_Manager::DeleteSpan(int start_px, int end_px, int line) {
    // Fully verified. Source of truth: spanlist.cpp.decomp @ 0x004BE290
    int orig_line = line;
    int end_in = end_px;

    if (line < this->Min_Line || this->Max_Line < line) return;

    if (end_px < start_px) {
        end_px = start_px;
        start_px = end_in;
    }

    int min_span = this->Min_Span_Px;
    int max_span = this->Max_Span_Px;
    if (end_px < min_span) return;
    if (max_span < start_px) return;

    if (start_px < min_span) start_px = min_span;
    if (max_span < end_px) end_px = max_span;

    VSpan_Node* head = this->Line_Head_Ptrs[line];
    if (!head) return;

    if (end_px < this->LeftMostPx[line]) return;
    if (this->RightMostPx[line] < start_px) return;

    if ((start_px <= this->LeftMostPx[line]) && (this->RightMostPx[line] <= end_px)) {
        this->VSList.FreeThread(head, this->Line_Tail_Ptrs[line]);
        this->Line_Head_Ptrs[line] = (VSpan_Node*)0;
        this->Line_Tail_Ptrs[line] = (VSpan_Node*)0;
        this->Span_Count[line] = 0;
        this->LeftMostPx[line] = 0;
        this->RightMostPx[line] = 0;
        return;
    }

    VSpan_Node* tail = this->Line_Tail_Ptrs[line];

    VSpan_Node* cur = head;
    while (cur->EndPx < start_px) {
        cur = cur->Next;
    }

    if (cur->StartPx < start_px) {
        if (end_px < cur->EndPx) {
            // Split a span in two.
            VSpan_Node* n = this->VSList.GetNode();
            n->Prev = cur;
            n->Next = cur->Next;
            cur->Next = n;
            if (n->Next != (VSpan_Node*)0) {
                n->Next->Prev = n;
            }
            if (cur == tail) {
                this->Line_Tail_Ptrs[line] = n;
            }
            n->StartPx = end_px + 1;
            n->EndPx = cur->EndPx;
            cur->EndPx = start_px - 1;
            this->Span_Count[line] = this->Span_Count[line] + 1;
            return;
        }

        if (cur->StartPx < start_px) {
            cur->EndPx = start_px - 1;
            cur = cur->Next;
        }
    }

    VSpan_Node* new_tail = tail;
    VSpan_Node* new_head = head;

    if (cur != (VSpan_Node*)0) {
        VSpan_Node* next = (VSpan_Node*)0;
        do {
            if ((cur->StartPx < start_px) || (end_px < cur->EndPx)) {
                next = (VSpan_Node*)0;
            } else {
                if (cur == new_head) {
                    new_head = cur->Next;
                }
                if (cur == new_tail) {
                    new_tail = cur->Prev;
                }
                if (cur->Prev != (VSpan_Node*)0) {
                    cur->Prev->Next = cur->Next;
                }
                if (cur->Next != (VSpan_Node*)0) {
                    cur->Next->Prev = cur->Prev;
                }
                next = cur->Next;
                this->VSList.FreeNode(cur);
                this->Span_Count[orig_line] = this->Span_Count[orig_line] - 1;
                cur = next;
            }
        } while (next != (VSpan_Node*)0);

        if ((cur != (VSpan_Node*)0) && (cur->StartPx <= end_px)) {
            cur->StartPx = end_px + 1;
        }
    }

    this->Line_Head_Ptrs[orig_line] = new_head;
    this->Line_Tail_Ptrs[orig_line] = new_tail;
    this->LeftMostPx[orig_line] = new_head->StartPx;
    this->RightMostPx[orig_line] = new_tail->EndPx;
}

int TSpan_List_Manager::PointVisible(int x_px, int y_line) {
    // Fully verified. Source of truth: spanlist.cpp.decomp @ 0x004BE5B0
    if ((-1 < y_line) && (y_line < this->Num_Lines)) {
        VSpan_Node* node = this->Line_Head_Ptrs[y_line];
        if (node != (VSpan_Node*)0) {
            while ((x_px < node->StartPx) || (node->EndPx < x_px)) {
                node = node->Next;
                if (node == (VSpan_Node*)0) {
                    return 0;
                }
            }
            return 1;
        }
    }
    return 0;
}

void TSpan_List_Manager::Merge_n_Align(TSpan_List_Manager* list_a, TSpan_List_Manager* list_b) {
    // Fully verified. Source of truth: spanlist.cpp.decomp @ 0x004BE5F0
    this->ResetAll();

    int num_lines = this->Num_Lines;
    if ((num_lines != list_a->Num_Lines) || (num_lines != list_b->Num_Lines) || (this->Num_Pixels != list_a->Num_Pixels) ||
        (this->Num_Pixels != list_b->Num_Pixels) || (num_lines < 1)) {
        return;
    }

    int i = 0;
    while (true) {
        VSpan_Node* a = list_a->Line_Head_Ptrs[i];
        VSpan_Node* b = list_b->Line_Head_Ptrs[i];

        while (true) {
            if (a == (VSpan_Node*)0) {
                if (b == (VSpan_Node*)0) break;
            } else {
                this->AddSpan(a->StartPx & 0xfffffffc, a->EndPx | 3, i);
                a = a->Next;
            }
            if (b != (VSpan_Node*)0) {
                this->AddSpan(b->StartPx & 0xfffffffc, b->EndPx | 3, i);
                b = b->Next;
            }
        }

        i = i + 1;
        if (num_lines <= i) return;
    }
}

void TSpan_List_Manager::DeleteShape(TShape* param_1, int param_2, int param_3, int param_4, int param_5) {
    // Fully verified. Source of truth: spanlist.cpp.decomp @ 0x004BE4B0
    if (param_1 == nullptr || param_1->FShape == nullptr || param_1->shape_info == nullptr) {
        return;
    }

    Shape_Info* shape_info = param_1->shape_info;
    long* outline = (long*)(param_1->FShape->Version + shape_info[param_2].Shape_Outline_Offset);
    int right = (int)shape_info[param_2].Width - 1 + param_3;
    int y = param_4;
    int end_y = param_4 + (int)shape_info[param_2].Height;

    if (param_5 == 0) {
        while (y < end_y) {
            long lVar = *outline++;
            ushort* puVar = (ushort*)((char*)outline - 2);
            if (((ushort)lVar & 0x8000) == 0) {
                this->DeleteSpan(param_3 + (short)(ushort)lVar, right - (short)*puVar, y);
            }
            y++;
        }
        return;
    }

    while (y < end_y) {
        long lVar = *outline++;
        ushort* puVar = (ushort*)((char*)outline - 2);
        if (((*puVar) & 0x8000) == 0) {
            this->DeleteSpan(param_3 + (short)*puVar, right - (short)(ushort)lVar, y);
        }
        y++;
    }
}

void TSpan_List_Manager::AlignamizeSpans() {
    // Fully verified. Source of truth: spanlist.cpp.decomp @ 0x004BE690
    for (int y = 0; y < this->Num_Lines; ++y) {
        VSpan_Node* node = this->Line_Head_Ptrs[y];
        if (node == nullptr) {
            continue;
        }

        while (node != nullptr) {
            VSpan_Node* next = node->Next;
            node->StartPx &= 0xFFFFFFFC;
            node->EndPx |= 3;
            if (next != nullptr && node->EndPx >= ((next->StartPx & 0x7FFFFFFC) - 1)) {
                node->EndPx = next->EndPx | 3;
                node->Next = next->Next;
                if (next == this->Line_Tail_Ptrs[y]) {
                    this->Line_Tail_Ptrs[y] = node;
                }
                if (next->Next != nullptr) {
                    next->Next->Prev = node;
                }
                this->VSList.FreeNode(next);
                this->Span_Count[y] = this->Span_Count[y] - 1;
            } else {
                node = node->Next;
            }
        }

        this->LeftMostPx[y] = this->Line_Head_Ptrs[y]->StartPx;
        this->RightMostPx[y] = this->Line_Tail_Ptrs[y]->EndPx;
    }
}

void TSpan_List_Manager::ScrollSpansHorizontally(int param_1, int param_2) {
    // Source of truth: spanlist.cpp.decomp @ 0x004BE750
    if (param_1 == 0) {
        return;
    }
    if (param_2 != 0) {
        int abs_dx = (param_1 < 0) ? -param_1 : param_1;
        if ((this->Max_Span_Px - this->Min_Span_Px) < abs_dx) {
            this->ResetAll();
            return;
        }
    }

    for (int y = 0; y < this->Num_Lines; ++y) {
        VSpan_Node* node = this->Line_Head_Ptrs[y];
        while (node != nullptr) {
            VSpan_Node* next = node->Next;
            int start = node->StartPx + param_1;
            int end = node->EndPx + param_1;
            if (param_2 != 0) {
                if (end < this->Min_Span_Px || this->Max_Span_Px < start) {
                    if (node->Prev != nullptr) {
                        node->Prev->Next = next;
                    } else {
                        this->Line_Head_Ptrs[y] = next;
                    }
                    if (next != nullptr) {
                        next->Prev = node->Prev;
                    } else {
                        this->Line_Tail_Ptrs[y] = node->Prev;
                    }
                    this->VSList.FreeNode(node);
                    this->Span_Count[y] = this->Span_Count[y] - 1;
                    node = next;
                    continue;
                }
                if (start < this->Min_Span_Px) start = this->Min_Span_Px;
                if (this->Max_Span_Px < end) end = this->Max_Span_Px;
            }
            node->StartPx = start;
            node->EndPx = end;
            node = next;
        }
    }
}

void TSpan_List_Manager::ScrollSpansVertically(int param_1, int param_2) {
    // Source of truth: spanlist.cpp.decomp @ 0x004BE850
    if (param_1 == 0) {
        return;
    }

    int min_line = (param_2 == 0) ? 0 : this->Min_Line;
    int max_line = (param_2 == 0) ? (this->Num_Lines - 1) : this->Max_Line;
    int abs_dy = (param_1 < 0) ? -param_1 : param_1;
    if ((max_line - min_line) < abs_dy) {
        this->ResetAll();
        return;
    }

    for (int y = 0; y < this->Num_Lines; ++y) {
        int dst = y + param_1;
        if (this->Line_Head_Ptrs[y] != nullptr && (dst < min_line || max_line < dst)) {
            this->VSList.FreeThread(this->Line_Head_Ptrs[y], this->Line_Tail_Ptrs[y]);
            this->Line_Head_Ptrs[y] = nullptr;
            this->Line_Tail_Ptrs[y] = nullptr;
            this->Span_Count[y] = 0;
            this->LeftMostPx[y] = 0;
            this->RightMostPx[y] = 0;
        }
    }

    if (param_1 < 0) {
        for (int y = this->Num_Lines - 1; y + param_1 >= 0; --y) {
            this->Line_Head_Ptrs[y + param_1] = this->Line_Head_Ptrs[y];
            this->Line_Tail_Ptrs[y + param_1] = this->Line_Tail_Ptrs[y];
            this->Span_Count[y + param_1] = this->Span_Count[y];
            this->LeftMostPx[y + param_1] = this->LeftMostPx[y];
            this->RightMostPx[y + param_1] = this->RightMostPx[y];
        }
        for (int y = this->Num_Lines + param_1; y < this->Num_Lines; ++y) {
            if (y >= 0) {
                this->Line_Head_Ptrs[y] = nullptr;
                this->Line_Tail_Ptrs[y] = nullptr;
                this->Span_Count[y] = 0;
                this->LeftMostPx[y] = 0;
                this->RightMostPx[y] = 0;
            }
        }
    } else {
        for (int y = 0; y + param_1 < this->Num_Lines; ++y) {
            this->Line_Head_Ptrs[y + param_1] = this->Line_Head_Ptrs[y];
            this->Line_Tail_Ptrs[y + param_1] = this->Line_Tail_Ptrs[y];
            this->Span_Count[y + param_1] = this->Span_Count[y];
            this->LeftMostPx[y + param_1] = this->LeftMostPx[y];
            this->RightMostPx[y + param_1] = this->RightMostPx[y];
        }
        for (int y = 0; y < param_1; ++y) {
            this->Line_Head_Ptrs[y] = nullptr;
            this->Line_Tail_Ptrs[y] = nullptr;
            this->Span_Count[y] = 0;
            this->LeftMostPx[y] = 0;
            this->RightMostPx[y] = 0;
        }
    }
}

int TSpan_List_Manager::ValidateSpan(int param_1) {
    // Fully verified. Source of truth: spanlist.cpp.decomp @ 0x004BE9E0
    int span_num = 0;
    if (param_1 < 0 || param_1 >= this->Num_Lines) {
        return 0;
    }

    if (this->Line_Head_Ptrs[param_1] == nullptr) {
        return (this->Line_Tail_Ptrs[param_1] == nullptr && this->Span_Count[param_1] == 0 && this->LeftMostPx[param_1] == 0 &&
                this->RightMostPx[param_1] == 0)
                   ? 1
                   : 0;
    }

    VSpan_Node* node = this->Line_Head_Ptrs[param_1];
    VSpan_Node* prev = nullptr;
    int prev_end = 0;
    while (node != nullptr) {
        span_num++;
        if (span_num == 1 && node->StartPx != this->LeftMostPx[param_1]) {
            return 0;
        }
        if (node->Prev != prev) {
            return 0;
        }
        if (node->EndPx < node->StartPx) {
            return 0;
        }
        if (span_num > 1 && node->StartPx <= prev_end) {
            return 0;
        }
        prev_end = node->EndPx;
        prev = node;
        node = node->Next;
    }

    if (this->Span_Count[param_1] != span_num || this->Line_Tail_Ptrs[param_1] != prev || prev->EndPx != this->RightMostPx[param_1]) {
        return 0;
    }
    return (this->LeftMostPx[param_1] <= this->RightMostPx[param_1]) ? 1 : 0;
}

int TSpan_List_Manager::DecodeLine(uchar* param_1, int param_2, uchar param_3, int /*param_4*/) {
    // Fully verified. Source of truth: spanlist.cpp.decomp @ 0x004BEAD0
    int num = 0;
    if (param_1 == nullptr || param_2 < 0 || param_2 >= this->Num_Lines) {
        return 0;
    }
    for (VSpan_Node* n = this->Line_Head_Ptrs[param_2]; n != nullptr; n = n->Next) {
        for (int x = n->StartPx; x <= n->EndPx; ++x) {
            param_1[x] = param_1[x] + param_3;
        }
        num++;
    }
    return num;
}

void TSpan_List_Manager::take_snapshot(char* param_1, int* param_2, TDrawArea* param_3, int param_4, TSpan_List_Manager** param_5,
                                       int* param_6, int param_7) {
    // TODO: Source of truth: spanlist.cpp.decomp @ 0x004BEB10 (I/O/error path parity still incomplete)
    if (param_2 == nullptr || param_3 == nullptr) {
        return;
    }
    for (int i = 0; i < param_7; ++i) {
        if (param_5 == nullptr || param_5[i] == nullptr) {
            return;
        }
    }

    int width = this->Num_Pixels;
    int height = this->Num_Lines;
    int stride = (width + 3) & 0xFFFC;
    uchar* line = (uchar*)malloc((size_t)stride);
    if (line == nullptr) {
        return;
    }

    char bmp_name[64] = {0};
    if (*param_2 < 0) {
        *param_2 = 0;
    }
    const char* fmt = (param_1 != nullptr) ? param_1 : "snapshot_%03d.bmp";
    sprintf(bmp_name, fmt, *param_2);
    *param_2 = *param_2 + 1;

    int fd = _open(bmp_name, _O_CREAT | _O_TRUNC | _O_BINARY | _O_WRONLY, _S_IREAD | _S_IWRITE);
    if (fd != -1) {
        tagBITMAPFILEHEADER fh = {};
        tagBITMAPINFOHEADER ih = {};
        tagRGBQUAD pal[256] = {};
        tagPALETTEENTRY draw_pal[256] = {};

        fh.bfType = 0x4D42;
        fh.bfOffBits = sizeof(tagBITMAPFILEHEADER) + sizeof(tagBITMAPINFOHEADER) + sizeof(pal);
        fh.bfSize = fh.bfOffBits + (DWORD)(height * stride);
        ih.biSize = sizeof(tagBITMAPINFOHEADER);
        ih.biWidth = width;
        ih.biHeight = height;
        ih.biPlanes = 1;
        ih.biBitCount = 8;
        ih.biCompression = BI_RGB;
        ih.biSizeImage = (DWORD)(height * stride);
        param_3->GetPalette(draw_pal);
        for (int i = 0; i < 256; ++i) {
            pal[i].rgbBlue = draw_pal[i].peBlue;
            pal[i].rgbGreen = draw_pal[i].peGreen;
            pal[i].rgbRed = draw_pal[i].peRed;
            pal[i].rgbReserved = 0;
        }

        _write(fd, &fh, sizeof(fh));
        _write(fd, &ih, sizeof(ih));
        _write(fd, pal, sizeof(pal));

        for (int y = height - 1; y >= 0; --y) {
            memset(line, 0, (size_t)stride);
            this->DecodeLine(line, y, (uchar)param_4, width);
            for (int i = 0; i < param_7; ++i) {
                int overlay_value = (param_6 != nullptr) ? param_6[i] : 0;
                param_5[i]->DecodeLine(line, y, (uchar)overlay_value, width);
            }
            _write(fd, line, stride);
        }
        _close(fd);
    }

    free(line);
}


#if 0
// TODO: Parity reference block from spanlist.cpp.decomp for take_snapshot exact behavior.

// Offset: 0x004BEB10
void take_snapshot(TSpan_List_Manager* this_, char* param_2, int* param_3, TDrawArea* param_4, int param_5, TSpan_List_Manager** param_6, int* param_7, int param_8) {
    // --- Ghidra decompiler output ---
    // 
    // /* WARNING: Variable defined which should be unmapped: Height */
    // /* public: void __thiscall TSpan_List_Manager::take_snapshot(char *,int &,class TDrawArea
    //    *,int,class TSpan_List_Manager * *,int *,int) */
    // 
    // void __thiscall
    // TSpan_List_Manager::take_snapshot
    //           (TSpan_List_Manager *this,char *param_1,int *param_2,TDrawArea *param_3,int param_4,
    //           TSpan_List_Manager **param_5,int *param_6,int param_7)
    // 
    // {
    //   uchar uVar1;
    //   uchar uVar2;
    //   int iVar3;
    //   int iVar4;
    //   int iVar5;
    //   int iVar6;
    //   uchar *puVar7;
    //   uint uVar8;
    //   TSpan_List_Manager **ppTVar9;
    //   uint uVar10;
    //   uchar *puVar11;
    //   char *pcVar12;
    //   int Height;
    //   int Width;
    //   int infile;
    //   int bmWide;
    //   tagBITMAPFILEHEADER bmFH;
    //   tagBITMAPINFOHEADER bmIH;
    //   char BMPFile [60];
    //   tagRGBQUAD bmPAL [256];
    //   tagPALETTEENTRY thePal [256];
    //   
    //   if ((0 < param_7) && (iVar4 = 0, ppTVar9 = param_5, 0 < param_7)) {
    //     do {
    //       if (*ppTVar9 == (TSpan_List_Manager *)0x0) {
    //         return;
    //       }
    //       iVar4 = iVar4 + 1;
    //       ppTVar9 = ppTVar9 + 1;
    //     } while (iVar4 < param_7);
    //   }
    //   iVar4 = this->Num_Pixels;
    //   iVar3 = this->Num_Lines;
    //   uVar10 = iVar4 + 3U & 0xfffc;
    //   bmFH._6_4_ = iVar3 * uVar10 + 0x436;
    //   bmFH.bfSize._2_2_ = 0x4d42;
    //   bmFH.bfOffBits._0_2_ = 0;
    //   bmFH.bfOffBits._2_2_ = 0;
    //   bmIH.biWidth = 0x28;
    //   bmIH.biCompression._0_2_ = 1;
    //   bmIH.biCompression._2_2_ = 8;
    //   bmIH.biSizeImage = 0;
    //   bmIH.biXPelsPerMeter = 0;
    //   bmIH.biYPelsPerMeter = 0;
    //   bmIH.biClrUsed = 0;
    //   bmIH.biClrImportant = 0;
    //   BMPFile[0] = '\0';
    //   BMPFile[1] = '\0';
    //   BMPFile[2] = '\0';
    //   BMPFile[3] = '\0';
    //   bmFH._0_4_ = this;
    //   bmIH.biHeight = iVar4;
    //   bmIH._12_4_ = iVar3;
    //   TDrawArea::GetPalette(param_3,thePal + 1);
    //   iVar5 = 0;
    //   do {
    //     uVar1 = (&thePal[1].peGreen)[iVar5];
    //     (&bmPAL[1].rgbBlue)[iVar5] = (&thePal[1].peBlue)[iVar5];
    //     uVar2 = (&thePal[1].peRed)[iVar5];
    //     (&bmPAL[1].rgbGreen)[iVar5] = uVar1;
    //     (&bmPAL[1].rgbRed)[iVar5] = uVar2;
    //     (&bmPAL[1].rgbReserved)[iVar5] = '\0';
    //     iVar5 = iVar5 + 4;
    //   } while (iVar5 < 0x400);
    //   iVar5 = 0;
    //   if (*param_2 < 0) {
    //     *param_2 = 0;
    //   }
    //   while( true ) {
    //     if (param_1 == (char *)0x0) {
    //       iVar6 = *param_2;
    //       pcVar12 = s_C__AOE__03d_BMP;
    //     }
    //     else {
    //       iVar6 = *param_2;
    //       pcVar12 = param_1;
    //     }
    //     sprintf(BMPFile + 4,pcVar12,iVar6);
    //     iVar5 = iVar5 + 1;
    //     iVar6 = __open(BMPFile + 4,0);
    //     if (iVar6 == -1) break;
    //     *param_2 = *param_2 + 1;
    //     close(iVar6);
    //     if (1000 < iVar5) {
    //       return;
    //     }
    //   }
    //   puVar7 = (uchar *)malloc(uVar10);
    //   iVar5 = __open(BMPFile + 4,0x8301,0x180);
    //   if (iVar5 != -1) {
    //     write(iVar5,(undefined1 *)((int)&bmFH.bfSize + 2),0xe);
    //     write(iVar5,&bmIH.biWidth,0x28);
    //     write(iVar5,bmPAL + 1,0x400);
    //     while (iVar3 = iVar3 + -1, -1 < iVar3) {
    //       puVar11 = puVar7;
    //       for (uVar8 = uVar10 >> 2; uVar8 != 0; uVar8 = uVar8 - 1) {
    //         puVar11[0] = '\0';
    //         puVar11[1] = '\0';
    //         puVar11[2] = '\0';
    //         puVar11[3] = '\0';
    //         puVar11 = puVar11 + 4;
    //       }
    //       for (iVar6 = 0; iVar6 != 0; iVar6 = iVar6 + -1) {
    //         *puVar11 = '\0';
    //         puVar11 = puVar11 + 1;
    //       }
    //       DecodeLine((TSpan_List_Manager *)bmFH._0_4_,puVar7,iVar3,(uchar)param_4,iVar4);
    //       if (0 < param_7) {
    //         Width = param_7;
    //         ppTVar9 = param_5;
    //         do {
    //           DecodeLine(*ppTVar9,puVar7,iVar3,*(uchar *)(((int)param_6 - (int)param_5) + (int)ppTVar9),
    //                      iVar4);
    //           ppTVar9 = ppTVar9 + 1;
    //           Width = Width + -1;
    //         } while (Width != 0);
    //       }
    //       write(iVar5,puVar7,uVar10);
    //     }
    //     close(iVar5);
    //   }
    //   free(puVar7);
    //   return;
    // }
    // 
    // 
}


#endif

