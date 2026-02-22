#include "../include/DClipInfo_List.h"
#include "../include/DClipInfo_Node.h"
#include "../include/Shape_Info.h"

#include <cstdlib>

DClipInfo_List::DClipInfo_List(int initial_blocks, int grow_size, int element_size, int y_min, int y_max, int max_draw_levels) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053AD90.
    this->Free_Pool_Zone = -1;
    this->Free_Pool_Index = -1;
    this->Element_Size = element_size;
    this->Default_Grow_Size = grow_size;
    this->YLine_Size = (y_max - y_min) + 1;
    this->Zone_Ptrs = nullptr;
    this->Zone_Size_Ptrs = nullptr;
    this->Max_Zones = 8;
    this->Used_Zones = 0;
    this->Free_Head = nullptr;
    this->Total_Blocks = 0;
    this->Free_Blocks = 0;
    this->YLine_Offset = -y_min;
    this->Max_Draw_Levels = max_draw_levels;
    this->SetCaptureLevel(0, max_draw_levels);

    this->Draw_Clip_Nodes = (DClipInfo_Node**)std::calloc((size_t)this->YLine_Size, 4);
    this->Draw_Level_Head = (DClipInfo_Node**)std::calloc((size_t)(this->Max_Draw_Levels + 1), 4);
    this->Draw_Level_Tail = (DClipInfo_Node**)std::calloc((size_t)(this->Max_Draw_Levels + 1), 4);

    this->ResetStats();
    this->SetNumZones(8);
    this->InitNewZone(initial_blocks);

    this->Select_Box = nullptr;
}

DClipInfo_List::~DClipInfo_List() {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053AE50.
    if (this->Used_Zones > 0) {
        for (int i = 0; i < this->Used_Zones; ++i) {
            if (this->Zone_Ptrs && this->Zone_Ptrs[i]) {
                std::free(this->Zone_Ptrs[i]);
            }
        }
    }

    if (this->Zone_Ptrs) {
        std::free(this->Zone_Ptrs);
    }
    if (this->Zone_Size_Ptrs) {
        std::free(this->Zone_Size_Ptrs);
    }
    if (this->Draw_Clip_Nodes) {
        std::free(this->Draw_Clip_Nodes);
    }
    if (this->Draw_Level_Head) {
        std::free(this->Draw_Level_Head);
    }
    if (this->Draw_Level_Tail) {
        std::free(this->Draw_Level_Tail);
    }
}

void DClipInfo_List::SetCaptureLevel(int min_level, int max_level) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053AED0.
    int iVar1 = max_level;
    if (max_level < min_level) {
        iVar1 = min_level;
        min_level = max_level;
    }
    if (min_level < 0) {
        min_level = 0;
    }
    if (this->Max_Draw_Levels < iVar1) {
        iVar1 = this->Max_Draw_Levels;
    }
    this->Accept_Min_Level = min_level;
    this->Accept_Max_Level = iVar1;
}

void DClipInfo_List::SetNumZones(int num_zones) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053AF00.
    if (this->Max_Zones <= num_zones) {
        DClipInfo_Node** new_zone_ptrs = (DClipInfo_Node**)std::calloc((size_t)num_zones, 4);
        int* new_zone_sizes = (int*)std::calloc((size_t)num_zones, 4);
        if (this->Zone_Ptrs != nullptr) {
            if (this->Used_Zones > 0) {
                for (int i = 0; i < this->Used_Zones; ++i) {
                    new_zone_ptrs[i] = this->Zone_Ptrs[i];
                    new_zone_sizes[i] = this->Zone_Size_Ptrs[i];
                }
            }
            std::free(this->Zone_Ptrs);
            std::free(this->Zone_Size_Ptrs);
        }
        this->Zone_Ptrs = new_zone_ptrs;
        this->Zone_Size_Ptrs = new_zone_sizes;
        this->Max_Zones = num_zones;
    }
}

void DClipInfo_List::InitNewZone(int blocks) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053AF90.
    if (this->Used_Zones == this->Max_Zones) {
        this->SetNumZones(this->Used_Zones + 4);
    }

    int zone = this->Used_Zones;
    this->Used_Zones = zone + 1;

    this->Zone_Size_Ptrs[zone] = blocks;
    DClipInfo_Node* mem = (DClipInfo_Node*)std::malloc((size_t)this->Element_Size * (size_t)blocks);
    this->Zone_Ptrs[zone] = mem;

    this->NewZone_Count = this->NewZone_Count + 1;
    this->Total_Blocks = this->Total_Blocks + blocks;
    this->Free_Blocks = this->Free_Blocks + blocks;

    if (this->Free_Pool_Zone == -1) {
        this->Free_Pool_Zone = zone;
        this->Free_Pool_Index = 0;
    }
}

DClipInfo_Node* DClipInfo_List::GetNode() {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053B000.
    if (this->Free_Blocks == 0) {
        this->InitNewZone(this->Default_Grow_Size);
    }

    DClipInfo_Node* free_node = this->Free_Head;
    if (free_node != nullptr) {
        this->Free_Head = free_node->Next;
        this->Free_Blocks = this->Free_Blocks - 1;
        return free_node;
    }

    int idx = this->Free_Pool_Index;
    int zone = this->Free_Pool_Zone;
    DClipInfo_Node* base = this->Zone_Ptrs[zone];

    int next_idx = idx + 1;
    this->Free_Blocks = this->Free_Blocks - 1;
    this->Free_Pool_Index = next_idx;

    if (next_idx == this->Zone_Size_Ptrs[zone]) {
        this->Free_Pool_Zone = zone + 1;
        this->Free_Pool_Index = 0;
        if (zone + 1 == this->Used_Zones) {
            this->Free_Pool_Zone = -1;
        }
    }

    return base + idx;
}

void DClipInfo_List::SetDrawRegion(int xmin, int ymin, int xmax, int ymax) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053B070.
    if (xmin <= xmax) {
        if (ymin <= ymax) {
            this->SD_XMin = xmin;
            this->SD_XMax = xmax;
            this->SD_YMin = ymin;
            this->SD_YMax = ymax;
        }
    }
}

void DClipInfo_List::AddDrawNode(void* shape_base, Shape_Info* shape, int draw_line, int draw_x, int draw_y, int draw_flag, uchar* color_table, int xform_mask, int draw_level, int object_id) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053B0A0.
    int line = this->YLine_Offset + draw_line;
    if ((draw_level <= this->Accept_Max_Level) && (this->Accept_Min_Level <= draw_level)) {
        short sx = (short)draw_x;
        short hx = (short)shape->Hotspot_X + sx;
        short sy = (short)draw_y;
        short hy = (short)shape->Hotspot_Y + sy;

        if (((draw_x <= this->SD_XMax) &&
                ((this->SD_XMin <= draw_x + -1 + shape->Width && (draw_y <= this->SD_YMax)) &&
                    (this->SD_YMin <= draw_y + -1 + shape->Height))) &&
            ((-1 < line) && (line < this->YLine_Size))) {
            DClipInfo_Node* node = this->GetNode();
            DClipInfo_Node* cur = this->Draw_Clip_Nodes[line];
            if (cur == nullptr) {
                this->Draw_Clip_Nodes[line] = node;
            } else {
                for (DClipInfo_Node* next = cur->Next; next != nullptr; next = next->Next) {
                    cur = next;
                }
                cur->Next = node;
            }

            node->Object_ID = object_id;
            node->Draw_Flag = draw_flag;
            node->Shape_Base = (uchar*)shape_base;
            node->Color_Table = color_table;
            node->Xform_Mask = xform_mask;
            node->Next = nullptr;
            node->NextOnLevel = nullptr;
            node->Shape = shape;
            node->Draw_X = draw_x;
            node->Draw_Y = draw_y;
            node->Draw_Level = draw_level;
            node->Node_Type = 0;

            if (this->Select_Box == nullptr) {
                node->x1 = sx;
                node->y1 = sy;
                node->x2 = (short)(sx + (short)shape->Width + -1);
                node->y2 = (short)(sy + (short)shape->Height + -1);
            } else {
                node->x1 = (short)(hx + this->Select_Box[0]);
                node->y1 = (short)(this->Select_Box[1] + hy);
                node->x2 = (short)(this->Select_Box[2] + hx);
                node->y2 = (short)(this->Select_Box[3] + hy);
                this->Select_Box = nullptr;
            }

            node->x3 = hx;
            node->y3 = hy;
            node->x4 = 0;
            node->y4 = 0;
        }
    }
}

DClipInfo_Node* DClipInfo_List::AddGDINode(int node_type, int draw_line, int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4, int draw_level, int draw_flag, int object_id) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053B220.
    int line = this->YLine_Offset + draw_line;
    if ((((draw_level <= this->Accept_Max_Level) && (this->Accept_Min_Level <= draw_level)) && (-1 < line)) &&
        (line < this->YLine_Size)) {
        DClipInfo_Node* node = this->GetNode();
        node->Next = this->Draw_Clip_Nodes[line];
        this->Draw_Clip_Nodes[line] = node;

        node->Object_ID = object_id;
        node->Draw_Flag = draw_flag;
        node->Node_Type = node_type;
        node->x1 = (short)x1;
        node->y1 = (short)y1;
        node->x2 = (short)x2;
        node->y2 = (short)y2;
        node->x3 = (short)x3;
        node->y3 = (short)y3;
        node->NextOnLevel = nullptr;
        node->Shape = nullptr;
        node->Draw_X = 0;
        node->Draw_Y = 0;
        node->Shape_Base = nullptr;
        node->Color_Table = nullptr;
        node->Xform_Mask = 0;
        node->Draw_Level = draw_level;
        node->x4 = (short)x4;
        node->y4 = (short)y4;
        return node;
    }
    return nullptr;
}

DClipInfo_Node* DClipInfo_List::LocateIDbyDrawLevel(int object_id, int min_level, int max_level, int node_type) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053B300.
    int start = min_level;
    if (max_level < min_level) {
        start = max_level;
        max_level = min_level;
    }
    if (start < 0) {
        start = 0;
    }
    int cap = this->Max_Draw_Levels;
    if (cap < max_level) {
        max_level = cap;
    }
    if (((start <= cap) && (-1 < max_level)) && (start <= max_level)) {
        for (int lvl = start; lvl <= max_level; ++lvl) {
            for (DClipInfo_Node* node = this->Draw_Level_Head[lvl]; node != nullptr; node = node->NextOnLevel) {
                if ((node->Object_ID == object_id) && (node->Node_Type == node_type)) {
                    return node;
                }
            }
        }
    }
    return nullptr;
}

void DClipInfo_List::Scroll(int scroll_x, int scroll_y) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053B370.
    if (scroll_y > 0) {
        if (this->YLine_Size != scroll_y && -1 < this->YLine_Size - scroll_y) {
            for (int i = 0; i < this->YLine_Size - scroll_y; ++i) {
                this->Draw_Clip_Nodes[i] = this->Draw_Clip_Nodes[i + scroll_y];
            }
        }
        for (int i = this->YLine_Size - scroll_y; i < this->YLine_Size; ++i) {
            if (i >= 0) {
                this->Draw_Clip_Nodes[i] = nullptr;
            }
        }
    }

    if (scroll_y < 0) {
        int abs_y = -scroll_y;
        int i = this->YLine_Size - 1;
        if (i + scroll_y >= 0) {
            for (; abs_y <= i; --i) {
                this->Draw_Clip_Nodes[i] = this->Draw_Clip_Nodes[i + scroll_y];
            }
        }
        if (abs_y != 0 && scroll_y < 1) {
            for (int j = 0; j < abs_y; ++j) {
                this->Draw_Clip_Nodes[j] = nullptr;
            }
        }
    }

    if (this->YLine_Size > 0) {
        for (int i = 0; i < this->YLine_Size; ++i) {
            for (DClipInfo_Node* node = this->Draw_Clip_Nodes[i]; node != nullptr; node = node->Next) {
                short sy = (short)scroll_y;
                short sx = (short)scroll_x;
                switch (node->Node_Type) {
                case 0:
                    node->Draw_X = node->Draw_X - scroll_x;
                    node->Draw_Y = node->Draw_Y - scroll_y;
                    break;
                case 1:
                    node->y3 = (short)(node->y3 - sy);
                    node->y4 = (short)(node->y4 - sy);
                case 2:
                    node->x3 = (short)(node->x3 - sx);
                    node->x4 = (short)(node->x4 - sx);
                case 3:
                case 4:
                    node->x1 = (short)(node->x1 - sx);
                    node->y1 = (short)(node->y1 - sy);
                    node->x2 = (short)(node->x2 - sx);
                    node->y2 = (short)(node->y2 - sy);
                    break;
                }
            }
        }
    }
}

void DClipInfo_List::FreeNode(DClipInfo_Node* node) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053B490.
    node->Next = this->Free_Head;
    this->Free_Head = node;
    this->Free_Blocks = this->Free_Blocks + 1;
}

int DClipInfo_List::FreeThread(DClipInfo_Node* head, DClipInfo_Node* tail) {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053B4B0.
    int count = 0;
    if (head == nullptr) {
        return count;
    }

    DClipInfo_Node* cur = head;
    if (tail == nullptr) {
        while (cur != nullptr) {
            DClipInfo_Node* last = cur;
            count = count + 1;
            this->Free_Blocks = this->Free_Blocks + 1;
            cur = last->Next;
            if (cur == nullptr) {
                last->Next = this->Free_Head;
                this->Free_Head = head;
                return count;
            }
        }
        return count;
    }

    while (cur != nullptr) {
        count = count + 1;
        this->Free_Blocks = this->Free_Blocks + 1;
        if (cur == tail) {
            cur = nullptr;
        } else {
            cur = cur->Next;
        }
    }

    tail->Next = this->Free_Head;
    this->Free_Head = head;
    return count;
}

void DClipInfo_List::ReclaimAllNodes() {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053B510.
    if (this->Draw_Clip_Nodes) {
        for (int i = 0; i < this->YLine_Size; ++i) {
            this->Draw_Clip_Nodes[i] = nullptr;
        }
    }
    if (this->Draw_Level_Head) {
        for (int i = 0; i <= this->Max_Draw_Levels; ++i) {
            this->Draw_Level_Head[i] = nullptr;
        }
    }
    if (this->Draw_Level_Tail) {
        for (int i = 0; i <= this->Max_Draw_Levels; ++i) {
            this->Draw_Level_Tail[i] = nullptr;
        }
    }

    this->Free_Head = nullptr;
    this->Free_Pool_Zone = 0;
    this->Free_Pool_Index = 0;
    this->Free_Blocks = this->Total_Blocks;
    this->Reset_Count = this->Reset_Count + 1;
}

void DClipInfo_List::ResetStats() {
    // Fully verified. Source of truth: view.cpp.decomp @ 0x0053B590.
    this->Alloc_Count = 0;
    this->Dealloc_Count = 0;
    this->NewZone_Count = 0;
    this->Reset_Count = 0;
}

