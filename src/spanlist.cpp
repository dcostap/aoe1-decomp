#include "../include/spanlist.h"
#include <fcntl.h>
#include <sys/stat.h>

#include <memory.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern "C" void* __cdecl malloc(unsigned int size);
extern "C" int __cdecl abs(int);
extern "C" int __cdecl open(const char* path, int flags, ...);
extern "C" int __cdecl close(int fd);
extern "C" int __cdecl write(int fd, const void* buf, unsigned int count);

TSpan_Node_List::TSpan_Node_List(int InitialSize, int GrowSize, int szitem)
    : Free_Pool_Zone(-1), Free_Pool_Index(-1), Zone_Ptrs(0),
      Zone_Size_Ptrs(0), Used_Zones(0), Free_Head(0), Total_Blocks(0),
      Free_Blocks(0), Max_Zones(8), Default_Grow_Size(GrowSize), Element_Size(szitem) {
    ResetStats();
    SetNumZones(8);
    InitNewZone(InitialSize);
}

TSpan_Node_List::~TSpan_Node_List(void) {
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

void TSpan_Node_List::SetNumZones(int New_Size) {
    if (New_Size >= this->Max_Zones) {
        VSpan_Node** Ptrs = (VSpan_Node**)calloc(New_Size, 4);
        int* newZoneSizePtrs = (int*)calloc(New_Size, 4);

        if (this->Zone_Ptrs) {
            for (int i = 0; i < this->Used_Zones; i++) {
                Ptrs[i] = this->Zone_Ptrs[i];
                newZoneSizePtrs[i] = this->Zone_Size_Ptrs[i];
            }

            free(this->Zone_Ptrs);
            free(this->Zone_Size_Ptrs);
        }

        this->Zone_Ptrs = Ptrs;
        this->Zone_Size_Ptrs = newZoneSizePtrs;
        this->Max_Zones = New_Size;
    }
}

void TSpan_Node_List::InitNewZone(int Zone_Size) {
    if (this->Used_Zones == this->Max_Zones) {
        SetNumZones(this->Used_Zones + 4);
    }

    int idx = this->Used_Zones;
    int grow = Zone_Size;
    int* sizes = this->Zone_Size_Ptrs;
    this->Used_Zones = idx + 1;
    int bytes = this->Element_Size * grow;
    sizes[idx] = grow;
    this->Zone_Ptrs[idx] = (VSpan_Node*)malloc(bytes);

    this->NewZone_Count++;
    this->Total_Blocks += Zone_Size;
    this->Free_Blocks += Zone_Size;

    if (this->Free_Pool_Zone == -1) {
        this->Free_Pool_Zone = idx;
        this->Free_Pool_Index = 0;
    }
}

VSpan_Node* TSpan_Node_List::GetNode() {
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

void TSpan_Node_List::FreeNode(VSpan_Node* theNode) {
    theNode->Next = this->Free_Head;
    theNode->Prev = 0;
    this->Free_Head = theNode;
    this->Free_Blocks = this->Free_Blocks + 1;
}

int TSpan_Node_List::FreeThread(VSpan_Node* HeadNode, VSpan_Node* TailNode) {
    int count;
    VSpan_Node* current;
    VSpan_Node* last;

    count = 0;
    current = HeadNode;
    if (HeadNode == 0) {
        return 0;
    }

    if (TailNode == 0) {
        do {
            last = current;
            this->Free_Blocks = this->Free_Blocks + 1;
            count = count + 1;
            current = last->Next;
        } while (current != 0);
        last->Next = this->Free_Head;
        this->Free_Head = HeadNode;
    } else {
        do {
            this->Free_Blocks = this->Free_Blocks + 1;
            count = count + 1;
            if (current != TailNode) {
                current = current->Next;
            } else {
                current = 0;
            }
        } while (current != 0);
        TailNode->Next = this->Free_Head;
        this->Free_Head = HeadNode;
    }

    return count;
}

void TSpan_Node_List::ReclaimAllNodes() {
    this->Free_Head = 0;
    this->Free_Pool_Zone = 0;
    this->Free_Pool_Index = 0;
    this->Free_Blocks = this->Total_Blocks;
    this->Reset_Count++;
}

void TSpan_Node_List::ResetStats() {
    this->Alloc_Count = 0;
    this->Dealloc_Count = 0;
    this->NewZone_Count = 0;
    this->Reset_Count = 0;
}

TSpan_List_Manager::TSpan_List_Manager(int Surface_Width, int Surface_Height)
    : VSList(((Surface_Width + 31) / 32) * Surface_Height, Surface_Height << 4, 0x10) {
    this->Num_Lines = Surface_Height;
    if (Surface_Height < 0x10) this->Num_Lines = 0x10;
    this->Num_Pixels = Surface_Width;
    if (Surface_Width < 0x10) this->Num_Pixels = 0x10;
    this->SetSpanRegions(0, 0, this->Num_Pixels - 1, this->Num_Lines - 1);
    this->Line_Head_Ptrs = (VSpan_Node**)calloc(this->Num_Lines, 4);
    this->Line_Tail_Ptrs = (VSpan_Node**)calloc(this->Num_Lines, 4);
    this->LeftMostPx = (int*)calloc(this->Num_Lines, 4);
    this->RightMostPx = (int*)calloc(this->Num_Lines, 4);
    this->Span_Count = (int*)calloc(this->Num_Lines, 4);
}

TSpan_List_Manager::~TSpan_List_Manager() {
    if (Line_Head_Ptrs != 0) free(Line_Head_Ptrs);
    if (Line_Tail_Ptrs != 0) free(Line_Tail_Ptrs);
    if (LeftMostPx != 0) free(LeftMostPx);
    if (RightMostPx != 0) free(RightMostPx);
    if (Span_Count != 0) free(Span_Count);
}

void TSpan_List_Manager::SetSpanRegions(int MinS, int MinL, int MaxS, int MaxL) {
    int temp;

    if (MinS > MaxS) {
        temp = MinS;
        MinS = MaxS;
        MaxS = temp;
    }

    if (MinL > MaxL) {
        temp = MinL;
        MinL = MaxL;
        MaxL = temp;
    }

    if (MinL < 0) {
        MinL = 0;
    }
    if (MaxL < 0) {
        return;
    }

    temp = this->Num_Lines;
    if (MinL >= temp) {
        return;
    }
    if (MaxL >= temp) {
        MaxL = temp - 1;
    }

    if (MinS < 0) {
        MinS = 0;
    }
    if (MaxS < 0) {
        return;
    }

    temp = this->Num_Pixels;
    if (MinS >= temp) {
        return;
    }
    if (MaxS >= temp) {
        MaxS = temp - 1;
    }

    this->Min_Line = MinL;
    this->Max_Line = MaxL;
    this->Min_Span_Px = MinS;
    this->Max_Span_Px = MaxS;
}

void TSpan_List_Manager::ResetAll() {
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

void TSpan_List_Manager::AddSpan(int LeftPx, int RightPx, int Line) {
    int temp;

    if (Line < this->Min_Line || Line > this->Max_Line) {
        return;
    }

    if (LeftPx > RightPx) {
        temp = LeftPx;
        LeftPx = RightPx;
        RightPx = temp;
    }

    if (RightPx < this->Min_Span_Px || LeftPx > this->Max_Span_Px) {
        return;
    }
    if (LeftPx < this->Min_Span_Px) {
        LeftPx = this->Min_Span_Px;
    }
    if (RightPx > this->Max_Span_Px) {
        RightPx = this->Max_Span_Px;
    }

    VSpan_Node* head = this->Line_Head_Ptrs[Line];
    if (head == 0) {
        VSpan_Node* node = this->VSList.GetNode();
        node->Prev = 0;
        node->Next = 0;
        node->StartPx = LeftPx;
        node->EndPx = RightPx;
        this->Line_Head_Ptrs[Line] = node;
        this->Line_Tail_Ptrs[Line] = node;
        this->LeftMostPx[Line] = LeftPx;
        this->RightMostPx[Line] = RightPx;
        this->Span_Count[Line] = this->Span_Count[Line] + 1;
        return;
    }

    VSpan_Node* tail = this->Line_Tail_Ptrs[Line];
    int leftmost = this->LeftMostPx[Line];

    if (leftmost < LeftPx) {
        int rightmost = this->RightMostPx[Line];

        if (RightPx < rightmost) {
            VSpan_Node* current = head;
            int current_end = current->EndPx;

            while (current_end < LeftPx - 1) {
                current = current->Next;
                current_end = current->EndPx;
            }

            if (RightPx + 1 < current->StartPx) {
                VSpan_Node* node = this->VSList.GetNode();
                tail = current->Prev;
                node->Next = current;
                node->Prev = tail;
                current->Prev = node;
                node->Prev->Next = node;
                node->StartPx = LeftPx;
                node->EndPx = RightPx;
                this->Span_Count[Line] = this->Span_Count[Line] + 1;
                return;
            }

            if (LeftPx < current->StartPx) {
                current->StartPx = LeftPx;
            }

            if (current->EndPx < RightPx && (tail = current->Next) != 0) {
                for (;;) {
                    if (RightPx + 1 < tail->StartPx) {
                        current->EndPx = RightPx;
                        return;
                    }
                    if (RightPx <= tail->EndPx) {
                        break;
                    }

                    if (tail->Prev != 0) {
                        tail->Prev->Next = tail->Next;
                    }
                    if (tail->Next != 0) {
                        tail->Next->Prev = tail->Prev;
                    }

                    VSpan_Node* next = tail->Next;
                    this->VSList.FreeNode(tail);
                    this->Span_Count[Line] = this->Span_Count[Line] - 1;
                    tail = next;
                    if (next == 0) {
                        return;
                    }
                }

                current->EndPx = tail->EndPx;
                current->Next = tail->Next;
                this->VSList.FreeNode(tail);
                this->Span_Count[Line] = this->Span_Count[Line] - 1;
                if (current->Next != 0) {
                    current->Next->Prev = current;
                    return;
                }
                this->Line_Tail_Ptrs[Line] = current;
            }
        } else {
            if (rightmost + 1 < LeftPx) {
                VSpan_Node* node = this->VSList.GetNode();
                node->Prev = tail;
                node->Next = 0;
                tail->Next = node;
                node->StartPx = LeftPx;
                node->EndPx = RightPx;
                this->RightMostPx[Line] = RightPx;
                this->Line_Tail_Ptrs[Line] = node;
                this->Span_Count[Line] = this->Span_Count[Line] + 1;
                return;
            }

            this->RightMostPx[Line] = RightPx;
            int before = LeftPx - 1;
            if (before <= tail->EndPx) {
                for (;;) {
                    if (tail->StartPx <= LeftPx) {
                        tail->EndPx = RightPx;
                        return;
                    }

                    VSpan_Node* previous = tail->Prev;
                    if (previous->EndPx < before) {
                        break;
                    }

                    this->Line_Tail_Ptrs[Line] = previous;
                    previous->Next = 0;
                    this->VSList.FreeNode(tail);
                    this->Span_Count[Line] = this->Span_Count[Line] - 1;
                    tail = previous;
                    if (previous->EndPx < before) {
                        return;
                    }
                }

                tail->StartPx = LeftPx;
                tail->EndPx = RightPx;
                return;
            }
        }
    } else {
        if (RightPx < leftmost - 1) {
            VSpan_Node* node = this->VSList.GetNode();
            node->Prev = 0;
            node->Next = head;
            head->Prev = node;
            node->StartPx = LeftPx;
            node->EndPx = RightPx;
            this->LeftMostPx[Line] = LeftPx;
            this->Line_Head_Ptrs[Line] = node;
            this->Span_Count[Line] = this->Span_Count[Line] + 1;
            return;
        }

        if (this->RightMostPx[Line] <= RightPx) {
            int* span_count = this->Span_Count + Line;
            int freed = this->VSList.FreeThread(head->Next, 0);
            *span_count = *span_count - freed;
            head->Prev = 0;
            head->Next = 0;
            head->StartPx = LeftPx;
            head->EndPx = RightPx;
            this->Line_Tail_Ptrs[Line] = head;
            this->RightMostPx[Line] = RightPx;
            this->LeftMostPx[Line] = LeftPx;
            return;
        }

        this->LeftMostPx[Line] = LeftPx;
        int after = RightPx + 1;
        if (head->StartPx <= after) {
            for (;;) {
                if (RightPx <= head->EndPx) {
                    head->StartPx = LeftPx;
                    return;
                }

                VSpan_Node* next = head->Next;
                if (after < next->StartPx) {
                    break;
                }

                this->Line_Head_Ptrs[Line] = next;
                next->Prev = 0;
                this->VSList.FreeNode(head);
                this->Span_Count[Line] = this->Span_Count[Line] - 1;
                head = next;
                if (after < next->StartPx) {
                    return;
                }
            }

            head->StartPx = LeftPx;
            head->EndPx = RightPx;
        }
    }
}

void TSpan_List_Manager::AddShape(TShape* theShape, int shape_num, int Xpos, int Ypos, int Mirror) {
    if (theShape != 0 && theShape->FShape != 0) {
        Shape_Info* info;
        int X2;
        info = &theShape->shape_info[shape_num];
        unsigned short* outline =
            (unsigned short*)(theShape->FShape->Version + info->Shape_Outline_Offset);
        X2 = info->Width - 1 + Xpos;
        int height = info->Height;

        if (Mirror == 0) {
            int line = Ypos;
            if (line < Ypos + height) {
                do {
                    unsigned short start = *outline++;
                    unsigned short end = *outline++;
                    if (line >= this->Min_Line && line <= this->Max_Line && (start & 0x8000) == 0) {
                        AddSpan((short)start + Xpos, X2 - (short)end, line);
                    }
                    line++;
                } while (line < Ypos + info->Height);
                return;
            }
        } else {
            int line = Ypos;
            if (line < Ypos + height) {
                do {
                    unsigned short start = *outline++;
                    unsigned short end = *outline++;
                    if (line >= this->Min_Line && line <= this->Max_Line && (end & 0x8000) == 0) {
                        AddSpan((short)end + Xpos, X2 - (short)start, line);
                    }
                    line++;
                } while (line < Ypos + info->Height);
            }
        }
    }
}

void TSpan_List_Manager::AddShape_Align(unsigned char* Shape_Base, Shape_Info* SI, int Xpos, int Ypos, int Mirror) {
    if (SI != 0) {
        unsigned short* outline;
        int line;
        unsigned short start;
        unsigned short end;
        outline = (unsigned short*)(Shape_Base + SI->Shape_Outline_Offset);
        int X2 = SI->Width - 1 + Xpos;

        if (Mirror == 0) {
            line = Ypos;
            if (line < Ypos + SI->Height) {
                do {
                    start = *outline++;
                    end = *outline++;
                    if (line >= this->Min_Line && line <= this->Max_Line && (start & 0x8000) == 0) {
                        AddSpan((short)start + Xpos & 0xfffffffc, X2 - (short)end | 3, line);
                    }
                    line++;
                } while (line < Ypos + SI->Height);
                return;
            }
        } else {
            line = Ypos;
            if (line < Ypos + SI->Height) {
                do {
                    start = *outline++;
                    end = *outline++;
                    if (line >= this->Min_Line && line <= this->Max_Line && (end & 0x8000) == 0) {
                        AddSpan((short)end + Xpos & 0xfffffffc, X2 - (short)start | 3, line);
                    }
                    line++;
                } while (line < Ypos + SI->Height);
            }
        }
    }
}

void TSpan_List_Manager::AddLine_Align(int x1, int y1, int x2, int y2) {
    int temp;
    int x_length;
    int y_length;
    int y_step;
    int error;
    int span_start;

    if (x1 == x2) {
        if (y1 > y2) {
            temp = y1;
            y1 = y2;
            y2 = temp;
        }

        for (; y1 <= y2; y1++) {
            AddSpan(x1 & 0xfffffffc, x1 | 3, y1);
        }
    } else if (y1 == y2) {
        AddSpan(x1 & 0xfffffffc, x2 | 3, y1);
    } else {
        if (x2 < x1) {
            temp = y1;
            y1 = y2;
            y2 = temp;
            temp = x1;
            x1 = x2;
            x2 = temp;
        }

        x_length = x2 - x1 + 1;
        span_start = x1;

        if (y1 < y2) {
            y_step = 1;
            y_length = y2 - y1 + 1;
        } else {
            y_step = -1;
            y_length = y1 - y2 + 1;
        }

        if (y_length <= x_length) {
            error = 0;
            for (; x1 < x2; x1++) {
                error += y_length;
                if (error >= x_length) {
                    AddSpan(span_start & 0xfffffffc, x1 | 3, y1);
                    y1 += y_step;
                    error -= x_length;
                    span_start = x1 + 1;
                }
            }
            AddSpan(span_start & 0xfffffffc, x1 | 3, y1);
        } else {
            error = 0;
            do {
                AddSpan(x1 & 0xfffffffc, x1 | 3, y1);
                if (y1 == y2) {
                    break;
                }
                error += x_length;
                if (error >= y_length) {
                    x1++;
                    error -= y_length;
                }
                y1 += y_step;
            } while (1);
        }
    }
}

void TSpan_List_Manager::AddMiniList(VSpanMiniList* theList, int Xpos, int Ypos) {
    if (theList == 0) {
        return;
    }

    while (theList != 0) {
        int y_delta = theList->Y_delta;
        if (y_delta == 0xFF) {
            return;
        }
        AddSpan(theList->X_start + Xpos, theList->X_end + Xpos, y_delta + Ypos);
        ++theList;
    }
}

void TSpan_List_Manager::SubtractMiniList(VSpanMiniList* theList, int Xpos, int Ypos) {
    if (theList == 0) {
        return;
    }

    int add_x = Xpos;
    int add_y = Ypos;

    while (theList != 0) {
        int y_delta = theList->Y_delta;

        if (y_delta == 0xFF) {
            return;
        }

        this->DeleteSpan((int)theList->X_start + add_x, (int)theList->X_end + add_x, y_delta + add_y);

        theList = (VSpanMiniList*)((char*)theList + 3);
    }
}

void TSpan_List_Manager::DeleteSpan(int LeftPx, int RightPx, int Line) {
    if (Line < this->Min_Line || Line > this->Max_Line) return;

    if (LeftPx > RightPx) {
        int t = LeftPx;
        LeftPx = RightPx;
        RightPx = t;
    }
    if (RightPx < this->Min_Span_Px || LeftPx > this->Max_Span_Px) return;
    if (LeftPx < this->Min_Span_Px) LeftPx = this->Min_Span_Px;
    if (RightPx > this->Max_Span_Px) RightPx = this->Max_Span_Px;

    VSpan_Node* head = this->Line_Head_Ptrs[Line];
    if (head != 0) {
        if (RightPx >= this->LeftMostPx[Line]) {
            if (LeftPx <= this->RightMostPx[Line]) {
                if (LeftPx <= this->LeftMostPx[Line] && RightPx >= this->RightMostPx[Line]) {
                    this->VSList.FreeThread(head, this->Line_Tail_Ptrs[Line]);
                    this->Line_Head_Ptrs[Line] = 0;
                    this->Line_Tail_Ptrs[Line] = 0;
                    this->Span_Count[Line] = 0;
                    this->LeftMostPx[Line] = 0;
                    this->RightMostPx[Line] = 0;
                    return;
                }

                VSpan_Node* R = this->Line_Tail_Ptrs[Line];
                VSpan_Node* L = head;
                VSpan_Node* first = head;

                if (first->EndPx < LeftPx) {
                    do {
                        first = first->Next;
                    } while (first->EndPx < LeftPx);
                }

                if (LeftPx > first->StartPx && RightPx < first->EndPx) {
                    VSpan_Node* node = this->VSList.GetNode();
                    node->Prev = first;
                    node->Next = first->Next;
                    first->Next = node;
                    if (node->Next != 0) node->Next->Prev = node;
                    if (first == R) this->Line_Tail_Ptrs[Line] = node;
                    node->StartPx = RightPx + 1;
                    node->EndPx = first->EndPx;
                    first->EndPx = LeftPx - 1;
                    this->Span_Count[Line]++;
                    return;
                }

                if (LeftPx > first->StartPx) {
                    first->EndPx = LeftPx - 1;
                    first = first->Next;
                }

                VSpan_Node* next;
                if (first != 0) do {
                    if (LeftPx <= first->StartPx && RightPx >= first->EndPx) {
                        if (first == head) L = first->Next;
                        if (first == R) R = first->Prev;
                        VSpan_Node* prev = first->Prev;
                        if (prev != 0) prev->Next = first->Next;
                        if (first->Next != 0) first->Next->Prev = first->Prev;
                        next = first->Next;
                        this->VSList.FreeNode(first);
                        this->Span_Count[Line]--;
                        head = L;
                        first = next;
                    } else {
                        next = 0;
                    }
                } while (next != 0);
                if (first != 0 && RightPx >= first->StartPx) {
                    first->StartPx = RightPx + 1;
                }
                this->Line_Head_Ptrs[Line] = head;
                this->Line_Tail_Ptrs[Line] = R;
                this->LeftMostPx[Line] = head->StartPx;
                this->RightMostPx[Line] = R->EndPx;
            }
        }
    }
}

void TSpan_List_Manager::DeleteShape(TShape* theShape, int shape_num, int Xpos, int Ypos, int Mirror) {
    if (theShape != 0 && theShape->FShape != 0) {
        unsigned short* outline;
        int X2;
        int line;
        unsigned short start;
        unsigned short end;

        Shape_Info* info = &theShape->shape_info[shape_num];
        outline =
            (unsigned short*)(theShape->FShape->Version + info->Shape_Outline_Offset);
        X2 = info->Width - 1 + Xpos;

        if (Mirror == 0) {
            line = Ypos;
            if (line < Ypos + info->Height) {
                do {
                    start = *outline++;
                    end = *outline++;
                    if ((start & 0x8000) == 0) {
                        this->DeleteSpan(Xpos + (short)start, X2 - (short)end, line);
                    }
                    line++;
                } while (line < Ypos + info->Height);
                return;
            }
        } else {
            line = Ypos;
            if (line < Ypos + info->Height) {
                do {
                    start = *outline++;
                    end = *outline++;
                    if ((end & 0x8000) == 0) {
                        this->DeleteSpan(Xpos + (short)end, X2 - (short)start, line);
                    }
                    line++;
                } while (line < Ypos + info->Height);
            }
        }
    }
}

int TSpan_List_Manager::PointVisible(int x, int Line) {
    if (Line < 0 || Line >= this->Num_Lines) return 0;

    VSpan_Node* node = this->Line_Head_Ptrs[Line];
    if (!node) return 0;

    while (node) {
        if (x >= node->StartPx && x <= node->EndPx) return 1;
        node = node->Next;
    }

    return 0;
}

void TSpan_List_Manager::Merge_n_Align(TSpan_List_Manager* List1, TSpan_List_Manager* List2) {
    ResetAll();

    if (Num_Lines != List1->Num_Lines) return;
    if (Num_Lines != List2->Num_Lines) return;
    if (Num_Pixels != List1->Num_Pixels) return;
    if (Num_Pixels != List2->Num_Pixels) return;

    for (int i = 0; i < Num_Lines; i++) {
        VSpan_Node* node1 = List1->Line_Head_Ptrs[i];
        VSpan_Node* node2 = List2->Line_Head_Ptrs[i];

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

void TSpan_List_Manager::AlignamizeSpans() {
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

void TSpan_List_Manager::ScrollSpansHorizontally(int XOffset, int ClipToCurrentRegion) {
    if (XOffset != 0) {
        if (ClipToCurrentRegion != 0 && abs(XOffset) > this->Max_Span_Px - this->Min_Span_Px) {
            this->ResetAll();
            return;
        }

        int y = 0;
        if (0 < this->Num_Lines) {
            do {
                VSpan_Node* node = this->Line_Head_Ptrs[y];

                while (node != 0) {
                    VSpan_Node* next = node->Next;
                    int start = node->StartPx + XOffset;
                    int end = node->EndPx + XOffset;
                    VSpan_Node* prev = node->Prev;

                    if (ClipToCurrentRegion != 0) {
                        int min = this->Min_Span_Px;
                        if (end < min || start > this->Max_Span_Px) {
                            if (prev != 0) {
                                prev->Next = next;
                            }
                            if (next != 0) {
                                next->Prev = prev;
                            }
                            this->VSList.FreeNode(node);
                            this->Span_Count[y] = this->Span_Count[y] - 1;
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

                y++;
            } while (y < this->Num_Lines);
        }
    }
}

void TSpan_List_Manager::ScrollSpansVertically(int YOffset, int ClipToCurrentRegion) {
    int y1;
    int y2;
    int step;
    int ClearStart;

    if (YOffset == 0) {
        return;
    }

    if (ClipToCurrentRegion != 0) {
        ClearStart = this->Min_Line;
        ClipToCurrentRegion = this->Max_Line;
    } else {
        ClearStart = 0;
        ClipToCurrentRegion = this->Num_Lines - 1;
    }

    if (abs(YOffset) > ClipToCurrentRegion - ClearStart) {
        this->ResetAll();
        return;
    }

    y1 = 0;
    y2 = YOffset;
    while (y1 < this->Num_Lines) {
        if (this->Line_Head_Ptrs[y1] != 0) {
            if (y2 < ClearStart || y2 > ClipToCurrentRegion) {
                this->VSList.FreeThread(this->Line_Head_Ptrs[y1], this->Line_Tail_Ptrs[y1]);
                this->Line_Head_Ptrs[y1] = 0;
                this->Line_Tail_Ptrs[y1] = 0;
                this->Span_Count[y1] = 0;
                this->LeftMostPx[y1] = 0;
                this->RightMostPx[y1] = 0;
            }
        }
        y1++;
        y2++;
    }

    if (YOffset > 0) {
        y2 = this->Num_Lines - YOffset - 1;
        y1 = 0;
        step = -1;
        ClearStart = 0;
        ClipToCurrentRegion = YOffset - 1;
    } else {
        y2 = YOffset;
        step = 1;
        ClearStart = this->Num_Lines - YOffset;
        y1 = this->Num_Lines - 1;
        ClipToCurrentRegion = this->Num_Lines;
    }

    y1 += step;
    if (y2 != y1) {
        do {
            this->Line_Head_Ptrs[y2 + YOffset] = this->Line_Head_Ptrs[y2];
            this->Line_Tail_Ptrs[y2 + YOffset] = this->Line_Tail_Ptrs[y2];
            this->Span_Count[y2 + YOffset] = this->Span_Count[y2];
            this->LeftMostPx[y2 + YOffset] = this->LeftMostPx[y2];
            this->RightMostPx[y2 + YOffset] = this->RightMostPx[y2];
            y2 += step;
        } while (y2 != y1);
    }

    if (ClearStart <= ClipToCurrentRegion) {
        for (; ClearStart <= ClipToCurrentRegion; ClearStart++) {
            this->Line_Head_Ptrs[ClearStart] = 0;
            this->Line_Tail_Ptrs[ClearStart] = 0;
            this->Span_Count[ClearStart] = 0;
            this->LeftMostPx[ClearStart] = 0;
            this->RightMostPx[ClearStart] = 0;
        }
    }
}

int TSpan_List_Manager::ValidateSpan(int Line) {
    int C = 0;
    int prevEnd = 0;

    if (Line >= 0 && Line < this->Num_Lines) {
        VSpan_Node* node = this->Line_Head_Ptrs[Line];
        if (node == 0) {
            if (this->Line_Tail_Ptrs[Line] == 0 && this->Span_Count[Line] == 0 && this->LeftMostPx[Line] == 0) {
                return this->RightMostPx[Line] == 0;
            }
        } else {
            VSpan_Node* prev = 0;
            while (node != 0) {
                C++;
                if (C == 1 && node->StartPx != this->LeftMostPx[Line]) return 0;
                if (node->Prev != prev) return 0;
                if (node->StartPx > node->EndPx) return 0;
                if (C > 1 && node->StartPx <= prevEnd) return 0;
                prevEnd = node->EndPx;
                prev = node;
                node = node->Next;
            }
            if (this->Span_Count[Line] != C) return 0;
            if (this->Line_Tail_Ptrs[Line] != prev) return 0;
            if (prev->EndPx != this->RightMostPx[Line]) return 0;
            return this->LeftMostPx[Line] <= this->RightMostPx[Line];
        }
    }
    return 0;
}

int TSpan_List_Manager::DecodeLine(unsigned char* LineBuf, int Line, unsigned char fillC, int MaxX) {
    int count = 0;
    VSpan_Node* node = this->Line_Head_Ptrs[Line];

    while (node != 0) {
        int x = node->StartPx;
        int end = node->EndPx;
        if (x <= end) {
            do {
                LineBuf[x] = LineBuf[x] + fillC;
                ++x;
            } while (x <= end);
        }
        node = node->Next;
        ++count;
    }

    return count;
}

void TSpan_List_Manager::take_snapshot(char* filespec, int& index_no,
                                        TDrawArea* render_area, int scolor,
                                        TSpan_List_Manager** SpanArray,
                                        int* colorArray, int ArraySize) {
    int infile;
    int bmWide;
    BITMAPFILEHEADER bmFH;
    BITMAPINFOHEADER bmIH;
    char BMPFile[0x3C];
    RGBQUAD bmPAL[256];
    PALETTEENTRY thePal[256];

    if (ArraySize > 0) {
        int i = 0;
        if (i < ArraySize) {
            TSpan_List_Manager** s = SpanArray;
            while (i < ArraySize) {
                if (*s == 0) return;
                i++;
                s++;
            }
        }
    }

    int Width;
    int Height;
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
    render_area->GetPalette(thePal);
    for (int p = 0; p < 0x100; ++p) {
        bmPAL[p].rgbBlue = thePal[p].peBlue;
        bmPAL[p].rgbGreen = thePal[p].peGreen;
        bmPAL[p].rgbRed = thePal[p].peRed;
        bmPAL[p].rgbReserved = 0;
    }

    int tries = 0;
    if (index_no < 0) index_no = 0;
    while (1) {
        if (filespec == 0) sprintf(BMPFile, "C:\\AOE_%03d.BMP", index_no);
        else sprintf(BMPFile, filespec, index_no);
        tries++;
        int fd = open(BMPFile, 0);
        if (fd == -1) break;
        index_no++;
        close(fd);
        if (tries > 1000) return;
    }

    unsigned char* line = (unsigned char*)malloc(bmWide);
    infile = open(BMPFile, _O_BINARY | _O_WRONLY | _O_CREAT | _O_TRUNC, _S_IREAD | _S_IWRITE);
    if (infile != -1) {
        write(infile, &bmFH, 14);
        write(infile, &bmIH, sizeof(bmIH));
        write(infile, bmPAL, 1024);
        int y = Width - 1;
        if (y >= 0) {
            do {
                memset(line, 0, bmWide);
                this->DecodeLine(line, y, (unsigned char)scolor, Height);
                if (ArraySize > 0) {
                    int i;
                    for (i = 0; i < ArraySize; ++i) {
                        SpanArray[i]->DecodeLine(line, y, (unsigned char)colorArray[i], Height);
                    }
                }
                write(infile, line, bmWide);
                y--;
            } while (y >= 0);
        }
        close(infile);
    }
    free(line);
    return;
}
