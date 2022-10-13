#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void hola(int signalNum){
    printf("Recibi la senial %d", signalNum);
}

int cond;
void terminarWhile(int signalN){
    printf("Finishing while");
    cond = 0;
}

int main(){
    signal(12,terminarWhile);
    
    //signal(2, hola);
    cond = 1;
    while(cond==1){
        printf("Working \n");
        sleep(1);
    }
    printf("Never reaches this point");
    return 0;
}

//gcc -o signal signal.cpp
//ps -fea
//kill (senial) (numero de proceso de -fea)

//kill -9 (numproceso) El numero 9 es para matar el proceso
//tarrea romper ciclo con la senial 12