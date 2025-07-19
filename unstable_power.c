/*
 * wii u UNSTBLE_PWR jig (Pico C SDK)
 */

#include "pico/stdlib.h"

// gpios 14, 15, 16, 17, and LED (25)
uint32_t gpio_bitmask = (1u << 14) | (1u << 15) | (1u << 16) | (1u << 17) | (1u << 25);

uint8_t timings[] = {66, 16, 16, 18, 16, 16, 16, 18, 16, 16, 16, 18, 16, 16, 16, 18, 16, 16, 16, 18, 16,
                     16, 16, 18, 16, 16, 16, 18, 8,  18, 16, 18, 8,  18, 16, 33, 45, 33, 16, 16, 91, 18,
                     16, 33, 41, 37, 8,  18, 29, 16, 16, 18, 16, 16, 16, 18, 16, 16, 16, 18, 16, 16, 16,
                     18, 8,  18, 16, 18, 8,  18, 16, 18, 8,  18, 16, 18, 8,  18, 16, 16, 70, 100};

bool pin = false;

int main()
{
  gpio_init_mask(gpio_bitmask);
  gpio_set_dir_out_masked(gpio_bitmask);
  gpio_clr_mask(gpio_bitmask);

  while (true) {
    pin = false;
    for (int i = 0; i < 82; i++) {
      gpio_put_masked(gpio_bitmask, pin ? gpio_bitmask : 0);
      sleep_ms(timings[i]);
      pin = !pin;
    }
  }
}
