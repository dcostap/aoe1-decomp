#include "../include/spanlist.h"

// These views are private. Drawarea and Shape own their shared declarations.
struct Shape_Info {
    unsigned long Shape_Data_Offsets;
    unsigned long Shape_Outline_Offset;
    long Reserved1;
    long Reserved2;
    long Width;
    long Height;
    long Hotspot_X;
    long Hotspot_Y;
};

struct SLhape_File_Header {
    char Version[4];
    long Num_Shapes;
    char Comment[24];
};

class TShape {
public:
    unsigned char* shape;
    int load_type;
    int load_size;
    Shape_Header* shape_header;
    Shape_File_Header* head;
    Shape_Offsets* offsets;
    SLhape_File_Header* FShape;
    Shape_Info* shape_info;
};

class TDrawArea {
public:
    void GetPalette(PALETTEENTRY* palette);
};

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" void* __cdecl malloc(unsigned int size);
extern "C" int __cdecl abs(int);
extern "C" int __cdecl open(const char* path, int flags, ...);
extern "C" int __cdecl close(int fd);
extern "C" int __cdecl write(int fd, const void* buf, unsigned int count);

TSpan_Node_List::TSpan_Node_List(int p1, int p2, int p3)
    : Free_Pool_Zone(-1), Free_Pool_Index(-1), Zone_Ptrs(0),
      Zone_Size_Ptrs(0), Used_Zones(0), Free_Head(0), Total_Blocks(0),
      Free_Blocks(0), Max_Zones(8), Default_Grow_Size(p2), Element_Size(p3)
{
    ResetStats();
    SetNumZones(8);
    InitNewZone(p1);
}

TSpan_Node_List::~TSpan_Node_List(void)
{
    int i = 0;

    while (i < this->Used_Zones) {
        if (this->Zone_Ptrs[i] != 0) {
            free(this->Zone_Ptrs[i]);
        }
        i++;
    }

    if (this->Zone_Ptrs != 0) {
        free(this->Zone_Ptrs);
    }
    if (this->Zone_Size_Ptrs != 0) {
        free(this->Zone_Size_Ptrs);
    }
}

void TSpan_Node_List::SetNumZones(int newCount)
{
    if (newCount >= this->Max_Zones) {
        VSpan_Node** newZonePtrs = (VSpan_Node**)calloc(newCount, 4);
        int* newZoneSizePtrs = (int*)calloc(newCount, 4);

        if (this->Zone_Ptrs) {
            for (int i = 0; i < this->Used_Zones; i++) {
                newZonePtrs[i] = this->Zone_Ptrs[i];
                newZoneSizePtrs[i] = this->Zone_Size_Ptrs[i];
            }

            free(this->Zone_Ptrs);
            free(this->Zone_Size_Ptrs);
        }

        this->Zone_Ptrs = newZonePtrs;
        this->Zone_Size_Ptrs = newZoneSizePtrs;
        this->Max_Zones = newCount;
    }
}

void TSpan_Node_List::InitNewZone(int growSize)
{
    if (this->Used_Zones == this->Max_Zones) {
        SetNumZones(this->Used_Zones + 4);
    }

    int idx = this->Used_Zones;
    int grow = growSize;
    int* sizes = this->Zone_Size_Ptrs;
    this->Used_Zones = idx + 1;
    int bytes = this->Element_Size * grow;
    sizes[idx] = grow;
    this->Zone_Ptrs[idx] = (VSpan_Node*)malloc(bytes);

    this->NewZone_Count++;
    this->Total_Blocks += growSize;
    this->Free_Blocks += growSize;

    if (this->Free_Pool_Zone == -1) {
        this->Free_Pool_Zone = idx;
        this->Free_Pool_Index = 0;
    }
}

VSpan_Node* TSpan_Node_List::GetNode()
{
    if (this->Free_Blocks == 0) {
        this->InitNewZone(this->Default_Grow_Size);
    }

    if (this->Free_Head != 0) {
        VSpan_Node* node = this->Free_Head;
        this->Free_Head = node->Next;
        this->Free_Blocks--;
        return node;
    }

    int zone = this->Free_Pool_Zone;
    VSpan_Node* result = this->Zone_Ptrs[zone] + this->Free_Pool_Index;

    this->Free_Blocks--;
    this->Free_Pool_Index++;

    if (this->Free_Pool_Index == this->Zone_Size_Ptrs[zone]) {
        this->Free_Pool_Zone = zone + 1;
        this->Free_Pool_Index = 0;
        if (zone + 1 == this->Used_Zones) {
            this->Free_Pool_Zone = -1;
        }
    }

    return result;
}

void TSpan_Node_List::FreeNode(VSpan_Node* node)
{
    node->Next = this->Free_Head;
    node->Prev = 0;
    this->Free_Head = node;
    this->Free_Blocks = this->Free_Blocks + 1;
}

int TSpan_Node_List::FreeThread(VSpan_Node* first, VSpan_Node* second)
{
    int count;
    VSpan_Node* current;
    VSpan_Node* last;

    count = 0;
    current = first;
    if (first == 0) {
        return 0;
    }

    if (second == 0) {
        do {
            last = current;
            this->Free_Blocks = this->Free_Blocks + 1;
            count = count + 1;
            current = last->Next;
        } while (current != 0);
        last->Next = this->Free_Head;
        this->Free_Head = first;
    } else {
        do {
            this->Free_Blocks = this->Free_Blocks + 1;
            count = count + 1;
            if (current != second) {
                current = current->Next;
            } else {
                current = 0;
            }
        } while (current != 0);
        second->Next = this->Free_Head;
        this->Free_Head = first;
    }

    return count;
}

void TSpan_Node_List::ReclaimAllNodes()
{
    this->Free_Head = 0;
    this->Free_Pool_Zone = 0;
    this->Free_Pool_Index = 0;
    this->Free_Blocks = this->Total_Blocks;
    this->Reset_Count++;
}

void TSpan_Node_List::ResetStats()
{
    this->Alloc_Count = 0;
    this->Dealloc_Count = 0;
    this->NewZone_Count = 0;
    this->Reset_Count = 0;
}

TSpan_List_Manager::TSpan_List_Manager(int NumPixels, int NumLines)
    : VSList(((NumPixels + 31) / 32) * NumLines, NumLines << 4, 0x10)
{
    this->Num_Lines = NumLines;
    if (NumLines < 0x10) this->Num_Lines = 0x10;
    this->Num_Pixels = NumPixels;
    if (NumPixels < 0x10) this->Num_Pixels = 0x10;
    this->SetSpanRegions(0, 0, this->Num_Pixels - 1,
                         this->Num_Lines - 1);
    this->Line_Head_Ptrs = (VSpan_Node**)calloc(this->Num_Lines, 4);
    this->Line_Tail_Ptrs = (VSpan_Node**)calloc(this->Num_Lines, 4);
    this->LeftMostPx = (int*)calloc(this->Num_Lines, 4);
    this->RightMostPx = (int*)calloc(this->Num_Lines, 4);
    this->Span_Count = (int*)calloc(this->Num_Lines, 4);
}

TSpan_List_Manager::~TSpan_List_Manager()
{
    if (Line_Head_Ptrs != 0) free(Line_Head_Ptrs);
    if (Line_Tail_Ptrs != 0) free(Line_Tail_Ptrs);
    if (LeftMostPx != 0) free(LeftMostPx);
    if (RightMostPx != 0) free(RightMostPx);
    if (Span_Count != 0) free(Span_Count);
}

void TSpan_List_Manager::SetSpanRegions(int param_1, int param_2,
                                        int param_3, int param_4)
{
    int temp;

    if (param_1 > param_3) {
        temp = param_1;
        param_1 = param_3;
        param_3 = temp;
    }

    if (param_2 > param_4) {
        temp = param_2;
        param_2 = param_4;
        param_4 = temp;
    }

    if (param_2 < 0) {
        param_2 = 0;
    }
    if (param_4 < 0) {
        return;
    }

    temp = this->Num_Lines;
    if (param_2 >= temp) {
        return;
    }
    if (param_4 >= temp) {
        param_4 = temp - 1;
    }

    if (param_1 < 0) {
        param_1 = 0;
    }
    if (param_3 < 0) {
        return;
    }

    temp = this->Num_Pixels;
    if (param_1 >= temp) {
        return;
    }
    if (param_3 >= temp) {
        param_3 = temp - 1;
    }

    this->Min_Line = param_2;
    this->Max_Line = param_4;
    this->Min_Span_Px = param_1;
    this->Max_Span_Px = param_3;
}

void TSpan_List_Manager::ResetAll()
{
    this->VSList.ReclaimAllNodes();

    {
        unsigned int size = this->Num_Lines * 4;
        memset(this->Line_Head_Ptrs, 0, size);
    }
    {
        unsigned int size = this->Num_Lines * 4;
        memset(this->Line_Tail_Ptrs, 0, size);
    }
    {
        unsigned int size = this->Num_Lines * 4;
        memset(this->LeftMostPx, 0, size);
    }
    {
        unsigned int size = this->Num_Lines * 4;
        memset(this->RightMostPx, 0, size);
    }
    {
        unsigned int size = this->Num_Lines * 4;
        memset(this->Span_Count, 0, size);
    }
}

void TSpan_List_Manager::AddSpan(int start, int end, int line)
{
    VSpan_Node* node;
    VSpan_Node* other;
    VSpan_Node* next;
    int temp;

    if (line < this->Min_Line || line > this->Max_Line) {
        return;
    }

    if (start > end) {
        temp = end;
        end = start;
        start = temp;
    }

    if (end < this->Min_Span_Px || start > this->Max_Span_Px) {
        return;
    }
    if (start < this->Min_Span_Px) {
        start = this->Min_Span_Px;
    }
    if (end > this->Max_Span_Px) {
        end = this->Max_Span_Px;
    }

    node = this->Line_Head_Ptrs[line];
    if (node == 0) {
        node = this->VSList.GetNode();
        node->Prev = 0;
        node->Next = 0;
        node->StartPx = start;
        node->EndPx = end;
        this->Line_Head_Ptrs[line] = node;
        this->Line_Tail_Ptrs[line] = node;
        this->LeftMostPx[line] = start;
        this->RightMostPx[line] = end;
        this->Span_Count[line] = this->Span_Count[line] + 1;
        return;
    }

    other = this->Line_Tail_Ptrs[line];
    if (start <= this->LeftMostPx[line]) {
        if (end < this->LeftMostPx[line] - 1) {
            other = this->VSList.GetNode();
            other->Prev = 0;
            other->Next = node;
            node->Prev = other;
            other->StartPx = start;
            other->EndPx = end;
            this->LeftMostPx[line] = start;
            this->Line_Head_Ptrs[line] = other;
            this->Span_Count[line] = this->Span_Count[line] + 1;
            return;
        }

        if (end >= this->RightMostPx[line]) {
            int* count = this->Span_Count;
            temp = this->VSList.FreeThread(node->Next, 0);
            count[line] = count[line] - temp;
            node->Prev = 0;
            node->Next = 0;
            node->StartPx = start;
            node->EndPx = end;
            this->Line_Tail_Ptrs[line] = node;
            this->RightMostPx[line] = end;
            this->LeftMostPx[line] = start;
            return;
        }

        this->LeftMostPx[line] = start;
        int boundary = end;
        boundary++;
        if (boundary >= node->StartPx) {
            do {
                if (end <= node->EndPx) {
                    node->StartPx = start;
                    return;
                }
                other = node->Next;
                if (boundary < other->StartPx) {
                    break;
                }
                this->Line_Head_Ptrs[line] = other;
                other->Prev = 0;
                this->VSList.FreeNode(node);
                this->Span_Count[line] = this->Span_Count[line] - 1;
                node = other;
                if (boundary < other->StartPx) {
                    return;
                }
            } while (1);
            node->StartPx = start;
            node->EndPx = end;
        }
    } else {
        if (end >= this->RightMostPx[line]) {
            if (start > this->RightMostPx[line] + 1) {
                node = this->VSList.GetNode();
                node->Prev = other;
                node->Next = 0;
                other->Next = node;
                node->StartPx = start;
                node->EndPx = end;
                this->RightMostPx[line] = end;
                this->Line_Tail_Ptrs[line] = node;
                this->Span_Count[line] = this->Span_Count[line] + 1;
                return;
            }

            this->RightMostPx[line] = end;
            if (start - 1 <= other->EndPx) {
                while (1) {
                    if (start >= other->StartPx) {
                        other->EndPx = end;
                        return;
                    }
                    node = other;
                    other = other->Prev;
                    if (start - 1 > other->EndPx) {
                        break;
                    }
                    this->Line_Tail_Ptrs[line] = other;
                    other->Next = 0;
                    this->VSList.FreeNode(node);
                    this->Span_Count[line] = this->Span_Count[line] - 1;
                    node = other;
                    if (other->EndPx < start - 1) {
                        return;
                    }
                }
                other->StartPx = start;
                other->EndPx = end;
            }
        } else {
            while (node->EndPx < start - 1) {
                node = node->Next;
            }

            if (node->StartPx > end + 1) {
                VSpan_Node* inserted = this->VSList.GetNode();
                other = node->Prev;
                inserted->Next = node;
                inserted->Prev = other;
                node->Prev = inserted;
                inserted->Prev->Next = inserted;
                inserted->StartPx = start;
                inserted->EndPx = end;
                this->Span_Count[line] = this->Span_Count[line] + 1;
                return;
            }

            if (start < node->StartPx) {
                node->StartPx = start;
            }
            if (node->EndPx < end) {
                next = node->Next;
                if (next != 0) {
                    while (1) {
                        if (end + 1 < next->StartPx) {
                            node->EndPx = end;
                            return;
                        }
                        if (end <= next->EndPx) {
                            break;
                        }
                        if (next->Prev != 0) {
                            next->Prev->Next = next->Next;
                        }
                        if (next->Next != 0) {
                            next->Next->Prev = next->Prev;
                        }
                        VSpan_Node* after = next->Next;
                        this->VSList.FreeNode(next);
                        this->Span_Count[line] = this->Span_Count[line] - 1;
                        next = after;
                        if (next == 0) {
                            return;
                        }
                    }
                    node->EndPx = next->EndPx;
                    node->Next = next->Next;
                    this->VSList.FreeNode(next);
                    this->Span_Count[line] = this->Span_Count[line] - 1;
                    if (node->Next != 0) {
                        node->Next->Prev = node;
                        return;
                    }
                    this->Line_Tail_Ptrs[line] = node;
                }
            }
        }
    }
}

void TSpan_List_Manager::AddShape(TShape* shape, int shape_number,
                                  int x, int y, int mirror)
{
    if (shape != 0 && shape->FShape != 0) {
        Shape_Info* info;
        int right;
        info = &shape->shape_info[shape_number];
        unsigned short* outline =
            (unsigned short*)(shape->FShape->Version +
                              info->Shape_Outline_Offset);
        right = info->Width - 1 + x;

        if (mirror == 0) {
            int line = y;
            if (line < y + info->Height) {
                do {
                    unsigned short start = *outline++;
                    unsigned short end = *outline++;
                    if (line >= this->Min_Line && line <= this->Max_Line
                        && (start & 0x8000) == 0) {
                        AddSpan((short)start + x, right - (short)end, line);
                    }
                    line++;
                } while (line < y + info->Height);
                return;
            }
        } else {
            int line = y;
            if (line < y + info->Height) {
                do {
                    unsigned short start = *outline++;
                    unsigned short end = *outline++;
                    if (line >= this->Min_Line && line <= this->Max_Line
                        && (end & 0x8000) == 0) {
                        AddSpan((short)end + x, right - (short)start, line);
                    }
                    line++;
                } while (line < y + info->Height);
            }
        }
    }
}

void TSpan_List_Manager::AddShape_Align(unsigned char* data,
                                        Shape_Info* shape, int x, int y,
                                        int align)
{
    if (shape != 0) {
        unsigned short* outline;
        int line;
        unsigned short start;
        unsigned short end;
        outline = (unsigned short*)(data + shape->Shape_Outline_Offset);
        int right = shape->Width - 1 + x;

        if (align == 0) {
            line = y;
            if (line < y + shape->Height) {
                do {
                    start = *outline++;
                    end = *outline++;
                    if (line >= this->Min_Line && line <= this->Max_Line
                        && (start & 0x8000) == 0) {
                        AddSpan((short)start + x & 0xfffffffc,
                                right - (short)end | 3, line);
                    }
                    line++;
                } while (line < y + shape->Height);
                return;
            }
        } else {
            line = y;
            if (line < y + shape->Height) {
                do {
                    start = *outline++;
                    end = *outline++;
                    if (line >= this->Min_Line && line <= this->Max_Line
                        && (end & 0x8000) == 0) {
                        AddSpan((short)end + x & 0xfffffffc,
                                right - (short)start | 3, line);
                    }
                    line++;
                } while (line < y + shape->Height);
            }
        }
    }
}

void TSpan_List_Manager::AddLine_Align(int x1, int y1, int x2, int y2)
{
    int x1v = x1;
    if (x1v == x2) {
        int line = y1;
        if (line > y2) { int t = line; line = y2; y2 = t; }
        int a = x1v & ~3;
        int b = x1v | 3;
        while (line <= y2) { AddSpan(a, b, line); line++; }
    } else if (y1 == y2) {
        AddSpan(x1v & ~3, x2 | 3, y1);
    } else {
        if (x2 < x1v) {
            int tx = x1v; x1v = x2; x2 = tx;
            int ty = y1; y1 = y2; y2 = ty;
        }
        int dy = x2 - x1v + 1;
        int dx, step_y;
        if (y1 < y2) { dx = y2 - y1 + 1; step_y = 1; }
        else { dx = y1 - y2 + 1; step_y = -1; }
        if (dy >= dx) {
            int err = 0;
            int span_x = x1v;
            int cur_x = x1v;
            while (cur_x < x2) {
                err += dx;
                if (err >= dy) {
                    AddSpan(span_x & ~3, cur_x | 3, y1);
                    y1 += step_y;
                    err -= dy;
                    span_x = cur_x + 1;
                }
                cur_x++;
            }
            AddSpan(span_x & ~3, cur_x | 3, y1);
        } else {
            int y_stop = y2;
            y2 = step_y;
            x2 = 0;
            while (1) {
                AddSpan(x1v & ~3, x1v | 3, y1);
                if (y1 == y_stop) break;
                x2 += dy;
                if (x2 >= dx) { x1v++; x2 -= dx; }
                y1 += y2;
            }
        }
    }
}

void TSpan_List_Manager::AddMiniList(VSpanMiniList* list, int yoff, int xoff)
{
    if (list == 0) {
        return;
    }

    while (list != 0) {
        int y_delta = list->Y_delta;
        if (y_delta == 0xFF) {
            return;
        }
        AddSpan((int)list->X_start + xoff,
                (int)list->X_end + xoff, y_delta + yoff);
        list = (VSpanMiniList*)((char*)list + 3);
    }
}

void TSpan_List_Manager::SubtractMiniList(VSpanMiniList* mini, int x_off,
                                           int y_off)
{
    if (mini == 0) {
        return;
    }

    int add_x = x_off;
    int add_y = y_off;

    while (mini != 0) {
        int y_delta = mini->Y_delta;

        if (y_delta == 0xFF) {
            return;
        }

        this->DeleteSpan((int)mini->X_start + add_x,
                         (int)mini->X_end + add_x,
                         y_delta + add_y);

        mini = (VSpanMiniList*)((char*)mini + 3);
    }
}

void TSpan_List_Manager::DeleteSpan(int left, int right, int line)
{
    if (line < this->Min_Line || line > this->Max_Line) return;

    if (left > right) {
        int t = left;
        left = right;
        right = t;
    }
    if (right < this->Min_Span_Px || left > this->Max_Span_Px) return;
    if (left < this->Min_Span_Px) left = this->Min_Span_Px;
    if (right > this->Max_Span_Px) right = this->Max_Span_Px;

    VSpan_Node* head = this->Line_Head_Ptrs[line];
    if (head != 0) {
        if (right >= this->LeftMostPx[line]) {
            if (left <= this->RightMostPx[line]) {
                if (left <= this->LeftMostPx[line]
                    && right >= this->RightMostPx[line]) {
                    this->VSList.FreeThread(head,
                                            this->Line_Tail_Ptrs[line]);
                    this->Line_Head_Ptrs[line] = 0;
                    this->Line_Tail_Ptrs[line] = 0;
                    this->Span_Count[line] = 0;
                    this->LeftMostPx[line] = 0;
                    this->RightMostPx[line] = 0;
                    return;
                }

                VSpan_Node* last = this->Line_Tail_Ptrs[line];
                VSpan_Node* savedHead = head;
                VSpan_Node* first = head;

                if (first->EndPx < left) {
                    do {
                        first = first->Next;
                    } while (first->EndPx < left);
                }

                if (left > first->StartPx && right < first->EndPx) {
                    VSpan_Node* node = this->VSList.GetNode();
                    node->Prev = first;
                    node->Next = first->Next;
                    first->Next = node;
                    if (node->Next != 0) node->Next->Prev = node;
                    if (first == last) this->Line_Tail_Ptrs[line] = node;
                    node->StartPx = right + 1;
                    node->EndPx = first->EndPx;
                    first->EndPx = left - 1;
                    this->Span_Count[line]++;
                    return;
                }

                if (left > first->StartPx) {
                    first->EndPx = left - 1;
                    first = first->Next;
                }

                VSpan_Node* next;
                if (first != 0) do {
                    if (left <= first->StartPx && right >= first->EndPx) {
                        if (first == head) savedHead = first->Next;
                        if (first == last) last = first->Prev;
                        VSpan_Node* prev = first->Prev;
                        if (prev != 0) prev->Next = first->Next;
                        if (first->Next != 0) first->Next->Prev = first->Prev;
                        next = first->Next;
                        this->VSList.FreeNode(first);
                        this->Span_Count[line]--;
                        head = savedHead;
                        first = next;
                    } else {
                        next = 0;
                    }
                } while (next != 0);
                if (first != 0 && right >= first->StartPx) {
                    first->StartPx = right + 1;
                }
                this->Line_Head_Ptrs[line] = head;
                this->Line_Tail_Ptrs[line] = last;
                this->LeftMostPx[line] = head->StartPx;
                this->RightMostPx[line] = last->EndPx;
            }
        }
    }
}

void TSpan_List_Manager::DeleteShape(TShape* shape, int shape_number,
                                      int x, int y, int mirror)
{
    if (shape != 0 && shape->FShape != 0) {
        Shape_Info* info;
        unsigned short* outline;
        int right;
        int line;
        unsigned short start;
        unsigned short end;

        info = shape->shape_info;
        info = info + shape_number;
        outline =
            (unsigned short*)(shape->FShape->Version +
                               info->Shape_Outline_Offset);
        right = info->Width - 1 + x;

        if (mirror == 0) {
            line = y;
            if (line < y + info->Height) {
                do {
                    start = *outline++;
                    end = *outline++;
                    if ((start & 0x8000) == 0) {
                        this->DeleteSpan(x + (short)start,
                                         right - (short)end, line);
                    }
                    line++;
                } while (line < y + info->Height);
                return;
            }
        } else {
            line = y;
            if (line < y + info->Height) {
                do {
                    start = *outline++;
                    end = *outline++;
                    if ((end & 0x8000) == 0) {
                        this->DeleteSpan(x + (short)end,
                                         right - (short)start, line);
                    }
                    line++;
                } while (line < y + info->Height);
            }
        }
    }
}

int TSpan_List_Manager::PointVisible(int x, int line)
{
    if (line < 0 || line >= this->Num_Lines) return 0;

    VSpan_Node* node = this->Line_Head_Ptrs[line];
    if (!node) return 0;

    while (node) {
        if (x >= node->StartPx && x <= node->EndPx) return 1;
        node = node->Next;
    }

    return 0;
}

void TSpan_List_Manager::Merge_n_Align(TSpan_List_Manager* p1,
                                       TSpan_List_Manager* p2)
{
    ResetAll();

    if (Num_Lines != p1->Num_Lines) return;
    if (Num_Lines != p2->Num_Lines) return;
    if (Num_Pixels != p1->Num_Pixels) return;
    if (Num_Pixels != p2->Num_Pixels) return;

    for (int i = 0; i < Num_Lines; i++) {
        VSpan_Node* node1 = p1->Line_Head_Ptrs[i];
        VSpan_Node* node2 = p2->Line_Head_Ptrs[i];

        while (node1 || node2) {
            if (node1) {
                AddSpan(node1->StartPx & 0xFFFFFFFC, node1->EndPx | 3, i);
                node1 = node1->Next;
            }
            if (node2) {
                AddSpan(node2->StartPx & 0xFFFFFFFC, node2->EndPx | 3, i);
                node2 = node2->Next;
            }
        }
    }
}

void TSpan_List_Manager::AlignamizeSpans()
{
    int i = 0;

    if (0 < this->Num_Lines) {
        do {
            VSpan_Node* node = this->Line_Head_Ptrs[i];

            while (node != 0) {
                VSpan_Node* next = node->Next;

                node->StartPx = node->StartPx & ~3;
                int end = node->EndPx | 3;
                node->EndPx = end;

                if (next != 0) {
                    if (end >= ((next->StartPx & 0x7FFFFFFC) - 1)) {
                        node->EndPx = next->EndPx | 3;
                        node->Next = next->Next;

                        if (next == this->Line_Tail_Ptrs[i]) {
                            this->Line_Tail_Ptrs[i] = node;
                        }

                        if (next->Next != 0) {
                            next->Next->Prev = node;
                        }

                        this->VSList.FreeNode(next);
                        this->Span_Count[i] = this->Span_Count[i] - 1;
                    } else {
                        node = node->Next;
                    }
                } else {
                    node = 0;
                }
            }

            int next_i = i + 1;
            this->LeftMostPx[i] = this->Line_Head_Ptrs[i]->StartPx;
            this->RightMostPx[i] = this->Line_Tail_Ptrs[i]->EndPx;
            i = next_i;
        } while (i < this->Num_Lines);
    }
}

void TSpan_List_Manager::ScrollSpansHorizontally(int dx, int use_regions)
{
    if (dx != 0) {
        if (use_regions != 0 && abs(dx) > this->Max_Span_Px - this->Min_Span_Px) {
            this->ResetAll();
            return;
        }

        int line = 0;
        if (0 < this->Num_Lines) {
            do {
                VSpan_Node* node = this->Line_Head_Ptrs[line];

                while (node != 0) {
                    VSpan_Node* next = node->Next;
                    int start = node->StartPx + dx;
                    int end = node->EndPx + dx;
                    VSpan_Node* prev = node->Prev;

                    if (use_regions != 0) {
                        int min = this->Min_Span_Px;
                        if (end < min || start > this->Max_Span_Px) {
                            if (prev != 0) {
                                prev->Next = next;
                            }
                            if (next != 0) {
                                next->Prev = prev;
                            }
                            this->VSList.FreeNode(node);
                            this->Span_Count[line] = this->Span_Count[line] - 1;
                            node = 0;
                        } else {
                            if (start < min) {
                                start = min;
                            }
                            if (end > this->Max_Span_Px) {
                                end = this->Max_Span_Px;
                            }
                        }
                    }

                    if (node != 0) {
                        node->StartPx = start;
                        node->EndPx = end;
                    }

                    node = next;
                }

                line++;
            } while (line < this->Num_Lines);
        }
    }
}

void TSpan_List_Manager::ScrollSpansVertically(int dy, int use_regions)
{
    int line;
    int src_line;
    int step;
    int clear_first;

    if (dy == 0) {
        return;
    }

    if (use_regions != 0) {
        clear_first = this->Min_Line;
        use_regions = this->Max_Line;
    } else {
        clear_first = 0;
        use_regions = this->Num_Lines - 1;
    }

    if (abs(dy) > use_regions - clear_first) {
        this->ResetAll();
        return;
    }

    line = 0;
    src_line = dy;
    while (line < this->Num_Lines) {
        if (this->Line_Head_Ptrs[line] != 0) {
            if (src_line < clear_first || src_line > use_regions) {
                this->VSList.FreeThread(this->Line_Head_Ptrs[line],
                                        this->Line_Tail_Ptrs[line]);
                this->Line_Head_Ptrs[line] = 0;
                this->Line_Tail_Ptrs[line] = 0;
                this->Span_Count[line] = 0;
                this->LeftMostPx[line] = 0;
                this->RightMostPx[line] = 0;
            }
        }
        line++;
        src_line++;
    }

    if (dy > 0) {
        src_line = this->Num_Lines - dy - 1;
        line = 0;
        step = -1;
        clear_first = 0;
        use_regions = dy - 1;
    } else {
        src_line = dy;
        step = 1;
        clear_first = this->Num_Lines - dy;
        line = this->Num_Lines - 1;
        use_regions = this->Num_Lines;
    }

    line += step;
    if (src_line != line) {
        do {
            this->Line_Head_Ptrs[src_line + dy] = this->Line_Head_Ptrs[src_line];
            this->Line_Tail_Ptrs[src_line + dy] = this->Line_Tail_Ptrs[src_line];
            this->Span_Count[src_line + dy] = this->Span_Count[src_line];
            this->LeftMostPx[src_line + dy] = this->LeftMostPx[src_line];
            this->RightMostPx[src_line + dy] = this->RightMostPx[src_line];
            src_line += step;
        } while (src_line != line);
    }

    if (clear_first <= use_regions) {
        for (; clear_first <= use_regions; clear_first++) {
            this->Line_Head_Ptrs[clear_first] = 0;
            this->Line_Tail_Ptrs[clear_first] = 0;
            this->Span_Count[clear_first] = 0;
            this->LeftMostPx[clear_first] = 0;
            this->RightMostPx[clear_first] = 0;
        }
    }
}

int TSpan_List_Manager::ValidateSpan(int line)
{
    int count = 0;
    int prevEnd = 0;

    if (line >= 0 && line < this->Num_Lines) {
        VSpan_Node* node = this->Line_Head_Ptrs[line];
        if (node == 0) {
            if (this->Line_Tail_Ptrs[line] == 0
                && this->Span_Count[line] == 0
                && this->LeftMostPx[line] == 0) {
                return this->RightMostPx[line] == 0;
            }
        } else {
            VSpan_Node* prev = 0;
            while (node != 0) {
                count++;
                if (count == 1 && node->StartPx != this->LeftMostPx[line]) return 0;
                if (node->Prev != prev) return 0;
                if (node->StartPx > node->EndPx) return 0;
                if (count > 1 && node->StartPx <= prevEnd) return 0;
                prevEnd = node->EndPx;
                prev = node;
                node = node->Next;
            }
            if (this->Span_Count[line] != count) return 0;
            if (this->Line_Tail_Ptrs[line] != prev) return 0;
            if (prev->EndPx != this->RightMostPx[line]) return 0;
            return this->LeftMostPx[line] <= this->RightMostPx[line];
        }
    }
    return 0;
}

int TSpan_List_Manager::DecodeLine(unsigned char* line, int line_index,
                                    unsigned char delta, int unused)
{
    int count = 0;

    if (this->Line_Head_Ptrs[line_index] != 0) {
        VSpan_Node* node = this->Line_Head_Ptrs[line_index];
        do {
            int x = node->StartPx;
            int end = node->EndPx;
            if (x <= end) {
                do {
                    line[x] = line[x] + delta;
                    ++x;
                } while (x <= end);
            }
            node = node->Next;
            ++count;
        } while (node != 0);
    }

    return count;
}

static const char s_default_snapshot_name[] = "C:\\AOE_%03d.BMP";

void TSpan_List_Manager::take_snapshot(char* name, int& number,
                                        TDrawArea* area, int color,
                                        TSpan_List_Manager** spans,
                                        int* colors, int count)
{
    int Width;
    int Height;
    int infile;
    int bmWide;
    BITMAPFILEHEADER bmFH;
    BITMAPINFOHEADER bmIH;
    char BMPFile[0x3C];
    RGBQUAD bmPAL[256];
    PALETTEENTRY thePal[256];

    if (count > 0) {
        int i = 0;
        if (i < count) {
            TSpan_List_Manager** s = spans;
            while (i < count) {
                if (*s == 0) return;
                i++;
                s++;
            }
        }
    }

    Width = this->Num_Lines;
    Height = this->Num_Pixels;
    bmWide = (Height + 3) & 0xfffc;

    bmFH.bfSize = Width * bmWide + 0x436;
    bmFH.bfType = 0x4d42;
    bmFH.bfReserved1 = 0;
    bmFH.bfReserved2 = 0;
    bmFH.bfOffBits = 0x436;

    bmIH.biSize = 0x28;
    bmIH.biWidth = Height;
    bmIH.biHeight = Width;
    bmIH.biPlanes = 1;
    bmIH.biBitCount = 8;
    bmIH.biCompression = 0;
    bmIH.biSizeImage = 0;
    bmIH.biXPelsPerMeter = 0;
    bmIH.biYPelsPerMeter = 0;
    bmIH.biClrUsed = 0;
    bmIH.biClrImportant = 0;
    area->GetPalette(thePal);
    for (int p = 0; p < 0x100; ++p) {
        bmPAL[p].rgbBlue = thePal[p].peBlue;
        bmPAL[p].rgbGreen = thePal[p].peGreen;
        bmPAL[p].rgbRed = thePal[p].peRed;
        bmPAL[p].rgbReserved = 0;
    }

    int tries = 0;
    if (number < 0) number = 0;
    while (1) {
        if (name == 0) sprintf(BMPFile, s_default_snapshot_name, number);
        else sprintf(BMPFile, name, number);
        tries++;
        int fd = open(BMPFile, 0);
        if (fd == -1) break;
        number++;
        close(fd);
        if (tries <= 1000) continue;
        return;
    }

    unsigned char* line = (unsigned char*)malloc(bmWide);
    infile = open(BMPFile, 0x8301, 0x180);
    if (infile != -1) {
        write(infile, &bmFH, 0x0e);
        write(infile, &bmIH, sizeof(bmIH));
        write(infile, bmPAL, 0x400);
        int y = Width - 1;
        if (y >= 0) {
            do {
                memset(line, 0, bmWide);
                this->DecodeLine(line, y, (unsigned char)color, Height);
                if (count > 0) {
                    int i;
                    for (i = 0; i < count; ++i) {
                        spans[i]->DecodeLine(line, y,
                                             (unsigned char)colors[i], Height);
                    }
                }
                write(infile, line, bmWide);
                y--;
            } while (y >= 0);
        }
        close(infile);
    }
    free(line);
}
