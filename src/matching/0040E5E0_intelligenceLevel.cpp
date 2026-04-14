class AIModule {
public:
    virtual ~AIModule();
    char gap_04[224];
    int intelligenceLevel_;

    int intelligenceLevel() const;
};
int AIModule::intelligenceLevel() const { return this->intelligenceLevel_; }
