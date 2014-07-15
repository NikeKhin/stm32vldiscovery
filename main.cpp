#include "bus.h"
#include "pin.h"
#include "adc.h"
#include "dac.h"
#include "tim.h"
#include "led.h"

int main()
{
    PinOut green(c9);          // output pin to light green LED
    PinOut blue(CPin::c8);     // this pin wired to blue LED
    PinIn button(a0);          // this pin connected to user button (blue one) in read mode

    green = true;
    blue = false;

    Analog converter(adc1);
    Analog::in1 left_channel(converter);
    Analog::in2 right_channel(converter);

    Timer timer{tim3, 5_s};
    converter.start(&timer);

    while (1)
    {
        // read two ADC channels in cycle
        int p = left_channel.read();
        int q = right_channel.read();
        // pause blinking when button is pressed
        if(button.get())
            wait(1_s);
        // toggle LEDs
        green=!green;
        blue.toggle(); // explicit way to toggle LED
        // insert delay
        wait(500_ms);
    }
    return 0;
}

