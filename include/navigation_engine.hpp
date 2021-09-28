#ifndef NAVIGATION_ENGINE_HPP
#define NAVIGATION_ENGINE_HPP

#include <map>
#include "beidou_subframe.hpp"

template<::SatelliteSystem s>
class NavEng {};

template <>
class NavEng<::SatelliteSystem::BeiDou>{
public:
    void catch_subframe_data_D1 (const std::uint32_t(&word)[10], std::uint8_t svId);
    void catch_subframe_data_D2 (const std::uint32_t(&word)[10], std::uint8_t svId);

    typedef union {
        struct {
            uint16_t sbfrm1       : 1;
            uint16_t sbfrm2       : 1;
            uint16_t sbfrm3       : 1;
            uint16_t sbfrm4       : 1;
            uint16_t sbfrm5_1_6   : 1;
            uint16_t sbfrm5_7     : 1;
            uint16_t sbfrm5_8     : 1;
            uint16_t sbfrm5_9     : 1;
            uint16_t sbfrm5_10    : 1;
            uint16_t sbfrm5_11_23 : 1;
            uint16_t sbfrm5_24    : 1;
            uint16_t almanac      : 1;
            uint16_t ephemeris    : 1;
            uint16_t utc          : 1;
            uint16_t ionospher    : 1;
        } new_nav_msg;

        uint16_t u16;
    } yeni_subframe;

    using satId = int;
    int32_t temp_toe;
    std::map<satId, yeni_subframe> new_subframe_map{};
    BeiDouNavData data{}; ///!< BeiDou Navigation Message Data

//private:
    using BeiDouD1Subframe1       = BeiDouSubframe<TrackingCode::B1I_D1, Subframe::one, PageId::None>;
    using BeiDouD1Subframe2       = BeiDouSubframe<TrackingCode::B1I_D1, Subframe::two, PageId::None>;
    using BeiDouD1Subframe3       = BeiDouSubframe<TrackingCode::B1I_D1, Subframe::three, PageId::None>;
    using BeiDouD1Subframe4       = BeiDouSubframe<TrackingCode::B1I_D1, Subframe::four, PageId::None>;
    using BeiDouD1Subframe5_1_6   = BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_1_6>;
    using BeiDouD1Subframe5_7     = BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_7>;
    using BeiDouD1Subframe5_8     = BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_8>;
    using BeiDouD1Subframe5_9     = BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_9>;
    using BeiDouD1Subframe5_10    = BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_10>;
    using BeiDouD1Subframe5_11_23 = BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_11_23>;
    using BeiDouD1Subframe5_24    = BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_24>;

    BeiDouD1Subframe1       D1_Subframe1{};       ///!< B1|D1 Subframe 1
    BeiDouD1Subframe2       D1_Subframe2{};       ///!< B1|D1 Subframe 2
    BeiDouD1Subframe3       D1_Subframe3{};       ///!< B1|D1 Subframe 3
    BeiDouD1Subframe4       D1_Subframe4{};       ///!< B1|D1 Subframe 4
    BeiDouD1Subframe5_1_6   D1_Subframe5_1_6{};   ///!< B1|D1 Subframe 5 and page 1-6
    BeiDouD1Subframe5_7     D1_Subframe5_7{};     ///!< B1|D1 Subframe 5 and page 7
    BeiDouD1Subframe5_8     D1_Subframe5_8{};     ///!< B1|D1 Subframe 5 and page 8
    BeiDouD1Subframe5_9     D1_Subframe5_9{};     ///!< B1|D1 Subframe 5 and page 9
    BeiDouD1Subframe5_10    D1_Subframe5_10{};    ///!< B1|D1 Subframe 5 and page 10
    BeiDouD1Subframe5_11_23 D1_Subframe5_11_23{}; ///!< B1|D1 Subframe 5 and page 11-23
    BeiDouD1Subframe5_24    D1_Subframe5_24{};    ///!< B1|D1 Subframe 5 and page 24
};

#endif /* NAVIGATION_ENGINE_HPP */