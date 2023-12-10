#ifndef CORE_HPP
#define CORE_HPP

#include <iostream>
#include <fstream>
#include <string>

/* Constants for UBX frame */
namespace UBX {
    constexpr uint8_t MAX_WORD_SIZE  = 10;
    constexpr uint8_t PRE1           = 181;
    constexpr uint8_t PRE2           = 98;
    constexpr uint8_t MSSG_CLASS     = 2;
    constexpr uint8_t CHECKSUM_BYTES = 2;
    constexpr uint8_t MSSG_ID     = 19; 
    constexpr uint8_t GNSS_ID     = 3;
    constexpr uint8_t SVID_BEGIN  = 1;
    constexpr uint8_t SVID_END    = 63;
    constexpr uint8_t PAYLOAD_LEN = 8 + 4 * MAX_WORD_SIZE;

    typedef struct {
        uint8_t gnssId{};
        uint8_t svId{};
        uint8_t reserved0{};
        uint8_t freqId{};
        uint8_t numWords{};
        uint8_t chn{};
        uint8_t version{};
        uint8_t reserved1{};
        uint32_t word[MAX_WORD_SIZE]{};
    } Payload_st;

    typedef struct {
        uint8_t preamble1{};
        uint8_t preamble2{};
        uint8_t messageClass{};
        uint8_t messageID{};
        uint16_t length{};
        Payload_st payload{};
        uint8_t checksumA{};
        uint8_t checksumB{};
    } Frame_st;

    inline bool calc_checksum(const Frame_st& ubxFrameData) {
        const auto *data_p = static_cast<const uint8_t*>(&ubxFrameData.messageClass);
        uint8_t CK_A{};
        uint8_t CK_B{};

        size_t frame_len = sizeof(ubxFrameData) - 6;
        for(size_t i=0;i<frame_len;i++) {
            if (i == 4 || i == 5) continue;
            CK_A = CK_A + data_p[i];
            CK_B = CK_A + CK_B;
        }

        if (CK_A == ubxFrameData.checksumA && CK_B == ubxFrameData.checksumB) {
            return EXIT_FAILURE;
        }

        return EXIT_SUCCESS;
    }
};

template <class T>
inline void read_from_file(std::ifstream& fileStream, T& variable) {
    fileStream.read(reinterpret_cast<char*>(&variable), sizeof(variable));
}

#endif /* CORE_HPP */
