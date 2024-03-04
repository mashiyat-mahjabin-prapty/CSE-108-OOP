package com.company;

class InvalidAmountException extends Exception
{
    private double a;

    InvalidAmountException(double amount)
    {
        a = amount;
    }

    @Override
    public String toString() {
        return "InvalidAmountException : Your input is " + a;
    }
}

class InvalidBalanceException extends Exception
{
    private double a;

    InvalidBalanceException(double balance)
    {
        a = balance;
    }

    @Override
    public String toString() {
        return "InvalidBalanceException : Balance becomes " + a;
    }
}

public class Account {
    private double balance;

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public Account(double balance) {
        this.balance = balance;
    }

    public void debit (double amount) throws InvalidBalanceException, InvalidAmountException
    {
        if (amount < 0.0) { throw new InvalidAmountException(amount); }
        if (balance - amount < 0.0)
        {
            throw new InvalidBalanceException(balance - amount);
        }
        balance -= amount;
    }

    public void credit (double amount) throws InvalidAmountException
    {
        if (amount < 0.0) { throw new InvalidAmountException(amount); }
        balance += amount;
    }
}
