package com.company;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static final String FILE_NAME = "cars.txt";

    public static void fileRead(List list) {
        try (BufferedReader br = new BufferedReader(new FileReader(FILE_NAME)))
        {
            while(true)
            {
                String line;
                Car temp = new Car();
                line = br.readLine();
                if (line == null) break;
                temp.setCar(line);
                list.add(temp);
                //temp.printCar();
            }
            br.close();
        } catch(Exception e)
        {
            e.printStackTrace();
        }
    }

    public static void fileWrite(List list)
    {
        try(BufferedWriter bufferedWriter = new BufferedWriter(new FileWriter(FILE_NAME)))
        {
            for(int i = 0; i < list.size(); i++)
            {
                Car car;
                car = (Car) list.get(i);
                String line;
                line = car.getRegistrationNo() + "," + car.getYearMade() + "," + car.getColour1() +
                        "," + car.getColour2() + "," + car.getColour3() +
                        "," + car.getCarMake() + "," + car.getCarModel() + "," + car.getPrice() + "\n";
                bufferedWriter.write(line);
            }
            bufferedWriter.close();
        } catch(Exception e)
        {
            e.printStackTrace();
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
                    Car.searchReg(reg);
                    break;
                case 2:
                    System.out.print("Please enter the name of the maker company:");
                    sc.nextLine();
                    String carMake = sc.nextLine();
                    System.out.print("Please enter the model(If you do not want to specify the model please enter ANY):");
                    String carModel = sc.nextLine();
                    if(carModel.equalsIgnoreCase("ANY"))
                        Car.searchCarMake(carMake);
                    else
                        Car.searchCarModel(carMake, carModel);
                    break;
                case 3:
                    return;
                default:
                    System.out.println("Invalid input;");
                    break;
            }
        }
    }

    public static boolean addCar(Car car)
    {
        for(int i = 0; i < Car.list.size(); i++)
        {
            Car temp = Car.list.get(i);
            if(temp != null)
            {
                if(temp.getRegistrationNo().equalsIgnoreCase(car.getRegistrationNo()))
                    return false;
            }
        }
        return true;
    }

    public static void deleteCar()
    {
        System.out.println("Welcome to the car deletion portal");
        System.out.print("Enter the registration number of the car:");
        Scanner sc = new Scanner(System.in);
        String op = sc.nextLine();
        boolean flag = false;
        for(int i = 0; i < Car.list.size(); i++)
        {
            Car temp = Car.list.get(i);
            if(temp != null)
            {
                if(temp.getRegistrationNo().equalsIgnoreCase(op))
                {
                    flag = true;
                    System.out.println("Deleted successfully!");
                    Car.list.remove(i);
                    break;
                }
            }
        }
        if(!flag) System.out.println("Invalid registration number");
    }

    public static void main(String[] args) {
        fileRead(Car.list);
        /*for (Car car : Car.list)
        {
            car.printCar();
        }*/
        while(true)
        {
            int choice;
            System.out.println("Main Menu");
            System.out.println("Choose an option to proceed:");
            System.out.println("(1) Search Cars\n" +
                    "(2) Add Car\n" +
                    "(3) Delete Car\n" +
                    "(4) Exit System");
            Scanner sc = new Scanner(System.in);
            choice = sc.nextInt();
            switch(choice)
            {
                case 1:
                    searchCar();
                    break;
                case 2:
                    Car car = new Car();
                    car.inputCar(car);
                    if(addCar(car))
                    {
                        Car.list.add(car);
                        System.out.println("Car added successfully!");
                    }
                    else System.out.println("Registration no. already exists");
                    System.out.println();
                    break;
                case 3:
                    deleteCar();
                    System.out.println();
                    break;
                case 4:
                    System.out.println("Thank you for your time");
                    /*for (Car c : Car.list)
                    {
                        c.printCar();
                    }*/
                    fileWrite(Car.list);
                    return;
                default:
                    System.out.println("Invalid input!\n" + "Please choose a valid option");
                    break;
            }

        }
    }
}
