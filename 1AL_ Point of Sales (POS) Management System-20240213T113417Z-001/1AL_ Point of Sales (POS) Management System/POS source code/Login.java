import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;

class Login implements ActionListener {
    private final JTextField text1, text2;
    private final JButton b1, b2;
    private final JFrame frame;

    Login() {
        frame = new JFrame("POS System");
        frame.setLayout(null);
        frame.setSize(500, 400);
        frame.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
        frame.setResizable(false);
        frame.getContentPane().setBackground(Color.white);

        JLabel logo = new JLabel(new ImageIcon("logo1.png"));
        logo.setBounds(125, 1, 250, 250);
        frame.add(logo);

        JLabel userLabel = new JLabel("Username:");
        userLabel.setBounds(10, 260, 100, 30);
        frame.add(userLabel);

        text1 = new JTextField();
        text1.setBounds(80, 260, 100, 30);
        frame.add(text1);

        JLabel passLabel = new JLabel("Password:");
        passLabel.setBounds(270, 260, 100, 30);
        frame.add(passLabel);

        text2 = new JPasswordField();  // Using JPasswordField for password input
        text2.setBounds(350, 260, 100, 30);
        frame.add(text2);

        b1 = new JButton("Log In");
        b1.setBounds(130, 300, 100, 30);
        b1.addActionListener(this);
        frame.add(b1);

        b2 = new JButton("Register");
        b2.setBounds(280, 300, 100, 30);
        b2.addActionListener(this);
        frame.add(b2);

        frame.setVisible(true);
    }

    public void actionPerformed(ActionEvent a) {
        String username = text1.getText();
        String password = text2.getText();
        File file = new File("data.txt");

        if (a.getSource() == b1) {
            try {
                BufferedReader reader = new BufferedReader(new FileReader(file));
                String line;
                while ((line = reader.readLine()) != null) {
                    if (username.equals(line)) {
                        line = reader.readLine();
                        if (password.equals(line)) {
                            frame.dispose();
                            new OOP();
                            break;
                        }
                    }
                    reader.readLine(); // Skip the confirmation password line
                }
                if (line == null) {
                    JOptionPane.showMessageDialog(null, "Invalid Username or Password");
                }
                reader.close();
            } catch (IOException ex) {
                JOptionPane.showMessageDialog(null, "Invalid Username or Password");
            }
        } else if (a.getSource() == b2) {
            frame.dispose();
            new register().reg();
        }
    }

    public static void main(String[] args) {
        new Login();
    }
}
