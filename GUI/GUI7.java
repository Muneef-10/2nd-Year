// import javax.swing.*;
// import java.awt.event.*;
// public class GUI7 extends JFrame implements ActionListener, ItemListener
// {
//     JLabel label1,label2, resultLabel;
//     // JTextField text1,text2;
//     JButton btn;
//     JCheckBox cb1,cb2;
//     GUI7()
//     {
//         setTitle("Add Two Numbers");
//         setSize(600,800);
//         setLayout(null);

//         cb1=new JCheckBox("Java");
//         cb1.setBounds(50,50,100,30);
//         cb1.addItemListener(null);

//         cb2=new JCheckBox("Python");
//         cb2.setBounds(50,80,100,30);
//         cb2.addItemListener(null);

//         btn=new JButton("Submit");
//         btn.setBounds(50,120,100,30);
//         btn.addActionListener(this);

//         add(cb1);
//         add(cb2);
//         add(btn);
     

//         setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
//         setVisible(true);
//     }

//     public void itemStateChanged(ItemEvent e)
//     {
//         String msg = "Selected";
//         if(cb1.isSelected()) msg +=": Java";
//         if(cb2.isSelected()) msg +=": Python";

//         JOptionPane.showMessageDialog(this, msg);
//     }
//     // public void actionPerformed(ActionEvent e)
//     // {
//     //     String msg = "Selected";
//     //     if(cb1.isSelected()) msg +=": Java";
//     //     if(cb2.isSelected()) msg +=": Python";

//     //     JOptionPane.showMessageDialog(this, msg);
//     //     // label1.setText(msg);
//     // }
//     public static void main(String[] args) {
//         new GUI7();
//     }

    
   
// }