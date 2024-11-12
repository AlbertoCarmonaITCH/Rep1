/*
 * Led.c
 *  Created on: Nov 7, 2024
 *      Author: fredy
 */
#include <clases/Led.h>
#include <stdio.h>
#include "msp.h"

//******* METODO CONSTRUCTOR set_Led *******
void set_Led(Led* obj_ptr,int puerto, int pin){
    obj_ptr->_puerto = puerto;
    obj_ptr->_pin = pin;

    if (obj_ptr->_puerto == 1){
        P1->SEL0    &= ~(1<<obj_ptr->_pin);
        P1->SEL1    &= ~(1<<obj_ptr->_pin);
        P1->DIR     |= (1<<obj_ptr->_pin);
        P1->OUT     &= ~(1<<obj_ptr->_pin);
    }else if(obj_ptr->_puerto == 2){
        P2->SEL0    &= ~(1<<obj_ptr->_pin);
        P2->SEL1    &= ~(1<<obj_ptr->_pin);
        P2->DIR     |= (1<<obj_ptr->_pin);
        P2->OUT     &= ~(1<<obj_ptr->_pin);
    }
    // INICIALIZA O ASIGNA LOS METODOS A LOS PUNTEROS DEL OBJETO LED
    obj_ptr->apagar =apagar;
    obj_ptr->encender = encender;
    obj_ptr->toggle = toggle;
}

void encender(Led* obj_ptr){
    if (obj_ptr->_puerto == 1){
        P1->OUT     |= (1<<obj_ptr->_pin);
    }else if(obj_ptr->_puerto == 2){
        P2->OUT     |= (1<<obj_ptr->_pin);
    }
}
void apagar(Led* obj_ptr){
    if (obj_ptr->_puerto == 1){
        P1->OUT     &= ~(1<<obj_ptr->_pin);
    }else if(obj_ptr->_puerto == 2){
        P2->OUT     &= ~(1<<obj_ptr->_pin);
    }
}
void toggle(Led* obj_ptr){
    if (obj_ptr->_puerto == 1){
        P1->OUT     ^= (1<<obj_ptr->_pin);
    }else if(obj_ptr->_puerto == 2){
        P2->OUT     ^= (1<<obj_ptr->_pin);
    }
}




