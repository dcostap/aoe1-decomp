struct ResourceTable {
    char gap_00[0x50];
    float* values;
};

struct ResourceContext {
    char gap_00[0xF0];
    ResourceTable* table;
};

class TribeResourceAIModule {
public:
    char gap_00[0xF0];
    ResourceContext* md;
    int numberResourcesValue;

    int resource(int index) const;
};

int TribeResourceAIModule::resource(int index) const {
    if ((index >= 0) && (index < this->numberResourcesValue)) {
        return (int)this->md->table->values[index];
    }
    return -1;
}
