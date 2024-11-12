/*
 * var2_def.h
 *  Created on: 3 oct. 2021
 *      Author: intel14
 */
#ifndef CLASE_GPIO_H_
#define CLASE_GPIO_H_
typedef enum io_e{ ENTRADA, SALIDA}io_e;

/* your class "CLASE_GPIO" or "gpio_s" here*/
typedef struct CLASE_GPIO{
    //CONSTRUCTOR O INICIALIZADOR PARAMETRIZADO
    void (*set_Gpiocongif)(struct CLASE_GPIO* obj_ptr, int puerto, int pin, io_e io);// No se le puede pasar la direccion de la funcion a apuntar  hasta haber creado un objeto
                                                               // por ejemplo: obj.set_Gpiocongif = set_Gpio;
    int _puerto;
    int _pin;
    io_e  _io;
    const char* _cadena;
}gpio_s;
/* Prototipos de los metodos */
void set_Gpio (gpio_s * obj_ptr, int n_puerto, int n_pin, io_e io);
void mostrar (gpio_s  *obj_ptr);
//*set_Gpiocongif = &set_Gpio;    // NO SE PUEDE SIN UN OBJETO

#endif /* CLASE_GPIO_H_ */
