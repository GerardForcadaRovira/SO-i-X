#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string>
#include <vector>

void ControlSalida(int _param){

    signal(SIGALRM, SIG_IGN);
    signal(SIGINT,SIG_IGN);

    std::cout<<"Quieres salir?"<<std::endl;
    char c;
    std::cin>>c;
    std::cout<<"He leido "<<c<<std::endl;
    if(c=='y')
    {
        exit(0);
    }
    signla(SIGNALRM, ControlSalida);
    signal(SIGINT, ControlSalida);

}

void handler(int _sign){

    signal(SIGALRM, SIG_IGN);
    std::cout<< "Son 5, ";
    alarm(5);

}
void handler2(int _sign){

    signal(SIGINT,SIG_IGN);

}

void ejercicio5(){

    for (int i=1;i<=1000;i++){
        std::cout<< i <<' ';
    }

}
void ejercicio7(){

    signla(SIGNALRM, ControlSalida);
    signal(SIGINT, ControlSalida);
    while(1){
        alarm(5);
        pause();
    }

}
void ejercicio9(){
    signal(SIGALRM,SIG_IGN);
    alarm(5);
    std::cout<<"Hola"<<std::endl;
    signal(SIGALRM,ControlSalida);
}
void ejercicio10(int _param){

    std::cout<<"saved"<<std::endl;

}



int main(){
/*
    alarm(5);
    //ejercicio5();
    //ejercicio7();
    signal(SIGALRM,handler);
    pause();
/////////////////////////////////
    signal(SIGALRM,ControlSalida);
    signal(SIGINT,ControlSalida);
    alarm(5);
    int status;
    pid_t pid = fork();
    signal(SIGALRM,ejercicio9);
    if(pid==0){

    }
*/
    int status;
    pid_t pid = fork();
    if(pid==0){
        signal(SIGUSR1,ejercicio10);//el SIGKILL NO se puede editar!!!!!!!!
        pause();

    }else{
        sleep(1);
        kill(pid,SIGUSR1);
        wait(&status);
    }

}
