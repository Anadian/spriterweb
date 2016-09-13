// sprite.h

#ifndef SPRITE_H
#define SPRITE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct Sprite_struct {
	float x;
	float y;
	float w;
	float h;
	float scale;
	float rotation;
	unsigned long textureaddress;
} Sprite_type;

Sprite_type Sprites = NULL;

#ifdef __cplusplus
}
#endif

#endif //SPRITE_H