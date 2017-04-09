#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {
    char cadena1 [] ="aprenderaprogramar.com"; char cadena2 [sizeof(cadena1)];
    char cadena3[] = " ok!";    char cadena4[50];
    strcpy (cadena2, cadena1); //Copia cadena1 en cadena2
    printf ("Cadena1 %s y Cadena2 %s \n", cadena1, cadena2);
    printf ("Longitud cadena1 %d\n", strlen(cadena1));

    strcpy (cadena4, cadena1) ;
    printf ("Concatenacion %s\n", strcat(cadena4, cadena3));
    printf ("Cadena4 vale %s \n", cadena4);

    if (strcmp (cadena4, cadena2)==0) 
        puts ("Las cadenas 1 y 2 son iguales");
    if (strcmp (cadena1, cadena3) > 0 )
        puts ("La cadena 1 precede alfabeticamente a la cadena 3");
    return 0; 
}
