#include <stdio.h>
int main(void)
{
	int psbit = 0, sbit = 0, rebit, i = 1, j = 0, end = 0, end2 = 0;
	int ps[64] = { 0 };
	int s[64] = { 0 };
	int Ps, S, psbit2, sbit2, sign = 0;
	scanf("%d %d", &Ps, &S);
	if (Ps <= 0 && s > 0)
	{
		sign = 1;
	}
	else if (Ps > 0 && s <= 0)
	{
		sign = 1;
	}
	//비교
	if (Ps <= 0)
	{
		ps[0] = 0;
		Ps *= (-1);
		for (; Ps != 0; Ps = Ps / 2)
		{
			ps[i] = Ps % 2;
			i++;
			psbit++;
		}
		i -= 1;
		psbit += 1;
		for (psbit2 = 1; psbit2 < psbit / 2; psbit2++)
		{
			Ps = ps[i];
			ps[i] = ps[psbit2];
			ps[psbit2] = Ps;
			i--;
		}
	}
	else
	{
		ps[0] = 0;
		for (; Ps != 0; Ps = Ps / 2)
		{
			ps[i] = Ps % 2;
			i++;
			psbit++;
		}
		i -= 1;
		psbit += 1;
		for (psbit2 = 1; psbit2 < psbit / 2; psbit2++)
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
	i = 1;
	j = 0;
	if (S <= 0)
	{
		s[0] = 0;
		S *= (-1);
		for (; S != 0; S = S / 2)
		{
			s[i] = S % 2;
			i++;
			sbit++;
		}
		i -= 1;
		sbit += 1;
		for (sbit2 = 1; sbit2 <= sbit / 2; sbit2++)
		{
			S = s[i];
			s[i] = s[sbit2];
			s[sbit2] = S;
			i--;
		}
	}
	else
	{
		s[0] = 0;
		for (; S != 0; S = S / 2)
		{
			s[i] = S % 2;
			i++;
			sbit++;
		}
		i -= 1;
		sbit += 1;
		for (sbit2 = 1; sbit2 <= sbit / 2; sbit2++)
		{
			S = s[i];
			s[i] = s[sbit2];
			s[sbit2] = S;
			i--;
		}
	}

	for (j = 0; j < sbit; j++)//승수 print
	{
		printf("%d", s[j]);
	}
	printf("\n");

	// 10진수 to 2진수

	i = rebit = psbit + sbit;
	int re[200] = { 0 };
	printf("  ");
	for (i -= 1; i >= 0; i--)//연산전 re print
	{
		printf("%d", re[i]);
	}
	i = rebit;
	printf("\n");

	for (sbit -= 1; sbit >= 0; sbit--)//승수 연산 확인
	{
		if (s[sbit] == 1)
		{
			printf("+ ");
			for (j = 0; j < psbit; j++)//피승수 출력
			{
				printf("%d", ps[j]);
			}
			printf("\n");

			end2 = end + psbit;
			for (j = psbit - 1; j >= 0; j--)//덧셈 연산
			{
				re[end2] = re[end2] + ps[j];
				if (re[end2] == 2)
				{
					re[end2] = 0;
					re[end2 + 1] += 1;
				}
				else if (re[end2] == 3)
				{
					re[end2] = 1;
					re[end2 + 1] += 1;
				}
				end2++;
			}

			i = rebit;
			printf("  ");
			for (i -= 1; i >= end; i--)//덧셈 결과 출력
			{
				printf("%d", re[i]);
			}
			printf("\n");
			rebit++; //덧셈결과 shift
			end++;

			i = rebit;
			printf("  ");
			for (i -= 1; i >= end; i--)//shift print
			{
				printf("%d", re[i]);
			}
			printf("\n");
		}
		else if (s[sbit] == 0)
		{
			printf("+ ");
			for (j = 0; j < psbit; j++)//피승수 print
			{
				printf("%d", 0);
			}
			printf("\n");

			rebit++;//연산결과 shift
			end++;

			i = rebit;
			printf("  ");
			for (i -= 1; i >= end; i--)//shift print
			{
				printf("%d", re[i]);
			}
			printf("\n");
		}
	}
	if (sign != 1)
	{
		i = rebit;
		printf("\n");
		printf("결과:");
		for (i -= 2; i >= end; i--)//결과 print
		{
			printf("%d", re[i]);
		}
	}
	else if (sign == 1)//두 피연산자의 부호 다를 경우 2의 보수 후 결과 출력
	{
		i = rebit;
		for (i -= 1; i >= end; i--)//1의 보수
		{
			re[i] = !re[i];
		}
		i = rebit;
		end2 = end;
		re[end2] = re[end2] + 1;
		for (j = i; j >= end; j--)
		{
			re[end2];
			if (re[end2] == 2)
			{
				re[end2] = 0;
				re[end2 + 1] += 1;
			}
			else if (re[end2] == 3)
			{
				re[end2] = 1;
				re[end2 + 1] += 1;
			}
			end2++;
		}
		printf("\n");
		i = rebit;
		printf("결과:");
		for (i -= 2; i >= end; i--)//2의 보수 결과 print
		{
			printf("%d", re[i]);
		}
		printf("\n");
	}
	return 0;
}
