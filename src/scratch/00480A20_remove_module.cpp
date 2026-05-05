// VA: 00480A20 RGE_Random_Map_Module::remove_module(RGE_Random_Map_Module*)
// PDB source: rmm_base.cpp lines 174-206 (90 bytes, 41 asm lines)
// Default flags
//
// __thiscall: this in ecx, 1 stack param (RGE_Random_Map_Module*). ret 4 cleanup.
// Returns unsigned char (al). Removes first matching node from singly-linked list at this+8.
// 77/90 edit-match bytes. 13-byte edit diff. Left in scratch.
//
// Remaining differences:
// 1. Walk entry: Original loads curr into ecx then adds to eax (mov ecx,[eax+4]; add eax,4).
//    VC5 computes pprev via lea then loads curr into eax (lea ecx,[eax+4]; mov eax,[eax+4]).
//    This swaps eax↔ecx register roles for the entire loop body.
// 2. Register allocation: All loop instructions are identical except eax↔ecx swapped.
//    This is a stable VC5 register coloring difference.
//
// Node layout:
//   [node+0] = module_ptr
//   [node+4] = next_ptr
// Class layout:
//   [this+0x08] = list (head pointer)

#include <stdlib.h>

class RGE_Random_Map_Module;

struct Node {
    RGE_Random_Map_Module* module;
    Node* next;
};

class RGE_Random_Map_Module {
public:
    char pad_00[8];
    Node* list;

    unsigned char remove_module(RGE_Random_Map_Module* param_1);
};

unsigned char RGE_Random_Map_Module::remove_module(RGE_Random_Map_Module* param_1) {
    Node* head = this->list;
    Node* found = 0;

    if (head != 0) {
        if (head->module == param_1) {
            found = head;
            this->list = head->next;
        } else {
            Node* curr;
            Node** pprev = &head->next;
            curr = *pprev;
            if (curr != 0) {
                do {
                    if (curr->module == param_1) {
                        found = curr;
                        *pprev = curr->next;
                    }
                    pprev = &(*pprev)->next;
                    curr = *pprev;
                } while (curr != 0);
            }
        }
    }

    if (found != 0) {
        free(found);
        return 1;
    }
    return 0;
}
