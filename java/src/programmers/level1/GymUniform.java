package programmers.level1;

// '여벌 체육복을 갖고 있다'의 정의가 이상함.
// 그냥 2벌 갖고 있는 사람도 아니고, 처음부터 가져온 사람도 아님. 도둑이 다녀간 직후에 2벌 갖고 있는 사람임.
// 그 때문에 코드를 깨끗하게 만들 수 없음.
public class GymUniform {
    public int solution(int n, int[] losts, int[] reserves) {
        int numLosts = losts.length;
        int numReserves = reserves.length;
        int count = n - numLosts;
        for (int i = 0; i < numLosts; i++) {
            for (int j = 0; j < numReserves; j++) {
                if (losts[i] == reserves[j]) {
                    count++;
                    losts[i] = -1;
                    reserves[j] = -3;
                    break;
                }
            }
        }
        for (int lost : losts) {
            for (int i = 0; i < numReserves; i++) {
                if (Math.abs(reserves[i] - lost) == 1) {
                    count++;
                    reserves[i] = -3;
                    break;
                }
            }
        }
        return count;
    }
}
