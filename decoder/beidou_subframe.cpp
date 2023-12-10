/*------------------------------------------------------------------------------
*
* @author: Mehmet Kaan Erol
*
------------------------------------------------------------------------------*/

#include "beidou_subframe.hpp"

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::one, PageId::None>::compute(BeiDouNavData&	 data, uint8_t svId) const
{
    data.eph[svId-1].Toc            = EXP2_3   * 
        merge_two_u(word3.toc_msb, word4.toc_lsb, 8);
    data.eph[svId-1].a0_s_f64       = EXP2_N33 * 
        merge_two_s(word8.a0_msb, word9.a0_lsb, 17);
    data.eph[svId-1].a1_ss_f64      = EXP2_N50 * 
        merge_two_s(word9.a1_msb,word10.a1_lsb, 17);
    data.eph[svId-1].a2_ss2_f64     = EXP2_N66 * word8.a2;
    data.eph[svId-1].AODE_f64       = word10.aode;
    data.eph[svId-1].BDTweek_s32    = word3.wn;
    data.eph[svId-1].uraIndex_u8    = word2.urai;
    data.eph[svId-1].ura_f64        = get_ura_from_urai(data.eph[svId-1].uraIndex_u8);
    data.eph[svId-1].svHealth_u8    = word2.sath1;
    data.eph[svId-1].tgd1_s_f64     = EXP1_N1  * EXP1_N9 * word4.tgd1;
    data.eph[svId-1].tgd2_s_f64     = EXP1_N1  * EXP1_N9 *
        merge_two_s(word4.tgd2_msb, word5.tgd2_lsb, 6);
    data.eph[svId-1].AODC_u16       = word2.aodc;
    data.eph[svId-1].Sow            = merge_two_u(word1.sow_msb, word2.sow_lsb, 12);

    // Ionospheric delay model parameters
    data.iono.alpha0_f64          = EXP2_N30 * word5.alpha0;
    data.iono.alpha1_f64          = EXP2_N27 * word5.alpha1;
    data.iono.alpha2_f64          = EXP2_N24 * word6.alpha2;
    data.iono.alpha3_f64          = EXP2_N24 * word6.alpha3;
    data.iono.beta0_f64           = EXP2_11  * merge_two_u(word6.beta0_msb, word7.beta0_lsb, 2);
    data.iono.beta1_f64           = EXP2_14  * word7.beta1;
    data.iono.beta2_f64           = EXP2_16  * word7.beta2;
    data.iono.beta3_f64           = EXP2_16  * merge_two_u(word7.beta3_msb, word8.beta3_lsb, 4);
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::two, PageId::None>::compute(BeiDouNavData& data, uint8_t svId) const
{
    data.eph[svId-1].Crs_m_f64           = EXP2_N6  *
        merge_two_s(word8.crs_msb, word9.crs_lsb, 10);
    data.eph[svId-1].deltaN_rad_sec_f64  = EXP2_N43 * PI *
        merge_two_s(word2.delta_n_msb, word3.delta_n_lsb, 6);
    data.eph[svId-1].m0_rad_f64          = EXP2_N31 * PI *
        merge_two_s(word4.m0_msb, word5.m0_lsb,12);
    data.eph[svId-1].Cuc_rad_f64         = EXP2_N31 * 
        merge_two_s(word3.cuc_msb, word4.cuc_lsb, 2);
    data.eph[svId-1].ecc_f64             = EXP2_N33 *
        merge_two_u(word5.e_msb, word6.e_lsb, 22);
    data.eph[svId-1].Cus_rad_f64         = EXP2_N31 * word7.cus;
    data.eph[svId-1].sqrtA_f64           = EXP2_N19 *
        merge_two_u(word9.sqrt_a_msb, word10.sqrt_a_lsb, 20);
    data.eph[svId-1].Crc_m_f64           = EXP2_N6  *
        merge_two_s(word7.crc_msb, word8.crc_lsb, 14);
    data.eph[svId-1].toe1 = word10.toe;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::three, PageId::None>::compute(BeiDouNavData& data, uint8_t svId) const
{
    data.eph[svId-1].Toe                 = EXP2_3   * merge_two_u(
        merge_two_u(data.eph[svId-1].toe1, word2.toe_msb, 10), word3.toe_lsb, 5);
    data.eph[svId-1].Cic_rad_f64         = EXP2_N31 * 
        merge_two_s(word4.cic_msb, word5.cic_lsb, 11);
    data.eph[svId-1].omega0_rad_f64      = EXP2_N31 * PI *
        merge_two_s(word8.omega0_msb, word9.omega0_lsb, 11);
    data.eph[svId-1].Cis_rad_f64         = EXP2_N31 *
        merge_two_s(word6.cis_msb, word7.cis_lsb, 9);
    data.eph[svId-1].i0_rad_f64          = EXP2_N31 * PI *
        merge_two_u(word3.i0_msb, word4.i0_lsb, 15);
    data.eph[svId-1].omega_rad_f64       = EXP2_N31 * PI *
        merge_two_s(word9.w_msb, word10.w_lsb, 21);
    data.eph[svId-1].OMGdot_rad_f64      = EXP2_N43 * PI *
        merge_two_s(word5.omega_msb, word6.omega_lsb, 13);
    data.eph[svId-1].IDOT_rad_sec_f64    = EXP2_N43 * PI *
        merge_two_s(word7.idot_msb, word8.idot_lsb, 1);
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::four, PageId::None>::compute(BeiDouNavData& data, uint8_t svId) const
{
    data.alm[svId-1].toa_sn_f64          = EXP2_12  * word7.toa;
    data.alm[svId-1].a0_s_f64            = EXP2_N20 * word4.a0;
    data.alm[svId-1].a1_ss_f64           = EXP2_N38 * word4.a1;
    data.alm[svId-1].deltai_rad_f64      = EXP2_N19 * PI * merge_two_s(word6.delta_i_msb, word7.delta_i_lsb, 13);
    data.alm[svId-1].ecc_f64             = EXP2_N21 * word6.e;
    data.alm[svId-1].omg0_rad_f64        = EXP2_N23 * PI * merge_two_s(word5.omega0_msb, word6.omega0_lsb, 2);
    data.alm[svId-1].omg_rad_f64         = EXP2_N23 * PI * merge_two_s(word8.w_msb, word9.w_lsb, 18);
    data.alm[svId-1].OMGdot_rad_f64      = EXP2_N38 * PI * merge_two_s(word7.omega_msb, word8.omega_lsb, 16);
    data.alm[svId-1].sqrtA_m_f64         = EXP2_N11 * merge_two_u(word2.sqrt_a_msb, word3.sqrt_a_lsb, 22);
    data.alm[svId-1].m0_rad_f64          = EXP2_N23 * PI * merge_two_s(word9.m0_msb, word10.m0_lsb, 20);
    data.alm[svId-1].amepid              = word10.amepid;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_1_6>::compute(BeiDouNavData& data, uint8_t svId) const
{
    data.alm[svId-1].toa_sn_f64          = EXP2_12  * word7.toa;
    data.alm[svId-1].a0_s_f64            = EXP2_N20 * word4.a0;
    data.alm[svId-1].a1_ss_f64           = EXP2_N38 * word4.a1;
    data.alm[svId-1].deltai_rad_f64      = EXP2_N19 * PI * merge_two_s(word6.delta_i_msb, word7.delta_i_lsb, 13);
    data.alm[svId-1].ecc_f64             = EXP2_N21 * word6.e;
    data.alm[svId-1].omg0_rad_f64        = EXP2_N23 * PI * merge_two_s(word5.omega0_msb, word6.omega0_lsb, 2);
    data.alm[svId-1].omg_rad_f64         = EXP2_N23 * PI * merge_two_s(word8.w_msb, word9.w_lsb, 18);
    data.alm[svId-1].OMGdot_rad_f64      = EXP2_N38 * PI * merge_two_s(word7.omega_msb, word8.omega_lsb, 16);
    data.alm[svId-1].sqrtA_m_f64         = EXP2_N11 * merge_two_u(word2.sqrt_a_msb, word3.sqrt_a_lsb, 22);
    data.alm[svId-1].m0_rad_f64          = EXP2_N23 * PI * merge_two_s(word9.m0_msb, word10.m0_lsb, 20);
    data.alm[svId-1].amepid              = word10.amepid;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_7>::compute(BeiDouNavData& data, uint8_t svId) const
{
    data.health[0]                     = merge_two_u(word2.hea1_msb, word3.hea1_lsb, 7);
    data.health[1]                     = word3.hea2;
    data.health[2]                     = merge_two_u(word3.hea3_msb, word4.hea3_lsb, 3);
    data.health[3]                     = word4.hea4;
    data.health[4]                     = word4.hea5;
    data.health[5]                     = merge_two_u(word4.hea6_msb, word5.hea6_lsb, 8);
    data.health[6]                     = word5.hea7;
    data.health[7]                     = merge_two_u(word5.hea8_msb, word6.hea8_lsb, 4);
    data.health[8]                     = word6.hea9;
    data.health[9]                     = word6.hea10;
    data.health[10]                    = word7.hea11;
    data.health[11]                    = word7.hea12;
    data.health[12]                    = merge_two_u(word7.hea13_msb, word8.hea13_lsb, 5);
    data.health[13]                    = word8.hea14;
    data.health[14]                    = merge_two_u(word8.hea15_msb, word9.hea15_lsb, 1);
    data.health[15]                    = word9.hea16;
    data.health[16]                    = word9.hea17;
    data.health[17]                    = merge_two_u(word9.hea18_msb, word10.hea18_lsb, 6);
    data.health[18]                    = word10.hea19;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_8>::compute(BeiDouNavData& data, uint8_t svId) const
{
    data.health[20]                    = merge_two_u(word2.hea20_msb, word3.hea20_lsb, 7);
    data.health[21]                    = word3.hea21;
    data.health[22]                    = merge_two_u(word3.hea22_msb, word4.hea22_lsb, 3);
    data.health[23]                    = word4.hea23;
    data.health[24]                    = word4.hea24;
    data.health[25]                    = merge_two_u(word4.hea25_msb, word5.hea25_lsb, 8);
    data.health[26]                    = word5.hea26;
    data.health[27]                    = merge_two_u(word5.hea27_msb, word6.hea27_lsb, 4);
    data.health[28]                    = word6.hea28;
    data.health[29]                    = word6.hea29;
    data.health[30]                    = word7.hea30;
    data.alm[svId-1].week_s32          = word7.wna;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_9>::compute(BeiDouNavData& data, uint8_t svId) const
{
    data.utc.A0gps_s_f64               = word4.a0gps;
    data.utc.A1gps_ss_f64              = merge_two_u(word4.a1gps_msb, word5.a1gps_lsb, 14);
    data.utc.A0gal_s_f64               = merge_two_u(word5.a0gal_msb, word6.a0gal_lsb, 6);
    data.utc.A1gal_ss_f64              = word6.a1gal;
    data.utc.A0glo_s_f64               = word7.a0glo;
    data.utc.A1glo_ss_f64              = merge_two_u(word7.a1glo_msb, word8.a1glo_lsb, 8);  
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_10>::compute(BeiDouNavData& data, uint8_t svId) const
{
    data.utc.A0utc_s_f64               = merge_two_u(word4.a0utc_msb, word5.a0utc_lsb, 10);
    data.utc.A1utc_ss_f64              = merge_two_u(word5.a1utc_msb, word6.a1utc_lsb, 12);
    data.utc.Dn_f64                    = word6.dn;
    data.utc.DtLS_s_f64                = merge_two_u(word2.delta_tls_msb, word3.delta_tls_lsb, 6);
    data.utc.DtLSF_s_f64               = word3.delta_lsf;
    data.utc.WNlsf_f64                 = word3.wnlsf;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_11_23>::compute(BeiDouNavData& data, uint8_t svId) const
{
    data.alm[svId-1].toa_sn_f64          = EXP2_12  * word7.toa;
    data.alm[svId-1].a0_s_f64            = EXP2_N20 * word4.a0;
    data.alm[svId-1].a1_ss_f64           = EXP2_N38 * word4.a1;
    data.alm[svId-1].deltai_rad_f64      = EXP2_N19 * PI * merge_two_s(word6.delta_i_msb, word7.delta_i_lsb, 13);
    data.alm[svId-1].ecc_f64             = EXP2_N21 * word6.e;
    data.alm[svId-1].omg0_rad_f64        = EXP2_N23 * PI * merge_two_s(word5.omega0_msb, word6.omega0_lsb, 2);
    data.alm[svId-1].omg_rad_f64         = EXP2_N23 * PI * merge_two_s(word8.w_msb, word9.w_lsb, 18);
    data.alm[svId-1].OMGdot_rad_f64      = EXP2_N38 * PI * merge_two_s(word7.omega_msb, word8.omega_lsb, 16);
    data.alm[svId-1].sqrtA_m_f64         = EXP2_N11 * merge_two_u(word2.sqrt_a_msb, word3.sqrt_a_lsb, 22);
    data.alm[svId-1].m0_rad_f64          = EXP2_N23 * PI * merge_two_s(word9.m0_msb, word10.m0_lsb, 20);
    data.alm[svId-1].amid                = word10.amid;
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_24>::compute(BeiDouNavData& data, uint8_t svId) const
{
    if (data.alm[svId-1].amid == 1)
    {
        data.health[31]                    = merge_two_u(word2.hea31_msb, word3.hea31_lsb, 7);
        data.health[32]                    = word3.hea32;
        data.health[33]                    = merge_two_u(word3.hea33_msb, word4.hea33_lsb, 3);
        data.health[34]                    = word4.hea34;
        data.health[35]                    = word4.hea35;
        data.health[36]                    = merge_two_u(word4.hea36_msb, word5.hea36_lsb, 8);
        data.health[37]                    = word5.hea37;
        data.health[38]                    = merge_two_u(word5.hea38_msb, word6.hea38_lsb, 4);
        data.health[39]                    = word6.hea39;
        data.health[40]                    = word6.hea40;
        data.health[41]                    = word7.hea41;
        data.health[42]                    = word7.hea42;
        data.health[43]                    = merge_two_u(word7.hea43_msb, word8.hea43_lsb, 5);
    }
    else if (data.alm[svId-1].amid == 2)
    {
        data.health[44]                    = merge_two_u(word2.hea31_msb, word3.hea31_lsb, 7);
        data.health[45]                    = word3.hea32;
        data.health[46]                    = merge_two_u(word3.hea33_msb, word4.hea33_lsb, 3);
        data.health[47]                    = word4.hea34;
        data.health[48]                    = word4.hea35;
        data.health[49]                    = merge_two_u(word4.hea36_msb, word5.hea36_lsb, 8);
        data.health[50]                    = word5.hea37;
        data.health[51]                    = merge_two_u(word5.hea38_msb, word6.hea38_lsb, 4);
        data.health[52]                    = word6.hea39;
        data.health[53]                    = word6.hea40;
        data.health[54]                    = word7.hea41;
        data.health[55]                    = word7.hea42;
        data.health[56]                    = merge_two_u(word7.hea43_msb, word8.hea43_lsb, 5);
    }
    else if (data.alm[svId-1].amid == 3)
    {
        data.health[57]                    = merge_two_u(word2.hea31_msb, word3.hea31_lsb, 7);
        data.health[58]                    = word3.hea32;
        data.health[59]                    = merge_two_u(word3.hea33_msb, word4.hea33_lsb, 3);
        data.health[60]                    = word4.hea34;
        data.health[61]                    = word4.hea35;
        data.health[62]                    = merge_two_u(word4.hea36_msb, word5.hea36_lsb, 8);
        data.health[63]                    = word5.hea37;
   }
}

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::one, PageId::None>::decode(const std::uint32_t(&word)[10])
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

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::two, PageId::None>::decode(const std::uint32_t(&word)[10])
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

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::three, PageId::None>::decode(const std::uint32_t(&word)[10])
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

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::four, PageId::None>::decode(const std::uint32_t(&word)[10])
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

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_1_6>::decode(const std::uint32_t(&word)[10])
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

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_7>::decode(const std::uint32_t(&word)[10])
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

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_8>::decode(const std::uint32_t(&word)[10])
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

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_9>::decode(const std::uint32_t(&word)[10])
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

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_10>::decode(const std::uint32_t(&word)[10])
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

uint8_t BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_11_23>::decode(const std::uint32_t(&word)[10])
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

void BeiDouSubframe<TrackingCode::B1I_D1, Subframe::five, PageId::page_24>::decode(const std::uint32_t(&word)[10])
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