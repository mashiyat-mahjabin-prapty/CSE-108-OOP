package sample;

import java.io.IOException;
import java.io.Serializable;
import java.net.Socket;
import java.util.*;

public class ClientThread implements Runnable, Serializable {
    private Socket socket;
    private Thread thread;
    private NetworkUtil networkUtil;
    private String username;
    private String password;



    public ClientThread(Socket socket, NetworkUtil networkUtil) throws IOException {
        this.socket = socket;
        this.thread = new Thread(this);
        this.networkUtil = networkUtil;
        thread.start();
    }

    @Override
    public void run() {

            try {
                while (true) {
                    Object object = networkUtil.read();
                    //System.out.println((String) object);
                    if (object == null) {
                        break;
                    }
                    if (object instanceof String) {
                        String req = (String) object;
                        System.out.println(req);
                        if (req.equalsIgnoreCase("send list")) {
                            networkUtil.write("sending cars," + Server.serverList.size());
                            int test = 1;
                            for (Car temp : Server.serverList) {
                                System.out.println(Server.serverList.size());
                                temp.printCar();
                                temp.setSerialNo(test++);
                                networkUtil.write(temp);
                                System.out.println("Done");
                            }
                            Car.updateMap(Server.serverList);
                            networkUtil.write("Finished successfully");
                        } else if (req.equalsIgnoreCase("Manufacture check")) {
                            System.out.println(req);
                            object = networkUtil.read();
                            username = (String) object;
                            System.out.println(username);
                            object = networkUtil.read();
                            password = (String) object;
                            System.out.println(password);

                            boolean flag = false;

                            for (Manufacturer m : Manufacturer.getManufacturerList()) {
                                if (m.getPassword().equalsIgnoreCase(password) && m.getUserName().equalsIgnoreCase(username)) {
                                    flag = true;
                                    networkUtil.write("Found");
                                    break;
                                }
                                System.out.println(flag);
                            }
                            System.out.println(flag);
                            if (!flag) networkUtil.write("Not Found");
                        } else if (req.equalsIgnoreCase("Add car")) {
                            object = networkUtil.read();
                            if (object instanceof Car) {
                                Car temp = (Car) object;
                                Server.serverList.add(temp);
                                //FileOp.fileWrite(Server.serverList, Car.FILE_NAME_CAR);
                            }
                            //FileOp.fileWrite(Server.serverList, Car.FILE_NAME_CAR);
                        } else if (req.equalsIgnoreCase("Delete Car")) {
                            object = networkUtil.read();
                            if (object instanceof String) {
                                String regToDelete = (String) object;
                                for (Car temp : Server.serverList) {
                                    if (temp.getRegistrationNo().equalsIgnoreCase(regToDelete)) {
                                        Server.serverList.remove(temp);
                                        break;
                                    }
                                }
                            }
                            //FileOp.fileWrite(Server.serverList, Car.FILE_NAME_CAR);
                        } else if (req.equalsIgnoreCase("Edit Car")) {
                            object = networkUtil.read();
                            if (object instanceof Car) {
                                Car temp = (Car) object;
                                for (Car car : Server.serverList) {
                                    if (car.getRegistrationNo().equalsIgnoreCase(temp.getRegistrationNo())) {
                                        Server.serverList.remove(car);
                                        Server.serverList.add(temp);
                                        break;
                                    }
                                }
                            }
                            //FileOp.fileWrite(Server.serverList, Car.FILE_NAME_CAR);
                        }
                    }
                }
            } catch (Exception e) {
                //e.printStackTrace();
            } finally {
                try {
                    FileOp.fileWrite(Server.serverList, Car.FILE_NAME_CAR);
                    networkUtil.closeConnection();
                    System.out.println("Closed");
                    socket.close();
                    Server.setClientCount(Server.getClientCount()-1);
                    if (Server.getClientCount() == 0)
                    {
                        Server.getServerSocket().close();
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
    }
}
