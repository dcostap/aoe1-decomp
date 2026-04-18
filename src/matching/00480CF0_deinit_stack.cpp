struct InnerObj { char pad[0x14]; int field_14; };
struct MapStack { char pad[0x10]; InnerObj* field_10; };
class SomeClass {
public:
    void deinit_stack(MapStack* stack);
};
void SomeClass::deinit_stack(MapStack* stack) {
    if (stack->field_10) {
        stack->field_10->field_14 = 0;
        stack->field_10 = 0;
    }
}
