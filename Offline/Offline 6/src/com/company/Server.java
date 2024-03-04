package com.company;

import java.io.File;
import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Collection;
import java.util.Scanner;

public class Server{
    private ServerSocket serverSocket;
    private NetworkUtil networkUtil;
    //private ClientThread clientThread;

    public Server()
    {

        /*for (int i = 0; i < Car.list.size(); i++)
        {
            Car temp = Car.list.get(i);
            temp.printCar();
        }*/
        FileOp.mapRead(manufacture_Functionality.manufacture);
        try {
            serverSocket = new ServerSocket(3333);
            while (true)
            {
                Socket clientSocket = serverSocket.accept();
                System.out.println("New client connected");
                this.networkUtil = new NetworkUtil(clientSocket);
                ClientThread clientThread = new ClientThread(clientSocket, networkUtil);
            }
        } catch (IOException e) {
            System.out.println("Server starts " + e);
            e.printStackTrace();
        }
    }


    /*public void serve (Socket clientSocket) throws IOException
    {
        NetworkUtil networkUtil = new NetworkUtil(clientSocket);
        while (true)
        {

        }
    }*/

    public static void main(String[] args) {
        Server server = new Server();

    }
}
