#include <stdio.h>
#include <stdlib.h>

/* declare global var's */
typedef int word;
int cache_size,
block_size,
mm_size, 
num_rows;

/* define structure of dynamic cache and initialize var */
typedef struct node{
    int tag;
    int valid;
    word *block; // dynamic array of words
}cache_type;
   
cache_type *cache = NULL;

/* define dynamic array for main memory */
word *main_mem = NULL; // creates dynamic array

/****************************************************************/
void enter_params()
{
    /* declare local var's */
    
    /* Prompt for main memory size, cache size, block size */
    printf("Enter main memory size (words): ");
    scanf("%d", &mm_size);
    printf("%d\n", mm_size);
    
    printf("Enter cache size (words): ");
    scanf("%d", &cache_size);
    printf("%d\n", cache_size);
    
    printf("Enter block size (words/blocks): ");
    scanf("%d", &block_size);
    printf("%d\n", block_size);
    
    if(block_size != 0){
       num_rows = cache_size/block_size;
    }//end if
    
    /* allocate and initialize main memory--value at index i = size of main 
    memory+i*/
    main_mem = (word*)malloc(mm_size * sizeof(word));
    
    for(int i = 0; i < mm_size - 1; i++){
       
       main_mem[i] += i + mm_size;
       
    }//end for
    
    /* allocate memory for cache based on number of lines in cache*/
    cache = (cache_type*)malloc(num_rows * sizeof(cache_type));
    
    /* initialize each tag to -1 and each block to NULL */
    for(int i = 0; i < num_rows - 1; i++){
       
       cache[i].valid = 0;
       cache[i].block = NULL;
       
    }//end for
    
return;
}

/****************************************************************/
void access_cache()
{
    /* declare local var's */
    int read_write, 
    mm_addr, 
    ctag, 
    cindex, 
    coffset, 
    base, 
    data;
    
    /* Prompt for read/write signal */
    printf("Select read (0) or write (1) to: ");
    scanf("%d", &read_write);
    printf("%d\n", read_write);
    
    /* Prompt for main memory address to read/write */
    if(read_write == 1){
       
        printf("Enter main memory address to write to: ");
        scanf("%d", &mm_addr);
        printf("%d\n", mm_addr);
    
        printf("Enter value to write: ");
        scanf("%d", &data);
        printf("%d\n", data);
    
    }//end if
    
    if(read_write == 0){
       
        printf("Enter main memory address to read from: ");
        scanf("%d", &mm_addr);
        printf("%d\n", mm_addr);
    
    }//end if

    
    /* Translate main mem addr to cache addr fields*/
    ctag = mm_addr / cache_size;
    
    cindex = (mm_addr % cache_size) / block_size;
    
    coffset = mm_addr % block_size;
    
    base = (mm_addr / block_size) * block_size;
        
    printf("\nAccess result from address %d: \n", mm_addr);
    
    /* Case 1: COMPULSORY MISS--BLOCK NOT ALLOCATED */
    if(cache[cindex].valid == 0){
        
        cache[cindex].valid = 1;
    
        /* Allocate cache block based on block size */
        cache[cindex].block = (word*)malloc(block_size * sizeof(word));
        
        cache[cindex].tag = ctag;
        
        for(int i = 0; i <= block_size - 1; i++){
           
           cache[cindex].block[i] = main_mem[base + i];
           
           }//end for
        
        
        if(read_write == 0){
           
           data = cache[cindex].block[coffset];
           printf("\tRead Miss!\n");
    
        }//end if
    
        else{
           
            cache[cindex].block[coffset] = data;
            printf("\tWrite Miss!\n");
    
        }//end else

    
    }//end if
    
    /* Case 2: CONFLICT MISS--NON-MATCHING TAGS */
    else if(cache[cindex].tag != ctag){
    
        /* Print message of Read/Write miss */
        if(read_write == 0){
           
            data = main_mem[mm_addr];
            printf("\tRead Miss!\n");
    
        }//end if
    
        else{
           
            main_mem[mm_addr] = data;
            printf("\tWrite Miss!\n");
    
        }//end else
    
        /* Overwrite tag */
        cache[cindex].valid = 1;
        
        /* Transfer equivalent block of main memory to cache--one word at a time */
        cache[cindex].block = (word*)malloc(block_size * sizeof(word));

        cache[cindex].tag = ctag;
        
        for(int i = 0; i <= block_size - 1; i++){
           
           cache[cindex].block[i] = main_mem[base + i];

        }//end for
        
    }//end else if
    
    /* Case 3: HIT DUE TO MATCHING TAGS */
    else{
        //transfer
        if(read_write == 0){

            data = cache[cindex].block[coffset];
            printf("\tRead Hit!\n");
            
        }//end if
        
        else{
           
           cache[cindex].block[coffset] = data;
           printf("\tWrite Hit!\n");

        }//end else
           
        /*print message of Read/Write hit*/
        
    }//end else
    
    /*print corresponding tag, block, word, data */
    printf("\tTag: %d\n", ctag);
    printf("\tBlock: %d\n", cindex);
    printf("\tWord: %d\n", coffset);
    printf("\tData: %d\n", data);

return;
}

/****************************************************************/
void free_cache()
{
    
    for(int i = 0; i < num_rows; i++){
       if(cache[i].block != NULL){
          
          free(cache[i].block);
           
       }//end if
        
    }//end for
    
    if(cache != NULL){
       
       free(cache);
       
    }//end if

return;
}

/****************************************************************/
int main()
{
/* declare local var's */
int choice;

/* until program exits, print menu, select choice via switch statement and 
call appropriate function*/

while(choice != 3){
      
      printf("\nDirect-Mapped Cache Memory: \n");
      printf("------------------------------ \n");
      printf("1) Enter Parameters \n");
      printf("2) Access Cache \n");
      printf("3) Quit Program \n\n");
      
      printf("Enter option: ");
      scanf("%d", &choice);
      printf("%d", choice);
      printf("\n");
      
      switch(choice){
         case 1: enter_params();
            break;
         
         case 2: access_cache();
            break;
                  
         case 3: free_cache();
            printf("Exiting Program....\n");
            break;
         
         default: printf("Error:Invaild Entry. Try Again.\n\n");
         
         }
      }

return 1;
}
