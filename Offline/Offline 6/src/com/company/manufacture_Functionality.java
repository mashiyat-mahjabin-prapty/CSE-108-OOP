package com.company;

import java.util.*;

public class manufacture_Functionality {

    private String username;
    private String password;
    public static Map<String, String> manufacture = new HashMap<String, String>();



    public String getUsername() {
        return username;
    }

    public void setUsername(String username) {
        this.username = username;
    }

    public String getPassword() {
        return password;
    }

    public void setPassword(String password) {
        this.password = password;
    }

    public static boolean login(String username, String password)
    {
        Set set = manufacture.entrySet();
        Iterator itr = set.iterator();
        boolean flag = false;

        while (itr.hasNext())
        {
            Map.Entry entry = (Map.Entry) itr.next();
            String user = (String) entry.getKey();
            String pass = (String) entry.getValue();

            if (user.equalsIgnoreCase(username) && pass.equalsIgnoreCase(password))
            {
                flag = true;
            }
        }
        return flag;
    }

    public static void manufacture_menu()
    {
        while(true)
        {
            System.out.println("Welcome to the manufacturer portal\nChoose an option to proceed:");
            System.out.println("1. View All Cars\n2. Add a Car\n3. Delete a Car\n4. Edit a Car\n5. Exit");
            Scanner scanner = new Scanner(System.in);
            int choice = scanner.nextInt();
            switch (choice)
            {
                case 1:
                    Car.ViewAllCar();
                    break;
                case 2:
                    addCar();
                    break;
                case 3:
                    deleteCar();
                    break;
                case 4:
                    editCar();
                    break;
                case 5:
                    System.out.println("Thank you!");
                    break;
                default:
                    System.out.println("Invalid Input!\nTry again");
                    break;
            }
            if (choice == 5) break;
        }

    }

    public static void addCar()
    {
        Car car = new Car();
        car.inputCar();
        boolean flag = true;
        for(int i = 0; i < Car.list.size(); i++)
        {
            Car temp = Car.list.get(i);
            if(temp != null)
            {
                if(temp.getRegistrationNo().equalsIgnoreCase(car.getRegistrationNo()))
                    flag = false;
            }
        }
        if (flag)
        {
            Car.list.add(car);
            Set set = Car.map.entrySet();
            Iterator itr = set.iterator();
            boolean exists = false;

            while (itr.hasNext())
            {
                Map.Entry entry = (Map.Entry) itr.next();
                String key = (String) entry.getKey();
                if (key.equalsIgnoreCase(car.getCarModel()))
                {
                    exists = true;
                    int quantity = (Integer) entry.getValue();
                    Car.map.replace(key, quantity, quantity++);
                    break;
                }
            }
            if (!exists)
            {
                Car.map.put(car.getCarModel(), 1);
            }
            System.out.println("Car added successfully!");
            FileOp.fileWrite(Car.list);
        }
        if (!flag) System.out.println("Registration number already exists!");
    }

    public static void deleteCar()
    {
        System.out.println("Welcome to the car deletion portal");
        System.out.print("Enter the registration number of the car:");
        Scanner sc = new Scanner(System.in);
        String op = sc.nextLine();
        Car temp = null;
        boolean flag = false;
        for(int i = 0; i < Car.list.size(); i++) {
            temp = Car.list.get(i);
            if (temp != null) {
                if (temp.getRegistrationNo().equalsIgnoreCase(op)) {
                    flag = true;
                    System.out.println("Deleted successfully!");
                    Car.list.remove(i);
                    break;
                }
            }
        }
        if (flag)
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
                    Car.map.replace(key, quantity, quantity--);
                    break;
                }
            }
        }
        if(!flag) System.out.println("Car not found!");
        FileOp.fileWrite(Car.list);
    }

    public static void editCar()
    {
        System.out.println("Welcome to the car editing portal:");
        System.out.println("Enter the registration number of the car: ");
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
                    System.out.println("Enter the necessary information of the car: ");
                    temp.inputCar();
                    Car.list.set(i, temp);
                    break;
                }
            }
        }
        if(!flag) System.out.println("Invalid registration number");
        FileOp.fileWrite(Car.list);
    }
}
