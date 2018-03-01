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
public class Multithreading implements Runnable{
    private Thread thread;
    private String threadName;
    
    Multithreading(String name){
        threadName = name;
        System.out.println(threadName + " are the best");
    }
    
    public void run(){
        System.out.println("nothing beats " + threadName + "\n");
        try{
            for (int i = 2; i<9; i++){
                System.out.println("i want " + i + " " + threadName);
                Thread.sleep(1000);
            }
        } catch (InterruptedException e){
            System.out.println(threadName + " were interrupted.");
        }        
        System.out.println("i'm tired of " + threadName);
    }
        
    public void start(){
        System.out.println(threadName + " really are the best huh?\n");
        thread = new Thread(this, threadName);
        thread.start();
    }
}