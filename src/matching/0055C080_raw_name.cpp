class __type_info_node {
public:
    char gap_0[8];
    char raw_name_data;
    char *raw_name();
};

char *__type_info_node::raw_name() {
    return &this->raw_name_data;
}
