#include "funciones.h"
#include <math.h>

float CalcularCuota(float monto, int plazo_en_meses, float tasa_de_interes) {
    float interes_mensual = CalcularInteres(monto, tasa_de_interes);
    float cuota = (monto * tasa_de_interes * pow(1 + tasa_de_interes, plazo_en_meses)) / (pow(1 + tasa_de_interes, plazo_en_meses) - 1);
    return cuota;
}

float CalcularInteres(float monto, float tasa_de_interes) {
    return monto * tasa_de_interes;
}

float CalcularCapital(float monto, float cuota, float interes, int plazo_en_meses) {
    return cuota - interes;
}