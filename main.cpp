#include "bus.h"
#include "pin.h"
#include "adc.h"
#include "dac.h"
#include "tim.h"
#include "led.h"

int main()
{
    //DigitalOut<PortC> pc9(9);   //this pin wired to green LED
    PinOut green(c9);
    PinOut blue(CPin::c8);         //this pin wired to blue LED
    PinIn button(a0);          //this pin connected to user button (blue one)

    green.set(true);
    blue.set(false);

    Analog adc(APB2::adc1);
    Analog::in0 left_channel(adc);
    Analog::in1 right_channel(adc);

    adc.start();

    int p = left_channel.read();
    int q = left_channel.read();

    while (1)
    {
        // pause blinking when button is pressed
        if(button.get())
            wait(1_s);
        // toggle LEDs
        green=!green;
        blue.toggle();
        // insert delay
        wait(500_ms);
    }
    return 0;
}

