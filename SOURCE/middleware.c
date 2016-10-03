//MiddleWare.c

#include "middleware.h"
#include "build.h"

#if USE_SDL2
#include <SDL2/SDL.h>
#if USE_SDL_IMAGE
#include <SDL2/SDL_image.h>
#endif //USE_SDL_IMAGE
#if USE_SDL_TTF
#include <SDL2/SDL_ttf.h>
#endif //USE_SDL_TTF
#endif //USE_SDL2

#include "delog.h"

int InitMiddleWare(){

#if USE_SDL2
	
	//Init SDL2
	SDL_Init(SDL_INIT_VIDEO|SDL_INIT_JOYSTICK);
	SDL_version compiled, linked, *p_linked;
	SDL_VERSION(&compiled);
	SDL_GetVersion(&linked);
	printl(5, "SDL: %d.%d.%d. (compiled) %d.%d.%d. (linked)", compiled.major, compiled.minor, compiled.patch, linked.major, linked.minor, linked.patch);
	
#if USE_SDL_IMAGE
	
	IMG_Init(IMG_INIT_PNG);
	SDL_IMAGE_VERSION(&compiled);
	p_linked = IMG_Linked_Version();
	printl(5, "SDL_Image: %d.%d.%d (compiled) %d.%d.%d (linked)", compiled.major, compiled.minor, compiled.patch, p_linked->major, p_linked->minor, p_linked->patch);
	
#endif //USE_SDL_IMAGE

#if USE_SDL_TTF
	
	
	TTF_Init();
	SDL_TTF_VERSION(&compiled);
	p_linked = TTF_Linked_Version();
	printl(5, "TTF Version: %d.%d.%d (compiled) %d.%d.%d (linked)", compiled.major, compiled.minor, compiled.patch, p_linked->major, p_linked->minor, p_linked->patch);
	
#endif //USE_SDL_TTF

#endif //USE_SDL2
	
	return 0;
}

int QuitMiddleWare(){
	
#if USE_SDL2

#if USE_SDL_TTF

	TTF_Quit();
	
#endif //USE_SDL_TTF

#if USE_SDL_IMAGE

	IMG_Quit();

#endif //USE_SDL_IMAGE

	SDL_Quit();

#endif //USE_SDL2

	return 0;
}
	