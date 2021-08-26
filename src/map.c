#include <stdio.h>

int main(int argc , char** argv){

    FILE * input=fopen(argv[1],"rb");
    FILE* map=fopen(argv[2],"wb");

    char str[1000];
    unsigned int position=0;

    fseek(input,0,SEEK_SET);
    fgets(str,1,input);
    fwrite(&position,sizeof(position),1, map);

    while(fgets(str,1000,input) !=NULL){
        position=ftell(input);
        /*printf("%d\n",position);*/
        fwrite((char*)&position,sizeof(position),1, map);
    }

    printf("SIZE = %lu",sizeof(position));
    fclose(input);
    fclose(map);
    return 0;
}
