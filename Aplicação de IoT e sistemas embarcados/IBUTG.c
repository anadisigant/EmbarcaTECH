#include <stdio.h>
#include <stdbool.h>
#include <unistd.h>  

// Cáclulo do IBUTG
double calculateIBUTG(double temp_globo, double temp_ar, double umidade) {
    return (0.7 * temp_globo) + (0.2 * temp_ar) + (0.1 * umidade);
}

// Função para simular a coleta de dados (atualizar com sensores reais)
void collectData(double *temp_globo, double *temp_ar, double *umidade) {
    //atualizar com valores obtidos dos sensores
    *temp_globo = 32.0;  
    *temp_ar = 30.0;    
    *umidade = 60.0;     
}

int main() {
    double temp_globo, temp_ar, umidade;
    double ibutg;

    while (true) {
        collectData(&temp_globo, &temp_ar, &umidade);

        ibutg = calculateIBUTG(temp_globo, temp_ar, umidade);

        printf("Temperatura do Globo: %.2f \u00b0C\n", temp_globo);
        printf("Temperatura do Ar: %.2f \u00b0C\n", temp_ar);
        printf("Umidade Relativa: %.2f%%\n", umidade);
        printf("IBUTG Calculado: %.2f\n", ibutg);

        if (ibutg >= 28.0) {
            printf("Alerta: Condições perigosas de calor!\n");
        } else if (ibutg >= 25.0 && ibutg < 28.0) {
            printf("Atenção: Condições quentes!\n");
        } else {
            printf("Condições normais de temperatura.\n");
        }

        printf("\n---\n\n");

        sleep(10);  // Espere 10 segundos antes de coletar novos dados
    }

    return 0;
}
