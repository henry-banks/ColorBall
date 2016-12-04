#include "SpaceshipController.h"
#include <math.h>
#include "sfwdraw.h"

using namespace sfw;

//SpaceshipController::SpaceshipController()
//{
//	CTR_LEFT = 'A';
//	CTR_RIGHT = 'D';
//	CTR_UP = 'W';
//	CTR_DOWN = 'S';
//	CTR_BREAK = ' ';
//}

SpaceshipController::SpaceshipController(unsigned aCTR_LEFT, unsigned aCTR_RIGHT, unsigned aCTR_UP, unsigned aCTR_DOWN, unsigned aCTR_BREAK, unsigned aCTR_SPRINT)
{
	CTR_LEFT = aCTR_LEFT;
	CTR_RIGHT = aCTR_RIGHT;
	CTR_UP = aCTR_UP;
	CTR_DOWN = aCTR_DOWN;
	CTR_BREAK = aCTR_BREAK;
	CTR_SPRINT = aCTR_SPRINT;
}


SpaceshipController::~SpaceshipController()
{
}

void SpaceshipController::update(Spaceship & ship, float turnAngle, float currentAngle)
{
	float hInput = 0;
	//Keep the arrow keys pointing to the correct direction when the ship is flipped around
	if (fmodf(currentAngle + 90, 360) < 180)	//Offset of 90 is required
	{
		hInput += getKey(CTR_LEFT);
		hInput -= getKey(CTR_RIGHT);
	}
	else
	{
		hInput -= getKey(CTR_LEFT);
		hInput += getKey(CTR_RIGHT);
	}
	

	float vInput = 0;
	vInput += getKey(CTR_UP);
	vInput -= getKey(CTR_DOWN);

	float bInput = getKey(CTR_BREAK);

	if (getKey(CTR_SPRINT))
	{
		ship.maxSpeed = ship.sprintSpeed;
		vInput *= 3;	//Actually speed the ship up
	}
		

	ship.doHoriz(hInput);
	ship.doVert(vInput);
	ship.doTurn(turnAngle);
	ship.doStop(bInput);
}
