int debug_rand(char* file, int line);

class RGE_RMM_Cliffs_Generator {
public:
    char gap_00[0x30];
    int number_of_cliffs;

    void setup_cliff_maps(void);
    void generate_cliff(void);
    unsigned char generate(void);
};

unsigned char RGE_RMM_Cliffs_Generator::generate(void) {
    int i;

    this->setup_cliff_maps();
    debug_rand("C:\\msdev\\work\\age1_x1\\rmm_clif.cpp", 0x32);
    i = 0;
    if (this->number_of_cliffs > 0) {
        do {
            this->generate_cliff();
            i++;
        } while (i < this->number_of_cliffs);
    }
    return 1;
}
