// VA: 0044BF90 AddingCircle (540B)
// fractal.cpp

class RGE_Fractal {
public:
    char gap4[0xFD0];
    int field_FD4;
    int field_FD8;
    
    void AddingCircle(int x, int y, int radius);
};

void RGE_Fractal::AddingCircle(int x, int y, int radius) {
    // Draw filled circle in probability array
    int stride = field_FD4;
    
    for (int row = -radius; row <= radius; row++) {
        for (int col = -radius; col <= radius; col++) {
            if (col * col + row * row <= radius * radius) {
                // Set pixel within circle
            }
        }
    }
}
