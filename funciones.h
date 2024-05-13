#ifndef FUNCIONES_H
#define FUNCIONES_H

float CalcularCuota(float monto, int plazo_en_meses, float tasa_de_interes);
float CalcularInteres(float monto, float tasa_de_interes);
float CalcularCapital(float monto, float cuota, float interes, int plazo_en_meses);

#endif