#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>


int main(int argc, char *argv[])
{

    
    int filedirectory[2];
	int Size_of_file;
	pid_t pid;

    char Text[1024];
	char Copy[1024];  

    
    char* sourceFile = argv[1];
    char* destFile = argv[2];

  
    pipe(file_directory);
    if (pipe(file_directory)==-1) 
    { 
        printf(stderr, "Pipe Failed" ); 
        return 1; 
    }  
    pid = fork();
     if (pid < 0) 
    { 
        printf(stderr, "Fork Failed" ); 
        return 1; 
    } 
    
    if (pid > 0) 
    {
	   int sourceFileNum;
	   ssize_t nBytes; 
       
        close(file_directory[0]);
        sourceFileNum=open(sourceFile, O_RDONLY);
        nBytes=read(sourceFileNum, text,sizeof(text));
        

        write(file_directory[1],text, nBytes);
        close(file_directory[1]);
    
    }else if (pid == 0){
    	
    	int dest_Desc;
        close(file_directory[1]);
        ssize_t numBytesCh;
        nBytesCh =read(file_directory[0], copy,sizeof(copy));
        close(file_directory[0]);
        destDesc=open(dest_file, O_CREAT | O_WRONLY);
        write(destDesc, copy, nBytesCh);
    }

    return 0;
}


