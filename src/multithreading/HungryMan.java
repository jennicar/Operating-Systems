/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package multithreading;

/**
 *
 * @author jenni
 */
public class HungryMan implements Runnable{
    Thread thread;
    String name;
    Object fork = new Object(), cup = new Object();
    
    HungryMan(String _name){
        name = _name;
    }
    
    public void mealTime(){
        System.out.println(name + " is ready to eat!");
        synchronized(fork){
            synchronized(cup){
                for (int i = 1; i <= 10; i++){
                    System.out.println(name + " took " + i + " bites YUM");
                    System.out.println(name + " had " + i + " sips MMM");
                }
            }
        }
        System.out.println(name + " is full!");
    }
    
    public void start(){
        thread = new Thread(this);
        thread.start();
    }
    
    @Override
    public void run(){
        mealTime();
    }
    
    public static void main(String [] args){
        HungryMan Mark = new HungryMan("Mark");
        HungryMan Justin = new HungryMan("Justin");
        Mark.start();
        Justin.start();
    }
}