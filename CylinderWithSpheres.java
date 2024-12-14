import java.awt.*;
import javax.swing.*;

public class CylinderWithSpheres extends JPanel {
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        Graphics2D g2d = (Graphics2D) g;

        int width = getWidth();
        int height = getHeight();

        int cylinderHeight = height / 10;
        int cylinderRadius = width / 4;

        int sphereRadius = cylinderRadius / 2;

        int cylinderX = width / 2 - cylinderRadius;
        int cylinderY = height / 2 - cylinderHeight / 2;

        int sphere1X = cylinderX - 10;
        int sphere1Y = cylinderY - sphereRadius;

        int sphere2X = cylinderX - 10;
        int sphere2Y = cylinderY + cylinderHeight - sphereRadius;

        g2d.setColor(Color.BLACK);
        g2d.fillOval(sphere1X, sphere1Y, sphereRadius * 2, sphereRadius * 2);

        g2d.setColor(Color.BLACK);
        g2d.fillOval(sphere2X, sphere2Y, sphereRadius * 2, sphereRadius * 2);

        g2d.setColor(Color.BLACK);
        g2d.fillRect(cylinderX, cylinderY, cylinderRadius * 2, cylinderHeight);
    }

    public static void main(String[] args) {
        JFrame frame = new JFrame("Cylinder with Spheres");
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(400, 400);
        frame.add(new CylinderWithSpheres());
        frame.setVisible(true);
    }
}