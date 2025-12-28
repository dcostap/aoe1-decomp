#include "TSpan_List_Manager.h"
#include "TDrawArea.h"
#include "TShape.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include <sys/stat.h>
#include <stdint.h> 

// Platform compatibility macros for file I/O if not defined
#ifndef O_BINARY
#define O_BINARY 0x8000
#endif

// Static string for snapshot filename
static char s_C__AOE__03d_BMP[] = "C:\\AOE_%03d.BMP";

// Address: 0x004bd8b0
TSpan_List_Manager::TSpan_List_Manager(int width, int height) 
    : VSList(((width + 31 + ((width + 31) >> 31 & 31)) >> 5) * height, height << 4, 16)
{
    // VSList initialization is handled in the initializer list above roughly matching:
    // TSpan_Node_List::TSpan_Node_List(&this->VSList, count_calc, height * 16, 16);
    
    this->Num_Lines = (height < 16) ? 16 : height;
    this->Num_Pixels = (width < 16) ? 16 : width;

    this->SetSpanRegions(0, 0, this->Num_Pixels - 1, this->Num_Lines - 1);

    this->Line_Head_Ptrs = (VSpan_Node **)calloc(this->Num_Lines, sizeof(VSpan_Node*));
    this->Line_Tail_Ptrs = (VSpan_Node **)calloc(this->Num_Lines, sizeof(VSpan_Node*));
    this->LeftMostPx     = (int *)calloc(this->Num_Lines, sizeof(int));
    this->RightMostPx    = (int *)calloc(this->Num_Lines, sizeof(int));
    this->Span_Count     = (int *)calloc(this->Num_Lines, sizeof(int));
}

// Address: 0x004bd9a0
TSpan_List_Manager::~TSpan_List_Manager() {
    if (this->Line_Head_Ptrs) free(this->Line_Head_Ptrs);
    if (this->Line_Tail_Ptrs) free(this->Line_Tail_Ptrs);
    if (this->LeftMostPx)     free(this->LeftMostPx);
    if (this->RightMostPx)    free(this->RightMostPx);
    if (this->Span_Count)     free(this->Span_Count);
    
    // this->VSList destructor called automatically
}

// Address: 0x004bda00
void TSpan_List_Manager::SetSpanRegions(int x1, int y1, int x2, int y2) {
    int left = (x2 < x1) ? x2 : x1;
    int right = (x2 < x1) ? x1 : x2;
    int top = (y2 < y1) ? y2 : y1;
    int bottom = (y2 < y1) ? y1 : y2;

    if (top < 0) top = 0;
    
    if (bottom >= 0 && top < this->Num_Lines) {
        if (bottom >= this->Num_Lines) bottom = this->Num_Lines - 1;
        
        if (left < 0) left = 0;
        
        if (right >= 0 && left < this->Num_Pixels) {
            if (right >= this->Num_Pixels) right = this->Num_Pixels - 1;
            
            this->Min_Line = top;
            this->Max_Line = bottom;
            this->Min_Span_Px = left;
            this->Max_Span_Px = right;
        }
    }
}

// Address: 0x004bda70
void TSpan_List_Manager::ResetAll() {
    this->VSList.ReclaimAllNodes();

    // Clear arrays
    memset(this->Line_Head_Ptrs, 0, this->Num_Lines * sizeof(VSpan_Node*));
    memset(this->Line_Tail_Ptrs, 0, this->Num_Lines * sizeof(VSpan_Node*));
    memset(this->LeftMostPx, 0, this->Num_Lines * sizeof(int));
    memset(this->RightMostPx, 0, this->Num_Lines * sizeof(int));
    memset(this->Span_Count, 0, this->Num_Lines * sizeof(int));
}

// Address: 0x004bdb00
void TSpan_List_Manager::AddSpan(int x1, int x2, int y) {
    if (y < this->Min_Line || y > this->Max_Line) return;

    if (x2 < x1) {
        int temp = x1; x1 = x2; x2 = temp;
    }

    // Clip against Min/Max Span Px
    if (x1 < this->Min_Span_Px) x1 = this->Min_Span_Px;
    if (x2 > this->Max_Span_Px) x2 = this->Max_Span_Px;
    
    if (x1 > x2) return; // Clipped out

    VSpan_Node *curr = this->Line_Head_Ptrs[y];

    // Case 1: Empty line
    if (!curr) {
        curr = this->VSList.GetNode();
        curr->Prev = nullptr;
        curr->Next = nullptr;
        curr->StartPx = x1;
        curr->EndPx = x2;
        
        this->Line_Head_Ptrs[y] = curr;
        this->Line_Tail_Ptrs[y] = curr;
        this->LeftMostPx[y] = x1;
        this->RightMostPx[y] = x2;
        this->Span_Count[y]++;
        return;
    }

    VSpan_Node *tail = this->Line_Tail_Ptrs[y];
    int left_most = this->LeftMostPx[y];

    // Case 2: New span is to the left of existing spans
    if (x1 <= left_most) {
        // Optimization: check against left most cache
        // However, the logic below handles insertion
    }

    // Determine search direction based on Left/Right most cache
    if (left_most < x1) {
        int right_most = this->RightMostPx[y];
        if (x2 < right_most) {
            // Middle insertion/merge required
            // Find insertion point traversing from head
            int end_chk = curr->EndPx;
            while (end_chk < x1 - 1) {
                curr = curr->Next;
                end_chk = curr->EndPx;
            }

            // curr is now the first node that interacts with [x1, x2] or is strictly after it

            // Subcase: Insert strictly before curr
            if (x2 + 1 < curr->StartPx) {
                VSpan_Node *node = this->VSList.GetNode();
                VSpan_Node *prev = curr->Prev;
                
                node->Next = curr;
                node->Prev = prev;
                curr->Prev = node;
                // prev->Next handled implicitly? No, need to set it.
                // The decomp says: pVVar6->Prev->Next = pVVar6;
                if (node->Prev) node->Prev->Next = node;
                // If head?
                // The logic seems to rely on curr not being head if we skipped nodes, 
                // OR if it is head, prev is null.
                // Decomp: pVVar6->Prev->Next = pVVar6. If Prev is null crash? 
                // But we are in `left_most < x1`, so we must have skipped at least one or x1 is > start of head?
                // Actually if x1 > LeftMostPx, and LeftMostPx == Head->StartPx.
                
                node->StartPx = x1;
                node->EndPx = x2;
                this->Span_Count[y]++;
                return;
            }
            
            // Subcase: Merge with curr
            if (x1 < curr->StartPx) curr->StartPx = x1;
            
            // Resolve overlap with subsequent nodes
            if (curr->EndPx < x2) {
                VSpan_Node *next_node = curr->Next;
                if (next_node) {
                    while (true) {
                        if (x2 + 1 < next_node->StartPx) {
                            curr->EndPx = x2;
                            return;
                        }
                        // Eat next_node
                        if (x2 <= next_node->EndPx) break; // Merged into next_node, done after adjustment

                        // Unlink next_node
                        if (next_node->Prev) next_node->Prev->Next = next_node->Next;
                        if (next_node->Next) next_node->Next->Prev = next_node->Prev;
                        
                        VSpan_Node *to_free = next_node;
                        next_node = next_node->Next;
                        this->VSList.FreeNode(to_free);
                        this->Span_Count[y]--;
                        
                        if (!next_node) return; // End of list
                    }
                    
                    // Merge ends
                    curr->EndPx = next_node->EndPx;
                    curr->Next = next_node->Next; // Skip the partially eaten node
                    
                    this->VSList.FreeNode(next_node);
                    this->Span_Count[y]--;
                    
                    if (curr->Next) curr->Next->Prev = curr;
                    else this->Line_Tail_Ptrs[y] = curr; // Tail update
                    return;
                }
            }
            return; // Merged into single node, no next node overlaps
        } 
        else {
            // New span extends beyond or touches the rightmost extent
            // Check tail
            if (tail->EndPx < x1 - 1) {
                // Append new node at end
                VSpan_Node *node = this->VSList.GetNode();
                node->Prev = tail;
                node->Next = nullptr;
                tail->Next = node;
                node->StartPx = x1;
                node->EndPx = x2;
                
                this->RightMostPx[y] = x2;
                this->Line_Tail_Ptrs[y] = node;
                this->Span_Count[y]++;
                return;
            }
            
            // Merge with tail (and potentially nodes before it? No, traverse backwards)
            this->RightMostPx[y] = x2;
            int threshold = x1 - 1;
            
            if (threshold <= tail->EndPx) {
                while (true) {
                    if (tail->StartPx <= x1) {
                        tail->EndPx = x2;
                        return;
                    }
                    // Tail is completely covered by new span, move back
                    VSpan_Node *prev = tail->Prev;
                    if (prev->EndPx < threshold) break; // Gap found
                    
                    // Consume tail
                    this->Line_Tail_Ptrs[y] = prev;
                    prev->Next = nullptr;
                    this->VSList.FreeNode(tail);
                    this->Span_Count[y]--;
                    tail = prev;
                    
                    if (prev->EndPx < threshold) return; // Should catch by break above
                }
                // Extend the node we stopped at
                tail->StartPx = x1;
                tail->EndPx = x2;
                return;
            }
        }
    } 
    else {
        // x1 <= LeftMostPx
        // Insert at head or merge with head
        if (x2 < left_most - 1) {
            // Strictly before head
            VSpan_Node *node = this->VSList.GetNode();
            node->Prev = nullptr;
            node->Next = curr; // curr is head
            curr->Prev = node;
            node->StartPx = x1;
            node->EndPx = x2;
            
            this->LeftMostPx[y] = x1;
            this->Line_Head_Ptrs[y] = node;
            this->Span_Count[y]++;
            return;
        }
        
        // Check for total coverage or merge
        if (this->RightMostPx[y] <= x2) {
            // New span covers EVERYTHING on this line
            int freed = this->VSList.FreeThread(curr->Next, nullptr);
            this->Span_Count[y] -= freed;
            
            curr->Prev = nullptr;
            curr->Next = nullptr;
            curr->StartPx = x1;
            curr->EndPx = x2;
            
            this->Line_Tail_Ptrs[y] = curr;
            this->RightMostPx[y] = x2;
            this->LeftMostPx[y] = x1;
            return;
        }
        
        // Update left bound
        this->LeftMostPx[y] = x1;
        int threshold = x2 + 1;
        
        if (curr->StartPx <= threshold) {
            while (true) {
                if (x2 <= curr->EndPx) {
                    curr->StartPx = x1;
                    return;
                }
                // Curr fully covered
                VSpan_Node *next = curr->Next;
                if (threshold < next->StartPx) break; // Gap
                
                // Consume curr
                this->Line_Head_Ptrs[y] = next;
                next->Prev = nullptr;
                this->VSList.FreeNode(curr);
                this->Span_Count[y]--;
                curr = next;
                
                if (threshold < next->StartPx) return;
            }
            curr->StartPx = x1;
            curr->EndPx = x2;
            return;
        }
    }
}

// Address: 004bdea0
void TSpan_List_Manager::AddShape(TShape *shape, int frame, int x, int y, int flag) {
    if (!shape || !shape->FShape) return;
    
    Shape_Info *info = shape->shape_info;
    // Access outlines stored in resource
    // FShape + Outline Offset (Note: pointer arithmetic based on bytes)
    long *outline_ptr = (long *)((uchar*)shape->FShape + info[frame].Shape_Outline_Offset);
    
    int right_edge = info[frame].Width - 1 + x;
    int curr_y = y;
    int limit_y = y + info[frame].Height;
    
    if (flag == 0) {
        // Normal orientation
        while (curr_y < limit_y) {
            long val = *outline_ptr;
            ushort *val_shorts = (ushort*)outline_ptr;
            // outline_ptr structure: [LowShort: LeftOffset] [HighShort: RightOffset] (packed in long)
            // But decomp does: puVar1 = (ushort *)((int)plVar7 + 2);
            // This suggests the long contains 2 shorts.
            
            ushort left_off = (ushort)val; // Low word
            ushort right_off = val_shorts[1]; // High word
            
            outline_ptr++;
            
            if (curr_y >= this->Min_Line && curr_y <= this->Max_Line) {
                if (!(left_off & 0x8000)) { // Check for transparent/skip flag?
                    // Decomp: (short)(ushort)lVar5 + param_3
                    AddSpan((short)left_off + x, right_edge - (short)right_off, curr_y);
                }
            }
            curr_y++;
        }
    } else {
        // Flipped orientation? Decomp logic differs slightly in reading
        while (curr_y < limit_y) {
            long val = *outline_ptr;
            ushort *val_shorts = (ushort*)outline_ptr;
            // Swap reading for flip?
            ushort val1 = val_shorts[0];
            ushort val2 = val_shorts[1]; 
            // Decomp: pcVar2 = (char *)((int)plVar7 + 2); checks if val2 & 0x8000
            // Adds span: (short)val2 + x, right - (short)val1
            
            outline_ptr++;
            
            if (curr_y >= this->Min_Line && curr_y <= this->Max_Line) {
                if (!(val2 & 0x8000)) {
                    AddSpan((short)val2 + x, right_edge - (short)val1, curr_y);
                }
            }
            curr_y++;
        }
    }
}

// Address: 004bdfa0
void TSpan_List_Manager::AddShape_Align(uchar *data, Shape_Info *info, int x, int y, int flag) {
    if (!info) return;
    
    ushort *outline_data = (ushort *)(data + info->Shape_Outline_Offset);
    int right_edge = info->Width - 1 + x;
    int curr_y = y;
    int limit_y = y + info->Height;
    
    // Logic similar to AddShape but aligns coordinates to 4-pixel grid ( & 0xFFFFFFFC, | 3)
    if (flag == 0) {
        while (curr_y < limit_y) {
            ushort left = *outline_data;
            ushort right = *(outline_data + 1);
            outline_data += 2;
            
            if (curr_y >= this->Min_Line && curr_y <= this->Max_Line && !(left & 0x8000)) {
                AddSpan(((short)left + x) & 0xFFFFFFFC, (right_edge - (short)right) | 3, curr_y);
            }
            curr_y++;
        }
    } else {
        while (curr_y < limit_y) {
            ushort left = *outline_data;
            ushort right = *(outline_data + 1);
            outline_data += 2;
            
            if (curr_y >= this->Min_Line && curr_y <= this->Max_Line && !(right & 0x8000)) {
                AddSpan(((short)right + x) & 0xFFFFFFFC, (right_edge - (short)left) | 3, curr_y);
            }
            curr_y++;
        }
    }
}

// Address: 004be090
void TSpan_List_Manager::AddLine_Align(int x1, int y1, int x2, int y2) {
    // Adds a line to the span list, aligned to 4-pixel chunks. 
    // Used for fog of war/visibility lines.
    
    if (x1 == x2) {
        // Vertical line
        int start_y = (y1 < y2) ? y1 : y2;
        int end_y = (y1 < y2) ? y2 : y1;
        for (int y = start_y; y <= end_y; y++) {
            AddSpan(x1 & 0xFFFFFFFC, x1 | 3, y);
        }
    } else if (y1 == y2) {
        // Horizontal line
        int start_x = (x1 < x2) ? x1 : x2;
        int end_x = (x1 < x2) ? x2 : x1;
        AddSpan(start_x & 0xFFFFFFFC, end_x | 3, y1);
    } else {
        // Bresenham-like algorithm for diagonal lines
        int dx = (x2 > x1) ? (x2 - x1) : (x1 - x2);
        int dy = (y2 > y1) ? (y2 - y1) : (y1 - y2);
        int step_x = (x2 > x1) ? 1 : -1;
        int step_y = (y2 > y1) ? 1 : -1;
        
        int err = (dx > dy ? dx : -dy) / 2;
        int e2;
        
        // Note: The decomp uses a slightly optimized loop structure for span addition
        // Simplified equivalent logic:
        int cur_x = x1;
        int cur_y = y1;
        
        // This loop handles the aligned span addition per scanline
        // Since we want aligned blocks, we add [cur_x & ~3, cur_x | 3]
        
        // Decomp logic matches standard line drawing but calls AddSpan iteratively
        // To preserve exact behavior, implementing the specific loop from decomp:
        
        int count_major = (dx > dy) ? dx : dy;
        int inc_major = (dx > dy) ? step_x : step_y;
        int inc_minor = (dx > dy) ? step_y : step_x;
        int d_minor = (dx > dy) ? dy : dx;
        int d_major = (dx > dy) ? dx : dy;
        
        int accum = 0;
        int x = x1;
        int y = y1;
        
        if (dx >= dy) {
            // X Major
            int run_start_x = x;
            for (int i = 0; i <= dx; i++) {
                accum += dy;
                if (accum >= dx) {
                    // Y step imminent or end
                    // For alignment, we just add the block at current coords?
                    // Decomp is confusing here, looks like it runs a span for horizontal segments
                    AddSpan(x & 0xFFFFFFFC, x | 3, y);
                    y += step_y;
                    accum -= dx;
                }
                x += step_x;
            }
        } else {
            // Y Major
             for (int i = 0; i <= dy; i++) {
                accum += dx;
                if (accum >= dy) {
                    AddSpan(x & 0xFFFFFFFC, x | 3, y);
                    x += step_x;
                    accum -= dy;
                } else {
                    AddSpan(x & 0xFFFFFFFC, x | 3, y);
                }
                y += step_y;
            }
        }
    }
}

// Address: 004be1f0
void TSpan_List_Manager::AddMiniList(VSpanMiniList *list, int x_off, int y_off) {
    if (!list) return;
    while (list->Y_delta != 0xFF) { // 0xFF (-1 char) terminator
        // Casts to uint to handle char logic from decomp
        AddSpan((uint8_t)list->X_start + x_off, (uint8_t)list->X_end + x_off, (uint8_t)list->Y_delta + y_off);
        list++;
    }
}

// Address: 004be240
void TSpan_List_Manager::SubtractMiniList(VSpanMiniList *list, int x_off, int y_off) {
    if (!list) return;
    while (list->Y_delta != 0xFF) { // 0xFF terminator (actually char 255)
        DeleteSpan((uint8_t)list->X_start + x_off, (uint8_t)list->X_end + x_off, (uint8_t)list->Y_delta + y_off);
        list++;
    }
}

// Address: 004be290
void TSpan_List_Manager::DeleteSpan(int x1, int x2, int y) {
    // Inverse of AddSpan - removes range [x1, x2] from line y
    if (y < this->Min_Line || y > this->Max_Line) return;

    if (x2 < x1) { int t = x1; x1 = x2; x2 = t; }

    if (x1 < this->Min_Span_Px) x1 = this->Min_Span_Px;
    if (x2 > this->Max_Span_Px) x2 = this->Max_Span_Px;
    if (x1 > x2) return;

    VSpan_Node *curr = this->Line_Head_Ptrs[y];
    if (!curr) return;
    
    // Quick bounds check
    if (x2 < this->LeftMostPx[y] || x1 > this->RightMostPx[y]) return;
    
    // Total obliteration check
    if (x1 <= this->LeftMostPx[y] && x2 >= this->RightMostPx[y]) {
        this->VSList.FreeThread(curr, this->Line_Tail_Ptrs[y]);
        this->Line_Head_Ptrs[y] = nullptr;
        this->Line_Tail_Ptrs[y] = nullptr;
        this->Span_Count[y] = 0;
        this->LeftMostPx[y] = 0;
        this->RightMostPx[y] = 0;
        return;
    }

    // Traverse to find intersection
    VSpan_Node *tail = this->Line_Tail_Ptrs[y];
    
    // Decomp logic implies scanning
    while (curr && curr->EndPx < x1) {
        curr = curr->Next;
    }
    
    // Process intersections
    while (curr && curr->StartPx <= x2) {
        VSpan_Node *next = curr->Next;
        
        // Case: Split node
        if (curr->StartPx < x1 && curr->EndPx > x2) {
            VSpan_Node *new_node = this->VSList.GetNode();
            new_node->Prev = curr;
            new_node->Next = curr->Next;
            curr->Next = new_node;
            if (new_node->Next) new_node->Next->Prev = new_node;
            else this->Line_Tail_Ptrs[y] = new_node;
            
            new_node->StartPx = x2 + 1;
            new_node->EndPx = curr->EndPx;
            curr->EndPx = x1 - 1;
            this->Span_Count[y]++;
            return; // Done
        }
        
        // Case: Truncate Right
        if (curr->StartPx < x1) {
            curr->EndPx = x1 - 1;
        }
        // Case: Truncate Left
        else if (curr->EndPx > x2) {
            curr->StartPx = x2 + 1;
        }
        // Case: Delete Node
        else {
            if (curr->Prev) curr->Prev->Next = curr->Next;
            else this->Line_Head_Ptrs[y] = curr->Next;
            
            if (curr->Next) curr->Next->Prev = curr->Prev;
            else this->Line_Tail_Ptrs[y] = curr->Prev;
            
            this->VSList.FreeNode(curr);
            this->Span_Count[y]--;
        }
        
        curr = next;
    }
    
    // Re-calculate bounds if needed
    if (this->Line_Head_Ptrs[y]) {
        this->LeftMostPx[y] = this->Line_Head_Ptrs[y]->StartPx;
        this->RightMostPx[y] = this->Line_Tail_Ptrs[y]->EndPx;
    } else {
        this->LeftMostPx[y] = 0;
        this->RightMostPx[y] = 0;
    }
}

// Address: 004be4b0
void TSpan_List_Manager::DeleteShape(TShape *shape, int frame, int x, int y, int flag) {
    if (!shape || !shape->FShape) return;
    
    Shape_Info *info = shape->shape_info;
    long *outline_ptr = (long *)((uchar*)shape->FShape + info[frame].Shape_Outline_Offset);
    
    int right_edge = info[frame].Width - 1 + x;
    int curr_y = y;
    int limit_y = y + info[frame].Height;
    
    while (curr_y < limit_y) {
        long val = *outline_ptr++;
        // Assuming outline format matches AddShape: Low=Left, High=Right
        ushort *shorts = (ushort*)&val;
        ushort left_off, right_off;
        
        if (flag == 0) {
            left_off = shorts[0];
            right_off = shorts[1];
        } else {
            // Decomp implies swapping or different offsets for flipped
            left_off = shorts[1];
            right_off = shorts[0];
        }

        if (!(left_off & 0x8000)) { // Check "transparency" bit
             int x1, x2;
             if (flag == 0) {
                 x1 = x + (short)left_off;
                 x2 = right_edge - (short)right_off;
             } else {
                 x1 = x + (short)left_off; // Reusing var names based on decomp logic
                 x2 = right_edge - (short)right_off; // It effectively subtracts the 'start' from right side
             }
             DeleteSpan(x1, x2, curr_y);
        }
        curr_y++;
    }
}

// Address: 004be5b0
int TSpan_List_Manager::PointVisible(int x, int y) {
    if (y >= 0 && y < this->Num_Lines) {
        VSpan_Node *curr = this->Line_Head_Ptrs[y];
        while (curr) {
            if (x >= curr->StartPx && x <= curr->EndPx) return 1;
            curr = curr->Next;
        }
    }
    return 0;
}

// Address: 004be5f0
void TSpan_List_Manager::Merge_n_Align(TSpan_List_Manager *list1, TSpan_List_Manager *list2) {
    ResetAll();
    
    if (this->Num_Lines != list1->Num_Lines || this->Num_Lines != list2->Num_Lines) return;
    
    for (int y = 0; y < this->Num_Lines; y++) {
        VSpan_Node *n1 = list1->Line_Head_Ptrs[y];
        VSpan_Node *n2 = list2->Line_Head_Ptrs[y];
        
        while (n1 || n2) {
            if (n1) {
                AddSpan(n1->StartPx & 0xFFFFFFFC, n1->EndPx | 3, y);
                n1 = n1->Next;
            }
            if (n2) {
                AddSpan(n2->StartPx & 0xFFFFFFFC, n2->EndPx | 3, y);
                n2 = n2->Next;
            }
        }
    }
}

// Address: 004be690
void TSpan_List_Manager::AlignamizeSpans() {
    for (int y = 0; y < this->Num_Lines; y++) {
        VSpan_Node *curr = this->Line_Head_Ptrs[y];
        while (curr) {
            VSpan_Node *next = curr->Next;
            
            curr->StartPx &= 0xFFFFFFFC;
            curr->EndPx |= 3;
            
            // Check if expansion overlaps with next
            if (next) {
                if (curr->EndPx >= (next->StartPx & 0xFFFFFFFC) - 1) {
                    // Merge
                    curr->EndPx = next->EndPx | 3;
                    curr->Next = next->Next;
                    
                    if (curr->Next) curr->Next->Prev = curr;
                    else this->Line_Tail_Ptrs[y] = curr;
                    
                    this->VSList.FreeNode(next);
                    this->Span_Count[y]--;
                    continue; // Re-evaluate curr with new next
                }
            }
            curr = curr->Next;
        }
        // Update bounds
        if (this->Line_Head_Ptrs[y]) {
            this->LeftMostPx[y] = this->Line_Head_Ptrs[y]->StartPx;
            this->RightMostPx[y] = this->Line_Tail_Ptrs[y]->EndPx;
        }
    }
}

// Address: 004bead0
int TSpan_List_Manager::DecodeLine(uchar *buffer, int y, uchar color, int width) {
    if (y < 0 || y >= this->Num_Lines) return 0;
    
    int drawn = 0;
    VSpan_Node *curr = this->Line_Head_Ptrs[y];
    while (curr) {
        int start = curr->StartPx;
        int end = curr->EndPx;
        if (start < 0) start = 0;
        if (end >= width) end = width - 1;
        
        for (int x = start; x <= end; x++) {
            buffer[x] += color; // Note: Logic is `+= color`, likely for heatmaps or overlap counting
        }
        drawn++;
        curr = curr->Next;
    }
    return drawn;
}

// Address: 004beb10
void TSpan_List_Manager::take_snapshot(char *filename_fmt, int *seq, TDrawArea *draw_area, int color_base, TSpan_List_Manager **others, int *colors, int count) {
    
    #pragma pack(push, 1)
    struct InternalBMPHeader {
        uint16_t bfType;
        uint32_t bfSize;
        uint16_t bfReserved1;
        uint16_t bfReserved2;
        uint32_t bfOffBits;
    } bmFH;

    struct InternalBMPInfo {
        uint32_t biSize;
        int32_t  biWidth;
        int32_t  biHeight;
        uint16_t biPlanes;
        uint16_t biBitCount;
        uint32_t biCompression;
        uint32_t biSizeImage;
        int32_t  biXPelsPerMeter;
        int32_t  biYPelsPerMeter;
        uint32_t biClrUsed;
        uint32_t biClrImportant;
    } bmIH;
    #pragma pack(pop)

    struct RGBQ { uint8_t b, g, r, a; } bmPAL[256];

    PALETTEENTRY thePal[256];
    draw_area->GetPalette(thePal);
    
    for (int i = 0; i < 256; i++) {
        bmPAL[i].r = thePal[i].peRed;
        bmPAL[i].g = thePal[i].peGreen;
        bmPAL[i].b = thePal[i].peBlue;
        bmPAL[i].a = 0;
    }

    // Determine filename
    char filename[260];
    int fd = -1;
    while (true) {
        sprintf(filename, filename_fmt ? filename_fmt : "C:\\AOE_%03d.BMP", *seq);
        fd = _open(filename, _O_RDONLY | _O_BINARY);
        if (fd == -1) break;
        _close(fd);
        (*seq)++;
    }

    fd = _open(filename, _O_WRONLY | _O_CREAT | _O_TRUNC | _O_BINARY, _S_IWRITE);
    if (fd == -1) return;

    int width = this->Num_Pixels;
    int height = this->Num_Lines;
    uint32_t row_pitch = (width + 3) & ~3;
    
    bmFH.bfType = 0x4D42;
    bmFH.bfSize = sizeof(bmFH) + sizeof(bmIH) + sizeof(bmPAL) + (row_pitch * height);
    bmFH.bfReserved1 = 0;
    bmFH.bfReserved2 = 0;
    bmFH.bfOffBits = sizeof(bmFH) + sizeof(bmIH) + sizeof(bmPAL);

    bmIH.biSize = sizeof(bmIH);
    bmIH.biWidth = width;
    bmIH.biHeight = height;
    bmIH.biPlanes = 1;
    bmIH.biBitCount = 8;
    bmIH.biCompression = 0;
    bmIH.biSizeImage = 0;
    bmIH.biXPelsPerMeter = 0;
    bmIH.biYPelsPerMeter = 0;
    bmIH.biClrUsed = 0;
    bmIH.biClrImportant = 0;

    _write(fd, &bmFH, sizeof(bmFH));
    _write(fd, &bmIH, sizeof(bmIH));
    _write(fd, bmPAL, sizeof(bmPAL));

    uchar *line_buf = (uchar*)malloc(row_pitch);
    for (int y = height - 1; y >= 0; y--) {
        memset(line_buf, 0, row_pitch);
        this->DecodeLine(line_buf, y, (uchar)color_base, width);
        if (count > 0 && others) {
            for (int i = 0; i < count; i++) {
                if (others[i]) {
                    uchar col = (colors) ? (uchar)colors[i] : 255; 
                    others[i]->DecodeLine(line_buf, y, col, width);
                }
            }
        }
        _write(fd, line_buf, row_pitch);
    }

    free(line_buf);
    _close(fd);
    (*seq)++;
}
