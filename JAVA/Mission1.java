/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package javaapplication1;

import javax.swing.*;

/**
 *
 * @author student
 */
public class JavaApplication1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        String answer = "0";
        int questions = 0, good = 0;
        while (!answer.equals("quit")) {
            int rnd = (int) (Math.random() * 2);
            int x, y;
            if (rnd == 0) {
                x = (int) (Math.random() * 11);
                y = (int) (Math.random() * 11);
                answer = JOptionPane.showInputDialog(x + " X " + y + " = ?");
                try {
                    if (Integer.parseInt(answer) == x * y) {
                        System.out.println("Correct");
                        good++;
                    } else {
                        System.out.println("Wrong");
                        JOptionPane.showMessageDialog(null,x + " X " + y + " = " + x * y);
                    }
                    questions++;
                } catch (NumberFormatException e) {
                    answer = "quit";
                }
            } else {
                x = (int) (Math.random() * 101);
                y = (int) (Math.random() * 10) + 1;
                x = x - (x % y);
                answer = JOptionPane.showInputDialog(x + " / " + y + " = ?");
                try {
                    if (Integer.parseInt(answer) == x / y) {
                        System.out.println("Correct");
                        good++;
                    } else {
                        System.out.println("Wrong");
                        JOptionPane.showMessageDialog(null,x + " : " + y + " = " + x / y);
                    }
                    questions++;
                } catch (NumberFormatException e) {
                    answer = "quit";
                }
            }
        }
        JOptionPane.showMessageDialog(null, "Your grade is " + (int) ((double) good / questions * 100));
    }

}
