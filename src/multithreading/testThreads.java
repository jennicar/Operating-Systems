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
public class testThreads{
    public static void main(String args[]){
        Multithreading thread_1 = new Multithreading("apples");
        thread_1.start();
        Multithreading thread_2 = new Multithreading("oranges");        
        thread_2.start();
    }
}
