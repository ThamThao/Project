import javax.swing.*;
import java.awt.*;

public class HOME extends Component {
    JButton pos,cus,pro,inc,inv,logout;
    ImageIcon posimg,cusimg,proimg,incimg,invimg,logoutimg;
    public void hometabpage(JPanel htp, JTabbedPane tabs){
        pos = new JButton();
        cus = new JButton();
        pro = new JButton();
        inc = new JButton();
        inv = new JButton();
        logout = new JButton();

        htp.setLayout(null);
        htp.setBounds(10,200,1290,600);
        htp.setBorder(BorderFactory.createLineBorder(new Color(203, 195, 227), 3));
        htp.setBackground(new Color(230, 230, 250));
        posimg = new ImageIcon("cart1.png");
        pos.setIcon(posimg);
        pos.setFocusable(false);
        pos.setBackground(Color.lightGray);
        pos.setBorder(BorderFactory.createBevelBorder(0));
        pos.setBounds(200,100,200,200);
        pos.addActionListener(e -> HOME.this.POSactionPerformed(tabs));
        pos.setBackground(new Color(204, 204, 255));
        htp.add(pos);

        cusimg = new ImageIcon("cust1.png");
        cus.setIcon(cusimg);
        cus.setFocusable(false);
        cus.setBackground(Color.lightGray);
        cus.setBorder(BorderFactory.createBevelBorder(0));
        cus.setBounds(550,100,200,200);
        cus.addActionListener(e -> CUSactionPerformed(tabs));
        cus.setBackground(new Color(204, 204, 255));
        htp.add(cus);

        proimg = new ImageIcon("product.png");
        pro.setIcon(proimg);
        pro.setFocusable(false);
        pro.setBackground(Color.lightGray);
        pro.setBorder(BorderFactory.createBevelBorder(0));
        pro.setBounds(900,100,200,200);
        pro.addActionListener(e -> PROactionPerformed(tabs));
        pro.setBackground(new Color(204, 204, 255));
        htp.add(pro);

        incimg = new ImageIcon("profit.png");
        inc.setIcon(incimg);
        inc.setFocusable(false);
        inc.setBackground(Color.lightGray);
        inc.setBorder(BorderFactory.createBevelBorder(0));
        inc.setBounds(380,370,200,200);
        inc.addActionListener(e -> INCactionPerformed(tabs));
        inc.setBackground(new Color(204, 204, 255));
        htp.add(inc);

        invimg = new ImageIcon("invoice.png");
        inv.setIcon(invimg);
        inv.setFocusable(false);
        inv.setBackground(Color.lightGray);
        inv.setBorder(BorderFactory.createBevelBorder(0));
        inv.setBounds(720,370,200,200);
        inv.addActionListener(e -> INVactionPerformed(tabs));
        inv.setBackground(new Color(204, 204, 255));
        htp.add(inv);
    }

    public void POSactionPerformed(JTabbedPane tabs) {
        tabs.setSelectedIndex(1);
    }
    public void CUSactionPerformed(JTabbedPane tabs) {
        tabs.setSelectedIndex(2);
    }
    public void PROactionPerformed(JTabbedPane tabs) {
        tabs.setSelectedIndex(3);
    }
    public void INCactionPerformed(JTabbedPane tabs) {
        tabs.setSelectedIndex(4);
    }
    public void INVactionPerformed(JTabbedPane tabs) {
        tabs.setSelectedIndex(5);
    }
}