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
public class BankAccount {

    private String accountName;
    private String accountNum;
    private double balance;
    private boolean isOverDraftAllowed;
    private double overDraftSum;

    public BankAccount(String accountName, String accountNum, double balance, boolean isOverDraftAllowed, double overDraftSum) {
        //Create a bank acoount
        this.accountName = accountName;
        this.accountNum = accountNum;
        this.balance = balance;
        this.isOverDraftAllowed = isOverDraftAllowed;
        this.overDraftSum = overDraftSum;
    }

    public BankAccount() {
        //  Crate a defult bank account
        this("Account", "000001", 0, false, 0);
    }

    //Set the account name
    public void setAccountName(String accountName) {
        this.accountName = accountName;
    }
    //Get the account name
    public String getAccountName() {
        return this.accountName;
    }
    
    //Set the account number
    public void setAccountNum(String accountNum) {
        this.accountNum = accountNum;
    }

    //Get the account number
    public String getAccountNum() {
        return this.accountNum;
    }
    
    //Set the balance
    public void setBalance(double balance) {
        this.balance = balance;
    }
    
    //Get the balance
    public double getBalance() {
        return this.balance;
    }

    //Set the value of IsOverDraftAllowed
    public void setIsOverDraftAllowed(boolean isOverDraftAllowed) {
        this.isOverDraftAllowed = isOverDraftAllowed;
    }
    
    //Get the value of IsOverDraftAllowed
    public boolean getIsOverDraftAllowed() {
        return this.isOverDraftAllowed;
    }

    //Set the over draft sum
    public void setOverDraftSum(double overDraftSum) {
        this.overDraftSum = overDraftSum;
    }
    
    //Get the over draft sum
    public double getOverDraftSum() {
        return this.overDraftSum;
    }

    //Deposit specific amount of money
    public void deposit(double amount) {
        //Do it only if the value is above zero
        if (amount > 0) {
            this.balance += amount;
        }
    }

    public double withdrawal(double amount) {
        //Usedto return how much money was withdrawal
        double withdrawal = 0;
        
        //Do it only if the value is above zero
        if (amount > 0) {
            
            //Check if there is enough money
            if (balance > amount) {
                this.balance -= amount;
                withdrawal = amount;
                
            //Check if the customer is allowed to get into minus
            } else if (isOverDraftAllowed) {
                
                //Check if the customer can take all what he wants
                if (overDraftSum >= -(balance - amount)) {
                    this.balance -= amount;
                    withdrawal = amount;
                    
                //In case he can't take all what he wants
                } else {
                    withdrawal = overDraftSum + balance;
                    this.balance -= overDraftSum + balance;
                }
            }
            
            //In case he can't he is not allowed to take more than he has
            else
            {
                withdrawal = balance;
                this.balance -= balance;
            }
        }
        //The sum that the customer withdrawal
        return withdrawal;
    }

    //Return the string that shows the info about the account
    @Override
    public String toString() {
        return ("accountName: " + this.accountName + " accountNum: " + this.accountNum + " balance : " + this.balance + " isOverDraftAllowed : " + this.isOverDraftAllowed + " overDraftSum : " + this.overDraftSum);
    }
}
