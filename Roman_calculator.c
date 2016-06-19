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
 
/* External functions */
extern int Roman_to_dec(char romanval[10]);
extern int Dec_to_roman(int);
extern int check_string(char romanstring[]);

/* External variables */
/* None */

/* Internal functions */
int main(void);
int Roman_calculator(void);

/* -------------------------------------------------------------------------
** Function: main()
** Description: This is the entry function for the roman calculator software.
** Return: Integer
** Arguments: None
**
** -------------------------------------------------------------------------*/
int main() {
	int status = 0;
	char repeat_status;
	
	while (status != 1) {
		status = Roman_calculator(); /*primary function call */
		printf("********************************************\n\n");
		printf("Press 'Q' or 'q' to exit or any other character to continue.\n");
		scanf("%s", &repeat_status);
		printf("********************************************\n\n\n");		
		
		if ((repeat_status == 'Q') || (repeat_status == 'q')) {
			status = 1;
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
int Roman_calculator(void){
	
    char roman_input1[10], roman_input2[10], operator; /*Input Variables */ 
    int converted_dec1 = 0; /*Variable to capture roman number1 converted to decimal */
    int converted_dec2 = 0; /*Variable to capture roman number2 converted to decimal */
    int calculated_decimal = 0; /*Calculated decimal value after addition or substraction */
    
    /* First number capture and validity check */
	printf("Enter the first roman num (valid digits are I, V, X, L, C, D, M):\n");
    scanf("%s", roman_input1);
	
    if (check_string(roman_input1) > 0){
    	printf("\nError: The roman number entered is invalid.\n\n");
    	return 1;

    }
    
    /* Second number capture and validity check */
	printf("Enter the second roman num (valid digits are I, V, X, L, C, D, M):\n");
    scanf("%s", roman_input2);
	
    if (check_string(roman_input2) > 0){
       	printf("\nError: The roman number entered is invalid.\n\n");
       	return 1;

    }
    
	/* Convert roman to decimal */
	converted_dec1 = Roman_to_dec(roman_input1);
	converted_dec2 = Roman_to_dec(roman_input2);
	    
	/* Operator capture */
    printf("Enter '+' for addition or '-' for substraction: \n");
    scanf("%s", &operator); 

	if (operator == '+') 
		calculated_decimal = converted_dec1 + converted_dec2;
	else if (operator == '-') 
		calculated_decimal = converted_dec1 - converted_dec2;
	else {
		printf("\nError: The operator entered is invalid.\n");
		return 1;
		
	}

	/* Convert calculated decimal to roman */
	if (Dec_to_roman(abs(calculated_decimal)) == 1) {
		return 1;
		
	}

	return 0;
}/* End of function */
