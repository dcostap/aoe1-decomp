extern "C" char* __cdecl strncpy(char* dst, const char* src, unsigned int count);
extern "C" char* __cdecl strcpy(char* dst, const char* src);

class AIModuleMessage {
public:
    char pad_00[0x8];
    char text[128];

    void setText(char* text);
};

void AIModuleMessage::setText(char* text)
{
    if (text != 0) {
        strncpy(this->text, text, 0x7F);
        return;
    }

    strcpy(this->text, "");
}
