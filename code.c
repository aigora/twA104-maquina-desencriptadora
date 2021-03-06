// TRABAJO de INFORMÁTICA

//MAQUINA DESENCRIPTADORA

// PABLO CLARAMONTE MASIA

// ROBERTO ANDREA CAPOCASALE GONZALEZ

#include <stdio.h>
#include <windows.h>
#include <stdlib.h>

// DEFINIMOS ESTRUCTURA

typedef struct letras
{
    char letraminus;
    char letramayus;
    int rep;
    float porcentaje;
}letras;

// PROTOTIPOS DE FUNCIONES

void menu(void);
void menu0(void);
void menu00(void);
void menu01(void);
void menu11(void);
void Estadistica(char *cad, letras *pp);
void encrip0(int *q, int *n, char *cad);
void desencrip0(char *cad);
void desencrip01(int q, int n, char *cad);
void desencrip2(int n, char *cad);
void encrip2(int n, char *cad);
void bruto1(char *cad);
void bruto2(char *cad);

// FUNCION PRINCIPAL

int main()
{
    int g = 0;
    system("mode 80,15");
    printf("                              \n\n\n");
    printf("                                CARGANDO");
    printf("\n\n\n\n\n               ");
    char cargando[] = { "||||||||||||||||||||||||||||||||||||||||||" };
    while (cargando[g] != '\0')
    {
        printf("%c", cargando[g]);
        Sleep(50);
        g++;
    }
    printf("                                 ");
    printf("\n\n\n%c", 37);
    for (g = 1; g<101; g++)
    {
        printf("\r");
        printf("                                  %c%d", 37, g);
        Sleep(35);
        printf("\r");
    }
    system("CLS");
    ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
    system("color 1F");
    printf("\tMAQUINA ENCRIPTADORA\n\n");
    menu();
    system("pause");
}

// FUNCIÓN MENÚ - PIDE LAS OPCIONES

void menu(void)
{
    char opc;
    char opc1;
    char b1[3] = "si", b2[3] = "SI", b3[3] = "no", b4[3] = "NO";
    do
    {
        do
        {
            printf("\tA-Encriptar por teclado\n\tB-Desencriptar por teclado\n\tC-Encriptar por fichero\n\tD-Desencriptar por fichero\n\tE-Salir\n");
            scanf_s("%c", &opc);
            if (opc == 'a')
                opc = 'A';
            if (opc == 'b')
                opc = 'B';
            if (opc == 'c')
                opc = 'C';
            if (opc == 'd')
                opc = 'D';
            if (opc == 'e')
                opc = 'E';
            system("cls");
        } while (opc != 'A' && opc != 'B' && opc != 'C' && opc != 'D' && opc != 'E');
        switch (opc)
        {
            case 'A':
                printf("HA ENTRADO EN LA OPCION ENCRIPTADO POR TECLADO\n");
                menu0();
                break;
            case 'B':
                printf("HA ENTRADO EN LA OPCION DESENCRIPTADO POR TECLADO\n");
                menu00();
                break;
            case 'C':
                printf("HA ENTRADO EN LA OPCION ENCRIPTADO POR FICHERO\n");
                menu01();
                break;
            case 'D':
                printf("HA ENTRADO EN LA OPCION DESENCRIPTADO POR FICHERO\n");
                menu11();
                break;
            case 'E':
                return;
        }
        printf("Presione 'E' si no quiere seguir con el programa\n");
        printf("Presione cualquier otra tecla para volver al inicio\n");
        scanf_s("%c", &opc1);
        if (opc1 == 'e')
            opc1 = 'E';
    } while (opc1 != 'E');
}

// FUNCIÓN MENÚ-0 PERMITE DEJAR AL USUARIO ELEGIR ENTRE TEXTO LIBRE O ASIGNACIÓN DINÁMICA DE MEMORIA

void menu0(void)
{
    char cad[5000];
    letras pp[26];
    char opc;
    char a[3], b[3], c[3], d[3], b1[3] = "si", b2[3] = "SI", b3[3] = "no", b4[3] = "NO";
    int i;
    int q, n, z;
    char *cad1;
    do
    {
        printf("A-Espacio libre(5000 caracteres maximo)\nB-Usar asignacion dinamica de memoria\n");
        scanf_s("%c", &opc);
        if (opc == 'a')
            opc = 'A';
        if (opc == 'b')
            opc = 'B';
        system("cls");
    } while (opc != 'A' && opc != 'B');
    switch (opc)
    {
        case 'A':
            printf("HA ENTRADO EN LA OPCION ENCRIPTADO POR TEXTO LIBRE(5000 CARACTERES MAXIMO)\n");
            printf("Introduzca su texto:\n");
            getchar();
            gets_s(cad);
            printf("%cQuiere una estadistica de aparicion de sus letras%c\n", 168, 63);
            gets_s(a);
            if (strcmp(a, b1) == 0 || strcmp(a, b2) == 0)
            {
                Estadistica(cad, pp);
                for (i = 0; i < 26; i++)
                {
                    printf("%c %.2f\n", pp[i].letramayus, pp[i].porcentaje);
                }
                printf("\n");
                puts(cad);
                printf("\n");
            }
            encrip0(&q, &n, cad);
            printf("Este es su codigo encriptado:\n");
            puts(cad);
            printf("\n%cQuiere desencriptar%c\n", 168, 63);
            getchar();
            gets_s(a);
            if (strcmp(a, b1) == 0 || strcmp(a, b2) == 0)
            {
                printf("%cConoce la clave%c\n", 168, 63);
                gets_s(b);
                if (strcmp(b, b1) == 0 || strcmp(b, b2) == 0)
                {
                    desencrip0(cad);
                    printf("\nEste es su codigo desencriptado:\n");
                    puts(cad);
                    printf("\n");
                    break;
                }
                else
                {
                    printf("\nEste es su texto desencriptado:\n");
                    desencrip01(q, n, cad);
                    puts(cad);
                    printf("\n");
                }
                
            }
            if (strcmp(a, b3) == 1 || strcmp(a, b4) == 1)
            {
                printf("\n");
                break;
            }
            break;
        case'B':
            printf("HA ENTRADO EN LA OPCION ENCRIPTADO POR ASIGNACION DINAMICA DE MEMORIA\n");
            printf("Dime el numero de elementos de la frase:\n");
            scanf_s("%d", &z);
            cad1 = (char*)malloc(z);
            printf("Introduzca su texto:\n");
            fflush(stdin);
            getchar();
            fgets(cad1, z + 1, stdin);
            printf("%cQuiere una estadistica de aparicion de sus letras%c\n", 168, 63);
            getchar();
            gets_s(a);
            if (strcmp(a, b1) == 0 || strcmp(a, b2) == 0)
            {
                Estadistica(cad1, pp);
                for (i = 0; i < 26; i++)
                {
                    printf("%c %.2f\n", pp[i].letramayus, pp[i].porcentaje);
                }
                printf("\n");
                puts(cad1);
                printf("\n");
            }
            encrip0(&q, &n, cad1);
            printf("Este es su codigo encriptado:\n");
            puts(cad1);
            printf("\n%cQuiere desencriptar%c\n", 168, 63);
            getchar();
            gets_s(c);
            if (strcmp(c, b1) == 0 || strcmp(c, b2) == 0)
            {
                printf("%cConoce la clave%c\n", 168, 63);
                gets_s(d);
                if (strcmp(d, b1) == 0 || strcmp(d, b2) == 0)
                {
                    desencrip0(cad1);
                    printf("\nEste es su codigo desencriptado:\n");
                    puts(cad1);
                    printf("\n");
                    break;
                }
                else
                {
                    printf("\nEste es su texto desencriptado:\n");
                    desencrip01(q, n, cad1);
                    puts(cad1);
                    printf("\n");
                    break;
                }
                
            }
            if (strcmp(a, b3) == 1 || strcmp(a, b4) == 1)
            {
                printf("\n");
                break;
            }
            system("pause");
            free(cad1);
            break;
    }
}

// FUNCIÓN MENÚ-00 EL USUARIO ELIGE SI DESEA EL TEXO EN MINÚSCULAS O MAYÚSCULAS

void menu00(void)
{
    char opc;
    char cad[5000];
    do
    {
        printf("A-Texto en minusculas\nB-Texto en mayusculas\n");
        scanf_s("%c", &opc);
        if (opc == 'a')
            opc = 'A';
        if (opc == 'b')
            opc = 'B';
        system("cls");
    } while (opc != 'A' && opc != 'B');
    switch (opc)
    {
        case 'A':
        {
            system("cls");
            printf("HA ENTRADO EN LA OPCION TEXTO EN MINUSCULAS\n");
            printf("Introduzca su texto encriptado\n");
            getchar();
            gets_s(cad);
            bruto1(cad);
            break;
        }
        case 'B':
        {
            system("cls");
            printf("HA ENTRADO EN LA OPCION TEXTO EN MAYUSCULAS\n");
            printf("Introduzca su texto encriptado\n");
            getchar();
            gets_s(cad);
            bruto2(cad);
            break;
        }
    }
}

// FUNCIÓN MENÚ-01 REALIZA DESENCRIPTACIÓN POR FICHERO Y OFRECE ESTADÍSTICA DE APARICIÓN DE LETRAS

void menu01(void)
{
    letras pp[26];
    FILE *pf;
    char cad[5000];
    char v[30];
    int q, n, i;
    char e[3], f[3], b1[3] = "si", b2[3] = "SI", b3[3] = "no", b4[3] = "NO";
    char w[3];
    printf("%cQue fichero quiere abrir%c\n", 168, 63);
    printf("NO SE OLVIDE DE LA EXTENSION\n");
    printf("Los ficheros se llaman mensaje.txt e ingles.txt\n");
    getchar();
    gets_s(v);
    errno_t err;
    err = fopen_s(&pf, v, "r");
    fgets(cad, 5000, pf);
    fclose(pf);
    puts(cad);
    printf("\n");
    printf("%cQuiere una estadistica de aparicion de sus letras%c\n", 168, 63);
    gets_s(w);
    if (strcmp(w, b1) == 0 || strcmp(w, b2) == 0)
    {
        Estadistica(cad, pp);
        for (i = 0; i < 26; i++)
        {
            printf("%c %.2f\n", pp[i].letramayus, pp[i].porcentaje);
        }
        printf("\n");
        puts(cad);
        printf("\n");
    }
    encrip0(&q, &n, cad);
    //puts(cad2);
    printf("Este es su codigo encriptado:\n");
    puts(cad);
    printf("\n%cQuiere desencriptar%c\n", 168, 63);
    getchar();
    gets_s(e);
    if (strcmp(e, b1) == 0 || strcmp(e, b2) == 0)
    {
        printf("%cConoce la clave%c\n", 168, 63);
        gets_s(f);
        if (strcmp(f, b1) == 0 || strcmp(f, b2) == 0)
        {
            desencrip0(cad);
            printf("\nEste es su codigo desencriptado:\n");
            puts(cad);
            printf("\n");
        }
        else
        {
            printf("\nEste es su texto desencriptado:\n");
            desencrip01(q, n, cad);
            puts(cad);
            printf("\n");
        }
        
    }
    if (strcmp(e, b3) == 1 || strcmp(e, b4) == 1)
        printf("\n");
}

// FUNCIÓN MENÚ-11 ABRE FICHEROS INTRODUCIDOS POR TECLADO

void menu11(void)
{
    letras pp[26];
    FILE *pf;
    char cad[5000];
    char v[30];
    int q, n, i;
    char e[3], f[3], b1[3] = "si", b2[3] = "SI", b3[3] = "no", b4[3] = "NO";
    char w[3];
    printf("%cQue fichero quiere abrir%c\n", 168, 63);
    printf("NO SE OLVIDE DE LA EXTENSION\n");
    printf("Los ficheros se llaman textoencriptado.txt e sorpresa.txt\n");
    getchar();
    gets_s(v);
    errno_t err;
    err = fopen_s(&pf, v, "r");
    fgets(cad, 5000, pf);
    fclose(pf);
    puts(cad);
    printf("\n");
    system("pause");
    
    Estadistica(cad, pp);
    if (pp[0].letramayus < 'E')
        n = 'E' - pp[0].letramayus;
    if (pp[0].letramayus > 'E')
        n = pp[0].letramayus - 'E';
    desencrip2(n, cad);
    printf("\n");
    puts(cad);
    printf("\n");
}

// FUNCIÓN ESTADISTICA - OFRECE ESTADISTICAS DE APARICIÓN DE LETRAS

void Estadistica(char *cad, letras *pp)
{
    int contador = 0;
    int i, j, k, nminus = 97, nmayus = 65, aux1;
    float aux;
    letras v[26];
    letras v2[26];
    v[0].letraminus = 'a';
    v[0].letramayus = 'A';
    for (i = 1; i < 26; i++)
    {
        nminus++;
        nmayus++;
        v[i].letraminus = nminus;
        v[i].letramayus = nmayus;
    }
    for (i = 0; i < 26; i++)
    {
        v[i].rep = 0;
    }
    i = 0;
    while (cad[i] != '\0')
    {
        if (cad[i] >= 'a' && cad[i] <= 'z')
        {
            for (j = 0; j < 26; j++)
            {
                if (v[j].letraminus == cad[i])
                    v[j].rep++;
            }
            contador++;
        }
        if (cad[i] >= 'A' && cad[i] <= 'Z')
        {
            for (k = 0; k < 26; k++)
            {
                if (v[k].letramayus == cad[i])
                    v[k].rep++;
            }
            contador++;
        }
        i++;
    }
    for (i = 0; i < 26; i++)
    {
        v[i].porcentaje = ((float)v[i].rep / contador) * 100;
    }
    for (i = 0; i < 26; i++)
    {
        v2[i] = v[i];
    }
    for (i = 0; i < 25; i++)
    {
        for (j = i + 1; j < 26; j++)
        {
            if (v2[j].porcentaje > v2[i].porcentaje)
            {
                aux = v2[j].porcentaje;
                v2[j].porcentaje = v2[i].porcentaje;
                v2[i].porcentaje = aux;
                aux1 = v2[j].letramayus;
                v2[j].letramayus = v2[i].letramayus;
                v2[i].letramayus = aux1;
            }
        }
    }
    printf("\n");
    for (i = 0; i < 26; i++)
    {
        pp[i] = v2[i];
    }
}

// FUNCION ENCRIP-0  PIDE AL USUARIO UNA CLAVE PARA POSTERIORMENTE DESENCRIPTARLO

void encrip0(int *q, int *n, char *cad)
{
    int i = 0;
    int m;
    int g = 2, p = 23, ni = 5;
    int G = 1, M = 1, L = 1;
    float modc1, modc2, modc3, B;
    printf("Introduzca la clave:\n");
    scanf_s("%d", &m);
    if (m > 10)
    {
        do
        {
            m = m - 10;
        } while (m > 10);
    }
    for (i = 0; i < m; i++)
        G = g * G;
    modc1 = G % p;
    
    for (i = 0; i < ni; i++)
        M = (modc1)*M;
    modc2 = M % p;
    
    for (i = 0; i < ni; i++)
        L = (g)*L;
    B = L % p;
    
    if (modc2 > 26)
    {
        do
        {
            modc2 = modc2 - 26;
        } while (modc2 > 26);
    }
    i = 0;
    while (cad[i] != '\0')
    {
        if (cad[i] == ' ')
            cad[i] = cad[i];
        if (cad[i] == ',')
            cad[i] = cad[i];
        if (cad[i] == '.')
            cad[i] = cad[i];
        if (cad[i] == '-')
            cad[i] = cad[i];
        if (cad[i] == ':')
            cad[i] = cad[i];
        if (cad[i] == 'ø' || cad[i] == '?')
            cad[i] = cad[i];
        if (cad[i] == '!' || cad[i] == '173')
            cad[i] = cad[i];
        
        if (cad[i] >= 'a' && cad[i] <= 'z')
        {
            if ((cad[i] + modc2) >= 'z')
                if (((cad[i] + modc2) - 'z') == 0)
                    cad[i] = 'z';
                else
                    cad[i] = (((cad[i] + modc2) - 'z') + '`');
                else
                    cad[i] = cad[i] + modc2;
        }
        if (cad[i] >= 'A' && cad[i] <= 'Z')
        {
            if ((cad[i] + modc2) >= 'Z')
                if (((cad[i] + modc2) - 'Z') == 0)
                    cad[i] = 'Z';
                else
                    cad[i] = (((cad[i] + modc2) - 'Z') + '@');
                else
                    cad[i] = cad[i] + modc2;
        }
        if (cad[i] >= '0' && cad[i] <= '9')
        {
            modc3 = modc2;
            if (modc3 > 10)
            {
                do
                {
                    modc3 = modc3 - 10;
                } while (modc3 > 10);
            }
            {
                if ((cad[i] + modc3) >= '9')
                    if (((cad[i] + modc3) - '9') == 0)
                        cad[i] = '9';
                    else
                        cad[i] = (((cad[i] + modc3) - 57) + 47);
                    else
                        cad[i] = cad[i] + modc3;
            }
        }
        i++;
    }
    *q = B;
    *n = m;
}

// FUNCIÓN DESENCRIP-0 PARA DESENCRIPTAR A PARTIR DE LA CLAVE

void desencrip0(char *cad)
{
    int g = 2, p = 23, ni = 5;
    int G = 1, M = 1;
    float modc1, modc2, modc3;
    int i = 0, n;
    
    printf("%cCual es su clave%c\n", 168, 63);
    scanf_s(" %d", &n);
    if (n > 10)
    {
        do
        {
            n = n - 10;
        } while (n > 10);
    }
    for (i = 0; i < n; i++)
        G = g * G;
    modc1 = G % p;
    
    for (i = 0; i < ni; i++)
        M = (modc1)*M;
    modc2 = M % p;
    
    if (modc2 > 26)
    {
        do
        {
            modc2 = modc2 - 26;
        } while (n > 26);
    }
    i = 0;
    while (cad[i] != '\0')
    {
        if (cad[i] == ' ')
            cad[i] = cad[i];
        if (cad[i] == ',')
            cad[i] = cad[i];
        if (cad[i] == '.')
            cad[i] = cad[i];
        if (cad[i] == '-')
            cad[i] = cad[i];
        if (cad[i] == ':')
            cad[i] = cad[i];
        if (cad[i] == 'ø' || cad[i] == '?')
            cad[i] = cad[i];
        if (cad[i] == '!' || cad[i] == '173')
            cad[i] = cad[i];
        
        if (cad[i] >= ('a') && cad[i] <= ('z'))
        {
            if ((cad[i] - modc2) <= ('a'))
                if (((cad[i] - modc2) - 'a') == 0)
                    cad[i] = 'a';
                else
                    cad[i] = (((cad[i]) - modc2) + 26);
                else
                    cad[i] = cad[i] - modc2;
        }
        if (cad[i] >= ('A') && cad[i] <= ('Z'))
        {
            if ((cad[i] - modc2) <= ('A'))
                if (((cad[i] - modc2) - 'A') == 0)
                    cad[i] = 'A';
                else
                    cad[i] = (((cad[i]) - modc2) + 26);
                else
                    cad[i] = cad[i] - modc2;
        }
        if (cad[i] >= '0' && cad[i] <= '9')
        {
            modc3 = modc2;
            if (modc3 > 10)
            {
                do
                {
                    modc3 = modc3 - 10;
                } while (modc3 > 10);
            }
            {
                if ((cad[i] - modc3) <= '0')
                    if (((cad[i] - modc3) - '0') == 0)
                        cad[i] = '0';
                    else
                        cad[i] = (((cad[i]) - modc3) + 10);
                    else
                        cad[i] = cad[i] - modc3;
            }
        }
        i++;
    }
}

// FUNCIÓN DESENCRIP 01

void desencrip01(int q, int n, char *cad)
{
    int g = 2, p = 23;
    int H = 1, F = 1;
    float modd1, modd2, modd3;
    int i = 0;
    
    for (i = 0; i < n; i++)
        H = (q)*H;
    modd2 = H % p;
    if (n > 10)
    {
        do
        {
            n = n - 10;
        } while (n > 10);
    }
    if (modd2 > 26)
    {
        do
        {
            modd2 = modd2 - 26;
        } while (modd2 > 26);
    }
    i = 0;
    while (cad[i] != '\0')
    {
        if (cad[i] == ' ')
            cad[i] = cad[i];
        if (cad[i] == ',')
            cad[i] = cad[i];
        if (cad[i] == '.')
            cad[i] = cad[i];
        if (cad[i] == '-')
            cad[i] = cad[i];
        if (cad[i] == ':')
            cad[i] = cad[i];
        if (cad[i] == 'ø' || cad[i] == '?')
            cad[i] = cad[i];
        if (cad[i] == '!' || cad[i] == '173')
            cad[i] = cad[i];
        
        if (cad[i] >= ('a') && cad[i] <= ('z'))
        {
            if ((cad[i] - modd2) <= ('a'))
                if (((cad[i] - modd2) - 'a') == 0)
                    cad[i] = 'a';
                else
                    cad[i] = (((cad[i]) - modd2) + 26);
                else
                    cad[i] = cad[i] - modd2;
        }
        if (cad[i] >= ('A') && cad[i] <= ('Z'))
        {
            if ((cad[i] - modd2) <= ('A'))
                if (((cad[i] - modd2) - 'A') == 0)
                    cad[i] = 'A';
                else
                    cad[i] = (((cad[i]) - modd2) + 26);
                else
                    cad[i] = cad[i] - modd2;
        }
        if (cad[i] >= '0' && cad[i] <= '9')
        {
            modd3 = modd2;
            if (modd3 > 10)
            {
                do
                {
                    modd3 = modd3 - 10;
                } while (modd3 > 10);
            }
            {
                if ((cad[i] - modd3) <= '0')
                    if (((cad[i] - modd3) - '0') == 0)
                        cad[i] = '0';
                    else
                        cad[i] = (((cad[i]) - modd3) + 10);
                    else
                        cad[i] = cad[i] - modd3;
            }
        }
        i++;
    }
}

// FUNCIÓN DESENCRIP 2

void desencrip2(int n, char *cad)
{
    int i = 0;
    while (cad[i] != '\0')
    {
        if (cad[i] == ' ')
            cad[i] = cad[i];
        if (cad[i] == ',')
            cad[i] = cad[i];
        if (cad[i] == '.')
            cad[i] = cad[i];
        if (cad[i] == '-')
            cad[i] = cad[i];
        if (cad[i] == ':')
            cad[i] = cad[i];
        if (cad[i] == 'ø' || cad[i] == '?')
            cad[i] = cad[i];
        if (cad[i] == '!' || cad[i] == '173')
            cad[i] = cad[i];
        
        if (cad[i] >= ('a') && cad[i] <= ('z'))
        {
            if ((cad[i] - n) <= ('a'))
                if (((cad[i] - n) - 'a') == 0)
                    cad[i] = 'a';
                else
                    cad[i] = (((cad[i]) - n) + 26);
                else
                    cad[i] = cad[i] - n;
        }
        if (cad[i] >= ('A') && cad[i] <= ('Z'))
        {
            if ((cad[i] - n) <= ('A'))
                if (((cad[i] - n) - 'A') == 0)
                    cad[i] = 'A';
                else
                    cad[i] = (((cad[i]) - n) + 26);
                else
                    cad[i] = cad[i] - n;
        }
        if (cad[i] >= '0' && cad[i] <= '9')
        {
            if ((cad[i] - n) <= '0')
                if (((cad[i] - n) - '0') == 0)
                    cad[i] = '0';
                else
                    cad[i] = (((cad[i]) - n) + 10);
                else
                    cad[i] = cad[i] - n;
        }
        i++;
    };
}

// FUNCIÓN ENCRIP 2

void encrip2(int n, char *cad)
{
    int i = 0;
    while (cad[i] != '\0')
    {
        if (cad[i] == ' ')
            cad[i] = cad[i];
        if (cad[i] == ',')
            cad[i] = cad[i];
        if (cad[i] == '.')
            cad[i] = cad[i];
        if (cad[i] == '-')
            cad[i] = cad[i];
        if (cad[i] == ':')
            cad[i] = cad[i];
        if (cad[i] == 'ø' || cad[i] == '?')
            cad[i] = cad[i];
        if (cad[i] == '!' || cad[i] == '173')
            cad[i] = cad[i];
        if (cad[i] >= 'a' && cad[i] <= 'z')
        {
            if ((cad[i] + n) >= 'z')
                if (((cad[i] + n) - 'z') == 0)
                    cad[i] = 'z';
                else
                    cad[i] = (((cad[i] + n) - 'z') + '`');
                else
                    cad[i] = cad[i] + n;
        }
        if (cad[i] >= 'A' && cad[i] <= 'Z')
        {
            if ((cad[i] + n) >= 'Z')
                if (((cad[i] + n) - 'Z') == 0)
                    cad[i] = 'Z';
                else
                    cad[i] = (((cad[i] + n) - 'Z') + '@');
                else
                    cad[i] = cad[i] + n;
        }
        if (cad[i] >= '0' && cad[i] <= '9')
        {
            if ((cad[i] + n) >= '9')
                if (((cad[i] + n) - '9') == 0)
                    cad[i] = '9';
                else
                    cad[i] = (((cad[i] + n) - 57) + 47);
                else
                    cad[i] = cad[i] + n;
        }
        i++;
    }
}

// FUNCIÓN BRUTO1 DEVUELVE INTENTOS DE DESENCRIPTADO HASTA QUE EL USUARIO ENCUENTRA SU TEXTO

void bruto1(char *cad)
{
    int i = 0, n;
    char x[3], b1[3] = "si", b2[3] = "SI", b3[3] = "no", b4[3] = "NO";
    printf("\n");
    while (cad[i] != '\0')
    {
        if (cad[i] == cad[i + 1])
        {
            if (cad[i] < 'l')
                n = 26 - ('l' - cad[i]);
            if (cad[i] > 'l')
                n = cad[i] - 'l';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
            {
                encrip2(n, cad);
                if (cad[i] < 'r')
                    n = 26 - ('r' - cad[i]);
                if (cad[i] > 'r')
                    n = cad[i] - 'r';
                desencrip2(n, cad);
                puts(cad);
                printf("%cEs este su texto desencriptado%c", 168, 63);
                gets_s(x);
                if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
                {
                    break;
                }
            }
        }
        if ((26 - (cad[i] - cad[i + 1])) == ('p' - 'm'))
        {
            n = ('z' - cad[i]) + (cad[i + 1] - '`');
            n = n + ('m' - cad[i + 1]);
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if ((cad[i + 1] - cad[i] == 'p' - 'm'))
        {
            if (cad[i] >= 'a' && cad[i] <= 'm')
            {
                n = cad[i] - 'm';
                n = 26 + n;
            }
            if (cad[i] >= 'm' && cad[i] <= 'z')
                n = cad[i] - 'm';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if (cad[i] - cad[i + 1] == 'm' - 'b')
        {
            if (cad[i] >= 'a' && cad[i] <= 'm')
            {
                n = cad[i] - 'm';
                n = 26 + n;
            }
            if (cad[i] >= 'm' && cad[i] <= 'z')
                n = cad[i] - 'm';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if ((26 - (cad[i] - cad[i + 1])) == ('r' - 'b'))
        {
            n = ('z' - cad[i]) + (cad[i + 1] - '`');
            n = n + ('b' - cad[i + 1]);
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if (cad[i + 1] - cad[i] == 'r' - 'b')
        {
            if (cad[i] >= 'a' && cad[i] <= 'b')
            {
                n = cad[i] - 'b';
                n = 26 + n;
            }
            if (cad[i] >= 'b' && cad[i] <= 'z')
                n = cad[i] - 'b';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if ((26 - (cad[i] - cad[i + 1])) == ('l' - 'b'))
        {
            n = ('z' - cad[i]) + (cad[i + 1] - '`');
            n = n + ('b' - cad[i + 1]);
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if (cad[i + 1] - cad[i] == 'l' - 'b')
        {
            if (cad[i] >= 'a' && cad[i] <= 'b')
            {
                n = cad[i] - 'b';
                n = 26 + n;
            }
            if (cad[i] >= 'b' && cad[i] <= 'z')
                n = cad[i] - 'b';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if ((26 - (cad[i] - cad[i + 1])) == ('o' - 'h'))
        {
            n = ('z' - cad[i]) + (cad[i + 1] - '`');
            n = n + ('h' - cad[i + 1]);
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if ((cad[i + 1] - cad[i] == 'o' - 'h'))
        {
            if (cad[i] >= 'a' && cad[i] <= 'h')
            {
                n = cad[i] - 'h';
                n = 26 + n;
            }
            if (cad[i] >= 'h' && cad[i] <= 'z')
                n = cad[i] - 'h';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if (cad[i] - cad[i + 1] == 'h' - 'a')
        {
            if (cad[i] >= 'a' && cad[i] <= 'h')
            {
                n = cad[i] - 'h';
                n = 26 + n;
            }
            if (cad[i] >= 'h' && cad[i] <= 'z')
                n = cad[i] - 'h';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if (cad[i] - cad[i + 1] == 'h' - 'e')
        {
            if (cad[i] >= 'a' && cad[i] <= 'h')
            {
                n = cad[i] - 'h';
                n = 26 + n;
            }
            if (cad[i] >= 'h' && cad[i] <= 'z')
                n = cad[i] - 'h';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        i++;
    }
}

// VOID BRUTO2 SIMILAR A BRUTO1

void bruto2(char *cad)
{
    int i = 0, n;
    char x[3], b1[3] = "si", b2[3] = "SI", b3[3] = "no", b4[3] = "NO";
    printf("\n");
    while (cad[i] != '\0')
    {
        if ((26 - (cad[i] - cad[i + 1])) == ('P' - 'M'))
        {
            n = ('Z' - cad[i]) + (cad[i + 1] - '@');
            n = n + ('M' - cad[i + 1]);
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if ((cad[i + 1] - cad[i] == 'P' - 'M'))
        {
            if (cad[i] >= 'A' && cad[i] <= 'M')
            {
                n = cad[i] - 'M';
                n = 26 + n;
            }
            if (cad[i] >= 'M' && cad[i] <= 'Z')
                n = cad[i] - 'M';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        
        if (cad[i] - cad[i + 1] == 'M' - 'B')
        {
            if (cad[i] >= 'A' && cad[i] <= 'M')
            {
                n = cad[i] - 'M';
                n = 26 + n;
            }
            if (cad[i] >= 'M' && cad[i] <= 'Z')
                n = cad[i] - 'M';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        
        if ((26 - (cad[i] - cad[i + 1])) == ('R' - 'B'))
        {
            n = ('Z' - cad[i]) + (cad[i + 1] - '@');
            n = n + ('B' - cad[i + 1]);
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if (cad[i + 1] - cad[i] == 'R' - 'B')
        {
            if (cad[i] >= 'A' && cad[i] <= 'B')
            {
                n = cad[i] - 'B';
                n = 26 + n;
            }
            if (cad[i] >= 'B' && cad[i] <= 'Z')
                n = cad[i] - 'B';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        
        if ((26 - (cad[i] - cad[i + 1])) == ('L' - 'B'))
        {
            n = ('Z' - cad[i]) + (cad[i + 1] - '@');
            n = n + ('B' - cad[i + 1]);
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if (cad[i + 1] - cad[i] == 'L' - 'B')
        {
            if (cad[i] >= 'A' && cad[i] <= 'B')
            {
                n = cad[i] - 'B';
                n = 26 + n;
            }
            if (cad[i] >= 'B' && cad[i] <= 'Z')
                n = cad[i] - 'B';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        
        if ((26 - (cad[i] - cad[i + 1])) == ('O' - 'H'))
        {
            n = ('Z' - cad[i]) + (cad[i + 1] - '@');
            n = n + ('H' - cad[i + 1]);
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if ((cad[i + 1] - cad[i] == 'O' - 'H'))
        {
            if (cad[i] >= 'A' && cad[i] <= 'H')
            {
                n = cad[i] - 'H';
                n = 26 + n;
            }
            if (cad[i] >= 'H' && cad[i] <= 'Z')
                n = cad[i] - 'H';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if (cad[i] - cad[i + 1] == 'H' - 'A')
        {
            if (cad[i] >= 'A' && cad[i] <= 'H')
            {
                n = cad[i] - 'H';
                n = 26 + n;
            }
            if (cad[i] >= 'H' && cad[i] <= 'Z')
                n = cad[i] - 'H';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        if (cad[i] - cad[i + 1] == 'H' - 'E')
        {
            if (cad[i] >= 'A' && cad[i] <= 'H')
            {
                n = cad[i] - 'H';
                n = 26 + n;
            }
            if (cad[i] >= 'H' && cad[i] <= 'Z')
                n = cad[i] - 'H';
            desencrip2(n, cad);
            puts(cad);
            printf("%cEs este su texto desencriptado%c", 168, 63);
            gets_s(x);
            if (strcmp(x, b1) == 0 || strcmp(x, b2) == 0)
            {
                break;
            }
            if (strcmp(x, b3) == 1 || strcmp(x, b4) == 1)
                encrip2(n, cad);
            printf("\n");
        }
        
        i++;
    }
}
