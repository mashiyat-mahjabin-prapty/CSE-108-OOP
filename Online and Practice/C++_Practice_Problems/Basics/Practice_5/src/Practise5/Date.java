package Practice5;

import Practise5.Event;
import Practise5.EventList;

import static java.lang.Math.abs;

public class Date {
    private int year;
    private int month;
    private int day;
    public Date(){
        this.day = 0;
        this.month = 0;
        this.year = 0;
    }
    public Date(int day, int month, int year) {
        this.year = year;
        this.month = month;
        this.day = day;
    }

    public int getYear() {
        return year;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public int getMonth() {
        return month;
    }

    public void setMonth(int month) {
        this.month = month;
    }

    public int getDay() {
        return day;
    }

    public void setDay(int day) {
        this.day = day;
    }

    public void printDate(){
        System.out.println(day + "-" + month + "-" + year);
    }

    public int CompareDays(Date d){
        if(this.day == d.day && this.month == d.month && this.year == d.year){
            int i = 0;
            return i;
        }
        else if(this.year == d.year){
            if(this.month == d.month){
                if(this.day > d.day){
                    int i = 1;
                    return i;
                }
                else{
                    int i = -1;
                    return i;
                }
            }
            else if(this.month > d.month){
                int i = 1;
                return i;
            }
            else{
                int i = -1;
                return i;
            }
        }
        else if(this.year > d.year){
            int i = 1;
            return i;
        }
        else{
            int i = -1;
            return i;
        }
    }
    public int numOfDays(Date d){
        int i = abs(this.year - d.year);
        int j = abs(this.month - d.month);
        int k = abs(this.day - d.day);
        i = (i * 30 * 12) + (j * 30) + k;

        return i;
    }

    public static void main(String[] args){
        Date d1 = new Date(26, 3, 2020);
        Date d2 = new Date(13, 2, 2019);
        Date d3 = new Date(10, 1, 2018);
        Date d4 = new Date(26, 11, 2019);
        Date d5 = new Date(16, 7, 2019);

        d1.printDate();
        if(d2.CompareDays(d4) == 0){
            System.out.println("The dates are same");
        }
        else if (d2.CompareDays(d4) == 1) {
            System.out.println("The first date comes after the second date");
        }
        else if(d2.CompareDays(d4) == -1) {
            System.out.println("The first date comes before the second date");
        }
        if(d3.CompareDays(d2) == 0){
            System.out.println("The dates are same");
        }
        else if (d3.CompareDays(d2) == 1) {
            System.out.println("The first date comes after the second date");
        }
        else if(d3.CompareDays(d2) == -1){
            System.out.println("The first date comes before the second date");
        }
        int p = d4.numOfDays(d2);
        System.out.println("The number of days between the two dates is: " + p);

        Event e1 = new Event("Wedding1", new Date(11,7,2019), new Date(17,7,2019));
        Event e2 = new Event("Wedding2", new Date(15,7,2019), new Date(23,7,2019));
        Event e3 = new Event("Wedding3", new Date(26,12,2019), new Date(29,12,2019));
        Event e4 = new Event("Wedding4", new Date(7, 2, 2017), new Date(15, 2, 2017));
        Event e5 = new Event("Birthday1", new Date(9, 2, 2017), new Date(9, 2, 2017));
        Event e6 = new Event("Birthday2", new Date(2, 12, 2010), new Date(2, 12, 2010));
        Event e7 = new Event("Birthday3", new Date(28, 12, 2019), new Date(28, 12, 2019));

        int dur = e3.durationInDays();
        System.out.println(e3.getName() + " consisted of " + dur + " days");
        boolean q = e1.doesConflict(e2);
        if(q){
            System.out.println(e1.getName() + " and " + e2.getName() + " collide");
        }
        else{
            System.out.println(e1.getName() + " and " + e2.getName() + " do not collide");
        }

        EventList a = new EventList();
        a.append(e1);
        a.append(e2);
        a.append(e3);
        a.append(e4);
        a.append(e5);
        a.append(e6);
        a.append(e7);

        a.printEvents(d5);
        a.print();
    }
}
