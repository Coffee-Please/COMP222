#include <stdio.h>

/* declare global var's, including total cycles, total instruction count, and clock cycle rate */
   float clock_cycle_rate;
   int total_instr;
   float total_cycles;
   
/*********************************************************/
void enter_param(){
/* declare local var's and initialize*/
   int num_classes;
   int cpi;
   int instr;
      
/* prompt for # instruction classes & clock cycle rate of machine */
   printf("Enter the number of instruction classes: ");
   scanf("%d", &num_classes);
   printf("%d", num_classes);
   printf("\n");
   
   printf("Enter the frequency of the machine (GHz): ");
   scanf("%f", &clock_cycle_rate);
   printf("%.2f", clock_cycle_rate);
   printf("\n");

/* for each instruction class, prompt for CPI of class and instruction count */
   for(int i = 1; i <= num_classes; i++){
      printf("Enter the CPI of class ");
      printf("%d", i);
      printf(": ");   
      scanf("%d", &cpi);
      printf("%d", cpi);   
      printf("\n");

      printf("Enter the instruction count of class ");
      printf("%d", i);
      printf("(billions): ");   
      scanf("%d", &instr);
      printf("%d", instr);   
      printf("\n");

   /* update values in appropriate global var's */
      total_instr += instr;
      total_cycles += cpi * instr;
   }
   return;
}

/*********************************************************/
void calc_cpi(){
/* declare local var's */
   float avg_cpi;
   
/* Calculate Average CPI and print result */
   printf("The average CPI of the sequence is: ");
   
   avg_cpi = total_cycles/total_instr;
   
   printf("%.2f", avg_cpi);
   printf("\n");
   
   return;
}

/*********************************************************/
void calc_exec_time(){
/* declare local var's */
   float exec_time;
   
/* Calculate Execution time and print result */
   printf("The execution time of the sequence is: ");
   
   exec_time = total_cycles/clock_cycle_rate;
   
   printf("%.2f", exec_time);
   printf(" sec\n");

   return;
}

/*********************************************************/
void calc_mips(){
/* declare local var's */
   float mips;

/* Calculate MIPS and print result */
   printf("The total MIPS of the sequence is: ");

   mips = 1000 * (total_instr/(total_cycles/clock_cycle_rate));
   
   printf("%.2f", mips);
   printf("\n");

   return;
}

/*********************************************************/
int main(){
/* declare local var's */
   int choice;

/* until user chooses to quit, print menu,select choice via switch statement and call appropriate function*/
   while(choice != 5){
      printf("Measuring Performance: \n");
      printf("---------------------- \n");
      printf("1) Enter parameters \n");
      printf("2) Calculate CPI of a sequence \n");
      printf("3) Calculate Execution time of a sequence \n");
      printf("4) Calculate MIPS of a sequence \n");
      printf("5) Exit program \n\n");
      
      printf("Enter selection: ");
      scanf("%d", &choice);
      printf("%d", choice);
      printf("\n");
      
      switch(choice){
         case 1: enter_param();
            break;
         
         case 2: calc_cpi();
            break;
         
         case 3: calc_exec_time();
            break;
         
         case 4: calc_mips();
            break;
         
         case 5: printf("Exiting Program. Goodbye!\n");
            break;
         
         default: printf("Error:Invaild Entry. Try Again.\n\n");
         
         }
      }
   return 0;
}
