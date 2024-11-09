#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

// Fun��o de valida��o de senha.
int ValidacaoDeSenha(char *senha) {
    int maiusc = 0;
    int num = 0;
    int tamanho = strlen(senha);

    if (tamanho <= 8) {
        printf("\nA senha possui menos de 8 d�gitos, tente novamente.\n");
        return 0;
    }

    for (int i = 0; i < tamanho; i++) {
        if (isupper(senha[i])) {
            maiusc = 1;
        }
        if (isdigit(senha[i])) {
            num++;
        }
    }

    if (maiusc == 0) {
        printf("\nA senha deve conter pelo menos uma letra MAI�SCULA.\n");
        return 0;
    }

    if (num < 3) {
        printf("\nA senha deve conter pelo menos 3 n�meros.\n");
        return 0;
    }

    return 1;
}

// Fun��o principal
int main() {
    char Cadastrousuario[100], Cadastrosenha[100], usuario[100], senha[100];
    char nivelAcesso[10];

    setlocale(LC_ALL, "Portuguese");

    // Escopo principal do cadastro
    printf("Para se cadastrar, deve-se digitar o nome de usu�rio, senha e n�vel de acesso.\n");
    printf("-------------------------------------------------------------\n");

    printf("\nDigite o seu nome de usu�rio: ");
    if (fgets(Cadastrousuario, sizeof(Cadastrousuario), stdin) != NULL) {
        Cadastrousuario[strcspn(Cadastrousuario, "\n")] = '\0';
    }

    printf("\nDigite sua senha (Deve conter pelo menos 8 d�gitos, 3 n�meros e pelo menos uma letra MAI�SCULA): ");
    if (fgets(Cadastrosenha, sizeof(Cadastrosenha), stdin) != NULL) {
        Cadastrosenha[strcspn(Cadastrosenha, "\n")] = '\0';
    }

    if (!ValidacaoDeSenha(Cadastrosenha)) {
        printf("Senha inv�lida! Tente novamente.\n");
        return 1;
    }

    printf("\nEscolha o n�vel de acesso (funcionario, gerente, CEO): ");
    if (fgets(nivelAcesso, sizeof(nivelAcesso), stdin) != NULL) {
        nivelAcesso[strcspn(nivelAcesso, "\n")] = '\0';
    }

    printf("\n-----------------------------------------------------------\n");
    printf("Cadastro efetuado com sucesso!\n");

    // Escopo do login
    printf("\nFa�a o login.\n");
    printf("Digite o seu nome de usu�rio: ");
    if (fgets(usuario, sizeof(usuario), stdin) != NULL) {
        usuario[strcspn(usuario, "\n")] = '\0';
    }

    printf("Digite a sua senha: ");
    if (fgets(senha, sizeof(senha), stdin) != NULL) {
        senha[strcspn(senha, "\n")] = '\0';
    }

    // Valida��o se o login corresponde ao cadastro
    if (strcmp(usuario, Cadastrousuario) == 0 && strcmp(senha, Cadastrosenha) == 0) {
        printf("LOGIN bem-sucedido.\n");

        // Verifica o n�vel de acesso e direciona para o arquivo correspondente
        if (strcmp(nivelAcesso, "funcionario") == 0) {
            printf("Acesso ao arquivo: funcionario.txt\n");
            FILE *arquivo = fopen("funcionario.txt", "a");
            if (arquivo != NULL) {
                fprintf(arquivo, "Usu�rio %s acessou como FUNCION�RIO.\n", usuario);
                fclose(arquivo);
            } else {
                printf("Erro ao abrir o arquivo funcionario.txt\n");
            }
        } else if (strcmp(nivelAcesso, "gerente") == 0) {
            printf("Acesso ao arquivo: gerente.txt\n");
            FILE *arquivo = fopen("gerente.txt", "a");
            if (arquivo != NULL) {
                fprintf(arquivo, "Usu�rio %s acessou como GERENTE.\n", usuario);
                fclose(arquivo);
            } else {
                printf("Erro ao abrir o arquivo gerente.txt\n");
            }
        } else if (strcmp(nivelAcesso, "CEO") == 0) {
            printf("Acesso ao arquivo: CEO.txt\n");
            FILE *arquivo = fopen("CEO.txt", "a");
            if (arquivo != NULL) {
                fprintf(arquivo, "Usu�rio %s acessou como CEO.\n", usuario);
                fclose(arquivo);
            } else {
                printf("Erro ao abrir o arquivo CEO.txt\n");
            }
        } else {
            printf("N�vel de acesso inv�lido.\n");
        }

    } else {
        printf("Falha ao logar. Verifique se o usu�rio ou a senha foram digitados corretamente.\n");
    }

    return 0;
}
