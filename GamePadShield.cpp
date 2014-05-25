/*

  Project:       1Sheeld Library 
  File:          GamePadShield.cpp
                 
  Version:       1.0

  Compiler:      Arduino avr-gcc 4.3.2

  Author:        Integreight
                 
  Date:          2014.5

*/

#include "OneSheeld.h"
#include "GamePadShield.h"



//Class Constructor
GamePadShield::GamePadShield()
{
	value =0x00;
	isCallBackAssigned=false;
}

//Checker
bool GamePadShield::isUpPressed()
{
	up = !!(value & (1<<UP_BIT));
	return up ;
}
//Checker 
bool GamePadShield::isDownPressed()
{
	down = !!(value & (1<<DOWN_BIT));
	return down ;
}
//Checker
bool GamePadShield::isLeftPressed()
{
	left = !!(value & (1<<LEFT_BIT));
	return left ;
}
//Checker
bool GamePadShield::isRightPressed()
{
	right = !!(value & (1<<RIGHT_BIT));
	return right ;
}
//Checker
bool GamePadShield::isOrangePressed()
{
	orange = !!(value & (1<<ORANGE_BIT));
	return orange ;
}
//Checker 
bool GamePadShield::isRedPressed()
{
	red = !!(value & (1<<RED_BIT));
	return red ;
}
//Checker 
bool GamePadShield::isGreenPressed()
{
	green = !!(value & (1<<GREEN_BIT));
	return green ;
}
//Checker
bool GamePadShield::isBluePressed()
{
	blue = !!(value & (1<<BLUE_BIT));
	return blue ;
}
//GamePad Input Data Processing  
void GamePadShield::processData()
{
	//Checking the Function-ID
	byte functionId =OneSheeld.getFunctionId();
	if(functionId==GAMEPAD_VALUE)
	{
		value=OneSheeld.getArgumentData(0)[0];
		//Users Function Ivocation
		if(isCallBackAssigned)
		{
			(*buttonChangeCallBack)(up , down , left , right , orange , red , green , blue);
		}
	}
}

//Users Function Setter 
void GamePadShield::setOnButtonChange(void (* userFunction)(unsigned char up,unsigned char down,unsigned char left,unsigned char right,unsigned char orange ,unsigned char red,unsigned char green,unsigned char blue))
{
	buttonChangeCallBack=userFunction;
	isCallBackAssigned=true;
}

//Instantiating Object
GamePadShield GamePad;