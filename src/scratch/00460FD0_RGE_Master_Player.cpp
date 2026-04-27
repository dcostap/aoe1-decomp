// VA: 00460FD0 RGE_Master_Player::RGE_Master_Player (FILE* ctor, fscanf-based, 200 B)
// PDB source: mst_play.cpp
// Attempt log:
// - fscanf-based constructor, won't match due to fscanf scheduling
// - Left in scratch after shallow pass

#include <stdio.h>

struct RGE_Master_Player_ctor1 {
    void* vtable;
    void ctor(FILE* f);
};

void RGE_Master_Player_ctor1::ctor(FILE* f)
{
    vtable = (void*)0x570C08;
}
