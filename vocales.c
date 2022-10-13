#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <ctype.h>


int main(){
    char c;
    char may;
    int n;
    do{
        n=read(STDIN_FILENO,&c,1);
        may = toupper(c);
        if(may == 'A'|| may=='E' || may=='I' || may== 'O' || may=='U' || may=='a'|| may=='e'|| may=='i'|| may=='o'|| may=='u'){
            write(2, "1 \n", 17);
            write(STDOUT_FILENO,&may,1);
        }
    }while(n !=0);
    return 0;
}