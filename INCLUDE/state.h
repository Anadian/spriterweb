// state.h

#ifndef STATE_H
#define STATE_H

#ifdef __cplusplus
extern "C" {
#endif

typedef struct CriticalVariables_struct {signed short AppRunning;
	signed short MainThread;
	signed short LogicThread;
	char State;} CriticalVariables_type;

CriticalVariables_type CriticalVariables;

#ifdef __cplusplus
}
#endif

#endif //STATE_H