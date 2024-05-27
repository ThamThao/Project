import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import javax.swing.JOptionPane;

class file extends register {

    file(String username, String password, String password2) {
        File f1 = new File("data.txt");
        boolean registrationSuccessful = false;

        try {
            boolean fileExists = f1.exists();
            if (!fileExists) {
                if (f1.createNewFile()) {
                    System.out.println("File created successfully.");
                } else {
                    System.out.println("File already exists.");
                }
            }

            registrationSuccessful = write(f1, username, password, password2);
            if (registrationSuccessful) {
                JOptionPane.showMessageDialog(null, "Registration successful.");
                new Login();
            } else {
                JOptionPane.showMessageDialog(null, "Registration failed. The Username and Password must be longer than 4 characters. The Password must be same with the Confirm Password.");
                new register().reg();  // Open a new registration page
            }
        } catch (IOException e) {
            System.out.println("Error creating or writing to the file.");
        }
    }

    public boolean write(File f1, String username, String password, String password2) {
        try (FileWriter writer = new FileWriter(f1, true)) {
            byte[] u = (username + "\n").getBytes();
            byte[] p = (password + "\n").getBytes();
            byte[] p2 = (password2 + "\n").getBytes();

            if (username.length() >= 4 && password.length() >= 4 && password.equals(password2)) {
                writer.write(new String(u));
                writer.write(new String(p));
                writer.write(new String(p2));
                writer.write("-\n");
                System.out.println("Registration Successful");
                return true;
            } else {
                System.out.println("Invalid Username or Password");
                System.out.println("username.length() < 4: " + (username.length() < 4));
                System.out.println("password.length() < 4: " + (password.length() < 4));
                System.out.println("password.equals(password2): " + password.equals(password2));
                return false;
            }
        } catch (IOException e) {
            System.out.println("An error occurred while writing to the file.");
            return false;
        }
    }
}
