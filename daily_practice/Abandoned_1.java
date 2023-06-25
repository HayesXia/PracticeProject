package demo_01;

// 导入java.awt和javax.swing包
import java.awt.*;
import javax.swing.*;

// 创建一个继承JFrame类的窗口类
public class SmileWindow extends JFrame {
    // 设置窗口的大小、位置、标题和关闭方式
    public SmileWindow() {
        super("Smile Window");
        setSize(300, 300);
        setLocation(100, 100);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        // 创建一个画板对象，并将其添加到窗口的内容面板中
        SmilePanel panel = new SmilePanel();
        add(panel);
    }

    // 主方法，创建一个窗口对象，并使其可见
    public static void main(String[] args) {
        SmileWindow window = new SmileWindow();
        window.setVisible(true);
    }
}

// 创建一个继承JPanel类的画板类
class SmilePanel extends JPanel {
    // 重写paintComponent方法，在其中使用Graphics对象绘制笑脸
    public void paintComponent(Graphics g) {
        super.paintComponent(g);

        // 设置颜色和线型
        g.setColor(Color.YELLOW);
        g.fillOval(50, 50, 200, 200); // 绘制笑脸的轮廓
        g.setColor(Color.BLACK);
        g.drawOval(50, 50, 200, 200); // 绘制笑脸的边框

        // 绘制笑脸的眼睛
        g.fillOval(100, 100, 20, 20); // 左眼
        g.fillOval(180, 100, 20, 20); // 右眼

        // 绘制笑脸的嘴巴
        g.drawArc(100, 150, 100, 50, 180, 180); // 弧形
    }
}
