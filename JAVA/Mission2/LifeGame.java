
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;

public class LifeGame extends JApplet implements ActionListener {

    private Container c;
    private JTextArea displayBoard;		// display board
    private JButton nextGeneration;	// button to generate next generation
    private int x;
    private int y;
    private String[][] lifeStatus;

    public void init() {					// Applet init() method
        // set layout manager
        getXY();
        randomLife();
        c = getContentPane();
        c.setLayout(new BorderLayout());

        // setup components
        displayBoard = new JTextArea();
        nextGeneration = new JButton("Next generation");
        nextGeneration.addActionListener(this);

        // add components to applet
        c.add(displayBoard, BorderLayout.CENTER);
        c.add(nextGeneration, BorderLayout.SOUTH);
        displayBoard.setFont(new Font("monospaced", Font.PLAIN, 12));

        displayLife();
    }
    
    public void displayLife() {
        String output = "";
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                output += lifeStatus[i][j] + " ";
            }
            output += "\n";
        }
        displayBoard.setText(output);
    }

    // implementation of ActionListener interface
    public void actionPerformed(ActionEvent e) {
        generateNextGeneration();
        displayLife();
    }

    public void randomLife() {
        int rnd;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                rnd = (int) (Math.random() * 2);
                if (rnd == 0) {
                    lifeStatus[i][j] = "-";
                } else {
                    lifeStatus[i][j] = "+";
                }
            }
        }
    }

    public void generateNextGeneration() {
        boolean stati = true;
        String[][] nextGeneration = new String[y][x];
        int counter;
        for (int i = 0; i < y; i++) {
            for (int j = 0; j < x; j++) {
                counter = countNeighbors(i, j);
                if (lifeStatus[i][j].equals("-")) {
                    if (counter == 3) {
                        nextGeneration[i][j] = "+";
                        stati = false;
                    } else {
                        nextGeneration[i][j] = lifeStatus[i][j];
                    }
                } else {
                    counter--;
                    if (counter < 2 || counter > 3) {
                        nextGeneration[i][j] = "-";
                        stati = false;
                    } else {
                        nextGeneration[i][j] = lifeStatus[i][j];
                    }
                }
            }
        }
        lifeStatus = nextGeneration;
        if (stati) {
            int go;
            go = JOptionPane.showConfirmDialog(null, "Do you want to start again?", "The game is static", JOptionPane.YES_NO_OPTION);
            if (go == JOptionPane.YES_OPTION) {
                getXY();
                randomLife();
            }
        }
    }

    public int countNeighbors(int y2, int x2) {
        int counter = 0;
        for (int i = y2 - 1; i < y2 + 2; i++) {
            for (int j = x2 - 1; j < x2 + 2; j++) {
                try {
                    if (lifeStatus[i][j].equals("+")) {
                        counter++;
                    }
                } catch (IndexOutOfBoundsException e) {
                }
            }
        }
        return counter;
    }
    public void getXY(){
        while (true) {
            try {
                x = Integer.parseInt(JOptionPane.showInputDialog("Give x"));
                y = Integer.parseInt(JOptionPane.showInputDialog("Give y"));
                if(x>-1 && y>-1)
                {
                    break;
                }                
            } catch (NumberFormatException e) {
            }
        }
        lifeStatus = new String[y][x];
    }

}