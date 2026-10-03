#include <stdio.h>

int calculateRoomCharge(int days, int choice)
{
    int price;

    if (choice == 1)
        price = 2000;
    else if (choice == 2)
        price = 3500;
    else
        price = 5000;

    return price * days;
}

float calculateDiscount(int days, int roomCharge)
{
    float discount;

    if (days < 4)
        discount = 0;
    else if (days <= 7)
        discount = roomCharge * 0.10;
    else
        discount = roomCharge * 0.15;

    return discount;
}

float calculateFoodCharge(int days, int foodChoice)
{
    if (foodChoice == 1)
        return 300 * days;
    else
        return 0;
}

int main()
{
    int choice, days, rooms, foodChoice;
    int roomCharge;
    float discount, foodCharge, finalAmount;

    printf("====================================\n");
    printf("       HOTEL BOOKING SYSTEM\n");
    printf("====================================\n");

    printf("\nRoom Types:\n");
    printf("1. Standard Room - Rs.2000/day\n");
    printf("2. Deluxe Room   - Rs.3500/day\n");
    printf("3. Suite         - Rs.5000/day\n");

    printf("\nEnter room choice: ");
    scanf("%d", &choice);

    if (choice < 1 || choice > 3)
    {
        printf("Invalid room choice!\n");
        return 0;
    }

    printf("Enter number of rooms: ");
    scanf("%d", &rooms);

    printf("Enter number of days: ");
    scanf("%d", &days);

    printf("\nAdd breakfast?\n");
    printf("1. Yes - Rs.300/day per room\n");
    printf("2. No\n");

    printf("Enter choice: ");
    scanf("%d", &foodChoice);

    if (foodChoice < 1 || foodChoice > 2)
    {
        printf("Invalid food choice!\n");
        return 0;
    }

    roomCharge = calculateRoomCharge(days, choice);
    roomCharge = roomCharge * rooms;

    discount = calculateDiscount(days, roomCharge);

    foodCharge = calculateFoodCharge(days, foodChoice);
    foodCharge = foodCharge * rooms;

    finalAmount = roomCharge + foodCharge - discount;

    printf("\n====================================\n");
    printf("             HOTEL BILL\n");
    printf("====================================\n");

    printf("Room Type: ");

    if (choice == 1)
        printf("Standard Room\n");
    else if (choice == 2)
        printf("Deluxe Room\n");
    else
        printf("Suite\n");

    printf("No. of Rooms : %d\n", rooms);
    printf("No. of Days  : %d\n", days);

    printf("\nRoom Charge  : Rs.%.2f\n", (float)roomCharge);
    printf("Breakfast    : Rs.%.2f\n", foodCharge);

    printf("\n----- DISCOUNT DETAILS -----\n");

    if (days < 4)
    {
        printf("Stay: Less than 4 days\n");
        printf("Discount: 0%%\n");
    }
    else if (days <= 7)
    {
        printf("Stay: 4 to 7 days\n");
        printf("Discount: 10%%\n");
    }
    else
    {
        printf("Stay: More than 7 days\n");
        printf("Discount: 15%%\n");
    }

    printf("Discount Amount: Rs.%.2f\n", discount);

    printf("\n------------------------------------\n");
    printf("Final Amount: Rs.%.2f\n", finalAmount);
    printf("------------------------------------\n");

    printf("\nBooking Confirmed!\n");
    printf("Thank you for choosing our hotel!\n");

    return 0;
}