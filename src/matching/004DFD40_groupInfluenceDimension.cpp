class SomeClass {
public:
    int groupInfluenceDimension(int dim);
};
int SomeClass::groupInfluenceDimension(int dim) {
    if (dim <= 1) return 2;
    return dim * dim;
}
