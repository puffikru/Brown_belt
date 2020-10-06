#include <variant>
#include <cstdint>
#include <optional>
#include <iostream>

using namespace std;

enum class FailReason {
    ZERO_BALANCE,
    LOW_BID,
    INVALID_CURRENCY,
    // ...
};


variant<uint64_t, FailReason> ComputeCost(const Banner& banner) {
    if (banner.balance <= 0) {
        return FailReason::ZERO_BALANCE;
    } else if (banner.bid < MIN_BID) {
        return FailReason::LOW_BID;
    } else if (!IsCurrencyValid(banner.currency)) {
        return FailReason::INVALID_CURRENCY;
    }
    // ...

    return ConvertBid(min(banner.bid, banner.balance), banner.currency);
}

int main() {
    optional<uint64_t> cost;

    if (const auto cost_or_failure = ComputeCost(banner);
            holds_alternative<FailReason>(cost_or_failure)) {
        LogFailure(banner, get<FailReason>(cost_or_failure));
    } else {
        cost = get<uint64_t>(cost_or_failure);
    }

    variant<int, double> GetSomeNumber() {
        return round(asin(0.5) * 180);
    }

}