package sample;

import javafx.collections.ObservableList;
import javafx.event.ActionEvent;
import javafx.fxml.FXML;
import javafx.fxml.FXMLLoader;
import javafx.fxml.Initializable;
import javafx.scene.Node;
import javafx.scene.Parent;
import javafx.scene.Scene;
import javafx.scene.control.*;
import javafx.scene.control.cell.PropertyValueFactory;
import javafx.scene.control.cell.TextFieldTableCell;
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;
import javafx.stage.Window;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class ManufacturerController implements Initializable {

    @FXML private Button backMan;
    @FXML private Button refresh;
    @FXML private TableView<Car> carTableView;
    @FXML private TableColumn<Car, Integer> serialNo;
    @FXML private TableColumn<Car, String> registrationNo;
    @FXML private TableColumn<Car, String> company;
    @FXML private TableColumn<Car, String> model;
    @FXML private TableColumn<Car, String> colors;
    @FXML private TableColumn<Car, Integer> year;
    @FXML private TableColumn<Car, Double> price;
    @FXML private TableColumn<Car, String> quantity;
    @FXML private TextField registration;
    @FXML private TextField colorsText;
    @FXML private TextField companyText;
    @FXML private TextField modelText;
    @FXML private TextField priceAdd;
    @FXML private TextField YearMake;


    @Override
    public void initialize(URL url, ResourceBundle resourceBundle) {

        serialNo.setCellValueFactory(new PropertyValueFactory<Car, Integer>("serialNo"));
        registrationNo.setCellValueFactory(new PropertyValueFactory<Car, String>("registrationNo"));
        company.setCellValueFactory(new PropertyValueFactory<Car, String>("carMake"));
        model.setCellValueFactory(new PropertyValueFactory<Car, String>("carModel"));
        colors.setCellValueFactory(new PropertyValueFactory<Car, String>("colours"));
        year.setCellValueFactory(new PropertyValueFactory<Car, Integer>("yearMade"));
        price.setCellValueFactory(new PropertyValueFactory<Car, Double>("price"));
        quantity.setCellValueFactory(new PropertyValueFactory<Car, String>("quantity"));
        carTableView.setItems(Client.getListClient());

        carTableView.setEditable(true);
        company.setCellFactory(TextFieldTableCell.forTableColumn());
        colors.setCellFactory(TextFieldTableCell.forTableColumn());
        model.setCellFactory(TextFieldTableCell.forTableColumn());

        carTableView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
        //price.setCellFactory((String)TextFieldTableCell.forTableColumn());

    }

    public void changeModel (TableColumn.CellEditEvent editEvent) throws IOException, ClassNotFoundException {
        Car carSelected = carTableView.getSelectionModel().getSelectedItem();
        carSelected.setCarModel(editEvent.getNewValue().toString());
        Client.getNetworkUtil().write("Edit car");
        Client.getNetworkUtil().write(carSelected);
        carTableView.setItems(Client.getUpdate());
        FileOp.fileWrite(Client.getListClient(), Car.FILE_NAME_CAR);
    }

    /*public void changePrice (TableColumn.CellEditEvent editEvent) throws IOException, ClassNotFoundException {
        Car carSelected = carTableView.getSelectionModel().getSelectedItem();
        carSelected.setPrice((Double) editEvent.getNewValue());
        Client.getNetworkUtil().write("Edit car");
        Client.getNetworkUtil().write(carSelected);
        carTableView.setItems(Client.getUpdate());
        FileOp.fileWrite(Client.getListClient(), Car.FILE_NAME_CAR);
    }*/



    public void changeCompany (TableColumn.CellEditEvent editEvent) throws IOException, ClassNotFoundException {
        Car carSelected = carTableView.getSelectionModel().getSelectedItem();
        carSelected.setCarMake(editEvent.getNewValue().toString());
        Client.getNetworkUtil().write("Edit car");
        Client.getNetworkUtil().write(carSelected);
        carTableView.setItems(Client.getUpdate());
        FileOp.fileWrite(Client.getListClient(), Car.FILE_NAME_CAR);
    }

    public void changeColor (TableColumn.CellEditEvent editEvent) throws IOException, ClassNotFoundException {
        Car carSelected = carTableView.getSelectionModel().getSelectedItem();
        carSelected.setColours(editEvent.getNewValue().toString());
        Client.getNetworkUtil().write("Edit car");
        Client.getNetworkUtil().write(carSelected);
        carTableView.setItems(Client.getUpdate());
        FileOp.fileWrite(Client.getListClient(), Car.FILE_NAME_CAR);
    }

    public void changeYear (TableColumn.CellEditEvent editEvent) throws IOException, ClassNotFoundException {
        Car carSelected = carTableView.getSelectionModel().getSelectedItem();
        carSelected.setYearMade((Integer) editEvent.getNewValue());
        Client.getNetworkUtil().write("Edit car");
        Client.getNetworkUtil().write(carSelected);
        carTableView.setItems(Client.getUpdate());
        FileOp.fileWrite(Client.getListClient(), Car.FILE_NAME_CAR);
    }

    @FXML
    public void AddButton () throws IOException, ClassNotFoundException {
        Car car = new Car();
        String line = registration.getText() + "," + YearMake.getText() + ","
                    + colorsText.getText() + "," + companyText.getText() +
                    "," + modelText.getText() + "," + priceAdd.getText() + ",";
        car.setCar(line);

        carTableView.getItems().add(car);

        Client.getNetworkUtil().write("Add car");
        Client.getNetworkUtil().write(car);
        carTableView.setItems(Client.getUpdate());
        FileOp.fileWrite(Client.getListClient(), Car.FILE_NAME_CAR);
    }

    @FXML
    public void buttonpushed (ActionEvent event) throws IOException, ClassNotFoundException {
        Button button;
        button = (Button) event.getSource();
        if (button == backMan)
        {
            Parent Parent = FXMLLoader.load(getClass().getResource("sample.fxml"));
            Scene View = new Scene(Parent);
            Stage window = (Stage) ((Node)event.getSource()).getScene().getWindow();

            window.setScene(View);
            window.show();
        }
        else if (button == refresh)
        {
            Client.getNetworkUtil().write("send list");
            carTableView.setItems(Client.getUpdate());
        }
    }

    @FXML
    public void deleteCar() throws IOException, ClassNotFoundException {
        ObservableList<Car> allCars;
        Car selections;
        allCars = carTableView.getItems();

        selections = carTableView.getSelectionModel().getSelectedItem();

        System.out.println(selections);
        allCars.remove(selections);
        Client.getNetworkUtil().write("Delete Car");
        Client.getNetworkUtil().write(selections.getRegistrationNo());

        carTableView.setItems(Client.getUpdate());
        Car.updateMap(carTableView.getItems());
        FileOp.fileWrite(carTableView.getItems(), Car.FILE_NAME_CAR);
    }

}

