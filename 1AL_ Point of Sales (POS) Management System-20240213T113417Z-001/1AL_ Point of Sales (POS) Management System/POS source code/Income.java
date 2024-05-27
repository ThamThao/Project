import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import javax.swing.table.JTableHeader;
import javax.swing.table.TableRowSorter;
import java.awt.*;
import java.awt.event.*;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;


public class Income{
    double total_sales;
    DefaultTableModel m, IncomeModel;
    JPanel title;
    JPanel search;
    JPanel TotalSales_display;
    JTextField searchbar;
    JLabel pagetype;
    JLabel TotalSales_title;
    JLabel searchIcon;
    JLabel Show_TotalSales;
    JTable IncomeTable;
    JButton refresh;
    ImageIcon scIcon = new ImageIcon("search.png");
    public void incomepage(JPanel incomepg){
        pagetype = new JLabel();
        pagetype.setForeground(Color.white);
        pagetype.setFont(new Font("Monospaced", Font.BOLD, 30));
        pagetype.setText("POS Income");
        pagetype.setBounds(50,15,300,50);

        title = new JPanel();
        title.setLayout(null);
        title.setBackground(new Color(147, 181, 146));//top panel color
        title.setBounds(3,3,1284,75);

        searchIcon = new JLabel();
        searchIcon.setIcon(scIcon);
        searchIcon.setBounds(550,105,300,40);
        incomepg.add(searchIcon);

        searchbar = new JTextField();
        searchbar.setFocusable(true);
        searchbar.addFocusListener(new FocusListener() {
            @Override
            public void focusGained(FocusEvent event) {
                if(searchbar.getText().equals("Search by Name")) {
                    searchbar.setText("");
                }
                searchbar.setForeground(Color.BLACK);
                searchbar.setFont(new Font("Arial", Font.PLAIN, 23));
            }

            @Override
            public void focusLost(FocusEvent event) {
                if(searchbar.getText().equals("")) {
                    searchbar.setText("Search by Name");
                }
                searchbar.setForeground(Color.LIGHT_GRAY);
                searchbar.setFont(new Font("Arial", Font.PLAIN, 23));
            }
        });
        searchbar.addKeyListener(new KeyListener() {
            @Override
            public void keyTyped(KeyEvent event) {}
            @Override
            public void keyPressed(KeyEvent event) {}
            @Override
            public void keyReleased(KeyEvent event) {
                String searchString = searchbar.getText();
                search(searchString);
            }
        });
        searchbar.setBounds(50, 105, 500, 40);
        incomepg.add(searchbar);

        search = new JPanel();
        search.setLayout(null);
        search.setBackground(new Color(134, 144, 145 ));//search panel color
        search.setBounds(3,78,1284,90);
        incomepg.add(search);

        incomepg.setLayout(null);
        incomepg.setBounds(10,2,1290,1000);
        incomepg.setBorder(BorderFactory.createLineBorder(new Color(203, 195, 227), 3));
        incomepg.setBackground(Color.white);


        Object [] col ={"Product ID","Product Name","Unit Price (RM)","Quantity","Total Price","Date"};
        m = new DefaultTableModel();
        m.setColumnIdentifiers(col);
        IncomeTable = new JTable();
        IncomeTable.setModel(m);
        IncomeTable.setFont(new Font("Verdana", Font.PLAIN, 15));
        IncomeTable.setRowHeight(30);
        IncomeTable.setEnabled(false);
        IncomeTable.setAutoCreateRowSorter(true);
        JTableHeader tableHeader = IncomeTable.getTableHeader();
        tableHeader.setFont(new Font("Verdana", Font.BOLD, 17));

        refresh = new JButton();
        refresh.setBackground(new Color(134, 144, 145));
        refresh.setForeground(Color.white);
        refresh.setFont(new Font("Comic Sans", Font.BOLD,25));
        refresh.setText("Refresh");
        refresh.setFocusable(false);
        refresh.setBorder(BorderFactory.createEtchedBorder());
        refresh.setBounds(800,725, 200, 80);
        refresh.addMouseListener(new MouseAdapter() {//change the color of the button when mouse entered
            public void mouseEntered(MouseEvent evt) {
                refresh.setBackground(new Color(158, 167, 167 ));
            }
        
            public void mouseExited(MouseEvent evt) {
                refresh.setBackground(new Color(134, 144, 145));
            }
        });
        refresh.addActionListener(e -> {
            IncomeModel = (DefaultTableModel) IncomeTable.getModel();
            IncomeModel.setRowCount(0); // Clear the table model
            File file = new File("income.txt");

            try{
                FileReader fr = new FileReader(file);
                BufferedReader reader = new BufferedReader(fr);

                IncomeModel = (DefaultTableModel) IncomeTable.getModel();
                Object[] lines = reader.lines().toArray();

                for (Object line : lines) {
                    String[] tableRow = line.toString().split(",");
                    IncomeModel.addRow(tableRow);
                }
            }
            catch(FileNotFoundException ex)
            {
                System.out.println("FILE NO FOUND");
            }
            total_sales = 0;//to reset the total sales
            for(int i = 0; i < IncomeTable.getRowCount() ; i++)
            {
                total_sales += Double.parseDouble(IncomeTable.getValueAt(i, 4).toString());
            }
            Show_TotalSales.setText(String.format("%.2f", total_sales));//round up to 2 decimal place
        });
        incomepg.add(refresh);

        TotalSales_display = new JPanel();
        TotalSales_display.setBounds(1075,725, 200, 80);
        TotalSales_display.setBackground(new Color(190, 208, 219));

        TotalSales_title = new JLabel();
        TotalSales_title.setBounds(1090,725,300,40);
        TotalSales_title.setFont(new Font("Arial", Font.PLAIN, 23));
        TotalSales_title.setText("Total Sales (RM)");


        Show_TotalSales = new JLabel();
        Show_TotalSales.setFont(new Font("Arial", Font.BOLD, 23));
        Show_TotalSales.setForeground(Color.BLACK);
        Show_TotalSales.setText("0");
        Show_TotalSales.setBounds(1120, 750, 200, 50);
        
        total_sales = 0; //to reset the total sales
        for(int i = 0; i < IncomeTable.getRowCount() ; i++)
        {
            total_sales += Double.parseDouble(IncomeTable.getValueAt(i, 4).toString());
        }

        Show_TotalSales.setText(String.format("%.2f", total_sales));//round up to 2 decimal place

        JScrollPane pane = new JScrollPane(IncomeTable);
        pane.setBounds(3,170,1285,520);

        incomepg.add(pagetype);
        incomepg.add(title);
        incomepg.add(TotalSales_title);
        incomepg.add(Show_TotalSales);
        incomepg.add(TotalSales_display);
        incomepg.add(pane);
    }

    public void search(String str){
        m = (DefaultTableModel) IncomeTable.getModel();
        TableRowSorter<DefaultTableModel> trs = new TableRowSorter<>(m);
        IncomeTable.setRowSorter(trs);
        trs.setRowFilter(RowFilter.regexFilter("(?i)" + str));
    }
}