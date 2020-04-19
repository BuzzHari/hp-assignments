import java.util.*;

public class JoinEx implements Runnable {
    private Random rand = new Random(System.currentTimeMillis());

    public void run() {
        for(int i = 0; i < 100000000; i++)
            rand.nextInt();
        System.out.println("[" + Thread.currentThread().getName()+"] finished");
    }

    public static void main(String[] args) throws InterruptedException {
        Thread[] threads = new Thread[5];

        for(int i = 0; i < threads.length; i++) {
            threads[i] = new Thread(new JoinEx(), "Thread-"+i);
            threads[i].start();
        }

        for(int i = 0; i < threads.length; i++) {
            threads[i].join();
        }
        System.out.println("[" + Thread.currentThread().getName() + "]" + "All threads have finished.");
    }
}
