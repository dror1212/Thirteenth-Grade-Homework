/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package bankaccount;

/**
 *
 * @author student
 */
public class TestBankAccount {
    public static void main(String[] args)
    {
        BankAccount x = new BankAccount("shenhav", "000001",10000,false,1000);
        System.out.println(x.toString());
        System.out.println(x.withdrawal(5000));
        System.out.println(x.toString());
        System.out.println(x.withdrawal(50000));
        System.out.println(x.toString());
        
    }
}
