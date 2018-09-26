#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
/*
int main(){

    int status;
    pid_t pid = fork();

    if(pid==0){

        execl("/usr/bin/firefox","/usr/bin/firefox",(char*)0);

    }else{

        pid = fork();
        if(pid == 0){
        execl("/usr/bin/soffice","/usr/bin/soffice",(char*)0);
        }

       // std::cout<<<"i am your father"<<std::endl;

        wait(&status);
        wait(&status);

    }

    return(0);
}
*/
