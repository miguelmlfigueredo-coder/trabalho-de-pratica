#include <stdio.h>

int assentos[3][5] = {0};
float precos[3];
int opcao, assento, sessao;
int sessao, assento;
int livres, reservados;
float valorSessao, totalGeral;

int main() {

    do {
        printf("\n===== MENU =====\n");
        printf("1 - Mostrar mapa de assentos\n");
        printf("2 - Reservar assento\n");
        printf("3 - Cancelar Reserva\n");
        printf("4 - Mostrar resumo das sessoes\n");
        printf("0 - Encerrar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        if (opcao == 1) {
            //parte de alguem
        } else if (opcao == 2) {

            printf("\n--- RESERVAR ASSENTO ---\n");
            printf("Numero da sessao 1 a 3: ");
            scanf("%d", &sessao);
            printf("Numero do assento 1 a 5: ");
            scanf("%d", &assento);

            if (sessao < 1 || sessao > 3) {
                printf("Sessao invalida! Escolha uma sessao entre 1 e 3. \n");
            } else if (assento < 1 || assento > 5) {
                printf("Assento invalido! Escolha um assento entre 1 e 5. \n");
            } else {
                if (assentos[sessao-1][assento-1] == 0) {
                    assentos[sessao-1][assento-1] = 1;
                    printf("Assento %d da sessao %d reservado com sucesso! \n", assento, sessao);
                    printf("Preco do ingresso: R$ %.2f\n", precos[sessao-1]);
                } else {
                    printf("Assento %d da sessao %d ja esta reservado! \n", assento, sessao);
                }
            }

} else if (opcao == 3) {
    printf("\nDigite o numero da sessao (1 a 3): ");
    scanf("%d", &sessao);

    printf("Digite o numero do assento (1 a 5): ");
    scanf("%d", &assento);

    if (sessao < 1 || sessao > 3) {
        printf("Sessao invalida!\n");

    } else if (assento < 1 || assento > 5) {
        printf("Assento invalido!\n");

    } else if (assentos[sessao - 1][assento - 1] == 1) {
        assentos[sessao - 1][assento - 1] = 0;
        printf("Reserva cancelada com sucesso!\n");

    } else {
        printf("Nao existe reserva nesse assento!\n");
    }
} else if (opcao == 4) {
    
    totalGeral = 0;

    printf("\n===== RESUMO DAS SESSOES =====\n");

    for (int i = 0; i < 3; i++) {        
        livres = 0;
        reservados = 0;

        for (int j = 0; j < 5; j++) {

            if (assentos[i][j] == 0) {
                livres++;
            } else {
                reservados++;
            }
        }

        valorSessao = reservados * precos[i];
        totalGeral += valorSessao;

        printf("\nSessao %d:\n", i + 1);
        printf("Assentos livres: %d\n", livres);
        printf("Assentos reservados: %d\n", reservados);
        printf("Valor das reservas: R$ %.2f\n", valorSessao);
    }

    printf("\nTotal geral das reservas: R$ %.2f\n", totalGeral);
}
        } else if (opcao == 0) {
            printf("Encerrando o programa... \n");
        } else {
            printf("Opcao invalida! Tente novamente. \n");
        }

    } while (opcao != 0);

    return 0;
}