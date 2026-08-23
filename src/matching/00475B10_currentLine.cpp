#include "../../include/pnl_edit_context.h"

char* TEditPanel::currentLine() {
    this->update_text();
    return this->text;
}
