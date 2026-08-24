// target: VA 0047DFE0 TTextPanel::insert_line(long,long,long,long)
// first pass: two 256-byte locals with the buffer order/push order from the packet

#ifndef PNL_TXT_TU_CONTEXT
class TTextPanel {
public:
    int get_string(long string_id, char* buffer, long length);
    int insert_line(long line, long param_2, long param_3, long value);
    int insert_line(long line, char* str1, char* str2, long value);
};
#endif

int TTextPanel::insert_line(long param_1, long param_2, long param_3, long param_4) {
    char str1[256];
    char str2[256];

    this->get_string(param_2, str1, 0x100);
    this->get_string(param_3, str2, 0x100);
    return this->insert_line(param_1, str1, str2, param_4);
}
