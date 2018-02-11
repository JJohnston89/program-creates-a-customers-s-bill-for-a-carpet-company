/* This program creates a customers's bill for a carpet company. The program prompts a user for length of the room in feet,
   width of the room in feet, customer discount in percent, and the cost per square foot. The program calculates the area, 
   carpet cost, labor cost, installed price, discount, subtotal, tax, and total. Then the program prints out the measurements, and the charges.
      Written by: Joshua Johnston
      Data: 10/9/2014
*/


#include<stdio.h>

#define TAX_RATE 8.50 
#define LABOR_COST 0.35

//Function Declarations
void getData (int* length, int* width, int* discount, float* costPerSQFt);

void calculate_values(int length, int width, int discount, float costPerSQFt, int* area, float* carpet_cost, 
	              float* total_labor_cost, float* install_price, float* Subtotal, float* Final_discount, 
		      float* tax, float* Total_Price);

void Calculate_Install_Price (int length, int width, float costPerSQFt, int* area, 	 
	                      float* carpet_cost, float* total_labor_cost, float* install_price);

void Calculate_Subtotal(int discount, float install_price, float* Subtotal, float* Final_discount);

void Calculate_Total_Price(float Subtotal, float* tax, float* Total_Price);

void print_result(int length, int width, int area, float costPerSQFt, float carpet_cost, 
	         float total_labor_cost, float install_price, int discount, float Final_discount, 	
	         float Subtotal, float tax, float Total_Price);

void print_measurements(int length, int width, int area);

void print_charges(float costPerSQFt, float carpet_cost, 
	           float total_labor_cost, float install_price, int discount, float Final_discount, 	
	           float Subtotal, float tax, float Total_Price);


int main(void)
{

//      Local Declarations

	int length;
	int width;
	int area;
	int discount;

	float costPerSQFt;
	float install_price;
	float carpet_cost;
	float total_labor_cost;
	float Subtotal;
	float Total_Price;
	float Final_discount;
	float tax;

//      Statements

	getData(&length, &width, &discount, &costPerSQFt);
	
	calculate_values(length, width, discount, costPerSQFt, &area, &carpet_cost, 
	                 &total_labor_cost, &install_price, &Subtotal, &Final_discount,
			 &tax, &Total_Price);
	
	print_result(length, width, area, costPerSQFt, carpet_cost, 
	             total_labor_cost, install_price, discount,  Final_discount, 	
	             Subtotal, tax, Total_Price);

 
   return 0;
} // main

/* ===========================getData=========================================
   This function reads three integers, and one real from the keyboard into variables
   specified in the parameter list.
     Pre Nothing.
     Post Data read and placed in calling function.
*/

void getData (int* length, int* width, int* discount, float* costPerSQFt)
{
//      Statements

	printf("Please enter length of the room (feet): ");
	scanf("%d", length);

	printf("Please enter width of the room (feet): ");
	scanf("%d", width);

	printf("Please enter your customer discount (percent): ");
	scanf("%d", discount);

	printf("Please enter the cost per square foot (xxx.xx): ");
	scanf("%f", costPerSQFt);

	return;
} // getData

/*  ===========================================calculate_values===================================================
     This function calls three sub functions to do calculations. 
	     Pre  length, width, discount contain integer values, and costPerSQFt contain real value.
	     Post  area, carpet_cost, total_labor_cost, install_price, Subtotal, Final_discount, tax, 
		   and Total_Price are calculated in the sub functions.
*/

void calculate_values(int length, int width, int discount, float costPerSQFt, int* area, float* carpet_cost, 
	              float* total_labor_cost, float* install_price, float* Subtotal, float* Final_discount, 
		      float* tax, float* Total_Price )
{ 
	
	
//      tatements

	Calculate_Install_Price(length, width, costPerSQFt, area, carpet_cost, total_labor_cost, install_price);
	
	Calculate_Subtotal( discount, *install_price, Subtotal, Final_discount);
	
	Calculate_Total_Price(*Subtotal, tax, Total_Price);
	

	return;

} // calculate_values

/*  ===================================Calculate_Install_Price==============================================
     This function calculates area, carpet_cost, total_labor_cost, and installed_price, and then places the 
	   area, carpet_cost, total_labor_cost, and install_price into the calling program variables.
	    Pre length and width contain integer values, and costPerSQFt contain real value.
	    Post area, carpet_cost, total_labor_cost, and install_price are calculated.
*/


 void Calculate_Install_Price (int length, int width, float costPerSQFt, int* area, float* carpet_cost, 
                               float* total_labor_cost, float* install_price)
{ 
	
//      Statements

	*area = length * width;
	*carpet_cost = *area * costPerSQFt;
	*total_labor_cost = LABOR_COST * *area;
	*install_price = *carpet_cost + *total_labor_cost;

	return;
} // Calculate_Install_Price

/*  ===============================Calculate_Subtotal===============================================
     This function calculates the Final_discount, and Subtotal.
	    Pre discount contain integer value, and install_price contain real value.
	    Post Subtotal, and Final_discount calculated.
*/

void Calculate_Subtotal(int discount, float install_price, float* Subtotal, float* Final_discount)
{ 

//      Statements
	
	*Final_discount = install_price * ((float)discount / 100);
	*Subtotal = install_price - *Final_discount;

	return;

} // Calculate_Subtotal

/*  =============================Calculate_Total_Price======================
     This function calculates the tax, and the Total_Price.
	  Pre Subtotal contains real value.
	  Post tax, and Total_Price is calculated.
*/

void Calculate_Total_Price (float Subtotal, float* tax, float* Total_Price)
{

//      Statements

	*tax = Subtotal * TAX_RATE / 100;
	*Total_Price= *tax + Subtotal;

	return;

} // Calculate_Total_Price

/*  =======================================print_result===============================================
     This function calls two sub functions to print.
*/
 
void print_result(int length, int width, int area, float costPerSQFt, float carpet_cost, 
	          float total_labor_cost, float install_price, int discount, float Final_discount, 	
	          float Subtotal, float tax, float Total_Price)
{

//      Statements

	print_measurements(length, width, area);
	
	print_charges(costPerSQFt, carpet_cost, total_labor_cost, install_price, discount, Final_discount, 	
	              Subtotal, tax, Total_Price);

	return;
} // print_result

/*  =================print_measurements===================
     This function prints measurements.
	  Pre length, width, and area contain integer values.
	  Post length, width, and area are printed.
*/

void print_measurements(int length, int width, int area)
{

//      Statements

	printf("\t\tMEASUREMENT \n\n");
	printf("Length \t\t\t\t   %4d ft\n", length);
	printf("Width \t\t\t           %4d ft\n", width);
	printf("Area  \t\t\t           %4d square ft\n\n", area);

	return;
} // print_measurements

/*  =============================print_charges========================================================
     This function prints the charges.
	  Pre costPerSQFt, carpet_cost, total_labor_cost, install_price, Final_discount, Subtotal, tax, 
	      Total_Price contain real values, and discount contain integer value. 
	  Post costPerSQFt, carpet_cost, total_labor_cost, install_price, Final_discount, Subtotal, tax, 
	       Total_Price, and discount are printed.
*/


void print_charges(float costPerSQFt, float carpet_cost, 
	           float total_labor_cost, float install_price, int discount, float Final_discount, 	
	           float Subtotal, float tax, float Total_Price)
{

//      Statements

	printf("\t\t  CHARGES \n\n");
	printf("Description  Cost/SQ.Ft.      Charge\n\n");
	printf("-----------  -----------  -----------\n");
	printf("Carpet     %10.2f      %10.2f\n", costPerSQFt, carpet_cost);
	printf("Labor            %4.2f      %10.2f\n\n", LABOR_COST, total_labor_cost);
	printf("                          -----------\n\n");
	printf("Installed Price            %10.2f\n", install_price);
	printf("Discount          %3d%%     %10.2f\n\n", discount, Final_discount);
	printf("                          -----------\n\n");
	printf("Subtotal                   %10.2f\n", Subtotal);
	printf("Tax                        %10.2f\n", tax);
	printf("Total                      %10.2f\n", Total_Price);

	return;
} // print_charges
