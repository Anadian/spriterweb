// Index.h

#ifndef INDEX_H
#define INDEX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stddef.h> //size_t

typedef struct Index_struct {unsigned char *pointer;
	size_t size;
	signed long count;} Index_type;

int CreateIndex(Index_type *index, void *object); //Return ID
int AddToIndex(Index_type *index, void *object); //Return ID
int RemoveFromIndex(Index_type *index, int id);
int GetObject(Index_type *index, int id, void *object);
//int SetObject(Index_type *index, void *object, int id);
//int CompressIndex(Index_type *index);
int PrintIndex(Index_type *index);
int DropIndex(Index_type *index);

#ifdef __cplusplus
}
#endif

#endif //INDEX_H