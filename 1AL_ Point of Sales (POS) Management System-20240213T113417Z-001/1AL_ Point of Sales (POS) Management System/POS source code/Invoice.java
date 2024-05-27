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

public class Invoice{
    double totalprice;
    DefaultTableModel m;
    JPanel title, search;
    JTable Invtable;
    JButton add,del,upd;
    JLabel titleword;
    JLabel searchIcon;
    JLabel inv_n;
    JLabel inv_d;
    JLabel inv_pt;  
    JLabel inv_q;
    JLabel inv_up; 
    JTextField searchbar;
    JTextField txt_n;
    JTextField txt_d;
    JTextField txt_pt; 
    JTextField txt_q;
    JTextField txt_up; 
    ImageIcon sIcon = new ImageIcon("search.png");
    public void invoicetabpage(JPanel itp){
        titleword = new JLabel();
        titleword.setForeground(Color.white);
        titleword.setFont(new Font("Arial", Font.PLAIN, 30));
        titleword.setText("Invoice");
        titleword.setBounds(50,15,300,50);

        title = new JPanel();
        title.setLayout(null);
        title.setBackground(new Color(147, 181, 146));
        title.setBounds(3,3,1284,75);

        searchIcon = new JLabel();
        searchIcon.setIcon(sIcon);
        searchIcon.setBounds(550,105,300,40);

        searchbar = new JTextField();
        searchbar.setFocusable(true);
        searchbar.addFocusListener(new FocusListener() {
            @Override
            public void focusGained(FocusEvent e) {
                if(searchbar.getText().equals("Search by Number")) {
                    searchbar.setText("");
                }
                searchbar.setForeground(Color.BLACK);
                searchbar.setFont(new Font("Arial", Font.PLAIN, 23));
            }

            @Override
            public void focusLost(FocusEvent e) {
                if(searchbar.getText().equals("")) {
                    searchbar.setText("Search by Number");
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
                if ((e.getKeyChar() < '0' || e.getKeyChar() > '9' || e.getKeyChar() == ' ') && e.getKeyChar() != '\b' && e.getKeyChar() != '\n') {
                    searchbar.setText("");
                    JOptionPane.showMessageDialog(null, "Only Number without Space");
                }
                else{
                    String searchString = searchbar.getText();
                    search(searchString);
                }
            }
        });
        searchbar.setBounds(50, 105, 500, 40);

        search = new JPanel();
        search.setLayout(null);
        search.setBackground(new Color(134, 144, 145)); 
        search.setBounds(3,78,1284,90);

        itp.setLayout(null);
        itp.setBounds(10,2,1290,1000);
        itp.setBorder(BorderFactory.createLineBorder(new Color(203, 195, 227), 3));
        itp.setBackground(Color.white);

        Object [] col ={"Invoice Number","Invoice Date"
    ,"Payment Type","Quantity","Unit Price(RM)","Total"};
        m = new DefaultTableModel();
        m.setColumnIdentifiers(col);
        Invtable = new JTable();
        Invtable.setModel(m);
        // Set the cell renderer to center align the content
        DefaultTableCellRenderer centerRenderer = new DefaultTableCellRenderer();
        centerRenderer.setHorizontalAlignment(JLabel.CENTER);
        for (int i = 0; i < Invtable.getColumnCount(); i++) {
            Invtable.getColumnModel().getColumn(i).setCellRenderer(centerRenderer);
        }
        Invtable.setFont(new Font("Verdana", Font.PLAIN, 15));
        Invtable.setRowHeight(30);
        Invtable.setAutoCreateRowSorter(true);
        Invtable.setDefaultEditor(Object.class, null); // Prevent editing the table content
        JTableHeader tableHeader = Invtable.getTableHeader();
        tableHeader.setFont(new Font("Verdana", Font.BOLD, 17));

        add = new JButton("Add");
        del = new JButton("Delete");
        upd = new JButton("Update");

        inv_n = new JLabel();
        inv_d = new JLabel();
        inv_pt = new JLabel();
        inv_q = new JLabel();
        inv_up = new JLabel();

        txt_n = new JTextField();
        txt_d  = new JTextField();
        txt_pt = new JTextField();
        txt_q = new JTextField();
        txt_up  = new JTextField();

        inv_n.setBounds(20, 720, 200, 25);
        inv_d.setBounds(20, 770, 200, 25);
        inv_pt.setBounds(20, 820, 200, 25);
        inv_q.setBounds(20, 870, 200, 25);
        inv_up.setBounds(20, 920, 200, 25);

        txt_n.setBounds(220, 720, 300, 30);
        txt_d.setBounds(220, 770, 300, 30);
        txt_pt.setBounds(220, 820, 300, 30);
        txt_q.setBounds(220,870,300,30);
        txt_up.setBounds(220, 920, 300, 30);

        txt_n.setFont(new Font("Arial",Font.PLAIN, 21));
        txt_d.setFont(new Font("Arial",Font.PLAIN, 21));
        txt_pt.setFont(new Font("Arial",Font.PLAIN, 21));
        txt_q.setFont(new Font("Arial",Font.PLAIN, 21));
        txt_up.setFont(new Font("Arial",Font.PLAIN, 21));

        txt_n.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                if ((e.getKeyChar() < '0' || e.getKeyChar() > '9' || e.getKeyChar() == ' ') && e.getKeyChar() != '\b' && e.getKeyChar() != '\n') {
                    txt_n.setText("");
                    JOptionPane.showMessageDialog(null, "Only Number without Space");
                }
            }
        });
        txt_q.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                if ((e.getKeyChar() < '0' || e.getKeyChar() > '9' || e.getKeyChar() == ' ') && e.getKeyChar() != '\b' && e.getKeyChar() != '\n') {
                    txt_q.setText("");
                    JOptionPane.showMessageDialog(null, "Only Number without Space");
                }
            }
        });
        txt_up.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                if ((e.getKeyChar() < '0' || e.getKeyChar() > '9' || e.getKeyChar() == ' ') && e.getKeyChar() != '\b' && e.getKeyChar() != '\n' && e.getKeyChar() != '.') {
                    txt_up.setText("");
                    JOptionPane.showMessageDialog(null, "Only Number without Space");
                }
            }
        });

        inv_n.setText("Invoice Number:");
        inv_d.setText("Invoice Date:");
        inv_pt.setText("Payment Type:");
        inv_q.setText("Quantity:");
        inv_up.setText("Unit Price(RM):");

        inv_n.setFont(new Font("Arial",Font.ITALIC, 21));
        inv_d.setFont(new Font("Arial",Font.ITALIC, 21));
        inv_pt.setFont(new Font("Arial",Font.ITALIC, 21));
        inv_q.setFont(new Font("Arial",Font.ITALIC, 21));
        inv_up.setFont(new Font("Arial",Font.ITALIC, 21));

        add.setBackground(Color.cyan);
        add.setForeground(Color.white);
        add.setFont(new Font("Comic Sans", Font.BOLD,25));
        add.setText("Add");
        add.setFocusable(false);
        add.setBorder(BorderFactory.createEtchedBorder());
        add.setBackground(new Color(134, 144, 145));
        add.setOpaque(true); // Make sure the background color is visible

        // Add MouseListener to change button color on mouse enter/exit
        add.addMouseListener(new java.awt.event.MouseAdapter() {
            public void mouseEntered(java.awt.event.MouseEvent evt) {
                add.setBackground(new Color(158, 167, 167 )); // Change color when mouse enters
            }

            public void mouseExited(java.awt.event.MouseEvent evt) {
                add.setBackground(new Color(134, 144, 145)); // Change back to default color when mouse exits
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
        upd.setBackground(new Color(134, 144, 145 ));
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

        JScrollPane pane = new JScrollPane(Invtable);
        pane.setBounds(3,170,1285,520);

        File file = new File("Invoice.txt");

        try{
            FileReader fr = new FileReader(file);
            BufferedReader br11 = new BufferedReader(fr);

            DefaultTableModel model11 = (DefaultTableModel)Invtable.getModel();
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
            if(txt_n.getText().equals("") || txt_d.getText().equals("") || txt_pt.getText().equals("") || txt_q.getText().equals("")||txt_up.getText().equals("")){
                JOptionPane.showMessageDialog(null,"Cannot Have EMPTY Blank");
            }
            else if(!isValidDate(txt_d.getText()))
            {
                JOptionPane.showMessageDialog(null,"Invalid Date");
            }
            else {
                totalprice = Integer.parseInt(txt_q.getText()) * Double.parseDouble(txt_up.getText());
                m.addRow(new Object[]{txt_n.getText(),txt_d.getText()
                        ,txt_pt.getText(),txt_q.getText(),txt_up.getText(),totalprice});

            String name = txt_n.getText();
            String due= txt_d.getText();
            String p_m = txt_pt.getText();
            String q = txt_q.getText();
            String up = txt_up.getText();
            
                    try{
                        if(name.length() > 0 && due.length() > 0 && p_m.length() > 0 && q.length() > 0 && up.length() > 0)
                    {
                        FileWriter fw = new FileWriter(file);
                        BufferedWriter bw = new BufferedWriter(fw);
                
                        for(int i = 0 ; i < Invtable.getRowCount();i++)
                        {
                            for(int j = 0 ; j < Invtable.getColumnCount();j++){
                            bw.write(Invtable.getValueAt(i,j).toString()+",");
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
                        
                txt_n.setText("");
                txt_d.setText("");
                txt_pt.setText("");
                txt_q.setText("");
                txt_up.setText("");

                } 
        });

        del.addActionListener(e -> {
            int gsr = Invtable.getSelectedRow();
            if(gsr >= 0){
                m.removeRow(gsr);
            }
            else{
                JOptionPane.showMessageDialog(null, " Delete Error ");   
            }
            if(file.exists())
                {
                try{
                    FileWriter fw = new FileWriter(file);
                    BufferedWriter bw = new BufferedWriter(fw);
            
                    for(int i = 0 ; i < Invtable.getRowCount();i++)
                    {
                        for(int j = 0 ; j < Invtable.getColumnCount();j++){
                        bw.write(Invtable.getValueAt(i,j).toString()+",");
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
            int gsr = Invtable.getSelectedRow();
    
            if(gsr >= 0){
                if(txt_n.getText().equals("") || txt_d.getText().equals("") || txt_pt.getText().equals("") || txt_q.getText().equals("") || txt_up.getText().equals("")){
                    JOptionPane.showMessageDialog(null,"Cannot Have EMPTY Blank");
                }
                else{
                    totalprice = Integer.parseInt(txt_q.getText()) * Integer.parseInt(txt_up.getText());
                    m.setValueAt(txt_n.getText(),gsr,0);
                    m.setValueAt(txt_d.getText(),gsr,1);
                    m.setValueAt(txt_pt.getText(),gsr,2);
                    m.setValueAt(txt_q.getText(),gsr,3);
                    m.setValueAt(txt_up.getText(),gsr,4);
                    m.setValueAt(totalprice,gsr,5);
    
                String name = txt_n.getText();
                String due= txt_d.getText();
                String p_m = txt_pt.getText();
                String q = txt_q.getText();
                String up = txt_up.getText();
    
                if(file.exists())
                    {
                        
                    try{
                        if(name.length() > 0 && due.length() > 0 && p_m.length() > 0 && q.length() > 0 && up.length() > 0)
                        {
                        FileWriter fw = new FileWriter(file);
                        BufferedWriter bw = new BufferedWriter(fw);
                
                        for(int i = 0 ; i < Invtable.getRowCount();i++)
                        {
                            for(int j = 0 ; j < Invtable.getColumnCount();j++){
                            bw.write(Invtable.getValueAt(i,j).toString()+",");
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
    
                    txt_n.setText("");
                    txt_d.setText("");
                    txt_pt.setText("");
                    txt_q.setText("");
                    txt_up.setText("");
                }
            }
            else{
                JOptionPane.showMessageDialog(null, " Update Error ");
            }
        
        });

        itp.add(titleword);
        itp.add(title);
        itp.add(searchIcon);
        itp.add(searchbar);
        itp.add(search);

        itp.add(inv_n);
        itp.add(inv_d);
        itp.add(inv_pt);
        itp.add(inv_q);
        itp.add(inv_up);

        itp.add(txt_n);
        itp.add(txt_d);
        itp.add(txt_pt);
        itp.add(txt_q);
        itp.add(txt_up);

        itp.add(add);
        itp.add(del);
        itp.add(upd);

        itp.add(pane);
    }
    public void search(String str){
        m = (DefaultTableModel) Invtable.getModel();
        TableRowSorter<DefaultTableModel> trs = new TableRowSorter<>(m);
        Invtable.setRowSorter(trs);
        trs.setRowFilter(RowFilter.regexFilter(str));

    }

    public boolean isValidDate(String dateStr) {
    try {
        SimpleDateFormat sdf = new SimpleDateFormat("yyyy-MM-dd");

        // Set lenient to false to enforce strict date parsing
        sdf.setLenient(false);

        // Parse the date
        Date date = sdf.parse(dateStr);

        // Check if the parsed date is the same as the original string
        return dateStr.equals(sdf.format(date));
    } catch (ParseException e) {
        // Date parsing failed
        return false;
    }
}
}