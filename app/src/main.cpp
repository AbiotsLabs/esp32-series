#include "abiotsTestComponent.hpp"

extern "C"
{
    void app_main()
    {
        AbiotsTestComponent test(100);
        test.toString();
    }
}
