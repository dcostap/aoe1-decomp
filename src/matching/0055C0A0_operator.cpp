class type_info {
public:
    type_info& operator=(const type_info& rhs);
};

type_info& type_info::operator=(const type_info& rhs) {
    return *this;
}
