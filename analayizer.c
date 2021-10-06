#include<stdio.h>
#include<stdlib.h>
#include<string.h>
FILE *read_file ,*write_file;
int flag;
int opc = 0 ,keyc = 0 ,idc = 0 ,relc = 0 ,symc = 0 ;
char str[100];
char op[100][100] ,key[100][100] ,id[100][100] ,rel[100][100],sym[100][100];


int operator(char str2[100])
{
    int flag=0;
    char _operator[9][100]={"+","=","-","/","*","**","++","--","%"};
    for(int i = 0;i < 9; i++)
    {
       if(strcmp(str2,_operator[i]) == 0)
        {
          return 1;
        }
    }
    return 0;
  
}

int keyword(char str2[100])
{
    int flag=0;
    char _keyword[33][100]={"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for","goto","if","int","long","register","return","short","signed","sizeof","staticstruct","switch","typedef","union","unsigned","void","volatile","while","main"};
    for(int i = 0;i < 33; i++)
    {
       if(strcmp(str2,_keyword[i]) == 0)
        {
          return 1;
        }
    }
     return 0;
  
}

int relation(char str2[100])
{
    int flag=0;
    char _relation[6][100]={"==","!=","\>","<",">=","<="};
    for(int i = 0;i < 6; i++)
    {
       if(strcmp(str2,_relation[i]) == 0)
        {
           return 1;
        }
    }
    return 0; 
}
int symbol(char str2[100])
{
    int flag=0;
    char _symbol[10][100]={"{","}","[","]",";",",","\'","\"",")","("};
    for(int i = 0;i < 10; i++)
    {
       if(strcmp(str2,_symbol[i]) == 0)
        {
           return 1;
        }
    }
    return 0; 
}

int display()
{
    write_file = fopen("write.txt","w");
        fprintf(write_file,"\t\t\tLexical Analyzer\n\nOperators\n"); 
        for(int i=0 ; i < opc ; i++)
        {
            fprintf(write_file,"\"%s\"\t",op[i]); 
        }
        fprintf(write_file,"\n\nkeywords\n");
        for(int i=0 ; i < keyc ; i++)
        {
            fprintf(write_file,"\"%s\"\t",key[i]); 
        }
        fprintf(write_file,"\n\nidentifiers\n");
        for(int i=0 ; i < idc ; i++)
        {
            fprintf(write_file,"\"%s\"\t",id[i]); 
        }
        fprintf(write_file,"\n\nrelation\n");
        for(int i=0 ; i < relc ; i++)
        {
            fprintf(write_file,"\"%s\"\t\t",rel[i]); 
        }
        fprintf(write_file,"\n\nspecial symbols\n");
        for(int i=0 ; i < symc ; i++)
        {
            fprintf(write_file,"\"%s\"\t\t",sym[i]); 
        }

    fclose(write_file);
    return 0;
}


int main()
{
    
    read_file = fopen("read.txt","r");
   
    while(fscanf(read_file,"%s",str) != EOF)
    {
        if(operator(str))
         {
           strcpy(op[opc++], str);
         } 
        else if(keyword(str))
         {
          strcpy(key[keyc++], str); 
         }
        else if(relation(str))
         {
          strcpy(rel[relc++], str); 
         }
         else if(symbol(str))
         {
          strcpy(sym[symc++], str); 
         }
        else
          {
             strcpy(id[idc++], str);
          
         }
    }
    
    display();   
    fclose(read_file);
   
    
    return 0;
    
}
