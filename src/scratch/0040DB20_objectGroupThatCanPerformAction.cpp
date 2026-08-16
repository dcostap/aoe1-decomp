extern int __cdecl some_func(void*, const char*, int);
extern char str_data[];
class SomeClass {
public:
    int objectGroupThatCanPerformAction(int action);
};
int SomeClass::objectGroupThatCanPerformAction(int action) {
    some_func(this, str_data, action);
    return -1;
}
