#include <stdio.h>
int main(void)
{
	int psbit = 0, sbit = 0, rebit, i, j = 0, end = 0, end2 = 0;
	int ps[64] = { 0 };
	int s[64] = { 0 };
	while (psbit != 4)
	{
		int num;
		scanf("%d", &num);
		ps[psbit] = num;
		psbit++;
	}
	while (sbit != 4)
	{
		int num;
		scanf("%d", &num);
		s[sbit] = num;
		sbit++;
	}
	i = rebit = psbit + sbit;
	int re[200] = { 0 };
	printf("  ");
	for (i -= 1; i >= 0; i--)//계산전 re print
	{
		printf("%d", re[i]);
	}
	i = rebit;
	printf("\n");

	for (sbit -= 1; sbit >= 0; sbit--)//승수 확인
	{
		if (s[sbit] == 1)
		{
			printf("+ ");
			for (j = 0; j < psbit; j++)//피승수 print
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
			for (i -= 1; i >= end; i--)//연산결과 print
			{
				printf("%d", re[i]);
			}
			printf("\n");
			rebit++; //오른쪽 shift 
			end++;

			i = rebit;
			printf("  ");
			for (i -= 1; i >= end; i--)// 오른쪽 shift print
			{
				printf("%d", re[i]);
			}
			printf("\n");
		}
		else if (s[sbit] == 0)
		{
			printf("+ ");
			for (; j < psbit; j++)//피승수 print
			{
				printf("%d", 0);
			}
			printf("\n");
			
			rebit++;//오른쪽 shift
			end++;

			i = rebit;
			printf("  ");
			for (i -= 1; i >= end; i--)// 오른쪽 shift print
			{
				printf("%d", re[i]);
			}
		}
	}
	return 0;
}
