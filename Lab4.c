#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Employee {
 void **vtable;
 int age;
};

struct HourlyEmployee {
 void **vtable;
 int age;
 double hourly_rate;
 double hours;
// ……….. DONE

};
struct CommissionEmployee {
  void **vtable;
  int age;
  double sales_amount;

//  ………… DONE

};
struct SeniorSalesman {
  void **vtable;
  int age;
  double sales_amount;
//  ………………… DONE

};
void Speak_Hourly(struct Employee *employee) {
 struct HourlyEmployee *hourlyEmployee = (struct HourlyEmployee *) employee;
 //Display hourly rate
 printf("I work for %.2lf dollars per hour :(\n", hourlyEmployee->hourly_rate);
}

double GetPay_Hourly(struct Employee *employee) {
  struct HourlyEmployee *hourlyEmployee = (struct HourlyEmployee *) employee;
  return hourlyEmployee->hourly_rate * hourlyEmployee->hours;
//  ……………………………. DONE

}
void Speak_Commission(struct Employee *employee) {
 struct CommissionEmployee *commissionEmployee = (struct CommissionEmployee *) employee;
///Display sales amount
 printf("I made commission on %.2lf dollars from sales!\n", commissionEmployee->sales_amount);
}

double GetPay_Commission(struct Employee *employee) { 
  struct CommissionEmployee *commissionEmployee = (struct CommissionEmployee *) employee;
  return (0.1 * commissionEmployee->sales_amount) + 40000;
//  ……………………………………………..; DONE
}

double GetPay_Senior(struct Employee *employee) {
  struct SeniorSalesman *seniorsalesman = (struct SeniorSalesman *) employee;
  double age_bonus = 0;
  if(seniorsalesman->age >= 40)
    age_bonus = seniorsalesman->sales_amount*0.05;
  return (seniorsalesman->sales_amount*0.2 + 50000 + age_bonus);
//  ………………………………………………………….. DONE

}
void *Vtable_HourlyEmployee[2] = {Speak_Hourly, GetPay_Hourly};

void *Vtable_CommisionEmployee[2] = {Speak_Commission, GetPay_Commission};
// ………………………………….. DONE 
void *Vtable_SeniorSalesman[2] = {Speak_Commission, GetPay_Senior};
// ………………………………….. DONE

struct HourlyEmployee Construct_Hourly(struct HourlyEmployee *hourlyEmployee) {
 hourlyEmployee->vtable = Vtable_HourlyEmployee;
 hourlyEmployee->age = 0;
 hourlyEmployee->hourly_rate = 0;
 hourlyEmployee->hours = 0;
}

struct CommissionEmployee Construct_Commission(struct CommissionEmployee *commissionEmployee) {
commissionEmployee->vtable = Vtable_CommisionEmployee;
commissionEmployee->age = 0;
commissionEmployee->sales_amount = 0;
//  …………………………………………………………… DONE
}

struct SeniorSalesman Construct_Senior(struct SeniorSalesman *seniorSalesman) {
  seniorSalesman->vtable = Vtable_SeniorSalesman;
  seniorSalesman->sales_amount = 0;
// …………………………………………………………………….. DONE
}


int main() {
char userInt = 0;
struct Employee *employee = (struct Employee*) malloc(sizeof(struct Employee));
 // Display the selections. Validate the selection/
int testInt;
while(isdigit(userInt) == false || testInt < 0 || testInt >= 4){
	printf("Choose an Employee type by number selection:\n1 Hourly Employee \n2 Commission Employee\n3 Senior Salesman\n");
	scanf(" %c", &userInt);
	testInt = userInt - '0';
	
	if(testInt == 1 || testInt == 2 || testInt == 3){
		break;
	}else{
		printf("Invalid selection.");
		printf("Choose an Employee type by number selection:\n1 Hourly Employee \n2 Commission Employee\n3 Senior Salesman\n");
		scanf(" %c", &userInt);
		testInt = userInt - '0';
	}
}

// Input age
int age;
printf("How old is the employee?\n");
scanf(" %d", &age);

if(testInt == 1){
	//For hourly employee
	struct HourlyEmployee *pHourlyEmployee = (struct HourlyEmployee *) malloc(sizeof(struct HourlyEmployee));
	//Consturct pHourlyEmployee
	//Input hourly rate and hours
	Construct_Hourly(pHourlyEmployee);
	double rate, hours;
	printf("Enter the Employee's pay rate.\n");
	scanf(" %lf", &rate);
	printf("Enter the Employee's hours.\n");
	scanf(" %lf", &hours);
	
	
	employee = (struct Employee *) pHourlyEmployee;
	//Do the same for other employee types
	pHourlyEmployee->age = age;
	pHourlyEmployee->hourly_rate = rate;
	pHourlyEmployee->hours = hours;
	
	employee = realloc(employee, sizeof(struct HourlyEmployee));
	employee = (void*) pHourlyEmployee;
	
}
else if(testInt == 2){
	struct CommissionEmployee *pCommissionEmployee = malloc(sizeof(struct CommissionEmployee));
	Construct_Commission(pCommissionEmployee);
	double sales_amount;
	printf("What is the Employee's amount of sales\n");
	scanf(" %lf", &sales_amount);
	
	pCommissionEmployee->age = age;
	pCommissionEmployee->sales_amount = sales_amount;
	
	employee = realloc(employee, sizeof(struct CommissionEmployee));
	employee = (void*) pCommissionEmployee;
}
else if(testInt == 3){
	struct SeniorSalesman *pSeniorSalesman = malloc(sizeof(struct SeniorSalesman));
	Construct_Senior(pSeniorSalesman);
	double sales_amount;
	printf("What is the Employee's amount of sales\n");
	scanf(" %lf", &sales_amount);
	
	pSeniorSalesman->age = age;
	pSeniorSalesman->sales_amount = sales_amount;
	
	employee = realloc(employee, sizeof(struct SeniorSalesman));
	employee = (void*) pSeniorSalesman;
}

((void (*)(struct Employee *)) employee->vtable[0])((struct Employee *) employee);
double paid = ((double (*)(struct Employee*)) employee->vtable[1])((struct Employee *) employee);

printf("This Employee made $%.2f\n", paid);

free(employee);
return 0;
}
// ( (void *) (struct Employee *)) employee->vtable[0] ( (struct Employee *) employee)
