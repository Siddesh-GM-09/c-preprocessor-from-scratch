//File: remove_comments.c
//Task:
//- Remove all // and /* */ comments
//- Replace with space when needed

#include "header.h"
void removeComments(void){
    FILE *fp=fopen("test.c","r");
    if(!fp){
        printf("\033[31mFile Not Found\033[0m\n");
        return;
    }
    FILE *dp=fopen("abc.i","w");
    char str[1024];
    int flag=0;
    while (fgets(str, 1024, fp)){
        int iflag=1;
        for(int i=0;str[i]!='\0';i++){
            //inside the multiline comment
            if(flag){ 
                if(str[i]=='*'&&str[i+1]=='/'){  //mutltiline comment end
                    fprintf(dp," ");
                    flag=0;
                    i++;
                } 
                else{
                    fprintf(dp," ");
                    if(flag==1 && iflag==1){
                        fprintf(dp,"\n");
                        iflag=0;
                    }
                }
            }
            //single line comment remove
            else if(str[i]=='/' && str[i+1]=='/'){
                fprintf(dp,"\n");
                break;
            }
            /*multiline comment remove*/
            else if(str[i]=='/' && str[i+1]=='*'){
                fprintf(dp," ");
                flag=1;     //start of multi line comment
                iflag=0;    
                i++;
            }
            else{      //don't have comments
                fprintf(dp,"%c",str[i]); 
            }
        }
    }
    fclose(fp);
    fclose(dp);
}