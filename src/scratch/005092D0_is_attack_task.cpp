struct SomeStruct { char pad[0x06]; short field_06; };
class SomeClass {
public:
    int is_attack_task(SomeStruct* task);
};
int SomeClass::is_attack_task(SomeStruct* task) {
    return task->field_06 == 7;
}
