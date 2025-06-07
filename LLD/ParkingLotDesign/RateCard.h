class RateCard {
public:
    double minFee;
    double maxFee;
    double hourlyRate;

    // Default constructor
    RateCard() : minFee(0), maxFee(0), hourlyRate(0) {}

    // Param constructor
    RateCard(double minF, double maxF, double rate)
        : minFee(minF), maxFee(maxF), hourlyRate(rate) {}
};
