// Index.c

#include "index.h"

#include <stdlib.h> //malloc, free
#include <string.h> //memcpy

int CreateIndex(Index_type *index, void *object){
	index->pointer = malloc(sizeof(*object));
	index->size = sizeof(*object);
	index->count = 1;
	return 0;
}
int AddToIndex(Index_type *index, void *object){
	int i;
	int id;
	id = -1;
	for(i = 0; i < index->count; i++){
		if( *(index->pointer + (i * index->size)) == 0){
			id = i;
			memcpy((index->pointer + (i * index->size)), object, sizeof(*object));
			i = index->count;
		}
	}
	if(id == -1){
		index->pointer = realloc(index->pointer, (index->size * (index->count + 1)));
		(index->count)++;
		memcpy((index->pointer + (index->size * (index->count - 1))), object, sizeof(*object));
		id = (index->count - 1);
	}
	return id;
}
int RemoveFromIndex(Index_type *index, int id){
	int i;
	int subid;
	subid = 0;
	for(i = 0; i < index->count; i++){
		if(subid == id){
			*(index->pointer + (i * index->size)) = 0;
			return 1;
		}
		else if( *(index->pointer + (i * index->size)) != NULL) subid++;
	}
	return 0;
}
int GetObject(Index_type *index, int id, void *object){
	int i;
	int subid;
	subid = 0;
	for(i = 0; i < index->count; i++){
		if(subid == id){
			memcpy(object, (index->pointer + (i * index->size)), sizeof(*object));
			return 1;
		} 
		else if( *(index->pointer + (i * index->size)) != NULL) subid++;
	}
	return 0;
}
int PrintIndex(Index_type *index){
	if(index->count > 0){
		printf("Index address: %u size: %u count: %u\n", index->pointer, index->size, index->count);
		return 1;
	} else printf("Index not valid.\n");
	return 0;
}
int DropIndex(Index_type *index){
	int i;
	for(i = 0; i < index->count; i++){
		*(index->pointer + (i * index->size)) = 0;
	}
	index->size = 0;
	index->count = 0;
	free(index->pointer);
	return 0;
}