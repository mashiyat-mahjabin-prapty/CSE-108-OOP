package sample;

import javafx.collections.FXCollections;
import javafx.collections.ObservableList;

import java.io.File;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.ArrayList;
import java.util.Collection;
import java.util.List;
import java.util.Scanner;


public class Server{

    private static ServerSocket serverSocket;
    private NetworkUtil networkUtil;
    public static ObservableList<Car> serverList = FXCollections.observableArrayList();
    private static int clientCount;
    //private ClientThread clientThread;

    public Server() throws IOException {
        FileOp.fileRead(serverList, Car.FILE_NAME_CAR);
        FileOp.fileRead(Manufacturer.getManufacturerList(), Manufacturer.FILE_NAME_MAN);
        /*for (int i = 0; i < Car.list.size(); i++)
        {
            Car temp = Car.list.get(i);
            temp.printCar();
        }*/
        try {
            serverSocket = new ServerSocket(33333);
            while (true)
            {
                Socket clientSocket = serverSocket.accept();
                System.out.println("New client connected");
                clientCount++;
                this.networkUtil = new NetworkUtil(clientSocket);
                ClientThread clientThread = new ClientThread(clientSocket, networkUtil);
            }
        } catch (IOException e) {
            System.out.println("Server starts " + e);
            //e.printStackTrace();
            //serverSocket.close();
        }
    }

    public static int getClientCount() {
        return clientCount;
    }

    public static void setClientCount(int clientCount) {
        Server.clientCount = clientCount;
    }

    public static void main(String[] args) throws IOException {
        Server server = new Server();
    }

    public static ServerSocket getServerSocket() {
        return serverSocket;
    }

    public static void setServerSocket(ServerSocket serversocket) {
        serverSocket = serversocket;
    }

}
