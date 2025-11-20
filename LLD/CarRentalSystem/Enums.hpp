#ifndef ENUMS_HPP
#define ENUMS_HPP

enum class VehicleType {
    CAR, BIKE, SCOOTER
};

enum class Status {
    ACTIVE,
    INACTIVE
};

enum class ReservationType {
    HOURLY,
    DAILY
};

enum class ReservationStatus {
    SCHEDULED,
    INPROGRESS,
    COMPLETED,
    CANCELLED
};

enum class PaymentMode {
    CASH,
    ONLINE
};

#endif