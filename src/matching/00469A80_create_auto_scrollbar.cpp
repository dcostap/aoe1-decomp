// first pass: direct virtual create call, then wire the resulting scrollbar into the text panel
// the target function must stay lexically first so the extractor sees its bytes first
// tried a raw vtable function-pointer cast; the remaining mismatch was the ECX/thiscall setup on the factory call

int TEasy_Panel::create_auto_scrollbar(TScrollBarPanel** scrollbar_out, TTextPanel* text, long param_3) {
    if (this->create_auto_scrollbar_impl(text->field_40, scrollbar_out, text, 0, 0, 0, param_3, 0) == 0) {
        return 0;
    }

    text->set_scrollbar(*scrollbar_out, 1);
    return 1;
}
