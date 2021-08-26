#include <stdio.h>
#include <wchar.h>
#include <locale.h>

int main(int argc , char** argv){

    FILE* input =fopen("quotes.min","r");
    
    setlocale(LC_CTYPE,"en_US.UTF-8");
    wchar_t buf[100000];

    while (fgetws(buf,1000,input)!=NULL){
        wprintf(L"%s",buf);
        wprintf(const wchar_t *restrict __format, ...)
    }
    fclose(input);
    return 0;
}
