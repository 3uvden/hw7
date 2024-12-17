#include <iostream>
#include <Windows.h>

bool isLeapYear(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int dateDifference(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days1 = year1 * 365 + day1;
    for (int i = 0; i < month1 - 1; i++) {
        days1 += (i == 1) ? 28 + isLeapYear(year1) : (i % 2 == 0 ? 30 : 31);
    }

    int days2 = year2 * 365 + day2;
    for (int i = 0; i < month2 - 1; i++) {
        days2 += (i == 1) ? 28 + isLeapYear(year2) : (i % 2 == 0 ? 30 : 31);
    }

    return days2 - days1;
}

int main() {
    
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int day1, month1, year1;
    int day2, month2, year2;

    std::cout << "¬ведите первую дату (день мес€ц год): ";
    std::cin >> day1 >> month1 >> year1;
    std::cout << "¬ведите вторую дату (день мес€ц год): ";
    std::cin >> day2 >> month2 >> year2;

    int difference = dateDifference(day1, month1, year1, day2, month2, year2);
    std::cout << "–азность в дн€х: " << difference << "\n";

    return 0;
}