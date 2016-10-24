//menu.c
/*
#include "menu.h"
#include "stdio.h" //sprintf
#include "parson.h"
#include "stretchy_buffer.h"
#include "utf8.h"
#include "delog.h"

int LoadMenu(unsigned long menu){
	char *filename;
	sprintf(filename, "Resources/menu%d.json", menu);
	/*FILE *file;
	file = fopen(filename, "r");*
	JSON_Value *Root_value;
	Root_value = json_parse_file(filename);
	JSON_Array *Root_array;
	Root_array = json_value_get_array(Root_value);
	int i;
	int ArraySize;
	ArraySize = json_array_get_count(Root_array);
	for(i = 0; i < ArraySize; i++){
		JSON_Object Object;
		Object = json_array_get_object(Root_array, i);
		Entry_type Entry;
		utf8cpy(Entry.entry,json_object_get_string(Object, "entry"));
		utf8cpy(Entry.description,json_object_get_string(Object, "description"));
		Entry.style = (int)(json_object_get_number(Object, "style"));
		sb_push(Entries,Entry);
		printl(5, "%d: %d %s %s %d", i, (int)(*Object), Entry.entry, Entry.description, Entry.style);
	}
	printl(3, "%s: %d | %d %d %d %d", __func__, menu, (int)(*Root_value), (int)(*Root_array), ArraySize, sb_count(Entries));
	json_object_clear(Object);
	json_array_clear(Root_array);
	json_value_free(Root_value);
	return sb_count(Entries);
}
int ClearEntries(){
	if(Entries != NULL){
		sb_free(Entries);
		Entries = NULL;
	}
	return 0;
}*/
