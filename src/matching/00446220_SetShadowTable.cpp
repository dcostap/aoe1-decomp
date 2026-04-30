// VA: 00446220 TDrawArea::SetShadowTable (13 B)
// PDB source: Drawarea.cpp
// Stores the shadow color table pointer

struct RGE_Color_Table;

class TDrawArea {
public:
    char gap_00[0xC8];
    RGE_Color_Table* ShadowTable;  // +0xC8
    void SetShadowTable(RGE_Color_Table* table);
};

void TDrawArea::SetShadowTable(RGE_Color_Table* table)
{
    this->ShadowTable = table;
}
