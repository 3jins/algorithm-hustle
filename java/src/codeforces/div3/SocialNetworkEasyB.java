package codeforces.div3;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

// difficulty: 1000
// 14:55 ~ 15:08 (문제 이해)
// 15:08 ~ 15:25 (윈도우 렉 시바;; 뭔 재부팅이 10분이 넘게 걸리냐)
// 15:36 ~ 15:44
public class SocialNetworkEasyB {
    private int numMessages;
    private int displaySize;
    private Queue<Integer> displayQueue = new LinkedList<>();
    private int displayQueueSize = 0;

    public SocialNetworkEasyB() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            String[] inputs = reader.readLine().split(" ");
            numMessages = Integer.parseInt(inputs[0]);
            displaySize = Integer.parseInt(inputs[1]);
            inputs = reader.readLine().split(" ");
            for (String input : inputs) {
                int friendId = Integer.parseInt(input);
                if (isConversationAlreadyDisplaying(friendId)) continue;
                if (displayQueueSize == displaySize) {
                    displayQueue.poll();
                    displayQueueSize--;
                }
                displayQueue.add(friendId);
                displayQueueSize++;
            }
            String result = "";
            while (!displayQueue.isEmpty()) {
                result = displayQueue.poll() + " " + result;
            }
            System.out.println(displayQueueSize);
            System.out.println(result);
        } catch (IOException e) {
        }
    }

    private boolean isConversationAlreadyDisplaying(int friendId) {
        for (int id : displayQueue) {
            if (friendId == id) return true;
        }
        return false;
    }
}
