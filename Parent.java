/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package newpackage;
import java.util.Random;
/**
 *
 * @author student
 */
public class Parent implements Runnable{

    Data x;
    public Parent()
    {
        this.x = Data.getInstance();
    }
    @Override
    public void run() {
        while (true){
            Random rand = new Random();
            int n = rand.nextInt(10);
            x.add(n);
            System.out.println("put " + n);
            try {
                Thread.sleep(1000);
            }
            catch(InterruptedException ex){}

        }
    }  
}
