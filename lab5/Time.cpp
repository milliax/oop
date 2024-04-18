#include "Time.h"

Time Time::operator+(Time other) {
    // perform + opearion overloading
    Time temp;

    temp.hour = this->hour + other.hour;
    temp.minute = this->minute + other.minute;
    temp.second = this->second + other.second;

    format(temp);

    return temp;
}

Time Time::operator-(Time other) {
    // perform - opearion overloading
    Time temp;

    temp.hour = this->hour - other.hour;
    temp.minute = this->minute - other.minute;
    temp.second = this->second - other.second;

    format(temp);

    return temp;
}

bool Time::operator==(const Time& other) {
    // perform == opearion overloading

    return this->hour == other.hour && this->minute == other.minute &&
           this->second == other.second;
}

bool Time::operator!=(const Time& other) {
    // perform != opearion overloading

    return this->hour != other.hour || this->minute != other.minute ||
           this->second != other.second;
}

istream& operator>>(istream& in, Time& time) {
    // perform input overloading
    string temp;

    in >> temp;

    if (temp.size() > 0) {
        time.hour = stoi(temp.substr(0, 2));
        time.minute = stoi(temp.substr(3, 2));
        time.second = stoi(temp.substr(6, 2));
    }

    return in;
}

ostream& operator<<(ostream& out, const Time& time) {
    // perform output overloading

    out << setfill('0') << setw(2) << time.hour << ":" << setw(2) << time.minute
        << ":" << setw(2) << time.second << endl;

    return out;
}

void Time::format(Time& time) {
    if (time.hour > 0 && time.hour < 24 && time.minute > 0 &&
        time.minute < 60 && time.second > 0 && time.second < 60) {
        // the format is perfect
        return;
    }

    if (time.second >= 60 || time.second < 0) {
        while (time.second < 0) {
            time.minute -= 1;
            time.second += 60;
        }

        time.minute += time.second / 60;
        time.second %= 60;
    }

    if (time.minute >= 60 || time.minute < 0) {
        while (time.minute < 0) {
            time.hour -= 1;
            time.minute += 60;
        }

        time.hour += time.minute / 60;
        time.minute %= 60;
    }

    if (time.hour < 0) {
        time.hour = 0;
        time.minute = 0;
        time.second = 0;
    }
}