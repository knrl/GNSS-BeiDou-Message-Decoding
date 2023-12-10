#include "controller.hpp"

int main()
{
    std::string ubx_data{"dataset/COM3_210730_115228.ubx"};
    auto cnt = Controller<SatelliteSystem::BeiDou>::get_instance(ubx_data);
    cnt->run();
    return EXIT_SUCCESS;
}
