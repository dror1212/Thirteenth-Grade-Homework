/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author dror
 */

import javax.swing.*;
import java.awt.*;

public class CubeTower extends JApplet {
    private int x;
    
    @Override
    public void init() {
        setCubeX();
    }
    
    @Override
    public void paint(Graphics g){
        // Clean the board
        g.clearRect(0, 0, getWidth(), getHeight());
        
        // Get the pixels that are going to be empty up and in the sides
        int unusedWidth = getWidth() % x;
        int unusedHeight = getHeight() % x;
        
        int counter = 0;
        int i = getHeight() - x - 1;
        
        // Go from layer to the next by subing the size of the cube
        for(; i > unusedHeight / 2; i -= x){
            // Paint the cubes depends on the layer
            for(int j = (unusedWidth + counter * x) / 2; j < getWidth() - (counter + 1) * x / 2; j += x){
                g.drawRect(j,i,x,x);
            }
            counter++;
        }
    }
        
    public void setCubeX(){
        while (true) {
            try {
                x = Integer.parseInt(JOptionPane.showInputDialog("Give x"));
                if(x>-1)
                {
                    break;
                }                
            } catch (NumberFormatException e) {
            }
        }
    }
    
}
