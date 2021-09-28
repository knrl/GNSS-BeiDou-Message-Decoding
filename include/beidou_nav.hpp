/*------------------------------------------------------------------------------
*
* @author: Mehmet Kaan Erol
*
------------------------------------------------------------------------------*/

#ifndef BEIDOU_NAV_HPP
#define BEIDOU_NAV_HPP

#include "navigation_base.hpp"

template<>
struct Almanac<SatelliteSystem::BeiDou> {
    uint8_t svId_u8{};             ///!< Satellite identifier PRN
    uint8_t svHealth_u8{};         ///!< Satellite health information
    uint8_t svConfig_u8{};         ///!< SV config anti-spoofing
    double ecc_f64{};              ///!< Eccentricity
    int32_t week_s32{};            ///!< Almanac week number
    int8_t amepid{};               ///!< AmEpID is the identification of the expanded almanac information
    int8_t amid{};                 ///!< Identification of time-sharing broadcasting
    double toa_sn_f64{};           ///!< Toa (s) in week
    double deltai_rad_f64{};       ///!< Delta orbital Inclination(rad)
    double i0_rad_f64{};           ///!< Orbital Inclination(rad)
    double OMGdot_rad_f64{};       ///!< Rate of Right Ascension(rad/s) omegaDot
    double sqrtA_m_f64{};          ///!< SQRT(A)  (m 1/2), Square root of semi-major axis, semiperiod
    double omg0_rad_f64{};         ///!< Longitude of ascending node of orbital plane (rad)
    double omg_rad_f64{};          ///!< Argument of Perigee(rad)
    double m0_rad_f64{};           ///!< Mean Anomaly at reference time(rad)
    double a0_s_f64{};             ///!< a0(s): Satellite clock bias
    double a1_ss_f64{};            ///!< a1(s/s): Satellite clock rate
};

template<>
struct Ephemeris<SatelliteSystem::BeiDou> {
    uint8_t svId_u8{};             ///!< Satellite identifier PRN
    uint8_t svHealth_u8{};         ///!< Satellite health information
    int32_t week_s32{};            ///!< Ephemeris week number
    int32_t BDTweek_s32{};         ///!< fit interval (h)
    uint8_t uraIndex_u8{};         ///!< SV accuracy URA index
    double ura_f64{};              ///!< SV accuracy
    double AODE_f64{};             ///!< AODE Age of data - ephemeris
    uint16_t AODC_u16{};           ///!< AODC Age of data - clock
    uint32_t toe1;

    double tgd1_s_f64{};           ///!< Group delay differential between the B1I signal and the B3I signal
    double tgd2_s_f64{};           ///!< Group delay differential between the B2I signal and the B3I signal

    double Toe{};                  ///!< Time of Ephemeris Epoch
    double Toc{};                  ///!< Time of Clock Epoch
    double Sow{};                  ///!< Seconds of week (sec)

    /// Clock informations
    double a0_s_f64{};             ///!< Time polynomial coefficient 0 - SV clock bias (sec)
    double a1_ss_f64{};            ///!< Time polynomial coefficient 1 - SV clock drift (sec/sec)
    double a2_ss2_f64{};           ///!< Time polynomial coefficient 2 - SV clock drift rate (sec/sec**2)

    /// Major orbit parameters
    double sqrtA_f64{};            ///!< Square root of semi-major axis (m 1/2)
    double OMGdot_rad_f64{};       ///!< Rate of Right Ascension(rad/s)
    double deltaN_rad_sec_f64{};   ///!< Mean motion difference from computed value at reference time
    double m0_rad_f64{};           ///!< Mean anomaly at reference time
    double ecc_f64{};              ///!< Eccentricity
    double omega_rad_f64{};        ///!< Argument of Perigee(rad)
    double omega0_rad_f64{};       ///!< Longitude of ascending node of orbital plane at weekly epoch
    double i0_rad_f64{};           ///!< Inclination angle(rad), at reference time
    double IDOT_rad_sec_f64{};     ///!< Inclination Rate rad/sec

    /// Harmonic perturbations
    double Cis_rad_f64{};          ///!< Amplitude of sine harmonic correction term to angle of inclination
    double Cic_rad_f64{};          ///!< Amplitude of cosine harmonic correction term to angle of inclination
    double Crs_m_f64{};            ///!< Amplitude of sine correction term to orbit radius
    double Crc_m_f64{};            ///!< Amplitude of cosine correction term to orbit radius
    double Cus_rad_f64{};          ///!< Amplitude of sine harmonic correction term to argument of latitude
    double Cuc_rad_f64{};          ///!< Amplitude of cosine harmonic correction term to argument of latitude

};

template<>
struct UTC<SatelliteSystem::BeiDou> {
    double A0utc_s_f64{};
    double A1utc_ss_f64{};
    double A0gps_s_f64{};
    double A1gps_ss_f64{};
    double A0glo_s_f64{};
    double A1glo_ss_f64{};
    double A0gal_s_f64{};
    double A1gal_ss_f64{};
    double DtLS_s_f64{};     ///!< Delta time due to current leap seconds
    double WNt_f64{};        ///!< UTC parameters reference week number
    double WNlsf_f64{};      ///!< Week number at the end of which the future leap second becomes effective
    double Dn_f64{};         ///!< Day number at the end of which the future leap second becomes effective
    double DtLSF_s_f64{};    ///!< Delta time due to future leap seconds
};

template<>
struct Ionosphere<SatelliteSystem::BeiDou> {
    double alpha0_f64{};     ///!< Ionospheric parameter alpha0 [s]
    double alpha1_f64{};     ///!< Ionospheric parameter alpha1 [s/semi-circle]
    double alpha2_f64{};     ///!< Ionospheric parameter alpha2 [s/semi-circle^2]
    double alpha3_f64{};     ///!< Ionospheric parameter alpha3 [s/semi-circle^3]
    double beta0_f64{};      ///!< Ionospheric parameter beta0  [s]
    double beta1_f64{};      ///!< Ionospheric parameter beta1  [s/semi-circle]
    double beta2_f64{};      ///!< Ionospheric parameter beta2  [s/semi-circle^2]
    double beta3_f64{};      ///!< Ionospheric parameter beta3  [s/semi-circle^3]
};

using BeiDouUTC        = UTC<SatelliteSystem::BeiDou>;
using BeiDouAlmanac    = Almanac<SatelliteSystem::BeiDou>;
using BeiDouEphemeris  = Ephemeris<SatelliteSystem::BeiDou>;
using BeiDouIonosphere = Ionosphere<SatelliteSystem::BeiDou>;

struct BeiDouNavData{
    BeiDouAlmanac    alm[Num_BeiDou_Satellites]{};
    BeiDouEphemeris  eph[Num_BeiDou_Satellites]{};
    uint8_t          health[Num_BeiDou_Satellites]{};
    BeiDouUTC        utc{};
    BeiDouIonosphere iono{};
};

#endif /* BEIDOU_NAV_HPP */
