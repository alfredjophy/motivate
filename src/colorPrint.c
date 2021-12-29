#include <stdio.h>
#include <stdbool.h>

void printF(char str[],int formatting,int fg_color,int bg_color){
    printf("\033[%d;%d;%dm%s\033[0m",formatting,fg_color+30,bg_color+40,str);

}

int main(int argc, char** argv){
    
    for(int i=0;i<877;i++)
        printF("hello world\n",i%10,(i/10)%10,i/100);
    
    return 0;
}
