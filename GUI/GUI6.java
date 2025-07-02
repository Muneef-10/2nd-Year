// import javax.swing.*;
// import java.awt.event.*;
// public class GUI6 extends JFrame implements ActionListener
// {
//     JLabel label1,label2, resultLabel;
//     // JTextField text1,text2;
//     JButton btn;
//     JCheckBox cb1,cb2;
//     GUI6()
//     {
//         setTitle("Add Two Numbers");
//         setSize(600,800);
//         setLayout(null);

//         cb1=new JCheckBox("Java");
//         cb1.setBounds(50,50,100,30);

//         cb2=new JCheckBox("Python");
//         cb2.setBounds(50,80,100,30);

//         btn=new JButton("Submit");
//         btn.setBounds(50,120,100,100);
//         btn.addActionListener(this);

//         add(cb1);
//         add(cb2);
//         add(btn);
     

//         setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//         setVisible(true);
//     }

//     public void actionPerformed(ActionEvent e)
//     {
//         String msg = "Selected";
//         if(cb1.isSelected()) msg +=": Java";
//         if(cb2.isSelected()) msg +=": Python";

//         JOptionPane.showMessageDialog(this, msg);
//         // label1.setText(msg);
//     }
//     public static void main(String[] args) {
//         new GUI6();
//     }
   
// }


import javax.swing.*;
// import java.awt.*;

public class GUI6  {
    JFrame frame;

    GUI6() {
        frame = new JFrame("Language Selector");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 300);
        frame.setLayout(null);

        JCheckBox cb1 = new JCheckBox("Java");
        cb1.setBounds(50, 50, 100, 30);

        JCheckBox cb2 = new JCheckBox("Python");
        cb2.setBounds(50, 80, 100, 30);

        JButton btn = new JButton("Submit");
        btn.setBounds(50, 130, 100, 30);

        // Using lambda for button action
        btn.addActionListener(e -> {
            String msg = "Selected";
            if (cb1.isSelected()) {
                msg += ": Java";
            }
            if (cb2.isSelected()) {
                msg += ": Python";
            }

            JOptionPane.showMessageDialog(frame, msg);
        });

        // Add components to the frame
        frame.add(cb1);
        frame.add(cb2);
        frame.add(btn);

        frame.setVisible(true);
    }

    public static void main(String[] args) {
        new GUI6();
    }
}
