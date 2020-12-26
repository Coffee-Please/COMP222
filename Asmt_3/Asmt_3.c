#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define structure for instruction containing fields for instruction string, 
destination register, 2 source registers, and individual instruction delay 
and a variable as pointer to structure for creating a dynamic array of instructions */
typedef struct Scoreboard{
   char instr_string[13];
   int dest_reg;
   int src_1;
   int src_2;
   int delay;
} instr_type;

/* global var's */
instr_type *instr_set = NULL;//dynamic array
int num_instr;

/*************************************************************/
void enter_instr()
{
/* Declare local variables*/

/* Prompt for total number of instructions */
   printf("\nEnter total number of instructions: ");
   scanf("%d", &num_instr);
   printf("%d\n", num_instr);
   
/* Allocate memory to hold a set of instructions */
   instr_set = (instr_type*)malloc((3 * num_instr + 1) * sizeof(instr_type));

/* Initialize instruction 0's destination register to -1 to 
prevent false RAW dependency w/ instruction 2 */
   instr_set[0].dest_reg = -1;

/* For each instruction, prompt for user input and read instruction as a string 
and store at proper field of appropriate index within dynamic array of instructions */
   for(int i = 1; i <= num_instr; i++){
      scanf("%s", instr_set[i].instr_string);
      
      instr_set[i].dest_reg = instr_set[i].instr_string[5] - '0';
      instr_set[i].src_1 = instr_set[i].instr_string[8] - '0';
      instr_set[i].src_2 = instr_set[i].instr_string[11] - '0';

   }//end for


return;
}

/*****************************************************/
void build_dynamic_pipeline()
{
/* Declare local variables */
   int delay = 0;
   int overlap = 0;
   int total_cycles = 0;
   instr_set[1].delay = 0;

/* For each instruction i from 2 to total number of instructions, 
	initialize delay as 0 and check for dependency
	between instruction (i-2) and i, as well as between instruction (i-1) and i */

   for(int i = 2; i <= num_instr; i++){
   
      delay = 0;

      /* If dependency,  set delay appropriately, as well
	   as a flag to check for possible overlap between dependent instructions */
   
      /* Note: general formula for delay: 
   		delay=2 if instruction i depends on instruction (i-1)
   		delay=1 if instruction i depends on instruction (i-2) 
   		and no overlapping dependency of higher precedent
   		delay=0 otherwise
   	*/
   
      if((instr_set[i].src_1 == instr_set[i - 2].dest_reg) || (instr_set[i].src_2 == instr_set[i - 2].dest_reg)){

         if(overlap == 0){
            delay = 1;
            overlap = 1;
         
         }//end if
         
         else{
         
            delay = 0;
            overlap = 0;
            
         }//end else
         
      }//end if
   
      else{
         overlap = 0;
      }//end else
      
      if((instr_set[i].src_1 == instr_set[i - 1].dest_reg) || (instr_set[i].src_2 == instr_set[i - 1].dest_reg)){
      
         delay = 2;
         overlap = 1;
         
      }//end if

   	/* set delay for instruction i based on calculated delay*/
   	
      instr_set[i].delay = delay + 1 + instr_set[i - 1].delay;

   }//end for

/* end for-loop */

/* Calculate and print total cycles (include overhead from instruction 1*/

   total_cycles = instr_set[num_instr].delay + 5;
   
   printf("\nTotal cycles: %d\n\n", total_cycles);

/* Print Instruction string & Gantt chart by tabbing each instruction's cycles 
based on each instruction's delay */

   for(int i = 1; i <= num_instr; i++){

      printf("%s :", instr_set[i].instr_string);
      
      for(int t = 1; t <= instr_set[i].delay; t++){
         
         printf("\t");

      }//end for t
      
      printf("\tIF\tID\tEX\tME\tWB\n");
      
   }//end for i

return;
}

void build_static_pipeline() 
{
/* Declare local variables */
   int delay = 0;
   int overlap = 0;
   int total_cycles = 0;
   
/* For each instruction i from 2 to total number of instructions
	initialize delay as 0 and check for dependency
	between instruction (i-2) and i, as well as between instruction (i-1) and i */

   for(int i = 2; i <= num_instr; i++){
   
      delay = 0;

   	/* If dependency, add NOPs appropriately by shifting remaining instructions down
   	and set delay & flag to check for possible overlap between dependent instructions,
   	and increase total number of instructions appropriately*/
   
   	/* Note: general formula for delay: 
   	delay=2 if instruction i depends on instruction (i-1)
   	delay=1 if instruction i depends on instruction (i-2) and no dependency of higher precedent
   	delay=0 otherwise
   	*/
   	
	      if((instr_set[i].src_1 == instr_set[i - 2].dest_reg) || (instr_set[i].src_2 == instr_set[i - 2].dest_reg)){

         if(overlap == 0){
            delay = 1;
            overlap = 1;
         
         }//end if
         
         else{
         
            delay = 0;
            overlap = 0;
            
         }//end else
         
      }//end if
   
      else{
         overlap = 0;
      }//end else
      
      if((instr_set[i].src_1 == instr_set[i - 1].dest_reg) || (instr_set[i].src_2 == instr_set[i - 1].dest_reg)){
      
         delay = 2;
         overlap = 1;
         
      }//end if

      if(delay == 2){
      
         for(int k = num_instr; k >= i; k--){
         
            instr_set[k + 2] = instr_set [k];
         
         }//end for
         
         strcpy(instr_set[i].instr_string, "NOP\t");
         strcpy(instr_set[i + 1].instr_string, "NOP\t");
         
         num_instr += 2;
         i += 2;
         
      }//end if

      if(delay == 1){
      
         for(int k = num_instr; k >= i; k--){
         
            instr_set[k + 1] = instr_set [k];
         
         }//end for
         
         strcpy(instr_set[i].instr_string, "NOP\t");
   
         num_instr += 1;
         i += 1;
         
      }//end if

   }//end for


	
 /* end for-loop */

/* Calculate and print total cycles (include overhead from instruction 1*/

   total_cycles = 5 + num_instr - 1;
   
   printf("\nTotal cycles: %d\n\n", total_cycles);

/* Print Instruction string & Gantt chart 
by tabbing each instruction's cycles appropriately
*/

   for(int i = 1; i <= num_instr; i++){

      printf("%s :", instr_set[i].instr_string);
      
      for(int t = 1; t <= i; t++){
         
         printf("\t");

      }//end for t
      
      printf("IF\tID\tEX\tME\tWB\n");
      
   }//end for i

return;
}

/****************************************************************/
void quit_program(){
   if(instr_set != NULL){
      
      free(instr_set);
      
   }//end if
   
return;
}//end quit

/****************************************************************/
int main()
{
/* declare local var's */
   int choice;
   
/* until program exits, print menu, select choice via switch statement and call appropriate function*/
   while(choice != 4){
      
      printf("\nInstruction-level parallelism: \n");
      printf("------------------------------ \n");
      printf("1) Enter instructions \n");
      printf("2) Calculate and show total cycle count on a 5-stage dynamic pipeline processor \n");
      printf("3) Calculate and show total cycle count on a 5-stage static pipeline processor (w/ NOPs)\n");
      printf("4) Quit program \n\n");
      
      printf("Enter selection: ");
      scanf("%d", &choice);
      printf("%d", choice);
      printf("\n");
      
      switch(choice){
         case 1: enter_instr();
            break;
         
         case 2: build_dynamic_pipeline();
            break;
         
         case 3: build_static_pipeline();
            break;
                  
         case 4: quit_program();
            printf("Exiting Program. Goodbye!\n");
            break;
         
         default: printf("Error:Invaild Entry. Try Again.\n\n");
         
         }
      }
  
  return 1;
}
