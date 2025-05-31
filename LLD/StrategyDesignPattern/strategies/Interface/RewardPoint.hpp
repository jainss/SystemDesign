#pragma once

class RewardPoint {
public:
    virtual void giveRewardPoint() = 0;
    virtual ~RewardPoint() = default;
};