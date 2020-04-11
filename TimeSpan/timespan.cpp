//
//  timespan.cpp
//  TimeSpan
//
//  Created by Soo Yun Kim on 3/31/20.
//  Copyright © 2020 Soo Yun Kim. All rights reserved.
//

#include "timespan.hpp"

// constructor
// set zero to hours, minutes, and seconds
TimeSpan::TimeSpan() : h{0}, m{0}, s{0} {}

// constructor
// Call simplify function to modify the TimeSpan format
TimeSpan::TimeSpan(double h, double m, double s) : h{h}, m{m}, s{s} {
    simplify();
}

// destructor
TimeSpan::~TimeSpan() {}

// friend function
// Make minutes and seconds to two digits
// returns the TimeSpan in 00:00:00 format
std::ostream &operator<<(std::ostream &out, const TimeSpan &ts) {
    out << ts.h << ":" << std::setw(2) << std::setfill('0')
    << ts.m << ":" << std::setw(2) << std::setfill('0') << ts.s;
    return out;
}

// Checks if two TimeSpans are equal
// return true if the times are equal, false otherwise
bool TimeSpan::operator==(const TimeSpan &ts) const {
    return ts.h == h && ts.m == m && ts.s == s;
}

// Checks if two TimeSpans are unequal
// return true if the times are different, false otherwise
bool TimeSpan::operator!=(const TimeSpan &ts) const {
    return ts.h != h && ts.m != m && ts.s != s;
}

// Checks if given TimeSpan is greater than compared TimeSpan
// return true if the parameter time is greater than the current object,
// false otherwise
bool TimeSpan::operator>(const TimeSpan &ts) const {
    return ts.h > h && ts.m > m && ts.s > s;
}

// Checks if given TimeSpan is less than compared TimeSpan
// return true if the parameter time is less than the current object,
// false otherwise
bool TimeSpan::operator<(const TimeSpan &ts) const {
    return ts.h < h && ts.m < m && ts.s < s;
}

// Checks if given TimeSpan is greater than or equal to compared TimeSpan
// return true if the parameter time is greater than or equal to
// the current object, false otherwise
bool TimeSpan::operator>=(const TimeSpan &ts) const {
    return *this == ts || *this > ts;
}

// Checks if given TimeSpan is less than or equal to compared TimeSpan
// return true if the parameter time is less than or equal to
// the current object, false otherwise
bool TimeSpan::operator<=(const TimeSpan &ts) const {
    return *this == ts || *this < ts;
}

// operator+
// overloaded +:
// addition of 2 TimeSpan, current object and parameter
// Result is simplified to lowest terms.
TimeSpan TimeSpan::operator+(const TimeSpan &ts) const {
    TimeSpan add;
    
    add.h = ts.h + h;
    add.m = ts.m + m;
    add.s = ts.s + s;
    
    add.simplify();
    
    return add;
}

// operator+=
// overloaded +=:
// current object = current object + parameter
// Result is simplified to lowest terms.
TimeSpan& TimeSpan::operator+=(const TimeSpan &ts) {
    h += ts.h;
    m += ts.m;
    s += ts.s;
    
    simplify();
    
    return *this;
}

// operator-
// overloaded -:
// subtraction of 2 TimeSpan, current object and parameter
// Result is simplified to lowest terms.
TimeSpan TimeSpan::operator-(const TimeSpan &ts) const {
    TimeSpan sub;
    
    sub.h = h - ts.h;
    sub.m = m - ts.m;
    sub.s = s - ts.s;
    
    sub.simplify();
    
    return sub;
}

// operator-=
// overloaded -=:
// current object = current object - parameter
// Result is simplified to lowest terms.
TimeSpan& TimeSpan::operator-=(const TimeSpan &ts) {
    h -= ts.h;
    m -= ts.m;
    s -= ts.s;
    
    simplify();
    
    return *this;
}

// operator*
// overloaded *:
// multiplication of 2 TimeSpan, current object and parameter
// Result is simplified to lowest terms.
TimeSpan TimeSpan::operator*(const int &num) const {
    TimeSpan mult;
    
    mult.h = h * num;
    mult.m = m * num;
    mult.s = s * num;
    
    mult.simplify();
    
    return mult;
}

// simplify a correct format of TimeSpan
TimeSpan TimeSpan::simplify() {
    s = h * 60 * 60 + m * 60 + s;
    h = 0;
    m = 0;
    
    while (0 > m || 60 <= m || 0 > s || 60 <= s) {
        if (s < 0) {
            m--;
            s += 60;
        }
        if (s > 59) {
            m++;
            s -= 60;
        }
        if (m < 0) {
            h--;
            m += 60;
        }
        if (m > 59) {
            h++;
            m -= 60;
        }
    }
    
    h = (int)h;
    m = (int)m;
    s = (int)s;
    
    return *this;
}
