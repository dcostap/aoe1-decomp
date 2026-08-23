#include "../../include/pnl_edit_context.h"

// BINARY NOTE: The first direct call is TEditPanel::update_text.

char* TEditPanel::get_text() {
    this->update_text();
    return this->text;
}
