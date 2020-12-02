import java.util.*;
public class e12{
    static List<Integer> li;
    public static void main(String args[]){
        final long startTime = System.currentTimeMillis();

        int total = 1;
        int n = 1;
        int seq = 1;
        while(total <= 500){
            total = 1;
            li = new ArrayList<Integer>();
            seq = (n * (n + 1)) / 2;
            System.out.print("Number: " + n + "\tSequence: " + seq + "\t");
            prime(seq);
            Set<Integer> hashset = new HashSet<>(li);
            for(int i : hashset){
                total *= (Collections.frequency(li, i) + 1);
            }
            System.out.println("Total Factors: " + total);
            n ++;
        }   
        System.out.println("\n\nAnswer: " + seq + "\n\n");
        final long endTime = System.currentTimeMillis();
        System.out.println("Total execution time: " + (endTime - startTime));
    }
    public static void prime(int n){
        while(n % 2 == 0){
            li.add(2);
            n /= 2;
        }
        for(int i = 3; i <= Math.sqrt(n); i += 2){
            while(n % i == 0){
                li.add(i);
                n /= i;
            }
        }
        if(n > 2)
            li.add(n);
    }
}
