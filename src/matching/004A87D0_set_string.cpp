class TRIBE_Screen_Sed {
public:
    void get_string(long panel_id, char* buffer, int limit);
    void set_string(char* buffer, long panel_id, int limit);
};

void TRIBE_Screen_Sed::set_string(char* buffer, long panel_id, int limit) {
    this->get_string(panel_id, buffer, limit);
}
