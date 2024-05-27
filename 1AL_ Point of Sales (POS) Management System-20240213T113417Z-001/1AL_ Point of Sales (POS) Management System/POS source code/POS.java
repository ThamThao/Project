import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.JTableHeader;
import java.awt.*;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.text.DecimalFormat;
import java.time.LocalDate;
import java.util.Scanner;
import java.util.concurrent.atomic.AtomicReference;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

public class POS extends Income{ //POS is a class that is publicly accessible and inherits from the Income class.

    String inputProd_ID="", Prod_name="", Prod_price="";
    DecimalFormat df = new DecimalFormat("#.00");
    int atc = 0;
    double shtotalq = 0, totalprice = 0, total_price = 0, discountrate = 0.93;
    JScrollPane scroll;
    LocalDate myObj = LocalDate.now(); 
    String[] custype = {"Normal Customer", "Member"};
    JComboBox<String> cusbox;
    JTextField inputID,paid_entered,q_entered;
    JButton done, remove, addtocart;
    JTable POStable;
    JLabel postitle;
    JLabel displaydate;
    JLabel line;
    JLabel R_totalq;
    JLabel R_totalp;
    JLabel ShowTotalQuantity;
    JLabel ShowTotalPrice;
    JLabel discount;
    JLabel cus;
    JLabel Quantity;
    JLabel Prod_label;
    JLabel shtotal;
    JLabel change_money;
    JLabel totallabel,paidlabel,change;
    JLabel exc;
    JPanel receipt, side_dsg, show, total, paid;
    public void Pospage(JPanel Pospg){
        postitle = new JLabel();
        postitle.setFont(new Font("Monospaced", Font.BOLD, 30));
        postitle.setText("Welcome to LOS SANTOS ");
        postitle.setBounds(900,0,400,50);
        Pospg.add(postitle);

        displaydate = new JLabel();
        displaydate.setFont(new Font("Arial",Font.BOLD,30));
        displaydate.setText(String.valueOf(myObj));
        displaydate.setBounds(1020,70,200,50);
        Pospg.add(displaydate);

        line = new JLabel();
        line.setText("*******************************");
        line.setBounds(900,40,400,50);
        line.setFont(new Font("Serif", Font.PLAIN, 24));
        Pospg.add(line);

        R_totalq = new JLabel();
        R_totalp = new JLabel();
        ShowTotalQuantity = new JLabel();
        ShowTotalPrice = new JLabel();

        R_totalq.setFont(new Font("Arial", Font.BOLD, 23));
        R_totalq.setText("Total Quantity:");
        R_totalq.setBounds(920, 360, 200, 50);
        Pospg.add(R_totalq);

        R_totalp.setFont(new Font("Arial", Font.BOLD, 23));
        R_totalp.setText("Total Price (RM):");
        R_totalp.setBounds(920, 440, 200, 50);
        Pospg.add(R_totalp);

        ShowTotalQuantity.setFont(new Font("Arial", Font.BOLD, 23));
        ShowTotalQuantity.setForeground(Color.BLUE);
        ShowTotalQuantity.setText(Double.toString(shtotalq));
        ShowTotalQuantity.setBounds(1180, 360, 200, 50);
        Pospg.add(ShowTotalQuantity);

        ShowTotalPrice.setFont(new Font("Arial", Font.BOLD, 23));
        ShowTotalPrice.setForeground(Color.BLUE);
        ShowTotalPrice.setText(Double.toString(total_price));
        ShowTotalPrice.setBounds(1180, 440, 150, 50);
        Pospg.add(ShowTotalPrice);


        side_dsg = new JPanel();
        side_dsg.setLayout(null);
        side_dsg.setBorder(BorderFactory.createEmptyBorder());
        side_dsg.setBounds(900,320,375,200);
        side_dsg.setBackground(new Color(190, 208, 219));
        Pospg.add(side_dsg);

        cus = new JLabel();
        cus.setForeground(Color.lightGray);
        cus.setFont(new Font("Arial", Font.ITALIC, 23));
        cus.setText("Customer:");
        cus.setBounds(910, 560, 200, 50);
        Pospg.add(cus);

        cusbox = new JComboBox<>(custype);
        cusbox.setBounds(1050, 570, 150, 30);
        Pospg.add(cusbox);

        discount = new JLabel();
        discount.setForeground(Color.red);
        discount.setFont(new Font("Arial", Font.ITALIC, 23));
        discount.setText("");
        discount.setBounds(1010, 610, 200, 50);
        Pospg.add(discount);

        receipt = new JPanel();
        receipt.setLayout(null);
        receipt.setBorder(BorderFactory.createLineBorder(Color.black,1));
        receipt.setBounds(888,2,400,700);
        receipt.setBackground(Color.white);
        Pospg.add(receipt);

        Quantity = new JLabel();
        Prod_label = new JLabel();

        Quantity.setFont(new Font("Arial", Font.BOLD, 23));
        Quantity.setForeground(Color.white);
        Quantity.setText("Quantity:");
        Quantity.setBounds(550, 30, 200, 50);
        Pospg.add(Quantity);

        q_entered = new JTextField();
        q_entered.setFont(new Font("Arial", Font.BOLD, 23));
        q_entered.setBounds(680, 40, 150, 30);
        q_entered.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                if ((e.getKeyChar() < '0' || e.getKeyChar() > '9') && e.getKeyChar() != '\b' && e.getKeyChar() != '\n') {
                    q_entered.setText("");
                    JOptionPane.showMessageDialog(null, "Invalid Input");
                }
            }
        });
        Pospg.add(q_entered);

        Prod_label.setFont(new Font("Arial", Font.BOLD, 23));
        Prod_label.setForeground(Color.white);
        Prod_label.setText("Product ID:");
        Prod_label.setBounds(30, 30, 200, 50);
        Pospg.add(Prod_label);

        inputID = new JTextField();
        inputID.setFont(new Font("Arial", Font.BOLD, 23));
        inputID.setBounds(180,35,150,35);
        inputID.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                if ((e.getKeyChar() < '0' || e.getKeyChar() > '9') && e.getKeyChar() != '\b' && e.getKeyChar() != '\n') {
                    inputID.setText("");
                    JOptionPane.showMessageDialog(null, "Invalid Input");
                }
            }
        });
        Pospg.add(inputID);

        addtocart = new JButton();
        addtocart.setFont(new Font("Arial", Font.BOLD, 25));
        addtocart.setText("Add To Cart");
        addtocart.setBackground(new Color(134, 144, 145));
        addtocart.setForeground(Color.white);
        addtocart.setBorder(BorderFactory.createEtchedBorder());
        addtocart.setFocusable(false);
        addtocart.setBounds(330,95,250,80);
        addtocart.addMouseListener(new MouseAdapter() {
            public void mouseEntered(MouseEvent evt) {
                addtocart.setBackground(new Color(158, 167, 167));
            }
        
            public void mouseExited(MouseEvent evt) {
                addtocart.setBackground(new Color(134, 144, 145));
            }
        });
        Pospg.add(addtocart);

        show = new JPanel();
        show.setLayout(null);
        show.setBackground(new Color(147, 181, 146));
        show.setBounds(3,3,885,200);
        Pospg.add(show);

        POStable = new JTable();
        String[] columns = {"Product ID", "Product Name","Unit Price (RM)", "Quantity", "Total Price (RM)"};
        AtomicReference<DefaultTableModel> model = new AtomicReference<>(new DefaultTableModel());

        model.get().setColumnIdentifiers(columns);
        POStable.setModel(model.get());
        POStable.setBackground(Color.white);
        POStable.setForeground(Color.black);
        POStable.setFont(new Font("Verdana", Font.PLAIN, 15));
        POStable.setRowHeight(30);
        POStable.setAutoCreateRowSorter(true);
        JTableHeader tableHeader = POStable.getTableHeader();
        tableHeader.setFont(new Font("Verdana", Font.BOLD, 17));

        scroll = new JScrollPane(POStable);
        scroll.setBackground(Color.white);
        scroll.setBounds(3,203,887,500);
        Pospg.add(scroll);

        shtotal = new JLabel();
        shtotal.setFont(new Font("Verdana", Font.PLAIN, 20));
        shtotal.setForeground(Color.white);
        shtotal.setText(df.format(total_price*discountrate));
        shtotal.setBounds(150, 715, 200, 60);
        Pospg.add(shtotal);

        totallabel = new JLabel();
        totallabel.setFont(new Font("Arial", Font.BOLD, 21));
        totallabel.setForeground(Color.white);
        totallabel.setText("Final Price:");
        totallabel.setBounds(10, 720, 200, 50);
        Pospg.add(totallabel);

        total = new JPanel();
        total.setLayout(null);
        total.setBorder(BorderFactory.createLineBorder(new Color(147, 181, 146),1));
        total.setBackground(new Color(147, 181, 146));
        total.setBounds(3,700,300,100);
        Pospg.add(total);

        exc = new JLabel();
        exc.setBackground(Color.lightGray);
        exc.setForeground(new Color(147, 181, 146));
        exc.setFont(new Font("Arial", Font.ITALIC, 21));
        exc.setText("");
        exc.setBounds(620,720,200,50);
        Pospg.add(exc);

        paid_entered = new JTextField();
        paid_entered.setFont(new Font("Verdana", Font.PLAIN, 20));
        paid_entered.setText("0");
        paid_entered.setBounds(400, 720, 200, 60);
        paid_entered.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent e) {}
            @Override
            public void keyPressed(KeyEvent e) {}
            @Override
            public void keyReleased(KeyEvent e) {
                try{
                    if(paid_entered.getText().length() > 0)
                        exc.setText("");
                    if ((e.getKeyChar() < '0' || e.getKeyChar() > '9') && e.getKeyChar() != '\b' && e.getKeyChar() != '\n' && e.getKeyChar() != '.') {
                        paid_entered.setText("0");
                        JOptionPane.showMessageDialog(null, "Invalid Input");
                    }
                    else {
                        change_money.setText(String.valueOf(Double.parseDouble(paid_entered.getText()) - Double.parseDouble(shtotal.getText()) ));
                    }
                }
                catch(NumberFormatException nfe){
                    exc.setText("Input is Required");
                }

            }
        });
        Pospg.add(paid_entered);

        change_money = new JLabel();
        change_money.setFont(new Font("Verdana", Font.PLAIN, 20));
        change_money.setForeground(Color.white);
        change_money.setText("0");
        change_money.setBounds(930, 715, 200, 60);
        Pospg.add(change_money);

        paidlabel = new JLabel();
        paidlabel.setFont(new Font("Arial", Font.BOLD, 21));
        paidlabel.setForeground(Color.white);
        paidlabel.setText("Paid:");
        paidlabel.setBounds(313, 720, 200, 50);
        Pospg.add(paidlabel);

        change = new JLabel();
        change.setFont(new Font("Arial", Font.BOLD, 21));
        change.setForeground(Color.white);
        change.setText("Change:");
        change.setBounds(813, 720, 200, 50);
        Pospg.add(change);

        paid = new JPanel();
        paid.setLayout(null);
        paid.setBorder(BorderFactory.createLineBorder(new Color (147, 181, 146),1));
        paid.setBackground(new Color(147, 181, 146));
        paid.setBounds(303,700,985,100);
        Pospg.add(paid);

        
        done = new JButton();
        done.setBounds(250,850,250,100);
        done.setBackground(new Color(134, 144, 145));
        done.setForeground(Color.white);
        done.setFont(new Font("Comic Sans", Font.BOLD,25));
        done.setText("Done");
        done.setFocusable(false);
        done.setBorder(BorderFactory.createEmptyBorder());
        done.addMouseListener(new MouseAdapter() {
            public void mouseEntered(MouseEvent evt) {
                done.setBackground(new Color(158, 167, 167));
            }
        
            public void mouseExited(MouseEvent evt) {
                done.setBackground(new Color(134, 144, 145));
            }
        });

        File file2 = new File("Income.txt");
        done.addActionListener(e ->{
            if(Double.parseDouble(paid_entered.getText()) < Double.parseDouble(shtotal.getText()))
                JOptionPane.showMessageDialog(null, "Not Enough Amount");
            else{
                try{
                    FileOutputStream w1 = new FileOutputStream(file2,true);
                    for(int i = 0 ; i < POStable.getRowCount();i++)
                    {
                        for(int j = 0 ; j < POStable.getColumnCount();j++){
                            String scan = POStable.getValueAt(i,j).toString()+",";
                            byte[] a = scan.getBytes();
                            w1.write(a);
                        }
                        byte[] b = String.valueOf(myObj).getBytes();
                        w1.write(b);
                        w1.write('\n');
                    }
                    w1.close();
                }
                catch(Exception ex)
                {
                    System.out.println("error");
                }
                atc = 0;
                inputID.setText("0");
                q_entered.setText("0");
                paid_entered.setText("0");
                total_price = 0;
                shtotalq = 0;
                shtotal.setText(Double.toString(total_price));
                ShowTotalQuantity.setText(Double.toString(shtotalq));
                ShowTotalPrice.setText(Double.toString(total_price));
                int count = POStable.getRowCount();
                while(count > 0){
                    model.get().removeRow(count-1);
                    count--;
                }
            }

        });
        Pospg.add(done);

        remove = new JButton();
        remove.setBounds(750,850,250,100);
        remove.setBackground(new Color(134, 144, 145));
        remove.setForeground(Color.white);
        remove.setFont(new Font("Comic Sans", Font.BOLD,25));
        remove.setText("Remove");
        remove.setFocusable(false);
        remove.setBorder(BorderFactory.createEmptyBorder());
        remove.addMouseListener(new MouseAdapter() {
            public void mouseEntered(MouseEvent evt) {
                remove.setBackground(new Color(158, 167, 167));
            }
        
            public void mouseExited(MouseEvent evt) {
                remove.setBackground(new Color(134, 144, 145));
            }
        });
        remove.addActionListener(e ->{
            int gsr = POStable.getSelectedRow();
            if(gsr >= 0){
                shtotalq -= Double.parseDouble(POStable.getValueAt(gsr, 3).toString());
                total_price -= Double.parseDouble(POStable.getValueAt(gsr, 4).toString());
                shtotal.setText(Double.toString(total_price));
                ShowTotalQuantity.setText(Double.toString(shtotalq));
                ShowTotalPrice.setText(Double.toString(total_price));
                model.get().removeRow(gsr);
                atc--;
            }
            else{
                JOptionPane.showMessageDialog(null, " Delete Error ");
            }


        });
        Pospg.add(remove);

        Pospg.setLayout(null);
        Pospg.setBounds(10,2,1290,1000);
        Pospg.setBorder(BorderFactory.createLineBorder(Color.black, 3));
        Pospg.setBackground(Color.white);

        addtocart.addActionListener(e -> {
            if(inputID.getText().equals("") || q_entered.getText().equals("")){
                JOptionPane.showMessageDialog(null, " Invalid Input ");
            }
            else{
                File file = new File("Product.txt");

                try{
                    Scanner scan = new Scanner(file).useDelimiter(",");
                    inputProd_ID = inputID.getText();

                    while(scan.hasNextLine())
                    {
                        if(scan.next().equals(inputProd_ID))
                        {
                            Prod_name = scan.next();
                            Prod_price = scan.next();
                            break;
                        }
                        scan.nextLine();
                    }
                    if(!scan.hasNextLine()){
                        inputID.setText("");
                        JOptionPane.showMessageDialog(null, "This Product is not Added");
                    }
                    else{
                        totalprice = Double.parseDouble(Prod_price) * Double.parseDouble(q_entered.getText());
                        model.get().addRow(new Object[]{inputID.getText(),Prod_name,Prod_price,
                                q_entered.getText(),totalprice
                        });
                        shtotalq += Double.parseDouble(POStable.getValueAt(atc, 3).toString());
                        total_price += Double.parseDouble(POStable.getValueAt(atc, 4).toString());
                        shtotal.setText(Double.toString(total_price));
                        ShowTotalQuantity.setText(Double.toString(shtotalq));
                        ShowTotalPrice.setText(Double.toString(total_price));
                        atc++;
                    }
                }
                catch(FileNotFoundException ex)
                {
                    System.out.println("no file");
                }
            }
        });

        cusbox.addItemListener(e -> {
            if(e.getItem() == "Normal Customer"){
                shtotal.setText(df.format(total_price*discountrate));
                discount.setText("");
            }
            else{
                shtotal.setText(df.format(total_price*discountrate));
                discount.setText("Discount Rate: 7%");
            }

        });

    }
}