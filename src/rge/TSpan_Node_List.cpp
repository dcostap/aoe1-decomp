#include "TSpan_Node_List.h"
#include "TSpan_List_Manager.h" // For VSpan_Node definition
#include <stdlib.h>
#include <string.h>

TSpan_Node_List::TSpan_Node_List(int initial_size, int grow_size, int element_size) {
    this->Free_Pool_Zone = -1;
    this->Free_Pool_Index = -1;
    this->Zone_Ptrs = nullptr;
    this->Zone_Size_Ptrs = nullptr;
    this->Used_Zones = 0;
    this->Free_Head = nullptr;
    this->Total_Blocks = 0;
    this->Free_Blocks = 0;
    this->Element_Size = element_size;
    this->Max_Zones = 8;
    this->Default_Grow_Size = grow_size;
    
    this->ResetStats();
    this->SetNumZones(8);
    this->InitNewZone(initial_size);
}

TSpan_Node_List::~TSpan_Node_List() {
    if (this->Used_Zones > 0) {
        for (int i = 0; i < this->Used_Zones; i++) {
            if (this->Zone_Ptrs[i]) {
                free(this->Zone_Ptrs[i]);
            }
        }
    }
    if (this->Zone_Ptrs) free(this->Zone_Ptrs);
    if (this->Zone_Size_Ptrs) free(this->Zone_Size_Ptrs);
}

void TSpan_Node_List::SetNumZones(int count) {
    if (this->Max_Zones > count) return; // Logic says <=, effectively growing or initializing

    VSpan_Node **new_ptrs = (VSpan_Node **)calloc(count, sizeof(VSpan_Node*));
    int *new_sizes = (int *)calloc(count, sizeof(int));
    
    if (this->Zone_Ptrs) {
        if (this->Used_Zones > 0) {
            for (int i = 0; i < this->Used_Zones; i++) {
                new_ptrs[i] = this->Zone_Ptrs[i];
                new_sizes[i] = this->Zone_Size_Ptrs[i];
            }
        }
        free(this->Zone_Ptrs);
        free(this->Zone_Size_Ptrs);
    }
    
    this->Zone_Ptrs = new_ptrs;
    this->Zone_Size_Ptrs = new_sizes;
    this->Max_Zones = count;
}

void TSpan_Node_List::InitNewZone(int size) {
    if (this->Used_Zones == this->Max_Zones) {
        this->SetNumZones(this->Used_Zones + 4);
    }
    
    int zone_idx = this->Used_Zones;
    this->Used_Zones++;
    
    this->Zone_Size_Ptrs[zone_idx] = size;
    // Note: Decomp uses malloc(Element_Size * size). Since we treat it as VSpan_Node*, manual pointer arithmetic is needed if Element_Size != sizeof(VSpan_Node).
    // However, the class uses Element_Size member.
    // In GetNode, it does `return pVVar1 + iVar2;` which implies VSpan_Node stride.
    // So Element_Size *must* be sizeof(VSpan_Node) for the pointer arithmetic in GetNode to match C++ type safety,
    // OR we cast to char* for arithmetic. Given TSpan_List_Manager initializes it with sizeof(VSpan_Node) (implied 16 bytes), it aligns.
    
    this->Zone_Ptrs[zone_idx] = (VSpan_Node *)malloc(this->Element_Size * size);
    
    this->NewZone_Count++;
    this->Total_Blocks += size;
    this->Free_Blocks += size;
    
    if (this->Free_Pool_Zone == -1) {
        this->Free_Pool_Zone = zone_idx;
        this->Free_Pool_Index = 0;
    }
}

VSpan_Node* TSpan_Node_List::GetNode() {
    if (this->Free_Blocks == 0) {
        this->InitNewZone(this->Default_Grow_Size);
    }
    
    // Try explicit free list first
    VSpan_Node *node = this->Free_Head;
    if (node) {
        this->Free_Head = node->Next;
        this->Free_Blocks--;
        return node;
    }
    
    // Allocate from linear pool
    int idx = this->Free_Pool_Index;
    int zone = this->Free_Pool_Zone;
    
    node = this->Zone_Ptrs[zone];
    
    this->Free_Blocks--;
    this->Free_Pool_Index++;
    
    if (this->Free_Pool_Index == this->Zone_Size_Ptrs[zone]) {
        this->Free_Pool_Zone++;
        this->Free_Pool_Index = 0;
        
        if (this->Free_Pool_Zone == this->Used_Zones) {
            this->Free_Pool_Zone = -1; // Should trigger allocation next time if not handled
        }
    }
    
    // Assuming Element_Size matches sizeof(VSpan_Node) due to typed pointer arithmetic
    return &node[idx];
}

void TSpan_Node_List::FreeNode(VSpan_Node *node) {
    node->Next = this->Free_Head;
    node->Prev = nullptr;
    this->Free_Head = node;
    this->Free_Blocks++;
}

int TSpan_Node_List::FreeThread(VSpan_Node *head, VSpan_Node *tail) {
    int count = 0;
    if (!head) return 0;
    
    VSpan_Node *curr = head;
    
    if (!tail) {
        // Free until end of list
        VSpan_Node *prev;
        do {
            prev = curr;
            count++;
            this->Free_Blocks++;
            curr = prev->Next;
        } while (curr);
        
        prev->Next = this->Free_Head;
        this->Free_Head = head;
        return count;
    }
    
    // Free until tail is hit (inclusive)
    do {
        count++;
        this->Free_Blocks++;
        if (curr == tail) {
            curr = nullptr;
        } else {
            curr = curr->Next;
        }
    } while (curr);
    
    tail->Next = this->Free_Head;
    this->Free_Head = head;
    return count;
}

void TSpan_Node_List::ReclaimAllNodes() {
    this->Free_Head = nullptr;
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