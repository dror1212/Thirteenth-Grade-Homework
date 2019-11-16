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
public class Shelf {
    private int shelfNumber;
    private Book[] books;
    public Shelf(int shelfNumber)
    {
        this.shelfNumber = shelfNumber;
        init();
    }
    
    public Shelf()
    {
        this(0);
    }
    
    private void init()
    {
        books = new Book[5];
        for(int i = 0; i < 5; i++)
        {
            books[i] = new Book();
        }
    }
    
    public int getNumberOfBooks()
    {
        int counter = 0;
        for(int i = 0; i < 5;i++)
        {
            if(!books[i].isEmpty()){
                counter++;
            }
            else
                break;
        }
        
        return counter;
    }
    
    public int getNumberOfPages()
    {
        int counter = 0;
        for(int i = 0; i < 5;i++)
        {
            if(!books[i].isEmpty())
                counter+= books[i].getPages();
            else
                break;
        }
        
        return counter;
    }
    
    public boolean addBook(String author, String name, int pages, int year)
    {
        boolean check = false;
        if(getNumberOfPages() + pages <= 1500)
        {
            for(int i = 0;(!check)&&(i < 5);i++)
            {
                if(books[i].isEmpty()){
                    books[i].set(author,name,pages,year);
                    check = true;
                }
            }
        }
        return check;
    }
    
    public boolean removeBook(int index)
    {
        boolean check = false;
        if(!books[index].isEmpty())
        {
            for(int i = index; i < 4;i++)
            {
                books[i] = books[i+1];
                check = true;
            }
            if(check || index == 4)
            {
                books[4] = new Book();
                check = true;
            }
        }
        
        return check;
    }
    
    public boolean isEmpty()
    {
        return (books[0].isEmpty());
    }
    
    @Override
    public String toString()
    {
        String ret = "";
        if(!isEmpty())
            {
            ret = "     The books on the shelf number " + shelfNumber + " are:\n";
            for(int i = 0; i < 5; i++)
            {
                if(!books[i].isEmpty())
                    ret += books[i].toString();
                else
                    break;
            }
        }
        
        return ret;
    }
    
    public String extendedToString()
    {
        String ret = toString();
        if(ret.isEmpty())
        {
            ret = "is empty Shelf number " + shelfNumber;
        }
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
