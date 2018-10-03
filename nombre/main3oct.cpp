#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>

int main(){


int fdHijos[2]; //0 = recibe info / 1 = envia info
int estado = pipe(fdHijos);

pid_t pid1 = fork();

switch(pid1){//solo pid1
    case 0:
       // close(fdHijos[1]); //envio
        char lect[4];
        read(fdHijos[0],lect,4);
        write(fdHijos[1],lect,4);
        //size_t le = read(fdHijos[0],lect,10);
        //lect[le] ='\0';
        std::cout<< lect <<std::endl;
        break;
    default:
        pid_t pid2 = fork();
        if (pid2 == 0){
            sleep(1);
            close(fdHijos[1]); //envio
            char lect2[4];
            read(fdHijos[0],lect2,4);
            std::cout<< lect2 <<std::endl;
        }else{
        close(fdHijos[0]); //lectura
        write(fdHijos[1],"Hola",4);
        break;
        }
    }
}
