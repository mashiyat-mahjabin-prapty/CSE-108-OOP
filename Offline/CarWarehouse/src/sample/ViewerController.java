package sample;


import javafx.collections.FXCollections;
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
import javafx.scene.image.Image;
import javafx.scene.image.ImageView;
import javafx.stage.Stage;

import java.io.IOException;
import java.net.URL;
import java.util.ResourceBundle;

public class ViewerController implements Initializable {

    @FXML private Button backView;
    @FXML private Button refresh;
    @FXML private Button regButton;
    @FXML private Button comButton;
    @FXML private TextField regNo;
    @FXML private TextField companyText;
    @FXML private TextField modelText;
    @FXML private Label searchLabel;
    @FXML private TableView<Car> carTableView;
    @FXML private TableColumn<Car, Integer> serialNo;
    @FXML private TableColumn<Car, String> registrationNo;
    @FXML private TableColumn<Car, String> company;
    @FXML private TableColumn<Car, String> model;
    @FXML private TableColumn<Car, String> colors;
    @FXML private TableColumn<Car, Integer> year;
    @FXML private TableColumn<Car, Double> price;
    @FXML private TableColumn<Car, String> quantity;



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

        carTableView.getSelectionModel().setSelectionMode(SelectionMode.SINGLE);
    }

    @FXML
    public void buttonpushed (ActionEvent event) throws IOException, ClassNotFoundException {
        Button button;
        button = (Button) event.getSource();
        if (button == backView)
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

        else if (button == regButton)
        {
            String registrationText = regNo.getText();
            for (Car car : Client.getListClient())
            {
                colorRow(registrationNo, registrationText);
                //System.out.println("Entered loop");
                if (car.getRegistrationNo().equalsIgnoreCase(registrationText))
                {
                    //colorRow(registrationNo, registrationText);
                    searchLabel.setText("Car found");
                    //break;
                }
            }
        }
        else if (button == comButton)
        {
            String com = companyText.getText();
            String mod = modelText.getText();
            for (Car car : Client.getListClient())
            {
                colorRow(model, mod);
                //System.out.println("Entered loop");
                if (car.getCarMake().equalsIgnoreCase(com) && car.getCarModel().equalsIgnoreCase(mod))
                {
                    searchLabel.setText("Car found");
                }
            }
        }
    }

    @FXML
    public void buyCar() throws IOException, ClassNotFoundException {
        ObservableList<Car> allCars;
        Car selections;
        allCars = carTableView.getItems();

        selections = carTableView.getSelectionModel().getSelectedItem();

        allCars.remove(selections);
        Client.getNetworkUtil().write("Delete Car");
        Client.getNetworkUtil().write(selections.getRegistrationNo());

        carTableView.setItems(Client.getUpdate());
        Car.updateMap(carTableView.getItems());
        FileOp.fileWrite(allCars, Car.FILE_NAME_CAR);
    }

    private void colorRow(TableColumn<Car, String> column, String check)
    {
        column.setCellFactory(carStringTableColumn -> {
            return new TableCell<Car, String>() {
                @Override
                protected void updateItem(String item, boolean empty) {
                    super.updateItem(item,empty);

                    setText(empty ? "" : getItem().toString());
                    setGraphic(null);

                    TableRow<Car> currentRow = getTableRow();

                    if (!isEmpty())
                    {
                        if (item.equalsIgnoreCase(check))
                        {
                            currentRow.setStyle("-fx-background-color: cyan");
                        }
                        else
                        {
                            currentRow.setStyle("-fx-background-color: transparent");
                        }
                    }
                }
            };
        });
    }

}
