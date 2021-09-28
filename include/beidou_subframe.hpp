#ifndef BEIDOU_SUBFRAME_HPP
#define BEIDOU_SUBFRAME_HPP

#include "navigation_base.hpp"
#include "beidou_nav.hpp"

#define PI          3.14159265358979323846
#define exp2_3      8.0
#define exp2_11     2048
#define exp2_14     16384
#define exp2_16     65536
#define exp2_12     4096
#define exp2_n6     0.015625
#define exp2_n11    0.00048828125
#define exp2_n19    0.0000019073486328125
#define exp2_n20    0.00000095367431640625
#define exp2_n21    0.000000476837158203125
#define exp2_n23    0.00000011920928955078125
#define exp2_n24    0.000000059604644775390625
#define exp2_n27    0.000000007450580596923828125
#define exp2_n30    0.000000000931322574615478515625
#define exp2_n31    0.0000000004656612873077392578125
#define exp2_n33    1.16415321826934814453e-10
#define exp2_n38    3.63797880709171295166e-12
#define exp2_n43    1.13686837721616029739e-13
#define exp2_n50    8.88178419700125232338e-16
#define exp2_n66    1.35525271560688054250e-20
#define exp1_n1     0.1
#define exp1_n9     1e-9

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

typedef struct {
    time_t time;
    double sec;
} gtime_t;

class Utils{
public:
    uint32_t merge_two_u(uint32_t, uint32_t, int);
    int32_t merge_two_s(int32_t, uint32_t, int);
    double get_ura_from_urai(uint8_t);
    gtime_t epoch2time(const double *);
    gtime_t bdt2time(int, double);
    gtime_t bdt2gpst(gtime_t, double);
private:
    constexpr static double bdt0[] = {2006,1,1,0,0,0};
};

typedef union{
    struct{
        uint32_t parity_bits        : 4;    // parity bits
        uint32_t sow_msb            : 8;    // seconds of week
        uint32_t fraid              : 3;    // frame id
        uint32_t rev                : 4;    // reserved
        uint32_t pre                : 11;   // preamble
        uint32_t pad                : 2;    // padding
    };

    uint32_t word;
} Word1;

typedef union{
    struct{
        uint32_t parity_bits    : 8;
        uint32_t sqrt_a_msb     : 2;
        uint32_t pnum           : 7;
        uint32_t rev            : 1;
        uint32_t sow_lsb        : 12;
        uint32_t pad            : 2;
    };

    uint32_t word;
} Word2;

template<TrackingCode T, Subframe S, PageId P>
class BeiDouSubframe {};

// SUBFRAME 1
template<>
class BeiDouSubframe<TrackingCode::B1I_D1, Subframe::one, PageId::None>{
public:
    void coz(const std::uint32_t(&word)[10]);
    void anlamlandir(BeiDouNavData&, uint8_t);

private:
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t urai           : 4;    // user range accuracy index
            uint32_t aodc           : 5;    // age of data, clock
            uint32_t sath1          : 1;    // autonomous satellite health flag
            uint32_t sow_lsb        : 12;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word2;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t toc_msb        : 9;
            uint32_t wn             : 13;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word3;
    
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t tgd2_msb        : 4;
            int32_t tgd1            : 10;
            uint32_t toc_lsb        : 8;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word4;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t alpha1          : 8;
            int32_t alpha0          : 8;   
            uint32_t tgd2_lsb       : 6;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word5;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t beta0_msb       : 6;
            int32_t alpha3          : 8;
            int32_t alpha2          : 8;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word6;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t beta3_msb       : 4;
            int32_t beta2           : 8;
            int32_t beta1           : 8;
            uint32_t beta0_lsb      : 2;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word7;

    typedef union{ 
        struct{
            uint32_t parity_bits    : 8;
            int32_t a0_msb          : 7;    // satellite clock bias
            int32_t a2              : 11;
            uint32_t beta3_lsb      : 4;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word8;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t a1_msb          : 5;    // satellite clock rate
            uint32_t a0_lsb         : 17;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word9;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t aode           : 5;    // age of data, ephemeris
            uint32_t a1_lsb         : 17;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

    Utils utils;
    Word1 word1;
    Word2 word2;
    Word3 word3;
    Word4 word4;
    Word5 word5;
    Word6 word6;
    Word7 word7;
    Word8 word8;
    Word9 word9;
    Word10 word10;
};

// SUBFRAME 2
template<>
class BeiDouSubframe<TrackingCode::B1I_D1, Subframe::two, PageId::None>{
public:
    static uint32_t toe1;

    void coz(const std::uint32_t(&word)[10]);
    void anlamlandir(BeiDouNavData&, uint8_t);

//private:
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t delta_n_msb     : 10;
            uint32_t sow_lsb        : 12;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word2;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t cuc_msb         : 16;
            uint32_t delta_n_lsb    : 6;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word3;
    
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t m0_msb          : 20;
            uint32_t cuc_lsb        : 2;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word4;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t e_msb          : 10;
            uint32_t m0_lsb         : 12;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word5;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t e_lsb          : 22;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word6;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t crc_msb         : 4;
            int32_t cus             : 18;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word7;

    typedef union{ 
        struct{
            uint32_t parity_bits    : 8;
            int32_t crs_msb         : 8;
            uint32_t crc_lsb        : 14;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word8;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t sqrt_a_msb     : 12;
            uint32_t crs_lsb        : 10;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word9;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t toe            : 2;
            uint32_t sqrt_a_lsb     : 20;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

    Utils utils;
    Word1 word1;
    Word2 word2;
    Word3 word3;
    Word4 word4;
    Word5 word5;
    Word6 word6;
    Word7 word7;
    Word8 word8;
    Word9 word9;
    Word10 word10;
};

// SUBFRAME 3
template<>
class BeiDouSubframe<TrackingCode::B1I_D1, Subframe::three, PageId::None>{
public:
    void coz(const std::uint32_t(&word)[10]);
    void anlamlandir(BeiDouNavData&, uint8_t);

//private:
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t toe_msb        : 10; // * : These are data bits next to MSBs and before LSBs.
            uint32_t sow_lsb        : 12;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word2;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t i0_msb          : 17;
            uint32_t toe_lsb        : 5;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word3;
    
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t cic_msb         : 7;
            uint32_t i0_lsb         : 15;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word4;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t omega_msb      : 11;
            int32_t cic_lsb        : 11;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word5;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t cis_msb         : 9;
            uint32_t omega_lsb      : 13;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word6;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t idot_msb        : 13;
            uint32_t cis_lsb        : 9;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word7;

    typedef union{ 
        struct{
            uint32_t parity_bits    : 8;
            int32_t omega0_msb      : 21;
            uint32_t idot_lsb       : 1;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word8;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t w_msb           : 11;
            uint32_t omega0_lsb     : 11;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word9;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t rev            : 1;
            uint32_t w_lsb          : 21;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

    Utils utils;
    Word1 word1;
    Word2 word2;
    Word3 word3;
    Word4 word4;
    Word5 word5;
    Word6 word6;
    Word7 word7;
    Word8 word8;
    Word9 word9;
    Word10 word10;
};

// SUBFRAME 4
template<>
class BeiDouSubframe<TrackingCode::B1I_D1, Subframe::four, PageId::None>{
public:
    void coz(const std::uint32_t(&word)[10]);
    void anlamlandir(BeiDouNavData&, uint8_t);

//private:
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t sqrt_a_msb     : 2;
            uint32_t pnum           : 7;
            uint32_t rev            : 1;
            uint32_t sow_lsb        : 12;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word2;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t sqrt_a_lsb     : 22;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word3;
    
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t a0              : 11;
            int32_t a1              : 11;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word4;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t omega0_msb      : 22;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word5;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t delta_i_msb     : 3;
            uint32_t e              : 17;
            uint32_t omega0_lsb     : 2;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word6;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t omega_msb       : 1;
            uint32_t toa            : 8;
            uint32_t delta_i_lsb    : 13;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word7;

    typedef union{ 
        struct{
            uint32_t parity_bits    : 8;
            int32_t w_msb           : 6;
            uint32_t omega_lsb      : 16;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word8;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t m0_msb          : 4;
            uint32_t w_lsb          : 18;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word9;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t amepid         : 2;
            uint32_t m0_lsb         : 20;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

    Utils utils;
    Word1 word1;
    Word2 word2;
    Word3 word3;
    Word4 word4;
    Word5 word5;
    Word6 word6;
    Word7 word7;
    Word8 word8;
    Word9 word9;
    Word10 word10;
};

// SUBFRAME 5 (Page No. 1-6)
template<>
class BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_1_6>{
public:
    void coz(const std::uint32_t(&word)[10]);
    void anlamlandir(BeiDouNavData&, uint8_t);

//private:
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t sqrt_a_msb     : 2;
            uint32_t pnum           : 7;
            uint32_t rev            : 1;
            uint32_t sow_lsb        : 12;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word2;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t sqrt_a_lsb     : 22;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word3;
    
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t a0              : 11;
            int32_t a1              : 11;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word4;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t omega0_msb      : 22;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word5;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t delta_i_msb     : 3;
            uint32_t e              : 17;
            uint32_t omega0_lsb     : 2;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word6;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t omega_msb       : 1;
            uint32_t toa            : 8;
            uint32_t delta_i_lsb    : 13;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word7;

    typedef union{ 
        struct{
            uint32_t parity_bits    : 8;
            int32_t w_msb           : 6;
            uint32_t omega_lsb      : 16;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word8;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t m0_msb          : 4;
            uint32_t w_lsb          : 18;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word9;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t amepid         : 2;
            uint32_t m0_lsb         : 20;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

    Utils utils;
    Word1 word1;
    Word2 word2;
    Word3 word3;
    Word4 word4;
    Word5 word5;
    Word6 word6;
    Word7 word7;
    Word8 word8;
    Word9 word9;
    Word10 word10;
};

// SUBFRAME 5 (Page No. 7)
template<>
class BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_7>{
public:
    void coz(const std::uint32_t(&word)[10]);
    void anlamlandir(BeiDouNavData&, uint8_t);

//private:
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea1_msb       : 2;
            uint32_t pnum           : 7;
            uint32_t rev            : 1;
            uint32_t sow_lsb        : 12;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word2;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea3_msb       : 6;
            uint32_t hea2           : 9;
            uint32_t hea1_lsb       : 7;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word3;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea6_msb       : 1;
            uint32_t hea5           : 9;
            uint32_t hea4           : 9;
            uint32_t hea3_lsb       : 3;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word4;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea8_msb       : 5;
            uint32_t hea7           : 9;
            uint32_t hea6_lsb       : 8;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word5;

    typedef union{
        struct{            
            uint32_t parity_bits    : 8;
            uint32_t hea10          : 9;
            uint32_t hea9           : 9;
            uint32_t hea8_lsb       : 4;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word6;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea13_msb      : 4;
            uint32_t hea12          : 9;
            uint32_t hea11          : 9;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word7;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea15_msb      : 8;
            uint32_t hea14          : 9;
            uint32_t hea13_lsb      : 5;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word8;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea18_msb      : 3;
            uint32_t hea17          : 9;
            uint32_t hea16          : 9;
            uint32_t hea15_lsb      : 1;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word9;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t rev            : 7;
            uint32_t hea19          : 9;
            uint32_t hea18_lsb      : 6;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

    Utils utils;
    Word1 word1;
    Word2 word2;
    Word3 word3;
    Word4 word4;
    Word5 word5;
    Word6 word6;
    Word7 word7;
    Word8 word8;
    Word9 word9;
    Word10 word10;
};

// SUBFRAME 5 (Page No. 8)
template<>
class BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_8>{
public:
    void coz(const std::uint32_t(&word)[10]);
    void anlamlandir(BeiDouNavData&, uint8_t);

//private:
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea20_msb      : 2;
            uint32_t pnum           : 7;
            uint32_t rev            : 1;
            uint32_t sow_lsb        : 12;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word2;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea22_msb      : 6;
            uint32_t hea21          : 9;
            uint32_t hea20_lsb      : 7;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word3;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea25_msb      : 1;
            uint32_t hea24          : 9;
            uint32_t hea23          : 9;
            uint32_t hea22_lsb      : 3;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word4;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea27_msb      : 5;
            uint32_t hea26          : 9;
            uint32_t hea25_lsb      : 8;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word5;

    typedef union{
        struct{            
            uint32_t parity_bits    : 8;
            uint32_t hea29          : 9;
            uint32_t hea28          : 9;
            uint32_t hea27_lsb      : 4;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word6;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t toa_msb        : 5;
            uint32_t wna            : 8;
            uint32_t hea30          : 9;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word7;

    typedef union{
        struct{
            uint32_t rev_msb_1      : 27;
            uint32_t toa_lsb        : 3;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word8;

    typedef union{
        struct{
            uint32_t rev_msb_2      : 30;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word9;

    typedef union{
        struct{
            uint32_t parity_bits    : 24;
            uint32_t rev_lsb        : 6;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

    Utils utils;
    Word1 word1;
    Word2 word2;
    Word3 word3;
    Word4 word4;
    Word5 word5;
    Word6 word6;
    Word7 word7;
    Word8 word8;
    Word9 word9;
    Word10 word10;
};

// SUBFRAME 5 (Page No. 9)
template<>
class BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_9>{
public:
    void coz(const std::uint32_t(&word)[10]);
    void anlamlandir(BeiDouNavData&, uint8_t);

//private:
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t rev2           : 2;
            uint32_t pnum           : 7;
            uint32_t rev1           : 1;
            uint32_t sow_lsb        : 12;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word2;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t rev            : 22;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word3;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t a1gps_msb      : 2;
            uint32_t a0gps          : 14;
            uint32_t rev            : 6;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word4;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t a0gal_msb      : 8;
            uint32_t a1gps_lsb      : 14;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word5;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t a1gal          : 16;
            uint32_t a0gal_lsb      : 6;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word6;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t a1glo_msb      : 8;
            uint32_t a0glo          : 14;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word7;

    typedef union{
        struct{
            uint32_t rev_msb_1      : 22;
            uint32_t a1glo_lsb      : 8;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word8;

    typedef union{
        struct{
            uint32_t rev_msb_2      : 30;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word9;

    typedef union{
        struct{
            uint32_t parity_bits    : 24;
            uint32_t rev_lsb        : 6;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

    Utils utils;
    Word1 word1;
    Word2 word2;
    Word3 word3;
    Word4 word4;
    Word5 word5;
    Word6 word6;
    Word7 word7;
    Word8 word8;
    Word9 word9;
    Word10 word10;
};

// SUBFRAME 5 (Page No. 10)
template<>
class BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_10>{
public:
    void coz(const std::uint32_t(&word)[10]);
    void anlamlandir(BeiDouNavData&, uint8_t);

//private:
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t delta_tls_msb  : 2;
            uint32_t pnum           : 7;
            uint32_t rev            : 1;
            uint32_t sow_lsb        : 12;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word2;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t wnlsf          : 8;
            uint32_t delta_lsf      : 8;
            uint32_t delta_tls_lsb  : 6;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word3;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t a0utc_msb      : 22;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word4;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t a1utc_msb      : 12;
            uint32_t a0utc_lsb      : 10;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word5;

    typedef union{
        struct{
            uint32_t rev_msb_1      : 10;
            uint32_t dn             : 8;
            uint32_t a1utc_lsb      : 12;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word6;

    typedef union{
        struct{
            uint32_t rev_msb_2      : 30;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word7;

    typedef union{
        struct{
            uint32_t rev_msb_3      : 30;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word8;

    typedef union{
        struct{
            uint32_t rev_lsb        : 20;
            uint32_t parity_bits_msb: 10;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word9;

    typedef union{
        struct{
            uint32_t parity_bits_lsb: 30;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

    Utils utils;
    Word1 word1;
    Word2 word2;
    Word3 word3;
    Word4 word4;
    Word5 word5;
    Word6 word6;
    Word7 word7;
    Word8 word8;
    Word9 word9;
    Word10 word10;
};

// SUBFRAME 5 (Page No. 11-23)
template<>
class BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_11_23>{
public:
    uint8_t coz(const std::uint32_t(&word)[10]);
    void anlamlandir(BeiDouNavData&, uint8_t);

//private:
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t sqrt_a_msb     : 2;
            uint32_t pnum           : 7;
            uint32_t rev            : 1;
            uint32_t sow_lsb        : 12;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word2;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t sqrt_a_lsb     : 22;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word3;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t a0              : 11;
            int32_t a1              : 11;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word4;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t omega0_msb      : 22;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word5;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t delta_i_msb     : 3;
            uint32_t e              : 17;
            int32_t omega0_lsb      : 2;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word6;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t omega_msb       : 1;
            uint32_t toa            : 8;
            int32_t delta_i_lsb     : 13;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word7;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t w_msb           : 6;
            uint32_t omega_lsb      : 16;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word8;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            int32_t m0_msb          : 4;
            uint32_t w_lsb          : 18;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word9;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t amid           : 2;
            uint32_t m0_lsb         : 20;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

    Utils utils;
    Word1 word1;
    Word2 word2;
    Word3 word3;
    Word4 word4;
    Word5 word5;
    Word6 word6;
    Word7 word7;
    Word8 word8;
    Word9 word9;
    Word10 word10;
};

// SUBFRAME 5 (Page No. 24)
template<>
class BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_24>{
public:
    void coz(const std::uint32_t(&word)[10]);
    void anlamlandir(BeiDouNavData&, uint8_t);

//private:
    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea31_msb      : 2;
            uint32_t pnum           : 7;
            uint32_t rev            : 1;
            uint32_t sow_lsb        : 12;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word2;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea33_msb      : 6;
            uint32_t hea32          : 9;
            uint32_t hea31_lsb      : 7;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word3;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea36_msb      : 1;
            uint32_t hea35          : 9;
            uint32_t hea34          : 9;
            uint32_t hea33_lsb      : 3;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word4;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea38_msb      : 5;
            uint32_t hea37          : 9;
            uint32_t hea36_lsb      : 8;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word5;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea40          : 9;
            uint32_t hea39          : 9;
            uint32_t hea38_lsb      : 4;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word6;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t hea43_msb      : 4;
            uint32_t hea42          : 9;
            uint32_t hea41          : 9;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word7;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t rev            : 15;
            uint32_t amid           : 2;
            uint32_t hea43_lsb      : 5;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word8;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t rev            : 22;
            uint32_t pad            : 2;
        };
    
        uint32_t word;
    } Word9;

    typedef union{
        struct{
            uint32_t parity_bits    : 8;
            uint32_t rev            : 22;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

    Utils utils;
    Word1 word1;
    Word2 word2;
    Word3 word3;
    Word4 word4;
    Word5 word5;
    Word6 word6;
    Word7 word7;
    Word8 word8;
    Word9 word9;
    Word10 word10;
};

#endif // BEIDOU_SUBFRAME_HPP