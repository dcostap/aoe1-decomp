struct Map_Stack;

class RGE_Random_Map_Module {
public:
    char gap_00[0x20];
    unsigned char* search_map;
    unsigned char** search_map_rows;
    Map_Stack* stack_array;
    Map_Stack** stack_offsets;

    void share_resources(unsigned char** a, unsigned char*** b, Map_Stack** c, Map_Stack*** d);
};

void RGE_Random_Map_Module::share_resources(unsigned char** a, unsigned char*** b, Map_Stack** c, Map_Stack*** d) {
    if (a != 0) {
        *a = this->search_map;
    }
    if (b != 0) {
        *b = this->search_map_rows;
    }
    if (c != 0) {
        *c = this->stack_array;
    }
    if (d != 0) {
        *d = this->stack_offsets;
    }
}
