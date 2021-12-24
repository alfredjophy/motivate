#include <fstream>
#include <cstdlib>

int main (){ 

    unsigned int seed;
    FILE* urandom = fopen("/dev/urandom", "r");
    fread(&seed, sizeof(int), 1, urandom);
    fclose(urandom);
    srand(seed);

    std::ifstream quotes("/usr/share/motivate/quotes.txt",std::ios::binary);
    std::ifstream map("/usr/share/motivate/quotes.map",std::ios::binary); 


    if(!quotes.is_open()||!map.is_open()){
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
    printf("\033[0;92;49m\"%s\"\n",line.c_str());      
    getline(quotes,line);                              
    printf("\033[3;91;49m\t - %s\n",line.c_str());

    quotes.close();
    map.close();
    return 0;
}
