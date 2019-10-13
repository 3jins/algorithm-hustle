package baekjoon.samsung;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

// 일단 약 1시간 시도 후 입출력 외의 코드 리셋
// 16:39 ~ 16:59, 17:21 ~ 17:27 - 문제 잘못 읽었음을 깨달음
// 17:27 ~ 17:35
public class InsertingOperators14888 {
    private int numOperands;
    private int[] operands;
    private int[] operators = new int[4];
    private int max = -1000000000;
    private int min = 1000000000;

    public InsertingOperators14888() {
        init();
        findMaxMinResult(operands[0], 1);
        System.out.println(max);
        System.out.println(min);
    }

    private void init() {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        try {
            numOperands = Integer.parseInt(reader.readLine());
            operands = new int[numOperands];
            String[] inputs = reader.readLine().split(" ");
            for (int i = 0; i < numOperands; i++) {
                operands[i] = Integer.parseInt(inputs[i]);
            }
            inputs = reader.readLine().split(" ");
            for (int i = 0; i < 4; i++) {
                operators[i] = Integer.parseInt(inputs[i]);
            }
        } catch (IOException e) {
        }
    }

    private int updateCalcResult(int calcResult, int operator, int operand) {
        switch(operator) {
            case 0:
                return calcResult + operand;
            case 1:
                return calcResult - operand;
            case 2:
                return calcResult * operand;
            case 3:
                return calcResult / operand;
            default:
                return calcResult;
        }
    }

    private void findMaxMinResult(int calcResult, int operandsCnt) {
        if (operandsCnt == numOperands) {
            max = Math.max(calcResult, max);
            min = Math.min(calcResult, min);
        }
        for (int i = 0; i < 4; i++) {
            if (operators[i] == 0) continue;
            operators[i]--;
            findMaxMinResult(updateCalcResult(calcResult, i, operands[operandsCnt]), operandsCnt + 1);
            operators[i]++;
        }
    }
}
