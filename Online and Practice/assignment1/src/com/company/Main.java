package com.company;

import java.util.Scanner;

public class Main
{

    public static void main(String[] args) {
	    Account acc = new Account(5000.50);
        System.out.println("Your primary account balance is " + acc.getBalance());
	    while(true)
        {
            System.out.println("Choose an option to proceed: ");
            System.out.println("1. Credit balance\n2. Debit Balance\n3. See Balance\n4. Exit");
            Scanner sc = new Scanner(System.in);
            int choice = sc.nextInt();
            switch (choice)
            {
                case 1:
                    while(true)
                    {
                        System.out.println("Enter an amount to credit");
                        double amount = sc.nextDouble();
                        try {
                            acc.credit(amount);
                            break;
                        } catch (InvalidAmountException e)
                        {
                            System.out.println(e);
                        }
                    }
                    break;
                case 2:
                    while(true)
                    {
                        System.out.println("Enter an amount to debit");
                        double amount = sc.nextDouble();
                        try {
                            acc.debit(amount);
                            break;
                        } catch (InvalidAmountException e)
                        {
                            System.out.println(e);
                        } catch (InvalidBalanceException e)
                        {
                            System.out.println(e);
                        }
                    }
                    break;
                case 3:
                    System.out.println(acc.getBalance());
                    break;
                case 4:
                    break;
                default:
                    System.out.println("Invalid option. Try again!");
                    break;
            }
            if (choice == 4 ) break;
        }
    }
}
