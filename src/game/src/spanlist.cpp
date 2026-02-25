#include <stdlib.h>
#include <string.h>
#include "../include/TSpan_List_Manager.h"
#include "../include/VSpanMiniList.h"
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

