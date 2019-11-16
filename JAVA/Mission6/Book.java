package myLibrary;

import java.time.LocalDate;

/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author dror
 */
public final class Book {
    private String author;
    private String name;
    private int pages;
    private int year;
    
    public Book(String author, String name, int pages, int year)
    {
        this.author = author;
        this.name = name;
        setPages(pages);
        setYear(year);
    }
    
    public Book()
    {
        this("","",0,0);
    }
    
    public void setAuthor(String author)
    {
        this.author = author;
    }
    
    public String getAuthor()
    {
        return this.author;
    }
    
    public void setName(String name)
    {
        this.name = name;
    }
    
    public String getName()
    {
        return this.name;
    }
    
    public void setPages(int pages)
    {
        if(pages > -1)
            this.pages = pages;
    }
    
    public int getPages()
    {
        return this.pages;
    }
    
    public void setYear(int year)
    {
        if(year > -1 && year <= LocalDate.now().getYear())
            this.year = year;
    }
    
    public int getYear()
    {
        return this.year;
    }
    
    public void set(String author, String name, int pages, int year)
    {
        setPages(pages);
        setYear(year);
        setName(name);
        setAuthor(author);
    }
    
    public boolean isEmpty()
    {
        return (author.isEmpty() && name.isEmpty() && pages == 0 && year == 0);
    }
    
    @Override
    public String toString()
    {
        if(!isEmpty())
            return ("           Book Name: " + name + " by " + author + ". " + pages + " pages.  Year: " + year + "\n");
        return "";
    }
    
    public void print()
    {
        System.out.println(toString());
    }
}
