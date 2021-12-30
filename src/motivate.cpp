#include <fstream>
#include <cstdlib>

#define printF(c_format,str,style,fg_color,bg_color)  printf("\033[0m\033[%d;%d;%dm%s%s\033[0m",style,fg_color,bg_color+10,c_format,str)

#define charToColorCode(x) 30+x-'0'+(60-'A'+'0')*('A'<=x&&x<='H')   // maps 0-9 to 30-39 and A-H to 90-97

int main (int argc,char **argv) {

    // accept 6 digit hex default 0283A8
    int quote_style[3]= {0,32,8};   // 0 2 8
    int author_style[3]= {3,91,8};  // 3 B 8
    
    if(argc>1) {
        if(argv[1][0]=='-'&&argv[1][1]=='h') {
            printf("Usage: motivate [-h] [quote_style author_style]\n");
            printf("Formatting can be done by 3 separate digits - formatting_style foreground_color background_color\n");
            printf("The quote and author style require 3 args each.\n\n");
            printf("The default is: quote_style - 0 2 8 author_style - 3 B 8\n");
            printf("Usage : $ motivate 0 2 8 3 B 8\n\n");
            printf("The behaviour of formatting_style can vary based on the terminal emulator.\n\n");
            //----------------------------------------------------------------------------------
            printf("FORMATTING OPTIONS\n\n");
            printf("\tRESET         0\n");
            printf("\tBRIGHT        1\n");
            printf("\tDIM           2\n");
            printf("\tUNDERSCORE    3\n");
            printf("\tBLINK         4\n");
            printf("\tREVERSE       5\n");
            printf("\tHIDDEN        6\n");
            printf("\tHIGHLIGHT     7\n");
            printf("\tSTRIKETHROUGH 9\n\n");
            //----------------------------------------------------------------------------------
            printf("COLOR OPTIONS - sourced from the terminal's theme (each color has a normal and a bright variant)\n\n");
            printf("\tBLACK         0   A\n");
            printf("\tRED           1   B\n");
            printf("\tGREEN         2   C\n");
            printf("\tYELLOW        3   D\n");
            printf("\tBLUE          4   E\n");
            printf("\tMAGENTA       5   F\n");
            printf("\tCYAN          6   G\n");
            printf("\tWHITE         7   H\n");
            printf("\tNOCOLOR       8       works only for background_color\n\n");

            printf("For more details, checkout the SGR section : https://en.wikipedia.org/wiki/ANSI_escape_code\n");
            return 0;
        }
        else if(argc!=7) {
            printf("Expects 6 arguments.\nRefer help : motivate -h");
            return 1;
        }
        else {
            quote_style[0]=argv[1][0]-'0';
            quote_style[1]=charToColorCode(argv[2][0]);
            quote_style[2]=charToColorCode(argv[3][0]);
            author_style[0]=argv[4][0]-'0';
            author_style[1]=charToColorCode(argv[5][0]);
            author_style[2]=charToColorCode(argv[6][0]);
        }
    }

    unsigned int seed;
    FILE* urandom = fopen("/dev/urandom", "r");
    fread(&seed, sizeof(int), 1, urandom);
    fclose(urandom);
    srand(seed);

    std::ifstream quotes("/usr/share/motivate/quotes.txt",std::ios::binary);
    std::ifstream map("/usr/share/motivate/quotes.map",std::ios::binary);


    if(!quotes.is_open()||!map.is_open()) {
        printf("Error! Files are missing. Consider reinstalling.\n");
        return 1;
    }

    map.seekg(0,std::ios::end);
    int number_of_quotes= map.tellg()/(2*sizeof(unsigned int));
    int random = rand()%number_of_quotes;

    std::string line;
    unsigned int linePosition=0;

    map.seekg(2*random*sizeof(linePosition),std::ios::beg);
    map.read(reinterpret_cast<char*>(&linePosition),sizeof(unsigned int));
    quotes.seekg(linePosition);

    getline(quotes,line);
    printF("",line.c_str(),quote_style[0],quote_style[1],quote_style[2]);
    getline(quotes,line);
    printF("\n\t- ",line.c_str(),author_style[0],author_style[1],author_style[2]);
    printf("\n");

    quotes.close();
    map.close();
    return 0;
}
