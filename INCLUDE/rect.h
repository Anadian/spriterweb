//rect.h

#ifndef RECT_H
#define RECT_H

#ifdef __cplusplus
extern "C" {
#endif //cplusplus

typedef struct Rect_struct {
	unsigned int x;
	unsigned int y;
	unsigned int w;
	unsigned int h;
} Rect_type;

#ifdef __cplusplus
}
#endif

#endif //RECT_H