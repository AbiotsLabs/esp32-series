#include "driver/gpio.h"

#include "esp_log.h"

extern "C"
{
    static const char *TAG = "BLINK";

    void blink()
    {
        int counter = 0;
        while (true)
        {
            if (counter < 500)
            {
                gpio_set_level(GPIO_NUM_2, 1);
                ESP_LOGD(TAG, "Switching on the led");
            }
            else
            {
                gpio_set_level(GPIO_NUM_2, 0);
                ESP_LOGD(TAG, "Switching off the led");
            }
            if (counter > 1000)
            {
                counter = 0;
            }
            ++counter;
        }
    }

    void ldrSwitch()
    {
        ESP_LOGD(TAG, "Starting the LDR switch");
        while (true)
        {
            if (gpio_get_level(GPIO_NUM_16) == 1)
            {
                ESP_LOGD(TAG,"detected.....");
                gpio_set_level(GPIO_NUM_2, 1);
            }
            else
            {
                gpio_set_level(GPIO_NUM_2, 0);
            }
        }
    }

    void app_main()
    {
        /* gpio_pad_select_gpio(GPIO_NUM_2);
        ESP_ERROR_CHECK(gpio_set_direction(GPIO_NUM_2, GPIO_MODE_OUTPUT));
        ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_2, 1));

        gpio_pad_select_gpio(GPIO_NUM_16);
        ESP_ERROR_CHECK(gpio_set_direction(GPIO_NUM_16, GPIO_MODE_OUTPUT));
        ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_16, 1));

        gpio_pad_select_gpio(GPIO_NUM_22);
        ESP_ERROR_CHECK(gpio_set_direction(GPIO_NUM_22, GPIO_MODE_OUTPUT));
        ESP_ERROR_CHECK(gpio_set_level(GPIO_NUM_22, 1)); */

        gpio_config_t gpioOutputConfig{
            GPIO_SEL_2,
            GPIO_MODE_OUTPUT,
            GPIO_PULLUP_DISABLE,
            GPIO_PULLDOWN_DISABLE,
            GPIO_INTR_DISABLE};
        gpio_config(&gpioOutputConfig);

        gpio_config_t gpioInputConfig{
            GPIO_SEL_16,
            GPIO_MODE_INPUT,
            GPIO_PULLUP_DISABLE,
            GPIO_PULLDOWN_DISABLE,
            GPIO_INTR_DISABLE};
        gpio_config(&gpioInputConfig);
        ldrSwitch();
    }
}
