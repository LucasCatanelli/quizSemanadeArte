#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Pergunta {
    char desc[500], opcaoA[100], opcaoB[100], opcaoC[100], opcaoD[100], resposta_final;
};

struct Resultado_Questao {
    int pontuacao;
    char nome[100], sobrenome[100];
};

int main() {
    struct Pergunta perguntas[4];

    struct Pergunta pergunta1 = {
        "1. A semana da arte moderna e considerada um marco do modernismo no Brasil. Os modernistas estavam decididos a criar uma identidade para a arte brasileira. Cartaz da semana da arte moderna, exibido em 1922.\n\nQual o ano da semana da arte moderna?",
        "A) 1965",
        "B) 2021",
        "C) 2000",
        "D) 1922",
        'D'
    };
    perguntas[0] = pergunta1;

    struct Pergunta pergunta2 = {
        "2. Na epoca, a semana da arte moderna foi duramente criticada pela elite, o escritor famoso Monteiro Lobato fez duras criticas para as obras de Anita Malfatti (Uma das principais artistas do modernismo) 'Arte anormal' disse o escritor.\n\nO que Monteiro Lobato achava da arte de Anita Malfatti?",
        "A) Adorava",
        "B) Gostava",
        "C) Nao se importava",
        "D) Nao gostava e chamava de 'Arte anormal'",
        'D'
    };
    perguntas[1] = pergunta2;

    struct Pergunta pergunta3 = {
        "3. A semana da arte moderna aconteceu no Teatro Municipal de Sao Paulo.\n\nQual cidade aconteceu a semana da arte moderna?",
        "A) Sao Paulo",
        "B) Paris",
        "C) Rio de Janeiro",
        "D) Salvador",
        'A'
    };
    perguntas[2] = pergunta3;

    struct Pergunta pergunta4 = {
        "4. O quadro pintado por Tarsila do Amaral em 1933 e um dos principais marcos do modernismo. Ele contem operarios que retratam o processo de industrializacao do estado de Sao Paulo.\n\nO que o quadro retrata?",
        "A) Pessoas voando",
        "B) Processo de industrializacao do estado de Sao Paulo",
        "C) Avanco da medicina no Brasil",
        "D) Processo de industrializacao nos Estados Unidos",
        'B'
    };
    perguntas[3] = pergunta4;

    int numPerguntas = 4;

    printf("Seja Bem-vindo ao Quiz da Arte Moderna Brasileira!\n");

    int numeroParticipantes;
    printf("Quantos participantes vao responder o quiz? : ");
    scanf("%d", &numeroParticipantes);

    FILE *arquivoResultado_Questao = fopen("resultados4.csv", "a");

    if (arquivoResultado_Questao == NULL) {
        printf("Nao foi possivel abrir o arquivo que contem os resultados.\n");
        return 1;
    }

    for (int x = 0; x < numeroParticipantes; x++) {
        printf("\nDados do Participante %d:\n", x + 1);

        struct Resultado_Questao resultadoAtual;
        	printf("Nome do participante: ");
        	scanf("%s", resultadoAtual.nome);

        printf("Sobrenome do participante: ");
        scanf("%s", resultadoAtual.sobrenome);

        resultadoAtual.pontuacao = 0;

        for (int i = 0; i < numPerguntas; i++) {
            printf("\n%s\n", perguntas[i].desc);
            printf("%s\n%s\n%s\n%s\n", perguntas[i].opcaoA, perguntas[i].opcaoB, perguntas[i].opcaoC, perguntas[i].opcaoD);

            char resposta;
            printf("Responda utilizando em MAIUSCULO (A/B/C/D): ");
            scanf(" %c", &resposta);

            if (resposta == perguntas[i].resposta_final) {
                resultadoAtual.pontuacao++;
                printf("Parabens!! Sua resposta esta correta!\n");
            } else {
                printf("Infelizmente sua resposta esta incorreta. A resposta correta e: %c\n", perguntas[i].resposta_final);
            }
        }

        fprintf(arquivoResultado_Questao, "Nome do Participante: %s %s, Pontuacao do Participante: %d\n", resultadoAtual.nome, resultadoAtual.sobrenome, resultadoAtual.pontuacao);
    }

    fclose(arquivoResultado_Questao);

	system ("pause");
    return 0;
}
