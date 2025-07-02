import javax.swing.*;

public class RailwayTicketBookingForm {
    JFrame frame;

    RailwayTicketBookingForm() {
        frame = new JFrame("Railway Ticket Booking Form");
        frame.setSize(400, 450);
        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // Name
        JLabel nameLabel = new JLabel("Name:");
        nameLabel.setBounds(30, 30, 100, 25);
        JTextField nameField = new JTextField();
        nameField.setBounds(140, 30, 200, 25);

        // Age
        JLabel ageLabel = new JLabel("Age:");
        ageLabel.setBounds(30, 70, 100, 25);
        JTextField ageField = new JTextField();
        ageField.setBounds(140, 70, 200, 25);

        // Destination
        JLabel cityLabel = new JLabel("Destination:");
        cityLabel.setBounds(30, 110, 100, 25);
        String[] cities = {"Delhi", "Mumbai", "Chennai", "Kolkata", "Bangalore"};
        JComboBox<String> cityCombo = new JComboBox<>(cities);
        cityCombo.setBounds(140, 110, 200, 25);

        // Class Type (Radio Buttons)
        JLabel classLabel = new JLabel("Class Type:");
        classLabel.setBounds(30, 150, 100, 25);
        JRadioButton sleeperBtn = new JRadioButton("Sleeper");
        sleeperBtn.setBounds(140, 150, 80, 25);
        JRadioButton acBtn = new JRadioButton("AC");
        acBtn.setBounds(220, 150, 60, 25);
        JRadioButton generalBtn = new JRadioButton("General");
        generalBtn.setBounds(280, 150, 80, 25);
        ButtonGroup classGroup = new ButtonGroup();
        classGroup.add(sleeperBtn);
        classGroup.add(acBtn);
        classGroup.add(generalBtn);

        // Food Preference (Checkboxes)
        JLabel foodLabel = new JLabel("Food Preference:");
        foodLabel.setBounds(30, 190, 120, 25);
        JCheckBox vegBox = new JCheckBox("Veg");
        vegBox.setBounds(160, 190, 60, 25);
        JCheckBox nonVegBox = new JCheckBox("Non-Veg");
        nonVegBox.setBounds(230, 190, 100, 25);

        // Submit Button
        JButton submitBtn = new JButton("Show Summary");
        submitBtn.setBounds(130, 240, 150, 30);

        // Action
        submitBtn.addActionListener(e -> {
            String name = nameField.getText();
            String age = ageField.getText();
            String city = (String) cityCombo.getSelectedItem();

            String classType = "";
            if (sleeperBtn.isSelected()) classType = "Sleeper";
            else if (acBtn.isSelected()) classType = "AC";
            else if (generalBtn.isSelected()) classType = "General";

            String food = "";
            if (vegBox.isSelected()) food += "Veg ";
            if (nonVegBox.isSelected()) food += "Non-Veg";

            String summary = "Name: " + name + "\nAge: " + age +
                    "\nDestination: " + city +
                    "\nClass: " + classType +
                    "\nFood Preference: " + food;

            JOptionPane.showMessageDialog(frame, summary);
        });

        // Add to frame
        frame.add(nameLabel);
        frame.add(nameField);
        frame.add(ageLabel);
        frame.add(ageField);
        frame.add(cityLabel);
        frame.add(cityCombo);
        frame.add(classLabel);
        frame.add(sleeperBtn);
        frame.add(acBtn);
        frame.add(generalBtn);
        frame.add(foodLabel);
        frame.add(vegBox);
        frame.add(nonVegBox);
        frame.add(submitBtn);

        frame.setVisible(true);
    }

    public static void main(String[] args) {
        new RailwayTicketBookingForm();
    }
}
