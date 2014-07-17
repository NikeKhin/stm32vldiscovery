/****************************************************************************
*  Copyright (c) 2009 by Michael Fischer. All rights reserved.
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions
*  are met:
*
*  1. Redistributions of source code must retain the above copyright
*     notice, this list of conditions and the following disclaimer.
*  2. Redistributions in binary form must reproduce the above copyright
*     notice, this list of conditions and the following disclaimer in the
*     documentation and/or other materials provided with the distribution.
*  3. Neither the name of the author nor the names of its contributors may
*     be used to endorse or promote products derived from this software
*     without specific prior written permission.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL
*  THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
*  OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
*  AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
*  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF
*  THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
*  SUCH DAMAGE.
*
****************************************************************************
*  History:
*
*  28.03.09  mifi   First Version, based on the original syscall.c from
*                   newlib version 1.17.0
****************************************************************************/

#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

//NK: Added
#ifdef STM32F10X_MD_VL
#include <stm32f10x.h>
#endif

#ifdef STM32L1XX_MD
#include <stm32l1xx.h>//NK: Added
#endif

/***************************************************************************/
//NK: Added platform specific

#define STDIN USART1
void uart_putc(char ch)
{
    while (USART_GetFlagStatus(STDIN, USART_FLAG_TC) == RESET);
    USART_SendData(STDIN, (uint8_t) ch);
}

char uart_getc()
{
    while (USART_GetFlagStatus(STDIN, USART_FLAG_RXNE) == RESET);
    char c = (char) (USART_ReceiveData(STDIN) & (uint16_t) 0x01FF);
    return c;
}

/***************************************************************************/

int _read_r (struct _reent *r, int file, char * ptr, int len)
{
  r = r;
  file = file;
  ptr = ptr;
  len = len;
#if 1 //NK: Turned on
  int index;

  /* For example, input string by UART */
  for(index=0; index<len; index++)
  {
    *ptr++ = uart_getc();
  }
  return len;
#else
  errno = EINVAL;
  return -1;
#endif
}

/***************************************************************************/

int _lseek_r (struct _reent *r, int file, int ptr, int dir)
{
  r = r;
  file = file;
  ptr = ptr;
  dir = dir;

  return 0;
}

/***************************************************************************/

int _write_r (struct _reent *r, int file, char * ptr, int len)
{
  r = r;
  file = file;
  ptr = ptr;

#if 1 //NK: Turned on
  int index;

  /* For example, output string by UART */
  for(index=0; index<len; index++)
  {
    if (ptr[index] == '\n')
    {
      uart_putc('\r');
    }

    uart_putc(ptr[index]);
  }
#endif

  return len;
}

/***************************************************************************/

int _close_r (struct _reent *r, int file)
{
  return 0;
}

/***************************************************************************/

/* Register name faking - works in collusion with the linker.  */
register char * stack_ptr asm ("sp");

caddr_t _sbrk_r (struct _reent *r, int incr)
{
  extern char   end asm ("end"); /* Defined by the linker.  */
  static char * heap_end;
  char *        prev_heap_end;

  if (heap_end == NULL)
    heap_end = & end;

  prev_heap_end = heap_end;

  if (heap_end + incr > stack_ptr)
  {
      /* Some of the libstdc++-v3 tests rely upon detecting
        out of memory errors, so do not abort here.  */
#if 0
      extern void abort (void);

      _write (1, "_sbrk: Heap and stack collision\n", 32);

      abort ();
#else
      errno = ENOMEM;
      return (caddr_t) -1;
#endif
  }

  heap_end += incr;

  return (caddr_t) prev_heap_end;
}

/***************************************************************************/

int _fstat_r (struct _reent *r, int file, struct stat * st)
{
  r = r;
  file = file;

  memset (st, 0, sizeof (* st));
  st->st_mode = S_IFCHR;
  return 0;
}

/***************************************************************************/

int _isatty_r(struct _reent *r, int fd)
{
  r = r;
  fd = fd;

  return 1;
}

/***************************************************************************/
//NK: Added
int _getpid()
{
	return 1;
}

int _kill(int pid, int sig)
{
	errno = EINVAL;
	return (-1);
}

void _exit(int i)
{
	while (1);
}


/*** EOF ***/


