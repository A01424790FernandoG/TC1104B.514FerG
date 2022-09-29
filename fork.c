#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(){
    int pid = fork();

    if(pid == 0){
        printf("Soy el proceso hijo \n"); //Si el padre muere muere el hijo porq no hay quien lo elimine y el SO se protege de esa manera
        //execl("/workspace/TC1104B.514FerG/hola.exe", "hola.exe", NULL); //Poner el nombre del archivo, si pones otro puede que no puedas detenerlo pq no tienes su nombre
        execlp("hola.exe", "hola.exe",NULL);
        sleep(5);
        printf("NUNCA NUNCA NUNCAAAA");
    }else{
        printf("Soy el proceso padre \n");
        wait(NULL);
    }
    return 0;
}