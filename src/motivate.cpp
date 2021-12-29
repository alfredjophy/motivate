#include <fstream>
#include <cstdlib>


inline void printF(const char* c_format,const char *str,int style=0,int fg_color=1,int bg_color=0) {
    printf("\033[%d;%d;%dm%s%s\033[0m",style,fg_color+30,bg_color+40,c_format,str);
}

int main (int argc,char **argv) {

    // accept 3 arguments
    int quote_style[3]= {0,2,0};
    int author_style[3]= {3,1,0};

    if(argc>1) {
        if(argv[1][0]=='-'&&argv[1][1]=='h') {
            printf("Motivate - Gives you a motivational quote\nUsage: motivational [-h] [format]\n\n\tFor help   -h \n\n\tFormatting can be done for the quote and the author name\n\tEach format accept 3 arguments - style foreground_color background color\n\tThe default theme has args 0 2 0 3 1 0\n\t$ motivate 0 2 0 3 1 0\n\t6 arguments are necessary\n\n\tFormatting Styles (features like blinking depends on the terminal emulator)\n\tRESET		  0\n\tBRIGHT 		  1\n\tDIM		  2\n\tUNDERLINE 	  3\n\tBLINK		  4\n\tREVERSE		  7\n\tHIDDEN		  8\n\tSTRIKETHROUGH     9\n\n\tColors\n\tBLACK 		 0\n\tRED		 1\n\tGREEN		 2\n\tYELLOW		 3\n\tBLUE		 4\n\tMAGENTA		 5\n\tCYAN		 6\n\tWHITE		 7\n");
            return 0;
        }
        else if(argc!=7) {
            printf("Expects 6 arguments.\nRefer help : motivate -h");
            return 1;
        }
        else {
            quote_style[0]=argv[1][0]-'0';
            quote_style[1]=argv[2][0]-'0';
            quote_style[2]=argv[3][0]-'0';
            author_style[0]=argv[4][0]-'0';
            author_style[1]=argv[5][0]-'0';
            author_style[2]=argv[6][0]-'0';
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

    quotes.close();
    map.close();
    return 0;
}
