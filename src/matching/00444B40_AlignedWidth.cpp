// VA: 00444B40 TDrawArea::AlignedWidth (4 B)
// PDB source: Drawarea.cpp
// Returns the aligned surface pitch

#ifndef DRAWAREA_CANONICAL_TU
class TDrawArea {
public:
    char gap_00[0x20];
    int Pitch;  // +0x20
};
#endif

long TDrawArea::AlignedWidth()
{
    return this->Pitch;
}
