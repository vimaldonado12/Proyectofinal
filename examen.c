/* Vivian Maldonado
Proyecto Final */

#include <stdio.h>

int oyentes = 0;
int primero, segundo;

int votos[100][3];
int sumas[10] = {0};
int puntosOyentes[100] = {0};

//Funciones
void VOTOS();
void suma();
void win();
void premio();

int main()
{
    printf("Bienvenido al concurso de canciones\n\n");

    printf("En este programa cada oyente debera votar por 3 canciones.\n");
    printf("Las canciones estan numeradas del 0 al 9.\n");
    printf("La primera cancion recibe 3 puntos.\n");
    printf("La segunda cancion recibe 2 puntos.\n");
    printf("La tercera cancion recibe 1 punto.\n\n");

    printf("Al final se calculara:\n");
    printf("- La cancion mas votada.\n");
    printf("- La segunda cancion mas votada.\n");
    printf("- Los puntos obtenidos por cada oyente.\n");
    printf("- El oyente ganador.\n\n");

    printf("Para terminar el programa escribe -1 en el primer voto.\n");

    VOTOS();
    suma();
    win();
    premio();

    return 0;
}



//Captura de votos
void VOTOS()
{
    while(oyentes < 100)
    {
        printf("\nOyente %d\n", oyentes);

        printf("Voto 1: ");
        scanf("%d", &votos[oyentes][0]);

        //Condicion para terminar
        if(votos[oyentes][0] == -1)
        {
            break;
        }

        while(votos[oyentes][0] < 0 || votos[oyentes][0] > 9)
        {
            printf("Numero no valido, intenta otra vez: ");
            scanf("%d", &votos[oyentes][0]);
        }

        printf("Voto 2: ");
        scanf("%d", &votos[oyentes][1]);

        while(votos[oyentes][1] < 0 || votos[oyentes][1] > 9)
        {
            printf("Numero no valido, intenta otra vez: ");
            scanf("%d", &votos[oyentes][1]);
        }

        printf("Voto 3: ");
        scanf("%d", &votos[oyentes][2]);

        while(votos[oyentes][2] < 0 || votos[oyentes][2] > 9)
        {
            printf("Numero no valido, intenta otra vez: ");
            scanf("%d", &votos[oyentes][2]);
        }

        oyentes++;
    }
}



//Suma de votos
void suma()
{
    int i;

    for(i = 0; i < oyentes; i++)
    {
        sumas[votos[i][0]] = sumas[votos[i][0]] + 3;
        sumas[votos[i][1]] = sumas[votos[i][1]] + 2;
        sumas[votos[i][2]] = sumas[votos[i][2]] + 1;
    }

    printf("\nVotos obtenidos por cada cancion\n");

    for(i = 0; i < 10; i++)
    {
        printf("Cancion %d: %d votos\n", i, sumas[i]);
    }
}



//Buscar canciones mas votadas
void win()
{
    int i;
    int mayor = -1;
    int segundoMayor = -1;

    for(i = 0; i < 10; i++)
    {
        if(sumas[i] > mayor)
        {
            segundoMayor = mayor;
            segundo = primero;

            mayor = sumas[i];
            primero = i;
        }
        else
        {
            if(sumas[i] > segundoMayor && i != primero)
            {
                segundoMayor = sumas[i];
                segundo = i;
            }
        }
    }

    printf("\nPrimera cancion mas votada: %d\n", primero);
    printf("Segunda cancion mas votada: %d\n", segundo);
}



//Puntos de oyentes
void premio()
{
    int i, j;

    int ganador = 0;
    int mayorPuntos = -1;

    printf("\nPuntos de oyentes\n\n");

    for(i = 0; i < oyentes; i++)
    {
        int acertoPrimera = 0;
        int acertoSegunda = 0;

        for(j = 0; j < 3; j++)
        {
            int cancion = votos[i][j];

            if(cancion == primero)
            {
                acertoPrimera = 1;
            }

            if(cancion == segundo)
            {
                acertoSegunda = 1;
            }
        }

        //30 puntos si tiene la cancion numero 1
        if(acertoPrimera == 1)
        {
            puntosOyentes[i] = puntosOyentes[i] + 30;
        }

        //20 puntos si tiene la cancion numero 2
        if(acertoSegunda == 1)
        {
            puntosOyentes[i] = puntosOyentes[i] + 20;
        }

        //10 puntos extra si tiene ambas
        if(acertoPrimera == 1 && acertoSegunda == 1)
        {
            puntosOyentes[i] = puntosOyentes[i] + 10;
        }

        printf("Oyente %d: %d puntos\n", i, puntosOyentes[i]);

        if(puntosOyentes[i] > mayorPuntos)
        {
            mayorPuntos = puntosOyentes[i];
            ganador = i;
        }
    }

    printf("\nFelicidades Ganadooor!: el oyente numero %d\n", ganador);
}
