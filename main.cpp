#include "bus.h"
#include "pin.h"
#include "adc.h"
#include "dac.h"
#include "tim.h"
#include "led.h"

int main()
{
    DigitalOut<PortC> pc9(9);
    DigitalOutC pc8(8);
    DigitalOutA pa0(0);

    while (1)
    {
        // pause blinking
        if(pa0.get())
            wait(1_s);
        // Turn on LD2 and LD3
        pc9=true;
        pc8=false;
        // Insert delay
        wait(500_ms);
        // Turn off LD3 and LD4
        pc9.set(false);
        pc8.set(true);
        // Insert delay
        wait(500_ms);
    }
    return 0;
}



// Declare timer #6 interrupt handler
#ifdef __cplusplus
extern "C" {
#endif
void TIM6_DAC_IRQHandler(void)
{
    Dac::tick();
}
#ifdef __cplusplus
}
#endif

