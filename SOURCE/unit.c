//unit.c

#include "unit.h"
#include "state.h"
#include <math.h>

SI_p SI_pFromSI_m(SI_m m){
	return (SI_p)round(m * 16);
}
SI_m SI_mFromSI_p(SI_p p){
	return (SI_m)(p / 16);
}
SI_t SI_tFromSI_s(SI_s s){
	return (SI_t)round(s * 1000);
}
SI_s SI_sFromSI_t(SI_t t){
	return (SI_s)(t / 1000);
}
SI_p SI_pPerSI_tFromSI_mPerSI_s(float mps){
	return (SI_p)round((mps*16)/1000);
}
SI_m SI_mPerSI_sFromSI_pPerSI_t(signed long ppt){
	return (SI_m)((ppt*1000)/16);
}
SI_p SI_pPerSI_mfFromSI_pPerSI_t(signed long ppt){
	return (SI_p)(ppt*CriticalVariables.MainSplit);
}
SI_p SI_pPerSI_lfFromSI_pPerSI_t(signed long ppt){
	return (SI_p)(ppt*CriticalVariables.LogicSplit);
}
SI_p SI_pPerSI_lfFromSI_mPerSI_s(float mps){
	return (SI_p)(SI_pPerSI_lfFromSI_pPerSI_t(SI_pPerSI_tFromSI_mPerSI_s(mps)));
}
SI_t SI_tFromSI_mf(SI_mf mf){
	return (SI_t)(CriticalVariables.MainSplit*mf);
}
SI_t SI_tFromSI_lf(SI_lf lf){
	return (SI_t)(CriticalVariables.LogicSplit*lf);
}
SI_mf SI_mfFromSI_t(SI_t t){
	return (SI_mf)(t/CriticalVariables.MainSplit);
}
SI_lf SI_lfFromSI_t(SI_t t){
	return (SI_lf)(t/CriticalVariables.LogicSplit);
}
SI_s SI_sFromSI_mf(SI_mf mf){
	return (SI_s)(SI_sFromSI_t(SI_tFromSI_mf(mf)));
}
SI_s SI_sFromSI_lf(SI_lf lf){
	return (SI_s)(SI_sFromSI_t(SI_tFromSI_lf(lf)));
}