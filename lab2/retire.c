#include <stdio.h>
#include <stdlib.h>
#define SALARY 100000 // $100K/year
void main(int argc, char *argv[])
{
    int after_tax_distribution = 0;
    int age = 0;
    int amount;
    int distribution = 0;
    int i = 0;
    int matching_401k_amount = 0;
    int max_matching_401k_amount = 0;
    int principle = 0;
    int roth_distribution = 0; // Need to determine.
    int taxes = 0;
    int taxable_distribution;
    int total_saved = 0;
    int yearly_401k_contribution = 0;
    if (argc < 2) {
        printf("Missing input parameters to retire program.\n");
        printf("Usage: retire age_starting dollar_saved_per_month\n");
        exit(0);
    }
    age = atoi(argv[1]);
    amount = atoi(argv[2]);
    printf("\n");
    printf("Welcome to Your Retirement Calculator\n");
    printf("-----------------------------------------------------------------\n");
    printf(" 1. You start saving at age %d.\n", age);
    printf(" 2. The amount saved per month is $%d.\n", amount);
    printf("-----------------------------------------------------------------\n");
    for (i=age;i<65;i++) {
        yearly_401k_contribution = 12 * amount;
        principle = principle + yearly_401k_contribution;
        // 6% of salary is matched at 50%.
        max_matching_401k_amount = SALARY * .06;
        if (yearly_401k_contribution >= max_matching_401k_amount)
            matching_401k_amount = 0; // NEED TO CORRECT
        else
            matching_401k_amount = 0; // NEED TO CORRECT
                                      // 1.107 is 10.7%, the average gain over 30 years in an S&P Index Fund.
        total_saved = (total_saved + (12 * amount)) * 1.107 + matching_401k_amount;
        printf("At age %d, principle = $%d, total saved = $%d\n",
                i, principle, total_saved);
    }
    printf("-----------------------------------------------------------------\n");
    printf("From age %d to 65, if $%d is saved per month:\n", age, amount);
    printf(" The principle amount you contributed is : $%d\n", principle);
    printf(" The principle amount + your gains is : $%d\n", total_saved);
    printf("-----------------------------------------------------------------\n");
    printf("\n");
    printf("-----------------------------------------------------------------\n");
    printf("But how much money will I receive per year from 65 to 95?\n");
    printf("-----------------------------------------------------------------\n");
    int before_tax_distribution = total_saved/(95-65);
    // THE IF STATEMENTS BELOW ARE BASED ON 2022 TAX TABLES.
    // NEED TO UPDATE AND CORRECT FOR 2023 TAX TABLES.
    if (distribution <= 10275)
        taxes = distribution * 0.10; // 10%
    else if (distribution <= 41775)
        taxes = 0; // 12%
    else if (distribution <= 89075)
        taxes = (10275*0.10) + (41775-10275)*.12 + (distribution-41775)*.22; // 22%
    else if (distribution <= 170050)
        taxes = 0; // 24%
    else if (distribution <= 215950)
        taxes = 0; // 32%
    else if (distribution <= 539900)
        taxes = 0; // 35%
    else
        taxes = 0; // 37%
    after_tax_distribution = before_tax_distribution - taxes;
    roth_distribution = 0;
    printf("Distribution before taxes is: $%d\n", distribution);
    printf("Distribution from a 401k account is: $%d\n", after_tax_distribution);
    printf("Distribution from a ROTH account is: $%d\n", roth_distribution);
    printf("-----------------------------------------------------------------\n");
}
