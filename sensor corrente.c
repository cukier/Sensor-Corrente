#include <18f452.h>

#fuses nowdt
#fuses hs
#fuses noput
#fuses noprotect
#fuses nodebug
#fuses brownout
#fuses nolvp
#fuses nocpd
#fuses nowrt

#use delay (clock = 4000000)

#include <lcd_4bii.c>

void main (void) {
	float leitura_an = 0;
	float leitura_cv = 0;

	setup_adc_ports (AN0_AN1_AN3);
	setup_adc (adc_clock_internal);
	set_adc_channel (1);
	
	lcd_init();
	delay_ms (200);
	
	while (true) {
		delay_ms (50);
		leitura_an = read_adc ();
		leitura_cv = 14 * (leitura_an - 97) / 78;
		printf (lcd, "\fAn: %f\nCv: %f", leitura_an, leitura_cv);
		delay_ms (1000);
	}
}