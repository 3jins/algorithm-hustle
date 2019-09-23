package programmers.level2;

public class JoyStick {
    private int getSumOfMinMoves(char[] nameCharArray) {
        int minMoves = 0;
        for (char c : nameCharArray) {
            minMoves += Math.min(c - 'A', 26 - (c - 'A'));
        }
        return minMoves;
    }

    private int findShortestJourney(char[] nameCharArray, int nameLength) {
        int shortestJourney = nameLength;
        // 정방향
        for (int startIdx = 0; startIdx < nameLength; startIdx++) {
            int journey = Math.min(startIdx, (nameLength - startIdx) % nameLength);
            int stash = 0;
            for (int i = 1; i < nameLength; i++) {
                char c = nameCharArray[(i + startIdx) % nameLength];
                if (c == 'A') {
                    stash++;
                } else {
                    journey += (stash + 1);
                    stash = 0;
                }
            }
            shortestJourney = Math.min(shortestJourney, journey);
        }
        // 역방향
        for (int startIdx = 0; startIdx < nameLength; startIdx++) {
            int journey = Math.min(startIdx, (nameLength - startIdx) % nameLength);
            int stash = 0;
            for (int i = 1; i < nameLength; i++) {
                char c = nameCharArray[(nameLength + startIdx - i) % nameLength];
                if (c == 'A') {
                    stash++;
                } else {
                    journey += (stash + 1);
                    stash = 0;
                }
            }
            shortestJourney = Math.min(shortestJourney, journey);
        }
        return shortestJourney;
    }

    public int solution(String name) {
        int nameLength = name.length();
        char[] nameCharArray = name.toCharArray();
        return getSumOfMinMoves(nameCharArray) + findShortestJourney(nameCharArray, nameLength);
    }
}
