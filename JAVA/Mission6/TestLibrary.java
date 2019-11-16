/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package myLibrary;

/**
 *
 * @author dror
 */
public class TestLibrary {
    public static void main(String[] args)
    {
        Library x = new Library("Dror");
        x.print(true);
        x.addBook(new Book("dani","dani",200,2000));
        x.addBook(new Book("ddddd","daaa",800,2009));
        x.addBook(new Book("ddddd","daaa",3000,2009));
        x.addBook(new Book("ddddd","daaa",3,2009));
        x.addBook(new Book("ddddd","daaa",3,2009));
        x.addBook(new Book("ddddd","daaa",3,2009));
        x.addBook(new Book("ddd5","daaa",3,2009));
        x.removeBook(1,1);
        x.addBook(new Book("dd2","daaa",3,2009));
        x.addBook(new Book("ddddd","daaa",3,2009));
        x.addBook(new Book("ddddd","daaa",3,2009),8);
        x.print(true);
        System.out.println(x.removeBook(8,0));
        System.out.println(x.removeBook(7,2));
        x.print(true);
    }
}
