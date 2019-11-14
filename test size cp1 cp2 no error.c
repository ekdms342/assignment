#include <stdio.h>
void sizeBit (int num,int bit);
void cp1Bit (int,int);
int bit2 (int num);
int bn (int bit);
void sizenum (int num);
void cp1 (int);
void cp2 (int);
int main (void)
{
    int num;
    scanf("%d",&num);
    sizenum(num);
    printf("\n");
    cp1(num);
    printf("\n");
    cp2(num);
    return 0; 
}
void cp1Bit (int num,int bit)
{
    int bit2 = 15- bit;     
    if(num>0)
    {
        printf("%d",0);
        for(bit2;bit2!=0;bit2--)
        {
            printf("%d",0);
        }
    }else 
    {
        printf("%d",1);
        for(bit2;bit2!=0;bit2--)
        {
            printf("%d",1);
        }
    }
    
}
void sizeBit (int num,int bit)
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
    int bit,i,sn;
    bit = bit2(num);
    i = bn(bit);
    sizeBit(num,bit);
    num = num*(-1);
    while(i != 1)
    {
        sn = num/i;
        printf("%d",sn);
        num=num%i;
        i = i/2;
    }
    if(i==1 && num==1)
    {
        printf("%d",1);
    }else 
    {
        printf("%d",0);
    }
}

void cp1 (int num)
{
    int bit,i,sn;
    bit = bit2(num);
    i = bn(bit);
    cp1Bit(num,bit);
    num = num*(-1);
    while(i != 1)
    {
        sn = (num/i) != 1;
        printf("%d",sn);
        num=num%i;
        i = i/2;
    }
    if(i==1 && num==1)
    {
        printf("%d",0);
    }else 
    {
        printf("%d",1);
    }
}

void cp2 (int num)
{ 
    int sn, cp,i,bit,i2,cy;
    bit = bit2(num);
    i = bn(bit);
    cp1Bit(num,bit);
    num = num* (-1);
    cp = num;
    cy = 1;
    i2 = 1; 
    while(num!=0)
    {
        sn = (num % 2) != 1;
        num = num/2;
        i2 = i2*2;
        sn = sn+1;
        cy++;
        if(sn==1)
        {
            break;
        }
    }
    while(i >= i2)
    {
        sn = (cp/i) != 1;
        printf("%d",sn);
        cp = cp % i;
        i = i/2;
    }
    printf("%d",1);
    i = i/2;
    if(cy == 2)
    {
        while(i != 0)
        {
            printf("%d",1);
            i = i/2;
        }
    }else 
    {
        while(i != 0)
        {
            printf("%d",0);
            i = i/2;
        }
    }
}
