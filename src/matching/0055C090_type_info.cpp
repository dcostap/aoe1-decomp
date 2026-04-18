extern int type_info_vtable;
class type_info {
public:
    type_info(const type_info& other);
    int* vtable_ptr;
};
type_info::type_info(const type_info& other) {
    this->vtable_ptr = &type_info_vtable;
}
