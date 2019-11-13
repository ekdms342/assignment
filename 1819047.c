#include <stdio.h>
void Bit (int,int);
int bit2 (int);
void sizenum (int);

int main (void)
{
    int num;
    scanf("%d",&num);
    sizenum(num);
    return 0; 
}

void Bit (int num,int bit)
{
    if(num>0)
    {
        printf("%d",0);
    }else 
    {
        printf("%d",1);
    }
    for(bit;bit!=0;bit--)
    {
        printf("%d",0);
    }
}

int bit2 (int num)
{
    int bit=0;
    for(num = num*(-1)+2;num!=0;num=num/2)
    {
        bit++;
    }
    bit = 15-bit; 
    return bit;
}

void sizenum (int num)
{ 
    int bit;
    bit = bit2(num);
    Bit(num,bit);
    for(num = num*(-1);num!=0;num=num/2)
    {
        printf("%d",num%2);
    }
}
void cp1 (int num)
{
    for(num = num*(-1)+2;num!=0;num=num/2)
    {
        printf("%d",num%2 != 1);
    }
}
