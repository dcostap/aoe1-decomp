#ifndef PLAYER_GROUPED_TU
#include "../player_tu_context.h"
#endif

unsigned char RGE_Player::get_checksums(long& cksum1, long& cksum2,
                                        long& cksum3) {
    if (!this->checksum_created_this_update) {
        this->create_checksum();
    }
    cksum1 = this->checksum;
    cksum2 = this->position_checksum;
    cksum3 = this->action_checksum;
    return 1;
}
