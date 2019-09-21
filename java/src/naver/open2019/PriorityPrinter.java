package naver.open2019;

import java.util.PriorityQueue;

/* 버그 생긴 이유 목록
 *
 * - 문제에서 시킨 순서 고대로 짰어야 했다. 임의대로 조금 수정해서 짜다 개판됨.
 * - 인덱스가 ++됨에 따라서 `request` 변수도 업데이트 됐어야 했다.
 * - endTime 증가시킬 때 요청간 공백 있는 경우 고려 안 함. 디스크컨트롤러 때와 마찬가지.
 * - ++하는 과정에서 ArrayIndexOutOfBoundException 고려 안 함.
 */
public class PriorityPrinter {
    private class Doc implements Comparable<Doc> {
        int docNo;
        int reqTime;
        int pages;

        @Override
        public int compareTo(Doc doc) {
            if (this.pages == doc.pages) {
                return this.reqTime >= doc.reqTime ? 1 : -1;
            }
            return this.pages >= doc.pages ? 1 : -1;
        }

        public Doc(int docNo, int reqTime, int pages) {
            this.docNo = docNo;
            this.reqTime = reqTime;
            this.pages = pages;
        }

        @Override
        public String toString() {
            return "Doc{" +
                    "docNo=" + docNo +
                    ", reqTime=" + reqTime +
                    ", pages=" + pages +
                    '}';
        }
    }

    public int[] solution(int[][] requests) {
        int numRequests = requests.length;
        int[] printSeq = new int[numRequests];
        PriorityQueue<Doc> reqQueue = new PriorityQueue<>();

        int endTime = 0;
        int seq = 0;
        int reqIdx = 0;
        while (seq < numRequests) {
            // System.out.println((reqIdx + 1) + " " + endTime + " " + reqQueue.toString());
            // System.out.println(Arrays.toString(printSeq));
            int[] request = requests[reqIdx];
            if (reqQueue.isEmpty() && request[1] > endTime) { // 인쇄 중 또는 대기 중인 문서가 없을 때
                printSeq[seq++] = request[0];
                endTime = Math.max(endTime, request[1]) + request[2];
                reqIdx++;
            } else { // 인쇄 중 또는 대기 중인 문서가 있을 때
                reqQueue.add(new Doc(request[0], request[1], request[2]));
                if (++reqIdx < numRequests) {
                    request = requests[reqIdx];
                }

                // 인쇄 중인 문서가 전부 인쇄된 후
                while (!reqQueue.isEmpty() && (reqIdx >= numRequests || request[1] >= endTime)) {
                    if (reqIdx < numRequests && request[1] == endTime) {
                        reqQueue.add(new Doc(request[0], request[1], request[2]));
                        request = requests[++reqIdx];
                    }
                    Doc nextDoc = reqQueue.poll();
                    printSeq[seq++] = nextDoc.docNo;
                    endTime = Math.max(endTime, nextDoc.reqTime) + nextDoc.pages;
                }
            }
        }

        return printSeq;
    }
}
