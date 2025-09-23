#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
//h = 180 - 220
//w = 80 - 120
//d = 50 - 90
//p(dvp) = 900
//p(dsp) = 735
//p(дуба) = 850
//m = p * V
//n = h/40
void main()
{
	printf("entering cabinet parameters h w d\n");
	double h, w, d;
	const int pdvp = 900;
	const int pdsp = 735;
	const int pdub = 850;
	scanf("%lf %lf %lf", &h, &w, &d);
	if ((h < 180) || (h > 220) || (w < 80) || (w > 120) || (d < 50) || (d > 90))
	{
		printf("incorrect input\n");
	}
	else
	{
		int n = h / 40; //если нужно избежать стыка нижней полки с нижней крышкой, тогда следует: if (h%40 == 0) n = n - 1;
		double m;
		h = h / 100;
		w = w / 100;
		d = d / 100;
		m = (pdvp * (h * w * 0.005)) + (2 * pdsp * (h * d * 0.015)) + (2 * pdsp * (w * d * 0.015)) + (pdub * (h * w * 0.01)) + (n * pdsp * (d * (w - 0.03) * 0.005));
		printf("cabinet weight = %lf", m);
	}
}