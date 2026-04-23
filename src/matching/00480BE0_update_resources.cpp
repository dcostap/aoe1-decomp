class RGE_Random_Map_Module {
public:
    char gap_00[0x04];
    RGE_Random_Map_Module* parent;
    char gap_08[0x18];
    int search_map;
    int search_map_rows;
    int stack_array;
    int stack_offsets;

    void share_resources(int* search_map, int* search_map_rows, int* stack_array, int* stack_offsets);
    void update_child_resources(void);
    void update_resources(void);
};

void RGE_Random_Map_Module::update_resources(void) {
    this->parent->share_resources(&this->search_map, &this->search_map_rows, &this->stack_array, &this->stack_offsets);
    this->update_child_resources();
}
