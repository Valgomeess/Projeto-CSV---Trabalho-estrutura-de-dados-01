#include <stdio.h>
#include <string.h>
#include "processos.h"


   int main() {
    char* line = "\"638633058,\"\"00000103020166070018\"\",2016-04-20 15:03:40.000,{12554},{11778},2\"\n";

    int id, classe, assunto, ano;
    char numero[100], data[100]; 

    
    int total_readed = sscanf(line, "\"%d,\"\"%[^\"]\"\",%[^,],{%d},{%d},%d\"", &id, numero, data, &classe, &assunto, &ano);

    printf("linha: %s", line);
    printf("total readed: %d\n", total_readed);
    printf("processo -> id: %d, numero: %s, data_ajuizamento: %s, id_classe: %d, id_assunto: %d, ano_eleicao: %d \n", 
            id, numero, data, classe, assunto, ano);

    return 0;
}

