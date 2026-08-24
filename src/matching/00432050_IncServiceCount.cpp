// PDB owner: TCommunications_Services::IncServiceCount, com_serv.cpp lines 54-57.

#ifndef COM_SERV_TU_CONTEXT
class TCommunications_Services {
public:
    char gap_0[0x2580];
    int field_2580;
    int IncServiceCount();
};
#endif

int TCommunications_Services::IncServiceCount() {
    this->field_2580 = this->field_2580 + 1;
    return this->field_2580;
}
