struct FacetObj {
    char gap_0[0x60];
    short nFacets;
};

class RGE_Master_Static_Object {
public:
    char gap_0[0x10];
    FacetObj *facetPtr;
    int numberFacets();
};

int RGE_Master_Static_Object::numberFacets() {
    if (this->facetPtr)
        return (int)this->facetPtr->nFacets;
    return 0;
}
