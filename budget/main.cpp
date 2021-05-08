//#include <iostream>
//#include <exception>
//#include <sstream>
//#include <map>
//#include <cstdlib>
//#include <iomanip>
//#include <iterator>
//#include <ctime>
//#include <memory>
//#include <algorithm>
//
// using namespace std;
//
// class Date {
// public:
//    Date(const string& date) {
//        ParseDate(date);
//    }
//
//    time_t AsTimestamp() const;
//
//    int GetYear() const {
//        return year_;
//    }
//
//    int GetMonth() const {
//        return month_;
//    }
//
//    int GetDay() const {
//        return day_;
//    }
//
//    void SetYear(int n) {
//        year_ = n;
//    }
//
//    void SetMonth(int n) {
//        month_ = n;
//    }
//
//    void SetDay(int n) {
//        day_ = n;
//    }
//
//
//
// private:
//    int year_;
//    int month_;
//    int day_;
//
//    void ParseDate(const string& date) {
//        stringstream ss(date);
//        ss >> year_;
//        ss.ignore(1);
//        ss >> month_;
//        ss.ignore(1);
//        ss >> day_;
//    }
//};
//
// Date& operator++(Date& date) {
//    date.SetDay(date.GetDay() + 1);
//    if (date.GetMonth() == 1 || date.GetMonth() == 3 || date.GetMonth() == 5 || date.GetMonth() ==
//    7 ||
//            date.GetMonth() == 8 || date.GetMonth() == 10 || date.GetMonth() == 12) {
//        if (date.GetDay() > 31) {
//            date.SetMonth(date.GetMonth() + 1);
//            date.SetDay(1);
//        }
//    } else if (date.GetMonth() == 2) {
//        if (date.GetDay() > 28) {
//            date.SetMonth(date.GetMonth() + 1);
//            date.SetDay(1);
//        }
//    } else {
//        if (date.GetDay() > 30) {
//            date.SetMonth(date.GetMonth() + 1);
//            date.SetDay(1);
//        }
//    }
//    if (date.GetMonth() > 12) {
//        date.SetYear(date.GetYear() + 1);
//        date.SetMonth(1);
//    }
//    return date;
//}
//
// Date operator++(Date& date, int) {
//    Date tmp = date;
//    date.SetDay(date.GetDay() + 1);
//    if (date.GetMonth() == 1 || date.GetMonth() == 3 || date.GetMonth() == 5 || date.GetMonth() ==
//    7 ||
//        date.GetMonth() == 8 || date.GetMonth() == 10 || date.GetMonth() == 12) {
//        if (date.GetDay() > 31) {
//            date.SetMonth(date.GetMonth() + 1);
//            date.SetDay(1);
//        }
//    } else if (date.GetMonth() == 2) {
//        if (date.GetDay() > 28) {
//            date.SetMonth(date.GetMonth() + 1);
//            date.SetDay(1);
//        }
//    } else {
//        if (date.GetDay() > 30) {
//            date.SetMonth(date.GetMonth() + 1);
//            date.SetDay(1);
//        }
//    }
//    if (date.GetMonth() > 12) {
//        date.SetYear(date.GetYear() + 1);
//        date.SetMonth(1);
//    }
//    return tmp;
//}
//
// bool operator<(const Date& lhs, const Date& rhs) {
//    if (lhs.GetYear() < rhs.GetYear()) {
//        return true;
//    } else if (lhs.GetMonth() < rhs.GetMonth()) {
//        return true;
//    } else {
//        return lhs.GetDay() < rhs.GetDay();
//    }
//}
//
//
// bool operator>(const Date& lhs, const Date& rhs) {
//    if (lhs.GetYear() > rhs.GetYear()) {
//        return true;
//    } else if (lhs.GetMonth() > rhs.GetMonth()) {
//        return true;
//    } else {
//        return lhs.GetDay() > rhs.GetDay();
//    }
//}
//
//
// bool operator==(const Date& lhs, const Date& rhs) {
//    return lhs.GetYear() == rhs.GetYear() && lhs.GetMonth() == rhs.GetMonth() && lhs.GetDay() ==
//    rhs.GetDay();
//}
//
// ostream& operator<<(ostream& os, const Date& date) {
//    os << date.GetYear() << " " << date.GetMonth() << " " << date.GetDay();
//    return os;
//}
//
// bool operator==(pair<const Date, double>& lhs, const Date& rhs) {
//    return lhs.first == rhs;
//}
//
//
// time_t Date::AsTimestamp() const {
//    std::tm t;
//    t.tm_sec   = 0;
//    t.tm_min   = 0;
//    t.tm_hour  = 0;
//    t.tm_mday  = day_;
//    t.tm_mon   = month_ - 1;
//    t.tm_year  = year_ - 1900;
//    t.tm_isdst = 0;
//    return mktime(&t);
//}
//
// int ComputeDaysDiff(const Date& date_to, const Date& date_from) {
//    const time_t timestamp_to = date_to.AsTimestamp();
//    const time_t timestamp_from = date_from.AsTimestamp();
//    static const int SECONDS_IN_DAY = 60 * 60 * 24;
////    cout << timestamp_from << '\n';
////    cout << timestamp_to << '\n';
////    cout << timestamp_to - timestamp_from << '\n';
//    return (timestamp_to - timestamp_from) / SECONDS_IN_DAY;
//}
//
//
// class Budget {
// public:
//    Budget(){}
//
//    void SaveIncome(Date& from, Date& to, int value) {
//        int days = ComputeDaysDiff(to, from) + 1;
////        cout << days << '\n';
//        double income_per_day = value * 1.0 / days * 1.0;
////        cout << days << '\n';
////        cout << from << '\n';
////        cout << income_[from] << '\n';
//        for (size_t i = 0; i < days; ++i) {
//
//            income_[from++] += income_per_day;
//        }
//    }
//
//    double GetIncomeSum(Date& from, Date& to) {
////        Date fr = from;
////        Date t = to;
////        PayTax(fr, t);
//        int days = ComputeDaysDiff(to, from) + 1;
//        double sum = 0;
////        cout << days << '\n';
//        cout << from << " - " << to << '\n';
//        auto it = find(begin(income_), end(income_), from);
//        cout << "it: " << it->first << '\n';
//        auto begin = income_.find(from);
//        auto end = income_.find(to);
//        cout << begin->first << " " << begin->second << '\n';
//        cout << end->first << " " << end->second << '\n';
//        for (; begin != end; ++begin) {
//            sum += income_[begin->first];
//        }
//
//
////        for (size_t i = 0; i < days; ++i) {
////            cout << i << '\n';
////            cout << income_[from] << '\n';
//
////            if (from > to) {
////                i = days;
////            }
////            sum += income_[from++];
////            cout << "sum: " << sum << '\n';
//
////            cout << sum << '\n';
////            cout << "======" << '\n';
////        }
//
//        for (const auto& i : income_) {
//            cout << i.first << ": " << i.second << '\n';
//        }
//        cout << '\n';
//
//        cout << "sum: " << sum << '\n';
//        return sum;
//    }
//
//    void PayTax(Date& from, Date& to) {
//        int days = ComputeDaysDiff(to, from) + 1;
//        for (size_t i = 0; i < days; ++i) {
//            income_[from++] *= 0.87;
//        }
//
////        for (const auto& i : income_) {
////            cout << i.first << ": " << i.second << '\n';
////        }
//
////        cout << income_[from] << '\n';
//    }
//
// private:
//    map<Date, double> income_;
//};
//
//
//
// int main() {
//    int Q;
//    string query;
//    string from;
//    string to;
//    int value;
//    Budget budget;
//    cin >> Q;
//    while (Q > 0) {
//        cin >> query;
//        if (query == "ComputeIncome") {
//            cin >> from >> to;
//            Date fr(from);
//            Date t(to);
//            budget.GetIncomeSum(fr, t);
//        } else if (query == "Earn") {
//            cin >> from >> to >> value;
//            Date fr(from);
//            Date t(to);
//            budget.SaveIncome(fr, t, value);
//        } else if (query == "PayTax") {
//            cin >> from >> to;
//            Date fr(from);
//            Date t(to);
//            budget.PayTax(fr, t);
//        } else {
//            throw invalid_argument("Unknown query");
//        }
//        --Q;
//    }
//
//    return 0;
//}

#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <unordered_map>
#include <sstream>

struct Date {
    int year;
    int month;
    int day;

    time_t AsTimestamp() const;
};

Date &operator++(Date &date) {
    date.day++;
    if (date.day > 31) {
        date.month++;
        date.day = 1;
    }
    if (date.month > 12) {
        date.year++;
        date.month = 1;
    }
    return date;
}

Date operator++(Date &date, int) {
    Date date_ = date;
    date.day++;
    if (date.day > 31) {
        date.month++;
        date.day = 1;
    }
    if (date.month > 12) {
        date.year++;
        date.month = 1;
    }
    return date_;
}

std::ostream &operator<<(std::ostream &os, const Date &date) {
    os << date.year << "-" << date.month << "-" << date.day;
    return os;
}

std::shared_ptr<Date> ParseDate(const std::string &date) {
    std::stringstream ss(date);
    Date date_;
    ss >> date_.year;
    ss.ignore(1);
    ss >> date_.month;
    ss.ignore(1);
    ss >> date_.day;
    return std::make_shared<Date>(date_);
}

time_t Date::AsTimestamp() const {
    tm t;
    t.tm_sec = 0;
    t.tm_min = 0;
    t.tm_hour = 0;
    t.tm_mday = day;
    t.tm_mon = month - 1;
    t.tm_year = year - 1900;
    t.tm_isdst = 0;
    return mktime(&t);
}

int ComputeDaysDiff(const Date &date_to, const Date &date_from) {
    const time_t timestamp_to = date_to.AsTimestamp();
    const time_t timestamp_from = date_from.AsTimestamp();
    static const int SECONDS_IN_DAY = 60 * 60 * 24;
    return static_cast<int>((timestamp_to - timestamp_from) / SECONDS_IN_DAY);
}

class Budget {
public:
    Budget() = default;

    Budget(const Date *from, const Date *to) {
    }

    double GetSumForRange(const std::shared_ptr<Date> &from,
                          const std::shared_ptr<Date> &to) const {
    }

    void SetIncome(std::shared_ptr<Date> &from, std::shared_ptr<Date> &to, double value) {
        int days = ComputeDaysDiff(*to, *from) + 1;
        int income_per_day = static_cast<int>(value / days);
        for (size_t i = 0; i < days; ++i) {
            income_[from.get()] = income_per_day;
            (*from)++;
        }
        for (const auto &i : income_) {
            std::cout << *i.first << " " << i.second << '\n';
        }
    }

private:
    std::unordered_map<Date *, double> income_;
};

int main() {
    Budget budget;
    auto from = ParseDate("2020-10-01");
    auto to = ParseDate("2020-10-05");
    budget.SetIncome(from, to, 2000);
    return 0;
}