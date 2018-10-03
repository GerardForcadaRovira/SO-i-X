#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
#include <fcntl.h>
/*
int main(){

pid_t pid = fork();

    if(pid==0){

        std::string sh = "hijo";
        int fdh = open("/home/gerard/SO I X/nombre/fichero.txt", O_WRONLY);
        if (fdh<0){
            std::cout<<"error hijo"<<std::endl;
            exit(0);

        }
        write(fdh,sh.c.str(),sh.size());
        int close(sh);

    }
    else
    {

        std::string sp = "padre";
        int fdp = open("/home/gerard/SO I X/nombre/fichero.txt", O_WRONLY);
        if (fdp<0){
            std::cout<<"error hijo"<<std::endl;
            exit(0);
        }
        write(fdp,sp.c.str(),sp.size());
        int close(sp);

    }

std::cout<<"finish"<<std::endl;

}*/
