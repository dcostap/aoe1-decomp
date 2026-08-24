#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
    long lengthValue;
    long numWordsValue;
    long indexValue;
    long currentWordValue;

    void change(char from, char to);
};
#endif

void DString::change(char from, char to) {
    long i;

    i = 0;
    if (this->lengthValue > 0) {
        do {
            if (this->stringValue[i] == from) {
                this->stringValue[i] = to;
            }
            i = i + 1;
        } while (i < this->lengthValue);
    }
}
