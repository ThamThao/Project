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
import java.text.SimpleDateFormat;
import java.text.ParseException;
import java.util.Date;


public class Product{
    DefaultTableModel model;
    JButton add;
    JButton del;
    JButton upd;
    JTable ProdTable;
    JPanel title, search;
    JTextField searchbar;
    JLabel titleword, searchIcon, prod_id,prod_name,prod_price,prod_quantity,prod_inventorydate; 
    JTextField text_id,text_name,text_price,text_quantity,text_date;
    ImageIcon sIcon = new ImageIcon("search.png");
    public void producttabpage(JPanel ptp){
        titleword = new JLabel();
        titleword.setForeground(Color.white);
        titleword.setFont(new Font("Arial", Font.PLAIN, 30));
        titleword.setText("Product Information");
        titleword.setBounds(50,15,300,50);
        ptp.add(titleword);

        title = new JPanel();
        title.setLayout(null);
        title.setBackground(new Color(147, 181, 146));
        title.setBounds(3,3,1284,75);
        ptp.add(title);

        searchIcon = new JLabel();
        searchIcon.setIcon(sIcon);
        searchIcon.setBounds(550,105,300,40);
        ptp.add(searchIcon);

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
        ptp.add(searchbar);

        search = new JPanel();
        search.setLayout(null);
        search.setBackground(new Color(134, 144, 145)); 
        search.setBounds(3,78,1284,90);
        ptp.add(search);

        ptp.setLayout(null);
        ptp.setBounds(10,2,1290,1000);
        ptp.setBorder(BorderFactory.createLineBorder(new Color(203, 195, 227), 3));
        ptp.setBackground(Color.white);

        Object[] columns = {"Product ID","Product Name","Price(RM)","Quantity","Inventory Date"};
        model = new DefaultTableModel();
        model.setColumnIdentifiers(columns);
        ProdTable= new JTable();
        ProdTable.setModel(model);
        // Set the cell renderer to center align the content
        DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
        centerRenderer.setHorizontalAlignment(JLabel.CENTER);
        for (int i = 0; i < ProdTable.getColumnCount(); i++) {
            ProdTable.getColumnModel().getColumn(i).setCellRenderer(centerRenderer);
        }
        ProdTable.setFont(new Font("Verdana", Font.PLAIN, 15));
        ProdTable.setRowHeight(30);
        ProdTable.setAutoCreateRowSorter(true);
        ProdTable.setDefaultEditor(Object.class, null); // Prevent editing the table content
        JTableHeader tableHeader = ProdTable.getTableHeader();
        tableHeader.setFont(new Font("Verdana", Font.BOLD, 17));

        add = new JButton("Add");
        del = new JButton("del");
        upd = new JButton("upd");

        prod_id = new JLabel();
        prod_name = new JLabel();
        prod_price = new JLabel();
        prod_quantity = new JLabel();
        prod_inventorydate = new JLabel();

        text_id = new JTextField();
        text_name = new JTextField();
        text_price = new JTextField();
        text_quantity = new JTextField();
        text_date = new JTextField();

        prod_id.setBounds(20, 720, 200, 25);
        prod_name.setBounds(20, 775, 200, 25);
        prod_price.setBounds(20, 830, 200, 25);
        prod_quantity.setBounds(20, 885, 200, 25);
        prod_inventorydate.setBounds(20, 940, 200, 25);

        text_id.setBounds(220, 720, 300, 35);
        text_name.setBounds(220, 775, 300, 35);
        text_price.setBounds(220, 830, 300, 35);
        text_quantity.setBounds(220, 885, 300, 35);
        text_date.setBounds(220, 940, 300, 35);

        text_id.setFont(new Font("Arial",Font.PLAIN, 21));
        text_name.setFont(new Font("Arial",Font.PLAIN, 21));
        text_price.setFont(new Font("Arial",Font.PLAIN, 21));
        text_quantity.setFont(new Font("Arial",Font.PLAIN, 21));
        text_date.setFont(new Font("Arial",Font.PLAIN, 21));

        text_id.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                if ((e.getKeyChar() < '0' || e.getKeyChar() > '9' || e.getKeyChar() == ' ') && e.getKeyChar() != '\b' && e.getKeyChar() != '\n') {
                    text_id.setText("");
                    JOptionPane.showMessageDialog(null, "Only Number without Space");
                }
            }
        });
        text_price.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                if ((e.getKeyChar() < '0' || e.getKeyChar() > '9' || e.getKeyChar() == ' ') && e.getKeyChar() != '\b' && e.getKeyChar() != '\n' && e.getKeyChar() != '.') {
                    text_price.setText("");
                    JOptionPane.showMessageDialog(null, "Only Number without Space");
                }
            }
        });
        text_quantity.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                if ((e.getKeyChar() < '0' || e.getKeyChar() > '9' || e.getKeyChar() == ' ') && e.getKeyChar() != '\b' && e.getKeyChar() != '\n') {
                    text_quantity.setText("");
                    JOptionPane.showMessageDialog(null, "Only Number without Space");
                }
            }
        });
        

        prod_id.setText("Product ID:");
        prod_name.setText("Product Name:");
        prod_price.setText("Price(RM):");
        prod_quantity.setText("Quantity:");
        prod_inventorydate.setText("Inventory Date:");

        prod_id.setFont(new Font("Arial",Font.ITALIC, 21));
        prod_name.setFont(new Font("Arial",Font.ITALIC, 21));
        prod_price.setFont(new Font("Arial",Font.ITALIC, 21));
        prod_quantity.setFont(new Font("Arial",Font.ITALIC, 21));
        prod_inventorydate.setFont(new Font("Arial",Font.ITALIC, 21));

        prod_id.setForeground(new Color(83,143,223));
        prod_name.setForeground(new Color(83,143,223));
        prod_price.setForeground(new Color(83,143,223));
        prod_quantity.setForeground(new Color(83,143,223));
        prod_inventorydate.setForeground(new Color(83,143,223));

        add.setBackground(Color.cyan);
        add.setForeground(Color.white);
        add.setFont(new Font("Comic Sans", Font.BOLD,25));
        add.setText("Add");
        add.setFocusable(false);
        add.setBorder(BorderFactory.createEtchedBorder());
        add.setBackground(new Color(134, 144, 145 ));
        add.setOpaque(true); // Make sure the background color is visible

        // Add MouseListener to change button color on mouse enter/exit
        add.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                add.setBackground(new Color(158, 167, 167 )); // Change color when mouse enters
            }

            public void mouseExited(java.awt.event.MouseEvent evt) {
                add.setBackground(new Color(134, 144, 145 )); // Change back to default color when mouse exits
            }
        });

        del.setBackground(Color.cyan);
        del.setForeground(Color.white);
        del.setFont(new Font("Comic Sans", Font.BOLD,25));
        del.setText("Delete");
        del.setFocusable(false);
        del.setBorder(BorderFactory.createEtchedBorder());
        del.setBackground(new Color(134, 144, 145 ));
        del.setOpaque(true); // Make sure the background color is visible
        del.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                del.setBackground(new Color(158, 167, 167)); // Change color when mouse enters
            }
        
            public void mouseExited(java.awt.event.MouseEvent evt) {
                del.setBackground(new Color(134, 144, 145 )); // Change back to default color when mouse exits
            }
        });

        upd.setBackground(Color.cyan);
        upd.setForeground(Color.white);
        upd.setFont(new Font("Comic Sans", Font.BOLD,25));
        upd.setText("Update");
        upd.setFocusable(false);
        upd.setBorder(BorderFactory.createEtchedBorder());
        upd.setBackground(new Color(134, 144, 145));
        upd.setOpaque(true); // Make sure the background color is visible
        upd.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                upd.setBackground(new Color(158, 167, 167)); // Change color when mouse enters
            }
        
            public void mouseExited(java.awt.event.MouseEvent evt) {
                upd.setBackground(new Color(134, 144, 145 )); // Change back to default color when mouse exits
            }
        });

        add.setBounds(640,720,250,100);
        del.setBounds(940,720,250,100);
        upd.setBounds(790,870,250,100);

        JScrollPane pane = new JScrollPane(ProdTable);
        pane.setBounds(3,170,1285,520);

        File file = new File("Product.txt");

        try{
            FileReader fr = new FileReader(file);
            BufferedReader br11 = new BufferedReader(fr);

            DefaultTableModel model11 = (DefaultTableModel)ProdTable.getModel();
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
            if(text_id.getText().equals("") || text_name.getText().equals("") || text_price.getText().equals("") || text_quantity.getText().equals("") || text_date.getText().equals("")){
                JOptionPane.showMessageDialog(null,"Cannot Have EMPTY Blank");
            }
            else if(!isValidDate(text_date.getText())){
                JOptionPane.showMessageDialog(null,"Invalid Date Format");
            } // Check if the date is valid
            else {
                model.addRow(new Object[]{text_id.getText(),text_name.getText()
                        ,text_price.getText(),text_quantity.getText()
                        ,text_date.getText()});

                String id = text_id.getText();
                String name = text_name.getText();
                String price = text_price.getText();
                String quantity = text_quantity.getText();
                String date = text_date.getText();

                try{
                    if(id.length() > 0 && name.length() > 0 && price.length() > 0L && quantity.length() > 0 && date.length() > 0 )
                    {
                        FileWriter fw = new FileWriter(file);
                        BufferedWriter bw = new BufferedWriter(fw);

                        for(int i = 0 ; i < ProdTable.getRowCount();i++)
                        {
                            for(int j = 0 ; j < ProdTable.getColumnCount();j++){
                                bw.write(ProdTable.getValueAt(i,j).toString()+",");
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

                text_id.setText("");
                text_name.setText("");
                text_price.setText("");
                text_quantity.setText("");
                text_date.setText("");
            }
        });

        del.addActionListener(e -> {
            int gsr = ProdTable.getSelectedRow();
            if(gsr >= 0){
                model.removeRow(gsr);
            }
            else{
                JOptionPane.showMessageDialog(null, " del Error ");
            }
            if(file.exists())
            {
                try{
                    FileWriter fw = new FileWriter(file);
                    BufferedWriter bw = new BufferedWriter(fw);

                    for(int i = 0 ; i < ProdTable.getRowCount();i++)
                    {
                        for(int j = 0 ; j < ProdTable.getColumnCount();j++){
                            bw.write(ProdTable.getValueAt(i,j).toString()+",");
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

        upd.addActionListener(e -> {
            int gsr = ProdTable.getSelectedRow();

            if(gsr >= 0){
                if(text_id.getText().equals("") || text_name.getText().equals("") || text_price.getText().equals("") || text_quantity.getText().equals("") || text_date.getText().equals("")){
                    JOptionPane.showMessageDialog(null,"Cannot Have EMPTY Blank");
                }
                else if(!isValidDate(text_date.getText())){
                    JOptionPane.showMessageDialog(null,"Invalid Date Format");
                } // Check if the date is valid
                else{
                    model.setValueAt(text_id.getText(),gsr,0);
                    model.setValueAt(text_name.getText(),gsr,1);
                    model.setValueAt(text_price.getText(),gsr,2);
                    model.setValueAt(text_quantity.getText(),gsr,3);
                    model.setValueAt(text_date.getText(),gsr,4);

                    String id = text_id.getText();
                    String name = text_name.getText();
                    String price = text_price.getText();
                    String quantity = text_quantity.getText();
                    String date = text_date.getText();

                    if(file.exists())
                    {

                        try{
                            if(id.length() > 0 && name.length() > 0 && price.length() > 0L && quantity.length() > 0 && date.length() > 0 )
                            {
                                FileWriter fw = new FileWriter(file);
                                BufferedWriter bw = new BufferedWriter(fw);

                                for(int i = 0 ; i < ProdTable.getRowCount();i++)
                                {
                                    for(int j = 0 ; j < ProdTable.getColumnCount();j++){
                                        bw.write(ProdTable.getValueAt(i,j).toString()+",");
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
                    text_id.setText("");
                    text_name.setText("");
                    text_price.setText("");
                    text_quantity.setText("");
                    text_date.setText("");
                }
            }
            else{
                JOptionPane.showMessageDialog(null, " upd Error ");
            }

        });
        ptp.add(prod_id);
        ptp.add(prod_name);
        ptp.add(prod_price);
        ptp.add(prod_quantity);
        ptp.add(prod_inventorydate);

        ptp.add(text_id);
        ptp.add(text_name);
        ptp.add(text_price);
        ptp.add(text_quantity);
        ptp.add(text_date);

        ptp.add(add);
        ptp.add(del);
        ptp.add(upd);

        ptp.add(pane);
    }

    public void search(String str){
        model = (DefaultTableModel) ProdTable.getModel();
        TableRowSorter<DefaultTableModel> trs = new TableRowSorter<>(model);
        ProdTable.setRowSorter(trs);
        trs.setRowFilter(RowFilter.regexFilter(str));
    }
    public boolean isValidDate(String dateString) {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");
        sdf.setLenient(false);
        try {
            // Parse the string to a date
            Date date = sdf.parse(dateString);
            
            // Check if the parsed date is equal to the original string, ensuring a strict match
            return dateString.equals(sdf.format(date));
        } catch (ParseException e) {
            return false;
        }
    }
}