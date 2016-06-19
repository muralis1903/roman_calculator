/* ---------------------------------------------------------------------------
** This software is developed for the purpose of code test.
**
** Filename: main.c
** Purpose: This file contains functions used to convert roman number to decimal.
**
** Author: Muralidhar Rao Sunkari
** Version: 1.0
** -------------------------------------------------------------------------*/
/* Header Files */
#include <stdio.h>
#include <string.h>
#include "Roman_to_dec.h"
 
/* Internal functions */
int digit(char);
int Roman_to_dec(char romanval[10]);
 
/* -------------------------------------------------------------------------
** Function: Roman_to_dec()
** Description: This function convert roman to decimal.
** Return: Integer
** Arguments: String: Roman number
**
** -------------------------------------------------------------------------*/
int Roman_to_dec(char romanval[10]) {

    int i = 0; /* counter to loop through string */
    /*long int number = 0; */ 
    int length = strlen(romanval); /* Variable to capture string length */
    int numarray[10] = {0}; /*Array to capture decimal equvalent of roman character */
    int decimal_output = 0; /* Calculated decimal output */
	
    /* Loop to calculate decimal equvalent */
	for( i =0; i <= length; i++) {
		
		if (digit(romanval[i]) >=0) {
    		numarray[i] = digit(romanval[i]);
 		}
    }

    i = 0; /*reset counter */
	
    /* Loop to calculate If a lesser numeral is put before a bigger */
    while (length!=0) {
		
		if (numarray[i] < numarray[i+1]) {
			decimal_output = decimal_output + (numarray[i+1] - numarray[i]);
			i = i+2;
		}
		
		else {

			decimal_output = decimal_output + numarray[i];
			i++;
		}

        length--;
    }
    
    /* printf("Its decimal value is : %d\n", decimal_output); */
    return decimal_output;
}
 
/* -------------------------------------------------------------------------
** Function: digit()
** Description: This function returns decimal equvalent of roman character.
** Return: Integer
** Arguments: character: Roman char
**
** -------------------------------------------------------------------------*/
int digit(char c)
{
    int value = 0;
    switch (c) {
    case 'I':
        value = 1;
        break;
    case 'V':
        value = 5;
        break;
    case 'X':
        value = 10;
        break;
    case 'L':
        value = 50;
        break;
    case 'C':
        value = 100;
        break;
    case 'D':
        value = 500;
        break;
    case 'M':
        value = 1000;
        break;
    case '0':
        value = 0;
        break;
    default:
        value = -1;
    }

    return value;
}
