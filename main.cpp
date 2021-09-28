#include <fstream>
#include "include/navigation_engine.hpp"

typedef struct{
    uint8_t gnssId;
    uint8_t svId;
    uint8_t reserved0;
    uint8_t freqId;
    uint8_t numWords;
    uint8_t chn;
    uint8_t version;
    uint8_t reserved1;
    uint32_t word[10];
} Payload;

typedef struct{
    uint8_t preamble1;
    uint8_t preamble2;
    uint8_t messageClass;
    uint8_t messageID;
    uint16_t length;
    Payload payload;
    uint8_t checksumA;
    uint8_t checksumB;
} UBXframe;

const static unsigned char pre1           = 181;
const static unsigned char pre2           = 98;
const static unsigned char mssgClass      = 2;
const static unsigned char mssgID         = 19; 
const static unsigned char gnssid         = 3;
const static unsigned char svid_begin     = 1;
const static unsigned char svid_end       = 63;
const static unsigned char numWords       = 10;
const static unsigned char payload_length = 8 + 4 * numWords;
const static unsigned char num_of_sat     = (svid_end - svid_begin) + 1;

NavEng<SatelliteSystem::BeiDou> BeiDouEng;

template <class T>
void read_from_file(std::ifstream& fileStream, T& variable){
    fileStream.read((char*) &variable, sizeof(variable));
}

bool calc_checksum(UBXframe d){
    uint8_t *data = &d.messageClass;
    uint8_t CK_A = 0, CK_B = 0;
    for(int i=0;i<sizeof(d) - 6;i++)
    {
        if (i == 4 || i == 5) continue;
        //std::cout << std::hex << (uint) data[i] <<  " ";
        CK_A = CK_A + data[i];
        CK_B = CK_A + CK_B;
    }

    if (CK_A == d.checksumA && CK_B == d.checksumB){
        return 1;
    }
    return 0;
}

void run(std::string filename){
    std::ifstream fileStream(filename, std::ios::in | std::ios :: binary);   

    UBXframe d;
    while (fileStream.tellg() != -1){
        read_from_file(fileStream, d.preamble1);
        read_from_file(fileStream, d.preamble2);
        read_from_file(fileStream, d.messageClass);
        read_from_file(fileStream, d.messageID);
        read_from_file(fileStream, d.length);

        // UBX-RXM-SFRBX message check
        if (pre1 == d.preamble1 && pre2 == d.preamble2 && 
            mssgClass == d.messageClass && mssgID == d.messageID &&
            d.length == payload_length){
            read_from_file(fileStream, d.payload);
            read_from_file(fileStream, d.checksumA);
            read_from_file(fileStream, d.checksumB);

            if (d.payload.gnssId == gnssid && (d.payload.svId >= svid_begin && 
                d.payload.svId <= svid_end)){
                // calculate checksum if return true from calc_checksum than decode the subframe
                if (calc_checksum(d)){
                    // reserved0 represent sigId and we consider when sigId is equal to 0 
                    uint8_t *temp = &d.payload.svId;
                    switch(d.payload.reserved0){
                        case 0: /* BeiDou B1I|D1 */
                            BeiDouEng.catch_subframe_data_D1(d.payload.word, d.payload.svId);
                            break;
                        case 1: /* BeiDou B1I|D2 */ break;
                        case 2: /* BeiDou B2I|D1 */
                            break;
                        case 3: /* BeiDou B2I|D2 */ break;
                        default:     /* error */    break;
                    }
                }
            }
        }
        else{
            // set the current position to end of the subframe
            // here d.length is for payload length and plus 2 is for 2 byte checksum (checksum A + checksum B) 
            fileStream.seekg((d.length + 2), std::ios::cur);
        }
    }
    fileStream.close();
}

int main()
{
    std::string filename = "dataset/COM3_210730_115228.ubx";

    run(filename);
    return 0;
}