package com.company;

import java.util.Iterator;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;

public class Viewer_Functionality {

    public static void viewer_menu()
    {
        while(true)
        {
            System.out.println("Welcome to the viewer portal\nChoose an option to proceed:");
            System.out.println("1. View All Cars\n2. Search a Car\n3. Buy a Car\n4. Exit");
            Scanner scanner = new Scanner(System.in);
            int choice = scanner.nextInt();
            switch (choice)
            {
                case 1:
                    Car.ViewAllCar();
                    break;
                case 2:
                    searchCar();
                    break;
                case 3:
                    boolean flag = buyCar();
                    if (flag) System.out.println("Thank you for buying the car");
                    else System.out.println("Sorry, no such car found!");
                    break;
                case 4:
                    System.out.println("Thank you!");
                    break;
                default:
                    System.out.println("Invalid Input!\nTry again");
                    break;
            }
            if (choice == 4) break;
        }
    }

    public static void searchCar()
    {
        while (true)
        {
            System.out.println("Welcome car searching portal");
            System.out.println("Choose an option:");
            System.out.println("(1) By Registration Number\n" +
                    "(2) By Car Make and Car Model\n" +
                    "(3) Back to Main Menu");
            Scanner sc = new Scanner(System.in);
            int choose = sc.nextInt();
            switch(choose)
            {
                case 1:
                    System.out.print("Please enter the registration no.:");
                    sc.nextLine();
                    String reg = sc.nextLine();
                    searchReg(reg);
                    break;
                case 2:
                    System.out.print("Please enter the name of the maker company:");
                    sc.nextLine();
                    String carMake = sc.nextLine();
                    System.out.print("Please enter the model(If you do not want to specify the model please enter ANY):");
                    String carModel = sc.nextLine();
                    if(carModel.equalsIgnoreCase("ANY"))
                        searchCarMake(carMake);
                    else
                        searchCarModel(carMake, carModel);
                    break;
                case 3:
                    return;
                default:
                    System.out.println("Invalid input;");
                    break;
            }
        }
    }
    public static void searchReg(String reg)
    {
        boolean flag = false;
        for(int i = 0; i < Car.list.size(); i++)
        {
            Car temp = Car.list.get(i);
            if(temp != null)
            {
                if(temp.getRegistrationNo().equalsIgnoreCase(reg))
                {
                    flag = true;
                    temp.printCar();
                }
            }
        }
        if (!flag) System.out.println("Car not found!");
    }

    public static void searchCarMake(String cmake)
    {
        boolean flag = false;
        for(int i = 0; i < Car.list.size(); i++)
        {
            Car temp = Car.list.get(i);
            if(temp != null)
            {
                if(temp.getCarMake().equalsIgnoreCase(cmake))
                {
                    flag = true;
                    temp.printCar();
                }
            }
        }
        if (!flag) System.out.println("Car not found!");
    }

    public static void searchCarModel(String cmake, String cmodel)
    {
        boolean flag = false;
        for(int i = 0; i < Car.list.size(); i++)
        {
            Car temp = Car.list.get(i);
            if(temp != null)
            {
                if(temp.getCarMake().equalsIgnoreCase(cmake) && temp.getCarModel().equalsIgnoreCase(cmodel))
                {
                    flag = true;
                    temp.printCar();
                }
            }
        }
        if (!flag) System.out.println("Car not found!");
    }

    public static boolean buyCar()
    {
        boolean flag = false;
        Scanner scanner = new Scanner(System.in);
        System.out.println("Welcome to car buying portal: ");
        System.out.println("Enter the company of the car you want to buy: ");
        String company = scanner.nextLine();
        System.out.println("Enter the model of the car you want to buy: ");
        String model = scanner.nextLine();
        for (Car temp : Car.list) {
            if (temp.getCarMake().equalsIgnoreCase(company) && temp.getCarModel().equalsIgnoreCase(model))
            {
                System.out.println("Car found");
                flag = true;
                Set set = Car.map.entrySet();
                Iterator itr = set.iterator();

                while (itr.hasNext())
                {
                    Map.Entry entry = (Map.Entry) itr.next();
                    String key = (String) entry.getKey();
                    if (key.equalsIgnoreCase(temp.getCarModel()))
                    {
                        int quantity = (Integer) entry.getValue();
                        Car.map.replace(key, quantity, quantity--);
                        break;
                    }
                }
            }
            if (flag)
            {
                Car.list.remove(temp);
                break;
            }
        }
        FileOp.fileWrite(Car.list);
        return flag;
    }
}
