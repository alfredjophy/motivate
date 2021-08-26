#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "motivate.h"   // NOLINT

int main(){
    srand((unsigned) time(0));
    
    FILE* quotes=fopen(quotes_path,"rb");   // NOLINT
    FILE* map=fopen(quotes_map_path,"rb");  // NOLINT

    if(quotes==NULL || map==NULL){
        printf("Error! Files are missing. Consider reinstalling.");
        return -1;
    }

    fseek(map,0,SEEK_END);
    int number_of_quotes=ftell(map)/(2*sizeof(unsigned int));

    int random=rand()%number_of_quotes;
    unsigned int linePosition=0;
    fseek(map,2*random*sizeof(linePosition),SEEK_SET);
    fread(&linePosition, sizeof(linePosition), 1, map);

    char quote[1000];
    fseek(quotes, linePosition, SEEK_CUR);

    fgets(quote,1000,quotes);
    printf("%s",quote);
    fgets(quote,1000,quotes);
    printf("%s",quote);
    return 0;
}
