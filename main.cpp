#include <string>
using namespace std;

#include "bus.h"
#include "pin.h"
#include "adc.h"
#include "dac.h"
#include "tim.h"
#include "led.h"



// Private function prototypes -----------------------------------------------
void Delay(__IO uint32_t nCount);

int main()
{

    DigitalOut<PortC> pc9(9);
    DigitalOutC pc8(8);
    DigitalOutA pa0(0);

    while (1)
    {
        // pause blinking
        if(pa0.get())
            Delay(0xBFFFF);
        // Turn on LD2 and LD3
        pc9.set(true);
        pc8.set(false);
        // Insert delay
        Delay(0xAFFFF);
        // Turn off LD3 and LD4
        pc9.set(false);
        pc8.set(true);
        // Insert delay
        Delay(0xAFFFF);
    }

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
