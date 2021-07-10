/*
 * ADC_PROG.c
 *
 * Created: 12/7/2020 10:57:31 PM
 *  Author: ahmed
 */ 
#include "std-types.h"
#include "BIT_MATH.h"
#include "ADC_CONFIG.h"
#include "ADC_PRIV.h"
#include "ADC_INT.h"

static void (*ADC_Callback)(void) = 0;

void ADC_voidConfig(void)
{
	ADMUX |= REF_SELECT << 6;
	ADMUX |= ADJUST << 5;
	
	#if INPUT_MODE==MODE_SINGLE && INPUT_CH==0
	ADMUX  |= 0;
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==1
	ADMUX  |= 1;
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==2
	ADMUX  |= 2;
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==3
	ADMUX  |= 3;
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==4
	ADMUX  |= 4;
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==5
	ADMUX  |= 5;
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==6
	ADMUX  |= 6;
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==7
	ADMUX  |= 7;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==0 && INPUT_NEG==0 && GAIN==GAIN_10
	ADMUX  |= 8;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==1 && INPUT_NEG==0 && GAIN==GAIN_10
	ADMUX  |= 9;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==0 && INPUT_NEG==0 && GAIN==GAIN_200
	ADMUX  |= 10;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==1 && INPUT_NEG==0 && GAIN==GAIN_200
	ADMUX  |= 11;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==2 && INPUT_NEG==2 && GAIN==GAIN_10
	ADMUX  |= 12;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==3 && INPUT_NEG==2 && GAIN==GAIN_10
	ADMUX  |= 13;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==2 && INPUT_NEG==2 && GAIN==GAIN_200
	ADMUX  |= 14;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==3 && INPUT_NEG==2 && GAIN==GAIN_200
	ADMUX  |= 15;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==0 && INPUT_NEG==1 && GAIN==GAIN_1
	ADMUX  |= 16;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==1 && INPUT_NEG==1 && GAIN==GAIN_1
	ADMUX  |= 17;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==2 && INPUT_NEG==1 && GAIN==GAIN_1
	ADMUX  |= 18;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==3 && INPUT_NEG==1 && GAIN==GAIN_1
	ADMUX  |= 19;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==4 && INPUT_NEG==1 && GAIN==GAIN_1
	ADMUX  |= 20;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==5 && INPUT_NEG==1 && GAIN==GAIN_1
	ADMUX  |= 21;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==6 && INPUT_NEG==1 && GAIN==GAIN_1
	ADMUX  |= 22;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==7 && INPUT_NEG==1 && GAIN==GAIN_1
	ADMUX  |= 23;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==0 && INPUT_NEG==2 && GAIN==GAIN_1
	ADMUX  |= 24;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==1 && INPUT_NEG==2 && GAIN==GAIN_1
	ADMUX  |= 25;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==2 && INPUT_NEG==2 && GAIN==GAIN_1
	ADMUX  |= 26;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==3 && INPUT_NEG==2 && GAIN==GAIN_1
	ADMUX  |= 27;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==4 && INPUT_NEG==2 && GAIN==GAIN_1
	ADMUX  |= 28;
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==5 && INPUT_NEG==2 && GAIN==GAIN_1
	ADMUX  |= 29;
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==VBG
	ADMUX  |= 30;
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==GND
	ADMUX  |= 31;
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==8
	ADMUX  |= 0;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==9
	ADMUX  |= 1;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==10
	ADMUX  |= 2;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==11
	ADMUX  |= 3;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==12
	ADMUX  |= 4;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==13
	ADMUX  |= 5;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==14
	ADMUX  |= 6;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_SINGLE && INPUT_CH==15
	ADMUX  |= 7;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==8 && INPUT_NEG==8 && GAIN==GAIN_10
	ADMUX  |= 8;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==9 && INPUT_NEG==8 && GAIN==GAIN_10
	ADMUX  |= 9;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==8 && INPUT_NEG==8 && GAIN==GAIN_200
	ADMUX  |= 10;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==9 && INPUT_NEG==8 && GAIN==GAIN_200
	ADMUX  |= 11;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==10 && INPUT_NEG==10 && GAIN==GAIN_10
	ADMUX  |= 12;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==11 && INPUT_NEG==10 && GAIN==GAIN_10
	ADMUX  |= 13;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==10 && INPUT_NEG==10 && GAIN==GAIN_200
	ADMUX  |= 14;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==11 && INPUT_NEG==10 && GAIN==GAIN_200
	ADMUX  |= 15;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==8 && INPUT_NEG==9 && GAIN==GAIN_1
	ADMUX  |= 16;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==9 && INPUT_NEG==9 && GAIN==GAIN_1
	ADMUX  |= 17;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==10 && INPUT_NEG==9 && GAIN==GAIN_1
	ADMUX  |= 18;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==11 && INPUT_NEG==9 && GAIN==GAIN_1
	ADMUX  |= 19;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==12 && INPUT_NEG==9 && GAIN==GAIN_1
	ADMUX  |= 20;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==13 && INPUT_NEG==9 && GAIN==GAIN_1
	ADMUX  |= 21;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==14 && INPUT_NEG==9 && GAIN==GAIN_1
	ADMUX  |= 22;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==15 && INPUT_NEG==9 && GAIN==GAIN_1
	ADMUX  |= 23;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==8 && INPUT_NEG==10 && GAIN==GAIN_1
	ADMUX  |= 24;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==9 && INPUT_NEG==10 && GAIN==GAIN_1
	ADMUX  |= 25;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==10 && INPUT_NEG==10 && GAIN==GAIN_1
	ADMUX  |= 26;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==11 && INPUT_NEG==10 && GAIN==GAIN_1
	ADMUX  |= 27;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==12 && INPUT_NEG==10 && GAIN==GAIN_1
	ADMUX  |= 28;
	BIT_SET(ADCSRB, 3);
	#elif INPUT_MODE==MODE_DIFF   && INPUT_POS==13 && INPUT_NEG==10 && GAIN==GAIN_1
	ADMUX  |= 29;
	BIT_SET(ADCSRB, 3);
	#endif
	
	ADCSRA |= CLK_PRESCALER;
	
	#if TRIG_TYPE==TRIG_TYPE_AUTO
	BIT_SET(ADCSRA,5);
	ADCSRB |= TRIG_SRC;
	#endif
}
void ADC_voidEnable(void)
{
	BIT_SET(ADCSRA,7);
}
void ADC_voidDisable(void)
{
	BIT_CLR(ADCSRA,7);
}
u16 ADC_u16Convert(void)
{
	if (!(ADCSRA&128)) return 0;
	BIT_SET(ADCSRA,6);
	while((ADCSRA & 64));
	ADC_voidClrFlag();
	#if ADJUST == LEFT_ADJUST
	return (ADCL | (((u16)ADCH) << 8))&0xFFC0;
	#elif ADJUST == RIGHT_ADJUST
	return (ADCL | (((u16)ADCH) << 8))&0x03FF;
	#endif
}

void ADC_voidIntMask(void)
{
	BIT_CLR(ADCSRA,3);
}
void ADC_voidIntUnmask(void)
{
	BIT_SET(ADCSRA,3);
}
void ADC_voidClrFlag(void)
{
	BIT_SET(ADCSRA,4);
}

void ADC_voidSetCallback(void (* callback)(void))
{
	ADC_Callback = callback;
}

void ADC_ISR  () __attribute__((signal,used));
void ADC_ISR  ()
{
	(*ADC_Callback)();
}