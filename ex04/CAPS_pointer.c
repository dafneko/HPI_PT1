#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
void to_upper(char* s)
{
    while (*s)
    {
        if (*s >= 'a' && *s <= 'z')
            *s -= 32;
        s++;
    }
}
 
void upper_and_print(const char s[]) {
        //############ IGNORE THIS PART ############//
	// Wir machen hier eine Kopie von s in t
	size_t len = strlen(s);
	char* t = (char*)malloc(len + 1);
	memcpy(t, s, len + 1);
        //############### UNTIL HERE ###############//
 
	to_upper(t);
	printf("'%s' -> '%s'\n", s, t);
	free(t);
}
 
int main(void) {
	upper_and_print("");			// ""
	upper_and_print("a");			// "A"
	upper_and_print("A");			// "A"
	upper_and_print("AbA");		        // "ABA"
	upper_and_print("bAAb");		// "BAAB"
	upper_and_print("Hallo Welt!");			// "HALLO WELT!"
	upper_and_print("Hasso-Plattner-Institute");	// "HASSO-PLATTNER-INSTITUTE"
	return 0;
}