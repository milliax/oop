#include "DateCalculator.h"

using namespace std;

void DateCalculator::readFile(const char *fileName) {
    // Read the data from the txt file.
    //
    // Hint: You can use get() to get a character in ifstream.
    //       You can use getline() to get one line in the txt file.
    //       You can use stoi() to change variable type from string to int
    ifstream rfile;
    rfile.open(fileName);

    if (!rfile.is_open()) {
        cout << "File not Found " << endl;
        return;
    }

    string str;
    stringstream ss;

    char sign, trash;
    int year, month, day, delta;

    while (getline(rfile, str)) {
        // inputtring.emplace_back(temp);

        // parse string
        ss.str("");
        ss.clear();

        ss << str;
        ss >> year >> trash >> month >> trash >> day >> sign >> delta;

        inputDates.push_back(
            {year, month, day, (sign == '+' ? delta : (delta * -1))});
    }

    rfile.close();
}

DateTime DateCalculator::add(DateTime toModifyDate) {
    // Calculate the date add the changeDays.
    int daysInThisMonth = daysInMonth(toModifyDate.year, toModifyDate.month);

    // cout << "Iteration: " << toModifyDate.year << "/" << toModifyDate.month
    //      << "/" << toModifyDate.day << " " << toModifyDate.delta << endl;

    // cout << setw(4) << setfill('0') << toModifyDate.year << "/";
    // cout << setw(2) << toModifyDate.month << "/";
    // cout << setw(2) << toModifyDate.day << " "
    //      << toModifyDate.delta << endl;

    if (toModifyDate.delta > 0) {
        if (toModifyDate.day + toModifyDate.delta > daysInThisMonth) {
            int year = toModifyDate.year;
            int month = toModifyDate.month + 1;
            return add({
                year + ((month - 1) / 12),
                (month - 1) % 12 + 1,
                toModifyDate.day,
                toModifyDate.delta - (daysInThisMonth),
            });
        }

        // delta + deos not exceed the days of a month copacity > 0, but can add
        // directly
        return add({toModifyDate.year, toModifyDate.month,
                    toModifyDate.day + toModifyDate.delta, 0});
    } else {
        return minus({
            toModifyDate.year,
            toModifyDate.month,
            toModifyDate.day,
            toModifyDate.delta,
        });
    }

    return {
        toModifyDate.year + (toModifyDate.month / 12),
        (toModifyDate.month - 1) % 12 + 1,
        toModifyDate.day,
        toModifyDate.delta,
    };
}

DateTime DateCalculator::minus(DateTime toModifyDate) {
    // cout << "minus" << endl;

    // Calculate the date minus the changeDays.
    if (toModifyDate.day + toModifyDate.delta > 0) {
        return {toModifyDate.year, toModifyDate.month,
                toModifyDate.day + toModifyDate.delta, 0};
    }
    // the remaining days in the month is not sufficient.

    // borrow a month

    if (toModifyDate.month > 1) {
        // still have a month to borrow
        // cout << "borrow a month: " << toModifyDate.year << "/"
        //      << toModifyDate.month << "/" << toModifyDate.day << endl;
        return minus({
            toModifyDate.year,
            toModifyDate.month - 1,
            toModifyDate.day +
                daysInMonth(
                    toModifyDate.month == 1 ? toModifyDate.year - 1
                                            : toModifyDate.year,
                    toModifyDate.month == 1 ? 12 : toModifyDate.month - 1),
            toModifyDate.delta,
        });
    }

    // cout << "borrow a year" << endl;
    // borrow a year
    return minus({
        toModifyDate.year - 1,
        toModifyDate.month + 12,
        toModifyDate.day,
        toModifyDate.delta,
    });
}

int DateCalculator::daysInMonth(int year, int month) {
    int daysInThisMonth;
    switch ((month - 1) % 12 + 1) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            // Big month
            daysInThisMonth = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            // Small Month
            daysInThisMonth = 30;
            break;
        case 2:
            // it depends
            if (isLeapYear(year)) {
                daysInThisMonth = 29;
            } else {
                daysInThisMonth = 28;
            }
            break;
    }

    return daysInThisMonth;
}

void DateCalculator::count() {
    int delta_remain = inputDates[datePos].delta;

    int year = inputDates[datePos].year;
    int month = inputDates[datePos].month;
    int day = inputDates[datePos].day;

    if (delta_remain > 0) {
        DateTime Result = add({year, month, day, delta_remain});
        inputDates[datePos].year = Result.year;
        inputDates[datePos].month = Result.month;
        inputDates[datePos].day = Result.day;
        inputDates[datePos].delta = Result.delta;
    } else if (delta_remain < 0) {
        DateTime Result = minus({year, month, day, delta_remain});
        inputDates[datePos].year = Result.year;
        inputDates[datePos].month = Result.month;
        inputDates[datePos].day = Result.day;
        inputDates[datePos].delta = Result.delta;
    }
}

bool DateCalculator::isLeapYear(int year) {
    // Determine whether the input year is a leap year.
    if (year % 4 == 0) {
        // is leap year
        if (year % 100 == 0) {
            // not leap year
            if (year % 400 == 0) {
                // is leap year
                // cout << "it's leap" << endl;
                return true;
            }
            return false;
        }
        // cout << "it's leap" << endl;
        return true;
    }
    return false;
}

void DateCalculator::showDay() {
    // The function output the date on the screen.
    //
    // Hint: You can use setw() to set the length of the number.
    //       You can use setfill('c') to fill 'c' to the empty space.
    //       Two functions of above is in iomanip header file.
    cout << setw(4) << setfill('0') << inputDates[datePos].year << "/";
    cout << setw(2) << inputDates[datePos].month << "/";
    cout << setw(2) << inputDates[datePos].day << endl;
}

bool DateCalculator::is_finish() { return datePos >= inputDates.size(); }

void DateCalculator::next() { datePos++; }