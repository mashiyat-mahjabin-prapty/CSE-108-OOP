package sample;


import javafx.collections.FXCollections;
import javafx.collections.ObservableArray;
import javafx.collections.ObservableList;
import javafx.collections.ObservableMap;
import javafx.scene.image.Image;

import java.io.Serializable;
import java.util.*;

public class Car implements Serializable {
    private static int total;
    private int serialNo;
    private String registrationNo;
    private int yearMade;
    private String colours;
    private String carMake;
    private String carModel;
    private double price;
    private String quantity;
    private static Map<String, Integer> map = new HashMap<>();
    public static final String FILE_NAME_CAR = "cars.txt";

    public Car()
    {
        registrationNo = null;
        yearMade = 0;
        colours = null;
        carMake = null;
        carModel = null;
        price = 0.0;
        quantity = null;
    }


    public String getQuantity() {
        return quantity;
    }

    public void setQuantity(String quantity) {
        this.quantity=quantity;
    }


    public int getSerialNo() {return serialNo;}

    public void setSerialNo(int serial) {
        this.serialNo = serial;
    }

    public String getColours() {
        return colours;
    }

    public void setColours(String colour) {
        this.colours=colour;
    }

    public String getRegistrationNo() {
        return registrationNo;
    }

    public void setRegistrationNo(String registrationNo) { this.registrationNo=registrationNo; }

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
        this.carMake=carMake;
    }

    public String getCarModel() {
        return carModel;
    }

    public void setCarModel(String carModel) {
        this.carModel=carModel;
    }

    public double getPrice() {
        return price;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public String setMap(String model)
    {
        String str = null;
        boolean flag = false;
        Set set = Car.map.entrySet();
        Iterator itr = set.iterator();

        while (itr.hasNext())
        {
            Map.Entry entry = (Map.Entry) itr.next();
            String key = (String) entry.getKey();
            if (key.equalsIgnoreCase(model))
            {
                int quantity = (Integer) entry.getValue();
                Car.map.replace(key, quantity, quantity++);
                flag = true;
                str = key+ " - " + quantity;
                System.out.println(str);
                break;
            }

            }
        if (!flag)
        {
            Car.map.put(model, 1);
            str = model +" - 1";
            System.out.println(str);
        }
        return str;
    }

    public void setCar(String line)
    {
        String[] str = line.split(",");
        setSerialNo(++total);
        System.out.println(serialNo);
        setRegistrationNo(str[0]);
        setYearMade(Integer.parseInt(str[1]));
        setColours(str[2]);
        setCarMake(str[3]);
        setCarModel(str[4]);
        setPrice(Double.parseDouble(str[5]));
        setQuantity(setMap(this.carModel));
    }

    public void printCar()
    {
        System.out.println("Car found");
        System.out.println("Registration no.: " + this.getRegistrationNo());
        System.out.println("Year of Making: " + this.getYearMade());
        System.out.print("Colours of the Car: " + this.getColours() + " ");
        System.out.println();
        System.out.println("Name of the Car Making Company: " + this.getCarMake());
        System.out.println("Name of the Model: " + this.getCarModel());
        System.out.println("Price of the car: $" + this.getPrice());
        System.out.println("Quantity: " + this.getQuantity());
        System.out.println();
    }

    public static void updateMap(ObservableList<Car> list)
    {
        map = new HashMap<>();
        for (Car car : list)
        {
            String str = car.setMap(car.getCarModel());
            car.setQuantity(str);
        }
    }
}
