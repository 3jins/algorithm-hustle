package programmers.level2;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.List;

public class BiggestNumber {
    private class Number implements Comparable<Number> {
        int number;

        public Number(int number) {
            this.number = number;
        }

        @Override
        public int compareTo(Number number) {
            int comb1 = Integer.parseInt(this.number + "" + number.number);
            int comb2 = Integer.parseInt(number.number + "" + this.number);
            return comb1 < comb2 ? 1 : -1;
        }
    }

    public String solution(int[] numbers) {
        List<Number> numberList = new ArrayList<>(numbers.length + 1);
        Arrays.sort(numbers); // 아니 이게 말이 됨? ㅡㅡ;
        for (int number : numbers) {
            numberList.add(new Number(number));
        }
        Collections.sort(numberList);

        String biggestNumber = "";
        for (Number number : numberList) {
            if (number.number == 0 && biggestNumber.equals("0")) continue;
            biggestNumber += number.number;
        }
        return biggestNumber;
    }
}
