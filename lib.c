#include <stdio.h>
#include <math.h>
#include <stdlib.h>

long double fun(long double x){	 //funkcja wyliczaj¹ca wartoœæ funkcji f(x)=2x-6-  ln?x
	return 2*x - 6 - log(x);
} 

int sign(long double x){	//funkcja signum 
	if(x == 0) return 0;
	else if(x < 0) return -1;
	else return 1;
}

void scanData(long double *aa, long double *bb){  //funckja wczytuj¹ca dane
	printf("Podaj wartosci a>0 oraz b>a takie ,ze f(a)*f(b)<0\n");
	while(1){
		printf("a = ");
		scanf("%Lf", aa);
		if( *(aa) > 0 ){ break; }
	}
	while(1){
		printf("b = ");
		scanf("%Lf", bb);
		if( *(bb) > *(aa) && ( fun( *(aa) ) * fun( *(bb) ) ) < 0 ){ break; }
	}
}

void polowienie(int i, long double aa, long double bb, long double EE){  //funkcja stosuj¹ca metodê po³ownienia
	long double c = (aa + bb) / 2;
	long double f_od_c = fun(c);
	
	if( f_od_c == 0 || fabs( aa - bb ) < EE  ){ 
		printf("METODA POLOWIENIA\n");
		printf("Liczba krokow: [ %i ] \n", i);
		printf("punkt zerowy x0 = [ %.64Lf ]\n", c);
		printf("f(x0) = [ %.64Lf ]\n\n", f_od_c);
	
		return; 
	}
	else{
		if( sign( fun(aa) ) != sign( f_od_c ) ){
			polowienie(++i,aa,c,EE);
		}
		else if( sign( f_od_c ) != sign( fun(bb) ) ){
			polowienie(++i,c,bb,EE);
		}
	}
}


void sieczne(int i, long double x0, long double x1, long double EE){  //funkcja stosuj¹ca metodê siecznych
	long double x;

	x = x1 - ( ( fun( x1 ) * ( x1 - x0 ) ) / ( fun( x1 ) - fun( x0 ) ) );
	
	long double f_od_x = fun( x );

	if( f_od_x == 0 || fabs( x1 - x ) < EE || x <= 0 ) {
		printf("METODA SIECZNYCH\n");
		printf("Liczba krokow: [ %i ]\n", i);
		printf("Punkt zerowy x0 = [ %.64Lf ]\n", x);
		printf("f(x0) = [ %.64Lf ]\n\n", f_od_x);

		return; 
	}
	else{
		sieczne(++i, x1, x, EE);
	}
}




void przybliz(long double aa, long double bb){  //funkcja przybli¿aj¹ca u¿ywaj¹ca metod po³owienia i siecznych
long double EE;
int t;
while(1){
		while(1){
			printf("podaj dokladonosc 0 < E < 1, E = ");
			scanf("%Lf", &EE);
			if( EE > 0 && EE < 1 ) break;
		}

		polowienie(1, aa, bb, EE);
		sieczne(1, aa, bb, EE);
	
		printf("aby zakonczyc wpisz 0, aby kontynuowac wpisz 1.");
		scanf("%i", &t);
		if( t != 1 ) break;
}
}
