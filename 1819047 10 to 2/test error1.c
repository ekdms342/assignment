#include <stdio.h>
void Bit (int num,int bit);

int bit2 (int num);

int bn (int bit);

void sizenum (int num);

int main (void)
{
    int num;
    scanf("%d",&num);
    sizenum(num);
    return 0; 
}
void Bit (int num,int bit)
{
    int bit2 = 15- bit;     
    if(num>0)
    {
        printf("%d",0);
    }else 
    {
        printf("%d",1);
    }
    for(bit2;bit2!=0;bit2--)
    {
        printf("%d",0);
    }
}

int bit2 (int num)
{
    int bit=0;
    for(num = num*(-1);num!=0;)
    {
        num=num/2; 
        bit++;
    }
    return bit;
}

int bn (int bit)
{
    int i=1;
    for(bit-=1;bit>0;bit--)
    {
        i*=2;
    }
    return i;
}

void sizenum (int num)
{ 
    int bit,i;
    bit = bit2(num);
    i = bn(bit);
    Bit(num,bit);
    for(num = num*(-1);num>=0;)
    {
        printf("%d",num/i);
        num=num%i;
        i = i/2;
    }
}