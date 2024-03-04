package Practise5;

import Practice5.Date;

public class EventList {
    Event[] events = new Event[100];
    int n;

    public EventList(){
        this.n = 0;
        for(int i = 0; i < 100; i++){
            this.events[i] = new Event();
        }
    }

    public void append(Event e){
        this.events[n].setStart(e.getStart());
        this.events[n].setEnd(e.getEnd());
        this.events[n].setName(e.getName());
        this.n++;
    }

    public void set(Event[] a, int count){
        this.n = count;
        for(int i = 0; i < n; i++){
            this.events[i].setStart(a[i].getStart());
            this.events[i].setEnd(a[i].getEnd());
            this.events[i].setName(a[i].getName());
        }
    }

    public void print(){
        for(int i = 0; i < n; i++){
            System.out.println(this.events[i].getName());
        }
    }

    public void printEvents(Date d){
        for(int i = 0; i < n; i++){
            Date d1 = new Date();
            Date d2 =  new Date();
            d1 = this.events[i].getStart();
            d2 = this.events[i].getEnd();
            //d1.printDate();
            //d2.printDate();
            int p = d1.CompareDays(d);
            int q = d2.CompareDays(d);
            if(p == 0 || q == 0 || (p == -1 && q == 1)){
                System.out.println("This event is happening at this date: " + this.events[i].getName());
            }
        }
    }
}
