#include <cstdio>

#define printF(c_format,str,style,fg_color,bg_color)  printf("\033[0m\033[%d;%d;%dm%s%s\033[0m",style,fg_color,bg_color+10,c_format,str)

#define charToColorCode(x) 30+x-'0'+(60-'A'+'0')*('A'<=x&&x<='H')   // maps 0-9 to 30-39 and A-H to 90-97

int main(int argc, char** argv){
    
    int formatting_styles[]={'0','1','2','3','4','5','6','7','8','9'};
    int color_styles[]={'0','1','2','3','4','5','6','7','8','A','B','C','D','E','F','G','H'};
    
    for(int i=0;i<10;i++)
        for(int j=0;j<17;i++)
            for(int k=0;k<17;k++)
                printF("","Hello World\n",charToColorCode(formatting_styles[i]),charToColorCode(color_styles[j]),charToColorCode(color_styles[k]));
    return 0;
}
