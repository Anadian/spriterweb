//unit.h

#ifndef UNIT_H
#define UNIT_H

#ifdef __cplusplus
extern "C" {
#endif //__cplusplus

unsigned long MainFrame;
unsigned long FrameSplit;

typedef float SI_s; //second
typedef float SI_m; //metre
typedef unsigned long SI_t; //tick
typedef signed long SI_p; //pixel
typedef unsigned long SI_f; //frame

SI_p SI_pFromSI_m(SI_m m);
SI_m SI_mFromSI_p(SI_p p);
SI_t SI_tFromSI_s(SI_s s);
SI_s SI_sFromSI_t(SI_t t);
SI_p SI_pPerSI_tFromSI_mPerSI_s(float mps);
SI_m SI_mPerSI_sFromSI_pPerSI_t(signed long ppt);
SI_p SI_pPerSI_fFromSI_pPerSI_t(signed long ppt);
SI_p SI_pPerSI_fFromSI_mPerSI_s(float mps);

#ifdef __cplusplus
}
#endif /*__cplusplus*/

#endif //UNIT_H

