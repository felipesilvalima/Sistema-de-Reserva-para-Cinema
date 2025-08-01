#include <stdio.h>//DECLARAÇÃO DE BLIBLIOTECAS
#include <string.h>
#include <stdlib.h>
struct Reserva
{
    char movies[20][30];
    int assentos[20];
    char dates[20][30];
    char times[20][30];
    char type_sessions[20][30];
    char languagens[20][30];
    char rooms[20][30];
    char payments[20][30];
};

int main()
{
    void exibirFilmes();//FUNÇÕES
    void exibirSessoes();
    void exibirAssentos();
    void exibirPagamentos();
    int Login(char user[20], char password[20]);
    int LoginADM(char user[20], char password[20]);

    char user[20];//DECLARAÇÃO DE VARIVAEIS
    char password[20];
    int result_user = 0;
    int sair = 0;
    int movie = 0;
    int session = 0;
    int seat = 0;
    int seat_chosen[20] = {0};
    int i = 0;
    int c = 1;
    char confirm_reservation;
    int payment_end = 0;
    int payment_chosen = 0;
    int payment_confirm = 0;
    int confirmed_payment = 0;
    int menu = 0;
    int menu_chosen = 0;
    int fim = 1;


    const char FILMES[6][30] = {"","Bailarina", "Trem-Bala","Pecadores","Confinado","Warload"};//DECLARÇÃO DAS CONSTANTES
    const char DATE[6][15] = {"","01/05/2025","01/05/2025","01/05/2025","02/05/2025","03/05/2025"};
    const char TIME[6][10] = {"","18:00","19:30","20:00","17:30","19:00"};
    const char TYPE_SESSION[6][10] = {"","D2","3D","3D","3D","IMAX 3D"};
    const char LANGUAGE[6][10] = {"","Dublado","Legendado","Dublado","Dublado","Legendado"};
    const char ROOM [6][10] = {"","Sala 1","Sala 2","Sala 3","Sala 1","Sala 2"};
    const char PAYMENT[3][20] = {"","PIX","ESPÉCIE"};

    struct Reserva rv;

    while(fim == 1)//LAÇO PARA NÃO ENCERRAR O PROGRAMAR
    {

        printf("==========================MENU====================================\n\n");

        while(menu == 0)//LAÇO DO MENU INICIAL
        {
            printf("(1)- Login do Usuário\n");
            printf("(2)- Login do Administrado\n");
            scanf("%d", &menu_chosen);
            while(getchar() != '\n');
    
            while(menu_chosen != 1 && menu_chosen != 2 )//VALIDAÇÃO DAS OPÇÕES DE MENU
            {
                printf("Digite um opção válida\n");
                scanf("%d", &menu_chosen);
                while(getchar() != '\n');
            }
    
            if(menu_chosen == 1){break;}// DIRECIONAR AO LOGIN DO USUÁRIO
    
            if(menu_chosen == 2)// DIRECIONAR AO LOGIN DO ADMINISTRADOR
            {
                printf("==========================LOGIN DO ADMINISTRADOR====================================\n\n");

                while(menu != 1)//LOGIN DO ADM
                {
         
                     printf("Digite o Usuário\n");
                     fgets(user,20,stdin);
                     user[strcspn(user, "\n")] = 0;
             
                     printf("Digite a Senha\n");
                     fgets(password,20,stdin);
                     password[strcspn(password, "\n")] = 0;
             
                     result_user = LoginADM(user, password);//RETORNO DA FUNÇÃO LOGIN DO ADM
         
                     if(result_user == 1)// SE O ADM FOR AUTENTICADO COM SUCESSO
                     {
                         int reservation_found = 0; // 0 RESERVAS ENCONTRADAS

                         if(payment_confirm > 0)
                         {
                            while(menu != 1)// LAÇO DE SERVIÇOS DO ADM
                            {
                                for (int u = 1; u < c; u++)//LISTAGEM DE RESERVAS
                                {
                                    reservation_found = 1;
                                    printf("ID: %d\n", u);
                                    printf("FILME: %s\n",rv.movies[u]);
                                    printf("DATA: %s\n",rv.dates[u]);
                                    printf("HORA: %s\n",rv.times[u]);
                                    printf("TIPO DE SESSÃO: %s\n",rv.type_sessions[u]);
                                    printf("IDIOMA: %s\n",rv.languagens[u]);
                                    printf("ASSENTO: %d\n",rv.assentos[u]);
                                    printf("PAGAMENTO: %s\n\n",rv.payments[u]);
                                }
    
                                printf("(1)- Confirmar Pagamentos\n");//OPÇÕES DE CONFIRMAÇÃO E CANCELAMENTO DE PAGAMENTO
                                printf("(2)- Cancelar Pagamentos\n");
                                printf("(3)- Sair\n");
                                scanf("%d", &payment_end);
                                while(getchar() != '\n');
    
                                while(payment_end != 1 && payment_end != 2 && payment_end != 3)// VALIDAÇÃO DE OPÇÕES DE CONFRIMAÇÃO E CANCELAMENTO DE PAGAMENTO OU SAIR
                                {
                                    scanf("%d", &payment_end);
                                    while(getchar() != '\n');
                                }
    
                                if(payment_end == 1)// SE PAGAMENTO FOR CONFIRMADO
                                {
                                  int id_reserva = 0;

                                  printf("Digite o ID da reserva para confirmar o pagamento!\n");
                                  scanf("%d", &id_reserva);//ID DA RESERVA

                                  while(id_reserva == 0 || id_reserva > c)//VALIDAÇÃO DAS RESERVAS QUE PODEM SER ESCOLHIDAS
                                  {
                                     scanf("%d", &id_reserva);
                                  }
                                  
                                  for(int id = id_reserva; id < c; id++)//ALTERAÇÃO NA LISTA DE RESERVAR
                                  {
                                     strcpy(rv.movies[id], rv.movies[id +1]);
                                     strcpy(rv.times[id], rv.times[id +1]);
                                     strcpy(rv.type_sessions[id], rv.type_sessions[id +1]);
                                     strcpy(rv.languagens[id], rv.languagens[id +1]);
                                      rv.assentos[id] = rv.assentos[id +1];
                                     strcpy(rv.payments[id], rv.payments[id +1]); 
                                  }

                                    c--;
                                    confirmed_payment = 1;
                                     printf("Pagamentos Confirmados com sucesso!\n\n");

                                }
    
                                if(payment_end == 2)// SE PAGAMENTO FOR CANCELADO FEEDBACK NEGATIVO
                                {
                                    int id_reserva = 0;

                                  printf("Digite o ID da reserva para Cancelar o pagamento!\n");
                                  scanf("%d", &id_reserva);//ID DA RESERVA

                                  while(id_reserva == 0 || id_reserva > c)//VALIDAÇÃO DAS RESERVAS QUE PODEM SER ESCOLHIDAS
                                  {
                                     scanf("%d", &id_reserva);
                                  }
                                  
                                  for(int id = id_reserva; id < c; id++)//ALTERAÇÃO NA LISTA DE RESERVAR
                                  {
                                     strcpy(rv.movies[id], rv.movies[id +1]);
                                     strcpy(rv.times[id], rv.times[id +1]);
                                     strcpy(rv.type_sessions[id], rv.type_sessions[id +1]);
                                     strcpy(rv.languagens[id], rv.languagens[id +1]);
                                      rv.assentos[id] = rv.assentos[id +1];
                                     strcpy(rv.payments[id], rv.payments[id +1]); 
                                  }

                                    c--;
                                    confirmed_payment = 2;
                                     printf("Pagamentos Cancelador!\n\n");

                                }

                                if(payment_end == 3){menu = 1;}
                            }
                         }

                         if(reservation_found == 0)// SE NÃO EXISTIR RESERVA FEEDBACK NEGATIVO
                         {
                            printf("Não a nenhuma reserva!\n");
                         }
                     }
                }
                menu = 0;
    
            }
    
        }

        printf("==========================LOGIN DO USUÁRIO====================================\n\n");

        while(sair == 0)// LAÇO DOS SERVIÇOS PARA CLIENTE
        {
    
            printf("Digite o Usuário\n");
            fgets(user,20,stdin);
            user[strcspn(user, "\n")] = 0;
        
            printf("Digite a Senha\n");
            fgets(password,20,stdin);
            password[strcspn(password, "\n")] = 0;
        
            result_user = Login(user, password);//RETORNO DA FUNÇÃO LOGIN DO USUÁRIO
        
            if(result_user == 1)// USUÁRIO AUTENTICADO
            {
                if(confirmed_payment == 1)// SE O PAGAMENTO FOR CONFIRMADO RECEBERAR FEEDBACK DE CONFIRMAÇÃO E COMPROVANTE
                {
                    int numb_proof = rand();
                    printf("Reserva confirmada com sucesso!\n");
                    printf("seu número de Comprovante é [%d]\n", numb_proof);
                }

                if (confirmed_payment == 2)// SE O PAGAMENTO FOR CANCELADO RECEBERAR FEEDBACK NEGATIVO
                {
                    printf("Sua Reserva foi cancelada!!\n");
                }

                
                while(sair != 1)// LAÇO PARA FAZER A RESERVA
                {
                    printf("==========================ESCOLHER FILME====================================\n\n");
                    
                    exibirFilmes();//FUNÇÃO DE EXIBIR FILMES
                    printf("Escolhar um filme:\n");
                    scanf("%d", &movie);
                    while(getchar() != '\n');
    
                    while(movie == 0 || movie > 5)//VALIDAÇÃO DAS OPÇÕES QUE CONTEM NA LISTA DE FILMES
                    {
                        printf("Escolhar um filme que contem na lista\n");
                        scanf("%d", &movie);
                        while(getchar() != '\n');
                    }

                    strcpy(rv.movies[c], FILMES[movie]);
                   
                    printf("==========================ESCOLHER SESSÃO====================================\n\n");
    
                    exibirSessoes();//FUNÇÃO DE EXIBIR SESSÕES
                    printf("Escolhar uma sessão:\n");
                    scanf("%d",&session);
                    while(getchar() != '\n');
    
                    while(session == 0 || session > 5)//VALIDAÇÃO DAS OPÇÕES QUE CONTEM NA LISTA
                    {
                        printf("Escolhar uma sessão:\n");
                        scanf("%d",&session);
                        while(getchar() != '\n');
                    }

                    strcpy(rv.dates[c], DATE[session]);
                    strcpy(rv.times[c], TIME[session]);
                    strcpy(rv.type_sessions[c], TYPE_SESSION[session]);
                    strcpy(rv.languagens[c], LANGUAGE[session]);
                    strcpy(rv.rooms[c], ROOM[session]);
    
                    printf("==========================ESCOLHER ASSENTOS====================================\n\n");
    
                    exibirAssentos();//FUNÇÃO DE EXIBIR TODOS OS ASSENTOS
                    printf("Escolhar um assento:\n");
                    scanf("%d",&seat);
                    while(getchar() != '\n');
    
                    while(seat == 0 || seat > 20)//VALIDAÇÃO DAS OPÇÕES QUE CONTEM NA LISTA
                    {
                        printf("Escolhar uma assento:\n");
                        scanf("%d",&seat);
                        while(getchar() != '\n');
                    }
    

                    for(int j = 0; j < 20; j++)//CASO O ASSENTO ESCOLHIDO JÁ TENHA SIDO ESCOLHIDO POR OUTRAR PESSOA RETORNAR UM FEEDBACK DO SISTEMA
                    {

                        if(seat == seat_chosen[j])
                        {
                            printf("Esse assento Já foi escolhido:\n");
                            exibirAssentos();//FUNÇÃO DE EXIBIR TODOS OS ASSENTOS
                            printf("Escolhar um novo assento:\n");
                            scanf("%d",&seat);
                            while(getchar() != '\n');
    
                            while(seat == 0 || seat > 20 || seat == seat_chosen[j])//VALIDAÇÃO DAS OPÇÕES DE ASSENTOS E ASSENTOS VAGOS
                            {
                                printf("Por favor Escolhar uma assento que estejá na lista:\n");
                                scanf("%d",&seat);
                                while(getchar() != '\n');
                            }
                        }
                        
                    }


                    rv.assentos[c] = seat;// AQUI ESSA VARIAVEL DO STRUCT ESTÁ RECEBENDO TODOS OS ASSENTOS QUE VÃO SER OCUPADO PELOS CLIENTES
                    seat_chosen[i] = seat;// AQUI O ARRAY ESTÁ RECEBENDO O VALOR DO ASSENTO DO CLIENTE
                    
                    printf("Confirmar Reserva: (Y/N)\n");//CONFIRMAÇÃO DA RESERVA
                    scanf("%c", &confirm_reservation);
                    while(getchar() != '\n');
    
                    while( confirm_reservation != 'y' && confirm_reservation != 'Y' && confirm_reservation != 'n' && confirm_reservation != 'N')//VALIDAÇÃO DA OPÇÕES DE CONFIRMAÇÃO
                    {
                        printf("Confirmar Reserva: (Y/N)\n");
                        scanf("%c", &confirm_reservation);
                        while(getchar() != '\n');
                    }
    
                    if(confirm_reservation == 'y' || confirm_reservation == 'Y')// SE O CLIENTE CONFIRMA A RESERVA
                    {
                        i++; // ENCREMENTO PARA VALIDAÇÃO DOS ASSENTOS 
    
                        printf("==========================PAGAMENTOS====================================\n\n");
    
                        exibirPagamentos();//EXIBIR OS TIPOS DE PAGAMENTOS
                        printf("Escolhar o tipo de pagamento:\n");
                        scanf("%d", &payment_chosen);
                        while(getchar() != '\n');
    
                        while(payment_chosen == 0 || payment_chosen > 2)//VALIDAÇÃO DAS OPÇÕES DE PAGAMENTO
                        {
                            printf("Escolhar o tipo de pagamento que está na lista:\n");
                            scanf("%d", &payment_chosen);
                            while(getchar() != '\n');
                        }

                        strcpy(rv.payments[c], PAYMENT[payment_chosen]);
    
                        if(payment_chosen > 0)// SE O PAGAMENTO FOR FEITO
                        {
                            payment_confirm += 1;
                            c++;
                            int confirm_option = 0;

                            printf("Espere a confirmação do pagamento\n");
    
                             printf("(1)- Continuar\n");//OPÇÃO DE CONTINUAR OU SAIR
                            printf("(2)- Sair\n");
                            scanf("%d", &confirm_option);
                            while(getchar() != '\n');
    
                            while(confirm_option != 1 && confirm_option != 2 )//VALIDAÇÃO DA OPÇÃO DE CONTINUAR OU SAIR
                            {
                                scanf("%d", &confirm_option);
                                while(getchar() != '\n');
                            }
    
                            if(confirm_option == 2){sair = 1; break;}// CASE DESEJE SAIR RETORNARA A MENU PRINCIPAL
                        }
                        
                    }
    
                    if(confirm_reservation == 'n' || confirm_reservation == 'N')//CASO NÃO DESEJE CONFRIMAR A RESERVA
                    {
                        seat_chosen[i] = 0;
                        int confirm_option = 0;
    
                        printf("(1)- Continuar\n");//OPÇÃO DE CONTINUAR OU SAIR
                        printf("(2)- Sair\n");
                        scanf("%d", &confirm_option);
                        while(getchar() != '\n');
    
                        while(confirm_option != 1 && confirm_option != 2 )//VALIDAÇÃO DA OPÇÃO DE CONTINUAR OU SAIR
                        {
                             scanf("%d", &confirm_option);
                                while(getchar() != '\n');
                        }
    
                        if(confirm_option == 2){sair = 1; break;}// CASE DESEJE SAIR RETORNARA A MENU PRINCIPAL
                    }
    
                }
            }
        }
        sair = 0;
    }

    return 0;
}


int Login(char user[20], char password[20])//FUNÇÃO DE LOGIN
{
    const char users[3][20] = {"pedro","marcos","felipe"};//USUÁRIOS
    const char users_password[3][20] = {"102030","1223","1234"};//SENHA DOS USUÁRIOS
    int user_count = 0;// 0 USUÁRIOS ENCONTRADOS

    for(int i = 0; i < 3; i++)//VERIFICAÇÃO USUÁRIO DE 1 POR 1
    {
       if(strcmp(user, users[i]) == 0 && strcmp(password, users_password[i]) == 0)//CONDIÇÃO PARA VERIFICAR SE USUÁRIO É CORRETO
       {
          printf("Usuário Logado!\n");
         return user_count = 1;
       }
    }

    if(user_count == 0)// CASO O USUÁRIO ESTEJÁ INCORRETO
    {
        printf("Usuário inválido\n");
    }
}

int LoginADM(char user[20], char password[20])//FUNÇÃO DE LOGIN DO ADM
{
    const char users[1][20] = {"adm"};//USUÁRIO DO ADM
    const char users_password[1][20] = {"adm123"};//SENHA DOS USUÁRIO DO AMD
    int user_count = 0;// 0 USUÁRIOS ENCONTRADOS

    for(int i = 0; i < 1; i++)//VERIFICAÇÃO USUÁRIO DE 1 POR 1
    {
       if(strcmp(user, users[i]) == 0 && strcmp(password, users_password[i]) == 0)//CONDIÇÃO PARA VERIFICAR SE USUÁRIO É CORRETO
       {
          printf("Usuário Logado!\n\n");
         return user_count = 1;
       }
    }

    if(user_count == 0)// CASO O USUÁRIO ESTEJÁ INCORRETO
    {
        printf("Usuário inválido\n");
    }
}

void exibirFilmes(void)//FUNÇÃO DE EXBIR FILMES
{
    const char FILMES[6][30] = {"","Bailarina", "Trem-Bala","Pecadores","Confinado","Warload"};//LISTA DE FILMES

    for(int i = 1; i < 6; i++)//LAÇO PARA LISTAR TODOS OS FILMES DA LISTA
    {
        printf("%d- %s\n",i, FILMES[i]);
    }
}

void exibirSessoes(void)//FUNÇÃO DE EXIBIR TODAS AS SESSÕES
{
    const char DATE[6][15] = {"","01/05/2025","01/05/2025","01/05/2025","02/05/2025","03/05/2025"};//LISTA DE SESSÕES
    const char TIME[6][10] = {"","18:00","19:30","20:00","17:30","19:00"};
    const char TYPE_SESSION[6][10] = {"","D2","3D","3D","3D","IMAX 3D"};
    const char LANGUAGE[6][10] = {"","Dublado","Legendado","Dublado","Dublado","Legendado"};
    const char ROOM [6][10] = {"","Sala 1","Sala 2","Sala 3","Sala 1","Sala 2"};

    for(int i = 1; i < 6; i++)//LAÇO PARA LISTAR AS SESSÕES
    {
        printf("Opção %d\n", i);
        printf("DATA: %s\n", DATE[i]);
        printf("HORÁRIO: %s\n", TIME[i]);
        printf("TIPO DE SESSÃO: %s\n", TYPE_SESSION[i]);
        printf("IDIOMA: %s\n", LANGUAGE[i]);
        printf("SALA: %s\n\n", ROOM[i]);
    }
}

void exibirAssentos(void)//FUNÇÃO DE EXIBIR TODOS OS ASSENTOS
{
    
    for (int i = 1; i < 20; i++)//LAÇO PARA EXIBIR TODOS ASSENTOS
    {
        printf("[%d]\n", i);
    }
    
}

void exibirPagamentos(void)//FUNÇÃO DE EXIBIR TIPOS DE PAGAMENTO
{
 const char payment[3][20] = {"","PIX","ESPÉCIE"};//LISTA DE TIPOS DE PAGAMENTO

 for(int m = 1; m < 3; m++)//LAÇO QUE VAI LISTA OS TIPOS DE PAGAMENTO
 {
    printf("%d- %s\n",m, payment[m]);
 }

}