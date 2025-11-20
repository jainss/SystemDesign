enum class Coin {
    PENNY = 1,
    NICKEL = 5,
    DIME = 10,
    QUARTER = 25
};

// Optional helper to get int value from enum (like .value in Java)
int getCoinValue(Coin coin) {
    return static_cast<int>(coin);
}