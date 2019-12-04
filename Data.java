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
public class Data {
    public static Data x = null;
    int sum;
    private Data()
    {
        sum = 0;
    }
    public static Data getInstance()
    {
        if(x==null)
            x = new Data();
        return x;
    }
    void add(int a)
    {
        this.sum += a;
    }
    void sub(int a)
    {
        this.sum -= a;
    }
    int getSum()
    {
        return sum;
    }
}
