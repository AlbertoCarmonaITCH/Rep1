/*
 * PushBoton.h
 *  Created on: Nov 7, 2024
 *      Author: fredy
 */
#ifndef CLASES_PUSHBOTON_H_
#define CLASES_PUSHBOTON_H_

/*********  CLASE "PushBoton" ************/
typedef struct PushBoton{
    //CONSTRUCTOR O INICIALIZADOR PARAMETRIZADO
    void (*set_PushBoton)(struct PushBoton* obj_ptr, int puerto, int pin);
    //ATRIBUTOS
    int _puerto;
    int _pin;
    unsigned char _estado;
    //METODOS
    unsigned char (*leer)(struct PushBoton* obj_ptr);
}PushBoton;

void set_PushBoton(PushBoton* obj_ptr, int puerto, int pin);
unsigned char leer(struct PushBoton* obj_ptr);
#endif /* CLASES_PUSHBOTON_H_ */
