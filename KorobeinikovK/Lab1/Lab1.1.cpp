#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

void main() {
	float h, w, d, m;
	float dsp = 750, dvp = 400, wood = 690;
	float dsp_t = 1.5, dvp_t = 0.5, wood_t = 1;
	float pol_c = 0, r_pol = 40;
	dvp = dvp / 1000000;//м€гка€ плита в кг/см^3
	dsp = dsp / 1000000;//средней плотности в кг/см^3
	wood = wood / 1000000;//средн€€ плотность дуба в кг/см^3
	printf("Enter height (180 - 220 cm):");
	scanf("%f", &h);
	printf("Enter width (80-120 cm):");
	scanf("%f", &w);
	printf("Enter depth (50-90 cm):");
	scanf("%f", &d);
	if ((h < 180) || (h > 220)) {
		printf("Enteres incorrectly");
	}
	else if ((w < 80) || (w > 120)) {
		printf("Enteres incorrectly");
	}
	else if ((d < 50) || (d > 90)) {
		printf("Enteres incorrectly");
	}
	else {
		while ((r_pol + 1.5) <= h)
		{
			pol_c = pol_c + 1;
			r_pol = r_pol + 41.5;
		}
		m = (h * w * dvp_t * dvp) + (2 * h * d * dsp * dsp_t) + (2 * h * w * wood * wood_t) + (2 * d * w * dsp * dsp_t) + (pol_c * w * d * dsp * dsp_t);
		printf("Weight: %.3f kg", m);
	}
}