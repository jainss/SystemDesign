enum class ItemType {
    COKE,
    PEPSI,
    JUICE,
    SODA
};

inline const char* itemTypeToString(ItemType type) {
    switch (type) {
        case ItemType::COKE: return "COKE";
        case ItemType::PEPSI: return "PEPSI";
        case ItemType::JUICE: return "JUICE";
        case ItemType::SODA: return "SODA";
        default: return "UNKNOWN";
    }
}
