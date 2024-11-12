/*
 * clase_gpio.c
 *
 *  Created on: 3 oct. 2021
 *      Author: intel14
 */
#include <clases/clase_gpio.h>
#include <stdio.h>
#include "msp.h"

const char* Cadena[] = { "Entrada", "Salida" };  //COONSTANTES PARA EL ATRIBUTO _cadena
/************************************************
            SETTER
 ************************************************/
void set_Gpio(gpio_s  *obj_ptr,int puerto, int pin, io_e io){
    obj_ptr->_puerto = puerto;
    obj_ptr->_pin = pin;
    obj_ptr->_io = io;

    if ( obj_ptr->_io == ENTRADA)  obj_ptr->_cadena = Cadena[0];  // se le asigna la cadena "Salida"
    else                           obj_ptr->_cadena = Cadena[1]; // se le asigna la cadena "Entrada"

    if (obj_ptr->_puerto == 1){
        P1->SEL0    &= ~(1<<obj_ptr->_pin);
        P1->SEL1    &= ~(1<<obj_ptr->_pin);
        if ( obj_ptr->_io == ENTRADA){
            P1->DIR     &= ~ (1<<obj_ptr->_pin);
            P1->REN     |= (1<<obj_ptr->_pin);
            P1->OUT     |= (1<<obj_ptr->_pin);
        }else{
            P1->DIR     |= (1<<obj_ptr->_pin);
            P1->OUT     &= ~(1<<obj_ptr->_pin);
        }

    }else if(obj_ptr->_puerto == 2){
        P2->SEL0    &= ~(1<<obj_ptr->_pin);
        P2->SEL1    &= ~(1<<obj_ptr->_pin);
        if ( obj_ptr->_io == ENTRADA){
            P2->DIR     &= ~ (1<<obj_ptr->_pin);
            P2->REN     |= (1<<obj_ptr->_pin);
            P2->OUT     |= (1<<obj_ptr->_pin);
        }else{
            P2->DIR     |= (1<<obj_ptr->_pin);
            P2->OUT     &= ~(1<<obj_ptr->_pin);
        }
    }
}

/************************************************
                METODOS
 ************************************************/
void mostrar (gpio_s  *obj_ptr){
    printf("puerto %d\n",obj_ptr->_puerto);
    printf("pin %d\n",obj_ptr->_pin);
    printf("funcion: %s\n",obj_ptr->_cadena);
}


