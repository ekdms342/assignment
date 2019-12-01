#include <stdio.h>
int main(void)
{
	int Ps, S, Ps2, psbit = 0, sbit = 0, rebit, i = 0, j, z, psbit2 = 0,k=0,si;
	scanf("%d %d", &Ps, &S);
	int ps[64] = { 0 };//덧셈시 사용 (== 원래 ps의 부호)
	int s[64] = { 0 };
	int re[200] = { 0 };
	int ps2[64] = { 0 };// 뺄셈시 필요 (== 원래 ps 의 반대)

	Ps2 = Ps;

	//10 진수를 2 진수로
	if (Ps <= 0)//음수
	{
		for (i = 0; i != 64; i++)
		{
			ps[i] = 1;
		}
		i = 0;
		for (Ps *= (-1); Ps != 0; Ps = Ps / 2)// 1의 보수
		{
			ps[i] = Ps % 2;
			ps[i] = !ps[i];
			i++;
			psbit++;
		}
		ps[0] += 1;//2의 보수
		for (i = 0; i != psbit; i++)
		{
			if (ps[i] == 2)
			{
				ps[i] = 0;
				ps[i + 1] += 1;
			}
			else if (ps[i] == 3)
			{
				ps[i] = 1;
				ps[i + 1] += 1;
			}
		}
		ps[psbit] = 1;//부호bit

	}
	else if (Ps > 0)//양수
	{
		for (Ps; Ps != 0; Ps = Ps / 2)//10 진수를 2진수로
		{
			ps[i] = Ps % 2;
			i++;
			psbit++;
		}
		ps[psbit] = 0;//부호 bit
	}
	printf("피승수    ");
	for (i = psbit; i >= 0; i--)// 피승수 출력
	{
		printf("%d", ps[i]);
	}
	printf("\n");

	i = 0;

	if (S <= 0)//승수 음수
	{
		i = 0;
		for (S *= (-1); S != 0; S = S / 2)// 1의 보수
		{
			s[i] = S % 2;
			s[i] = !s[i];
			i++;
			sbit++;
		}
		s[0] += 1;//2의 보수
		for (i = 0; i != sbit; i++)
		{
			if (s[i] == 2)
			{
				s[i] = 0;
				s[i + 1] += 1;
			}
			else if (s[i] == 3)
			{
				s[i] = 1;
				s[i + 1] += 1;
			}
		}
		s[sbit] = 1;//부호bit
	}
	else if (S > 0)//양수
	{
		i = 0;
		for (S; S != 0; S = S / 2)//10 진수를 2진수로
		{
			s[i] = S % 2;
			i++;
			sbit++;
		}
		s[sbit] = 0;//부호 bit
	}

	printf("승수      ");
	for (i = sbit; i >= 0; i--)// 승수 출력 s는 역으로 저장되어 있음
	{
		printf("%d", s[i]);
	}
	i = 0;
	//10 진수를 2 진수로 end
	z = rebit = psbit + sbit;

	if (Ps2 > 0)//ps의 역 뺄셈시 사용
	{
		for (i = 0; i != 64; i++)
		{
			ps2[i] = 1;
		}
		i = 0;
		for (Ps2; Ps2 != 0; Ps2 = Ps2 / 2)// 1의 보수
		{
			ps2[i] = Ps2 % 2;
			ps2[i] = !ps2[i];
			i++;
			psbit2++;
		}
		ps2[0] += 1;//2의 보수
		for (i = 0; i != psbit2; i++)
		{
			if (ps2[i] == 2)
			{
				ps2[i] = 0;
				ps2[i + 1] += 1;
			}
			else if (ps2[i] == 3)
			{
				ps2[i] = 1;
				ps2[i + 1] += 1;
			}
		}
		ps2[psbit2] = 1;//부호bit

	}
	else if (Ps2 <= 0)//ps 의 역 뺼셈시 사용
	{
		i = 0;
		for (Ps2 *= (-1); Ps2 != 0; Ps2 = Ps2 / 2)//10 진수를 2진수로
		{
			ps2[i] = Ps2 % 2;
			i++;
			psbit2++;
		}
		ps2[psbit2] = 0;//부호 bit
	}
	i = 0;
	// 뺼셈시 사용 배열
	si = sbit;
	for (i = 0; i <= sbit/ 2; i++)//승수를 똑바로 해줌
	{
		j = s[i];
		s[i] = s[si];
		s[si] = j;
		si--;
	}
	j = 0;
	i = 0;
	s[sbit + 1] = 0;//승수 끝에 0 입력 

	printf("%d", s[sbit + 1]);// 승수 끝 0 출력
	printf("\n");
	printf("\n");
	printf("승수  ");
	for (i = 0; i <= z + 1; i++)//초기 re 출력
	{
		printf("%d", re[i]);
	}
	printf("\n");


	while (sbit >= 0)
	{
		if (s[sbit] == 0 && s[sbit + 1] == 1)//덧셈
		{
 			printf("%d %d", s[sbit], s[sbit + 1]);//승수 출력
			printf("  ");
			printf("+");
			for (i = rebit + 1; i >= 0; i--)//피승수(ps) 출력
			{
				printf("%d", ps[i]);
			}
			printf("\n");
			j = 0;
			for (i = k; i <= z + 1; i++)//덧셈 연산
			{
				re[i] = re[i] + ps[j];
				if (re[i] == 2)
				{
					re[i] = 0;
					re[i + 1] += 1;
					
				}
				else if (re[i] == 3)
				{
					re[i] = 1;
					re[i + 1] += 1;
				}
				j++;
			}
			k++;
			rebit--;
			printf("      ");
			for (i = z + 1; i >= 0; i--)//결과 출력
			{
				printf("%d", re[i]);
			}
			printf("\n");
			sbit--;
		}
		else if (s[sbit] == 1 && s[sbit + 1] == 0)//뺄셈
		{
			printf("%d %d", s[sbit], s[sbit + 1]); //승수 출력
			printf("  ");
			printf("+");
			for (i = rebit + 1; i >= 0; i--)//피승수(ps2) 출력
			{
				printf("%d", ps2[i]);
			}
			printf("\n");
			j = 0;
			for (i = k; i <= z + 1; i++)//뺄셈 연산
			{
				re[i] = re[i] + ps2[j];
				if (re[i] == 2)
				{
					re[i] = 0;
					re[i + 1] += 1;
				}
				else if (re[i] == 3)
				{
					re[i] = 1;
					re[i + 1] += 1;
				}
				j++;
			}
			rebit--;
			k++;
			printf("      ");
			for (i = z + 1; i >= 0; i--)//결과 출력
			{
				printf("%d", re[i]);
			}
			printf("\n");
			sbit--;
		}
		else if (s[sbit] == s[sbit + 1])// shift
		{
			printf("%d %d", s[sbit], s[sbit + 1]); //승수 출력
			printf("  ");
			printf("+");
			for (i = rebit + 1; i >= 0; i--)//피승수 출력
			{
				printf("%d", 0);
			}
			printf("\n");
			k++;
			rebit--;
			printf("      ");
			for (i = z + 1; i >= 0; i--)//결과 출력
			{
				printf("%d", re[i]);
			}
			printf("\n");
			sbit--;
		}
	}
	return 0;
}
