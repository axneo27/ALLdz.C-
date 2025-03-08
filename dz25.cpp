#include <iostream>
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include <random>
using namespace std;

void e1() {
    array<int, 10> arr = { 1,2,3,4,5,6,7,8,9,10 };
    auto Alleven = all_of(arr.begin(), arr.end(), isEven);
    auto k5 = any_of(arr.begin(), arr.end(), [](int v) {return v % 5 == 0; });
    auto minus = none_of(arr.begin(), arr.end(), [](int v) {return v < 0; });

    cout << Alleven << endl;
    cout << k5 << endl;
    cout << minus << endl;
}

void e2(int times, const std::function<void(int)>& action) {
    for (int i = 0; i < times; i++) {
        action(i);
    }
}

void e3() {
    array<string, 4> arr = {
        "gggggg",
        "dddddd",
        "aaaa",
        "gggg"
    };

    auto a = find_if(arr.begin(), arr.end(), [](string v) {
        size_t found = v.find('a');
        return found != string::npos;
    });
    a != arr.end() ? cout << *a << "\n" : cout << "Not found";
}

void e4() {
    array autos{
        "Jeep",
        "Ford",
        "Chevy",
        "BMW",
        "Mercedes",
        "VW",
        "Volvo",
        "Subaru",
        "Hyundai",
        "Kia",
        "Tesla",
        "GM",
        "Chrysler",
        "Buick",
        "Lincoln",
        "Ram",
        "Renault",
    };

    auto sameLetters = adjacent_find(autos.begin(), autos.end(), [](const auto& f, const auto& b) {
        return f[0] == b[0];
    });

    sameLetters != autos.end() ? cout << *sameLetters << ", " << *(sameLetters + 1) << "\n" : cout << "No\n";
}

void e5() {
    array<string_view, 10> arr = {
         "Jeep",
        "Ford",
        "Chevy",
        "BMW",
        "Mercedes",
        "VW",
        "Volvo",
        "Subaru",
        "Hyundai",
        "Kia"
    };

    int howMany = count_if(arr.begin(), arr.end(), [](string_view s) {
        size_t found = s.find('e');
        return found != string::npos;
    });

    cout << howMany << endl;
}

void e6() {
    array<int, 10> arr = {10, 1,2,3,4,5,6,7,8,9 };

    sort(arr.begin(), arr.end());
    for_each(arr.begin(), arr.end(), [](int& a) {cout << a << " "; });
    cout << endl;
}

void e7() {
    array<int, 7> arr = { 10, 1,2,3,4,5,6 };

    auto [min, max] = minmax_element(arr.begin(), arr.end());
    cout << "max: " << *max << " min: " << *min << endl;

}

void e8() {
    array<int, 8> arr = { 10, -1,-2,-3,4,5,-6,1213 };
    array<int, 8> arr2 = {0};

    transform(arr.begin(), arr.end(), arr2.begin(), [](int v) {
        return v < 0 ? v *= -1 : v;
    });
    for_each(arr.begin(), arr.end(), [](int& a) {cout << a << " "; });
    cout << endl;
    for_each(arr2.begin(), arr2.end(), [](int& a) {cout << a << " "; });
} 

void e9() {
    double(*x2y2) (double, double) {
        [](double x, double y) {return pow(x,2) + pow(y,2); }
    };

    double res = x2y2(2, 2);
    cout << res << endl;
    double res2 = x2y2(3, 12);
    cout << res2 << endl;
}

void e10() {
    array<int, 10> arr;
    iota(arr.begin(), arr.end(), 1);
    for_each(arr.begin(), arr.end(), [](int& a) {cout << a << " "; });
    cout << endl;

    std::random_device rd;
    shuffle(arr.begin(), arr.end(), rd);
    for_each(arr.begin(), arr.end(), [](int& a) {cout << a << " "; });
    cout << endl;
}

int main() {
    e1();
    /*e2(5, [](int i) {cout << pow(i, 2) << endl; });*/
    /*e3();*/
    /*e4();*/
    /*e5();*/
    /*e6();*/
    /*e7();*/
    /*e8();*/
    /*e9();*/
    /*e10();*/
}
