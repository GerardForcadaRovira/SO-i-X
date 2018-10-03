#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
/*
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
}// ************************** HACER UNA PIPE PARA CADA HIJO, UNA PARA EL HIJO 1 Y UNA PARA EL HIJO 2
*/
int main(){


int fdHijo1[2]; //0 = recibe info / 1 = envia info
int fdHijo2[2]; //0 = recibe info / 1 = envia info
int estado1 = pipe(fdHijo1);
int estado2 = pipe(fdHijo2);

pid_t pid1 = fork();

switch(pid1){//solo pid1
    case 0:
        close(fdHijo1[1]); //envio
        char lect[4];
        read(fdHijo1[0],lect,4);
        write(fdHijo1[1],lect,4);
        //size_t le = read(fdHijos[0],lect,10);
        //lect[le] ='\0';
        std::cout<< lect <<std::endl;
        break;
    default:
        pid_t pid2 = fork();
        if (pid2 == 0){
            close(fdHijo2[1]); //envio
            char lect2[4];
            read(fdHijo2[0],lect2,4);
            std::cout<< lect2 <<std::endl;
        }else{
        close(fdHijo1[0]); //lectura
        close(fdHijo2[0]); //lectura
        write(fdHijo1[1],"Hola",4);
        write(fdHijo2[1],"Hey!",4);
        break;
        }
    }
}
