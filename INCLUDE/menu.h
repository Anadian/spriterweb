//menu.h

#ifndef MENU_H
#define MENU_H

#ifdef __cplusplus
extern "C" {
#endif 

typedef struct Entry_struct {
	void *entry;
	void *description;
	char style; //Normal, greyed, hidden
} Entry_type;
unsigned long CurrentMenu;
unsigned long BackMenu;

Entry_type *Entries;

int LoadMenu(unsigned long menu);

#ifdef __cplusplus
}
#endif

#endif //MENU_H