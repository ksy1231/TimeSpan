//
//  timespan.hpp
//  TimeSpan
//
//  Created by Soo Yun Kim on 3/31/20.
//  Copyright © 2020 Soo Yun Kim. All rights reserved.
//

#ifndef timespan_hpp
#define timespan_hpp

#include <iostream>
#include <iomanip>

class TimeSpan {
    
public:
    // constructor
    TimeSpan();
    TimeSpan(double h, double m, double s);
    // destructor
    ~TimeSpan();
    
    // displaying
    friend std::ostream &operator<<(std::ostream &out, const TimeSpan &ts);
    
    // equality
    bool operator==(const TimeSpan &ts) const;
    bool operator!=(const TimeSpan &ts) const;
    
    // comparison
    bool operator>(const TimeSpan &ts) const;
    bool operator<(const TimeSpan &ts) const;
    bool operator>=(const TimeSpan &ts) const;
    bool operator<=(const TimeSpan &ts) const;
    
    // addition
    TimeSpan operator+(const TimeSpan &ts) const;
    TimeSpan& operator+=(const TimeSpan &ts);
    
    // subtraction
    TimeSpan operator-(const TimeSpan &ts) const;
    TimeSpan& operator-=(const TimeSpan &ts);
    
    // integer multiplication
    TimeSpan operator*(const int &num) const;
    
private:
    // hours
    double h;
    // minutes
    double m;
    // seconds
    double s;
    // simplify TimeSpan format
    TimeSpan simplify();
};

#endif /* timespan_hpp */
