/* ---------------------------------------------------------------------------
** This software is developed for the purpose of code test.
**
** Filename: Check_string.c
** Purpose: This file contains functions which checks roman number correctness.
**
** Author: Muralidhar Rao Sunkari
** Version: 1.0
** -------------------------------------------------------------------------*/
/* Header Files */
#include "Check_string.h"
	
/* Internal functions */
int check_string(char romanstring[]);

/* -------------------------------------------------------------------------
** function: check_string()
** Description: This function checks entered roman number validity.
** Return: Integer, -1 if invalid
** Arguments: String
**
** -------------------------------------------------------------------------*/

int check_string(char romanstring[]){
	
	int i = 0; /*counter used for characters in input string */
	int j = 0; /*counter used to loop */
	int len = strlen(romanstring); /*length of input string */
	int count_i = 0; /* counter to count number of I characters */
	int count_x = 0; /* counter to count number of X characters */
	int count_c = 0; /* counter to count number of C characters */
	int count_v = 0; /* counter to count number of V characters */
	int count_l = 0; /* counter to count number of L characters */
	int count_d = 0; /* counter to count number of D characters */
	int return_status = 0;
	
	/* loop to check number of occurrences of I or X or C */
	for(j = 0; j < 3; j++){
		
		count_i = 0;
		count_x = 0;
		count_c = 0;
		count_v = 0;
		count_l = 0;
		count_d = 0;
			
		for(i = 0; i < len; i++){
			
		    if(romanstring[i] == 'I') 
    			count_i++; 
				
    		else if(romanstring[i] == 'X') 
    			count_x++; 
				
    		else if(romanstring[i] == 'C') 
    			count_c++; 
				
    		else if(romanstring[i] == 'V') 
    			count_v++; 
				
    		else if(romanstring[i] == 'L') 
    			count_l++; 
				
    		else if(romanstring[i] == 'D') 
			    count_d++;
			
			else if (romanstring[i] != 'M'){
				return_status = 1;	
			}
			      
		}
		/*If I/X/C occurrence is more than 3 or V/L/D occurence
		 is more than once then flag invalid input */
		if ((count_i > 3) || (count_x > 3) || (count_c > 3) || 
		(count_v > 1) || (count_l > 1) || (count_d > 1)) {
			return_status = 1;	
		}
			
	}
	return return_status;
}
