package com.company;

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Car {
    private String registrationNo;
    private int yearMade;
    private String colour1;
    private String colour2;
    private String colour3;
    private String carMake;
    private String carModel;
    private double price;
    public static List<Car> list = new ArrayList<Car>();

    public Car()
    {
        registrationNo = null;
        yearMade = 0;
        colour1 = null;
        colour2 = null;
        colour3 = null;
        carMake = null;
        carModel = null;
        price = 0.0;
    }

    public String getColour1() {
        return colour1;
    }

    public void setColour1(String colour1) {
        this.colour1 = colour1;
    }

    public String getColour2() {
        return colour2;
    }

    public void setColour2(String colour2) {
        this.colour2 = colour2;
    }

    public String getColour3() {
        return colour3;
    }

    public void setColour3(String colour3) {
        this.colour3 = colour3;
    }

    public String getRegistrationNo() {
        return registrationNo;
    }

    public void setRegistrationNo(String registrationNo) {
        this.registrationNo = registrationNo;
    }

    public int getYearMade() {
        return yearMade;
    }

    public void setYearMade(int yearMade) {
        this.yearMade = yearMade;
    }

    public String getCarMake() {
        return carMake;
    }

    public void setCarMake(String carMake) {
        this.carMake = carMake;
    }

    public String getCarModel() {
        return carModel;
    }

    public void setCarModel(String carModel) {
        this.carModel = carModel;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setCar(String line)
    {
        String[] str = line.split(",");
        setRegistrationNo(str[0]);
        setYearMade(Integer.parseInt(str[1]));
        setColour1(str[2]);
        setColour2(str[3]);
        setColour3(str[4]);
        setCarMake(str[5]);
        setCarModel(str[6]);
        setPrice(Double.parseDouble(str[7]));
    }

    public void inputCar(Car car)
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Welcome to the car addition portal");
        System.out.println("Enter the information of the new car");
        System.out.print("Enter registration number:");
        car.setRegistrationNo(sc.nextLine());
        System.out.print("Enter Year of Making:");
        car.setYearMade(sc.nextInt());
        System.out.print("Enter first color:");
        sc.nextLine();
        car.setColour1(sc.nextLine());
        System.out.print("Enter second color(if any or press enter)");
        car.setColour2(sc.nextLine());
        System.out.print("Enter third color(if any or press enter):");
        car.setColour3(sc.nextLine());
        System.out.print("Enter the Maker Company:");
        car.setCarMake(sc.nextLine());
        System.out.print("Enter the Model of the car:");
        car.setCarModel(sc.nextLine());
        System.out.print("Enter the Price of the car:");
        car.setPrice(sc.nextDouble());
    }

    public static void searchReg(String reg)
    {
        boolean flag = false;
        for(int i = 0; i < list.size(); i++)
        {
            Car temp = list.get(i);
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
        for(int i = 0; i < list.size(); i++)
        {
            Car temp = list.get(i);
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
        for(int i = 0; i < list.size(); i++)
        {
            Car temp = list.get(i);
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

    public void printCar()
    {
        System.out.println("Car found");
        System.out.println("Registration no.: " + this.getRegistrationNo());
        System.out.println("Year of Making: " + this.getYearMade());
        System.out.print("Colours of the Car: " + this.getColour1() + " ");
        if (this.getColour2() != null) System.out.print(this.getColour2() + " ");
        if (this.getColour3() != null) System.out.print(this.getColour3());
        System.out.println();
        System.out.println("Name of the Car Making Company: " + this.getCarMake());
        System.out.println("Name of the Model: " + this.getCarModel());
        System.out.println("Price of the car: $" + this.getPrice());
        System.out.println();
    }
}
