import javax.swing.*;

public class LoginScreen {
    JFrame frame;

    LoginScreen() {
        frame = new JFrame("Login Form");
        frame.setSize(400, 250);
        frame.setLayout(null);
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        JLabel userLabel = new JLabel("Username:");
        userLabel.setBounds(30, 30, 80, 25);

        JTextField userField = new JTextField();
        userField.setBounds(120, 30, 150, 25);

        JLabel passLabel = new JLabel("Password:");
        passLabel.setBounds(30, 70, 80, 25);

        JPasswordField passField = new JPasswordField();
        passField.setBounds(120, 70, 150, 25);

        JButton loginBtn = new JButton("Login");
        loginBtn.setBounds(120, 110, 100, 30);

        JLabel resultLabel = new JLabel("");
        resultLabel.setBounds(30, 150, 300, 25);

        // Action for login button
        loginBtn.addActionListener(e -> {
            String username = userField.getText();
            String password = new String(passField.getPassword());

            // Hardcoded credentials
            if (username.equals("admin") && password.equals("1234")) {
                resultLabel.setText("Login Successful!");
                resultLabel.setForeground(java.awt.Color.GREEN);
            } else {
                resultLabel.setText("Invalid Username or Password");
                resultLabel.setForeground(java.awt.Color.RED);
            }
        });

        frame.add(userLabel);
        frame.add(userField);
        frame.add(passLabel);
        frame.add(passField);
        frame.add(loginBtn);
        frame.add(resultLabel);

        frame.setVisible(true);
    }

    public static void main(String[] args) {
        new LoginScreen();
    }
}
