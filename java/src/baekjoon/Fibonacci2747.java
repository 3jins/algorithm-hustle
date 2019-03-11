package baekjoon;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;

public class Fibonacci2747 {
    private int mValue;

    public Fibonacci2747() {
        init();
        System.out.println(getFibonacci(mValue));
    }

    public void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            mValue = Integer.parseInt(reader.readLine());
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    public int getFibonacci(int value) {
        if(value <= 1) return value;

        int idx = 2;
        ArrayList<Integer> fibonacciList = new ArrayList<>();
        fibonacciList.add(0);
        fibonacciList.add(1);
        while(idx <= value) {
            fibonacciList.add(fibonacciList.get(idx - 1) + fibonacciList.get(idx - 2));
            idx++;
        }

        return fibonacciList.get(value);
    }
}
