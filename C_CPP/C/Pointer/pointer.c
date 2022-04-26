#include <stdio.h>

#define N_VALUES 5

int main()
{
    float value[N_VALUES];
    float* vp;
    for(vp=&value[N_VALUES];vp>&value[0];)
    {
        //故此语句有问题；
        // *vp-- = 0; //vp-- 是先使用当前*vp赋值后，再自减；即*vp = 0后，vp--；
                     //当vp = 1时，*vp指向的value[1]=0, 之后，vp=vp-1=0=&value[0],不满足vp>&value[0]故跳出循环，无法完成对&value[0]的赋值;
        
        *--vp = 0;   //vp先自减后，再操作赋值语句；
                     //当vp=1时，--vp为vp=vp-1=0,*vp指向的value[0]=0;
    }
}

