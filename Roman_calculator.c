/* ---------------------------------------------------------------------------
** This software is developed for the purpose of code test.
**
** Filename: Roman_calculator.c
** Purpose: This file is the entry point for Roman Calculator software.
**
** Author: Muralidhar Rao Sunkari
** Version: 1.0
** -------------------------------------------------------------------------*/
/* Header Files */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Roman_to_dec.h"
#include "Dec_to_roman.h"
#include "Check_string.h"

#define DEV_CODE 1
#define TEST_CODE 2
#define INVALID -1
#define LOOP_EXIT 10
#define SUCCESS 3
#define FAIL 4
 
/* External functions */
extern int Roman_to_dec(char romanval[10]);
extern int Dec_to_roman(int);
extern int check_string(char romanstring[]);

/* External variables */
/* None */

/* Internal functions */
int main(void);
int Roman_calculator(char input1[10], char input2[10], char addsub);

/* Global variables */

int converted_dec1 = 0; /*Variable to capture roman number1 converted to decimal */
int converted_dec2 = 0; /*Variable to capture roman number2 converted to decimal */
int calculated_decimal = 0; /*Calculated decimal value after addition or substraction */

/* -------------------------------------------------------------------------
** Function: main()
** Description: This is the entry function for the roman calculator software.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
int main() {
	int status = INVALID;
	char repeat_status = '#';
	char retry = '#';
	int executionstatus = INVALID;
	char roman_input1[10] = {'#'};
	char roman_input2[10] = {'#'};
	char addsub = '#';
    	
	while (status != LOOP_EXIT) {
		printf("Enter 1 for Roman Calculator or 2 for Tests: ");
		scanf("%d", &executionstatus);
		
		if (executionstatus == DEV_CODE){
			
			printf("Enter the first roman num (valid digits are I, V, X, L, C, D, M): ");
        	scanf("%s", roman_input1);

			printf("Enter the second roman num (valid digits are I, V, X, L, C, D, M): ");
        	scanf("%s", roman_input2);
			
			printf("Enter '+' for addition or '-' for substraction: ");
    		scanf("%s", &addsub); 
	
			/*primary function call */
			status = Roman_calculator(roman_input1, roman_input2, addsub); 
	    }		
		else if (executionstatus == TEST_CODE){
			
			/*Test setup function call */
			Start_Test();
		}
		else {
			
			printf("The choice selected is not available.\n");
		}
		
		printf("********************************************\n\n");
		printf("Press 'Q' or 'q' to exit or any other character to continue.\n");
		scanf(" %s", &repeat_status);
		printf("********************************************\n\n\n");
					
		if ((repeat_status == 'Q') || (repeat_status == 'q')) {
			
			status = LOOP_EXIT;
		}
	}	
} 
/* -------------------------------------------------------------------------
** Function: Roman_calculator()
** Description: This is the primary function which initiates the user inputs
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
int Roman_calculator(char input1[], char input2[], char addsub){
	
     /* First number validity check */
	    if (check_string(input1) > 0){
    	printf("\nError: The roman number %s entered is invalid.\n\n",input1 );
    	return FAIL;

    }
    
    /* Second number validity check */
    if (check_string(input2) > 0){
       	printf("\nError: The roman number entered %s is invalid.\n\n", input2);
       	return FAIL;

    }
    
	/* Convert roman to decimal */
	converted_dec1 = Roman_to_dec(input1);
	converted_dec2 = Roman_to_dec(input2);
	    
	if (addsub == '+') 
		calculated_decimal = converted_dec1 + converted_dec2;
	else if (addsub == '-') 
		calculated_decimal = converted_dec1 - converted_dec2;
	else {
		printf("\nError: The operator entered is invalid.\n");
		return FAIL;
		
	}

	/* Convert calculated decimal to roman */
	if (Dec_to_roman(abs(calculated_decimal)) == 1) {
		return FAIL;
		
	}

	return SUCCESS;
}/* End of function */
