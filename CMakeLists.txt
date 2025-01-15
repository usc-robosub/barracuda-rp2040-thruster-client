cmake_minimum_required(VERSION 3.13)

# Initialize pico-sdk from submodule
include(pico-sdk/pico_sdk_init.cmake)

project(barracuda-rp2040-thruster-client)

# Initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# Rest of your project configuration
add_executable(thruster_client src/thruster_client.c)
target_link_libraries(thruster_client pico_stdlib hardware_gpio hardware_pwm)
pico_add_extra_outputs(thruster_client)