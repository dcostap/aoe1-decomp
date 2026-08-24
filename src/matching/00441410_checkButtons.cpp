#ifdef DLG_SMSG_CANONICAL_TU
#include "../../include/dlg_smsg_context.h"
#else
class TButtonPanel {
public:
    int get_state(void);
};

class TChat {
public:
    void setInChatGroup(int player, int inGroup);
};

extern TChat* chat;

class TribeSendMessageDialog {
public:
    char gap_00[0x52C];
    int commPlayers[8];

    void checkButtons(void);
};
#endif

void TribeSendMessageDialog::checkButtons(void) {
    int* commPlayer = this->commPlayers;
    int i = 8;

    do {
        if ((*commPlayer != 0) && ((TButtonPanel*)commPlayer[-22] != 0)) {
            TButtonPanel* button = (TButtonPanel*)commPlayer[-22];
            int state = button->get_state();
            if (state == 0) {
                chat->setInChatGroup(*commPlayer, 0);
            } else {
                chat->setInChatGroup(*commPlayer, 1);
            }
        }
        ++commPlayer;
        --i;
    } while (i != 0);
}
