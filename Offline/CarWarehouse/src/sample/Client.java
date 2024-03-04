package sample;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;
import javafx.collections.ObservableMap;

import java.io.IOException;
import java.io.Serializable;
import java.util.*;

public class Client implements Serializable, Runnable {
    private static NetworkUtil networkUtil;
    private static ObservableList<Car> listClient;
    private static ObservableList<String> viewerInfo = FXCollections.observableArrayList();
    private Thread thread;

    public Client(String serverAddress, int serverPort) throws IOException, ClassNotFoundException {

        listClient = null;
        networkUtil = new NetworkUtil(serverAddress, serverPort);
        this.thread = new Thread(this);
        thread.start();
    }

    public void run() {
        try {
            networkUtil.write("send list");
            //System.out.println(req);
            Object object = networkUtil.read();
            System.out.println(object);
            String[] str = ((String) object).split(",");
            System.out.println(str[0]);
            int number = Integer.parseInt(str[1]);
            System.out.println(number);
            //object = networkUtil.read();
            listClient = FXCollections.observableArrayList();
            for (int i = 0; i < number; i++) {
                object = networkUtil.read();
                Car temp = (Car) object;
                if (temp != null) {
                    listClient.add(temp);
                }
                System.out.println(object);
            }
            for (Car temp : listClient) {
                temp.printCar();
            }
            System.out.println(networkUtil.read());


        } catch (IOException e) {
            e.printStackTrace();
        } catch (ClassNotFoundException e) {
            e.printStackTrace();
        }
    }


    public static NetworkUtil getNetworkUtil() {
        return networkUtil;
    }

    public static void setNetworkUtil(NetworkUtil networkUtil) {
        Client.networkUtil = networkUtil;
    }

    public static ObservableList<Car> getListClient() {
        return listClient;
    }

    public static void setListClient(ObservableList<Car> listClient) {
        Client.listClient = listClient;
    }

    public Thread getThread() {
        return thread;
    }

    public void setThread(Thread thread) {
        this.thread = thread;
    }

    public static ObservableList<String> getViewerInfo() {
        return viewerInfo;
    }

    public static void setViewerInfo(ObservableList<String> viewerInfo) {
        Client.viewerInfo = viewerInfo;
    }

    public static ObservableList<Car> getUpdate() throws IOException, ClassNotFoundException {
        networkUtil.write("send list");
        Object object = networkUtil.read();
        System.out.println(object);
        String[] str = ((String) object).split(",");
        System.out.println(str[0]);
        int number = Integer.parseInt(str[1]);
        //object = networkUtil.read();
        listClient = FXCollections.observableArrayList();
        for (int i = 0; i < number; i++) {
            object = networkUtil.read();
            Car temp = (Car) object;
            if (temp != null) {
                listClient.add(temp);
            }
        }
        for (Car temp : listClient) {
            temp.printCar();
        }
        System.out.println(networkUtil.read());
        return listClient;
}
    public static String login() throws IOException, ClassNotFoundException {
        Object object = networkUtil.read();
        return (String)object;
    }

}
