#include "Flags.h"

int flagState[EndFlag];


int getStateFlag(FlagsList flag) 
{
	return flagState[flag] ;
};

void setStateFlag(FlagsList flag, int state) 
{
	flagState[flag] = state ;
}

void enableFlag(FlagsList flag)  
{
	setStateFlag(flag, true) ;
}

void disableFlag(FlagsList flag) 
{
	setStateFlag(flag, false) ;
}