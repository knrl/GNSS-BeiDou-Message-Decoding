/*------------------------------------------------------------------------------
*
* @author: Mehmet Kaan Erol
*
------------------------------------------------------------------------------*/

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include <utility>
#include "core.hpp"
#include "navigation_engine.hpp"

template <SatelliteSystem DecoderClass>
class Controller;

/*  Typedefs */
using ControllerBeidou = Controller<SatelliteSystem::BeiDou>;
using NavEngBeidou = NavEng<SatelliteSystem::BeiDou>;

template<>
class Controller<SatelliteSystem::BeiDou>
{
public:
    Controller(Controller &other) = delete;
    void operator=(const Controller&) = delete;
    static ControllerBeidou* get_instance(const std::string& filename);

    void run();

protected:
    explicit Controller(std::string filename_d) :
        filename(std::move(filename_d)) {}
    ~Controller() = default;

private:
    NavEngBeidou DecoderEngine;
    static ControllerBeidou* Cnt_p;
    std::string filename;
};

/* Definitions */
ControllerBeidou* ControllerBeidou::Cnt_p = nullptr;

ControllerBeidou* ControllerBeidou::get_instance(const std::string& filename) {
    if (Cnt_p == nullptr) {
        Cnt_p = new ControllerBeidou(filename);
    }
    return Cnt_p;
}

#endif /* CONTROLLER_HPP */
