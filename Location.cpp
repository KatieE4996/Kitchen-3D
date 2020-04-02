#ifndef _LOCATION_
#include "Location.h"
#endif


/********************************************
Class:			Location.cpp
Author:			Cooper
Purpose:		3-D location definitions
Created:		02/12/2020
Dependencies:	Location.h
*********************************************/
Location::Location() {
	setLocation(0, 0, 0);
}
Location::Location(float xCoord, float yCoord, float zCoord) {
	setLocation(xCoord, yCoord, zCoord);

}


//set Methods
void Location::setX(float xCoord) {
	this->xCoord = xCoord;
}

void Location::setY(float yCoord) {
	this->yCoord = yCoord;
}
void Location::setZ(float zCoord) {
	this->zCoord = zCoord;
}
void Location::setLocation(float x, float y, float z) {
	setX(x);
	setY(y);
	setZ(z);
}


// get Methods
float Location::getX() { return xCoord; }
float Location::getY() { return yCoord; }
float Location::getZ() { return zCoord; }

Location* Location::getLocation() { return this; }