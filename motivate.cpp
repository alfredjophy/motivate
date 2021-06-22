#include <fstream>
#include <cstdlib>
#include <ctime>

#define NUMBER_OF_QUOTES 221                                    // hard coded because i like stuff FASSTTTTTT....tbh , its me being lazy af
int main (){ 

        srand((unsigned) time(0));
        std::ifstream quotes("/usr/share/motivate/quotes.txt");
        
        int random = rand()%NUMBER_OF_QUOTES;
        
        std::string line;
        for(int i=0;getline(quotes,line);++i){
                if(i==random){
                        printf("\033[0;92;49m\"%s\"\n",line.c_str());
                        getline(quotes,line);
                        printf("\033[3;91;49m\t - %s\n",line.c_str());
                        exit;
                }
                getline(quotes,line);
        }

        quotes.close();
        return 0;
}
