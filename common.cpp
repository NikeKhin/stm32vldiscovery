/// @file utility functions

#include "common.h"


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


void wait(Time us)
{
    for(uint64_t ticks = us.ticks()>>3; ticks != 0; ticks--)__NOP();
}
