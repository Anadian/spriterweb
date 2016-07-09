//defs.h

#ifndef DEFS_H
#define DEFS_H

#define PRINTSAFE 1//Comment if you want to turn off printing
#if PRINTSAFE == 1

#define safeprintf if(PRINTSAFE) printf

#endif

#define USELIBCONFIG 1
#define USELUA 1
#define USESDL 1

#define MAX_MAPPABLE_ACTIONS 16
#define MAX_LOCAL_PLAYERS 4

#endif //DEFS_H