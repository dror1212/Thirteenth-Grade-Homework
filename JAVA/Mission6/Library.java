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
public class Library {
    private Shelf[] shelves;
    private String libraryName;
    
    public Library(String name)
    {
        this.libraryName = name;
        init();
    }
    
    private void init()
    {
        shelves = new Shelf[10];
        for(int i = 0; i < 10; i++)
        {
            shelves[i] = new Shelf(i);
        }
    }
    
    public int getNumberOfPages()
    {
        int counter = 0;
        for(int i =0; i < 10; i++)
            counter+= shelves[i].getNumberOfPages();
        return counter;
    }
    
    public int getNumberOfBooks()
    {
        int counter = 0;
        for(int i =0; i < 10; i++)
            counter+= shelves[i].getNumberOfBooks();
        return counter;
    }
    
    public boolean addBook(Book book)
    {
        boolean check = false;
        for(int i = 0;(!check) &&(i < 10); i++)
        {
            check = addBook(book,i);
        }
        
        return check;
    }
    
    public boolean addBook(Book book, int shelf)
    {          
        return shelves[shelf].addBook(book.getAuthor(),book.getName(),book.getPages(),book.getYear());
    }
    
    public boolean removeBook(int shelf, int book)
    {
        return shelves[shelf].removeBook(book);             
    }
    
    public boolean isEmpty()
    {
        boolean check = true;
        for(int i = 0; (check)&&(i < 10); i++)
        {
            check = shelves[i].isEmpty();
        }
        
        return check;
    }
    
    @Override
    public String toString()
    {
        if(isEmpty())
            return "";
        String ret = libraryName + " library contains 10 books summing " + getNumberOfPages() +" pages. \n  The books on the " + libraryName + " library are:\n";
        for(int i = 0; i < 10; i++)
        {
            ret += shelves[i].toString();
        }
        
        return ret;
    }
    
    public String extendedToString()
    {
        String ret = toString();
        if(ret.isEmpty())
            ret = libraryName + " library is empty";
        return ret;
    }
    
    public void print(boolean extended)
    {
        String ret;
        if(extended)
        {
            ret = extendedToString();
        }
        else
        {
            ret = toString();
        }
        
        System.out.println(ret);
    }
}
