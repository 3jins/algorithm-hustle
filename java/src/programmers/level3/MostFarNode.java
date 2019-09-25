package programmers.level3;

import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;

public class MostFarNode {
    private class Node {
        int nodeNo;
        int distance;

        public Node(int nodeNo, int distance) {
            this.nodeNo = nodeNo;
            this.distance = distance;
        }

        @Override
        public String toString() {
            return "Node{" +
                    "nodeNo=" + nodeNo +
                    ", distance=" + distance +
                    '}';
        }
    }

    private List<List<Integer>> routingTable = new ArrayList<>();
    private boolean[] isVisited;

    public int solution(int numNodes, int[][] edges) {
        isVisited = new boolean[numNodes + 1];
        routingTable.add(null);
        for (int i = 1; i <= numNodes; i++) {
            routingTable.add(new ArrayList<>());
        }
        for (int[] edge : edges) {
            routingTable.get(edge[0]).add(edge[1]);
            routingTable.get(edge[1]).add(edge[0]);
        }

        Queue<Node> bfsq = new LinkedList<>();
        isVisited[1] = true;
        bfsq.add(new Node(1, 0));
        int maxDistance = 0;
        int numMaxDistanceNode = 1;
        while (!bfsq.isEmpty()) {
            Node curNode = bfsq.poll();
            int distance = curNode.distance;
            if (maxDistance < distance) {
                maxDistance = distance;
                numMaxDistanceNode = 1;
            } else {
                numMaxDistanceNode++;
            }
            List<Integer> nextNodeNumbers = routingTable.get(curNode.nodeNo);
            for (int nextNodeNo : nextNodeNumbers) {
                if (isVisited[nextNodeNo]) continue;
                isVisited[nextNodeNo] = true;
                bfsq.add(new Node(nextNodeNo, distance + 1));
            }
        }

        return numMaxDistanceNode;
    }
}
