#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define block_size 512


 
int main(int argc, char *argv[])
{
    
 FILE *source=fopen(argv[1],"r");
 FILE *img =fopen(argv[2],"w") ;
    if ( source == NULL){
        printf("Could not open %s.\n",argv[1]);
        return 1;
    }    
        else{
            typedef uint8_t BYTE;
            BYTE buffer[block_size];
            int currentfilenumber=0;
            while(feof(source)==0){
                   fread(buffer,sizeof(BYTE),4,source);
                   
             if (buffer[0]== 0xff && buffer[1]==0xd8 && buffer[2]==0xff && (buffer[3]&0xf0)==0xe0){
                 
                 FILE *img =fopen(argv[2],"w") ;
                 sprintf(img,"%03i.jpg",currentfilenumber);
                 
                 if ( img == NULL){
                     printf("No destination file %s.\n",argv[2]);
                     return 1;
                     }
                    else{
                        fread(buffer,sizeof(BYTE),block_size,source);
                        fwrite(buffer,sizeof(BYTE),block_size,img);
                        fclose(img);
                        currentfilenumber++;
                        
                        sprintf(img,"%03i.jpg",currentfilenumber);
                        FILE *img =fopen(img,"w") ;
                     }
                    
           
             }
             
                
           
        
            }
    
}
fclose(source);
fclose(img);

return 0;
}