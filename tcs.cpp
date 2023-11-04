#include <iostream>
#include <string>
#include <cmath>

bool isPrime(int num) {
    if (num <= 1) return false;
    if (num <= 3) return true;
    if (num % 2 == 0 || num % 3 == 0) return false;

    for (int i = 5; i * i <= num; i += 6) {
        if (num % i == 0 || num % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    std::string date, dow;
    int n;
    std::cin >> date >> dow >> n;

    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(4, 2));
    int day = std::stoi(date.substr(6, 2));

    int primeDaysCount = 0;
    int daysAfterRain = 0;

    while (primeDaysCount < n) {
        day++;
        if (day > 31) {
            day = 1;
            month++;
        }
        if (month > 12) {
            month = 1;
            year++;
        }

        if (isPrime(day) && (month == 2 || month == 3 || month == 5 || month == 7 || month == 11)) {
            primeDaysCount++;
            if (primeDaysCount == n) {
                daysAfterRain = 1;
            }
        }
    }

    if (daysAfterRain > 0) {
        std::cout << "Yes " << daysAfterRain << std::endl;
    } else {
        int nextPrimeDay = 1;
        while (true) {
            day++;
            if (day > 31) {
                day = 1;
                month++;
            }
            if (month > 12) {
                month = 1;
                year++;
            }
            if (isPrime(day) && (month == 2 || month == 3 || month == 5 || month == 7 || month == 11)) {
                std::cout << "No " << nextPrimeDay << std::endl;
                break;
            }
            nextPrimeDay++;
        }
    }

    return 0;
}
