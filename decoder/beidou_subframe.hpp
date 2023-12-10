/*------------------------------------------------------------------------------
*
* @author: Mehmet Kaan Erol
*
------------------------------------------------------------------------------*/

#ifndef BEIDOU_SUBFRAME_HPP
#define BEIDOU_SUBFRAME_HPP

#include "navigation_base.hpp"
#include "beidou_nav.hpp"
#include "utils.hpp"

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
    void decode(const std::uint32_t(&word)[10]);
    void compute(BeiDouNavData&, uint8_t) const;

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
            int32_t wn              : 13;
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

    void decode(const std::uint32_t(&word)[10]);
    void compute(BeiDouNavData&, uint8_t) const;

private:
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
    void decode(const std::uint32_t(&word)[10]);
    void compute(BeiDouNavData&, uint8_t) const;

private:
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
    void decode(const std::uint32_t(&word)[10]);
    void compute(BeiDouNavData&, uint8_t) const;

private:
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
            int8_t amepid           : 2;
            uint32_t m0_lsb         : 20;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

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
    void decode(const std::uint32_t(&word)[10]);
    void compute(BeiDouNavData&, uint8_t) const;

private:
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
            int8_t amepid           : 2;
            uint32_t m0_lsb         : 20;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

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
    void decode(const std::uint32_t(&word)[10]);
    void compute(BeiDouNavData&, uint8_t) const;

private:
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
    void decode(const std::uint32_t(&word)[10]);
    void compute(BeiDouNavData&, uint8_t) const;

private:
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
            int32_t wna             : 8;
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
    void decode(const std::uint32_t(&word)[10]);
    void compute(BeiDouNavData&, uint8_t) const;

private:
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
    void decode(const std::uint32_t(&word)[10]);
    void compute(BeiDouNavData&, uint8_t) const;

private:
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
    uint8_t decode(const std::uint32_t(&word)[10]);
    void compute(BeiDouNavData&, uint8_t) const;

private:
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
            int8_t amid             : 2;
            uint32_t m0_lsb         : 20;
            uint32_t pad            : 2;
        };

        uint32_t word;
    } Word10;

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
    void decode(const std::uint32_t(&word)[10]);
    void compute(BeiDouNavData&, uint8_t) const;

private:
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
