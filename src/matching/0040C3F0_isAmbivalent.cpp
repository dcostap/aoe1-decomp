class DiplomacyAIModule {
public:
    int isDisliked(int player) const;
    int isLiked(int player) const;
    int isAmbivalent(int player) const;
};

int DiplomacyAIModule::isAmbivalent(int player) const {
    if (this->isDisliked(player) == 0) {
        if (this->isLiked(player) == 0) {
            return 1;
        }
    }
    return 0;
}
