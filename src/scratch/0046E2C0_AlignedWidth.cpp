class TShape {
public:
    char gap_0[0x14];
    int width;
    int AlignedWidth();
};

int TShape::AlignedWidth() {
    return (this->width + 3) & ~3;
}
