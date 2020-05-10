import java.util.*;
import java.util.concurrent.locks.*;
import java.util.LinkedList;
import java.util.Queue;

public class Producer_Consumer_63 {
    
	public static void main(String[] args) throws InterruptedException {
				Buffer alpha = new Buffer(2);
		//PRODUCER		
         Thread String_Producer = new Thread(new Runnable() {
        	 public void run() {
                try {
                    alpha.produce();
                   } 
                catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
         );
        // CONSUMER         
         Thread String_Consumer = new Thread(new Runnable() {
        	 public void run() {
                try {
                    alpha.produce();
                   } 
                catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
         );
        String_Producer.start();
 		String_Consumer.start();
        String_Producer.join();
   		String_Consumer.join();
    }
static class Buffer {
        		private Queue<Integer> list;
        		private int size;
        		public Buffer(int size) {
            this.list = new LinkedList<>();
            this.size = size;
        }
        public void produce() throws InterruptedException {
            int produce = 0;
            while (true) {
                synchronized (this) {
                    while (list.size() >= size) {
                    wait();
                    }
                    list.add(produce);
                    System.out.println("VALUE OF PRODUCER :- " + produce);
                    produce++;
                    notify();
                    Thread.sleep(1000);
                }
            }
        }
        public void Consumer() throws InterruptedException {
            while (true) {
                synchronized (this) {
                    while (list.size() == 0) {
                        wait();
                    }
                    int consume = list.poll();
                    System.out.println("VALUE OF CONSUMER :-  " + consume);
                    notify();
                    Thread.sleep(1000);
                }
            }
        }
    }
}