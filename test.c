#include <stdio.h>
int main (void)
{
    int psbit = 0, sbit = 0, rebit, i = 0, j = 0, end = 0, end2 = 0;
	int ps[64] = { 0 };
	int s[64] = { 0 };
    int Ps , S , psbit2, sbit2;
    scanf("%d %d", &Ps, &S);
    if(Ps <= 0)
    {
        for( ; Ps != 0; Ps = Ps/2 )
        {
            ps[i] = Ps % 2;
            i++;
            psbit++;
        }
        i -= 1;
        for(psbit2 = 0 ; psbit2 < psbit / 2 ; psbit2++)
        {
            Ps = ps[i];
            ps[i] = ps[psbit2];
            ps[psbit2] = Ps;
            i--;
        }
    }else
    {
       for( ; Ps != 0; Ps = Ps/2 )
        {
            ps[i] = Ps % 2;
            i++;
            psbit++;
        }
        i -= 1;
        for(psbit2 = 0 ; psbit2 < psbit / 2 ; psbit2++)
        {
            Ps = ps[i];
            ps[i] = ps[psbit2];
            ps[psbit2] = Ps;
            i--;
        }
    }

    for (j = 0; j < psbit; j++)//피승수 print
	{
		printf("%d", ps[j]);
	}
	printf("\n");

    if(S <= 0)
    {
        S *= (-1);
        for( ; S != 0; S = S/2 )
        {
            s[i] = S % 2;
            i++;
            psbit++;
        }
        i -= 1;
        for(sbit2 = 0 ; sbit2 < sbit / 2 ; sbit2++)
        {
            S = s[i];
            s[i] = s[sbit2];
            s[sbit2] = S;
            i--;
        }
    }else
    {
       for( ; S != 0; S = Ps/2 )
        {
            s[i] = S % 2;
            i++;
            sbit++;
        }
        i -= 1;
        for(sbit2 = 0 ; sbit2 < sbit / 2 ; sbit2++)
        {
            S = s[i];
            s[i] = s[sbit2];
            s[sbit2] = S;
            i--;
        }
    }
    for (j = 0; j < sbit; j++)//피승수 print
	{
		printf("%d", s[j]);
	}
	printf("\n");
}

