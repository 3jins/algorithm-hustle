package programmers.level3;

import java.util.Arrays;

public class Budget {
    private int[] budgetReqs;
    private int maxBudget;

    public int solution(int[] budgetReqs, int maxBudget) {
        this.budgetReqs = budgetReqs;
        this.maxBudget = maxBudget;
        if (arraySum(budgetReqs) <= maxBudget) return Arrays.stream(budgetReqs).max().getAsInt();
        return getUpperLimit(maxBudget / 2, divideDiff(maxBudget / 2));
    }

    private long arraySum(int[] arr) {
        long sum = 0;
        for (int e : arr) {
            sum += e;
        }
        return sum;
    }

    private int divideDiff(int diff) {
        return (diff + 1) / 2;
    }

    private int getUpperLimit(int upperLimit, int diff) {
        int budgetRemain = maxBudget;
        int cntOverBudget = 0;
        for (int budgetReq : budgetReqs) {
            if (budgetReq < upperLimit) {
                budgetRemain -= budgetReq;
            } else {
                budgetRemain -= upperLimit;
                cntOverBudget++;
            }
            if (budgetRemain < 0) {
                return getUpperLimit(upperLimit - diff, divideDiff(diff));
            }
        }
        if (budgetRemain >= cntOverBudget) {
            return getUpperLimit(upperLimit + diff, divideDiff(diff));
        }
        return upperLimit;
    }
}
