/*
 * PushBoton.c
 *  Created on: Nov 7, 2024
 *      Author: fredy
 */
#include <clases/PushBoton.h>
#include <stdio.h>
#include "msp.h"

// ******* METODO CONSTRUCTOR set_PushBoton *******
void set_PushBoton(PushBoton* obj_ptr, int puerto, int pin){
    obj_ptr->_puerto = puerto;
    obj_ptr->_pin = pin;
    if (obj_ptr->_puerto == 1){
        P1->SEL0    &= ~(1<<obj_ptr->_pin);
        P1->SEL1    &= ~(1<<obj_ptr->_pin);
        P1->DIR     &= ~ (1<<obj_ptr->_pin);
        P1->REN     |= (1<<obj_ptr->_pin);
        P1->OUT     |= (1<<obj_ptr->_pin);
    }else if(obj_ptr->_puerto == 2){
        P2->SEL0    &= ~(1<<obj_ptr->_pin);
        P2->SEL1    &= ~(1<<obj_ptr->_pin);
        P2->DIR     &= ~ (1<<obj_ptr->_pin);
        P2->REN     |= (1<<obj_ptr->_pin);
        P2->OUT     |= (1<<obj_ptr->_pin);
    }
    // INICIALIZA O ASIGNA LOS METODOS A LOS PUNTEROS DEL OBJETO PushBoton
    obj_ptr->leer =leer;
}
unsigned char leer(struct PushBoton* obj_ptr){
    if (obj_ptr->_puerto == 1){
        obj_ptr->_estado = P1->IN  & (1<<obj_ptr->_pin);
    }else if(obj_ptr->_puerto == 2){
        obj_ptr->_estado = P2->IN  & (1<<obj_ptr->_pin);
    }
    return obj_ptr->_estado;
}



