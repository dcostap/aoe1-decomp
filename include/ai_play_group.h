#ifndef AOE1_AI_PLAY_GROUP_H
#define AOE1_AI_PLAY_GROUP_H

class AIPlayGroup {
public:
    enum {
        MaxUnitTypes = 6,
        InvalidGroup = 255
    };

protected:
    unsigned char minValue[6];  // +0x00
    unsigned char maxValue[6];  // +0x06

public:
    AIPlayGroup();
    unsigned char minimum(int index) const;
    void setMinimum(int index, int value);
    unsigned char maximum(int index) const;
    void setMaximum(int index, int value);

protected:
    void initialize();
};

typedef char ai_play_group_size_check[(sizeof(AIPlayGroup) == 0x0C) ? 1 : -1];

#endif
