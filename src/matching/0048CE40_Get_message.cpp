class RGE_Scenario {
public:
    char gap_0000[0x1014];
    char* description;
    char* hints;
    char* win_message;
    char* loss_message;
    char* historicle_notes;

    char* Get_message(long which);
};

char* RGE_Scenario::Get_message(long which) {
    switch (which) {
    case 0:
        return this->description;
    case 1:
        return this->hints;
    case 2:
        return this->win_message;
    case 3:
        return this->loss_message;
    case 4:
        return this->historicle_notes;
    default:
        return 0;
    }
}
