#ifndef __DATE_CALCULATOR_H__
#define __DATE_CALCULATOR_H__

#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

struct DateTime {
    int year;
    int month;
    int day;
    int delta;
};

class DateCalculator {
   private:
    int year;
    int month;
    int day;
    int deltaDays;
    int datePos;
    vector<DateTime> inputDates;

   public:
    DateCalculator() : year(1970), month(1), day(1) { datePos = 0; }
    DateCalculator(int year, int month, int day)
        : year(year), month(month), day(day) {}

    void readFile(const char *filename);
    DateTime add(DateTime);
    DateTime minus(DateTime);
    bool isLeapYear(int year);
    void showDay();
    bool is_finish();
    void next();
    void count();
    int daysInMonth(int, int);
};

#endif  // __DATE_CALCULATOR_H__