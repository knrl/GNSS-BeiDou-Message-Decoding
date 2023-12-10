/*------------------------------------------------------------------------------
*
* @author: Mehmet Kaan Erol
*
------------------------------------------------------------------------------*/

#ifndef NAVIGATION_BASE_HPP
#define NAVIGATION_BASE_HPP

#include <iostream>
#include <type_traits>

enum class SatelliteSystem : std::uint8_t
{
    GPS           = 0,
    SBAS          = 1,
    Galileo       = 2,
    BeiDou        = 3,
    None          = 7,
};

enum class TrackingCode : std::int8_t
{
    B1I_D1    = 0, ///!< BeiDou B1I D2
    B1I_D2    = 1, ///!< BeiDou B1I D2
    B2I_D1    = 2, ///!< BeiDou B2I D1
    B2I_D2    = 3, ///!< BeiDou B2I D2
    None      = -1 ///!< None
};

enum class Subframe : std::int8_t
{
    one                = 1,  ///!< Subframe 1
    two                = 2,  ///!< Subframe 2
    three              = 3,  ///!< Subframe 3
    four               = 4,  ///!< Subframe 4
    five               = 5,  ///!< Subframe 5
    five_p_1_6         = 5,  ///!< Subframe 5 and page 1-6
    five_p_7           = 6,  ///!< Subframe 5 and page 7
    five_p_8           = 7,  ///!< Subframe 5 and page 8
    five_p_9           = 8,  ///!< Subframe 5 and page 9
    five_p_10          = 9,  ///!< Subframe 5 and page 10
    five_p_11_23       = 10, ///!< Subframe 5 and page 11-23
    five_p_24          = 11, ///!< Subframe 5 and page 24
    None               = -1  ///!< None
};

enum class PageId : std::int8_t
{
    page_1_6         = 5,  ///!< page 1-6
    page_7           = 6,  ///!< page 7
    page_8           = 7,  ///!< page 8
    page_9           = 8,  ///!< page 9
    page_10          = 9,  ///!< page 10
    page_11_23       = 10, ///!< page 11-23
    page_24          = 11, ///!< page 24
    None             = -1  ///!< None
};

template<SatelliteSystem s>
struct Almanac {};

template<SatelliteSystem s>
struct Ephemeris {};

template<SatelliteSystem s>
struct UTC {};

template<SatelliteSystem s>
struct Ionosphere {};

template<SatelliteSystem s>
struct TimeOffset {};

extern inline constexpr auto Num_BeiDou_Satellites  = std::integral_constant<std::size_t, 64>::value;

#endif /* NAVIGATION_BASE_HPP */
