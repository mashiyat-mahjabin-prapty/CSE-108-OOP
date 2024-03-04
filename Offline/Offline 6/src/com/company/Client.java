package com.company;

import java.io.IOException;
import java.io.Serializable;
import java.sql.SQLOutput;
import java.util.*;

public class Client implements Serializable{
    private NetworkUtil networkUtil;
    private ArrayList listClient;
    private HashMap mapClient;

    public Client(String serverAddress, int serverPort) throws IOException, ClassNotFoundException {

        //for (int i = 0; i < Car.list.size(); i++)
        //{
        //    Car temp = Car.list.get(i);
        //    temp.printCar();
        //}
        this.networkUtil = new NetworkUtil(serverAddress, serverPort);

    }

    public void doSomething() throws IOException, ClassNotFoundException {
        Object object = networkUtil.read();
        listClient = (ArrayList<Car>) object;
        networkUtil.write("Got arraylist");
        object = networkUtil.read();
        mapClient = (HashMap)object;
        String menu = (String) networkUtil.read();
        if (menu != null)System.out.println(menu);
        Scanner scanner = new Scanner(System.in);
        int choice = scanner.nextInt();
        networkUtil.write(choice);
        if (choice == 1)
        {
            System.out.print(networkUtil.read());
            scanner.nextLine();
            String username = scanner.nextLine();
            networkUtil.write(username);
            System.out.print(networkUtil.read());
            String password = scanner.nextLine();
            networkUtil.write(password);
            System.out.println(networkUtil.read());
            String check = (String) networkUtil.read();
            if (check.equalsIgnoreCase("true"))
            {
                manufacture_Functionality.manufacture_menu();
            }

        }
        else if (choice == 2)
        {
            System.out.print(networkUtil.read());
            scanner.nextLine();
            String viewer = scanner.nextLine();
            networkUtil.write(viewer);
            String check = (String) networkUtil.read();
            if (check.equalsIgnoreCase("true"))
            {
                Viewer_Functionality.viewer_menu();
            }
        }
    }

    public static void main(String[] args) throws IOException, ClassNotFoundException {
        String serverAddress = "127.0.0.1";
        int serverPort = 3333;
        Client client = new Client(serverAddress, serverPort);
        client.doSomething();

    }
}
