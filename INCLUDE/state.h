// state.h

#ifndef STATE_H
#define STATE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef enum ModeState {NONE = 0,
	OPENGL_TEST = 1} ModeState_type;

typedef struct CriticalVariables_struct {signed short AppRunning;
	signed short MainThread;
	signed short LogicThread;
	ModeState_type ModeState;} CriticalVariables_type;

CriticalVariables_type CriticalVariables;

#ifdef __cplusplus
}
#endif

#endif //STATE_H