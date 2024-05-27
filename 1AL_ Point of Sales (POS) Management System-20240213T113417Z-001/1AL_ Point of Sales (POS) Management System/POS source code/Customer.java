import javax.swing.*;
import javax.swing.table.DefaultTableCellRenderer;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.JTableHeader;
import javax.swing.table.TableRowSorter;
import java.awt.*;
import java.awt.event.FocusEvent;
import java.awt.event.FocusListener;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class Customer {
    DefaultTableModel model;
    JScrollPane scroll;
    JButton add, delete, update;
    JPanel title, search;
    JTextField searchbar, cusID, name, contact, gender, email; 
    JLabel titleword, searchIcon, CID, CName, CContact, CGender, CEmail;
    JTable customertable;
    ImageIcon sIcon = new ImageIcon("search.png");
    
    public void customertabpage(JPanel ctp){
        titleword = new JLabel();
        titleword.setForeground(Color.white);
        titleword.setFont(new Font("Arial", Font.PLAIN, 30));
        titleword.setText("Customer Information");
        titleword.setBounds(50,15,300,50);
        ctp.add(titleword);

        title = new JPanel();
        title.setLayout(null);
        // color of the top panel
        title.setBackground(new Color(147, 181, 146));
        title.setBounds(3,3,1284,75);
        ctp.add(title);

        searchIcon = new JLabel();
        searchIcon.setIcon(sIcon);
        searchIcon.setBounds(550,105,300,40);
        ctp.add(searchIcon);

        searchbar = new JTextField();
        searchbar.setFocusable(true);
        searchbar.addFocusListener(new FocusListener() {
            @Override
            public void focusGained(FocusEvent e) {
                if(searchbar.getText().equals("Search by Name")) {
                    searchbar.setText("");
                }
                searchbar.setForeground(Color.BLACK);
                searchbar.setFont(new Font("Arial", Font.PLAIN, 23));
            }

            @Override
            public void focusLost(FocusEvent e) {
                if(searchbar.getText().equals("")) {
                    searchbar.setText("Search by Name");
                }
                searchbar.setForeground(Color.LIGHT_GRAY);
                searchbar.setFont(new Font("Arial", Font.PLAIN, 23));
            }
        });
        searchbar.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                String searchString = searchbar.getText();
                search(searchString);
            }
        });
        searchbar.setBounds(50, 105, 500, 40);
        ctp.add(searchbar);

        search = new JPanel();
        search.setLayout(null);
        //  color of the search panel
        search.setBackground(new Color(134, 144, 145)); 
        search.setBounds(3,78,1284,90);
        ctp.add(search);

        ctp.setLayout(null);
        ctp.setBounds(10,2,1290,1000);
        ctp.setBorder(BorderFactory.createLineBorder(new Color(203, 195, 227), 3));
        ctp.setBackground(Color.white);
        customertable = new JTable();
        String[] columns = {"Customer ID", "Name","Contact", "Gender", "Email"}; 
        model = new DefaultTableModel();

        model.setColumnIdentifiers(columns);
        customertable.setModel(model);
         // Set the cell renderer to center align the content
        DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
        centerRenderer.setHorizontalAlignment(JLabel.CENTER);
        for (int i = 0; i < customertable.getColumnCount(); i++) {
            customertable.getColumnModel().getColumn(i).setCellRenderer(centerRenderer);
        }
        customertable.setBackground(Color.white);
        customertable.setForeground(Color.black);
        customertable.setFont(new Font("Verdana", Font.PLAIN, 15));
        customertable.setRowHeight(30);
        customertable.setAutoCreateRowSorter(true);
        customertable.setDefaultEditor(Object.class, null); // Prevent editing the table content
        JTableHeader tableHeader = customertable.getTableHeader();
        tableHeader.setFont(new Font("Verdana", Font.BOLD, 17));
        

        scroll = new JScrollPane(customertable);
        scroll.setBackground(Color.white);
        scroll.setBounds(3,168,1285,500);
        ctp.add(scroll);

        CID = new JLabel();
        CName = new JLabel();
        CContact = new JLabel();
        CGender = new JLabel(); 
        CEmail = new JLabel();

        CID.setText("Customer ID:");
        CID.setFont(new Font("Arial",Font.ITALIC, 19));
        CID.setForeground(new Color(212,123,123));
        CID.setBounds(10,700,150,30);
        ctp.add(CID);

        CName.setText("Customer Name:");
        CName.setFont(new Font("Arial",Font.ITALIC, 19));
        CName.setForeground(new Color(212,123,123));
        CName.setBounds(10,760,150,30);
        ctp.add(CName);

        CContact.setText("Customer Contact:");
        CContact.setFont(new Font("Arial",Font.ITALIC, 19));
        CContact.setForeground(new Color(212,123,123));
        CContact.setBounds(10,820,180,30);
        ctp.add(CContact);

        CGender.setText("Customer Gender:"); 
        CGender.setFont(new Font("Arial",Font.ITALIC, 19));
        CGender.setForeground(new Color(212,123,123));
        CGender.setBounds(700,700,200,30); 
        ctp.add(CGender);

        CEmail.setText("Customer Email:");
        CEmail.setFont(new Font("Arial",Font.ITALIC, 19));
        CEmail.setForeground(new Color(212,123,123));
        CEmail.setBounds(700,760,150,30);
        ctp.add(CEmail);

        cusID = new JTextField();
        name = new JTextField();
        contact = new JTextField();
        gender = new JTextField();
        email = new JTextField();

        cusID.setFont(new Font("Arial",Font.PLAIN, 20));
        cusID.setBounds(200, 700, 300, 35);
        cusID.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                if ((e.getKeyChar() < '0' || e.getKeyChar() > '9' || e.getKeyChar() == ' ') && e.getKeyChar() != '\b' && e.getKeyChar() != '\n') {
                    cusID.setText("");
                    JOptionPane.showMessageDialog(null, "Only Number without Space");
                }
            }
        });
        ctp.add(cusID);
        name.setFont(new Font("Arial",Font.PLAIN, 20));
        name.setBounds(200, 760, 300, 35);
        ctp.add(name);
        contact.setFont(new Font("Arial",Font.PLAIN, 20));
        contact.setBounds(200, 820, 300, 35);
        contact.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                if ((e.getKeyChar() < '0' || e.getKeyChar() > '9') && e.getKeyChar() != '\b' && e.getKeyChar() != '\n') {
                    contact.setText("");
                    JOptionPane.showMessageDialog(null, "Only Number without Space");
                }else {
                    String contactText = contact.getText().replaceAll("\\s", ""); // Remove spaces
                    if (contactText.length() > 10) { // Adjust the length as needed
                        contact.setText(contactText.substring(0, 10)); 
                        JOptionPane.showMessageDialog(null, "Contact number should be up to 10 digits");
                    } // Add contact number validation  
                }
            }
        });
        ctp.add(contact);
        gender.setFont(new Font("Arial",Font.PLAIN, 20));
        gender.setBounds(870, 700, 300, 35);
        gender.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                if (e.getKeyChar() != 'f' && e.getKeyChar() != 'm' && e.getKeyChar() != 'F' && e.getKeyChar() != 'M' && e.getKeyChar() != '\b' && e.getKeyChar() != '\n' || e.getKeyChar() == ' ') {
                    gender.setText("");
                    JOptionPane.showMessageDialog(null, "Input F/M only");
                }
                if(gender.getText().length() > 1){
                    gender.setText("");
                    JOptionPane.showMessageDialog(null, "Input F/M only");
                }

            }
        });
        ctp.add(gender);
        email.setFont(new Font("Arial",Font.PLAIN, 20));
        email.setBounds(870, 760, 300, 35);
        email.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                if (e.getKeyChar() == ' '){
                    email.setText("");
                    JOptionPane.showMessageDialog(null, "Cannot Input Space");
                }
                
            }
        });
        
        ctp.add(email);

        
        add = new JButton();
        delete = new JButton();
        update = new JButton();

        add.setBounds(220,880,200,80);
        add.setBackground(Color.white);
        add.setForeground(Color.white);
        add.setFont(new Font("Comic Sans", Font.BOLD,25));
        add.setText("Add");
        add.setFocusable(false);
        add.setBorder(BorderFactory.createEmptyBorder());

        
        add.setBackground(new Color(134, 144, 145 ));
        add.setOpaque(true); 

        // Add MouseListener to change button color on mouse enter/exit
        add.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                add.setBackground(new Color(158, 167, 167 )); // Change color when mouse enters
            }

            public void mouseExited(java.awt.event.MouseEvent evt) {
                add.setBackground(new Color(134, 144, 145 )); // Change back to default color when mouse exits
            }
        });
        ctp.add(add);

        delete.setBounds(530,880,200,80);
        delete.setBackground(Color.white);
        delete.setForeground(Color.white);
        delete.setFont(new Font("Comic Sans", Font.BOLD,25));
        delete.setText("Delete");
        delete.setFocusable(false);
        delete.setBorder(BorderFactory.createEmptyBorder());
        
        delete.setBackground(new Color(134, 144, 145 ));//change the color of the button
        delete.setOpaque(true); // Make sure the background color is visible
        delete.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                delete.setBackground(new Color(158, 167, 167)); // Change color when mouse enters
            }
        
            public void mouseExited(java.awt.event.MouseEvent evt) {
                delete.setBackground(new Color(134, 144, 145 )); // Change back to default color when mouse exits
            }
        });
        ctp.add(delete);

        update.setBounds(850,880,200,80);
        update.setBackground(Color.white);
        update.setForeground(Color.white);
        update.setFont(new Font("Comic Sans", Font.BOLD,25));
        update.setText("Update");
        update.setFocusable(false);
        update.setBorder(BorderFactory.createEmptyBorder());
        update.setBackground(new Color(134, 144, 145 ));//change the color of the button
        update.setOpaque(true); // Make sure the background color is visible
        update.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                update.setBackground(new Color(158, 167, 167)); // Change color when mouse enters
            }
        
            public void mouseExited(java.awt.event.MouseEvent evt) {
                update.setBackground(new Color(134, 144, 145 )); // Change back to default color when mouse exits
            }
        });
        ctp.add(update);



        File file = new File("Customer.txt");

        try{
            FileReader fr = new FileReader(file);
            BufferedReader br11 = new BufferedReader(fr);

            DefaultTableModel model11 = (DefaultTableModel)customertable.getModel();
            Object[] lines = br11.lines().toArray();

            for (Object line : lines) {
                String[] row11 = line.toString().split(",");
                model11.addRow(row11);
            }

        }
        catch(FileNotFoundException ex)
        {
            System.out.println("FILE NO FOUND");
        }

        add.addActionListener(e -> {
            if(cusID.getText().equals("") || name.getText().equals("") || contact.getText().equals("") || gender.getText().equals("") || email.getText().equals("")){
                JOptionPane.showMessageDialog(null,"Cannot Have EMPTY Blank");
            } else if (!validateEmail(email.getText())) {
                JOptionPane.showMessageDialog(null, "Invalid Email");
            } // Add email validation
            else{
                model.addRow(new Object[]{cusID.getText(),name.getText()
                        ,contact.getText(),gender.getText()
                        ,email.getText()});

                String id = cusID.getText();
                String name2 = name.getText();
                String price = contact.getText();
                String quantity = gender.getText();
                String date = email.getText();

                try{
                    if(id.length() > 0 && name2.length() > 0 && price.length() > 0L && quantity.length() > 0 && date.length() > 0 )
                    {
                        FileWriter fw = new FileWriter(file);
                        BufferedWriter bw = new BufferedWriter(fw);

                        for(int i = 0 ; i < customertable.getRowCount();i++)
                        {
                            for(int j = 0 ; j < customertable.getColumnCount();j++){
                                bw.write(customertable.getValueAt(i,j).toString()+",");
                            }

                            bw.newLine();
                        }
                        bw.close();
                        fw.close();
                    }
                    else
                    {
                        System.out.println("invaild input this data will not be saved in the file");
                    }
                }
                catch(Exception ex)
                {
                    System.out.println("error");
                }



                cusID.setText("");
                name.setText("");
                contact.setText("");
                gender.setText("");
                email.setText("");
            }
        });

        delete.addActionListener(e -> {
            int gsr = customertable.getSelectedRow();
            if(gsr >= 0){
                model.removeRow(gsr);
            }
            else{
                JOptionPane.showMessageDialog(null, " Delete Error ");
            }
            if(file.exists())
            {
                try{
                    FileWriter fw = new FileWriter(file);
                    BufferedWriter bw = new BufferedWriter(fw);

                    for(int i = 0 ; i < customertable.getRowCount();i++)
                    {
                        for(int j = 0 ; j < customertable.getColumnCount();j++){
                            bw.write(customertable.getValueAt(i,j).toString()+",");
                        }

                        bw.newLine();
                    }
                    bw.close();
                    fw.close();
                }
                catch(Exception ex)
                {
                    System.out.println("error");
                }
            }

        });

        update.addActionListener(e -> {
            int gsr = customertable.getSelectedRow();

            if(gsr >= 0){
                if(cusID.getText().equals("") || name.getText().equals("") || contact.getText().equals("") || gender.getText().equals("") || email.getText().equals("")){
                    JOptionPane.showMessageDialog(null,"Cannot Have EMPTY Blank");
                } else if (!validateEmail(email.getText())) {
                    JOptionPane.showMessageDialog(null, "Invalid Email");
                } // Add email validation
                else{
                    model.setValueAt(cusID.getText(),gsr,0);
                    model.setValueAt(name.getText(),gsr,1);
                    model.setValueAt(contact.getText(),gsr,2);
                    model.setValueAt(gender.getText(),gsr,3);
                    model.setValueAt(email.getText(),gsr,4);

                    String id = cusID.getText();
                    String name2 = name.getText();
                    String price = contact.getText();
                    String quantity = gender.getText();
                    String date = email.getText();

                    if(file.exists())
                    {

                        try{
                            if(id.length() > 0 && name2.length() > 0 && price.length() > 0L && quantity.length() > 0 && date.length() > 0 )
                            {
                                FileWriter fw = new FileWriter(file);
                                BufferedWriter bw = new BufferedWriter(fw);

                                for(int i = 0 ; i < customertable.getRowCount();i++)
                                {
                                    for(int j = 0 ; j < customertable.getColumnCount();j++){
                                        bw.write(customertable.getValueAt(i,j).toString()+",");
                                    }

                                    bw.newLine();
                                }
                                bw.close();
                                fw.close();
                            }
                            else
                            {
                                System.out.println("invaild input this data will not be saved in the file");
                            }
                        }
                        catch(Exception ex)
                        {
                            System.out.println("error");
                        }
                    }
                    cusID.setText("");
                    name.setText("");
                    contact.setText("");
                    gender.setText("");
                    email.setText("");
                }
            }
            else{
                JOptionPane.showMessageDialog(null, " Update Error ");
            }
        });
    }
    public void search(String str){
        model = (DefaultTableModel) customertable.getModel();
        TableRowSorter<DefaultTableModel> trs = new TableRowSorter<>(model);
        customertable.setRowSorter(trs);
        trs.setRowFilter(RowFilter.regexFilter(str));
    }
    // Add email validation
     public boolean validateEmail(String email) {
        String emailRegex = "^[a-zA-Z0-9_+&*-]+(?:\\.[a-zA-Z0-9_+&*-]+)*@(?:[a-zA-Z0-9-]+\\.)+[a-zA-Z]{2,7}$";
        Pattern pattern = Pattern.compile(emailRegex);
        Matcher matcher = pattern.matcher(email);
        return matcher.matches();
    }
}