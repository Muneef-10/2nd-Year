import javax.swing.*; 
import java.awt.*; 
import java.awt.event.*; 
public class CountryCapital extends JFrame implements ActionListener { 
JComboBox<String> countryBox, capitalBox; 
JButton submitBtn; 
JLabel resultLabel; 
// Parallel arrays for countries and their corresponding capitals 
String[] countries = {"India", "USA", "France", "Japan", "Australia"}; 
String[] capitals = {"New Delhi", "Washington D.C.", "Paris", "Tokyo", "Canberra"}; 
CountryCapital () { 
setTitle("Country-Capital Match (No Collection)"); 
setSize(400, 250); 
setLayout(null); 
setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 
setLocationRelativeTo(null); // Center the window 
// GUI Components 
JLabel countryLabel = new JLabel("Select Country:"); 
        countryLabel.setBounds(30, 30, 120, 25); 
        countryBox = new JComboBox<>(countries); 
        countryBox.setBounds(160, 30, 180, 25); 
 
        JLabel capitalLabel = new JLabel("Select Capital:"); 
        capitalLabel.setBounds(30, 70, 120, 25); 
        capitalBox = new JComboBox<>(capitals); 
        capitalBox.setBounds(160, 70, 180, 25); 
 
        submitBtn = new JButton("Submit"); 
        submitBtn.setBounds(130, 110, 100, 30); 
        submitBtn.addActionListener(this); 
 
        resultLabel = new JLabel(""); 
        resultLabel.setBounds(30, 160, 330, 25); 
        // resultLabel.setHorizontalAlignment(JLabel.CENTER); 
 
        add(countryLabel); 
        add(countryBox); 
        add(capitalLabel); 
        add(capitalBox); 
        add(submitBtn); 
        add(resultLabel); 
 
        setVisible(true); 
    } 
 
    @Override 
    public void actionPerformed(ActionEvent e) { 
        String selectedCountry = (String) countryBox.getSelectedItem(); 
        String selectedCapital = (String) capitalBox.getSelectedItem(); 
 
        // Find index of selected country 
        int index = -1; 
        for (int i = 0; i < countries.length; i++) { 
            if (countries[i].equals(selectedCountry)) { 
                index = i; 
                break; 
            } 
        } 
 
        if (index != -1 && capitals[index].equals(selectedCapital)) { 
            resultLabel.setForeground(Color.GREEN); 
            resultLabel.setText("   Correct Answer!"); 
        } else { 
            String correctCapital = (index != -1) ? capitals[index] : "Unknown"; 
            resultLabel.setForeground(Color.RED); 
            resultLabel.setText("  Incorrect! Correct capital of " + selectedCountry + " is " + 
correctCapital); 
        } 
} 
public static void main(String[] args) { 
new CountryCapital(); 
} 
} 