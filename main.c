#include <clases/clase_gpio.h>
#include <clases/Led.h>
#include <clases/PushBoton.h>
#include "msp.h"
//#include <stdint.h>
//#include <stddef.h>
//#include <stdbool.h>
#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
#include <var1_def.h>
/*****************************************************************************
 * Function: MAIN
 * Preconditions: NINGUNA.
 * Overview:
 * Input: NINGUNA.
 * Output: NINGUNA
 *
 *****************************************************************************/
#define CLASE_LED               // Para compilar el codigo de Clase Led
//#define EJEMPLO_GPIOCLASE     // Para compilar el codigo de EjemploClaseGpio

void main(void)
{
	WDT_A->CTL = WDT_A_CTL_PW | WDT_A_CTL_HOLD;		// stop watchdog timer
	printf("hola Aspectos basicos\n");
#ifdef EJEMPLO_GPIOCLASE
	gpio_s p1;
	gpio_s p2={set_Gpio,2,0,SALIDA};
	gpio_s p3={set_Gpio};

	p1.set_Gpiocongif = set_Gpio;
	p1._puerto = 1;
	p1._pin = 0;
	p1._io = ENTRADA;
	p1._cadena = "Entrada";


	mostrar(&p1);

	set_Gpio(&p1,3,2,SALIDA);
	mostrar(&p1);

	p1.set_Gpiocongif(&p1,1,0,ENTRADA);
	mostrar(&p1);
	mostrar(&p2);

	p3.set_Gpiocongif(&p3,2,1,SALIDA);
	mostrar(&p3);
#endif

#ifdef CLASE_LED

	Led ledrojo = {set_Led};        // Creacion de Objeto Led, asignando su metodo constructor o mas bien Inicializador
	ledrojo.set_Led(&ledrojo,1,0);  // Usando el metodo constructor o Inicializador.

	PushBoton botonIzq ={set_PushBoton};
	botonIzq.set_PushBoton(&botonIzq,1,4);  // Usando el metodo constructor o Inicializador.
	PushBoton botonDer ={set_PushBoton};
	botonDer.set_PushBoton(&botonDer,1,1);








	while(1){
	    if (botonIzq.leer(&botonIzq))
            ledrojo.apagar(&ledrojo);
        else{
            ledrojo.toggle(&ledrojo);
            _delay_cycles(500000);
        }
	    if (botonDer.leer(&botonDer){
	        ledrojo.apagar(&ledR);
	    }
	    else{
	                ledrojo.toggle(&ledrojo);
	                _delay_cycles(500000);
	    }
	}
#endif
}
