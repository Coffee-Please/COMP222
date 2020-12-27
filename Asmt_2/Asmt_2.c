#include <stdio.h>
#include <math.h>

/*************************/
void dec_to_ieee()
{
	/* declare local variables */
   float dec, temp_dec;
   int ieee, sign, mantissa = 0, exp = 0, temp_exp;
   
   
	/* prompt for floating point decimal number */ 
      printf("Enter the decimal representation: ");
      scanf("%f", &dec);
      printf("%.2f\n", dec);

	/* Check for 0--if so, print result */
   if(dec == 0.0){
      printf("Sign: 0\n");
      printf("Biased Exponent: 00000000\n");
      printf("Mantissa: 00000000000000000000000\n");
      printf("IEEE-754: 00000000\n");

      return;
      
   }//end if


	/* Print sign: if number>0, sign is 0, else 1 */
  if(dec > 0){
      sign = 0;
   }//end if
   else{
      sign = 1;
   }//end else

   printf("Sign: %d\n", sign);

	/* take absolute value of number before generating significand */ 
   dec = fabsf(dec);//fabsf == asb(float)

	/* Normalize number:*/
   temp_dec = dec;
   
   /*	while number >2, divide by 2, increment exponent*/
   while(temp_dec >= 2){
      temp_dec = temp_dec / 2;
      exp++;
   }//end while

   /*	while number <1, multiply by 2, decrement exponent*/
   while(temp_dec < 1){
      temp_dec = temp_dec * 2;
      exp--;
   }//end while

    /* Bias exponent by 127 and print each bit in binary with 8-iteration for-loop*/
   exp += 127;
   temp_exp = exp;
   
   printf("Biased Exponent: ");
   
   for(int i = 0; i < 8; i++){
      if(temp_exp >= 128){
         printf("1");
         temp_exp -= 128;
      }//end if
      else{
         printf("0");   
      }//end else

    temp_exp *= 2;
   }//end for

   printf("\n");

    /* Hide 1 and print significand in binary with 23-iteration for-loop*/
   printf("Mantissa: ");

   temp_dec -= 1;
      
   for(int i = 1; i <= 23; i++){
      if(temp_dec >= 0.5){
         temp_dec -= 0.5;
         mantissa += pow(2, (23 - i));
         printf("1");
      }//end if
      else{
         printf("0"); 
      }//end else
    temp_dec = temp_dec * 2;
   }//end for
   
   printf("\n");
   
   int first = sign * pow(2, 31);
   int second = exp * pow(2, 23);
   int third = mantissa;
    
	/* Print IEEE-754 representation */
   ieee = first + second + third;
      
   printf("IEEE-754: %x\n", ieee);
	
  return;
}

/***********************************************************************/
void ieee_to_dec()
{
  /* declare local variables */
  int ieee, exp;
  float significand, new_significand, norm_num;
  char sign;
  
  /* prompt for IEEE-754 representation */
      printf("Enter the IEEE-754 representation: ");
      scanf("%x", &ieee);
      printf("%x\n", ieee);
      
	/* check for special cases: 0, -0, +infinity, -infinity, NaN, 
		if so, print and return */ 
		//Case 0
		if(ieee == 0x00000000){
         printf("Special Case: 0\n");
         return;
      }//end if
      
      //Case -0
      if(ieee == 0x80000000){
         printf("Special Case: -0\n");
         return;
      }//end if

      //Case +infinity
      if(ieee == 0x7F800000){
         printf("Special Case: +Infinity\n");
         return;
      }//end if
      
      //Case -infinity
      if(ieee == 0xFF800000){
         printf("Special Case: -Infinity\n");
         return;
      }//end if
      
      //Case NaN
      if(ieee > 0xFF800000 || ieee > 0x7F800000){
         printf("Special Case: NaN");
         return;
      }//end if

	/* Mask sign from number: if sign=0, print "+", else print "-" */
	if(ieee < 0x80000000){
	   printf("Sign : +\n");
	   sign = '+';
	}//end if
	else{
		printf("Sign : -\n");
		sign = '-';
	}//end else
	
	
	/* Mask biased exponent and significand from number */
   exp = (ieee & 0x7F800000)/ (pow(2, 23));
   
   significand = (ieee & 0x007FFFFF)/ (pow(2, 23));
   
	/* If biased exponent=0, number is denormalized with unbiased exponent of -126, 
		print denormalized number as fraction * 2^(-126), return */
   if(exp == 0){
      
   printf("Unbiased Exponent: %d\n", (-126));
   printf("Denormalized Number: %c%f * 2^(-126)\n", sign, significand);
   
   return;
   
   }//end if


	/* Unbias exponent by subtracting 127 and print */
	exp -= 127;
	
   printf("Unbiased Exponent: %d\n", exp);

	/* Add hidden 1 and print normalized decimal number */
	new_significand = 1 + significand;
	
	if(ieee < 0x80000000){
    	printf("Normalized decimal: %f\n", new_significand);
	}//end if
	else{
	printf("Normalized decimal: %c%f\n", sign, new_significand);
	}//end else
	
	
	norm_num = new_significand * (pow(2, exp));
	
	/* Print decimal number */
	if(ieee < 0x80000000){
    	printf("Decimal: %f\n", norm_num);
	}//end if
	else{
	    printf("Decimal: %c%f\n", sign, norm_num);
	}//end else

	 return;
}

int main()
{
  /* declare local variables */
  int choice = 0;
  
  /* until user chooses to quit, prompt for choice and select appropriate function */
  while(choice != 3){
      printf("\nFloating-point conversion \n");
      printf("-------------------------- \n");
      printf("1) Decimal to IEEE-754 conversion \n");
      printf("2) IEEE-754 to Decimal conversion \n");
      printf("3) Exit\n\n");
      
      printf("Enter selection: ");
      scanf("%d", &choice);
      printf("%d\n", choice);
   
     switch(choice){
        //Case 1: Dec to IEEE
        case 1:
        dec_to_ieee();
        break;
        
        //Case 2: IEEE to Dec
        case 2:
        ieee_to_dec();
        break;
        
        //Case 3: Quit
        case 3:
        printf("Exiting Program...");
        break;
        
        default:
        printf("Error: Invalid Choice. Try Again.\n");
        break;
        
      }//end switch
   }//end while
    
  return 0;
}//end main
