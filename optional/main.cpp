#include <optional>

using namespace std;




struct Date {
    int year, month, day;
};

enum class InvalidDateReason {
    NONPOSITIVE_YEAR,
    MONTH_TOO_SMALL,
    MONTH_TOO_BIG,
    // ...
};


// Возврат optional из функции

optional<InvalidDateReason> CheckDate(const Date& date) {
    if (date.year < 1) {
        return InvalidDateReason::NONPOSITIVE_YEAR;
    } else if (date.month < 1) {
        return InvalidDateReason::MONTH_TOO_SMALL;
    } else if (date.month > 12) {
        return InvalidDateReason::MONTH_TOO_BIG;
    } // ...

    return nullopt;
}