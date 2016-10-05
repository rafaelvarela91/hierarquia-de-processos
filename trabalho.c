#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

pid_t pai, filho1, filho2, filho3, neto1, neto2;

void logica_pai() {
    static int cont = 0;

    if (cont == 18) {
        printf("Pai tem primeiro filho: "); fflush(stdout);
        filho1 = fork();

        if (filho1 == 0) {
            filho1 = getpid();
        } else {
            printf("%i\n", filho1);
        }
    }

    if (cont == 20) {
        printf("Pai tem segundo filho: "); fflush(stdout);
        filho2 = fork();

        if (filho2 == 0) {
            filho2 = getpid();
        } else {
            printf("%i\n", filho2);
        }
    }

    if (cont == 21) {
        printf("Pai tem terceiro filho: "); fflush(stdout);
        filho3 = fork();

        if (filho3 == 0) {
            filho3 = getpid();
        } else {
            printf("%i\n", filho3);
        }
    }

    if (cont == 33) {
        printf("Pai morre\n");
        exit(0);
    }

    ++cont;
}

void logica_filho1() {
    static int cont = 0;

    if (cont == 5) {
        printf("Filho 1 morre\n");
        exit(0);
    }
    ++cont;
}

void logica_filho2() {
    static int cont = 0;

  if (cont == 15) {
        printf("Neto 1 nasce: "); fflush(stdout);
        neto1 = fork();
        if (neto1 == 0) {
            neto1 = getpid();
        } else {
            printf("%i\n", neto1);
        }
    }

    if (cont == 20) {
        printf("Filho 2 morre\n");
        exit(0);
    }
    ++cont;
}

void logica_filho3() {
    static int cont = 0;

   if (cont == 3) {
        printf("Neto 2 nasce: "); fflush(stdout);
        neto2 = fork();
        if (neto2 == 0) {
            neto2 = getpid();
        } else {
            printf("%i\n", neto2);
        }
    }

    if (cont == 5) {
        printf("Filho 3 morre\n");
        exit(0);
    }
    ++cont;
}

void logica_neto1() {
    static int cont = 0;

    if (cont == 5) {
        printf("Neto 1 morreu\n");
        exit(0);
    }

    ++cont;
}

void logica_neto2() {
    static int cont = 0;

    if (cont == 10) {
        printf("Neto 2 morreu\n");
        exit(0);
    }

    ++cont;
}


int main() {
    pai = getpid();

    for (int i = 0; i < 100; ++i) {
        if (getpid() == pai) logica_pai();
        if (getpid() == filho1) logica_filho1();
        if (getpid() == filho2) logica_filho2();
	if (getpid() == filho3) logica_filho3();
        if (getpid() == neto1) logica_neto1();
        if (getpid() == neto2) logica_neto2();
        
        sleep(1);
    }
  
}
