//File: remove_comments.c
//Task:
//- Remove all // and /* */ comments
//- Replace with space when needed

#include "header.h"
void removeSingleLine(void){
    FILE *fp=fopen("test.c","r");
    if(!fp){
        printf("\033[31mFile Not Found\033[0m\n");
        return;
    }
    FILE *dp=fopen("abc.i","w");
    char *str=malloc(sizeof(char)*1024);
    while (fgets(str, 1024, fp)){
        for(int i=0;str[i]!='\0';i++){
            //single line comment remove
            if(str[i]=='/'&& str[i+1]=='/'){
                fprintf(dp," ");
                fprintf(dp,"\n");
                break;
            }
            else{
                fprintf(dp,"%c",str[i]);
            }
        }
    }
    free(str);
    fclose(fp);
    fclose(dp);
}