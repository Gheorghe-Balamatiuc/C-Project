#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define max(a, b) ((a) > (b) ? a : b)
#define min(a, b) ((a) < (b) ? a : b)

int nsali, nprogramari;

struct sali {
    int capacitate;
    char nume[100];
} s[100];

struct programari {
    char nume[100], ziua[100];
    int ora_in, ora_tr, data, luna, an;
} p[100];

//doar adminul poate adauga sau sterge salile
int main() {
    //citire
    FILE* file = fopen("sali.txt", "r");
    char nume[100];
    int capacitate;
    while (fscanf(file, "%s %d", nume, &capacitate) != EOF) {
        strcpy(s[nsali].nume, nume), s[nsali++].capacitate = capacitate;
    }
    fclose(file);
    //for (int i = 0; i < nsali; i++)
    //    printf("%s %d\n", s[i].nume, s[i].capacitate);

    file = fopen("programari.txt", "r");
    char linie[100];
    while (fgets(linie, 100, file)) {
        char ziua[100];
        int ora_in, ora_tr, data, luna, an;
        sscanf(linie, "%s %d-%d %s %d.%d.%d", &nume, &ora_in, &ora_tr, &ziua, &data, &luna, &an);
        strcpy(p[nprogramari].nume, nume);
        p[nprogramari].ora_in = ora_in;
        p[nprogramari].ora_tr = ora_tr;
        strcpy(p[nprogramari].ziua, ziua);
        p[nprogramari].data = data;
        p[nprogramari].luna = luna;
        p[nprogramari].an = an;
        nprogramari++;
        //printf("%s %d-%d %s %d.%d.%d\n", p[nprogramari - 1].nume, p[nprogramari - 1].ora_in, p[nprogramari - 1].ora_tr, 
        //    p[nprogramari - 1].ziua, p[nprogramari - 1].data, p[nprogramari - 1].luna, p[nprogramari - 1].an);
    }
    fclose(file);

    char utilizator[100];
    printf("Logare(user - utilizator obisnuit, admin - administrator): ");
    scanf("%s", &utilizator);
    while (strcmp(utilizator, "admin") != 0 && strcmp(utilizator, "user") != 0)
        printf("Date invalide!\nLogare(user - utilizator obisnuit, admin - administrator): "), scanf("%s", &utilizator);
    system("cls");

    while (true) {
        printf("1 - vizualizati sali disponibile\n");
        printf("2 - rezervati o sala\n");
        printf("3 - anulati rezervarea\n");
        printf("4 - afisarea tuturor salilor si rezervarilor\n");
        printf("5 - cautare dupa nume, capacitate sau disponibilitate\n");
        if (strcmp(utilizator, "admin") == 0) {
            printf("6 - adaugarea salii dupa capacitate si nume\n");
            printf("7 - stergerea salii dupa nume\n");
        }
        printf("0 - iesire\n\n");
        int command;
        if (strcmp(utilizator, "admin") == 0) {
            printf("Optiune: ");
            scanf("%d", &command);
            while (command < 0 || command > 7)
                printf("Date invalide\nOptiune: "), scanf("%d", &command);
        }
        else {
            printf("Optiune: ");
            scanf("%d", &command);
            while (command < 0 || command > 5)
                printf("Date invalide\nOptiune: "), scanf("%d", &command);
        }

        if (command == 1) {

            FILE* file = fopen("sali.txt", "r");
            char c = fgetc(file);
            while (c != EOF) { //end of file
                printf("%c", c);
                c = fgetc(file);
            }
            fclose(file);

            char num[100];
            printf("Tastati 0 pentru a reveni la meniul principal: ");
            scanf("%s", &num);
            while (!(num[0] == '0' && num[1] == '\0'))
                printf("Date invalide!\nTastati 0 pentru a reveni la meniul principal: "), scanf("%s", &num);
            system("cls");
        }

        if (command == 2) {
            printf("0 - inapoi\n");
            printf("1 - introducere date\n");
            int command;
            printf("Optiune: ");
            scanf("%d", &command);
            while (command != 0 && command != 1)
                printf("Date invalide\nOptiune: "), scanf("%d", &command);
            if (command == 0) {
                system("cls");
                continue;
            }
            char nume[100];
            printf("Nume: ");
            scanf("%s", &nume);
            int ora_in, ora_tr, data, luna, an;
            char ziua[100];
            printf("Ora de incepere: ");
            scanf("%d", &ora_in);
            while (!(0 <= ora_in && ora_in <= 24))
                printf("Date invalide!\nOra de incepere: "), scanf("%d", &ora_in);
            printf("Ora de terminare: ");
            scanf("%d", &ora_tr);
            while (!(0 <= ora_tr && ora_tr <= 24) || ora_in >= ora_tr)
                printf("Date invalide!\nOra de terminare: "), scanf("%d", &ora_tr);
            printf("Ziua(luni - duminica, Luni - Duminica): ");
            scanf("%s", &ziua);
            while (strcmp(ziua, "luni") != 0 && strcmp(ziua, "Luni") != 0 && strcmp(ziua, "marti") != 0 && strcmp(ziua, "Marti") != 0
                && strcmp(ziua, "miercuri") != 0 && strcmp(ziua, "Miercuri") != 0 && strcmp(ziua, "joi") != 0
                && strcmp(ziua, "Joi") != 0 && strcmp(ziua, "vineri") != 0 && strcmp(ziua, "Vineri") != 0
                && strcmp(ziua, "sambata") != 0 && strcmp(ziua, "Sambata") != 0 && strcmp(ziua, "duminica") != 0
                && strcmp(ziua, "Duminica") != 0)
                printf("Date invalide!\nZiua(luni - duminica, Luni - Duminica): "), scanf("%s", &ziua);
            printf("Data(1 - 31): ");
            scanf("%d", &data);
            while (!(1 <= data && data <= 31))
                printf("Date invalide!\nData: "), scanf("%d", &data);
            printf("Luna(1 - 12): ");
            scanf("%d", &luna);
            while (!(1 <= luna && luna <= 12))
                printf("Date invalide!\nLuna(1 - 12): "), scanf("%d", &luna);
            printf("Anul(2023 - inf): ");
            scanf("%d", &an);
            while (an < 2023)
                printf("Date invalide!\nLuna(2023 - inf): "), scanf("%d", &an);

            FILE* file = fopen("programari.txt", "a");
            fprintf(file, "%s %d-%d %s %d.%d.%d\n", nume, ora_in, ora_tr, ziua, data, luna, an);
            fclose(file);

            strcpy(p[nprogramari].nume, nume);
            p[nprogramari].ora_in = ora_in;
            p[nprogramari].ora_tr = ora_tr;
            strcpy(p[nprogramari].ziua, ziua);
            p[nprogramari].data = data;
            p[nprogramari].luna = luna;
            p[nprogramari].an = an;
            nprogramari++;

            system("cls");
        }

        if (command == 3) {
            printf("0 - inapoi\n");
            printf("1 - introducere date\n");
            int command;
            printf("Optiune: ");
            scanf("%d", &command);
            while (command != 0 && command != 1)
                printf("Date invalide\nOptiune: "), scanf("%d", &command);
            if (command == 0) {
                system("cls");
                continue;
            }
            char nume[100];
            printf("Nume: ");
            scanf("%s", nume);

            FILE* file = fopen("temp.txt", "a"), * temp = fopen("programari.txt", "r");
            char linie[100];
            while (fgets(linie, 100, temp))
                if (linie[0] != '\n') {
                    linie[strcspn(linie, "\n")] = '\0';
                    char nume_ck[100], ziua[100];
                    int ora_in, ora_tr, data, luna, an;
                    sscanf(linie, "%s %d-%d %s %d.%d.%d", &nume_ck, &ora_in, &ora_tr, &ziua, &data, &luna, &an);
                    if (strcmp(nume_ck, nume) != 0) {
                        fprintf(file, "%s\n", linie);
                    }
                }
            fclose(file);
            fclose(temp);
            remove("programari.txt");
            rename("temp.txt", "programari.txt");

            for (int i = 0; i < nprogramari; i++)
                if (strcmp(p[i].nume, nume) == 0) {
                    for (int j = i + 1; j < nprogramari; j++)
                        p[j - 1] = p[j];
                    nprogramari--;
                    i--;
                }
            //for(int i = 0; i < nprogramari; i ++)
            //    printf("%s %d-%d %s %d.%d.%d\n", p[i].nume, p[i].ora_in, p[i].ora_tr,
            //        p[i].ziua, p[i].data, p[i].luna, p[i].an);

            system("cls");
        }

        if (command == 4) {

            FILE* file = fopen("programari.txt", "r");
            char c = fgetc(file);
            while (c != EOF) { //end of file
                printf("%c", c);
                c = fgetc(file);
            }
            fclose(file);

            char num[100];
            printf("Tastati 0 pentru a reveni la meniul principal: ");
            scanf("%s", &num);
            while (!(num[0] == '0' && num[1] == '\0'))
                printf("Date invalide!\nTastati 0 pentru a reveni la meniul principal: "), scanf("%s", &num);
            system("cls");
        }

        if (command == 5) {
            printf("0 - inapoi\n");
            printf("1 - introducere date\n");
            int command;
            printf("Optiune: ");
            scanf("%d", &command);
            while (command != 0 && command != 1)
                printf("Date invalide\nOptiune: "), scanf("%d", &command);
            if (command == 0) {
                system("cls");
                continue;
            }
            int alegere;
            printf("Alegere(1 - nume, 2 - capacitate, 3 - disponibilitate): ");
            scanf("%d", &alegere);
            while (alegere != 1 && alegere != 2 && alegere != 3)
                printf("Date invalide!\nAlegere(1 - nume, 2 - capacitate, 3 - disponibilitate): "), scanf("%d", &alegere);
            if (alegere == 1) {
                char nume[100];
                printf("Nume: ");
                scanf("%s", nume);

                FILE* file = fopen("programari.txt", "r");
                char linie[100];
                bool ok = 0;
                while (fgets(linie, 100, file))
                    if (linie[0] != '\n') {
                        linie[strcspn(linie, "\n")] = '\0';
                        char nume_ck[100], ziua[100];
                        int ora_in, ora_tr, data, luna, an;
                        sscanf(linie, "%s %d-%d %s %d.%d.%d", &nume_ck, &ora_in, &ora_tr, &ziua, &data, &luna, &an);
                        if (strcmp(nume_ck, nume) == 0) {
                            printf("%s\n", linie), ok = 1;
                        }
                    }
                if (!ok)
                    printf("Nu a fost gasita nici o sala cu numele respectiv.\n");
                fclose(file);
            }
            if (alegere == 2) {
                int capacitate;
                printf("Capacitate: ");
                scanf("%d", &capacitate);
                while (capacitate <= 0)
                    printf("Date invalide\nCapacitate: "), scanf("%d", &capacitate);

                FILE* file = fopen("sali.txt", "r");
                char linie[100];
                bool ok = 0;
                while (fgets(linie, 100, file))
                    if (linie[0] != '\n') {
                        linie[strcspn(linie, "\n")] = '\0';
                        char nume_ck[100];
                        int capacitate_ck;
                        sscanf(linie, "%s %d", &nume_ck, &capacitate_ck);
                        if (capacitate_ck == capacitate)
                            printf("%s\n", linie), ok = 1;
                    }
                if (!ok)
                    printf("Nu a fost gasita nici o sala cu capacitatea respectiva.\n");
                fclose(file);
            }
            if (alegere == 3) {
                int disponibilitate;
                printf("Disponibilitate(1 - disponibile, 0 - indisponibile): ");
                scanf("%d", &disponibilitate);
                while (disponibilitate != 0 && disponibilitate != 1)
                    printf("Date invalide\nDisponibilitate(1 - disponibile, 0 - indisponibile): "), scanf("%d", &disponibilitate);

                FILE* file = fopen("sali.txt", "r");
                char linie[100];
                bool gasit = 0;
                while (fgets(linie, 100, file))
                    if (linie[0] != '\n') {
                        linie[strcspn(linie, "\n")] = '\0';
                        char nume_ck[100];
                        int capacitate_ck;
                        sscanf(linie, "%s %d", &nume_ck, &capacitate_ck);

                        bool ok1 = 1, ok0 = 0;
                        FILE* file1 = fopen("programari.txt", "r");
                        char linie1[100];
                        while (fgets(linie1, 100, file1))
                            if (linie1[0] != '\n') {
                                linie1[strcspn(linie1, "\n")] = '\0';
                                char nume_ck1[100], ziua1[100];
                                int ora_in1, ora_tr1, data1, luna1, an1;
                                sscanf(linie1, "%s %d-%d %s %d.%d.%d", &nume_ck1, &ora_in1, &ora_tr1, &ziua1, &data1, &luna1, &an1);
                                if (strcmp(nume_ck, nume_ck1) == 0 && disponibilitate == 0) {
                                    ok0 = 1;
                                }
                                if (strcmp(nume_ck, nume_ck1) == 0 && disponibilitate == 1) {
                                    ok1 = 0;
                                }
                            }
                        if (ok1 == 1 && disponibilitate == 1) {
                            printf("%s\n", linie), gasit = 1;
                        }
                        if (ok0 == 1 && disponibilitate == 0)
                            printf("%s\n", linie), gasit = 1;
                        fclose(file1);
                    }
                if (!gasit)
                    printf("Nu a fost gasita nici o sala cu disponibilitatea respectiva.\n");
                fclose(file);
            }

            char num[100];
            printf("Tastati 0 pentru a reveni la meniul principal: ");
            scanf("%s", &num);
            while (!(num[0] == '0' && num[1] == '\0'))
                printf("Date invalide!\nTastati 0 pentru a reveni la meniul principal: "), scanf("%s", &num);
            system("cls");
        }

        if (command == 6) {
            printf("0 - inapoi\n");
            printf("1 - introducere date\n");
            int command;
            printf("Optiune: ");
            scanf("%d", &command);
            while (command != 0 && command != 1)
                printf("Date invalide\nOptiune: "), scanf("%d", &command);
            if (command == 0) {
                system("cls");
                continue;
            }
            char nume[100];
            int capacitate;
            printf("Capacitate: ");
            scanf("%d", &capacitate);
            while (capacitate <= 0)
                printf("Date invalide\nCapacitate: "), scanf("%d", &capacitate);
            printf("Nume: ");
            scanf("%s", nume);

            FILE* file = fopen("sali.txt", "a");
            fprintf(file, "%s %d\n", nume, capacitate);
            fclose(file);

            strcpy(s[nsali].nume, nume), s[nsali++].capacitate = capacitate;
            //printf("%s %d\n", s[nsali - 1].nume, s[nsali - 1].capacitate);

            system("cls");
        }

        if (command == 7) {
            printf("0 - inapoi\n");
            printf("1 - introducere date\n");
            int command;
            printf("Optiune: ");
            scanf("%d", &command);
            while (command != 0 && command != 1)
                printf("Date invalide\nOptiune: "), scanf("%d", &command);
            if (command == 0) {
                system("cls");
                continue;
            }
            char nume[100];
            printf("Nume: ");
            scanf("%s", nume);

            FILE* file = fopen("temp.txt", "a"), * temp = fopen("sali.txt", "r");
            char linie[100];
            while (fgets(linie, 100, temp))
                if (linie[0] != '\n') {
                    linie[strcspn(linie, "\n")] = '\0';
                    char nume_ck[100];
                    int capacitate;
                    sscanf(linie, "%s %d", &nume_ck, &capacitate);
                    if (strcmp(nume_ck, nume) != 0)
                        fprintf(file, "%s\n", linie);
                }
            fclose(file);
            fclose(temp);
            remove("sali.txt");
            rename("temp.txt", "sali.txt");

            int ix;
            for (int i = 0; i < nsali; i++)
                if (strcmp(s[i].nume, nume) == 0)
                    ix = i;
            for (int i = ix + 1; i < nsali; i++)
                s[i - 1] = s[i];
            nsali--;

            //for (int i = 0; i < nsali; i++)
            //    printf("%s %d\n", s[i].nume, s[i].capacitate);

            system("cls");
        }

        if (command == 0) {
            break;
        }
    }
}