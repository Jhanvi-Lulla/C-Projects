#include<stdio.h>
#include<math.h>

// declaring prototype of functions

double division(double,double);
int modulus(int, int);
void print_menu();

int main()
{
int choice;
double first, second, result;
while(1)
{
print_menu();
scanf("%d", &choice);
if (choice == 7)
{
printf("\nExit!!");
break;
}
if (choice <1 || choice > 7)
{
printf("Invalid Menu Choice.\n");
continue;
}

printf("Enter first number : ");
scanf("%lf", &first);
printf("Enter second number : ");
scanf("%lf", &second);

switch (choice)
{
case 1: //Add
result = first + second;
break;

case 2: //Sub
result = first - second;
break;

case 3: //Multi
result = first * second;
break;

case 4: //Divide
result = division(first, second);
break;

case 5:
printf("\nResult of operation is : %d\n",
modulus((int)first, (int)second));
continue;   // important
/*
Flow:

Modulus print

continue → while loop ke top pe jump

Neeche wala printf("%.2f") skip ho jaata hai
*/

case 6: //Power
result = pow(first, second);
break;
}
if (!isnan(result))
{
printf("\nResult of operation is : %.2f\n", result);
}

};
return 0;
}

double division(double a, double b)
{
if (b==0) 
{
printf("Cannot be divided by Zero\n");
return 0;
}
else return a/b;
}

int modulus(int a, int b)
{
if (b==0) 
{
printf("Invalid Argument for Modulus\n");
return 0;
}
else return a%b;
}

void print_menu()
{
printf("\n*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*\n");
printf("Welcome to simple calculator\n");
printf("Choose any of the given options: \n");
printf("1. Add\n");
printf("2. Subtract\n");
printf("3. Multiply\n");
printf("4. Divide\n");
printf("5. Modulus\n");
printf("6. Power\n");
printf("7. Exit\n");
printf("Enter your choice\n");

}