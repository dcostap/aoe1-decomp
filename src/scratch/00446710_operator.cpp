class ostream {
public:
    ostream& operator<<(const char* value);
};

#ifndef DSTRING_TU_CONTEXT
class DString {
public:
    char* stringValue;
};
#endif

ostream& __cdecl operator<<(ostream& stream, const DString& value) {
    if (value.stringValue != 0) {
        stream << value.stringValue;
    }
    return stream;
}
