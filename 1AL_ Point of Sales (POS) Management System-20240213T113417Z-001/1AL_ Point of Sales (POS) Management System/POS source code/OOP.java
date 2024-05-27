import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class OOP extends Component implements ActionListener{
    JButton Home,POSb,Customers,Products,Income,Invoice,Logout;
    JPanel temp, hometab, htp, postab, Pospg, custab, ctp, protab, ptp, IncomeTab,incomepg, invtab, itp, settab;
    JLabel Logo;
    JTabbedPane Tabs;
    JLabel tab0;
    ImageIcon i1 = new ImageIcon("logo1.png");
    JFrame f;
    OOP(){
        HOME fun = new HOME();
        POS pos = new POS();
        Customer customer = new Customer();
        Product product = new Product();
        Income income = new Income();
        Invoice invoice = new Invoice();
        f = new JFrame();
        f.setTitle("POS System");
        f.setSize(1580,1030);
        f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        f.getContentPane().setBackground(new Color(109, 174, 129));
        f.setLayout(null);
        f.setResizable(false);

        Logo = new JLabel();
        Logo.setIcon(i1);
        Logo.setBounds(0,0,250,250);
        Logo.setBorder(BorderFactory.createLineBorder(Color.black, 1));
        f.add(Logo);

        temp = new JPanel();
        temp.setBorder(BorderFactory.createEmptyBorder());
        temp.setBounds(250,-20,1320,40);
        temp.setBackground(new Color(109, 174, 129));
        f.add(temp);

        Home = new JButton();
        POSb = new JButton();
        Customers = new JButton();
        Products = new JButton();
        Income = new JButton();
        Invoice = new JButton();
        Logout = new JButton();

        Home.setBounds(0,250,250,100);
        Home.setBackground(Color.white);
        Home.setForeground(Color.black);
        Home.setFont(new Font("Congenial", Font.BOLD,25));
        Home.setText("HOME");
        Home.setFocusable(false);
        Home.setBorder(BorderFactory.createEmptyBorder());
        Home.addActionListener(this);
        f.add(Home);

        POSb.setBounds(0,360,250,100);
        POSb.setBackground(Color.white);
        POSb.setForeground(Color.black);
        POSb.setFont(new Font("Congenial", Font.BOLD,25));
        POSb.setText("Point of Sales");
        POSb.setFocusable(false);
        POSb.setBorder(BorderFactory.createEmptyBorder());
        POSb.addActionListener(this);
        f.add(POSb);

        Customers.setBounds(0,470,250,100);
        Customers.setBackground(Color.white);
        Customers.setForeground(Color.black);
        Customers.setFont(new Font("Congenial", Font.BOLD,25));
        Customers.setText("Customer");
        Customers.setFocusable(false);
        Customers.setBorder(BorderFactory.createEmptyBorder());
        Customers.addActionListener(this);
        f.add(Customers);

        Products.setBounds(0,580,250,100);
        Products.setBackground(Color.white);
        Products.setForeground(Color.black);
        Products.setFont(new Font("Congenial", Font.BOLD,25));
        Products.setText("Products");
        Products.setFocusable(false);
        Products.setBorder(BorderFactory.createEmptyBorder());
        Products.addActionListener(this);
        f.add(Products);

        Income.setBounds(0,690,250,100);
        Income.setBackground(Color.white);
        Income.setForeground(Color.black);
        Income.setFont(new Font("Congenial", Font.BOLD,25));
        Income.setText("Income");
        Income.setFocusable(false);
        Income.setBorder(BorderFactory.createEmptyBorder());
        Income.addActionListener(this);
        f.add(Income);

        Invoice.setBounds(0,800,250,100);
        Invoice.setBackground(Color.white);
        Invoice.setForeground(Color.black);
        Invoice.setFont(new Font("Congenial", Font.BOLD,25));
        Invoice.setText("Invoice");
        Invoice.setFocusable(false);
        Invoice.setBorder(BorderFactory.createEmptyBorder());
        Invoice.addActionListener(this);
        f.add(Invoice);

        Logout.setBounds(0,910,250,100);
        Logout.setBackground(Color.white);
        Logout.setForeground(Color.black);
        Logout.setFont(new Font("Congenial", Font.BOLD,25));
        Logout.setText("Logout");
        Logout.setFocusable(false);
        Logout.setBorder(BorderFactory.createEmptyBorder());
        Logout.addActionListener(this);
        f.add(Logout);

        Tabs = new JTabbedPane();
        hometab = new JPanel();
        postab = new JPanel();
        custab = new JPanel();
        protab = new JPanel();
        IncomeTab = new JPanel();
        invtab = new JPanel();
        settab = new JPanel();

        hometab.setLayout(null);
        htp = new JPanel();
        tab0 = new JLabel();
        tab0.setFont(new Font("Forte",Font.BOLD,25));
        tab0.setBounds(460,200,500,100);
        tab0.setText("WELCOME TO LOS SANTOS POS SYSTEM");
        fun.hometabpage(htp, Tabs);
        hometab.add(tab0);
        hometab.add(htp);
        Tabs.addTab("tab0", hometab);

        postab.setLayout(null);
        Pospg = new JPanel();
        pos.Pospage(Pospg);
        postab.add(Pospg);
        Tabs.addTab("tab1", postab);

        custab.setLayout(null);
        ctp = new JPanel();
        customer.customertabpage(ctp);
        custab.add(ctp);
        Tabs.addTab("tab2", custab);

        protab.setLayout(null);
        ptp = new JPanel();
        product.producttabpage(ptp);
        protab.add(ptp);
        Tabs.addTab("tab3", protab);

        IncomeTab.setLayout(null);
        incomepg = new JPanel();
        income.incomepage(incomepg);
        IncomeTab.add(incomepg);
        Tabs.addTab("tab4", IncomeTab);

        invtab.setLayout(null);
        invtab.setLayout(null);
        itp = new JPanel();
        invoice.invoicetabpage(itp);
        invtab.add(itp);
        Tabs.addTab("tab5", invtab);

        Tabs.setBounds(250,-10,1320,1115);
        Tabs.setBorder(BorderFactory.createLineBorder(Color.black,2));
        Tabs.setTabLayoutPolicy(JTabbedPane.SCROLL_TAB_LAYOUT);
        f.add(Tabs);

        f.setVisible(true);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if(e.getSource()==Home)
            Tabs.setSelectedIndex(0);
        else if(e.getSource()==POSb)
            Tabs.setSelectedIndex(1);
        else if(e.getSource()==Customers)
            Tabs.setSelectedIndex(2);
        else if(e.getSource()==Products)
            Tabs.setSelectedIndex(3);
        else if(e.getSource()==Income)
            Tabs.setSelectedIndex(4);
        else if(e.getSource()==Invoice)
            Tabs.setSelectedIndex(5);
        else if(e.getSource()==Logout) {
            int response = JOptionPane.showConfirmDialog(null,"Do you wish to LOG OUT ?", "LOGOUT Confirm", JOptionPane.YES_NO_OPTION, JOptionPane.QUESTION_MESSAGE);
            if(response == JOptionPane.YES_OPTION){
                JOptionPane.showMessageDialog(null, "Logout Successfully");
                f.dispose();
                new Login();
            }
        }
    }
}