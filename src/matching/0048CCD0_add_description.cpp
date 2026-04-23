void getstring(char** dst, char* src);
void addstring(char** dst, char* old_text, char* append);

class RGE_Scenario {
public:
    char gap_00[0x1014];
    char* description;

    void add_description(char* text);
};

void RGE_Scenario::add_description(char* text) {
    if (this->description == 0) {
        getstring(&this->description, text);
        return;
    }
    addstring(&this->description, this->description, text);
}
