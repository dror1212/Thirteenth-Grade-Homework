/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package newpackage;

/**
 *
 * @author student
 */
public class main {
    public static void main(String[] args) {
        Parent x = new Parent();
        Parent x2 = new Parent();
        Child x3 = new Child();
        Child x4 = new Child();
        Thread t1 = new Thread(x);
        Thread t2 = new Thread(x2);
        Thread t3 = new Thread(x3);
        Thread t4 = new Thread(x4);
        t1.start();
        t2.start();
        t3.start();
        t4.start();
        while(true) {
            System.out.println("\n"+Data.getInstance().getSum()+"\n");
            try {
                Thread.sleep(300);
            }
            catch(InterruptedException ex){}
        }
    }
}
