#ifdef SCR_NAME_TU_CONTEXT
#include "../../include/scr_name_context.h"
#else
class TRIBE_Screen_Name {
public:
    char gap_00[0x478];
    void* title;
    void* name_text;
    void* name_list;
    void* name_scrollbar;
    void* new_button;
    void* remove_button;
    void* ok_button;
    void* cancel_button;
    void* close_button;

    void init_vars(void);
};
#endif

void TRIBE_Screen_Name::init_vars(void) {
    this->title = 0;
    this->name_text = 0;
    this->name_list = 0;
    this->name_scrollbar = 0;
    this->new_button = 0;
    this->remove_button = 0;
    this->ok_button = 0;
    this->cancel_button = 0;
    this->close_button = 0;
}
