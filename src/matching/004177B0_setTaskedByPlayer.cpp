class UnitAIModule {
public:
    void purgeNotifyQueue(unsigned long flags);
    void setTaskedByPlayer();
};

void UnitAIModule::setTaskedByPlayer() {
    this->purgeNotifyQueue(0);
}
