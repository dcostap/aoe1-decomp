class TDrawArea {
public:
    ~TDrawArea();
};

class RGE_Diamond_Map {
public:
    char gap_00[0x164];
    int own_save_area;
    TDrawArea* save_area;

    void delete_surfaces();
};

void RGE_Diamond_Map::delete_surfaces() {
    if (this->save_area != 0 && this->own_save_area != 0) {
        delete this->save_area;
        this->save_area = 0;
        this->own_save_area = 0;
    }
}
