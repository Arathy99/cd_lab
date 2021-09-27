#include<stdio.h>
#include<stdlib.h>
int v=0,c=0,co=0,d=0,s=0;
void main()
{
    FILE *read_file,*write_file;
    char ch;
    
    read_file = fopen("file1.txt","r");
    write_file = fopen("file2.txt","w");
    if(read_file == NULL || write_file == NULL)
    {
        perror("unable to read the file");
        exit(1);
    }
    while(1){
        ch=fgetc(read_file);
        if(ch == EOF)
             break;
        switch(ch){
            case 'a':  v = v+1;
                       break;
            case 'e':  v = v+1;
                       break;
            case 'i':  v = v+1;
                       break;
            case 'o':  v = v+1;
                       break;
            case 'u':  v = v+1;
                       break;
            case 'A':  v = v+1;
                       break;
            case 'E':  v = v+1;
                       break;
            case 'I':  v = v+1;
                       break;
            case 'O':  v = v+1;
                       break;
            case 'U':  v = v+1;
                       break;
            case '0':  d = d+1;
                       break;
            case '1':  d = d+1;
                       break;
            case '2':  d = d+1;
                       break;   
            case '3':  d = d+1;
                       break;
            case '4':  d = d+1;
                       break;
            case '5':  d = d+1;
                       break;            
            case '6':  d = d+1;
                       break;
            case '7':  d = d+1;
                       break;
            case '8':  d = d+1;
                       break;
            case '9':  d = d+1;
                       break;
            case '>':  s = s+1;
                       break;
            case '<':  s = s+1;
                       break;
            case '[':  s = s+1;
                       break;
            case ']':  s = s+1;
                       break;
            case ';':  s = s+1;
                       break;
            case '$':  s = s+1;
                       break;
            case '%':  s = s+1;
                       break;
            case '*':  s = s+1;
                       break;
            case ':':  s = s+1;
                       break;
            case '!':  s = s+1;
                       break; 
            case ' ':  s = s+1;
                       break; 
            case ',':  s = s+1;
                       break; 
            case '\\;':  s = s+1;
                       break;  
            case '\\':  s = s+1;
                       break;                 
            default :  co = co+1;
                       break;
        } 
          
    }
     c= co+v;
    fclose(read_file);
    fprintf(write_file,"List Of:\n\ncharacter ~\t%d\nvowels ~\t%d\nconsonants ~\t%d\ndigits ~\t%d\nspecial symbols ~\t%d\n",c,v,co,d,s);
    fclose(write_file);
    return 0;
}
