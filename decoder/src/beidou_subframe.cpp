/*------------------------------------------------------------------------------
*
* @author: Mehmet Kaan Erol
*
------------------------------------------------------------------------------*/

#include "beidou_subframe.hpp"
#include <cmath>

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::one, PageId::None>::anlamlandir(BeiDouNavData&	 data, uint8_t svId)
{
    data.eph[svId-1].Toc            = exp2_3   * 
        utils.merge_two_u(word3.toc_msb, word4.toc_lsb, 8);
    data.eph[svId-1].a0_s_f64       = exp2_n33 * 
        utils.merge_two_s(word8.a0_msb, word9.a0_lsb, 17);
    data.eph[svId-1].a1_ss_f64      = exp2_n50 * 
        utils.merge_two_s(word9.a1_msb,word10.a1_lsb, 17);
    data.eph[svId-1].a2_ss2_f64     = exp2_n66 * word8.a2;
    data.eph[svId-1].AODE_f64       = word10.aode;
    data.eph[svId-1].BDTweek_s32    = word3.wn;
    data.eph[svId-1].uraIndex_u8    = word2.urai;
    data.eph[svId-1].ura_f64        = utils.get_ura_from_urai(data.eph[svId-1].uraIndex_u8);
    data.eph[svId-1].svHealth_u8    = word2.sath1;
    data.eph[svId-1].tgd1_s_f64     = exp1_n1  * exp1_n9 * word4.tgd1;
    data.eph[svId-1].tgd2_s_f64     = exp1_n1  * exp1_n9 *
        utils.merge_two_s(word4.tgd2_msb, word5.tgd2_lsb, 6);
    data.eph[svId-1].AODC_u16       = word2.aodc;
    data.eph[svId-1].Sow            = utils.merge_two_u(word1.sow_msb, word2.sow_lsb, 12);

    // Ionospheric delay model parameters
    data.iono.alpha0_f64          = exp2_n30 * word5.alpha0;
    data.iono.alpha1_f64          = exp2_n27 * word5.alpha1;
    data.iono.alpha2_f64          = exp2_n24 * word6.alpha2;
    data.iono.alpha3_f64          = exp2_n24 * word6.alpha3;
    data.iono.beta0_f64           = exp2_11  * utils.merge_two_u(word6.beta0_msb, word7.beta0_lsb, 2);
    data.iono.beta1_f64           = exp2_14  * word7.beta1;
    data.iono.beta2_f64           = exp2_16  * word7.beta2;
    data.iono.beta3_f64           = exp2_16  * utils.merge_two_u(word7.beta3_msb, word8.beta3_lsb, 4);
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::two, PageId::None>::anlamlandir(BeiDouNavData& data, uint8_t svId)
{
    data.eph[svId-1].Crs_m_f64           = exp2_n6  *
        utils.merge_two_s(word8.crs_msb, word9.crs_lsb, 10);
    data.eph[svId-1].deltaN_rad_sec_f64  = exp2_n43 * PI *
        utils.merge_two_s(word2.delta_n_msb, word3.delta_n_lsb, 6);
    data.eph[svId-1].m0_rad_f64          = exp2_n31 * PI *
        utils.merge_two_s(word4.m0_msb, word5.m0_lsb,12);
    data.eph[svId-1].Cuc_rad_f64         = exp2_n31 * 
        utils.merge_two_s(word3.cuc_msb, word4.cuc_lsb, 2);
    data.eph[svId-1].ecc_f64             = exp2_n33 *
        utils.merge_two_u(word5.e_msb, word6.e_lsb, 22);
    data.eph[svId-1].Cus_rad_f64         = exp2_n31 * word7.cus;
    data.eph[svId-1].sqrtA_f64           = exp2_n19 *
        utils.merge_two_u(word9.sqrt_a_msb, word10.sqrt_a_lsb, 20);
    data.eph[svId-1].Crc_m_f64           = exp2_n6  *
        utils.merge_two_s(word7.crc_msb, word8.crc_lsb, 14);
    data.eph[svId-1].toe1 = word10.toe;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::three, PageId::None>::anlamlandir(BeiDouNavData& data, uint8_t svId)
{
    data.eph[svId-1].Toe                 = exp2_3   * utils.merge_two_u(
        utils.merge_two_u(data.eph[svId-1].toe1, word2.toe_msb, 10), word3.toe_lsb, 5);
    data.eph[svId-1].Cic_rad_f64         = exp2_n31 * 
        utils.merge_two_s(word4.cic_msb, word5.cic_lsb, 11);
    data.eph[svId-1].omega0_rad_f64      = exp2_n31 * PI *
        utils.merge_two_s(word8.omega0_msb, word9.omega0_lsb, 11);
    data.eph[svId-1].Cis_rad_f64         = exp2_n31 *
        utils.merge_two_s(word6.cis_msb, word7.cis_lsb, 9);
    data.eph[svId-1].i0_rad_f64          = exp2_n31 * PI *
        utils.merge_two_u(word3.i0_msb, word4.i0_lsb, 15);
    data.eph[svId-1].omega_rad_f64       = exp2_n31 * PI *
        utils.merge_two_s(word9.w_msb, word10.w_lsb, 21);
    data.eph[svId-1].OMGdot_rad_f64      = exp2_n43 * PI *
        utils.merge_two_s(word5.omega_msb, word6.omega_lsb, 13);
    data.eph[svId-1].IDOT_rad_sec_f64    = exp2_n43 * PI *
        utils.merge_two_s(word7.idot_msb, word8.idot_lsb, 1);
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::four, PageId::None>::anlamlandir(BeiDouNavData& data, uint8_t svId)
{
    data.alm[svId-1].toa_sn_f64          = exp2_12  * word7.toa;
    data.alm[svId-1].a0_s_f64            = exp2_n20 * word4.a0;
    data.alm[svId-1].a1_ss_f64           = exp2_n38 * word4.a1;
    data.alm[svId-1].deltai_rad_f64      = exp2_n19 * PI * utils.merge_two_s(word6.delta_i_msb, word7.delta_i_lsb, 13);
    data.alm[svId-1].ecc_f64             = exp2_n21 * word6.e;
    data.alm[svId-1].omg0_rad_f64        = exp2_n23 * PI * utils.merge_two_s(word5.omega0_msb, word6.omega0_lsb, 2);
    data.alm[svId-1].omg_rad_f64         = exp2_n23 * PI * utils.merge_two_s(word8.w_msb, word9.w_lsb, 18);
    data.alm[svId-1].OMGdot_rad_f64      = exp2_n38 * PI * utils.merge_two_s(word7.omega_msb, word8.omega_lsb, 16);
    data.alm[svId-1].sqrtA_m_f64         = exp2_n11 * utils.merge_two_u(word2.sqrt_a_msb, word3.sqrt_a_lsb, 22);
    data.alm[svId-1].m0_rad_f64          = exp2_n23 * PI * utils.merge_two_s(word9.m0_msb, word10.m0_lsb, 20);
    data.alm[svId-1].amepid              = word10.amepid;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_1_6>::anlamlandir(BeiDouNavData& data, uint8_t svId)
{
    data.alm[svId-1].toa_sn_f64          = exp2_12  * word7.toa;
    data.alm[svId-1].a0_s_f64            = exp2_n20 * word4.a0;
    data.alm[svId-1].a1_ss_f64           = exp2_n38 * word4.a1;
    data.alm[svId-1].deltai_rad_f64      = exp2_n19 * PI * utils.merge_two_s(word6.delta_i_msb, word7.delta_i_lsb, 13);
    data.alm[svId-1].ecc_f64             = exp2_n21 * word6.e;
    data.alm[svId-1].omg0_rad_f64        = exp2_n23 * PI * utils.merge_two_s(word5.omega0_msb, word6.omega0_lsb, 2);
    data.alm[svId-1].omg_rad_f64         = exp2_n23 * PI * utils.merge_two_s(word8.w_msb, word9.w_lsb, 18);
    data.alm[svId-1].OMGdot_rad_f64      = exp2_n38 * PI * utils.merge_two_s(word7.omega_msb, word8.omega_lsb, 16);
    data.alm[svId-1].sqrtA_m_f64         = exp2_n11 * utils.merge_two_u(word2.sqrt_a_msb, word3.sqrt_a_lsb, 22);
    data.alm[svId-1].m0_rad_f64          = exp2_n23 * PI * utils.merge_two_s(word9.m0_msb, word10.m0_lsb, 20);
    data.alm[svId-1].amepid              = word10.amepid;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_7>::anlamlandir(BeiDouNavData& data, uint8_t svId)
{
    data.health[0]                     = utils.merge_two_u(word2.hea1_msb, word3.hea1_lsb, 7);
    data.health[1]                     = word3.hea2;
    data.health[2]                     = utils.merge_two_u(word3.hea3_msb, word4.hea3_lsb, 3);
    data.health[3]                     = word4.hea4;
    data.health[4]                     = word4.hea5;
    data.health[5]                     = utils.merge_two_u(word4.hea6_msb, word5.hea6_lsb, 8);
    data.health[6]                     = word5.hea7;
    data.health[7]                     = utils.merge_two_u(word5.hea8_msb, word6.hea8_lsb, 4);
    data.health[8]                     = word6.hea9;
    data.health[9]                     = word6.hea10;
    data.health[10]                    = word7.hea11;
    data.health[11]                    = word7.hea12;
    data.health[12]                    = utils.merge_two_u(word7.hea13_msb, word8.hea13_lsb, 5);
    data.health[13]                    = word8.hea14;
    data.health[14]                    = utils.merge_two_u(word8.hea15_msb, word9.hea15_lsb, 1);
    data.health[15]                    = word9.hea16;
    data.health[16]                    = word9.hea17;
    data.health[17]                    = utils.merge_two_u(word9.hea18_msb, word10.hea18_lsb, 6);
    data.health[18]                    = word10.hea19;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_8>::anlamlandir(BeiDouNavData& data, uint8_t svId)
{
    data.health[20]                    = utils.merge_two_u(word2.hea20_msb, word3.hea20_lsb, 7);
    data.health[21]                    = word3.hea21;
    data.health[22]                    = utils.merge_two_u(word3.hea22_msb, word4.hea22_lsb, 3);
    data.health[23]                    = word4.hea23;
    data.health[24]                    = word4.hea24;
    data.health[25]                    = utils.merge_two_u(word4.hea25_msb, word5.hea25_lsb, 8);
    data.health[26]                    = word5.hea26;
    data.health[27]                    = utils.merge_two_u(word5.hea27_msb, word6.hea27_lsb, 4);
    data.health[28]                    = word6.hea28;
    data.health[29]                    = word6.hea29;
    data.health[30]                    = word7.hea30;

    data.alm[svId-1].week_s32            = word7.wna;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_9>::anlamlandir(BeiDouNavData& data, uint8_t svId)
{
    data.utc.A0gps_s_f64               = word4.a0gps;
    data.utc.A1gps_ss_f64              = utils.merge_two_u(word4.a1gps_msb, word5.a1gps_lsb, 14);
    data.utc.A0gal_s_f64               = utils.merge_two_u(word5.a0gal_msb, word6.a0gal_lsb, 6);
    data.utc.A1gal_ss_f64              = word6.a1gal;
    data.utc.A0glo_s_f64               = word7.a0glo;
    data.utc.A1glo_ss_f64              = utils.merge_two_u(word7.a1glo_msb, word8.a1glo_lsb, 8);  
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_10>::anlamlandir(BeiDouNavData& data, uint8_t svId)
{
    data.utc.A0utc_s_f64               = utils.merge_two_u(word4.a0utc_msb, word5.a0utc_lsb, 10);
    data.utc.A1utc_ss_f64              = utils.merge_two_u(word5.a1utc_msb, word6.a1utc_lsb, 12);
    data.utc.Dn_f64                    = word6.dn;
    data.utc.DtLS_s_f64                = utils.merge_two_u(word2.delta_tls_msb, word3.delta_tls_lsb, 6);
    data.utc.DtLSF_s_f64               = word3.delta_lsf;
    data.utc.WNlsf_f64                 = word3.wnlsf;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_11_23>::anlamlandir(BeiDouNavData& data, uint8_t svId)
{
    data.alm[svId-1].toa_sn_f64          = exp2_12  * word7.toa;
    data.alm[svId-1].a0_s_f64            = exp2_n20 * word4.a0;
    data.alm[svId-1].a1_ss_f64           = exp2_n38 * word4.a1;
    data.alm[svId-1].deltai_rad_f64      = exp2_n19 * PI * utils.merge_two_s(word6.delta_i_msb, word7.delta_i_lsb, 13);
    data.alm[svId-1].ecc_f64             = exp2_n21 * word6.e;
    data.alm[svId-1].omg0_rad_f64        = exp2_n23 * PI * utils.merge_two_s(word5.omega0_msb, word6.omega0_lsb, 2);
    data.alm[svId-1].omg_rad_f64         = exp2_n23 * PI * utils.merge_two_s(word8.w_msb, word9.w_lsb, 18);
    data.alm[svId-1].OMGdot_rad_f64      = exp2_n38 * PI * utils.merge_two_s(word7.omega_msb, word8.omega_lsb, 16);
    data.alm[svId-1].sqrtA_m_f64         = exp2_n11 * utils.merge_two_u(word2.sqrt_a_msb, word3.sqrt_a_lsb, 22);
    data.alm[svId-1].m0_rad_f64          = exp2_n23 * PI * utils.merge_two_s(word9.m0_msb, word10.m0_lsb, 20);
    data.alm[svId-1].amid                = word10.amid;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_24>::anlamlandir(BeiDouNavData& data, uint8_t svId)
{
    if (data.alm[svId-1].amid == 1)
    {
        data.health[31]                    = utils.merge_two_u(word2.hea31_msb, word3.hea31_lsb, 7);
        data.health[32]                    = word3.hea32;
        data.health[33]                    = utils.merge_two_u(word3.hea33_msb, word4.hea33_lsb, 3);
        data.health[34]                    = word4.hea34;
        data.health[35]                    = word4.hea35;
        data.health[36]                    = utils.merge_two_u(word4.hea36_msb, word5.hea36_lsb, 8);
        data.health[37]                    = word5.hea37;
        data.health[38]                    = utils.merge_two_u(word5.hea38_msb, word6.hea38_lsb, 4);
        data.health[39]                    = word6.hea39;
        data.health[40]                    = word6.hea40;
        data.health[41]                    = word7.hea41;
        data.health[42]                    = word7.hea42;
        data.health[43]                    = utils.merge_two_u(word7.hea43_msb, word8.hea43_lsb, 5);
    }
    else if (data.alm[svId-1].amid == 2)
    {
        data.health[44]                    = utils.merge_two_u(word2.hea31_msb, word3.hea31_lsb, 7);
        data.health[45]                    = word3.hea32;
        data.health[46]                    = utils.merge_two_u(word3.hea33_msb, word4.hea33_lsb, 3);
        data.health[47]                    = word4.hea34;
        data.health[48]                    = word4.hea35;
        data.health[49]                    = utils.merge_two_u(word4.hea36_msb, word5.hea36_lsb, 8);
        data.health[50]                    = word5.hea37;
        data.health[51]                    = utils.merge_two_u(word5.hea38_msb, word6.hea38_lsb, 4);
        data.health[52]                    = word6.hea39;
        data.health[53]                    = word6.hea40;
        data.health[54]                    = word7.hea41;
        data.health[55]                    = word7.hea42;
        data.health[56]                    = utils.merge_two_u(word7.hea43_msb, word8.hea43_lsb, 5);
    }
    else if (data.alm[svId-1].amid == 3)
    {
        data.health[57]                    = utils.merge_two_u(word2.hea31_msb, word3.hea31_lsb, 7);
        data.health[58]                    = word3.hea32;
        data.health[59]                    = utils.merge_two_u(word3.hea33_msb, word4.hea33_lsb, 3);
        data.health[60]                    = word4.hea34;
        data.health[61]                    = word4.hea35;
        data.health[62]                    = utils.merge_two_u(word4.hea36_msb, word5.hea36_lsb, 8);
        data.health[63]                    = word5.hea37;
   }
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::one, PageId::None>::coz(const std::uint32_t(&word)[10])
{
    word1.word = word[0];
    word2.word = word[1];
    word3.word = word[2];
    word4.word = word[3];
    word5.word = word[4];
    word6.word = word[5];
    word7.word = word[6];
    word8.word = word[7];
    word9.word = word[8];
    word10.word = word[9];
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::two, PageId::None>::coz(const std::uint32_t(&word)[10])
{
    word1.word = word[0];
    word2.word = word[1];
    word3.word = word[2];
    word4.word = word[3];
    word5.word = word[4];
    word6.word = word[5];
    word7.word = word[6];
    word8.word = word[7];
    word9.word = word[8];
    word10.word = word[9];
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::three, PageId::None>::coz(const std::uint32_t(&word)[10])
{
    word1.word = word[0];
    word2.word = word[1];
    word3.word = word[2];
    word4.word = word[3];
    word5.word = word[4];
    word6.word = word[5];
    word7.word = word[6];
    word8.word = word[7];
    word9.word = word[8];
    word10.word = word[9];
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::four, PageId::None>::coz(const std::uint32_t(&word)[10])
{
    word1.word = word[0];
    word2.word = word[1];
    word3.word = word[2];
    word4.word = word[3];
    word5.word = word[4];
    word6.word = word[5];
    word7.word = word[6];
    word8.word = word[7];
    word9.word = word[8];
    word10.word = word[9];
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_1_6>::coz(const std::uint32_t(&word)[10])
{
    word1.word = word[0];
    word2.word = word[1];
    word3.word = word[2];
    word4.word = word[3];
    word5.word = word[4];
    word6.word = word[5];
    word7.word = word[6];
    word8.word = word[7];
    word9.word = word[8];
    word10.word = word[9];
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_7>::coz(const std::uint32_t(&word)[10])
{
    word1.word = word[0];
    word2.word = word[1];
    word3.word = word[2];
    word4.word = word[3];
    word5.word = word[4];
    word6.word = word[5];
    word7.word = word[6];
    word8.word = word[7];
    word9.word = word[8];
    word10.word = word[9];
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_8>::coz(const std::uint32_t(&word)[10])
{
    word1.word = word[0];
    word2.word = word[1];
    word3.word = word[2];
    word4.word = word[3];
    word5.word = word[4];
    word6.word = word[5];
    word7.word = word[6];
    word8.word = word[7];
    word9.word = word[8];
    word10.word = word[9];
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_9>::coz(const std::uint32_t(&word)[10])
{
    word1.word = word[0];
    word2.word = word[1];
    word3.word = word[2];
    word4.word = word[3];
    word5.word = word[4];
    word6.word = word[5];
    word7.word = word[6];
    word8.word = word[7];
    word9.word = word[8];
    word10.word = word[9];
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_10>::coz(const std::uint32_t(&word)[10])
{
    word1.word = word[0];
    word2.word = word[1];
    word3.word = word[2];
    word4.word = word[3];
    word5.word = word[4];
    word6.word = word[5];
    word7.word = word[6];
    word8.word = word[7];
    word9.word = word[8];
    word10.word = word[9];
}

uint8_t BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_11_23>::coz(const std::uint32_t(&word)[10])
{
    word1.word = word[0];
    word2.word = word[1];
    word3.word = word[2];
    word4.word = word[3];
    word5.word = word[4];
    word6.word = word[5];
    word7.word = word[6];
    word8.word = word[7];
    word9.word = word[8];
    word10.word = word[9];
    return word10.amid;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_24>::coz(const std::uint32_t(&word)[10])
{
    word1.word = word[0];
    word2.word = word[1];
    word3.word = word[2];
    word4.word = word[3];
    word5.word = word[4];
    word6.word = word[5];
    word7.word = word[6];
    word8.word = word[7];
    word9.word = word[8];
    word10.word = word[9];
}

uint32_t Utils::merge_two_u(uint32_t a, uint32_t b, int n)
{
    return (a << n) + b;
}

int32_t Utils::merge_two_s(int32_t a, uint32_t b, int n)
{
    return (a << n) + b;
}

double Utils::get_ura_from_urai(uint8_t urai)
{
    if (urai >= 0 && urai < 6){
            if (urai == 1){
                return (double) 2.8;
            } 
            else if (urai == 3){
                return (double) 5.7;
            }
            else if (urai == 5){
                return (double) 11.3;
            }
            else{
                return (double) pow(2, (urai / 2) + 1);
            }
        }
        else if (urai >= 6 && urai < 15){
            return (double) pow(2, (urai - 2));
        } // If urai=15, it means the satellite is in maneuver or there is no accuracy prediction
        else if (urai == 15){
            return 0;
        }
    return -1;
}

gtime_t Utils::bdt2gpst(gtime_t t, double sec){
    double tt;
    t.sec += 14.0; 
    tt = floor(t.sec); 
    t.time += (int) tt; 
    t.sec -= tt;
    return t;
}

gtime_t Utils::bdt2time(int week, double sec){
    gtime_t t = epoch2time(bdt0);

    if (sec < -1e9 || 1e9 < sec) sec = 0.0;
    t.time += 86400 * 7 * week + (int)sec;
    t.sec = sec - (int)sec;
    return t;
}

gtime_t Utils::epoch2time(const double *ep){
    const int doy[] = {1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
    gtime_t time = { 0 };
    int days, sec, year = (int)ep[0], mon = (int)ep[1], day = (int)ep[2];
    
    if (year < 1970 || 2099 < year || mon < 1 || 12 < mon) return time;
    
    /* leap year if year%4==0 in 1901-2099 */
    days = (year - 1970) * 365 + (year - 1969) / 4 + doy[mon - 1] + day - 2 + (year % 4 == 0 && mon >= 3 ? 1 : 0);
    sec = (int) floor(ep[5]);
    time.time = (time_t)days * 86400 + (int)ep[3] * 3600 + (int)ep[4] * 60 + sec;
    time.sec = ep[5] - sec;
    return time;
}
