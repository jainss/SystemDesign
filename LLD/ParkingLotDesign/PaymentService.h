#include <cmath>
#include <unordered_map>
#include "RateCard.h"

class PaymentService {
public:
    static double calculateAmount(std::shared_ptr<Ticket> ticket);

private:
    static std::unordered_map<VehicleType, RateCard> rateTable;
    static double calculateHours(time_t start, time_t end) {
        double seconds = difftime(end, start);
        return ceil(seconds / 3600.0); // ceil rounds up to the nearest hour
    }
};
