#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <cmath>

constexpr double PI       = 3.14159265358979323846;
constexpr double EXP2_3   = 8.0;
constexpr double EXP2_11  = 2048;
constexpr double EXP2_14  = 16384;
constexpr double EXP2_16  = 65536;
constexpr double EXP2_12  = 4096;
constexpr double EXP2_N6  = 0.015625;
constexpr double EXP2_N11 = 0.00048828125;
constexpr double EXP2_N19 = 0.0000019073486328125;
constexpr double EXP2_N20 = 0.00000095367431640625;
constexpr double EXP2_N21 = 0.000000476837158203125;
constexpr double EXP2_N23 = 0.00000011920928955078125;
constexpr double EXP2_N24 = 0.000000059604644775390625;
constexpr double EXP2_N27 = 0.000000007450580596923828125;
constexpr double EXP2_N30 = 0.000000000931322574615478515625;
constexpr double EXP2_N31 = 0.0000000004656612873077392578125;
constexpr double EXP2_N33 = 1.16415321826934814453e-10;
constexpr double EXP2_N38 = 3.63797880709171295166e-12;
constexpr double EXP2_N43 = 1.13686837721616029739e-13;
constexpr double EXP2_N50 = 8.88178419700125232338e-16;
constexpr double EXP2_N66 = 1.35525271560688054250e-20;
constexpr double EXP1_N1  = 0.1;
constexpr double EXP1_N9  = 1e-9;

/* beidou time frame */
const static double bdt0[] = {2006,1,1,0,0,0};

/* time struct */
typedef struct {
    time_t time;
    double sec;
} gtime_t;


inline uint32_t merge_two_u(uint32_t a, uint32_t b, const int n)
{
    return (a << n) + b;
}

inline int32_t merge_two_s(int32_t a, uint32_t b, const int n)
{
    return (a << n) + b;
}

inline double get_ura_from_urai(const uint8_t urai)
{
    double res = -1;
    if (urai >= 0 && urai < 6){
        if (urai == 1) { res = 2.8; }
        else if (urai == 3) { res = 5.7; }
        else if (urai == 5) { res = 11.3; }
        else { res = pow(2, (urai / 2) + 1); }
    }
    else if (urai >= 6 && urai < 15) { res = pow(2, (urai - 2)); }
    /* If urai=15, it means the satellite is in maneuver or there is no accuracy prediction */
    else if (urai == 15) { res = 0; }
    return res;
}

inline gtime_t bdt2gpst(gtime_t t, double sec){
    double tt{};
    t.sec += 14.0;
    tt = floor(t.sec);
    t.time += (int) tt;
    t.sec -= tt;
    return t;
}

inline gtime_t epoch2time(const double *ep){
    const int doy[] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    gtime_t time = { 0 };
    int days{};
    int sec{};
    auto year = static_cast<int>(ep[0]);
    auto mon  = static_cast<int>(ep[1]);
    auto day  = static_cast<int>(ep[2]);

    if (year < 1970 || 2099 < year || mon < 1 || 12 < mon)
        return time;

    /* leap year if year%4==0 in 1901-2099 */
    days = (year - 1970) * 365 + (year - 1969) / 4 + doy[mon - 1] + day - 2 + (year % 4 == 0 && mon >= 3 ? 1 : 0);
    sec = static_cast<int>(floor(ep[5]));
    time.time = static_cast<time_t>(days * 86400) + static_cast<int>(ep[3] * 3600) + static_cast<int>(ep[4] * 60) + sec;
    time.sec = ep[5] - sec;
    return time;
}

inline gtime_t bdt2time(const int week, double sec){
    gtime_t t = epoch2time(bdt0);

    if (sec < -1e9 || 1e9 < sec) sec = 0.0;
    t.time += 86400 * 7 * week + static_cast<int>(sec);
    t.sec = sec - static_cast<int>(sec);
    return t;
}

#endif // UTILS_HPP
