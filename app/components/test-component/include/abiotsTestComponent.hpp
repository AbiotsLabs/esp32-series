#pragma once

#include <stdio.h>

#include "esp_log.h"

extern "C"
{
    class AbiotsTestComponent
    {
    private:
        const char *TAG = "AbiotsTestComponent";
        uint32_t size;
        const char *abiotsTestName = CONFIG_ABIOTS_TEST_NAME;
        const char *projectVer = CONFIG_APP_PROJECT_VER;

    public:
        AbiotsTestComponent(uint32_t size) : size(size){};
        void toString(void);
    };
}