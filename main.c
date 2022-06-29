#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){

    FILE *file;
    FILE *tempfile;

    file = fopen("file.txt", "r");
    tempfile = fopen("tempfile.txt", "w");
    
    if (file == NULL || tempfile == NULL){
        printf("error: failed opening files");
        return 1;
    }

    char buffer[1024];
    char line[1024];
    char name[20];

    
    int linenumber = -1;

    printf("enter your first name: \n");
    if(fgets(name, 20, stdin) == NULL){
        printf("error: failed reading string");
        return 1;
    }

    do
    {
        printf("enter a positive line number: \n");

        if(fgets(line, 1024, stdin) == NULL){
            
            printf("error: failed reading number");
            return 1;
        }
        
        linenumber = atoi(line);
    } while(linenumber < 1);

    int currentline = 1;

    while(fgets(buffer, 1024, file) != NULL){
        
        if(currentline == linenumber){
            
            fputs(name, tempfile);
        } 
        else {
        
            fputs(buffer, tempfile);
        }

        currentline++;
    }

    fclose(file);
    fclose(tempfile);
    
    remove("file.txt");
    rename("tempfile.txt", "file.txt");

}
