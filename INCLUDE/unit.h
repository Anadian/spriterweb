//unit.h

#ifndef UNIT_H
#define UNIT_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

typedef float SI_s; //second
typedef float SI_m; //metre
typedef unsigned long SI_t; //tick
typedef signed long SI_p; //pixel
typedef unsigned long SI_mf; //MainFrame
typedef unsigned long SI_lf;

SI_p SI_pFromSI_m(SI_m m);
SI_m SI_mFromSI_p(SI_p p);
SI_t SI_tFromSI_s(SI_s s);
SI_s SI_sFromSI_t(SI_t t);
SI_t SI_tFromSI_mf(SI_mf mf);
SI_t SI_tFromSI_lf(SI_lf lf);
SI_lf SI_lfFromSI_t(SI_t t);
SI_mf SI_mfFromSI_t(SI_t t);
SI_s SI_sFromSI_lf(SI_lf lf);
SI_s SI_sFromSI_mf(SI_mf mf);
SI_p SI_pPerSI_tFromSI_mPerSI_s(float mps);
SI_m SI_mPerSI_sFromSI_pPerSI_t(signed long ppt);
SI_p SI_pPerSI_mfFromSI_pPerSI_t(signed long ppt);
SI_p SI_pPerSI_mfFromSI_mPerSI_s(float mps);
SI_p SI_pPerSI_lfFromSI_pPerSI_t(signed long ppt);
SI_p SI_pPerSI_lfFromSI_mPerSI_s(float mps);

#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif //UNIT_H

