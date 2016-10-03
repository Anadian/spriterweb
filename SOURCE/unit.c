//unit.c

#include "unit.h"
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
SI_p SI_pPerSI_fFromSI_pPerSI_t(signed long ppt){
	return (SI_p)(ppt*FrameSplit);
}
SI_p SI_pPerSI_fFromSI_mPerSI_s(float mps){
	return (SI_p)((SI_pPerSI_tFromSI_mPerSI_s(mps))*FrameSplit);
}