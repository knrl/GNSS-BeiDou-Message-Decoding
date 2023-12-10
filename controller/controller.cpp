#include "controller.hpp"

void ControllerBeidou::run(){
    std::ifstream fileStream(filename, std::ios::in | std::ios :: binary);   

    UBX::Frame_st ubxFrameData;
    while (fileStream.tellg() != -1){
        read_from_file(fileStream, ubxFrameData.preamble1);
        read_from_file(fileStream, ubxFrameData.preamble2);
        read_from_file(fileStream, ubxFrameData.messageClass);
        read_from_file(fileStream, ubxFrameData.messageID);
        read_from_file(fileStream, ubxFrameData.length);

        // UBX-RXM-SFRBX message check
        if (UBX::PRE1 == ubxFrameData.preamble1 && UBX::PRE2 == ubxFrameData.preamble2 && 
            UBX::MSSG_CLASS == ubxFrameData.messageClass && UBX::MSSG_ID == ubxFrameData.messageID &&
            ubxFrameData.length == UBX::PAYLOAD_LEN){
            
            /* read one by one */
            read_from_file(fileStream, ubxFrameData.payload);
            read_from_file(fileStream, ubxFrameData.checksumA);
            read_from_file(fileStream, ubxFrameData.checksumB);

            /* check for intended data */
            if (ubxFrameData.payload.gnssId == UBX::GNSS_ID &&
                (ubxFrameData.payload.svId >= UBX::SVID_BEGIN && ubxFrameData.payload.svId <= UBX::SVID_END)){

                /* calculate checksum if returns true from calc_checksum than decode the subframe */
                if (UBX::calc_checksum(ubxFrameData)) {
                    /* reserved0 represent sigId and we consider when sigId is equal to 0 */
                    switch(TrackingCode(ubxFrameData.payload.reserved0)){
                        case TrackingCode::B1I_D1:
                            DecoderEngine.catch_subframe_data_D1(ubxFrameData.payload.word, ubxFrameData.payload.svId);
                            break;
                        case TrackingCode::B1I_D2: break;
                        case TrackingCode::B2I_D1: break;
                        case TrackingCode::B2I_D2: break;
                        default:    /* error */    break;
                    }
                }
            }
        }
        else {
            /* set the current position to end of the subframe
               here ubxFrameData.length is for payload length and plus 2 is for 2 byte checksum (checksum A + checksum B) */
            fileStream.seekg((ubxFrameData.length + UBX::CHECKSUM_BYTES), std::ios::cur);
        }
    }

    fileStream.close();
}
