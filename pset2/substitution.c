#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <strings.h>

int main(int argc, string argv[]){
    if(argc < 2){
        printf("Usage: ./substitution KEY\n");
        return 1;
    }
    
    if(strlen(argv[1]) < 26 ){
        printf("KEY must contain 26 characters \n");
        return 2;
    }
    
    for(int i=0; i < strlen(argv[1]);i++ ){
        if (!isalpha(argv[1][i])){
            printf("KEY must contain only alphabetic characters \n");
        return 3;
        }
    }
    
    for(int i=0; i < strlen(argv[1]);i++ ){
        for(int j=i+1; j <strlen(argv[1]);j++){
        if (toupper(argv[1][i]) == toupper(argv[1][j]) ){
            printf("KEY must not contain repeated characters \n");
        return 4;
        }
    }
    }
    
    string plaintext = get_string("Plaintext: ");
    int index;
    
    printf("Ciphertext:");
   
        for (int i=0; i < strlen(plaintext) ; i++){
            if(isalpha(plaintext[i])){
                if(isupper(plaintext[i])){
                    index = ((int) plaintext[i]) - 65;
                    plaintext[i] = argv[1][index];
                    
                    printf("%c",plaintext[i]);
                    }
                    else
                    {
                        index = ((int) plaintext[i]) - 97;
                        plaintext[i] = argv[1][index];
                        plaintext[i] = tolower(plaintext[i]);
                        
                        printf("%c",plaintext[i]);
                    }
                
            }
            else{
                printf("%c",plaintext[i]);
            }
            
        }
        
        printf("\n");
        
    
    return 0;
}
