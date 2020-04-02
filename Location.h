#pragma once

#ifndef _LOCATION_
#define _LOCATION_
#endif

/********************************************
Class:			Location.h
Author:			Cooper
Purpose:		3-D cordinate class template
Created:		none
*********************************************/
class Location {
private:
	float xCoord;
	float yCoord;
	float zCoord;

public:	//constructors
	Location();
	Location(float xCoord, float yCoord, float zCoord);


	//set Methods
	void setX(float xcoord);
	void setY(float yCoord);
	void setZ(float zCoord);
	void setLocation(float x, float y, float z);


	// get Methods
	float getX();
	float getY();
	float getZ();

	Location* getLocation();

};