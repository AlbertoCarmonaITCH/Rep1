/*
 * Led.h
 *  Created on: Nov 7, 2024
 *      Author: fredy
 */
#ifndef CLASES_LED_H_
#define CLASES_LED_H_

/*  class "Led" here*/
typedef struct Led{
    //CONSTRUCTOR O INCIALIZADOR PARAMETRIZADO
    void (*set_Led)(struct Led* obj_ptr, int puerto, int pin);
    //ATRIBUTOS
    int _puerto;
    int _pin;
    unsigned char _estado;
    //METODOS
    void (*encender)(struct Led* obj_ptr);
    void (*apagar)(struct Led* obj_ptr);
    void (*toggle)(struct Led* obj_ptr);
    // struct Led * _obj_ptr;
}Led;

void set_Led(Led * obj_ptr,int puerto, int pin);
void encender( Led* obj_ptr);
void apagar( Led* obj_ptr);
void toggle( Led* obj_ptr);

const static Led instruction_set[] =
{
     {.set_Led = set_Led,  ._puerto = 0,  ._pin = 0,  ._estado = 0, .encender = encender, .apagar = apagar, .toggle = toggle},
};


const static Led ledInit = {}



#endif /* CLASES_LED_H_ */
