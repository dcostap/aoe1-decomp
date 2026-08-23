#ifndef SPANLIST_SHARED_CONTEXT
class TSpan_Node_List {
public:
    void ReclaimAllNodes();
    char pad[0x10];
    int field_10;
    int field_14;
    int field_18;
    int field_1C;
    int field_20;
    char pad2[0x14];
    int field_38;
};
#endif
void TSpan_Node_List::ReclaimAllNodes() {
    this->field_10 = 0;
    this->field_14 = 0;
    this->field_18 = 0;
    this->field_20 = this->field_1C;
    this->field_38++;
}
