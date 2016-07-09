// input.h

#ifndef INPUT_H
#define INPUT_H

#include "build.h"

#ifdef __cplusplus
extern "C" {
#endif

/*typedef struct MappableAction_struct {char *name; char *primary; char *secondary; char *tertiary;} MappableAction_type;
typedef struct PlayerMapping_struct {MappableAction_type key[MAX_MAPPABLE_ACTIONS];} PlayerMapping_type;
typedef struct ControllerInfo_struct {PlayerMapping_type player[MAX_LOCAL_PLAYERS];} ControllerInfo_type;
ControllerInfo_type ci;*/

int InitInput();
int Input();

#ifdef __cplusplus
}
#endif

#endif //INPUT_H