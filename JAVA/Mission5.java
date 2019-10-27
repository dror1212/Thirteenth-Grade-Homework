/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package fraction;

/**
 *
 * @author student
 */
public class Fraction {
    private int Numerator;
    private int Denominator;
    
    public Fraction(int Numerator, int Denominator)
    {
        this.Numerator = Numerator;
        this.Denominator = Denominator;
    }
    
    public Fraction(int Numerator)
    {
        this(Numerator,1);
    }
    
    public Fraction()
    {
        this(1,1);
    }
    
    public Fraction(double num)
    {
        this((int)(num * 100000), 100000);
    }
    
    public int getNumerator()
    {
        return this.Numerator;
    }
    
    public int getDenominator()
    {
        return this.Denominator;
    }
    
    public void setNumerator(int Numerator)
    {
        this.Numerator = Numerator;
    }
    
    public void setDenominator(int Denominator)
    {
        this.Denominator = Denominator;
    }
    
    public Fraction FractionPlus(Fraction num)
    {
        double answer = this.getFraction();
        answer += num.getFraction();
        Fraction retValue = new Fraction(answer);
        return retValue;
    }
    
    public Fraction FractionPlus(double num)
    {
        double answer = this.getFraction() + num;
        Fraction retValue = new Fraction(answer);
        return retValue;
    }
    
    public Fraction FractionMinus(Fraction num)
    {
        double answer = this.getFraction();
        answer -= num.getFraction();
        Fraction retValue = new Fraction(answer);
        return retValue;
    }
    
    public Fraction FractionMinus(double num)
    {
        double answer = this.getFraction();
        Fraction retValue = new Fraction(answer);
        return retValue;
    }

    public Fraction FractionMultiply(Fraction num)
    {
        double answer = this.getFraction();
        answer *= (double)num.getNumerator() / num.getDenominator();
        Fraction retValue = new Fraction(answer);
        return retValue;
    }
    
    public Fraction FractionMultiply(double num)
    {
        double answer = this.getFraction();
        answer *= num;
        Fraction retValue = new Fraction(answer);
        return retValue;
    }
    
    public Fraction FractionDivide(Fraction num)
    {
        double answer = this.getFraction();
        answer /= num.getFraction();
        Fraction retValue = new Fraction(answer);
        return retValue;
    }
    
    public Fraction FractionDivide(double num)
    {
        double answer = this.getFraction();
        answer /= num;
        Fraction retValue = new Fraction(answer);
        return retValue;
    }
    
    @Override
    public String toString()
    {
        return this.Numerator + " / " + this.Denominator;
    }
    
    public double getFraction()
    {
        return (double)this.Numerator / this.Denominator;
    }
    
    @Override
    public boolean equals(Object obj)
    {
        if(obj instanceof Fraction)
        {
            Fraction one = (Fraction)(obj);
            return (one.getFraction() == this.getFraction());
        }
        return false;
    }
    
    public boolean isBig(Fraction num)
    {
        return (num.getFraction() > this.getFraction());
    }
    
    public boolean isSmall(Fraction num)
    {
        return (num.getFraction() < this.getFraction());
    }
    
    public int gcd(int num, int num2)
    {       
        for(int i = Math.min(num, num2); i > 0; i--)
        {
            if(num % i == 0 && num2 % i == 0)
            {
                return i;
            }
        }
        return 0;
    }
    
    public Fraction simplify(Fraction a)
    {
        int newDecimator=2;
        while(a.getNumerator()/newDecimator!=(double)(a.getNumerator())/newDecimator)
        {
            newDecimator++;
        }
        if(newDecimator==a.getNumerator())
        {
            return a;
        }
        int newNumerator = a.getNumerator()/newDecimator;
        return new Fraction(newNumerator,newDecimator);
    }
}
