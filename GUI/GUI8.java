import javax.swing.*;
import java.awt.event.*;
public class GUI8 extends JFrame implements ActionListener, ItemListener
{
    JRadioButton r1,r2,r3;
    JButton btn;
    GUI8()
    {
        setTitle("Gender");
        setSize(600,800);
        setLayout(null);

        r1 = new JRadioButton("Male");
        r1.setBounds(50,50,100,30);

        r2 = new JRadioButton("Female");
        r2.setBounds(50,80,100,30);
        
        r3 = new JRadioButton("Gaurav Neutral");
        r3.setBounds(50,110,150,30);

        ButtonGroup bg=new ButtonGroup();
        bg.add(r1);
        bg.add(r2);
        bg.add(r3);
        
        btn=new JButton("Submit");
        btn.setBounds(50,150,100,30);
        btn.addActionListener(this);

        add(r1);
        add(r2);
        add(r3);
        add(btn);
     

        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setVisible(true);
    }

    public void itemStateChanged(ItemEvent e)
    {
        // String msg = "Selected";
        // if(cb1.isSelected()) msg +=": Java";
        // if(cb2.isSelected()) msg +=": Python";

        // JOptionPane.showMessageDialog(this, msg);
    }
    public void actionPerformed(ActionEvent e)
    {
        String msg = "Selected: ";
        if(r1.isSelected()) msg +="Male";
        if(r2.isSelected()) msg +="Female";
        if(r3.isSelected()) msg +="Gaurav Neutral";

        JOptionPane.showMessageDialog(this, msg);
        // label1.setText(msg);
    }
    public static void main(String[] args) {
        new GUI8();
    }

    
   
}