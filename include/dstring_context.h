#ifndef AOE1_DSTRING_CONTEXT_H
#define AOE1_DSTRING_CONTEXT_H

// Authentic source-module surface for C:\\msdev\\work\\age1_x1\\dstring.cpp.
// The executable stores stringValue at offset 0 and four int state fields after it.
class DString {
public:
    char* stringValue;
    int lengthValue;
    int numWordsValue;
    int indexValue;
    int currentWordValue;

    DString();
    DString(const DString& other);
    DString(const char* value);
    ~DString();
    DString& operator=(const char* value);
    DString& operator=(const DString& other);

    char& operator[](int index);
    operator char*() const;
    DString operator+(const DString& value) const;
    int length() const;
    int numWords();
    int index() const;
    int contains(DString value) const;
    int contains(const char* value) const;
    DString word(int wordIndex);
    DString nextWord(int updateIndex);
    void moveToFirstWord();
    void moveToNextWord();
    DString subString(int start, int count);
    void append(DString value);
    DString stripTrailing(char value);
    DString stripLeading(char value);
    int asInt() const;
    double asDouble() const;
    void uppercase();
    DString asUppercase();
    void lowercase();
    DString asLowercase();
    void change(char from, char to);
};

int __cdecl operator==(const DString& lhs, const DString& rhs);
int __cdecl operator==(const DString& lhs, const char* rhs);
int __cdecl operator==(const char* lhs, const DString& rhs);
int __cdecl operator!=(const DString& lhs, const DString& rhs);
int __cdecl operator!=(const DString& lhs, const char* rhs);
int __cdecl operator!=(const char* lhs, const DString& rhs);
int __cdecl operator<(const DString& lhs, const DString& rhs);
int __cdecl operator<(const DString& lhs, const char* rhs);
int __cdecl operator<(const char* lhs, const DString& rhs);
int __cdecl operator>(const DString& lhs, const DString& rhs);
int __cdecl operator>(const DString& lhs, const char* rhs);
int __cdecl operator>(const char* lhs, const DString& rhs);

class DKeyString {
public:
    DString keyValue;
    DString valueValue;

    DKeyString();
    DKeyString(DString key, DString value);
    ~DKeyString();
    DString key() const;
    void setKey(DString key);
    DString value() const;
    void setValue(DString value);
};

#endif
