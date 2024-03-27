/*
Program for reading  a file of integers into an array
that is created 
with the first integer telling you how many to read.
*/

/*For the standard intput io related , data type and 
file related operation to do in the program*/
#include <stdio.h> 
#include <stdlib.h> // for the exit() and malloc()
#define MAX(x, y) (x > y ? x : y) // MACRO for lenient flow of code

/*Main PrograM starts from here*/
int main()
{
	/*Initialize the file pointer with the NULL*/
	FILE *toRead = NULL , *toWrite=NULL ;
	/*Opening the inputdata.txt file for storing the elemnts in data[]*/
	toRead = fopen ("rata.txt" , "r");
	/*Opening the answer-hw.txt file for storing the final output in it.*/
	toWrite = fopen ("answer-hw3.txt","w");

	/*
	*	Element  ----> variable is for finding all the available int elements in the file
	*	loop  -------> variable is used for the displaying the specific element of array data[]
	*	prev_number -> variable is used for stroing the previous element to find max
	*/
	int element = 0 , max =0;
	int prev_num=0;
	/*
	*	Sum ------> variable is for finding sum  of all the elements in data[]
	*	average --> variable is used for the finding the average of the array and store it into another file
	*/
	double sum =0,average=0;
	
	
	
	/*inputdata.txt file is available or not available checking. If the file is not available than not to do any function*/
	if (toRead == NULL)
	{
		printf("Getting an error while reading a file\r\n");
		exit(0); //exit from the main file as the file is not present
	}
	else
	{
		printf("File open sucessfully \r\n");
	}
	/*As per defination of the program first int element in the file will tell us the total available elements in the file*/
	fscanf(toRead,"%d",&element);
	printf("%d\n",element);
	/*As the elements may vary as per the user input we have created dynamic array  for the array.*/
	int datad[element];
    /*Data is the Dynamic memory for data[]. The pointer should be initialize with the NULL*/
	
    printf("data:\n",datad);
	
	/*copy the elements to the dynamic memory of the data in the form of int we used fscanf()*/
	for(int i=1;i<element+1;i++)
	{   
        
		fscanf(toRead,"%d",&datad[i]) !=1;
		printf("Element %d: %d \r\n",i,datad[i]); // as per the given input need to print all the elements on std o/p.
		sum = sum + (double)(datad[i]); // fining the sum for the average calculation 
		max=MAX(prev_num,datad[i]);
        prev_num=datad[i];
		
	}

    
	/*finding the average of the all the elements in the data[] from the file*/
	average =  sum / element;
    
	/*Printing the MAX  value and average value on std o/p as per given assignment*/
	printf("Average - %f and MAX - %d",average,max);
	/*Storing the MAX  value and average value to the o/p file*/
	fprintf(toWrite,"Average - %f and MAX - %d",average,max);
	
	/*closing both the files.*/
	fclose(toRead);
	fclose(toWrite);
}