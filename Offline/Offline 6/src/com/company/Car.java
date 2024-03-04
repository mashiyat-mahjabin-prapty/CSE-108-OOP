package com.company;

import java.io.Serializable;
import java.util.*;

public class Car implements Serializable {
    private String registrationNo;
    private int yearMade;
    private String colour1;
    private String colour2;
    private String colour3;
    private String carMake;
    private String carModel;
    private double price;
    public static List<Car> list = new ArrayList<Car>();
    public static Map<String, Integer> map = new HashMap<String, Integer>();

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

    public static void setMap()
    {
        for (Car temp : list)
        {
            Set set = Car.map.entrySet();
            Iterator itr = set.iterator();

            while (itr.hasNext())
            {
                Map.Entry entry = (Map.Entry) itr.next();
                String key = (String) entry.getKey();
                if (key.equalsIgnoreCase(temp.getCarModel()))
                {
                    int quantity = (Integer) entry.getValue();
                    Car.map.replace(key, quantity, quantity++);
                    break;
                }
                else
                {
                    Car.map.put(temp.getCarModel(), 1);
                    break;
                }
            }
        }
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

    public void inputCar()
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Welcome to the car addition portal");
        System.out.println("Enter the information of the new car");
        System.out.print("Enter registration number:");
        setRegistrationNo(sc.nextLine());
        System.out.print("Enter Year of Making:");
        setYearMade(sc.nextInt());
        System.out.print("Enter first color:");
        sc.nextLine();
        setColour1(sc.nextLine());
        System.out.print("Enter second color(if any or press enter)");
        setColour2(sc.nextLine());
        System.out.print("Enter third color(if any or press enter):");
        setColour3(sc.nextLine());
        System.out.print("Enter the Maker Company:");
        setCarMake(sc.nextLine());
        System.out.print("Enter the Model of the car:");
        setCarModel(sc.nextLine());
        System.out.print("Enter the Price of the car:");
        setPrice(sc.nextDouble());
        System.out.println("Enter the Quantity of the car: ");
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

    public static void ViewAllCar()
    {
        System.out.println("Printing all cars:");
        for (int i = 0; i < list.size(); i++) {
            Car temp = list.get(i);
            temp.printCar();
        }
    }
}
