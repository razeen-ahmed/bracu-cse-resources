#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <string.h>



struct Item{

	char name[20];
	int quantity;
	int price;
};


int main(){

	struct Item paratha;
	struct Item vegetable;
	struct Item drink;
	
	int people;
	double calc;
	
	strcpy(paratha.name, "Paratha");
	
	strcpy(vegetable.name,"Vegetables");
	
	strcpy(drink.name,"Mineral Water");
	
	printf("Qunatity of %s:",paratha.name);
	scanf("%d",&paratha.quantity);
	printf("Unit Price:");
	scanf("%d",&paratha.price);
	
	printf("\n");
	
	printf("Qunatity of %s:",vegetable.name);
	scanf("%d",&vegetable.quantity);
	printf("Unit Price:");
	scanf("%d",&vegetable.price);
	printf("\n");
	
	printf("Qunatity of %s:",drink.name);
	scanf("%d", &drink.quantity);
	printf("Unit Price:");
	scanf("%d",&drink.price);
	printf("\n");
	
	printf("Number of people:");
	scanf("%d",&people);
	printf("\n");
	
	
	//printf("%d %d",paratha.price, drink.price);
	
	calc = ((vegetable.quantity*vegetable.price)+ (paratha.quantity*paratha.price) + (drink.quantity*drink.price))/people;

        
        printf("Individual people will pay: %.2f tk",calc);
        
	return 0;
	
}









