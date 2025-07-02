import javax.swing.*;

public class Add 
{
    JFrame frame;
    Add()
    {
        frame=new JFrame("ADD and MUL");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setLayout(null);
        frame.setSize(500,500);

        JLabel lbl1=new JLabel("Enter 1st number: ");
        lbl1.setBounds(30,30,150,30);
        JTextField text1=new JTextField();
        text1.setBounds(180,30,100,30);

        JLabel lbl2=new JLabel("Enter 2nd number: ");
        lbl2.setBounds(30,50,150,30);
        JTextField text2=new JTextField();
        text2.setBounds(180,50,100,30);

        JButton mul=new JButton("MULTIPLE");
        mul.setBounds(50,80,80,30);

        JButton ad=new JButton("ADDTION");
        ad.setBounds(50,120,80,30);

        JLabel result=new JLabel("Result: ");
        result.setBounds(20,150,150,30);

        mul.addActionListener(e->{
            try
            {
                int num1=Integer.parseInt(text1.getText());
                int num2=Integer.parseInt(text2.getText());
                int mult=num1*num2;
                result.setText("Result: "+mult);
                JOptionPane.showMessageDialog(frame, "Cost"+mult);

            }
            catch(Exception ex)
            {
                result.setText("Enter number");
            }
        });

        ad.addActionListener(e->{
            try
            {
                int num1=Integer.parseInt(text1.getText());
                int num2=Integer.parseInt(text2.getText());
                int add=num1+num2;
                result.setText("Result: "+add);
            }
            catch(Exception ex)
            {
                result.setText("Enter number");
            }
        });

        frame.add(lbl1);
        frame.add(text1);
        frame.add(lbl2);
        frame.add(text2);
        frame.add(ad);
        frame.add(mul);
        frame.add(result);
        frame.setVisible(true);
        
    }
    public static void main(String[] args) {
        new Add();
    }
}