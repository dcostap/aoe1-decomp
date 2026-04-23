// tried the natural switch form; VC5 still picked the wrong register basin for the selector byte
class RGE_Command {
public:
    unsigned char duplicate_check_command_order(unsigned char* param_1);
    unsigned char duplicate_check_command_stop(unsigned char* param_1);
    unsigned char close_check_for_duplicate_orders(unsigned char* param_1);
};

unsigned char RGE_Command::close_check_for_duplicate_orders(unsigned char* param_1) {
    unsigned char selector = *param_1;
    switch (selector) {
    case 0:
    case 2:
    case 3:
        if (this->duplicate_check_command_order(param_1) != 0) {
            return 1;
        }
        break;
    case 1:
        if (this->duplicate_check_command_stop(param_1) != 0) {
            return 1;
        }
        break;
    }
    return 0;
}
