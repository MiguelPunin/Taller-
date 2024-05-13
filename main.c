        #include <stdio.h>
        #include <math.h>
        #include "funciones.h"

        int main() {
            float monto, tasa_de_interes, cuota;
            int plazo_en_anios;

            printf("Ingrese el monto del crédito: ");
            scanf("%f", &monto);

            printf("Ingrese el plazo del crédito en años: ");
            scanf("%d", &plazo_en_anios);

            printf("Ingrese la tasa de interés anual (en porcentaje, por ejemplo 10 para 10%%): ");
            scanf("%f", &tasa_de_interes);

            // Convertir la tasa de interés de porcentaje a decimal
            tasa_de_interes /= 100.0;

            // Convertir plazo de años a meses
            int plazo_en_meses = plazo_en_anios * 12;

            // Encabezado de la tabla
            printf("\n| Año\t| Capital Restante\t| Capital a Pagar\t| Interés Anual\t| Capital + Interés\t| Cuota Mensual\t|\n");
            printf("----------------------------------------------------------------------------------------------------\n");

            // Variables para almacenar el total del interés y de la cuota anual
            float total_interes = 0.0;
            float total_cuota_anual = 0.0;

            // Calcular y mostrar detalles para cada año
            for (int i = 1; i <= plazo_en_anios; i++) {
                // Calcular la cuota mensual
                cuota = CalcularCuota(monto, i * 12, tasa_de_interes);

                // Calcular el interés del año actual
                float interes_anual_actual = CalcularInteres(monto, tasa_de_interes);

                // Calcular el capital a pagar en el año actual
                float capital_anual_actual = CalcularCapital(monto, cuota, interes_anual_actual, i * 12);

                // Sumar al total del interés y de la cuota anual
                total_interes += interes_anual_actual;
                total_cuota_anual += cuota * 12;

                // Mostrar detalles para el año
                printf("| %d\t| %.2f\t\t\t| %.2f\t\t| %.2f\t\t| %.2f\t\t| %.2f\t\t|\n",
                       i, monto, capital_anual_actual, interes_anual_actual, capital_anual_actual + interes_anual_actual, cuota);

                // Actualizar el monto restante
                monto -= capital_anual_actual;
            }

            // Mostrar totales
            printf("\nTotal Interés Acumulado: %.2f\n", total_interes);
            printf("Total Cuota Anual: %.2f\n", total_cuota_anual);

            return 0;
        }
