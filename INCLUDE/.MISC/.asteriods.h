// Asteriods.h

#ifndef ASTERIODS_H
#define ASTERIODS_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct PlayerShip_struct {float velocity;
	float direction;
	float xvel;
	float yvel;
	float x;
	float y;
} PlayerShip_type;
typedef struct Asteriod_struct {float velocity;
	float direction;
	float xvel;
	float yvel;
	float x;
	float y;
	float size;
} Asteriod_type;
typedef struct Laser_struct {float velocity;
	float direction;
	float xvel;
	float yvel;
	float x;
	float y;
	float secondsactive;
} Laser_type;

int InitAsteriods();
int AsteriodsInput();
int AsteriodsLogic();
int AsteriodsVideo();
int QuitAsteriods();

#ifdef __cplusplus
}
#endif

#endif //ASTERIODS_H