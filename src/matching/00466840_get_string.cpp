// Context gate: Panel.cpp lines 2480-2493, TPanel owner. The exact anchor is
// one rge_base_game call followed by a byte test of the output buffer.
// BINARY NOTE: the call uses virtual slot +0x20 and preserves the output byte.
// Blocker: the shared RGE_Base_Game context declares get_string non-virtual,
// so grouped output emits a direct call instead of the original virtual call.

#ifndef AOE1_PANEL_CONTEXT_H
class RGE_Base_Game {
public:
    virtual int get_string(int string_id, char* buffer, int length);
};

extern RGE_Base_Game* rge_base_game;

class TPanel {
public:
    int get_string(int string_id, char* buffer, int length);
};

#endif
int TPanel::get_string(int string_id, char* buffer, int length) {
    rge_base_game->get_string(string_id, buffer, length);
    return buffer[0] != 0;
}
