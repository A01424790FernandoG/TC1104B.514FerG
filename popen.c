#include <stdio.h>

int main(){
    FILE *lsOutput;
    FILE *tomayIntput;
    char readBuffer[80];
    lsOutput = popen("ls *.c","r");
    tomayIntput = popen("./tomay", "w");
    while (fgets(readBuffer,80,lsOutput)){
        fputs(readBuffer, tomayIntput);
    }
    pclose(lsOutput);
    pclose(tomayIntput);
}