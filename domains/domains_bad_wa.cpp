//#include <algorithm>
//#include <iostream>
//#include <string>
//#include <string_view>
//#include <vector>
//
//using namespace std;
//
//
//vector<string> ReadDomain(size_t count) {
//    vector<string> result;
//    for (size_t i = 0; i < count; ++i) {
//        string domain;
//        cin >> domain;
//        reverse(begin(domain), end(domain));
//        result.push_back(domain);
//    }
//    return result;
//}
//
//bool isSubDomain(const string& subdomain, const string& domain) {
//    int i = 0;
//    int j = 0;
//
//    while (i < subdomain.size() && j < domain.size()) {
//        if (subdomain[i++] != domain[j++]) {
//            return false;
//        }
//    }
//    return j >= domain.size() && subdomain[i] == '.';
//}
//
//int main() {
//    size_t N, M;
//    cin >> N;
//    vector<string> banned = ReadDomain(N);
//    cin >> M;
//    vector<string> domains = ReadDomain(M);
//
//    sort(begin(banned), end(banned));
//
//    for (const auto& domain : domains) {
//        if (const auto it = upper_bound(begin(banned), end(banned), domain);
//                it != begin(banned) && isSubDomain(domain, *prev(it))) {
//            cout << "Good" << endl;
//        } else {
//            cout << "Bad" << endl;
//        }
//    }
//
//    for (const auto& i : banned) {
//        cout << i << '\n';
//    }
//    cout << '\n';
//
//    for (const auto& i : domains) {
//        cout << i << '\n';
//    }
//    cout << '\n';
//
//    return 0;
//}
//

//#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <string_view>
#include <vector>
#include <sstream>

using namespace std;

vector<string_view> SplitDomain(string_view domain) {
    vector<string_view> splited;

    while (!domain.empty()) {
        if (domain[0] == '.') {
            domain.remove_prefix(1);
        }
        auto pos = domain.find('.');
        splited.push_back(domain.substr(0, pos));
        if (pos != domain.npos) {
            domain.remove_prefix(pos);
        }
        else {
            break;
        }
    }
    return splited;
}

class DomainChecker {
public:
    void ReadBadDomains(istream& input) {
        int count;
        //input >> count;
        string str;
        getline(input, str, '\n');
        count = atoi(str.c_str());

        storage.resize(count);
        bad_domains.resize(count);

        for (int i = 0; i < storage.size(); i++) {
            //input >> storage[i];
            getline(input, storage[i], '\n');
            bad_domains[i] = SplitDomain(storage[i]);
        }
        sort(bad_domains.begin(), bad_domains.end(), [](const vector<string_view>& lhs, const vector<string_view>& rhs) { return lhs.size() < rhs.size(); });
    }

    bool CheckIsGood(vector<string_view> domain) const {
        auto it = bad_domains.begin();
        while (it != bad_domains.end() && it->size() <= domain.size()) {
            auto searcher = search(domain.begin(), domain.end(), it->begin(), it->end());
            if (searcher != domain.end()) {
                return false;
            }
            it++;
        }
        return true;
    }

    const vector<string>& GetStorage() {
        return storage;
    }

    const vector<vector<string_view>>& GetBadDomains() {
        return bad_domains;
    }
private:
    vector<string> storage;
    vector<vector<string_view>> bad_domains;
};

vector<string> ReadDomains(istream& input) {
    size_t count;
    //input >> count;
    string str;
    getline(input, str, '\n');
    count = atoi(str.c_str());

    vector<string> domains;
    for (size_t i = 0; i < count; ++i) {
        string domain;
        //input >> domain;
        getline(input, domain, '\n');
        domains.push_back(domain);
    }
    return domains;
}

void PrintGoodBad(ostream& output, const DomainChecker& Checker, const vector<string>& domains) {
    for (const auto& domain : domains) {
        bool good = Checker.CheckIsGood(SplitDomain(domain));
        if (good) {
            output << "Good\n";
        }
        else {
            output << "Bad\n";
        }
    }
}
int main() {
    /*TestRunner tr;
    RUN_TEST(tr, TestSplitDomain);
    RUN_TEST(tr, TestReadBadDomains);
    RUN_TEST(tr, TestCheckIsGood);
    RUN_TEST(tr, TestReadDomains);
    RUN_TEST(tr, TestPrintGoodBad);*/

    DomainChecker Checker;
    Checker.ReadBadDomains(cin);
    const vector<string> domains = ReadDomains(cin);

    PrintGoodBad(cout, Checker, domains);

    return 0;
}