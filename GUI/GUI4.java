import javax.swing.*;
import java.awt.event.*;
public class GUI4 extends JFrame implements ActionListener
{
    GUI4()
    {
        setTitle("Add button");
        setSize(300,200);

        JLabel label = new JLabel("Hello, Swing GUI!", JLabel.CENTER);
        
        JButton button = new JButton("Click me");
        button.setBounds(100,100,120,40);
        button.addActionListener(this);

        add(button);
        add(label);

        setDefaultCloseOperation(EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e)
    {
        JOptionPane.showMessageDialog(this,"Button clicked");
    }
    public static void main(String[] args) {
        new GUI4();
    }   
}
