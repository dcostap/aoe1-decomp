class _GUID {
public:
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char c[8];
};

class TCommunications_Sessions {
public:
    int IsEqualGuid(_GUID* guid1, _GUID* guid2);
};

int TCommunications_Sessions::IsEqualGuid(_GUID* guid1, _GUID* guid2) {
    if (guid1->x == guid2->x) {
        if (*(unsigned long*)&guid1->s1 == *(unsigned long*)&guid2->s1) {
            if (*(unsigned long*)&guid1->c[0] == *(unsigned long*)&guid2->c[0]) {
                if (*(unsigned long*)&guid1->c[4] == *(unsigned long*)&guid2->c[4]) {
                    return 1;
                }
            }
        }
    }

    return 0;
}
