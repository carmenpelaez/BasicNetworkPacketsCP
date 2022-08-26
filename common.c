#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main(int argc, char*argv){

    if (argc!=2)
    {
        printf("nothing happens");
        return -1;
    }

    FILE*fr = fopen("sample_packets.txt", "r"); 

    if (fr == NULL)
    {
        printf("file %d not found", argv[1]);
        return -1;
    }
    
    read_packet_file();
    parse_mac_dst();
    filter_mac();
    print_mac_list();

    printf("");

    return 0;

   
}


#define MAX_LINES 100
#define MAX_LEN 1000

int read_packet_file(FILE*fr ){
    char data[MAX_LINES][MAX_LEN];

    FILE*file;

    file = fopen("sample_packets.txt", "r");

    if (file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }

    int line =0;

    while (!feof(file) && !ferror(file))
    if (fgets(data[line], MAX_LEN, file) != NULL)
    line++;

    fclose(file);

    for (int i = 0; i < line; i++)
    {
        printf("%s", data[i]);
    }
    
    


    return 0;
    
}

void parse_mac_dst(){

}

void filter_mac(){

}

void print_mac_list(){
    // printf("%s_%s_%s_%s_%s");
}
//add error