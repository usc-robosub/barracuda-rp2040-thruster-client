#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "hardware/pwm.h"

int main() {
    // Initialize the GPIO and PWM
    gpio_set_function(4, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(4);

    // Set the PWM frequency
    pwm_set_wrap(slice_num, 24999); // 20ms period (50Hz)

    // Send a single pulse of 1500us
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 1875); // 1500us pulse width
    pwm_set_enabled(slice_num, true);
    sleep_ms(20); // Wait for one period (20ms)
    pwm_set_enabled(slice_num, false);

    // Send continuous pulses of 1600us
    pwm_set_chan_level(slice_num, PWM_CHAN_A, 2000); // 1600us pulse width
    pwm_set_enabled(slice_num, true);

    // Keep the program running to maintain the PWM output
    while (true) {
        tight_loop_contents();
    }

    return 0;
}