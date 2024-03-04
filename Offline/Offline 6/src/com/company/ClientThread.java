package com.company;

import java.io.IOException;
import java.io.Serializable;
import java.net.Socket;

public class ClientThread implements Runnable, Serializable {
    private Socket socket;
    private Thread thread;
    private NetworkUtil networkUtil;

    public ClientThread(Socket socket, NetworkUtil networkUtil) throws IOException {
        this.socket = socket;
        this.thread = new Thread(this);
        this.networkUtil = networkUtil;
        thread.start();
    }
    @Override
    public void run()
    {
        try {
            FileOp.fileRead(Car.list);
            networkUtil.write(Car.list);
            System.out.println(networkUtil.read());
            Car.setMap();
            networkUtil.write(Car.map);
            networkUtil.write("Choose an option:\n1. Manufacturer\n2. Viewer");
            int choice = (Integer) networkUtil.read();
            System.out.println(choice);
            switch(choice)
            {
                case 1:
                    networkUtil.write("Username:");
                    //System.out.println(networkUtil.read());
                    String username = (String) networkUtil.read();
                    System.out.println(username);
                    if (username == null)System.out.println("Not found");
                    networkUtil.write("Password:");
                    String password = (String) networkUtil.read();
                    boolean flag = manufacture_Functionality.login(username, password);
                    if (flag)
                    {
                        networkUtil.write("Successfully found manufacturer");
                        networkUtil.write("true");
                    }
                    else
                    {
                        networkUtil.write("Manufacturer not found");
                        networkUtil.write("false");
                        break;
                    }
                    break;
                case 2:
                    networkUtil.write("Viewer ID:");
                    //System.out.println(networkUtil.read());
                    String viewer = (String) networkUtil.read();
                    System.out.println(viewer);
                    if (viewer == null)
                    {
                        networkUtil.write("false");
                    }
                    else
                    {
                        networkUtil.write("true");
                        //Viewer_Functionality.viewer_menu();
                    }
                    break;
            }
        } catch (Exception e)
        {
            System.out.println(e);
        } finally {
            try {
                networkUtil.closeConnection();
            } catch (IOException e)
            {
                e.printStackTrace();
            }
        }
    }
}
