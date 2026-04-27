// VA: 0047C640 word_wrap_append (1064B)
// Pnl_txt.cpp

class TTextPanel {
public:
    char gap4[0x230];
    int field_234;
    
    void word_wrap_append(const char* text);
};

void TTextPanel::word_wrap_append(const char* text) {
    if (!text) return;
    
    // Word-wrap the text and append to panel
    field_234 = (int)text;
}
