// Camera.c

#include "camera.h"

Camera_type CreateNewCamera(CameraState_type state, PDR_type pdr){
	Camera_type Camera;
	Camera.state = state;
	Camera.pdr = pdr;
	return Camera;
}
