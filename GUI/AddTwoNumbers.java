import javax.swing.*;
import java.awt.event.*;
public class AddTwoNumbers extends JFrame implements ActionListener
{
    JLabel label1,label2, resultLabel;
    JTextField text1,text2;
    JButton addbutton,mulbutton;
    AddTwoNumbers()
    {
        setTitle("Add Two Numbers");
        setSize(600,800);

        label1 = new JLabel("Enter First Number:");
        label1.setBounds(30,30,150,25);

        text1 = new JTextField();
        text1.setBounds(180,30,150,25);

        label2 = new JLabel("Enter Second Number:");
        label2.setBounds(30,70,150,25);

        text2 = new JTextField();
        text2.setBounds(180,70,150,25);
        
        addbutton = new JButton("Add");
        addbutton.setBounds(130,110,100,30);
        addbutton.addActionListener(this);
        
        mulbutton = new JButton("Multiply");
        mulbutton.setBounds(260,110,100,30);
        mulbutton.addActionListener(this);

        resultLabel = new JLabel("Result:");
        resultLabel.setBounds(30,150,300,25);

        add(label1);
        add(text1);
        add(label2);
        add(text2);
        add(addbutton);
        add(mulbutton);
        add(resultLabel);

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void actionPerformed(ActionEvent e)
    {
        try
        {
            int num1=Integer.parseInt(text1.getText());
            int num2=Integer.parseInt(text2.getText());
            if(e.getSource()==addbutton)
            {
                int sum=num1+num2;
                resultLabel.setText("Result: "+sum);
            }
            else if(e.getSource()==mulbutton)
            {
                int mul=num1*num2;
                resultLabel.setText("Result: "+mul);
            }
        }
        catch(NumberFormatException ex)
        {
            resultLabel.setText("Please enter valid integers.");
        }
    }
    public static void main(String[] args) {
        new AddTwoNumbers();
    }
   
}