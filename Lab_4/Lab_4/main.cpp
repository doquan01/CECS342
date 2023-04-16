#include <stdio.h>
#include <stdlib.h>

struct Employee {
    void** vtable;
    int age;
};

struct HourlyEmployee {
    void** vtable;
    int age;
    double hourly_rate;
    double hours;
    // ……….. DONE

};
struct CommissionEmployee {
    void** vtable;
    int age;
    double sales_amount;

    //  ………… DONE

};
struct SeniorSalesman {
    void** vtable;
    int age;
    double sales_amount;
    //  ………………… DONE

};
void Speak_Hourly(struct Employee* employee) {
    struct HourlyEmployee* hourlyEmployee = (struct HourlyEmployee*)employee;
    //Display hourly rate
    printf("I work for %.2lf dollars per hour :(\n", hourlyEmployee->hourly_rate);
}

double GetPay_Hourly(struct Employee* employee) {
    struct HourlyEmployee* hourlyEmployee = (struct HourlyEmployee*)employee;
    return hourlyEmployee->hourly_rate;
    //  ……………………………. DONE

}
void Speak_Commission(struct Employee* employee) {
    struct CommissionEmployee* commissionEmployee = (struct CommissionEmployee*)employee;
    ///Display sales amount
    printf("I made commission on %.2lf dollars from sales!\n", commissionEmployee->sales_amount);
}

void GetPay_Commission(struct Employee* employee) {
    struct CommissionEmployee* commissionEmployee = (struct CommissionEmployee*)employee;
    //  ……………………………………………..; DONE
}

double GetPay_Senior(struct Employee* employee) {
    struct SeniorSalesman* seniorsalesman = (struct SeniorSalesman*)employee;
    double age_bonus = 0;
    if (seniorsalesman->age > 40)
        age_bonus = seniorsalesman->sales_amount * 0.05;
    return (seniorsalesman->sales_amount * 0.2 + 50000 + age_bonus);
    //  ………………………………………………………….. DONE

}
void* Vtable_HourlyEmployee[2] = { Speak_Hourly, GetPay_Hourly };

void* Vtable_CommisionEmployee[2] = { Speak_Commission,GetPay_Commission };
// ………………………………….. DONE 
void* Vtable_SeniorSalesman[2] = { Speak_Commission, GetPay_Senior };
// ………………………………….. DONE

struct HourlyEmployee Construct_Hourly(struct HourlyEmployee* hourlyEmployee) {
    struct HourlyEmployee x = *hourlyEmployee;
    hourlyEmployee->vtable = Vtable_HourlyEmployee;
    hourlyEmployee->age = 0;
    hourlyEmployee->hourly_rate = 0;
    hourlyEmployee->hours = 0;
    return x;
}

struct CommissionEmployee Construct_Commission(struct CommissionEmployee* commissionEmployee) {
    struct CommissionEmployee x = *commissionEmployee;
    commissionEmployee->vtable = Vtable_CommisionEmployee;
    commissionEmployee->age = 0;
    commissionEmployee->sales_amount = 0;
    //  …………………………………………………………… DONE
    return x;
}

struct SeniorSalesman Construct_Senior(struct SeniorSalesman* seniorSalesman) {
    struct SeniorSalesman x = *seniorSalesman;
    seniorSalesman->vtable = Vtable_SeniorSalesman;
    seniorSalesman->sales_amount = 0;
    // …………………………………………………………………….. DONE
    return x;
}


int main() {
    struct Employee* employee;
    // Display the selections. Validate the selection/

    // Input age
   //For hourly employee
    struct HourlyEmployee* pHourlyEmployee = (struct HourlyEmployee*)malloc(sizeof(struct HourlyEmployee));
    //Consturct pHourlyEmployee
    //Input hourly rate and hours

    employee = (struct Employee*)pHourlyEmployee;
    //Do the same for other employee types

    int age = 0; //added this

    employee->age = age;
    ((void (*)(struct Employee*)) employee->vtable[0])((struct Employee*)employee);

    //  …………………………………………………. DONE
    struct CommissionEmployee* pCommissionEmployee = (struct CommissionEmployee*)malloc(sizeof(struct CommissionEmployee));
    employee = (struct Employee*)pCommissionEmployee;
    employee->age = age;
    ((void (*)(struct Employee*)) employee->vtable[0])((struct Employee*)employee);

    return 0;
}
// ( (void *) (struct Employee *)) employee->vtable[0] ( (struct Employee *) employee)