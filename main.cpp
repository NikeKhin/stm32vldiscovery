#include <string>
using namespace std;

#include "bus.h"
#include "pin.h"
#include "adc.h"
#include "dac.h"
#include "tim.h"
#include "led.h"


//---------------------------------
//APB1 bus1;
//APB2 bus2;


// Private function prototypes -----------------------------------------------
void Delay(__IO uint32_t nCount);

int main()
{
    ADConverter1 adc;
//    printf("\r\n ADC value: %d \r\n", AD_value);
//    TemperatureC = (uint16_t)((V25-AD_value)/Avg_Slope+25);
//    printf("Temperature: %d%cC\r\n", TemperatureC, 176);


    Dac1 dac;
    dac.start();

    Led led3(LedID::blue), led4(LedID::green);

    adc.start();

    const float Avg_Slope = 4.3; //when avg_slope=4.3mV/C at ref 3.3V
    int16_t V25 = adc.read();//1750when V25=1.41V at ref 3.3V
    while (1)
    {
        int16_t AD_value;
        AD_value = adc.read();

        //temperatureC = ((V25-AD_value)/Avg_Slope);

        // Turn on LD2 and LD3
        led3.on();
        led4.on();
        // Insert delay
        Delay(0xAFFFF);
        // Turn off LD3 and LD4
        led3.off();
        led4.off();
        // Insert delay
        Delay(0xAFFFF);

//    printf("\r\n ADC value: %d \r\n", AD_value);
    }

    // Infinite loop
    while (true) {}
    return 0;
}

void Delay(__IO uint32_t nCount)
{
    for(; nCount != 0; nCount--);
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

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
    /* User can add his own implementation to report the file name and line number,
       ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

    /* Infinite loop */
    /* Use call stack to find out the caller and reason */
    while (1);
}
#endif
/*
To fit flash size:
-Wl,--gc-sections
*/

/*
Button:
http://robocraft.ru/blog/ARM/666.html
http://www.cs.indiana.edu/~geobrown/book.pdf
http://habrahabr.ru/post/161863/
http://en.radzio.dxp.pl/stm32vldiscovery/lesson2,reading,the,button.html
*/


