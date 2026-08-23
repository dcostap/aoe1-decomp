// VA: 004C6B50 numberFacets (15B)
// stat_obj.cpp
// BINARY NOTE: PDB owner is RGE_Static_Object::numberFacets.
// BINARY NOTE: The owned body is [004C6B50, 004C6B5F); the next byte is padding.
// BINARY NOTE: Keep the narrow sprite facet-count read at sprite + 0x60.

struct FacetObj {
    char gap_0[0x60];
    short nFacets;
};

class RGE_Static_Object {
public:
    char gap_0[0x10];
    FacetObj *sprite;
    int numberFacets();
};

int RGE_Static_Object::numberFacets() {
    if (this->sprite)
        return (int)this->sprite->nFacets;
    return 0;
}
