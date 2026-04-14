// STATUS: scratch
class dstring {
public:
    char* data;
    int length;

    char* operator[](int index);
};

char* dstring::operator[](int index) {
    if (index < 0 || this->length < index + 1) {
        return this->data;
    }
    return this->data + index;
}