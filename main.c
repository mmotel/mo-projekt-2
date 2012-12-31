#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#include "lib.h"

int main(void){
	long double a,b;
	
	scanData(&a,&b);
	przybliz(a,b);

	return 0;
}
