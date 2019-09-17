package programmers.level2;

import java.util.Arrays;
import java.util.PriorityQueue;

public class RamenFactory {
    private class Supply implements Comparable<Supply> {
        int date;
        int supplyAmount;

        public Supply(int date, int supply) {
            this.date = date;
            this.supplyAmount = supply;
        }

        @Override
        public int compareTo(Supply supply) {
            return this.date >= supply.date ? 1 : -1;
        }

        public String toString() {
            return "date: " + date + ", supplyAmount: " + supplyAmount;
        }
    }

    public int solution(int stock, int[] dates, int[] supplies, int k) {
        PriorityQueue<Supply> supplyMinHeap = new PriorityQueue<>();
        PriorityQueue<Integer> possibleSupplyMaxHeap = new PriorityQueue<>(
                (Integer o1, Integer o2) -> (o1 <= o2 ? 1 : -1)
        );

        int numSupplyChances = dates.length;
        for (int i = 0; i < numSupplyChances; i++) {
            supplyMinHeap.add(new Supply(dates[i], supplies[i]));
            // System.out.println(Arrays.deepToString(supplyMinHeap.toArray()));
        }

        int cnt = 0;
        for (int day = 0; day < k; day++) {
            stock--;
            if (stock >= 0) continue;
            while (!supplyMinHeap.isEmpty() && supplyMinHeap.peek().date <= day) {
                possibleSupplyMaxHeap.add(supplyMinHeap.poll().supplyAmount);
                System.out.println(Arrays.toString(possibleSupplyMaxHeap.toArray()));
            }
            System.out.println("----");
            stock += possibleSupplyMaxHeap.poll();
            cnt++;
        }

        return cnt;
    }
}
