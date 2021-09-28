/*------------------------------------------------------------------------------
*
* @author: Mehmet Kaan Erol
*
------------------------------------------------------------------------------*/

#include <iomanip>
#include <fstream>
#include "../include/navigation_engine.hpp"

void NavEng<SatelliteSystem::BeiDou>::catch_subframe_data_D1 (const std::uint32_t(&word)[10], std::uint8_t svId)
{
    uint8_t pageId = 0, frameid = 0;

    Word1 how;
    how.word = word[0];
    frameid = how.fraid;

    switch (Subframe(frameid))
    {
        case Subframe::one:
        {
            D1_Subframe1.coz(word);
            D1_Subframe1.anlamlandir(data, svId);
            new_subframe_map[svId-1].new_nav_msg.sbfrm1 = 1;
            break;
        }
        case Subframe::two:
        {
            D1_Subframe2.coz(word);
            D1_Subframe2.anlamlandir(data, svId);
            new_subframe_map[svId-1].new_nav_msg.sbfrm2 = 1;
            break;
        }
        case Subframe::three:
        {
            temp_toe = data.eph[svId-1].Toe;
            D1_Subframe3.coz(word);
            D1_Subframe3.anlamlandir(data, svId);
            new_subframe_map[svId-1].new_nav_msg.sbfrm3 = 1;
            break;
        }
        case Subframe::four:
        {
            D1_Subframe4.coz(word);
            D1_Subframe4.anlamlandir(data, svId);
            new_subframe_map[svId-1].new_nav_msg.sbfrm4 = 1;
            break;
        }
        case Subframe::five:
        {
            Word2 temp_word2;
            temp_word2.word = word[1];
            pageId = temp_word2.pnum;

            if (pageId >= 1 && pageId <= 6)
            {
                D1_Subframe5_1_6.coz(word);
                D1_Subframe5_1_6.anlamlandir(data, svId);
                new_subframe_map[svId-1].new_nav_msg.sbfrm5_1_6 = 1;
            }
            else if (pageId == 7)
            {
                D1_Subframe5_7.coz(word);
                D1_Subframe5_7.anlamlandir(data, svId);
                new_subframe_map[svId-1].new_nav_msg.sbfrm5_7 = 1;
            }
            else if (pageId == 8)
            {
                D1_Subframe5_8.coz(word);
                D1_Subframe5_8.anlamlandir(data, svId);
                new_subframe_map[svId-1].new_nav_msg.sbfrm5_8 = 1;
            }
            else if (pageId == 9)
            {
                D1_Subframe5_9.coz(word);
                D1_Subframe5_9.anlamlandir(data, svId);
                new_subframe_map[svId-1].new_nav_msg.sbfrm5_9 = 1;
            }
            else if (pageId == 10)
            {
                D1_Subframe5_10.coz(word);
                D1_Subframe5_10.anlamlandir(data, svId);
                new_subframe_map[svId-1].new_nav_msg.sbfrm5_10 = 1;
            }
            else if (pageId >= 11 && pageId <= 23 && data.alm[svId].amepid == 3 && svId >= 31) // SvId 31-63
            {
                uint8_t amid = D1_Subframe5_11_23.coz(word);
                if(amid != 0)
                {
                    if(amid <= 2 || (amid == 3 && pageId <= 17))
                    {
                        D1_Subframe5_11_23.anlamlandir(data, svId);
                        new_subframe_map[svId-1].new_nav_msg.sbfrm5_11_23 = 1;
                    }
                }
            }
            else if (pageId == 24 && data.alm[svId-1].amepid == 3 && data.alm[svId-1].amid != 0 && svId >= 31) // SvId 31-63
            {
                D1_Subframe5_24.coz(word);
                D1_Subframe5_24.anlamlandir(data, svId);
                /*
                std::cout << "Anlamlandir: " << std::endl;
                if (data.alm[svId-1].amid == 1)
                {
                    for (int i=31;i<44;i++)
                        std::cout << data.health[i] << " ";   
                }
                else if (data.alm[svId-1].amid == 2)
                {
                    for (int i=44;i<57;i++)
                        std::cout << data.health[i] << " ";
                }
                else if (data.alm[svId-1].amid == 3)
                {
                    for (int i=57;i<64;i++)
                        std::cout << data.health[i] << " ";
                }
                */
                new_subframe_map[svId-1].new_nav_msg.sbfrm5_24 = 1;
            }
            break;
        }
        default:
            break;
    }

    if (new_subframe_map[svId-1].new_nav_msg.sbfrm1 == 1 &&
        new_subframe_map[svId-1].new_nav_msg.sbfrm2 == 1 &&
        new_subframe_map[svId-1].new_nav_msg.sbfrm3 == 1   )
    {
        new_subframe_map[svId-1].new_nav_msg.ephemeris = 1;
        new_subframe_map[svId-1].new_nav_msg.sbfrm1    = 0;
        new_subframe_map[svId-1].new_nav_msg.sbfrm2    = 0;
        new_subframe_map[svId-1].new_nav_msg.sbfrm3    = 0;

        if (data.eph[svId-1].Toe != temp_toe)
        {   
            std::cout.precision(20);
            std::ofstream fileStream("out.eph", std::ios_base::app);
            std::string line;
            if (fileStream.is_open()){
                fileStream
                << std::scientific << "\t" << data.eph[svId-1].a0_s_f64 << "\t" << data.eph[svId-1].a1_ss_f64
                << std::scientific << "\t" << data.eph[svId-1].a2_ss2_f64 << "\t" << data.eph[svId-1].AODE_f64
                << std::scientific << "\t" << data.eph[svId-1].Crs_m_f64 << "\t" << data.eph[svId-1].deltaN_rad_sec_f64
                << std::scientific << "\t" << data.eph[svId-1].m0_rad_f64 << "\t" << data.eph[svId-1].Cuc_rad_f64 
                << std::scientific << "\t" << data.eph[svId-1].ecc_f64 << "\t" << data.eph[svId-1].Cus_rad_f64
                << std::scientific << "\t" << data.eph[svId-1].sqrtA_f64 << "\t" << data.eph[svId-1].Toe
                << std::scientific << "\t" << data.eph[svId-1].Toc << "\t" << data.eph[svId-1].Cic_rad_f64
                << std::scientific << "\t" << data.eph[svId-1].omega0_rad_f64 << "\t" << data.eph[svId-1].Cis_rad_f64
                << std::scientific << "\t" << data.eph[svId-1].i0_rad_f64 << "\t" << data.eph[svId-1].Crc_m_f64
                << std::scientific << "\t" << data.eph[svId-1].omega_rad_f64 << "\t" << data.eph[svId-1].OMGdot_rad_f64
                << std::scientific << "\t" << data.eph[svId-1].IDOT_rad_sec_f64 << "\t" << 0 << "\t" << data.eph[svId-1].BDTweek_s32
                << std::scientific << "\t" << 0 << "\t" << data.eph[svId-1].uraIndex_u8 << "\t" << data.eph[svId-1].svHealth_u8
                << std::scientific << "\t" << data.eph[svId-1].tgd1_s_f64 << "\t" << data.eph[svId-1].AODC_u16
                << std::scientific << "\t" << 0 << std::endl;
            }
            fileStream.close();
        }
    }
    else
    {
        new_subframe_map[svId-1].new_nav_msg.ephemeris     = 0;
    }

    if (new_subframe_map[svId-1].new_nav_msg.sbfrm4        == 1  ||
        new_subframe_map[svId-1].new_nav_msg.sbfrm5_1_6    == 1  ||
        new_subframe_map[svId-1].new_nav_msg.sbfrm5_11_23  == 1)
    {
        new_subframe_map[svId-1].new_nav_msg.almanac       = 1;
        new_subframe_map[svId-1].new_nav_msg.sbfrm4        = 0;
        new_subframe_map[svId-1].new_nav_msg.sbfrm5_1_6    = 0;
        new_subframe_map[svId-1].new_nav_msg.sbfrm5_11_23  = 0;
    }
    else
    {
        new_subframe_map[svId].new_nav_msg.almanac         = 0;
    }
}

void NavEng<::SatelliteSystem::BeiDou>::catch_subframe_data_D2 (const std::uint32_t(&word)[10], std::uint8_t svId)
{
}
