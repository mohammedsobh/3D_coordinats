/*
 * stepper.h
 *
 * Created: 25/10/2018 10:14:48 ã
 *  Author: eng_s
 * This library controls the bipolar Stepper Motor with the A9488 driver
 * with 4 stepper A,B,C,D
 * the step pin is control the speed of rotation by the rate of change
 * in it with msx pins.
 * and the DIR pin is control the direction of rotation cw or ccw
 */
#include "stepper.h"
#include <util/delay.h>
#include <avr/io.h>
#include <stdbool.h>
int speed;
int ms1,ms2,ms3,StepA,DIRA,StepB,DIRB,StepC,DIRC,StepD,DIRD;
int no ;
void STpinChange(int a, int b)
{
	if(b == 0)
	{
		if(a == St_PORTA0)
		PORTA &= ~(1<<PORTA0);
		else if(a == St_PORTA1)
		PORTA &= ~(1<<PORTA1);
		else if(a == St_PORTA2)
		PORTA &= ~(1<<PORTA2);
		else if(a == St_PORTA3)
		PORTA &= ~(1<<PORTA3);
		else if(a == St_PORTA4)
		PORTA &= ~(1<<PORTA4);
		else if(a == St_PORTA5)
		PORTA &= ~(1<<PORTA5);
		else if(a == St_PORTA6)
		PORTA &= ~(1<<PORTA6);
		else if(a == St_PORTA7)
		PORTA &= ~(1<<PORTA7);
		else if(a == St_PORTB0)
		PORTB &= ~(1<<PORTB0);
		else if(a == St_PORTB1)
		PORTB &= ~(1<<PORTB1);
		else if(a == St_PORTB2)
		PORTB &= ~(1<<PORTB2);
		else if(a == St_PORTB3)
		PORTB &= ~(1<<PORTB3);
		else if(a == St_PORTB4)
		PORTB &= ~(1<<PORTB4);
		else if(a == St_PORTB5)
		PORTB &= ~(1<<PORTB5);
		else if(a == St_PORTB6)
		PORTB &= ~(1<<PORTB6);
		else if(a == St_PORTB7)
		PORTB &= ~(1<<PORTB7);
		else if(a == St_PORTC0)
		PORTC &= ~(1<<PORTC0);
		else if(a == St_PORTC1)
		PORTC &= ~(1<<PORTC1);
		else if(a == St_PORTC2)
		PORTC &= ~(1<<PORTC2);
		else if(a == St_PORTC3)
		PORTC &= ~(1<<PORTC3);
		else if(a == St_PORTC4)
		PORTC &= ~(1<<PORTC4);
		else if(a == St_PORTC5)
		PORTC &= ~(1<<PORTC5);
		else if(a == St_PORTC6)
		PORTC &= ~(1<<PORTC6);
		else if(a == St_PORTC7)
		PORTC &= ~(1<<PORTC7);
		else if(a == St_PORTD0)
		PORTD &= ~(1<<PORTD0);
		else if(a == St_PORTD1)
		PORTD &= ~(1<<PORTD1);
		else if(a == St_PORTD2)
		PORTD &= ~(1<<PORTD2);
		else if(a == St_PORTD3)
		PORTD &= ~(1<<PORTD3);
		else if(a == St_PORTD4)
		PORTD &= ~(1<<PORTD4);
		else if(a == St_PORTD5)
		PORTD &= ~(1<<PORTD5);
		else if(a == St_PORTD6)
		PORTD &= ~(1<<PORTD6);
		else if(a == St_PORTD7)
		PORTD &= ~(1<<PORTD7);
	}
	else
	{
		if(a == St_PORTA0)
		PORTA |= (1<<PORTA0);
		else if(a == St_PORTA1)
		PORTA |= (1<<PORTA1);
		else if(a == St_PORTA2)
		PORTA |= (1<<PORTA2);
		else if(a == St_PORTA3)
		PORTA |= (1<<PORTA3);
		else if(a == St_PORTA4)
		PORTA |= (1<<PORTA4);
		else if(a == St_PORTA5)
		PORTA |= (1<<PORTA5);
		else if(a == St_PORTA6)
		PORTA |= (1<<PORTA6);
		else if(a == St_PORTA7)
		PORTA |= (1<<PORTA7);
		else if(a == St_PORTB0)
		PORTB |= (1<<PORTB0);
		else if(a == St_PORTB1)
		PORTB |= (1<<PORTB1);
		else if(a == St_PORTB2)
		PORTB |= (1<<PORTB2);
		else if(a == St_PORTB3)
		PORTB |= (1<<PORTB3);
		else if(a == St_PORTB4)
		PORTB |= (1<<PORTB4);
		else if(a == St_PORTB5)
		PORTB |= (1<<PORTB5);
		else if(a == St_PORTB6)
		PORTB |= (1<<PORTB6);
		else if(a == St_PORTB7)
		PORTB |= (1<<PORTB7);
		else if(a == St_PORTC0)
		PORTC |= (1<<PORTC0);
		else if(a == St_PORTC1)
		PORTC |= (1<<PORTC1);
		else if(a == St_PORTC2)
		PORTC |= (1<<PORTC2);
		else if(a == St_PORTC3)
		PORTC |= (1<<PORTC3);
		else if(a == St_PORTC4)
		PORTC |= (1<<PORTC4);
		else if(a == St_PORTC5)
		PORTC |= (1<<PORTC5);
		else if(a == St_PORTC6)
		PORTC |= (1<<PORTC6);
		else if(a == St_PORTC7)
		PORTC |= (1<<PORTC7);
		else if(a == St_PORTD0)
		PORTD |= (1<<PORTD0);
		else if(a == St_PORTD1)
		PORTD |= (1<<PORTD1);
		else if(a == St_PORTD2)
		PORTD |= (1<<PORTD2);
		else if(a == St_PORTD3)
		PORTD |= (1<<PORTD3);
		else if(a == St_PORTD4)
		PORTD |= (1<<PORTD4);
		else if(a == St_PORTD5)
		PORTD |= (1<<PORTD5);
		else if(a == St_PORTD6)
		PORTD |= (1<<PORTD6);
		else if(a == St_PORTD7)
		PORTD |= (1<<PORTD7);
	}
}

void steper_1step(){ // to make a full 1 step with 2 phase
	STpinChange(ms1,0);        // ms1 = 0,ms2 = 0,ms3 = 0 from a9488 data sheet
	STpinChange(ms2,0);
	STpinChange(ms3,0);
}
void steper_Hstep(){// to make a half 1 step with 1-2 phase ms1 = 1,ms2 = 0,ms3 = 0 from a9488 data sheet
	STpinChange(ms1,1);
	STpinChange(ms2,0);
	STpinChange(ms3,0);
}
void steper_Qstep(){// to make a Quarter 1 step with w1-2 phase ms1 = 0,ms2 = 1,ms3 = 0 from a9488 data sheet
	STpinChange(ms1,0);
	STpinChange(ms2,1);
	STpinChange(ms3,0);
}
void steper_Estep(){// to make a Eighth 1 step with 2w1-2 phase ms1 = 1,ms2 = 1,ms3 = 0 from a9488 data sheet
	STpinChange(ms1,1);
	STpinChange(ms2,1);
	STpinChange(ms3,0);
}
void steper_Sstep(){// to make a Sixteenth 1 step with 4w1-2 phase ms1 = 1,ms2 = 1,ms3 = 0 from a9488 data sheet
	STpinChange(ms1,1);
	STpinChange(ms2,1);
	STpinChange(ms3,1);
}
void setspeed(int sp){
	sp=(1000/sp);//1step = 1 mm 
	while(sp > 0){
		_delay_us (500);
		sp-=1;
	}
}
void one_stepper_Intiat(int ms1pin ,int ms2pin,int ms3pin,int stepApin , int dirApin,int steps,int16_t sp )
{
	ms1 = ms1pin;
	ms2 = ms2pin;
	ms3 = ms3pin;
	StepA = stepApin;
	DIRA = dirApin;
	no = 1;
	switch (steps){
		case 1:steper_1step();break;
		case 2:steper_Hstep();break;
		case 6:steper_Qstep();break;
		case 8:steper_Estep();break;
		case 16:steper_Sstep();break;
	}
	speed = sp;
}
void two_stepper_Intiat(int ms1pin ,int ms2pin,int ms3pin,int stepApin , int dirApin,int stepBpin , int dirBpin,int steps,int16_t sp )
{
	ms1		= ms1pin;
	ms2		= ms2pin;
	ms3		= ms3pin;
	StepA	= stepApin;
	DIRA	= dirApin;
	StepB	= stepBpin;
	DIRB	= dirBpin;
	no = 2;
	switch (steps){
		case 1:steper_1step();break;
		case 2:steper_Hstep();break;
		case 6:steper_Qstep();break;
		case 8:steper_Estep();break;
		case 16:steper_Sstep();break;
	}
	speed = sp;
}
void three_stepper_Intiat(int ms1pin ,int ms2pin,int ms3pin,int stepApin , int dirApin,int stepBpin , int dirBpin,int stepCpin , int dirCpin,int steps,int16_t sp )
{
	ms1		= ms1pin;
	ms2		= ms2pin;
	ms3		= ms3pin;
	StepA	= stepApin;
	DIRA	= dirApin;
	StepB	= stepBpin;
	DIRB	= dirBpin;
	StepC	= stepCpin;
	DIRC	= dirCpin;
	no = 3;
	switch (steps){
		case 1:steper_1step();break;
		case 2:steper_Hstep();break;
		case 6:steper_Qstep();break;
		case 8:steper_Estep();break;
		case 16:steper_Sstep();break;
	}
	speed = sp;
}
void four_stepper_Intiat(int ms1pin ,int ms2pin,int ms3pin,int stepApin , int dirApin,int stepBpin , int dirBpin,int stepCpin , int dirCpin,int stepDpin , int dirDpin,int steps,int16_t sp )
{
	ms1		= ms1pin;
	ms2		= ms2pin;
	ms3		= ms3pin;
	StepA	= stepApin;
	DIRA	= dirApin;
	StepB	= stepBpin;
	DIRB	= dirBpin;
	StepC	= stepCpin;
	DIRC	= dirCpin;
	StepD	= stepDpin;
	DIRD	= dirDpin;
	no = 4;	
	switch (steps){
		case 1:steper_1step();break;
		case 2:steper_Hstep();break;
		case 6:steper_Qstep();break;
		case 8:steper_Estep();break;
		case 16:steper_Sstep();break;
	}
	speed = sp;
}
void Stepper_move(bool clockw[],long NuOfSteps[])
{
	if (no == 1)
	{
		if (clockw[0])
		{
			STpinChange(DIRA,1);
		}
		else
		{
			STpinChange(DIRA,0);
		}
		while ((NuOfSteps[0]) != 0)
		{
		STpinChange(StepA,1);
		setspeed(speed);
		STpinChange(StepA,0);
		_delay_us (50);
		NuOfSteps[0] -= 1;
		}
	} 
	else if (no == 2)
	{
		if (clockw[0])
		{
			STpinChange(DIRA,1);
		}
		else
		{
			STpinChange(DIRA,0);
		}
		if (clockw[1])
		{
			STpinChange(DIRB,1);
		}
		else
		{
			STpinChange(DIRB,0);
		}
	while ((NuOfSteps[0] & NuOfSteps[1]) != 0)
	{
		if (NuOfSteps[0] != 0)
		{
			STpinChange(StepA,1);
		}
		else
			NuOfSteps[0] = 0;
		if (NuOfSteps[1] != 0)
		{
			STpinChange(StepB,1);
		}
		else
			NuOfSteps[1] = 0;
		setspeed(speed);
		STpinChange(StepA,0);
		STpinChange(StepB,0);
		NuOfSteps[0] -= 1;
		NuOfSteps[1] -= 1;
	}
	}
	else if (no == 3)
	{
		if (clockw[0])
		{
			STpinChange(DIRA,1);
		}
		else
		{
			STpinChange(DIRA,0);
		}
		if (clockw[1])
		{
			STpinChange(DIRB,1);
		}
		else
		{
			STpinChange(DIRB,0);
		}
		if (clockw[2])
		{
			STpinChange(DIRC,1);
		}
		else
		{
			STpinChange(DIRC,0);
		}
	while ((NuOfSteps[0] & NuOfSteps[1] & NuOfSteps[2]) != 0)
	{
		if (NuOfSteps[0] != 0)
		{
			STpinChange(StepA,1);
		}
		else
			NuOfSteps[0] = 0;
		if (NuOfSteps[1] != 0)
		{
			STpinChange(StepB,1);
		}
		else
			NuOfSteps[1] = 0;
		if (NuOfSteps[2] != 0)
		{
			STpinChange(StepC,1);
		}
		else
			NuOfSteps[2] = 0;
		setspeed(speed);
		STpinChange(StepA,0);
		STpinChange(StepB,0);
		STpinChange(StepC,0);
		NuOfSteps[0] -= 1;
		NuOfSteps[1] -= 1;
		NuOfSteps[2] -= 1;
	}
	}
	else if (no == 4)
	{
		if (clockw[0])
		{
			STpinChange(DIRA,1);
		}
		else
		{
			STpinChange(DIRA,0);
		}
		if (clockw[1])
		{
			STpinChange(DIRB,1);
		}
		else
		{
			STpinChange(DIRB,0);
		}
		if (clockw[2])
		{
			STpinChange(DIRC,1);
		}
		else
		{
			STpinChange(DIRC,0);
		}
		if (clockw[3])
		{
			STpinChange(DIRD,1);
		}
		else
		{
			STpinChange(DIRD,0);
		}
		while ((NuOfSteps[0] & NuOfSteps[1] & NuOfSteps[2] & NuOfSteps[3]) != 0)
		{
			if (NuOfSteps[0] != 0)
			{
				STpinChange(StepA,1);
			}
			else
			NuOfSteps[0] = 0;
			if (NuOfSteps[1] != 0)
			{
				STpinChange(StepB,1);
			}
			else
			NuOfSteps[1] = 0;
			if (NuOfSteps[2] != 0)
			{
				STpinChange(StepC,1);
			}
			else
			NuOfSteps[2] = 0;
			if (NuOfSteps[3] != 0)
			{
				STpinChange(StepD,1);
			}
			else
			NuOfSteps[3] = 0;
			setspeed(speed);
			STpinChange(StepA,0);
			STpinChange(StepB,0);
			STpinChange(StepC,0);
			STpinChange(StepD,0);
			NuOfSteps[0] -= 1;
			NuOfSteps[1] -= 1;
			NuOfSteps[2] -= 1;
			NuOfSteps[3] -= 1;
		}
	}
	
}
void Stepper_onerev(bool clockw , int step , int dir)
{
	if (clockw)
	{
		STpinChange(dir,1);
	}
	else
		STpinChange(dir,0);
	STpinChange(step,1);
	setspeed(speed);
	STpinChange(step,0);
	_delay_us (50);
}
void Stepper_rev(int step , int dir , bool clockw,long NuOfSteps){//rotate clockwise or ccw , number of steps for stepperC
	if (clockw)
	{
		STpinChange(DIRD,1);
	}
	else
	{
		STpinChange(DIRD,0);
	}
	
	while (NuOfSteps > 0)
	{
		Stepper_onerev(clockw , step , dir);
		NuOfSteps -= 1;
	}
}