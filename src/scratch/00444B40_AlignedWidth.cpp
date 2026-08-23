// VA: 00444B40 TDrawArea::AlignedWidth (4 B)
// PDB source: Drawarea.cpp
// Returns the aligned surface pitch

class TDrawArea {
public:
    char gap_00[0x20];
    int Pitch;  // +0x20
};

long TDrawArea::AlignedWidth()
{
    return this->Pitch;
}
