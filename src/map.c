#include <stdio.h>

int main(int argc , char** argv){
        
        FILE * input=fopen(argv[1],"rb");
        FILE* map=fopen(argv[2],"wb");

        char *str;
        unsigned int position=0;

        fseek(input,0,SEEK_SET);
        fscanf(input,"%s",str);
        fwrite(&position,sizeof(position),1, map);

        while(fscanf(input, "%s",str)){
                position=ftell(input);
                fwrite(&position,sizeof(position),1, map);
        }
        
        fclose(input);
        fclose(map);
        return 0;
}
