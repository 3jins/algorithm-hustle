package programmers.level2;

import java.util.PriorityQueue;

public class MoreSpicy {
    public int solution(int[] scovilleArr, int threshold) {
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        for (int scoville : scovilleArr) {
            minHeap.add(scoville);
        }

        int count = 0;
        while (true) {
            if (minHeap.peek() >= threshold) return count;
            if (minHeap.size() < 2) return -1;
            int least = minHeap.poll();
            int second = minHeap.poll();
            minHeap.add(least + second * 2);
            count++;
        }
    }
}
