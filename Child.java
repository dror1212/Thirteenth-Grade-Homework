/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package newpackage;

import java.util.Random;
import java.util.concurrent.TimeUnit;

/**
 *
 * @author student
 */
public class Child implements Runnable{

    Data x;
    public Child()
    {
        this.x = Data.getInstance();
    }
    @Override
    public void run() {
        while(true){
            Random rand = new Random();
            int n = rand.nextInt(10);
            x.sub(n);
            System.out.println("took " + n);
            try {
                Thread.sleep(1000);
            }
            catch(InterruptedException ex){}
        }
    }
}
