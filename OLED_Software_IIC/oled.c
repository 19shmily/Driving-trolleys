//////////////////////////////////////////////////////////////////////////////////
//  鏂  浠  鍚    : oled.c
//  鐗  鏈  鍙    : v2.0
//  浣     鑰    : Torris
//  鐢熸垚鏃ユ湡   : 2024-07-08
//  鏈 杩戜慨鏀    :
//  鍔熻兘鎻忚堪   : 0.96瀵窸LED 鎺ュ彛婕旂ず渚嬬▼(MSPM0G绯诲垪)
//  椹卞姩IC     : SSD1306/SSD1315
//              璇存槑:
//              ----------------------------------------------------------------
//              GND    鐢垫簮鍦
//              VCC    鎺 3.3v鐢垫簮
//              SCL    PA12锛堟椂閽燂級
//              SDA    PA13锛堟暟鎹級
//******************************************************************************/
#include "ti_msp_dl_config.h"
#include "oled.h"
#include "bmp.h"
#include "board.h"
#include "bsp_mpu6050.h"
#include "inv_mpu.h"
#include "stdio.h"
#include "string.h"
#define maic 13

int left_go=0,right_go=0;

int flag_ti2=3;
int flag_ti2_out=0;
int flag_ti4_out=0;
int reflect=0;
uint8_t status;
int jiaodu_zhi=131;
int fuzhi=0;
int zitai[2]={0};
int ti3_zitai[8]={0};
int buzhou=0;
int gai=0;
int MCC=0;
void motor_Ctrl(void);
void motor_sport(uint8_t flag, int16_t duty);
void Get_Light_TTL(void);
uint32_t r1=0,r2=0,l1=0,l2=0;
uint32_t all_r=0,all_l=0;
volatile bool readl4=0,readl3=0,readl2=0,readl1=0,readm=0,readr4=0,readr3=0,readr2=0,readr1=0;
uint32_t or=999,ol=999;
uint32_t ssr=100,ssl=100;
float pitch=0,roll=0,yaw=0;
int qiji=0;
int sudu_ll=25,sudu_rr=25;
int flag=0;
void show();
int key1=0,key2=0,key3=0,key4=0,keyg=0;
int key11=0,key22=0,key33=0,key44=0,keygo=0;
int wyyj=0;
void jiaodu_init()
{
    zitai[0]=jiaodu_zhi;
    zitai[1]=jiaodu_zhi+180;

    ti3_zitai[0]=jiaodu_zhi-38;     ti3_zitai[2]=jiaodu_zhi-38;     ti3_zitai[4]=jiaodu_zhi-39;     ti3_zitai[6]=jiaodu_zhi-39;
    ti3_zitai[1]=jiaodu_zhi+180+34;    ti3_zitai[3]=jiaodu_zhi+180+35;    ti3_zitai[5]=jiaodu_zhi+180+35;    ti3_zitai[7]=jiaodu_zhi+180+36;

//    ti3_zitai[0]=jiaodu_zhi-39;     ti3_zitai[2]=jiaodu_zhi-39;     ti3_zitai[4]=jiaodu_zhi-40;     ti3_zitai[6]=jiaodu_zhi-41;
//    ti3_zitai[1]=jiaodu_zhi+180+33;    ti3_zitai[3]=jiaodu_zhi+180+33;    ti3_zitai[5]=jiaodu_zhi+180+33;    ti3_zitai[7]=jiaodu_zhi+180+32;
}

void shengguang_tishi();

int main( void )
{
    SYSCFG_DL_init();
    uint8_t ret = 1;
    NVIC_EnableIRQ(TIMER_1s_INST_INT_IRQN);
    DL_TimerG_startCounter(TIMER_1s_INST);
    DL_TimerA_startCounter(PWM_0_INST);
    OLED_Init();        //鍒濆鍖朞LED
    board_init();
    MPU6050_Init();
    uint8_t lj=0;
    lj=mpu_dmp_init();
    jiaodu_init();
    NVIC_EnableIRQ(GPIO_Encoder_INT_IRQN);
    while(1)
    {
        if(MCC){shengguang_tishi();MCC=0;}
        show();
    }
}

void show()
{
            OLED_ShowNum(13,6,r2,3,16);
            OLED_ShowNum(13,4,l2,3,16);
            OLED_ShowNum(103,0,or,3,16);
            OLED_ShowNum(13,0,ol,3,16);
            OLED_ShowNum(0,2,key1,1,16);
            OLED_ShowNum(15,2,key2,1,16);
            OLED_ShowNum(30,2,key3,1,16);
            OLED_ShowNum(45,2,key4,1,16);
            OLED_ShowNum(53,4,yaw+180,3,16);

}

void GROUP1_IRQHandler(void)
{
    uint32_t gpioB=DL_GPIO_getEnabledInterruptStatus(GPIOB, GPIO_Encoder_R_A_PIN|GPIO_Encoder_L_A_PIN);
    if(gpioB&GPIO_Encoder_R_A_PIN)
    {
            r1++;
            DL_GPIO_clearInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_R_A_PIN);
    }
    if(gpioB&GPIO_Encoder_L_A_PIN)
        {
            l1++;
            DL_GPIO_clearInterruptStatus(GPIO_Encoder_PORT, GPIO_Encoder_L_A_PIN);
        }
    else ;

}


////////////////////////////////////////////////////////////////////////////////////////////////////////////
void out_pwm()
{
    if(ol>990){ol=990;}
    if(or>990){or=990;}
    if(or<450){or=450;}
    if(ol<450){ol=450;}
    DL_TimerA_setCaptureCompareValue(PWM_0_INST,ol,DL_TIMER_CC_0_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_0_INST,or,DL_TIMER_CC_1_INDEX);

}
/////////////////////////////////////////////////////////////////////////////////////////////////////

void out_stop()
{
    ol=999;
    or=999;
    DL_TimerA_setCaptureCompareValue(PWM_0_INST,ol,DL_TIMER_CC_0_INDEX);
    DL_TimerA_setCaptureCompareValue(PWM_0_INST,or,DL_TIMER_CC_1_INDEX);
}



float xianfu_hanshu(float fuzhimax,float fuzhimin,float shuruzhi)
{
    if(shuruzhi<fuzhimin)shuruzhi=fuzhimin;
    if(shuruzhi>fuzhimax)shuruzhi=fuzhimax;
    return shuruzhi;
}



void shengguang_tishi()
{
DL_GPIO_setPins(GPIOB, GPIO_sheng_PIN_0_PIN);
DL_GPIO_setPins(GPIOB, GPIO_guang_PIN_1_PIN);
delay_cycles(5000000);
DL_GPIO_clearPins(GPIOB, GPIO_sheng_PIN_0_PIN);
DL_GPIO_clearPins(GPIOB, GPIO_guang_PIN_1_PIN);
}

//基础速度PID控制器Encoder=Basic_Speed_error£¬Target=0;
int Motor_basic_l_PD (int Encoder,int Target)
{
    float Position_KP=15,Position_KD=0,Position_KI=0;
    static float Biasl,Last_Biasl,Pwml;
    static float pid_li=0;
    Biasl=Encoder-Target;
    if((Biasl<2)&&(Biasl>-2))Biasl=0;
    pid_li+=Biasl;
    pid_li=xianfu_hanshu(200, -200, pid_li);
    Pwml=Position_KP*Biasl+Position_KD*(Biasl-Last_Biasl)+(Position_KI*pid_li);
    Last_Biasl=Biasl;
    return Pwml;
}
int Motor_basic_r_PD (int Encoder,int Target)
{
    float Position_KP=15,Position_KD=0,Position_KI=0;
    static float Biasr,Last_Biasr,Pwmr;
    static float pid_ri=0;
    Biasr=Encoder-Target;
    if((Biasr<2)&&(Biasr>-2))Biasr=0;
    pid_ri+=Biasr;
    pid_ri=xianfu_hanshu(200, -200, pid_ri);
    Pwmr=Position_KP*Biasr+Position_KD*(Biasr-Last_Biasr)+(Position_KI*pid_ri);
    Last_Biasr=Biasr;
    return Pwmr;
}

float pid_huidu(float now)
{
    float Position_KP=60,Position_KD=4,Position_KI=0;
            static float Biasq,Last_Biasq,out_eq;
            static float pid_iq=0;
            Biasq=now;
            if((Biasq<2)&&(Biasq>-2))Biasq=0;
            pid_iq+=Biasq;
            pid_iq=xianfu_hanshu(200, -200, pid_iq);
            out_eq=Position_KP*Biasq+Position_KD*(Biasq-Last_Biasq)+(Position_KI*pid_iq);
            Last_Biasq=Biasq;
            return out_eq;
}

float pid_toloy(float mubiao,float now)
{
    float Position_KP=3,Position_KD=0,Position_KI=0;
        static float Bias,Last_Bias,out_e;
        static float pid_i=0;
        Bias=now-mubiao;
        if((Bias<2)&&(Bias>-2))Bias=0;
        pid_i+=Bias;
        pid_i=xianfu_hanshu(200, -200, pid_i);
        out_e=Position_KP*Bias+Position_KD*(Bias-Last_Bias)+(Position_KI*pid_i);
        Last_Bias=Bias;
        return out_e;
}


void zhixing()
{
    float toloy_zitai=pid_toloy(yaw,zitai[buzhou] );////////////////
    ol=1000-Motor_basic_l_PD(sudu_ll,l2)+toloy_zitai;
    or=1000-Motor_basic_r_PD(sudu_rr,r2)-toloy_zitai;
}

void zhixing_3()
{
    float toloy_zitai=pid_toloy(yaw,ti3_zitai[gai] );////////////////
    if(gai%2){left_go=0;right_go=1;}
    else {left_go=1;right_go=0;}
    ol=1000-Motor_basic_l_PD(sudu_ll,l2)+toloy_zitai;
    or=1000-Motor_basic_r_PD(sudu_rr,r2)-toloy_zitai;
    wyyj=0;
}


void xunxian()
{
    wyyj++;
    if(wyyj<5)
    {
        if(left_go==1)
        {
            ol=990;
            or=850;
        }
        else if(right_go==1)
        {
            ol=850;
            or=990;
        }
    }
    else{
        float toloy_zitai=pid_huidu(reflect);
        ol=1000-Motor_basic_l_PD(sudu_ll,l2)-toloy_zitai;
        or=1000-Motor_basic_r_PD(sudu_rr,r2)+toloy_zitai;
        left_go=0;right_go=0;
    }
}


int tmp=0;
void chubu_shiyan(){
if(flag<4&&(readm==0&&(readl1==0&&(readl2==0&&(readl3==0&&(readr1==0&&(readr2==0&&readr3==0)))))))
{
    flag++;
    return;
}
else if(flag>3&&(!readm &&(!readl1 &&(!readl2 &&(!readl3 &&(!readr1 &&(!readr2 &&(!readr3))))))))
{
    tmp=0;
    flag_ti2++;
    if(flag_ti2==1){buzhou=!buzhou;flag_ti2_out++;MCC=1;gai++;}
    if(key2==1)
        zhixing();
    else if(key3==1)
        zhixing_3();
    else if(key4==1)
            zhixing_3();

    return;
}
    if(!tmp)
    {
        MCC=1;
    }
    tmp++;
    flag=0;
    xunxian();
    flag_ti2=0;
}

void key_zero()
{
    key11=0;key1=0;
    key22=0;key2=0;
    key33=0;key3=0;
    key44=0;key4=0;
}


void TIMER_1s_INST_IRQHandler(void)
{
     status = mpu_dmp_get_data(&pitch,&roll,&yaw);
     readl1=DL_GPIO_readPins(GPIOA, GPIO_huidu_PIN_l1_PIN);
     readl2=DL_GPIO_readPins(GPIOA, GPIO_huidu_PIN_l2_PIN);
     readl3=DL_GPIO_readPins(GPIOA, GPIO_huidu_PIN_l3_PIN);
             readm=DL_GPIO_readPins(GPIOA, GPIO_huidu_PIN_m_PIN);
     readr1=DL_GPIO_readPins(GPIOA, GPIO_huidu_PIN_r1_PIN);
     readr2=DL_GPIO_readPins(GPIOA, GPIO_huidu_PIN_r2_PIN);
     readr3=DL_GPIO_readPins(GPIOA, GPIO_huidu_PIN_r3_PIN);
    key11+=DL_GPIO_readPins(GPIOB, GPIO_BUTTON_PIN_MOD1_PIN);
    key22+=DL_GPIO_readPins(GPIOB, GPIO_BUTTON_PIN_MOD2_PIN);
    key33+=DL_GPIO_readPins(GPIOB, GPIO_BUTTON_PIN_MOD3_PIN);
    key44+=DL_GPIO_readPins(GPIOB, GPIO_BUTTON_PIN_MOD4_PIN);
    keygo+=DL_GPIO_readPins(GPIOB, GPIO_BUTTON_PIN_GO_PIN);
             if(readl3)reflect=-8;
        else if(readl2)reflect=-6;
        else if(readl1)reflect=-3;
          else if(readm)reflect=0;
         else if(readr1)reflect=3;
         else if(readr2)reflect=6;
         else if(readr3)reflect=8;
        switch (DL_TimerG_getPendingInterrupt(TIMER_1s_INST)){
        case DL_TIMER_IIDX_ZERO:
            r2=r1;
            all_r+=r1;
            r1=0;
            l2=l1;
            all_l+=l1;
            l1=0;
            break;
        default:
            break;}
    if(key11){key_zero();key1=1;}
    if(key22){key_zero();key2=1;}
    if(key33){key_zero();key3=1;}
    if(key44){key_zero();key4=1;}
    if(keygo){keyg=1;}
    if(keyg==1){fuzhi++;
    if(fuzhi==1)
        {jiaodu_zhi=yaw;//111111111111
    jiaodu_init();}
    if(key2==1){
        if(flag_ti2_out<2){
         chubu_shiyan();
         out_pwm();
    }
        else out_stop();
    }
    else if (key1==1)
    {
        if(readm||reflect){
        out_stop();
        MCC=1;
        key1=0;
        }
        else {
        buzhou=0;
        zhixing();
        out_pwm();}
    }
    else if (key3==1)
    {
            if(flag_ti2_out<2){
              chubu_shiyan();
              out_pwm();
            }

            else out_stop();
    }
    else if (key4==1)
    {
        if(flag_ti2_out<8)
        {
            chubu_shiyan();
            out_pwm();
        }

                else out_stop();
    }
    else
        ;}
    else out_stop();
}

