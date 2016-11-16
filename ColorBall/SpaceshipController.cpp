#include "SpaceshipController.h"
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

SpaceshipController::SpaceshipController(unsigned aCTR_LEFT, unsigned aCTR_RIGHT, unsigned aCTR_UP, unsigned aCTR_DOWN, unsigned aCTR_BREAK)
{
	CTR_LEFT = aCTR_LEFT;
	CTR_RIGHT = aCTR_RIGHT;
	CTR_UP = aCTR_UP;
	CTR_DOWN = aCTR_DOWN;
	CTR_BREAK = aCTR_BREAK;
}


SpaceshipController::~SpaceshipController()
{
}

void SpaceshipController::update(Spaceship & ship)
{
	float hInput = 0;
	hInput += getKey(CTR_LEFT);
	hInput -= getKey(CTR_RIGHT);

	float vInput = 0;
	vInput += getKey(CTR_UP);
	vInput -= getKey(CTR_DOWN);

	float bInput = getKey(CTR_BREAK);

	ship.doTurn(hInput);
	ship.doThrust(vInput);
	ship.doStop(bInput);
}
