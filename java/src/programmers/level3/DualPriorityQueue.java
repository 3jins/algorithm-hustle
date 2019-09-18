package programmers.level3;

import java.util.ArrayList;
import java.util.List;
import java.util.PriorityQueue;

public class DualPriorityQueue {
    public int[] solution(String[] operations) {
        // PQ에다가 일단 다 집어넣는다.
        // D 뜨면 다 꺼낸다.
        // 1이면 마지막, -1이면 처음꺼 지운다.
        // I 뜨면 다시 다 넣는다.
        int[] result = {0, 0};
        PriorityQueue<Integer> minHeap = new PriorityQueue<>();
        List<Integer> dumpList = new ArrayList<>();

        for (String operation : operations) {
            String[] separatedOperations = operation.split(" ");
            String op = separatedOperations[0];
            int data = Integer.parseInt(separatedOperations[1]);

            if (op.equals("I")) {
                for(int queueData : dumpList) {
                    minHeap.add(queueData);
                }
                dumpList = new ArrayList<>();
                minHeap.add(data);
            } else {
                if (minHeap.isEmpty() && dumpList.isEmpty()) continue;
                while(!minHeap.isEmpty()) {
                    int queueData = minHeap.poll();
                    dumpList.add(queueData);
                }
                if (data == 1) {
                    dumpList.remove(dumpList.size() - 1);
                } else {
                    dumpList.remove(0);
                }
            }
        }

        while(!minHeap.isEmpty()) {
            int queueData = minHeap.poll();
            dumpList.add(queueData);
        }
        if (!dumpList.isEmpty()) {
            result[1] = dumpList.get(0);
            result[0] = dumpList.get(dumpList.size() - 1);
        }

        return result;
    }
}
