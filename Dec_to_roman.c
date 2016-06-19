/* ---------------------------------------------------------------------------
** This software is developed for the purpose of code test.
**
** Filename: Dec_to_roman.c
** Purpose: This file contains functions used to convert decimal number to roman.
**
** Author: Muralidhar Rao Sunkari
** Version: 1.0
** -------------------------------------------------------------------------*/
/* Header Files */
#include<stdio.h>
#include "Dec_to_roman.h"

/* Internal functions */
void predigits(char c1,char c2);
void postdigits(char c,int n);

/* Global variables */
char roman_Number[10];
int i = 0;

/* -------------------------------------------------------------------------
** Function: Dec_to_roman()
** Description: This functions used to convert decimal number to roman.
** Return: Integer
** Arguments: Integer - calculated decimal
**
** -------------------------------------------------------------------------*/
int Dec_to_roman(int number){

    int j; /* counter */

    /* Roman numbers can range between 0 and 5000 */
    /* if((number <= 0) || (number > 4999)){
	if(number > 4999){
         printf("Invalid calculated value. The output exceeds 4999.\n\n");
         return 1;
    }
    */

	/* loop to convert decimal to equavalent roman number */
    while(number != 0){

         if(number >= 1000){
             postdigits('M',number/1000);
             number = number - (number/1000) * 1000;
         }
         else if(number >=500){
             if(number < (500 + 4 * 100)){
                 postdigits('D',number/500);
                 number = number - (number/500) * 500;
             }
             else{
                 predigits('C','M');
                 number = number - (1000-100);
             }
         }
         else if(number >=100){
             if(number < (100 + 3 * 100)){
                 postdigits('C',number/100);
                 number = number - (number/100) * 100;
             }
             else{
                 predigits('C','D');
                 number = number - (500-100);
             }
         }
         else if(number >=50){
             if(number < (50 + 4 * 10)){
                 postdigits('L',number/50);
                 number = number - (number/50) * 50;
             }
             else{
                 predigits('X','C');
                 number = number - (100-10);
             }
         }
         else if(number >=10){
             if(number < (10 + 3 * 10)){
                 postdigits('X',number/10);
                 number = number - (number/10) * 10;
             }
             else{
                 predigits('X','L');
                 number = number - (50-10);
             }
         }
         else if(number >=5){
             if(number < (5 + 4 * 1)){
                 postdigits('V',number/5);
                 number = number - (number/5) * 5;
             }
             else{
                 predigits('I','X');
                 number = number - (10-1);
             }
         }
         else if(number >=1){
             if(number < 4){
                 postdigits('I',number/1);
                 number = number - (number/1) * 1;
             }
             else{
                 predigits('I','V');
                 number = number - (5-1);
             }
         }
    }

	/* Print the calculated roman char by char */
    printf("The calculated roman number is: ");
    for(j = 0; j < i; j++){
    	if (roman_Number[j] != '~')
		{
	    	printf("%c",roman_Number[j]);
         	roman_Number[j] = '~';
    	}
    }

	printf("\n\n");
    return 0;

}
/* -------------------------------------------------------------------------
** Function: predigits()
** Description: This is the entry function for the roman calculator software.
** Return: None
** Arguments: chars used for output string build
**
** -------------------------------------------------------------------------*/
void predigits(char c1,char c2){
    roman_Number[i++] = c1;
    roman_Number[i++] = c2;
}

/* -------------------------------------------------------------------------
** Function: predigits()
** Description: This is the entry function for the roman calculator software.
** Return: None
** Arguments:  char used for output string build and number of chars
**
** -------------------------------------------------------------------------*/
void postdigits(char c,int n){
    int j;
    for(j=0;j<n;j++)
         roman_Number[i++] = c;
   
}
