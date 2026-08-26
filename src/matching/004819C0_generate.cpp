#ifdef RMM_CLIF_SHARED_CONTEXT
#include "../../include/rmm_clif_context.h"
#else
int debug_rand(char* file, int line);

class RGE_RMM_Cliffs_Generator {
public:
    char gap_00[0x30];
    int number_of_cliffs;

    unsigned char generate(void);

protected:
    void setup_cliff_maps(void);
    void generate_cliff(void);
};
#endif

#ifdef RMM_CLIF_SHARED_CONTEXT
#define RMM_CLIF_NUMBER_OF_CLIFFS this->info.number_of_cliffs
#else
#define RMM_CLIF_NUMBER_OF_CLIFFS this->number_of_cliffs
#endif

unsigned char RGE_RMM_Cliffs_Generator::generate(void) {
    int i;

    this->setup_cliff_maps();
    debug_rand("C:\\msdev\\work\\age1_x1\\rmm_clif.cpp", 0x32);
    i = 0;
    if (RMM_CLIF_NUMBER_OF_CLIFFS > 0) {
        do {
            this->generate_cliff();
            i++;
        } while (i < RMM_CLIF_NUMBER_OF_CLIFFS);
    }
    return 1;
}

#undef RMM_CLIF_NUMBER_OF_CLIFFS
