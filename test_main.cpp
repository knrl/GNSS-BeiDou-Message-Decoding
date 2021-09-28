/*------------------------------------------------------------------------------
*
* @author: Mehmet Kaan Erol
*
------------------------------------------------------------------------------*/

#include "include/navigation_engine.hpp"
#include "gtest/gtest.h"

/**
 * ASSERT: Fails fast, aborting the current function. 
 * EXPECT: Continues after the failure.
 * 
 * 
 */

typedef struct{
    uint32_t word[10];
} Payload;

NavEng<SatelliteSystem::BeiDou> BeiDouEng;

class D1_Test: public ::testing::Test { 
public: 
   D1_Test( ) { 
       // initialization code here
   } 

   void SetUp( ) { 
       // code here will execute just before the test ensues 
   }

   void TearDown( ) { 
       // code here will be called just after the test completes
       // ok to through exceptions from here if need be
   }

   ~D1_Test( )  { 
       // cleanup any pending stuff, but no exceptions allowed
   }

   // put in any custom data members that you need 
};

class Utils_Test: public ::testing::Test { 
public: 
   Utils_Test( ) { 
       // initialization code here
   } 

   void SetUp( ) { 
       // code here will execute just before the test ensues 
   }

   void TearDown( ) { 
       // code here will be called just after the test completes
       // ok to through exceptions from here if need be
   }

   ~Utils_Test( )  { 
       // cleanup any pending stuff, but no exceptions allowed
   }

   // put in any custom data members that you need 
};

TEST(D1_test, init_test_nav_data)
{
    uint8_t svId = 0;
    NavEng<SatelliteSystem::BeiDou> temp_BeiDouEng;         
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].a0_s_f64);            
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].a1_ss_f64);           
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].svId_u8);            
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].svHealth_u8);        
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].week_s32);           
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].BDTweek_s32);        
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].uraIndex_u8);        
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].ura_f64);             
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].AODE_f64);            
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].AODC_u16);          
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].toe1);
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].tgd1_s_f64);           
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].tgd2_s_f64);           
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].Toe);                  
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].Toc);                  
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].Sow);                  
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].a0_s_f64);             
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].a1_ss_f64);            
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].a2_ss2_f64);           
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].sqrtA_f64);            
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].OMGdot_rad_f64);       
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].deltaN_rad_sec_f64);   
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].m0_rad_f64);           
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].ecc_f64);              
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].omega_rad_f64);        
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].omega0_rad_f64);       
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].i0_rad_f64);           
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].IDOT_rad_sec_f64);     
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].Cis_rad_f64);          
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].Cic_rad_f64);          
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].Crs_m_f64);            
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].Crc_m_f64);            
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].Cus_rad_f64);          
    EXPECT_EQ(0, temp_BeiDouEng.data.eph[svId].Cuc_rad_f64);          
    EXPECT_EQ(0, temp_BeiDouEng.data.utc.A0utc_s_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.utc.A1utc_ss_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.utc.A0gps_s_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.utc.A1gps_ss_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.utc.A0glo_s_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.utc.A1glo_ss_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.utc.A0gal_s_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.utc.A1gal_ss_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.utc.DtLS_s_f64);     
    EXPECT_EQ(0, temp_BeiDouEng.data.utc.WNt_f64);    
    EXPECT_EQ(0, temp_BeiDouEng.data.utc.WNlsf_f64);  
    EXPECT_EQ(0, temp_BeiDouEng.data.utc.Dn_f64);     
    EXPECT_EQ(0, temp_BeiDouEng.data.utc.DtLSF_s_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.iono.alpha0_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.iono.alpha2_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.iono.alpha3_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.iono.beta0_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.iono.beta2_f64);
    EXPECT_EQ(0, temp_BeiDouEng.data.iono.beta3_f64);
}

TEST(D1_Test, subframe1_coz)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38901758;
    payload.word[1] = 0x14e81025;
    payload.word[2] = 0x658e97b;
    payload.word[3] = 0x3287a16c;
    payload.word[4] = 0x3a0807f9;
    payload.word[5] = 0x3e42cf96;
    payload.word[6] = 0x1f41cea7;
    payload.word[7] = 0x28003c68;
    payload.word[8] = 0x355700db;
    payload.word[9] = 0x7ce21ed;

    /// ACT
    BeiDouEng.D1_Subframe1.coz(payload.word);

    /// ASSERT
    EXPECT_EQ(payload.word[0], BeiDouEng.D1_Subframe1.word1.word);
    EXPECT_EQ(payload.word[1], BeiDouEng.D1_Subframe1.word2.word);
    EXPECT_EQ(payload.word[2], BeiDouEng.D1_Subframe1.word3.word);
    EXPECT_EQ(payload.word[3], BeiDouEng.D1_Subframe1.word4.word);
    EXPECT_EQ(payload.word[4], BeiDouEng.D1_Subframe1.word5.word);
    EXPECT_EQ(payload.word[5], BeiDouEng.D1_Subframe1.word6.word);
    EXPECT_EQ(payload.word[6], BeiDouEng.D1_Subframe1.word7.word);
    EXPECT_EQ(payload.word[7], BeiDouEng.D1_Subframe1.word8.word);
    EXPECT_EQ(payload.word[8], BeiDouEng.D1_Subframe1.word9.word);
    EXPECT_EQ(payload.word[9], BeiDouEng.D1_Subframe1.word10.word);
}

TEST(D1_Test, subframe2_coz)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x3890275a;
    payload.word[1] = 0x14882a57;
    payload.word[2] = 0x2bf570fe;
    payload.word[3] = 0x19161fe3;
    payload.word[4] = 0x29ac1765;
    payload.word[5] = 0xba5e5ba;
    payload.word[6] = 0xa50ae55;
    payload.word[7] = 0x2435f6da;
    payload.word[8] = 0x6bcae5c;
    payload.word[9] = 0x3f24394e;

    /// ACT
    BeiDouEng.D1_Subframe1.coz(payload.word);

    /// ASSERT
    EXPECT_EQ(payload.word[0], BeiDouEng.D1_Subframe1.word1.word);
    EXPECT_EQ(payload.word[1], BeiDouEng.D1_Subframe1.word2.word);
    EXPECT_EQ(payload.word[2], BeiDouEng.D1_Subframe1.word3.word);
    EXPECT_EQ(payload.word[3], BeiDouEng.D1_Subframe1.word4.word);
    EXPECT_EQ(payload.word[4], BeiDouEng.D1_Subframe1.word5.word);
    EXPECT_EQ(payload.word[5], BeiDouEng.D1_Subframe1.word6.word);
    EXPECT_EQ(payload.word[6], BeiDouEng.D1_Subframe1.word7.word);
    EXPECT_EQ(payload.word[7], BeiDouEng.D1_Subframe1.word8.word);
    EXPECT_EQ(payload.word[8], BeiDouEng.D1_Subframe1.word9.word);
    EXPECT_EQ(payload.word[9], BeiDouEng.D1_Subframe1.word10.word);
}

TEST(D1_Test, subframe3_coz)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38903755;
    payload.word[1] = 0x14a34ea4;
    payload.word[2] = 0x144d0bb8;
    payload.word[3] = 0xb63ff56;
    payload.word[4] = 0x26bfffcf;
    payload.word[5] = 0x190fffbf;
    payload.word[6] = 0x145ecedc;
    payload.word[7] = 0x15007893;
    payload.word[8] = 0xad53802;
    payload.word[9] = 0x39fd626d;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_EQ(payload.word[0], BeiDouEng.D1_Subframe3.word1.word);
    EXPECT_EQ(payload.word[1], BeiDouEng.D1_Subframe3.word2.word);
    EXPECT_EQ(payload.word[2], BeiDouEng.D1_Subframe3.word3.word);
    EXPECT_EQ(payload.word[3], BeiDouEng.D1_Subframe3.word4.word);
    EXPECT_EQ(payload.word[4], BeiDouEng.D1_Subframe3.word5.word);
    EXPECT_EQ(payload.word[5], BeiDouEng.D1_Subframe3.word6.word);
    EXPECT_EQ(payload.word[6], BeiDouEng.D1_Subframe3.word7.word);
    EXPECT_EQ(payload.word[7], BeiDouEng.D1_Subframe3.word8.word);
    EXPECT_EQ(payload.word[8], BeiDouEng.D1_Subframe3.word9.word);
    EXPECT_EQ(payload.word[9], BeiDouEng.D1_Subframe3.word10.word);
}

TEST(D1_Test, subframe4_coz)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x3890475e;
    payload.word[1] = 0x14b82efb;
    payload.word[2] = 0x25148db3;
    payload.word[3] = 0x31f9a1;
    payload.word[4] = 0xae91d9e;
    payload.word[5] = 0x7c782a;
    payload.word[6] = 0x3e7c6107;
    payload.word[7] = 0x3f726a9d;
    payload.word[8] = 0x354b148b;
    payload.word[9] = 0x3ef48164;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_EQ(payload.word[0], BeiDouEng.D1_Subframe4.word1.word);
    EXPECT_EQ(payload.word[1], BeiDouEng.D1_Subframe4.word2.word);
    EXPECT_EQ(payload.word[2], BeiDouEng.D1_Subframe4.word3.word);
    EXPECT_EQ(payload.word[3], BeiDouEng.D1_Subframe4.word4.word);
    EXPECT_EQ(payload.word[4], BeiDouEng.D1_Subframe4.word5.word);
    EXPECT_EQ(payload.word[5], BeiDouEng.D1_Subframe4.word6.word);
    EXPECT_EQ(payload.word[6], BeiDouEng.D1_Subframe4.word7.word);
    EXPECT_EQ(payload.word[7], BeiDouEng.D1_Subframe4.word8.word);
    EXPECT_EQ(payload.word[8], BeiDouEng.D1_Subframe4.word9.word);
    EXPECT_EQ(payload.word[9], BeiDouEng.D1_Subframe4.word10.word);
}

TEST(D1_Test, subframe5_1_6_coz)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38905751;
    payload.word[1] = 0x12781a88;
    payload.word[2] = 0x251491b1;
    payload.word[3] = 0x1f30c;
    payload.word[4] = 0xa6d82ce;
    payload.word[5] = 0x101b2883;
    payload.word[6] = 0x1d906b53;
    payload.word[7] = 0x3f6a86c9;
    payload.word[8] = 0x2eb28e02;
    payload.word[9] = 0x787a16c;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_EQ(payload.word[0], BeiDouEng.D1_Subframe5_1_6.word1.word);
    EXPECT_EQ(payload.word[1], BeiDouEng.D1_Subframe5_1_6.word2.word);
    EXPECT_EQ(payload.word[2], BeiDouEng.D1_Subframe5_1_6.word3.word);
    EXPECT_EQ(payload.word[3], BeiDouEng.D1_Subframe5_1_6.word4.word);
    EXPECT_EQ(payload.word[4], BeiDouEng.D1_Subframe5_1_6.word5.word);
    EXPECT_EQ(payload.word[5], BeiDouEng.D1_Subframe5_1_6.word6.word);
    EXPECT_EQ(payload.word[6], BeiDouEng.D1_Subframe5_1_6.word7.word);
    EXPECT_EQ(payload.word[7], BeiDouEng.D1_Subframe5_1_6.word8.word);
    EXPECT_EQ(payload.word[8], BeiDouEng.D1_Subframe5_1_6.word9.word);
    EXPECT_EQ(payload.word[9], BeiDouEng.D1_Subframe5_1_6.word10.word);
}

TEST(D1_Test, subframe5_7_coz)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38905751;
    payload.word[1] = 0x12f01ce2;
    payload.word[2] = 0x0;
    payload.word[3] = 0x0;
    payload.word[4] = 0x0;
    payload.word[5] = 0x0;
    payload.word[6] = 0x0;
    payload.word[7] = 0xff04;
    payload.word[8] = 0x80739;
    payload.word[9] = 0x3e2c2ade;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_EQ(payload.word[0], BeiDouEng.D1_Subframe5_7.word1.word);
    EXPECT_EQ(payload.word[1], BeiDouEng.D1_Subframe5_7.word2.word);
    EXPECT_EQ(payload.word[2], BeiDouEng.D1_Subframe5_7.word3.word);
    EXPECT_EQ(payload.word[3], BeiDouEng.D1_Subframe5_7.word4.word);
    EXPECT_EQ(payload.word[4], BeiDouEng.D1_Subframe5_7.word5.word);
    EXPECT_EQ(payload.word[5], BeiDouEng.D1_Subframe5_7.word6.word);
    EXPECT_EQ(payload.word[6], BeiDouEng.D1_Subframe5_7.word7.word);
    EXPECT_EQ(payload.word[7], BeiDouEng.D1_Subframe5_7.word8.word);
    EXPECT_EQ(payload.word[8], BeiDouEng.D1_Subframe5_7.word9.word);
    EXPECT_EQ(payload.word[9], BeiDouEng.D1_Subframe5_7.word10.word);
}

TEST(D1_Test, subframe5_8_coz)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38905751;
    payload.word[1] = 0x1368204a;
    payload.word[2] = 0x2c160bea;
    payload.word[3] = 0x160b0d1;
    payload.word[4] = 0x160b057d;
    payload.word[5] = 0x20b05869;
    payload.word[6] = 0xb058622;
    payload.word[7] = 0x2aaaaab4;
    payload.word[8] = 0x2aaaaab4;
    payload.word[9] = 0x2aaaaab4;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_EQ(payload.word[0], BeiDouEng.D1_Subframe5_8.word1.word);
    EXPECT_EQ(payload.word[1], BeiDouEng.D1_Subframe5_8.word2.word);
    EXPECT_EQ(payload.word[2], BeiDouEng.D1_Subframe5_8.word3.word);
    EXPECT_EQ(payload.word[3], BeiDouEng.D1_Subframe5_8.word4.word);
    EXPECT_EQ(payload.word[4], BeiDouEng.D1_Subframe5_8.word5.word);
    EXPECT_EQ(payload.word[5], BeiDouEng.D1_Subframe5_8.word6.word);
    EXPECT_EQ(payload.word[6], BeiDouEng.D1_Subframe5_8.word7.word);
    EXPECT_EQ(payload.word[7], BeiDouEng.D1_Subframe5_8.word8.word);
    EXPECT_EQ(payload.word[8], BeiDouEng.D1_Subframe5_8.word9.word);
    EXPECT_EQ(payload.word[9], BeiDouEng.D1_Subframe5_8.word10.word);
}

TEST(D1_Test, subframe5_9_coz)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38905751;
    payload.word[1] = 0x13e02426;
    payload.word[2] = 0x0;
    payload.word[3] = 0x0;
    payload.word[4] = 0x0;
    payload.word[5] = 0x0;
    payload.word[6] = 0x0;
    payload.word[7] = 0x15556b;
    payload.word[8] = 0x1555554b;
    payload.word[9] = 0x1555554b;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_EQ(payload.word[0], BeiDouEng.D1_Subframe5_9.word1.word);
    EXPECT_EQ(payload.word[1], BeiDouEng.D1_Subframe5_9.word2.word);
    EXPECT_EQ(payload.word[2], BeiDouEng.D1_Subframe5_9.word3.word);
    EXPECT_EQ(payload.word[3], BeiDouEng.D1_Subframe5_9.word4.word);
    EXPECT_EQ(payload.word[4], BeiDouEng.D1_Subframe5_9.word5.word);
    EXPECT_EQ(payload.word[5], BeiDouEng.D1_Subframe5_9.word6.word);
    EXPECT_EQ(payload.word[6], BeiDouEng.D1_Subframe5_9.word7.word);
    EXPECT_EQ(payload.word[7], BeiDouEng.D1_Subframe5_9.word8.word);
    EXPECT_EQ(payload.word[8], BeiDouEng.D1_Subframe5_9.word9.word);
    EXPECT_EQ(payload.word[9], BeiDouEng.D1_Subframe5_9.word10.word);
}

TEST(D1_Test, subframe5_10_coz)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38905751;
    payload.word[1] = 0x145828d1;
    payload.word[2] = 0x4043de2;
    payload.word[3] = 0x3fffffff;
    payload.word[4] = 0x3fcfff5f;
    payload.word[5] = 0x3fa41817;
    payload.word[6] = 0x0;
    payload.word[7] = 0x0;
    payload.word[8] = 0x0;
    payload.word[9] = 0x0;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_EQ(payload.word[0], BeiDouEng.D1_Subframe5_10.word1.word);
    EXPECT_EQ(payload.word[1], BeiDouEng.D1_Subframe5_10.word2.word);
    EXPECT_EQ(payload.word[2], BeiDouEng.D1_Subframe5_10.word3.word);
    EXPECT_EQ(payload.word[3], BeiDouEng.D1_Subframe5_10.word4.word);
    EXPECT_EQ(payload.word[4], BeiDouEng.D1_Subframe5_10.word5.word);
    EXPECT_EQ(payload.word[5], BeiDouEng.D1_Subframe5_10.word6.word);
    EXPECT_EQ(payload.word[6], BeiDouEng.D1_Subframe5_10.word7.word);
    EXPECT_EQ(payload.word[7], BeiDouEng.D1_Subframe5_10.word8.word);
    EXPECT_EQ(payload.word[8], BeiDouEng.D1_Subframe5_10.word9.word);
    EXPECT_EQ(payload.word[9], BeiDouEng.D1_Subframe5_10.word10.word);
}

TEST(D1_Test, subframe1_anlamlandir)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38901758;
    payload.word[1] = 0x14e81025;
    payload.word[2] = 0x658e97b;
    payload.word[3] = 0x3287a16c;
    payload.word[4] = 0x3a0807f9;
    payload.word[5] = 0x3e42cf96;
    payload.word[6] = 0x1f41cea7;
    payload.word[7] = 0x28003c68;
    payload.word[8] = 0x355700db;
    payload.word[9] = 0x7ce21ed;

    const double Toc = 4.78800000000000000000e+05;
    const double a0_s_f64 = 9.28244553506374359131e-04;
    const double a1_ss_f64 = 1.41975320389065018389e-11;
    const double a2_ss2_f64 = 0.00000000000000000000e+00;
    const double AODE_f64 = 1.00000000000000000000e+00;
    const double BDTweek_s32 = 812;
    const uint8_t svHealth_u8 = 0;
    const double tgd1_s_f64 = 1.22000000000000017111e-08;
    const uint16_t AODC_u16 = 1;
    const double Sow = 4.80570000000000000000e+05;
    const double alpha0_f64 = 7.45058059692382812500e-09;
    const double alpha1_f64 = 5.21540641784667968750e-08;
    const double alpha2_f64 = -4.17232513427734375000e-07;
    const double alpha3_f64 = 6.55651092529296875000e-07;
    const double beta0_f64 = 1.24928000000000000000e+05;
    const double beta1_f64 = -1.96608000000000000000e+05;
    const double beta2_f64 = 1.83500800000000000000e+06;
    const double beta3_f64 = 4.29352550400000000000e+09;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    // ASSERT
    EXPECT_NEAR(Toc, BeiDouEng.data.eph[svId-1].Toc, 0.000001);
    EXPECT_NEAR(a0_s_f64, BeiDouEng.data.eph[svId-1].a0_s_f64, 0.000001);
    EXPECT_NEAR(a1_ss_f64, BeiDouEng.data.eph[svId-1].a1_ss_f64, 0.000001);
    EXPECT_NEAR(a2_ss2_f64, BeiDouEng.data.eph[svId-1].a2_ss2_f64, 0.000001);
    EXPECT_NEAR(AODE_f64, BeiDouEng.data.eph[svId-1].AODE_f64, 0.000001);
    EXPECT_NEAR(BDTweek_s32, BeiDouEng.data.eph[svId-1].BDTweek_s32, 0.000001);
    EXPECT_EQ(svHealth_u8, BeiDouEng.data.eph[svId-1].svHealth_u8);
    EXPECT_NEAR(tgd1_s_f64, BeiDouEng.data.eph[svId-1].tgd1_s_f64, 0.000001);
    EXPECT_EQ(AODC_u16, BeiDouEng.data.eph[svId-1].AODC_u16);
    EXPECT_NEAR(Sow, BeiDouEng.data.eph[svId-1].Sow, 0.000001);
    EXPECT_NEAR(alpha0_f64, BeiDouEng.data.iono.alpha0_f64, 0.000001);
    EXPECT_NEAR(alpha1_f64, BeiDouEng.data.iono.alpha1_f64, 0.000001);
    EXPECT_NEAR(alpha2_f64, BeiDouEng.data.iono.alpha2_f64, 0.000001);
    EXPECT_NEAR(alpha3_f64, BeiDouEng.data.iono.alpha3_f64, 0.000001);
    EXPECT_NEAR(beta0_f64, BeiDouEng.data.iono.beta0_f64, 0.000001);
    EXPECT_NEAR(beta1_f64, BeiDouEng.data.iono.beta1_f64, 0.000001);
    EXPECT_NEAR(beta2_f64, BeiDouEng.data.iono.beta2_f64, 0.000001);
    EXPECT_NEAR(beta3_f64, BeiDouEng.data.iono.beta3_f64, 0.000001);
}


TEST(D1_Test, subframe2_anlamlandir)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x3890275a;
    payload.word[1] = 0x14882a57;
    payload.word[2] = 0x2bf570fe;
    payload.word[3] = 0x19161fe3;
    payload.word[4] = 0x29ac1765;
    payload.word[5] = 0xba5e5ba;
    payload.word[6] = 0xa50ae55;
    payload.word[7] = 0x2435f6da;
    payload.word[8] = 0x6bcae5c;
    payload.word[9] = 0x3f24394e;

    const double Crs_m_f64 = -1.58328125000000000000e+02;
    const double deltaN_rad_sec_f64 = 9.75397772089505123168e-10;
    const double m0_rad_f64 = -2.71495633746903441974e+00;
    const double Cuc_rad_f64 = -5.03612682223320007324e-06;
    const double ecc_f64 = 1.13193361321464180946e-02;
    const double Cus_rad_f64 = 1.96741893887519836426e-05;
    const double sqrtA_f64 = 6.49397317123413085938e+03;
    const double Crc_m_f64 = -3.67171875000000000000e+02;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    // ASSERT
    EXPECT_NEAR(Crs_m_f64, BeiDouEng.data.eph[svId-1].Crs_m_f64, 0.000001);
    EXPECT_NEAR(deltaN_rad_sec_f64, BeiDouEng.data.eph[svId-1].deltaN_rad_sec_f64, 0.000001);
    EXPECT_NEAR(m0_rad_f64, BeiDouEng.data.eph[svId-1].m0_rad_f64, 0.000001);
    EXPECT_NEAR(Cuc_rad_f64, BeiDouEng.data.eph[svId-1].Cuc_rad_f64, 0.000001);
    EXPECT_NEAR(ecc_f64, BeiDouEng.data.eph[svId-1].ecc_f64, 0.000001);
    EXPECT_NEAR(Cus_rad_f64, BeiDouEng.data.eph[svId-1].Cus_rad_f64, 0.000001);
    EXPECT_NEAR(sqrtA_f64, BeiDouEng.data.eph[svId-1].sqrtA_f64, 0.000001);
    EXPECT_NEAR(Crc_m_f64, BeiDouEng.data.eph[svId-1].Crc_m_f64, 0.000001);
}

TEST(D1_Test, subframe3_anlamlandir)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38903755;
    payload.word[1] = 0x14a34ea4;
    payload.word[2] = 0x144d0bb8;
    payload.word[3] = 0xb63ff56;
    payload.word[4] = 0x26bfffcf;
    payload.word[5] = 0x190fffbf;
    payload.word[6] = 0x145ecedc;
    payload.word[7] = 0x15007893;
    payload.word[8] = 0xad53802;
    payload.word[9] = 0x39fd626d;

    const double Toe = 4.78800000000000000000e+05;
    const double Cic_rad_f64 = -1.33039429783821105957e-06;
    const double omega0_rad_f64 = -2.15948491642616646757e+00;
    const double Cis_rad_f64 = -1.62981450557708740234e-07;
    const double i0_rad_f64 = 9.45468001508710909064e-01;
    const double omega_rad_f64 = -2.18160879184866685065e+00;
    const double OMGdot_rad_f64 = -1.78043130496747830349e-09;
    const double IDOT_rad_sec_f64 = -2.18580533328003350339e-10;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_NEAR(Toe, BeiDouEng.data.eph[svId-1].Toe, 0.000001);
    EXPECT_NEAR(omega0_rad_f64, BeiDouEng.data.eph[svId-1].omega0_rad_f64, 0.000001);
    EXPECT_NEAR(Cis_rad_f64, BeiDouEng.data.eph[svId-1].Cis_rad_f64, 0.000001);
    EXPECT_NEAR(i0_rad_f64, BeiDouEng.data.eph[svId-1].i0_rad_f64, 0.000001);
    EXPECT_NEAR(omega_rad_f64, BeiDouEng.data.eph[svId-1].omega_rad_f64, 0.000001);
    EXPECT_NEAR(OMGdot_rad_f64, BeiDouEng.data.eph[svId-1].OMGdot_rad_f64, 0.000001);
    EXPECT_NEAR(IDOT_rad_sec_f64, BeiDouEng.data.eph[svId-1].IDOT_rad_sec_f64, 0.000001);
}

TEST(D1_Test, subframe4_anlamlandir)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x3890475e;
    payload.word[1] = 0x14b82efb;
    payload.word[2] = 0x25148db3;
    payload.word[3] = 0x31f9a1;
    payload.word[4] = 0xae91d9e;
    payload.word[5] = 0x7c782a;
    payload.word[6] = 0x3e7c6107;
    payload.word[7] = 0x3f726a9d;
    payload.word[8] = 0x354b148b;
    payload.word[9] = 0x3ef48164;

    const double toa_sn_f64 = 1.96608000000000000000e+05;
    const double a0_s_f64 = 4.81605529785156250000e-04;
    const double a1_ss_f64 = 2.18278728425502777100e-11;
    const double deltai_rad_f64 = 4.79249153965209326311e-02;
    const double ecc_f64 = 1.89924240112304687500e-03;
    const double omg0_rad_f64 = 1.07114552795643080962e+00;
    const double omg_rad_f64 = -2.07809418464406459037e+00;
    const double sqrtA_m_f64 = 5.28256884765625000000e+03;
    const double m0_rad_f64 = 1.95708384816925495819e+00;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_NEAR(toa_sn_f64, BeiDouEng.data.alm[svId-1].toa_sn_f64, 0.000001);
    EXPECT_NEAR(a0_s_f64, BeiDouEng.data.alm[svId-1].a0_s_f64, 0.000001);
    EXPECT_NEAR(a1_ss_f64, BeiDouEng.data.alm[svId-1].a1_ss_f64, 0.000001);
    EXPECT_NEAR(deltai_rad_f64, BeiDouEng.data.alm[svId-1].deltai_rad_f64, 0.000001);
    EXPECT_NEAR(ecc_f64, BeiDouEng.data.alm[svId-1].ecc_f64, 0.000001);
    EXPECT_NEAR(omg0_rad_f64, BeiDouEng.data.alm[svId-1].omg0_rad_f64, 0.000001);
    EXPECT_NEAR(omg_rad_f64, BeiDouEng.data.alm[svId-1].omg_rad_f64, 0.000001);
    EXPECT_NEAR(sqrtA_m_f64, BeiDouEng.data.alm[svId-1].sqrtA_m_f64, 0.000001);
    EXPECT_NEAR(m0_rad_f64, BeiDouEng.data.alm[svId-1].m0_rad_f64, 0.000001);
}

TEST(D1_Test, subframe5_1_6_anlamlandir)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38905751;
    payload.word[1] = 0x12781a88;
    payload.word[2] = 0x251491b1;
    payload.word[3] = 0x1f30c;
    payload.word[4] = 0xa6d82ce;
    payload.word[5] = 0x101b2883;
    payload.word[6] = 0x1d906b53;
    payload.word[7] = 0x3f6a86c9;
    payload.word[8] = 0x2eb28e02;
    payload.word[9] = 0x787a16c;

    const double toa_sn_f64 = 2.17088000000000000000e+05;
    const double a0_s_f64 = 4.75883483886718750000e-04;
    const double a1_ss_f64 = 0.00000000000000000000e+00 ;
    const double deltai_rad_f64 = 2.26741535209346346813e-02;
    const double ecc_f64 = 4.14371490478515625000e-04;
    const double omg0_rad_f64 = 1.02374379887843436343e+00;
    const double omg_rad_f64 = 6.60681330863628790695e-01;
    const double sqrtA_m_f64 = 5.28257080078125000000e+03;
    const double m0_rad_f64 = -7.39195980331072366454e-01;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_NEAR(toa_sn_f64, BeiDouEng.data.alm[svId-1].toa_sn_f64, 0.000001);
    EXPECT_NEAR(a0_s_f64, BeiDouEng.data.alm[svId-1].a0_s_f64, 0.000001);
    EXPECT_NEAR(a1_ss_f64, BeiDouEng.data.alm[svId-1].a1_ss_f64, 0.000001);
    EXPECT_NEAR(deltai_rad_f64, BeiDouEng.data.alm[svId-1].deltai_rad_f64, 0.000001);
    EXPECT_NEAR(ecc_f64, BeiDouEng.data.alm[svId-1].ecc_f64, 0.000001);
    EXPECT_NEAR(omg0_rad_f64, BeiDouEng.data.alm[svId-1].omg0_rad_f64, 0.000001);
    EXPECT_NEAR(omg_rad_f64, BeiDouEng.data.alm[svId-1].omg_rad_f64, 0.000001);
    EXPECT_NEAR(sqrtA_m_f64, BeiDouEng.data.alm[svId-1].sqrtA_m_f64, 0.000001);
    EXPECT_NEAR(m0_rad_f64, BeiDouEng.data.alm[svId-1].m0_rad_f64, 0.000001);
}

TEST(D1_Test, subframe5_7_anlamlandir)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38905751;
    payload.word[1] = 0x12f01ce2;
    payload.word[2] = 0x0;
    payload.word[3] = 0x0;
    payload.word[4] = 0x0;
    payload.word[5] = 0x0;
    payload.word[6] = 0x0;
    payload.word[7] = 0xff04;
    payload.word[8] = 0x80739;
    payload.word[9] = 0x3e2c2ade;
   
    const uint8_t health[19] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0xfe, 0, 0, 0xfe, 0x58};

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_EQ(health[0], BeiDouEng.data.health[0]);
    EXPECT_EQ(health[1], BeiDouEng.data.health[1]);
    EXPECT_EQ(health[2], BeiDouEng.data.health[2]);
    EXPECT_EQ(health[3], BeiDouEng.data.health[3]);
    EXPECT_EQ(health[4], BeiDouEng.data.health[4]);
    EXPECT_EQ(health[5], BeiDouEng.data.health[5]);
    EXPECT_EQ(health[6], BeiDouEng.data.health[6]);
    EXPECT_EQ(health[7], BeiDouEng.data.health[7]);
    EXPECT_EQ(health[8], BeiDouEng.data.health[8]);
    EXPECT_EQ(health[9], BeiDouEng.data.health[9]);
    EXPECT_EQ(health[10], BeiDouEng.data.health[10]);
    EXPECT_EQ(health[11], BeiDouEng.data.health[11]);
    EXPECT_EQ(health[12], BeiDouEng.data.health[12]);
    EXPECT_EQ(health[13], BeiDouEng.data.health[13]);
    EXPECT_EQ(health[14], BeiDouEng.data.health[14]);
    EXPECT_EQ(health[15], BeiDouEng.data.health[15]);
    EXPECT_EQ(health[16], BeiDouEng.data.health[16]);
    EXPECT_EQ(health[17], BeiDouEng.data.health[17]);
    EXPECT_EQ(health[18], BeiDouEng.data.health[18]);
}

TEST(D1_Test, subframe5_8_anlamlandir)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38905751;
    payload.word[1] = 0x1368204a;
    payload.word[2] = 0x2c160bea;
    payload.word[3] = 0x160b0d1;
    payload.word[4] = 0x160b057d;
    payload.word[5] = 0x20b05869;
    payload.word[6] = 0xb058622;
    payload.word[7] = 0x2aaaaab4;
    payload.word[8] = 0x2aaaaab4;
    payload.word[9] = 0x2aaaaab4;

    const uint8_t health[12] = {0, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58, 0x58};
    const uint32_t week_s32 = 0x2c;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_EQ(health[0], BeiDouEng.data.health[19]);
    EXPECT_EQ(health[1], BeiDouEng.data.health[20]);
    EXPECT_EQ(health[2], BeiDouEng.data.health[21]);
    EXPECT_EQ(health[3], BeiDouEng.data.health[22]);
    EXPECT_EQ(health[4], BeiDouEng.data.health[23]);
    EXPECT_EQ(health[5], BeiDouEng.data.health[24]);
    EXPECT_EQ(health[6], BeiDouEng.data.health[25]);
    EXPECT_EQ(health[7], BeiDouEng.data.health[26]);
    EXPECT_EQ(health[8], BeiDouEng.data.health[27]);
    EXPECT_EQ(health[9], BeiDouEng.data.health[28]);
    EXPECT_EQ(health[10], BeiDouEng.data.health[29]);
    EXPECT_EQ(health[11], BeiDouEng.data.health[30]);
    EXPECT_EQ(week_s32, BeiDouEng.data.alm[svId-1].week_s32);
}

TEST(D1_Test, subframe5_9_anlamlandir)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38905751;
    payload.word[1] = 0x13e02426;
    payload.word[2] = 0x0;
    payload.word[3] = 0x0;
    payload.word[4] = 0x0;
    payload.word[5] = 0x0;
    payload.word[6] = 0x0;
    payload.word[7] = 0x15556b;
    payload.word[8] = 0x1555554b;
    payload.word[9] = 0x1555554b;

    const double A0gps_s_f64 = 0;
    const double A1gps_ss_f64 = 0;
    const double A0gal_s_f64 = 0;
    const double A1gal_ss_f64 = 0;
    const double A0glo_s_f64 = 0;
    const double A1glo_ss_f64 = 0;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_NEAR(A0gps_s_f64, BeiDouEng.data.utc.A0gps_s_f64, 0.000001);
    EXPECT_NEAR(A1gps_ss_f64, BeiDouEng.data.utc.A1gps_ss_f64, 0.000001);
    EXPECT_NEAR(A0gal_s_f64, BeiDouEng.data.utc.A0gal_s_f64, 0.000001);
    EXPECT_NEAR(A1gal_ss_f64, BeiDouEng.data.utc.A1gal_ss_f64, 0.000001);
    EXPECT_NEAR(A0glo_s_f64, BeiDouEng.data.utc.A0glo_s_f64, 0.000001);
    EXPECT_NEAR(A1glo_ss_f64, BeiDouEng.data.utc.A1glo_ss_f64, 0.000001);
}

TEST(D1_Test, subframe5_10_anlamlandir)
{
    /// ARRANGE
    int8_t svId = 1;

    Payload payload;
    payload.word[0] = 0x38905751;
    payload.word[1] = 0x145828d1;
    payload.word[2] = 0x4043de2;
    payload.word[3] = 0x3fffffff;
    payload.word[4] = 0x3fcfff5f;
    payload.word[5] = 0x3fa41817;
    payload.word[6] = 0x0;
    payload.word[7] = 0x0;
    payload.word[8] = 0x0;
    payload.word[9] = 0x0;

    const double A0utc_s_f64 = 4.29496729200000000000e+09;
    const double A1utc_ss_f64 = 1.67771930000000000000e+07;
    const double Dn_f64 = 6.00000000000000000000e+00;
    const double DtLS_s_f64 = 4.00000000000000000000e+00;
    const double DtLSF_s_f64 = 4.00000000000000000000e+00;
    const double WNlsf_f64 = 6.10000000000000000000e+01;

    /// ACT
    BeiDouEng.catch_subframe_data_D1(payload.word, svId);

    /// ASSERT
    EXPECT_NEAR(A0utc_s_f64, BeiDouEng.data.utc.A0utc_s_f64, 0.000001);
    EXPECT_NEAR(A1utc_ss_f64, BeiDouEng.data.utc.A1utc_ss_f64, 0.000001);
    EXPECT_NEAR(Dn_f64, BeiDouEng.data.utc.Dn_f64, 0.000001);
    EXPECT_NEAR(DtLS_s_f64, BeiDouEng.data.utc.DtLS_s_f64, 0.000001);
    EXPECT_NEAR(DtLSF_s_f64, BeiDouEng.data.utc.DtLSF_s_f64, 0.000001);
    EXPECT_NEAR(WNlsf_f64, BeiDouEng.data.utc.WNlsf_f64, 0.000001);
}

TEST(Utils_Test, test_merge_two_u)
{
    /// ARRANGE
    Utils temp_utils;
    const uint32_t msb_bits_1 = 0xffff0f00;
    const uint32_t lsb_bits_1 = 0x111231f;
    const uint32_t msb_bits_2 = 0xfffffc18;
    const uint32_t lsb_bits_2 = 0xfffff110;

    const uint32_t expected_value_1 = 17838623;
    const uint32_t expected_value_2 = 4293939472;

    const int lsb_len_1 = 0;
    const int lsb_len_2 = 10;

    /// ACT
    uint32_t merged_bits_1 = temp_utils.merge_two_u(msb_bits_1, lsb_bits_1, lsb_len_1);
    uint32_t merged_bits_2 = temp_utils.merge_two_u(msb_bits_2, lsb_bits_2, lsb_len_2);

    /// ASSERT
    EXPECT_EQ(expected_value_1, merged_bits_1);
    EXPECT_EQ(expected_value_2, merged_bits_2);
}

TEST(Utils_Test, test_merge_two_s)
{
    /// ARRANGE
    Utils temp_utils;
    const uint32_t msb_bits_1 = 0xffff0f00;
    const uint32_t lsb_bits_1 = 0x111231f;
    const uint32_t msb_bits_2 = 0xfffffc18;
    const uint32_t lsb_bits_2 = 0xfffff110;

    const int32_t expected_value_1 = 17838623;
    const int32_t expected_value_2 = -1027824;

    const int lsb_len_1 = 0;
    const int lsb_len_2 = 10;

    /// ACT
    int32_t merged_bits_1 = temp_utils.merge_two_s(msb_bits_1, lsb_bits_1, lsb_len_1);
    int32_t merged_bits_2 = temp_utils.merge_two_s(msb_bits_2, lsb_bits_2, lsb_len_2);

    /// ASSERT
    EXPECT_EQ(expected_value_1, merged_bits_1);
    EXPECT_EQ(expected_value_2, merged_bits_2);
}

TEST(Utils_Test, test_get_ura_from_urai)
{
    /// ARRANGE
    Utils temp_utils;
    uint8_t urai_1 = 1;
    uint8_t urai_2 = 2;
    uint8_t urai_3 = 3;
    uint8_t urai_4 = 15;

    double expected_value_1 = 2.8;
    double expected_value_2 = 4.0;
    double expected_value_3 = 5.7;
    double expected_value_4 = 0.0;
  
    /// ACT
    double ura_1 = temp_utils.get_ura_from_urai(urai_1);
    double ura_2 = temp_utils.get_ura_from_urai(urai_2);
    double ura_3 = temp_utils.get_ura_from_urai(urai_3);
    double ura_4 = temp_utils.get_ura_from_urai(urai_4);

    /// ASSERT
    EXPECT_NEAR(expected_value_1, ura_1, 0.01);
    EXPECT_NEAR(expected_value_2, ura_2, 0.01);
    EXPECT_NEAR(expected_value_3, ura_3, 0.01);
    EXPECT_NEAR(expected_value_4, ura_4, 0.01);
}

int main()
{
    // initializes the framework and must be called before RUN_ALL_TESTS
    ::testing::InitGoogleTest();
    //  Note that RUN_ALL_TESTS automatically detects and runs all the tests defined using the TEST macro. 
    return RUN_ALL_TESTS();
}
