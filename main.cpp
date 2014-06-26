#include "bus.h"
#include "pin.h"
#include "adc.h"
#include "dac.h"
#include "tim.h"
#include "led.h"

int main()
{
    DigitalOut<PortC> pc9(9);   //this pin wired to green LED
    //PinOut<APB2> pc9(CPinID::p9);
    DigitalOutC pc8(8);         //this pin wired to blue LED
    DigitalInA pa0(0);          //this pin connected to user button (blue one)

    pc9=true;
    pc8=false;

    while (1)
    {
        // pause blinking when button is pressed
        if(pa0.get())
            wait(1_s);
        // toggle LEDs
        pc9=!pc9;
        pc8=!pc8;
        // insert delay
        wait(500_ms);
    }
    return 0;
}

