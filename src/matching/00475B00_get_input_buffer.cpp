#include "../../include/pnl_edit_context.h"

char* TEditPanel::get_input_buffer() {
    this->update_text();
    return this->text;
}
