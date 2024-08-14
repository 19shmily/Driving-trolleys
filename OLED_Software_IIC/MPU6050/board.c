/*
 * 绔嬪垱寮�鍙戞澘杞‖浠惰祫鏂欎笌鐩稿叧鎵╁睍鏉胯蒋纭欢璧勬枡瀹樼綉鍏ㄩ儴寮�婧�
 * 寮�鍙戞澘瀹樼綉锛歸ww.lckfb.com
 * 鎶�鏈敮鎸佸父椹昏鍧涳紝浠讳綍鎶�鏈棶棰樻杩庨殢鏃朵氦娴佸涔�
 * 绔嬪垱璁哄潧锛歨ttps://oshwhub.com/forum
 * 鍏虫敞bilibili璐﹀彿锛氥�愮珛鍒涘紑鍙戞澘銆戯紝鎺屾彙鎴戜滑鐨勬渶鏂板姩鎬侊紒
 * 涓嶉潬鍗栨澘璧氶挶锛屼互鍩瑰吇涓浗宸ョ▼甯堜负宸变换
 * Change Logs:
 * Date           Author       Notes
 * 2024-05-23     LCKFB     first version
 */
#include "board.h"
#include "stdio.h"
#include "string.h"

volatile unsigned int delay_times = 0;
volatile unsigned char uart_data = 0;

void board_init(void)
{
//	SYSCFG_DL_init();


    NVIC_EnableIRQ(I2C_MPU6050_INST_INT_IRQN);
}

void delay_us(unsigned long us) 
{
    while(us--)
        delay_cycles(CPUCLK_FREQ/1000000);
}

//void delay_ms(unsigned long ms)
//{
//    while(ms--)
//	    delay_cycles(CPUCLK_FREQ/1000);
//}

void delay_1us(unsigned long __us)
{ 
    delay_us(__us); 
}

void delay_1ms(unsigned long ms)
{ 
    delay_ms(ms); 
}

//int fputc(int c, FILE* stream)
//{
//    return c;
//}
//
//int fputs(const char* restrict s, FILE* restrict stream)
//{
//    uint16_t i, len;
//    len = strlen(s);
//    for(i=0; i<len; i++)
//    {
//    }
//    return len;
//}

//int puts(const char *_ptr)
//{
//    int count = fputs(_ptr, stdout);
//    count += fputs("\n", stdout);
//    return count;
//}

